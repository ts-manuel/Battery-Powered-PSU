/* 
 * File:    INA230_ADC.h
 * Author:  Manuel
 * Date:    09/10/2018
 * 
 * Comments:
 */

#include "INA230_ADC.h"
#include "hardware/timer.h"
#include "hardware/I2C_master.h"
#include "debug/log.h"
#include "debug/errors.h"

#define _BUS_VOLTAGE_LSB    (0.00125f)              //Resolution of the Bus voltage ADC     [V/LSB]
#define _SHUNT_VOLTAGE_LSB  (0.0000025f)            //Resolution of the Shunt voltage ADC   [V/LSB]
#define _POWER_LSB          (0.002f)                //Resolution of the Power register      [W/LSB]
#define _CURRENT_LSB        (_POWER_LSB / 25.0f)    //Resolution of the Power register      [A/LSB]
#define _SHUNT_RESISTOR     (0.1f)                  //Shunt resistor [Ohms]


//initializes the INA230 ADC, returns false if the initialization fails
bool INA230_ADC_Initialize(uint8_t i2cAddress){
    //Check communication with INA230
    uint16_t dieID = INA230_ReadWord(i2cAddress, _INA230_DIE_ID);
    if(dieID != 0x2260)
        return false;
    
    INA230_SetAverageCount(i2cAddress, e_AverageCount_16);                          //Set the number of averages
    INA230_SetBusVoltageConversionTime(i2cAddress, e_ConversionTime_8244uS);        //Set the conversion time for the bus voltage
    INA230_SetShuntVoltageConversionTime(i2cAddress, e_ConversionTime_8244uS);      //Set the conversion time for the shunt voltage
    INA230_SetOperatingMode(i2cAddress, e_OperatingMode_ShuntAndBus_Continuous);    //Set the operating mode
    INA230_SetCalibrationRegister(i2cAddress, _CURRENT_LSB, _SHUNT_RESISTOR);       //Calculate calibration value from the shunt resistor value and desired current LSB

    return true;
}

//Resets all the registers to the default value
void INA230_Reset(uint8_t i2cAddress){
    INA230_WriteWord(i2cAddress, _INA230_CONFIGURATION, 0x8000);
}

//Sets the number of averages
void INA230_SetAverageCount(uint8_t i2cAddress, INA230_AverageMode_t averageCount){
    uint16_t config = INA230_ReadWord(i2cAddress, _INA230_CONFIGURATION);   //Read old configuration value
    config = (config & 0xF1FF) | (((uint16_t)averageCount) << 9);           //Modify Average mode bits
    INA230_WriteWord(i2cAddress, _INA230_CONFIGURATION, config);            //Wite back the result
}

//Sets the conversion time for the bus voltage
void INA230_SetBusVoltageConversionTime(uint8_t i2cAddress, INA230_ConversionTime_t conversionTime){
    uint16_t config = INA230_ReadWord(i2cAddress, _INA230_CONFIGURATION);   //Read old configuration value
    config = (config & 0xFE3F) | (((uint16_t)conversionTime) << 6);         //Modify bus voltage conversion time bits
    INA230_WriteWord(i2cAddress, _INA230_CONFIGURATION, config);            //Wite back the result 
}

//Sets the conversion time for the shunt voltage
void INA230_SetShuntVoltageConversionTime(uint8_t i2cAddress, INA230_ConversionTime_t conversionTime){
    uint16_t config = INA230_ReadWord(i2cAddress, _INA230_CONFIGURATION);   //Read old configuration value
    config = (config & 0xFFC7) | (((uint16_t)conversionTime) << 3);         //Modify shunt voltage conversion time bits
    INA230_WriteWord(i2cAddress, _INA230_CONFIGURATION, config);            //Wite back the result 
}

