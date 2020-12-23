/* 
 * File:    power.h
 * Author:  Manuel
 * Date:    19/10/2018
 * 
 * Comments:
 */

#ifndef SRC_HARDWARE_POWER_H
#define	SRC_HARDWARE_POWER_H

#include "mcc.h"
#include "INA230_ADC.h"
#include "MAX5215_DAC.h"
#include "MCP4716_DAC.h"
#include "hardware/timer.h"
#include "globalVariables.h"

//Turns the power supply ON or OFF
void PWR_TurnOn(bool turnOn);

//Returns true if the power supply is on
bool PWR_IsPowerSupplyOn(void);

//Initializes the global variables
void PWR_Initialize(void);

//Updates the DACs values with set voltage and current, reads the ADCs
void PWR_Update(void);

#endif	/* SRC_HARDWARE_POWER_H */

