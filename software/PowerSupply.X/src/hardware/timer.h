/* 
 * File:    time.h
 * Author:  Manuel
 * Date:    08/10/2018
 * 
 * Comments: timing functions
 */

#ifndef SRC_TIME_H
#define	SRC_TIME_H
  
#include "epmp.h"

//Initializes the timing functionalities
void TIME_Initialize(void);

//Returns the number of microseconds elapsed from the start of the program
volatile int64_t TIME_GetMicros();

//Returns the number of milliseconds elapsed from the start of the code
volatile int64_t TIME_GetMillis();

//Delays by the specified amount
void TIME_Delay_ms(int64_t ms);

#endif	/* SRC_TIME_H */

