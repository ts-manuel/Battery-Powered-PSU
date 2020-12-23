/*
 * File:    i2cMaster.h
 * Author:  Manuel
 * Date:    26/06/2020
 * Device:  PIC16LF18346
 * Rev:     1.2 2020
 *
 * Bit-Banged I2C bus
 * 
 * MSSP2 does not work on PIC16LF18346 see errata
 * http://ww1.microchip.com/downloads/en/DeviceDoc/80000709D.pdf
 * 
 */

#ifndef _I2C_MASTER_H
#define	_I2C_MASTER_H

#include <mcc.h>

typedef enum {
    e_I2C_OK,
    e_I2C_ADDR_NACK,
    e_I2C_DATA_NACK
} i2c_result_t;


i2c_result_t I2C_Write(uint8_t slaveDeviceAddress, uint8_t* pData, uint8_t nCount);
i2c_result_t I2C_Read(uint8_t slaveDeviceAddress, uint8_t* pData, uint8_t nCount);

#endif	/* _I2C_MASTER_H */

