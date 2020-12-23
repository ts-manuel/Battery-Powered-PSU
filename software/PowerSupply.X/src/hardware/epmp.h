/* 
 * File:    epmp.h
 * Author:  Manuel
 * Date:    07/10/2018
 * 
 * Comments: Enhanced Parallel Master Port driver
 */

#ifndef XC_SRC_EPMP_H
#define	XC_SRC_EPMP_H

#include <xc.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

//Initializes the Enhanced Parallel Master Port
void EPMP_Initialize(void);

//Returns true if the port is busy
bool EPMP_IsBusy(void);

//Returns true if an error has occurred and clears the flag bit
bool EPMP_IsErrorSetAndClear(void);

//Returns true if a timeout condition has occurred and clears the flag bit
bool EPMP_IsTimeoutSetAndClear(void);

//Sets the end of the reserved address used by the module,
//The address must be greater than 0xFFFFFF
void EPMP_SetEndOfReservedAddressSpace(uint32_t endAddress);

//Sets the base address for the Chip select 1
//Default value on POR is 0x0800
//Valid bits as <23:15> and <11>
void EPMP_SetBaseAddressChipSelect1(uint32_t baseAddress);

//Writes a byte using the Enhanced Parallel Master Port at the specified address
void EPMP_WriteByte(uint8_t data, uint32_t address);

//Reads a byte from the Enhanced Parallel Master Port at the specified address
uint8_t EPMP_ReadByte(uint32_t address);

#endif	/* XC_SRC_EPMP_H */

