/*
 * File:    bms.h
 * Author:  Manuel
 * Date:    26/06/2020
 * Device:  PIC16LF18346
 * Rev:     1.2 2020
 *
 * Driver for the Texas Instruments BQ7692006PWR BMS
 * 
 */

#ifndef XC_BMS_H
#define	XC_BMS_H

#include <mcc.h>
#include <stdint.h>
#include <stdbool.h>
#include "types.h"

#ifdef _BIT
#undef _BIT
#endif
#ifdef _BYTE
#undef _BYTE
#endif
#define _BIT(x) ((uint16_t)1 << x)
#define _BYTE(x) ((uint8_t)x)

#define _BMS_ADDRESS    (0x18)  //BMS address

//_BMS_SYS_STAT
#define _SYS_CC_READY       _BIT(7)
#define _SYS_DEVICE_XREADY  _BIT(5)
#define _SYS_OVRD_ALLERT    _BIT(4)
#define _SYS_UV             _BIT(3)
#define _SYS_OV             _BIT(2)
#define _SYS_SCD            _BIT(1)
#define _SYS_OCD            _BIT(0)
//_BMS_SYS_CTRL1
#define _SYS_LOAD_PRESENT   _BIT(7)
#define _SYS_ADC_EN         _BIT(4)
#define _SYS_TEMP_SEL       _BIT(3)
#define _SYS_SHUT_A         _BIT(1)
#define _SYS_SHUT_B         _BIT(0)
//_BMS_SYS_CTRL2
#define _SYS_DELAY_DIS      _BIT(7)
#define _SYS_CC_EN          _BIT(6)
#define _SYS_CC_ONESHOT     _BIT(5)
#define _SYS_DSG_ON         _BIT(1)
#define _SYS_CHG_ON         _BIT(0)

#define _BMS_SYS_STAT   _BYTE(0x00)  //CC_READY<7>, DEVICE_XREADY<5>, OVRD_ALERT<4>, UV<3>, OV<2>, SCD<1>, OCD<0>
#define _BMS_CELLBAL1   _BYTE(0x01)  //CB<4:0>
#define _BMS_SYS_CTRL1  _BYTE(0x04)  //LOAD_PRESENT<7>, ADC_EN<4>, TEMP_SEL<3>, SHUT_A<1>, SHUT_B<0>
#define _BMS_SYS_CTRL2  _BYTE(0x05)  //DELAY_DIS<7>, CC_EN<6>, CC_ONESHOT<5>, DSG_ON<1>, CHG_ON<0>
#define _BMS_PROTECT1   _BYTE(0x06)  //RSNS<7>, SCD_DELAY<4:3>, SCD_THRESH<2:0>
#define _BMS_PROTECT2   _BYTE(0x07)  //OCD_DELAY<6:4>, OCD_THRESH<3:0>
#define _BMS_PROTECT3   _BYTE(0x08)  //UV_DELAY<7:6>, OV_DELAY<5:4>
#define _BMS_OV_TRIP    _BYTE(0x09)  //OV_THRESH<7:0>
#define _BMS_UV_TRIP    _BYTE(0x0A)  //UV_THRESH<7:0>
#define _BMS_CC_CFG     _BYTE(0x0B)  //(Must be programmed to 0x19)<5:0>
#define _BMS_VC1_HI     _BYTE(0x0C)  //VC1_HI<5:0>
#define _BMS_VC1_LO     _BYTE(0x0D)  //VC1_LO<7:0>
#define _BMS_VC2_HI     _BYTE(0x0E)  //VC2_HI<5:0>
#define _BMS_VC2_LO     _BYTE(0x0F)  //VC2_LO<7:0>
#define _BMS_VC3_HI     _BYTE(0x10)  //VC3_HI<5:0>
#define _BMS_VC3_LO     _BYTE(0x11)  //VC3_LO<7:0>
#define _BMS_VC4_HI     _BYTE(0x12)  //VC4_HI<5:0>
#define _BMS_VC4_LO     _BYTE(0x13)  //VC4_LO<7:0>
#define _BMS_VC5_HI     _BYTE(0x14)  //VC5_HI<5:0>
#define _BMS_VC6_LO     _BYTE(0x15)  //VC5_LO<7:0>
#define _BMS_BAT_HI     _BYTE(0x2A)  //BAT_HI<7:0>
#define _BMS_BAT_LO     _BYTE(0x2B)  //BAT_LO<7:0>
#define _BMS_TS1_HI     _BYTE(0x2C)  //TS1_HI<5:0>
#define _BMS_TS1_LO     _BYTE(0x2D)  //TS1_LO<7:0>
#define _BMS_CC_HI      _BYTE(0x32)  //CC_HI<7:0>
#define _BMS_CC_LO      _BYTE(0x33)  //CC_LO<7:0>
#define _BMS_ADCGAIN1   _BYTE(0x50)  //ADCGAIN<3:2>
#define _BMS_ADCOFFSET  _BYTE(0x51)  //ADCOFFSET<7:0>
#define _BMS_ADCGAIN2   _BYTE(0x59)  //ADCGAIN<7:5>


bool BMS_Initialize(void);
void BMS_Update(state_t state);
void BMS_AlertISR(void);

//i2c Interface
inline uint16_t BMS_GetCellVoltage(uint8_t cell);
inline uint16_t BMS_GetBatteryVoltage(void);
inline uint16_t BMS_GetTemperature(void);
inline int16_t  BMS_GetCurrent(void);
inline int32_t  BMS_GetEnergy(void);
inline int32_t  BMS_GetCapacity(void);
inline uint16_t BMS_GetOvervoltageThreshold(void);
inline uint16_t BMS_GetUnderVoltageThreashold(void);
inline uint8_t  BMS_GetSOC(void);

#endif	/* XC_BMS_H */

