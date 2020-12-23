/* 
 * File:    I2C_master.h
 * Author:  Manuel
 * Date:    24/07/2020
 * 
 * I2C bit-banged master port
 */

#ifndef SRC_HARDWARE_I2C_H
#define	SRC_HARDWARE_I2C_H

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

typedef enum {
    e_I2C_OK        = 0x00,
    e_I2C_ADDR_NACK = 0x01,
    e_I2C_DATA_NACK = 0x02
} i2c_result_t;


void I2C_Initialize(void);
i2c_result_t  I2C_Write(uint8_t DevAddr, uint8_t *buffer, int ByteCnt);
i2c_result_t  I2C_Read(uint8_t DevAddr, uint8_t* buffer, int ByteCnt);
i2c_result_t  I2C_Write_8(uint8_t DevAddr, uint8_t SubAddr, int ByteCnt, uint8_t *buffer);
i2c_result_t  I2C_Read_8(uint8_t DevAddr, uint8_t SubAddr, int ByteCnt, uint8_t* buffer);
i2c_result_t  I2C_Write_16(uint8_t DevAddr, uint16_t SubAddr, int ByteCnt, uint8_t *buffer);
i2c_result_t  I2C_Read_16(uint8_t DevAddr, uint16_t SubAddr, int ByteCnt, uint8_t* buffer);


#endif	/* SRC_HARDWARE_I2C_H */

