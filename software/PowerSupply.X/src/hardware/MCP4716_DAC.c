/* 
 * File:    MCP4716_DAC.h
 * Author:  Manuel
 * Date:    10/10/2018
 * 
 * Comments: 10-bit DAC used for the set current
 */

#include "MCP4716_DAC.h"
#include "hardware/timer.h"
#include "hardware/I2C_master.h"
#include "debug/log.h"
#include "debug/errors.h"

#define _I_DAC_REFERENCE (4.090f) //Reference voltage used for the DAC


void I_DAC_WriteVolatileDACRegister(uint8_t i2cAddress, uint16_t value);
void I_DAC_WriteVolatileMemory(uint8_t i2cAddress, uint8_t config, uint16_t value);
void I_DAC_WriteAllMemory(uint8_t i2cAddress, uint8_t config, uint16_t value);
void I_DAC_WriteVolatileConfig(uint8_t i2cAddress, uint8_t config);
/*I2C2_MESSAGE_STATUS I_DAC_WriteWord(uint8_t address, uint16_t data);
uint16_t I_DAC_ReadWord(uint8_t address);*/


//initializes the MCP4716 DAC
void I_DAC_Initialize(uint8_t i2cAddress){
    I_DAC_WriteVolatileConfig(i2cAddress, _VREF_VREFPIN_UNBUFF | _PWRDWN_100K | _GAIN_1X);
}

void I_DAC_SetCurrent(uint8_t i2cAddress, float current){
    //current *= 5.0f;    //Scale value to get 0V - 5V for 0A - 1A
    I_DAC_WriteVolatileDACRegister(i2cAddress, (uint16_t)((current * 1024.0f) / _I_DAC_REFERENCE));
}

//If b == true enable the DAC
void I_DAC_Enable(uint8_t i2cAddress, bool b){
    uint8_t powerDown = b ? _PWRDWN_NORMAL : _PWRDWN_100K;
    I_DAC_WriteVolatileConfig(i2cAddress, _VREF_VREFPIN_UNBUFF | _GAIN_1X | powerDown); //
}

//Sets the value of the DAC register and PowerDown bits
void I_DAC_WriteVolatileDACRegister(uint8_t i2cAddress, uint16_t value){
    i2c_result_t result;
    uint8_t address = (_MCP4716_WRITE_VOLATILE_DAC << 5) | (_PWRDWN_NORMAL << 4) | ((value >> 6) & 0x0F);
    uint8_t data    = (uint8_t)(value << 2);

    result = I2C_Write_8(i2cAddress, address, 1, &data);
    if(result != e_I2C_OK){
        LOG_PRINT_ERROR("I_DAC_WriteVolatileDACRegister I2C2_M_Write() returned: %d\n", result);
        ERRORS_ThrowError(e_MCP4716, "I2C WRITE FAIL");
    }
}

//Sets the value of the DAC register and Configuration bits (config bits = VREF1, VREF0, PD1, PD0, G)
void I_DAC_WriteVolatileMemory(uint8_t i2cAddress, uint8_t config, uint16_t value){
    i2c_result_t result;
    uint8_t address = (_MCP4716_WRITE_VOLATILE_MEMORY << 5) | (config & 0x1F);
    uint8_t buffer[2];
    
    buffer[0] = value >> 2;
    buffer[1] = value << 6;

    result = I2C_Write_8(i2cAddress, address, 2, buffer);
    if(result != e_I2C_OK){
        LOG_PRINT_ERROR("I_DAC_WriteVolatileMemory I2C2_M_Write() returned: %d\n", result);
        ERRORS_ThrowError(e_MCP4716, "I2C WRITE FAIL");
    }
}

//Sets the value of the DAC register and Configuration bits (config bits = VREF1, VREF0, PD1, PD0, G)
void I_DAC_WriteAllMemory(uint8_t i2cAddress, uint8_t config, uint16_t value){
    i2c_result_t result;
    uint8_t address = (_MCP4716_WRITE_ALL_MEMORY << 5) | (config & 0x1F);
    uint8_t buffer[2];
    
    buffer[0] = value >> 2;
    buffer[1] = value << 6;

    result = I2C_Write_8(i2cAddress, address, 2, buffer);
    if(result != e_I2C_OK){
        LOG_PRINT_ERROR("I_DAC_WriteAllMemory I2C2_M_Write() returned: %d\n", result);
        ERRORS_ThrowError(e_MCP4716, "I2C WRITE FAIL");
        
    }
}

//Sets the value of the DAC register and Configuration bits (config bits = VREF1, VREF0, PD1, PD0, G)
void I_DAC_WriteVolatileConfig(uint8_t i2cAddress, uint8_t config){
    i2c_result_t result;
    uint8_t address = (_MCP4716_WRITE_VOLATILE_CONFIG << 5) | (config & 0x1F);

    result = I2C_Write_8(i2cAddress, address, 0, NULL);
    if(result != e_I2C_OK){
        LOG_PRINT_ERROR("I_DAC_WriteVolatileConfig I2C2_M_Write() returned: %d\n", result);
        ERRORS_ThrowError(e_MCP4716, "I2C WRITE FAIL");
    }
}
/*
//Writes a word to the ADC at the specified address
I2C2_MESSAGE_STATUS I_DAC_WriteWord(uint8_t address, uint16_t data){
    I2C2_MESSAGE_STATUS status = I2C2_MESSAGE_PENDING;
    
    uint8_t buffer[3];
    buffer[0] = address;
    buffer[1] = (data >> 8) & 0xFF;
    buffer[2] = data & 0xFF;
    
    I2C2_MasterWrite(buffer, 3, _MCP4716_ADDRESS, &status);
    
    return status;
}

//Reads a Word from the ADC from the specified address
uint16_t I_DAC_ReadWord(uint8_t address){
    I2C2_MESSAGE_STATUS status = I2C2_MESSAGE_PENDING;
    uint16_t data;
    
    //Set read address
    I2C2_MasterWrite(&address, 1, _MCP4716_ADDRESS, &status);
    
    //Read the data
    I2C2_MasterRead((uint8_t*)&data, 2, _MCP4716_ADDRESS, &status);
    
    return data;
}
*/