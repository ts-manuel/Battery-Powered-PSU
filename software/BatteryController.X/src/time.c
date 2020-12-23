/*
 * File:    time.c
 * Author:  Manuel
 * Date:    26/06/2020
 * Device:  PIC16LF18346
 * Rev:     1.2 2020
 *
 * Timing functions
 * 
 */

#include "time.h"

//Global variables
static volatile uint32_t seconds;
static volatile uint32_t minutes;
extern volatile uint16_t timer0ReloadVal16bit;

/*
 * Initialize time variables
 */
void TIME_Initialize(void){
    seconds = 0;
    minutes = 0;
}

/*
 * Returns number of milliseconds elapsed from power on (overflows every 50 days)
 */
uint32_t TIME_Millis(void){
    //Disable interrupts
    uint8_t _INTCON = INTCON;
    INTCONbits.GIE = 0;
    
    uint16_t millis = TMR0_ReadTimer() - timer0ReloadVal16bit;
    
    //Restore interrupts
    INTCON = _INTCON;
    
    return seconds * 1000 + millis;
}

/*
 * Returns number of seconds elapsed from power on (overflows every 136 years)
 */
uint32_t TIME_Seconds(void){
    //Disable interrupts
    uint8_t _INTCON = INTCON;
    INTCONbits.GIE = 0;
    
    uint16_t millis = TMR0_ReadTimer() - timer0ReloadVal16bit;
    
    //Restore interrupts
    INTCON = _INTCON;
    
    return seconds + millis / 1000;
}

/*
 * Returns number of minutes elapsed from power on
 */
uint32_t TIME_Minutes(void){
    return minutes;
}

/*
 * Interrupt called every minute
 */
void TIME_ISR_Timer(void){
    minutes ++;
    seconds += 60;
}

/*
 * Delays for the specified amount of milliseconds
 */
void TIME_Delay_ms(uint32_t milliseconds){
    uint32_t now = TIME_Millis();
    while(TIME_Millis() < now + milliseconds);
}