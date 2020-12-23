/*
 * File:    time.h
 * Author:  Manuel
 * Date:    26/06/2020
 * Device:  PIC16LF18346
 * Rev:     1.2 2020
 *
 * Timing functions
 * 
 */

#ifndef XC_TIME_H
#define	XC_TIME_H

#include <mcc.h>
#include <stdint.h>

void TIME_Initialize(void);
void TIME_ISR_Timer(void);
uint32_t TIME_Millis(void);
uint32_t TIME_Seconds(void);
uint32_t TIME_Minutes(void);
void TIME_Delay_ms(uint32_t milliseconds);

#endif	/* XC_TIME_H */

