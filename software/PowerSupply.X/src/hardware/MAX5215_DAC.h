/* 
 * File:    MAX5215_DAC.h
 * Author:  Manuel
 * Date:    10/10/2018
 * 
 * Comments: 14-bit set voltage DAC
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef SRC_HARDWARE_MAX5215_H
#define	SRC_HARDWARE_MAX5215_H

#include "mcc.h"

#define _MAX5215_CH1_ADDRESS    (0x1F)  //I2C Address
#define _MAX5215_CH2_ADDRESS    (0x1D)

#define _MAX5215_NOP            (0x00)  //No operation: DAC settings and modes unaffected
#define _MAX5215_CODE_LOAD      (0x01)  //Write and load data to the CODE and DAC registers
#define _MAX5215_CODE           (0x02)  //Write data to the CODE register
#define _MAX5215_LOAD           (0x03)  //Load current CODE register content to the DAC register
#define _MAX5215_CODE_LOAD_m    (0x05)  //Similar to CODE_LOAD commend, but accepts multiple sets of dual-byte data following the initial command byte (see the I2C Write Operation (Multibyte Protocol) section)
#define _MAX5215_CODE_m         (0x06)  //Similar to CODE command, but accepts multiple sets of dual-byte data following the initial command byte (see the I2C Write Operation (Multibyte Protocol) section)
#define _MAX5215_USER_CONFIG    (0x08)  //User configuration command
#define _MAX5215_SW_RESET       (0x09)  //Software Reset
#define _MAX5215_SW_CLEAR       (0x0A)  //Software Clear



void V_DAC_Initialize(uint8_t i2cAddress);

//Sets the value of the DAC
void V_DAC_SetVoltage(uint8_t i2cAddress, float voltage);

//If b == true enable the DAC
void V_DAC_Enable(uint8_t i2cAddress, bool b);

//Writes a word to the DAC at the specified address
bool V_DAC_WriteWord(uint8_t i2cAddress, uint8_t address, uint16_t data);

//Reads a Word from the DAC from the specified address
uint16_t V_DAC_ReadWord(uint8_t i2cAddress, uint8_t address);

#endif	/* SRC_HARDWARE_MAX5215_H */

