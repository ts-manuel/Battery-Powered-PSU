/* 
 * File:    INA230_ADC.h
 * Author:  Manuel
 * Date:    09/10/2018
 * 
 * Comments:
 */

#ifndef SRC_INA230_ADC_H
#define	SRC_INA230_ADC_H

#include "mcc.h"

#define _INA230_CH1_ADDRESS     (0x40)  //I2C Address
#define _INA230_CH2_ADDRESS     (0x44)

#define _INA230_CONFIGURATION   (0x00)  //R/W All-register reset, shunt voltage and bus voltage ADC conversion times and averaging, operating mode
#define _INA230_SHUNT_VOLTAGE   (0x01)  //R   Shunt voltage measurement data
#define _INA230_BUS_VOLTAGE     (0x02)  //R   Bus voltage measuredment data
#define _INA230_POWER           (0x03)  //R   Contains the value of the calculated power being delivered to the load
#define _INA230_CURRENT         (0x04)  //R   Contains the value of the calculated current flowing through the shunt resistor
#define _INA230_CALIBRATION     (0x05)  //R/W Sets full-scale range and LS of current and power measurements. Overall system calibration
#define _INA230_MASK_ENABLE     (0x06)  //R/W Alert configuration and conversion ready flag
#define _INA230_ALERT_LIMIT     (0x07)  //R/W Contains the value to compare to the selected alert function
#define _INA230_DIE_ID          (0xFF)  //R   Containss unique die identification number

typedef enum{
    e_AverageCount_1,
    e_AverageCount_4,
    e_AverageCount_16,
    e_AverageCount_64,
    e_AverageCount_128,
    e_AverageCount_256,
    e_AverageCount_512,
    e_AverageCount_1024      
} INA230_AverageMode_t;

typedef enum{
    e_ConversionTime_140uS,
    e_ConversionTime_204uS,
    e_ConversionTime_332uS,
    e_ConversionTime_588uS,
    e_ConversionTime_1100uS,
    e_ConversionTime_2116uS,
    e_ConversionTime_4156uS,
    e_ConversionTime_8244uS,
} INA230_ConversionTime_t;

typedef enum{
    e_OperatingMode_PowerDown,
    e_OperatingMode_ShuntVoltage_Triggered,
    e_OperatingMode_BusVoltage_Triggered,
    e_OperatingMode_ShuntAndBuss_Triggered,
    e_OperatingMode_ShuntVotage_Continuous  = 5,
    e_OperatingMode_BusVoltage_Continuous,
    e_OperatingMode_ShuntAndBus_Continuous,
} INA230_OperatingMode_t;

typedef enum{
    e_AllertMask_ConversionReady            = (1 << 10),
    e_AllertMask_OverLimitPower             = (1 << 11),
    e_AllertMask_BusVoltageUnderVoltage     = (1 << 12),
    e_AllertMask_BusVoltageOverVoltage      = (1 << 13),
    e_AllertMask_ShuntVoltageUnderVoltage   = (1 << 14),
    e_AllertMask_ShuntVoltageOverVoltage    = (1 << 15)
} INA230_AllertMask_t;

//initializes the INA230 ADC, returns false if the initialization fails
bool INA230_ADC_Initialize(uint8_t i2cAddress);

//Resets all the registers to the default value
void INA230_Reset(uint8_t i2cAddress);

//Sets the number of averages
void INA230_SetAverageCount(uint8_t i2cAddress, INA230_AverageMode_t averageCount);

//Sets the conversion time for the bus voltage
void INA230_SetBusVoltageConversionTime(uint8_t i2cAddress, INA230_ConversionTime_t conversionTime);

//Sets the conversion time for the shunt voltage
void INA230_SetShuntVoltageConversionTime(uint8_t i2cAddress, INA230_ConversionTime_t conversionTime);

//Sets the operating mode
void INA230_SetOperatingMode(uint8_t i2cAddress, INA230_OperatingMode_t mode);

//Returns the value of the measured voltage across the shunt resistor in Volts
float INA230_GetShuntVoltage(uint8_t i2cAddress);

//Returns the value of the bus voltage in Volts
float INA230_GetVoltage(uint8_t i2cAddress);

//Returns the value of the measured power in Whats
float INA230_GetPower(uint8_t i2cAddress);

//Returns the value of the measured current in Amps
float INA230_GetCurrent(uint8_t i2cAddress);

//Sets the value of the LSB of the current register
void INA230_SetCalibrationRegister(uint8_t i2cAddress, float currentLSB, float shuntResistor);

void INA230_EnableAllertMaskbit(uint8_t i2cAddress, INA230_AllertMask_t allertMask, bool allertPolarity, bool enableLatch);

//Sets the value used as a threshold for the alert function
void INA230_SetAllertLimitRegister(uint8_t i2cAddress, uint16_t value);

//Writes a word to the ADC at the specified address
bool INA230_WriteWord(uint8_t i2cAddress, uint8_t address, uint16_t data);

//Reads a Word from the ADC from the specified address
uint16_t INA230_ReadWord(uint8_t i2cAddress, uint8_t address);


#endif	/* SRC_INA230_ADC_H */

