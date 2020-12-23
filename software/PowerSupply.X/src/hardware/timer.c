/* 
 * File:    time.h
 * Author:  Manuel
 * Date:    08/10/2018
 * 
 * Comments: timing functions
 */

#include "hardware/timer.h"
#include "tmr1.h"


volatile int64_t millis = 0;    //Microseconds elapsed from the start of the program (updated at every timer overflow)

static void TIME_TimerOverflowCallback(void);

//Initializes the timing functionalities
void TIME_Initialize(void){
    TMR1_SetInterruptHandler(TIME_TimerOverflowCallback);    //Set the time callback function
}

//Called when the timer overflows
static void TIME_TimerOverflowCallback(void){
    millis += 1;
}

//Returns the number of milliseconds elapsed from the start of the program
volatile int64_t TIME_GetMillis(){
    return millis;
}

//Delays by the specified amount
void TIME_Delay_ms(int64_t ms){
    int64_t start = TIME_GetMillis();
    while((TIME_GetMillis() - ms) < start);
}

