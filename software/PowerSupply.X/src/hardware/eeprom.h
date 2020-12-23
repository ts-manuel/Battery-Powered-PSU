/* 
 * File:    eeprom.h
 * Author:  Manuel
 * Date:    15/12/2018
 * 
 * Comments:
 */


#ifndef _SRC_HARDWARE_EEPROM_H
#define	_SRC_HARDWARE_EEPROM_H

#include <xc.h>
#include <mcc.h>
#include <stdint.h>
#include <stdbool.h>

//
#define _EEPROM_ADDRESS     (0x50)  //I2C Address


void EEPROM_Write(uint8_t* data, uint8_t numBytes, uint16_t address);
void EEPROM_Read(uint8_t* data, uint8_t numBytes, uint16_t address);

void EEPROM_StoreCallPoints(void);
bool EEPROM_LoadCallPoints(void);


#endif  //_SRC_HARDWARE_EEPROM_H