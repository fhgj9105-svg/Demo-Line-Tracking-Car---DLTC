/*
 * File:   analogRead.c
 * Author: DELL
 *
 * Created on December 10, 2025, 12:18 PM
 */



#include "Piclb_byNK.h"


unsigned int analogRead_8bits(unsigned char pin)
{
    ADCON0 = 0XC1;
    ADCON1 = 0X00;
    
    if (pin > 10 )
    {
        return 0;
    }
    ADCON0 &= 0x41;
    ADCON0 |= pin << 2;
    __delay_us(20);
    GO_DONE = 1;
    while (GO_DONE);
    return ADRESH;
}
unsigned int analogRead_10bits(unsigned char pin)
{
    ADCON0 = 0XC1;
    ADCON1 = 0XC0;
    
    if (pin > 10)
    {
        return 0;
    }
    ADCON0 &= 0x41;
    ADCON0 |= pin << 2;
    __delay_us(20);
    GO_DONE = 1;
    while (GO_DONE);
    return ((ADRESH << 8) + ADRESL);
}
