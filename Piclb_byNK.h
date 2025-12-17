/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   LIB
 * Author: NGOANKLEIN
 * Comments: Enjoy it!
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
//#ifndef _PIC_MAIN_H
#define	_PIC_MAIN_H

#include <xc.h> // include processor files - each processor file is guarded.  
#define _XTAL_FREQ 20000000
#pragma config FOSC = HS        // High-Speed Oscillator (dùng th?ch anh ngoài > 4MHz, ? ?ây 24MHz)
#pragma config WDTE = OFF       // Watchdog Timer disabled
#pragma config PWRTE = ON       // Power-up Timer enabled
#pragma config BOREN = ON       // Brown-out Reset enabled
#pragma config LVP = OFF        // Low-Voltage Programming enabled
#pragma config CPD = ON        // Data EEPROM Memory Code Protection off
#pragma config WRT = OFF        // Flash Program Memory Write Protection off
#pragma config CP = ON
#define HIGH_1 (0X17)
#define LOW_1 (0xFF)
unsigned int analogRead_8bits(unsigned char pin);//Return 8 bits result from 0 to 255 
unsigned int analogRead_10bits(unsigned char pin);//Return 10 bits result from 0 to 1023
void analogWrite_8bits(unsigned char pin, unsigned char pw);//Pin: 1/2 => RC1/RC2; frequency: HIGH_1/ LOW_1; PW: pulse width
void analogWrite_8bits_init(unsigned char pin, unsigned char frequency);