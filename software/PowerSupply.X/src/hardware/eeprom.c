/* 
 * File:    eeprom.c
 * Author:  Manuel
 * Date:    15/12/2018
 * 
 * Comments:
 */

#include "eeprom.h"
#include "globalVariables.h"
#include "I2C_master.h"
#include "delays.h"

static uint8_t Checksum(uint8_t* data, uint8_t numBytes);

/*
 * Writes data to the EEprom
 */
void EEPROM_Write(uint8_t* data, uint8_t numBytes, uint16_t address){  
    do{
        uint16_t nextPageStart = (address & 0xE0) + 0x20;   //Starting address of the next page
        uint8_t  byteCount = (nextPageStart - address) < numBytes ? (nextPageStart - address) : numBytes;   //Bytes to send
        
        I2C_Write_16(_EEPROM_ADDRESS, address, byteCount, data);
        __delay_ms(5);
        
        data += byteCount;      //Update pointer to point to the data to be sent next
        address += byteCount;   //Increment the address by the number of written bytes
        numBytes -= byteCount;  //Decrease the number of bytes remaining to send
    }while(numBytes > 0);
}

/*
 * Reads data from the EEprom
 */
void EEPROM_Read(uint8_t* data, uint8_t numBytes, uint16_t address){
    I2C_Read_16(_EEPROM_ADDRESS, address, numBytes, data);
}

/*
 * Store call points to the EEprom
 */
void EEPROM_StoreCallPoints(void){
    float callData[8] = {
        _GLOBAL_VAR_CH(1).voltageGain,
        _GLOBAL_VAR_CH(1).voltageOffset,
        _GLOBAL_VAR_CH(1).currentGain,
        _GLOBAL_VAR_CH(1).currentOffset,
        _GLOBAL_VAR_CH(2).voltageGain,
        _GLOBAL_VAR_CH(2).voltageOffset,
        _GLOBAL_VAR_CH(2).currentGain,
        _GLOBAL_VAR_CH(2).currentOffset
    };
    uint8_t checksum = Checksum((uint8_t*)callData, sizeof(callData));
    
    EEPROM_Write((uint8_t*)callData, sizeof(callData), _EEPROM_CALL_ADDRESS);
    EEPROM_Write((uint8_t*)&checksum, sizeof(uint8_t), _EEPROM_CALL_ADDRESS + sizeof(callData));
}

/*
 * Load call points to the EEprom,
 * returns true if checksum is OK
 */
bool EEPROM_LoadCallPoints(void){
    float callData[8];
    uint8_t checksum;
    
    EEPROM_Read((uint8_t*)callData, sizeof(callData), _EEPROM_CALL_ADDRESS);
    EEPROM_Read((uint8_t*)&checksum, sizeof(uint8_t), _EEPROM_CALL_ADDRESS + sizeof(callData));
    
    if(Checksum((uint8_t*)callData, sizeof(callData)) == checksum){
        _GLOBAL_VAR_CH(1).voltageGain   = callData[0];
        _GLOBAL_VAR_CH(1).voltageOffset = callData[1];
        _GLOBAL_VAR_CH(1).currentGain   = callData[2];
        _GLOBAL_VAR_CH(1).currentOffset = callData[3];
        
        _GLOBAL_VAR_CH(2).voltageGain   = callData[4];
        _GLOBAL_VAR_CH(2).voltageOffset = callData[5];
        _GLOBAL_VAR_CH(2).currentGain   = callData[6];
        _GLOBAL_VAR_CH(2).currentOffset = callData[7];
        return true;
    }
    else{
        _GLOBAL_VAR_CH(1).voltageGain   = 0.8000f;
        _GLOBAL_VAR_CH(1).voltageOffset = 0.0000f;
        _GLOBAL_VAR_CH(1).currentGain   = 0.8000f;
        _GLOBAL_VAR_CH(1).currentOffset = 0.0000f;
        
        _GLOBAL_VAR_CH(2).voltageGain   = 0.8000f;
        _GLOBAL_VAR_CH(2).voltageOffset = 0.0000f;
        _GLOBAL_VAR_CH(2).currentGain   = 0.8000f;
        _GLOBAL_VAR_CH(2).currentOffset = 0.0000f;
        return false;
    }
}

static uint8_t Checksum(uint8_t* data, uint8_t numBytes){
    uint8_t checksum = 0;
    
    for(uint8_t i = 0; i < numBytes; i++){
        checksum += data[i];
    }
    
    return ~checksum;
}