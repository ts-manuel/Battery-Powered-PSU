/* 
 * File:    power.h
 * Author:  Manuel
 * Date:    10/04/2019
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _SRC_POWER_H
#define	_SRC_POWER_H

#include <xc.h> 

void PWR_Initialize(void);

inline void PWR_Update(void);

void PWR_ShowBatteryLevel(void);

#endif	/* _SRC_POWER_H */

