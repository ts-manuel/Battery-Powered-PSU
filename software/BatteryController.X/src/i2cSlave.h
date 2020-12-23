/*
 * File:    i2cSlave.h
 * Author:  Manuel
 * Date:    26/06/2020
 * Device:  PIC16LF18346
 * Rev:     1.2 2020
 *
 * Slave I2C driver
 * 
 * Master can read from registers,
 * writing is not supported
 */

#ifndef _I2C_SLAVE_H
#define	_I2C_SLAVE_H

#include <mcc.h>
#include <stdint.h>

#define _I2CS_CELL1         (0x02)  //Cell 0 voltage                    2byte
#define _I2CS_CELL2         (0x03)  //Cell 1 voltage                    2byte
#define _I2CS_CELL3         (0x04)  //Cell 2 voltage                    2byte
#define _I2CS_BAT_VOLTAGE   (0x05)  //Battery voltage                   2byte
#define _I2CS_BMS_TEMP      (0x06)  //BMS ic internal temperature       2byte
#define _I2CS_DISCH_CURRENT (0x07)  //Battery discharge current         2byte
#define _I2CS_BAT_ENERGY    (0x08)  //Battery stored energy             4byte
#define _I2CS_BAT_OV_THRES  (0x09)  //Battery overvoltage threshold     2byte
#define _I2CS_BAT_UV_THRES  (0x10)  //Battery undervoltage threshold    2byte
#define _I2CS_BAT_SOC       (0x11)  //BAttery satte of charge           1byte

#define _I2CS_CHG_VOLTAGE   (0x20)  //Battery end of charge voltage     2byte
#define _I2CS_CHG_CURRENT   (0x21)  //Battery charge current            2byte


void I2C_SlaveAddrHandler(void);
void I2C_SlaveWriteHandler(void);
void I2C_SlaveReadHandler(uint8_t d);

#endif	/* _I2C_SLAVE_H */

