/*
 * File:   analogWrite.c
 * Author: DELL
 *
 * Created on December 11, 2025, 1:05 PM
 */


#include <xc.h>
#include "Piclb_byNK.h"

void analogWrite_8bits_init(unsigned char pin, unsigned char frequency) {
    if (pin == 2) {
        TRISC2 = 0;
        CCP1CON = 0x0C;
    }
    if (pin == 1) {
        CCP2CON = 0x0C;
        TRISC1 = 0;
    }
    PR2 = frequency;
    T2CON = 0X00;
    TMR2 = 0X00;
    TMR2ON = 1;
}

void analogWrite_8bits(unsigned char pin, unsigned char pw) {
    if (pin == 2) {
        CCPR1L = pw;
    }
    if (pin == 1) {
        CCPR2L = pw;
    }
}
