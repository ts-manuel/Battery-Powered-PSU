/* 
 * File:    battery.h
 * Author:  Manuel
 * Date:    31/10/2018
 * 
 * Comments:
 */

#ifndef _SRC_HARDWARE_BATTERY_H
#define	_SRC_HARDWARE_BATTERY_H

#include "mcc.h"

typedef struct{
    float voltages[3];
    float current;
    float SOC;
    float energy;
    float capacity;
} BatteryData_t;

extern BatteryData_t BatteryData;

void Battery_Update(void);

#endif	/* _SRC_HARDWARE_BATTERY_H */

//
//#ifndef _SRC_HARDWARE_BATTERY_H
//#define	_SRC_HARDWARE_BATTERY_H
//
//#include "mcc.h"
//
////Address of the battery on the I2C buss
//#define _BATTERY_I2C_ADDRESS 0x08
//
////Battery registers (Read only)
//#define _I2CS_CELL0         (0x02)  //Cell 0 voltage                    2byte
//#define _I2CS_CELL1         (0x03)  //Cell 1 voltage                    2byte
//#define _I2CS_CELL2         (0x04)  //Cell 2 voltage                    2byte
//#define _I2CS_BAT_VOLTAGE   (0x05)  //Battery voltage                   2byte
//#define _I2CS_BMS_TEMP      (0x06)  //BMS ic internal temperature       2byte
//#define _I2CS_DISCH_CURRENT (0x07)  //Battery discharge current         2byte
//#define _I2CS_BAT_ENERGY    (0x08)  //Battery stored energy             4byte
//#define _I2CS_BAT_OV_THRES  (0x09)  //Battery overvoltage threshold     2byte
//#define _I2CS_BAT_UV_THRES  (0x10)  //Battery undervoltage threshold    2byte
//#define _I2CS_BAT_SOC       (0x11)  //Battery State Of Charge           1byte
//
//#define _I2CS_CHG_VOLTAGE   (0x20)  //Battery end of charge voltage     2byte
//#define _I2CS_CHG_CURRENT   (0x21)  //Battery charge current            2byte
//
//uint8_t BATTERY_GetSOC(void);
//
////Returns the voltage of the n cell
//float BATTERY_GetCellVoltage(uint8_t n);
//
////Returns the voltage of the entire battery pack
//float BATTERY_GetVoltage(void);
//
////Returns the temperature of the BMS IC
//float BATTERY_GetTemperature(void);
//
////Returns the discharging current
//float BATTERY_GetDischargeCurrent(void);
//
////Returns the stored energy inside the battery (Wh)
//float BATTERY_GetSoredEnergy(void);
//
//float BATTERY_GetOverVoltageThreshold(void);
//
//float BATTERY_GetUnderVoltageThreshold(void);
//
////Returns the Set end of charge voltage (V)
//float BATTERY_GetEndOfChargeVoltage(void);
//
////Returns the Set Charge current (A)
//float BATTERY_GetChargeCurrent(void);
//
//
//#endif	/* _SRC_HARDWARE_BATTERY_H */

