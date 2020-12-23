/* 
 * File:    MAX5215_DAC.h
 * Author:  Manuel
 * Date:    10/10/2018
 * 
 * Comments: 14-bit set voltage DAC
 */

#include "MAX5215_DAC.h"
#include "hardware/timer.h"
#include "hardware/I2C_master.h"
#include "debug/log.h"
#include "debug/errors.h"

#define _V_DAC_REFERENCE (4.090f)   //Reference voltage for the DAC

//Initializes the DAC module
void V_DAC_Initialize(uint8_t i2cAddress){
    V_DAC_WriteWord(i2cAddress, _MAX5215_USER_CONFIG, 0x0000);  //Enable DAC
}

//Sets the value of the DAC
void V_DAC_SetVoltage(uint8_t i2cAddress, float voltage){
    //voltage /= 
    V_DAC_WriteWord(i2cAddress, _MAX5215_CODE_LOAD, (uint16_t)((voltage * 16384.0f) / _V_DAC_REFERENCE));
}

//If b == true enable the DAC
void V_DAC_Enable(uint8_t i2cAddress, bool b){
    V_DAC_WriteWord(i2cAddress, _MAX5215_USER_CONFIG, b ? 0x0000 : 0x0002);
}

//Writes a word to the DAC at the specified address
bool V_DAC_WriteWord(uint8_t i2cAddress, uint8_t address, uint16_t data){
    i2c_result_t result;
    uint8_t buffer[2];
    
    buffer[0] = (data >> 6) & 0xFF;
    buffer[1] = (data << 2) & 0xFF;
    
    result = I2C_Write_8(i2cAddress, address, 2, buffer);
    if(result != e_I2C_OK){
        LOG_PRINT_ERROR("V_DAC_WriteWord I2C2_M_Write() returned: %d\n", result);
        ERRORS_ThrowError(e_MAX5215, "I2C WRITE FAIL");
        return false;
    }
    
    return true;
}

//Reads a Word from the DAC from the specified address
uint16_t V_DAC_ReadWord(uint8_t i2cAddress, uint8_t address){
    i2c_result_t result;
    uint16_t data;
    
    result = I2C_Read_8(i2cAddress, address, 2, (uint8_t*)&data);
    if(result != e_I2C_OK){
        LOG_PRINT_ERROR("V_DAC_ReadWord I2C2_M_Read() returned: %d\n", result);
        ERRORS_ThrowError(e_MAX5215, "I2C READ FAIL");
        return 0;
    }

    return data;
}