//Sets the operating mode
void INA230_SetOperatingMode(uint8_t i2cAddress, INA230_OperatingMode_t mode){
    uint16_t config = INA230_ReadWord(i2cAddress, _INA230_CONFIGURATION);   //Read old configuration value
    config = (config & 0xFFF8) | ((uint16_t)mode);                          //Modify operating mode bits
    INA230_WriteWord(i2cAddress, _INA230_CONFIGURATION, config);            //Wite back the result
}

//Returns the value of the measured voltage across the shunt resistor in Volts
float INA230_GetShuntVoltage(uint8_t i2cAddress){
    int16_t value = (int16_t)INA230_ReadWord(i2cAddress, _INA230_SHUNT_VOLTAGE);
    return (float)value * _SHUNT_VOLTAGE_LSB;
}

//Returns the value of the bus voltage in Volts
float INA230_GetVoltage(uint8_t i2cAddress){
    int16_t value = (int16_t)INA230_ReadWord(i2cAddress, _INA230_BUS_VOLTAGE);
    return (float)value * _BUS_VOLTAGE_LSB;
}

//Returns the value of the measured power in Whats
float INA230_GetPower(uint8_t i2cAddress){
    int16_t value = (int16_t)INA230_ReadWord(i2cAddress, _INA230_POWER);
    return (float)value * _POWER_LSB;
}

//Returns the value of the measured current in Amps
float INA230_GetCurrent(uint8_t i2cAddress){
    int16_t value = (int16_t)INA230_ReadWord(i2cAddress, _INA230_CURRENT);
    return (float)value * _CURRENT_LSB;
}

//Sets the value of the LSB of the current register
void INA230_SetCalibrationRegister(uint8_t i2cAddress, float currentLSB, float shuntResistor){
    uint16_t value = (uint16_t)(0.00512f / (currentLSB * shuntResistor));
    
    value = 640 * 2;
    
    INA230_WriteWord(i2cAddress, _INA230_CALIBRATION, value);
}

void INA230_EnableAllertMaskbit(uint8_t i2cAddress, INA230_AllertMask_t allertMask, bool allertPolarity, bool enableLatch){
    uint16_t mask = INA230_ReadWord(i2cAddress, _INA230_MASK_ENABLE);   //Read old configuration value
    mask = (mask & 0x001F) | ((uint16_t)allertMask);                    //Modify operating mode bits
    
    mask |= allertPolarity  ? (1 << 1) : 0;
    mask |= enableLatch     ? (1 << 0) : 0;
    
    INA230_WriteWord(i2cAddress, _INA230_CONFIGURATION, mask);  
}

//Sets the value used as a threshold for the alert function
void INA230_SetAllertLimitRegister(uint8_t i2cAddress, uint16_t value){
    INA230_WriteWord(i2cAddress, _INA230_ALERT_LIMIT, value);  
}

//Writes a word to the ADC at the specified address
bool INA230_WriteWord(uint8_t i2cAddress, uint8_t address, uint16_t data){
    i2c_result_t result;
    uint8_t buffer[2];
    
    buffer[0] = data >> 8;
    buffer[1] = data & 0xFF;
    
    result = I2C_Write_8(i2cAddress, address, 2, buffer);
    if(result != e_I2C_OK){
        LOG_PRINT_ERROR("INA230_WriteWord I2C2_M_Write() returned: %d\n", result);
        ERRORS_ThrowError(e_INA230, "I2C WRITE FAIL");
        return false;
    }
    
    return true;
}

//Reads a Word from the ADC from the specified address
uint16_t INA230_ReadWord(uint8_t i2cAddress, uint8_t address){
    i2c_result_t result;
    uint8_t buffer[2];
    
    result = I2C_Read_8(i2cAddress, address, 2, buffer);
    if(result != e_I2C_OK){
        LOG_PRINT_ERROR("INA230_ReadWord I2C2_M_Read() returned: %d\n", result);
        ERRORS_ThrowError(e_INA230, "I2C READ FAIL");
        return 0;
    }

    return ((uint16_t)buffer[0] << 8) | (uint16_t)buffer[1];
}