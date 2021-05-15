/*
 * File:   main.c
 *
 * Created on August 16, 2010, 12:09 PM
 */

#define _XTAL_FREQ 16000000
 
#include <xc.h>
#include <stdint.h>

// BEGIN CONFIG
#pragma config WDTE = OFF // Watchdog Timer
#pragma config PWRTE = ON // Power-up Timer
#pragma config CP = OFF   // Code Protection

#include <htc.h>

int main(void) {
    TRISAbits.TRISA2 = 0; 
    TRISCbits.TRISC0 = 0; 
    TRISCbits.TRISC1 = 0; 
    TRISCbits.TRISC2 = 0; 

    WDTCONbits.SWDTEN = 0;
    
    int x = 1;
    int8_t direction = 1;
    
    while (1) {
        LATAbits.LATA2 = (x&1) != 0;
        LATCbits.LATC0 = (x&2) != 0;
        LATCbits.LATC1 = (x&4) != 0;
        LATCbits.LATC2 = (x&8) != 0;

        __delay_ms(40);
        if (direction == 1) {
           x <<= 1;
        
           if (x&16) {
              x = 8;
              direction = 0;
           }
        } else {
           x >>= 1;
        
           if (x == 0) {
              x = 1;
              direction = 1;
           }
        }
    }
    return 0;
}
