/*
 * File:   main.c
 * Author: 
 *
 * Created on December 11, 2025, 11:18 PM
 */



#include "Piclb_byNK.h"
//#define PORT_SCAN PORTD
//#define Kp (5)
//#define Ki (1)
//#define Kd (6)
//#define BASE_MAX 50
//#define BASE 10
//#define BASE_MIN 5
//float I = 0;
//int pr_error = 0;
//int error;
//static int last_error = 0;
//int calError()
//{
//    if(PORT_SCAN == 0X01)
//    {
//        error = 4;
//        return error;
//    }
//    if(PORT_SCAN == 0x03)
//    {
//        error = 3;
//        return error;
//    }
//    if(PORT_SCAN == 0X02)
//    {
//        error = 2;
//        return error;
//    }
//    if(PORT_SCAN == 0X06)
//    {
//        error = 1;
//        return error;
//    }
//    if(PORT_SCAN == 0X04)
//    {
//        error = 0;
//        return error;
//    }
//    if(PORT_SCAN == 0X0C)
//    {
//        error = -1;
//        return error;
//    }
//    if(PORT_SCAN == 0X08)
//    {
//        error = -2;
//        return error;
//    }
//    if(PORT_SCAN == 0x18)
//    {
//        error = -3;
//        return error;
//    }
//    if(PORT_SCAN == 0x10)
//    {
//        error = -4;
//        return error;
//    }
//    if (PORT_SCAN == 0X00)
//    {
//        last_error = pr_error;
//        return last_error;
//    }
//}
//float cal_PID()
//{
//    
//    float P = error;
//    I = I + error;
//    if (I >= 100) I = 100;
//    if (I <= -100) I =-100;
//    float D = error - pr_error;
//    pr_error = error;
//    float PID_value = ((Kp*P) + (Ki*I) + (Kd *D));
//    return PID_value;
//}
//void init_PWM(int PID_value, int *recent_left_PWM, int *recent_right_PWM)
//{
//   *recent_left_PWM =  BASE - PID_value;
//   *recent_right_PWM  = BASE + PID_value;
//   if (*recent_left_PWM >= BASE_MAX) *recent_left_PWM = BASE_MAX;
//   if (*recent_left_PWM <= BASE_MIN) *recent_left_PWM = BASE_MIN;
//   if (*recent_right_PWM <= BASE_MIN) *recent_right_PWM = BASE_MIN;
//   if (*recent_right_PWM >= BASE_MAX) *recent_right_PWM = BASE_MAX;
//}
//void main(void) {
//    ANSEL = 0X00;
//    ANSELH = 0X00;
//    PORTD = 0X00;
//    TRISD = 0X1F;
//    
//    analogWrite_8bits_init(1, HIGH_1);
//    analogWrite_8bits_init(2, HIGH_1);
//    int left = BASE, right = BASE;
//    while(1)
//    {
//        
//        if (left >= 255) left = 255;
//        if (left <= 0) left = 0;
//        if(right >= 255) right = 255;
//        if(right <= 0) right = 0;
//        
//        error = calError();
//       
//    init_PWM(cal_PID(), &left, &right);
//    analogWrite_8bits(1, left);
//    analogWrite_8bits(2, right);  
//   }
//}





#define PORT_SCAN PORTD

//#define FOR 
//#define REW

//#define STOP
//#define START

#define Kp 22
#define Ki 0
#define Kd 6

#define RO 150

#define BUTRU 0

#define CLAMP 100

#define BASE 100
#define BASE_MIN 0
#define BASE_MAX 200
int SENSOR_VALUE[5]= { -2, -1, 0, 1, 2};
float I = 0;
float error = 0, pr_error = 0, D= 0, out;
int left = BASE, right = BASE;
float cal_E(void)
{
    int count = 0;
    int w = 0;
    for (int i =0; i <5; i++)
    {
        if ((PORT_SCAN & (1 << i)))
        {
            w +=  SENSOR_VALUE[i];
            count++;
        }
    }
    if (count > 0)
    {
       error = (float)w/ (float)count;
       return error;
    }
    else if (count == 0)
    {
        if(pr_error > 0 ) error = 2.5;
        if(pr_error < 0 ) error = -2.5;
        return error;
    }
    
}
float PID(void)
{
    I += error;
    if (I > 100) I = 100;
    if (I < -100) I = -100;
    D = error - pr_error;
    pr_error = error;
    out = Kp*error + Ki*I + Kd*D;
    if (out > CLAMP) out = CLAMP;
    if (out < -CLAMP) out = -CLAMP;
    return out;
}
void caculate(float out)
{
    left = BASE - out;
    right = BASE + out - BUTRU;
    if (left > BASE_MAX) left = BASE_MAX;
    if (left < BASE_MIN ) left = BASE_MIN;
    if (right > BASE_MAX) right = BASE_MAX;
    if (right < BASE_MIN ) right = BASE_MIN;
}
void LEFT_UP()
{
    RC4 = 1;
    RC5 = 1;
    RC6 = 0;
    RC7 = 0;
}
void RIGHT_UP()
{
    RA0 = 0;
    RA1 = 0;
    RA2 = 1;
    RA3 = 1;
}
void RIGHT_DOWN()
{
    RA0 = 1;
    RA1 = 1;
    RA2 = 0;
    RA3 = 0;
}
void LEFT_DOWN()
{
    RC4 = 0;
    RC5 = 0;
    RC6 = 1;
    RC7 = 1;
}
void turnRight()
{
    if (error >= 2)
    {
        unsigned char il = left;
        unsigned char ir = right;
        right = RO;
        left =RO;
        while(1)
        {
            LEFT_UP();
            //RC4 = 0;
            RIGHT_DOWN();
            analogWrite_8bits(1, (unsigned char)left); 
            analogWrite_8bits(2, (unsigned char)right);
            //RA0 = 0;
            if(PORT_SCAN & 1<<2)
            {
                left = il;
                right = il;
                break;
            }
        }
    }
}
void turnLeft()
{
    if (error <= -2)
    {   
        unsigned char il = left;
        unsigned char ir = right;
        right = RO;
        left =RO;
        while(1)
        {
            LEFT_DOWN();
            //RC7 = 0;
            RIGHT_UP();
            analogWrite_8bits(1, (unsigned char)left); 
            analogWrite_8bits(2, (unsigned char)right);
            //RA4 = 0;
            if(PORT_SCAN & 1<<2) 
            {
                left = il;
                right = il;
                break;
            }
            
        }
    }
}
void main(void)
{
    ANSEL = 0X00;
    ANSELH = 0X00;
    TRISD = 0X3F;
    PORTC = 0X00;
    TRISC = 0X00;
    PORTA = 0X00;
    TRISA = 0X00;
    analogWrite_8bits_init(1, LOW_1);
    analogWrite_8bits_init(2, LOW_1);
    
    while(1)
    {
        LEFT_UP();
        RIGHT_UP();

        error = cal_E();
        turnRight();
        turnLeft();
        out = -PID();
        caculate(out);
        analogWrite_8bits(1, (unsigned char)left); 
        analogWrite_8bits(2, (unsigned char)right);
        __delay_ms(5);
    } 
    
}
