/* 
 * File:    MCP4716_DAC.h
 * Author:  Manuel
 * Date:    10/10/2018
 * 
 * Comments: 10-bit DAC used for the set current
 */

#ifndef SRC_HARDWARE_MCP4716_DAC_H
#define	SRC_HARDWARE_MCP4716_DAC_H

#include "mcc.h"

#define _MCP4716_CH1_ADDRESS    (0x60)  //I2C Address
#define _MCP4716_CH2_ADDRESS    (0x61)

//Config
#define _VREF_VDD_UNBUFF        (0x00)  //VDD is used as voltage reference
#define _VREF_VREFPIN_UNBUFF    (0x10)  //Vref pin is used as voltage refernce
#define _VREF_VREFPIN_BUFF      (0x18)  //Vref pin is used as voltage reference with buffer
#define _PWRDWN_NORMAL          (0x00)  //Normal operation
#define _PWRDWN_1K              (0x02)  //Low power mode, output loaded with 1K resistor to GND
#define _PWRDWN_100K            (0x04)  //Low power mode, output loaded with 100K resistor to GND
#define _PWRDWN_500K            (0x06)  //Low power mode, output loaded with 500K resistor to GND
#define _GAIN_1X                (0x00)  //Voltage refernce gain = 1
#define _GAIN_2X                (0x01)  //Voltage refernce gain = 2 (Not applicable when VDD is used as reference)


#define _MCP4716_WRITE_VOLATILE_DAC     (0x00)  //Modifies the DAC register and PowerDowm bits
#define _MCP4716_WRITE_VOLATILE_MEMORY  (0x02)  //Modifies the DAC register and Config bist
#define _MCP4716_WRITE_ALL_MEMORY       (0x03)  //Modifies the DAC register, configuration bits and EEPROM
#define _MCP4716_WRITE_VOLATILE_CONFIG  (0x04)  //Modifies the configuration bits


//initializes the MCP4716 DAC
void I_DAC_Initialize(uint8_t i2cAddress);

//Updates the DAC value and enables the output
void I_DAC_SetCurrent(uint8_t i2cAddress, float current);

//If b == true enable the DAC
void I_DAC_Enable(uint8_t i2cAddress, bool b);

#endif	/* SRC_HARDWARE_MCP4716_DAC_H */

