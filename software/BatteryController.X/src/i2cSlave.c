/*
 * File:    i2cSlave.c
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

#include "i2cSlave.h"
#include "bms.h"
#include "chg.h"

typedef enum {e_I2C_ADDR, e_I2C_DATA} I2C_state_t;

//Global variables
static volatile I2C_state_t state = e_I2C_ADDR;
static volatile uint32_t data;

//Static functions
static uint32_t ReadRegister(uint8_t address);
static void WriteRegister(uint8_t address, uint32_t data);


/*
 * Called after the I2C address is been acknowledge
 */
void I2C_SlaveAddrHandler(void){
    state = e_I2C_ADDR;
}

/*
 * Called after a read transaction is been acknowledge
 */
void I2C_SlaveWriteHandler(void) {
    I2C1_Write(data & 0xff);
    data >>= 8;
}

/*
 * Called after a write transaction is been acknowledge
 */
void I2C_SlaveReadHandler(uint8_t d) {

    if(state == e_I2C_ADDR){
        //Read data from the address
        data = ReadRegister(d);
        state = e_I2C_DATA;
    }
    else{
        
    }
}


/*
 * Returns the content of the register at the specified address
 */
static uint32_t ReadRegister(uint8_t address){

    switch(address){
        case _I2CS_CELL1:
            return BMS_GetCellVoltage(1);
        case _I2CS_CELL2:
            return BMS_GetCellVoltage(2);
        case _I2CS_CELL3:
            return BMS_GetCellVoltage(3);
        case _I2CS_BAT_VOLTAGE:
            return BMS_GetBatteryVoltage();
        case _I2CS_BMS_TEMP:
            return BMS_GetTemperature();
        case _I2CS_DISCH_CURRENT:
            return BMS_GetCurrent();
        case _I2CS_BAT_ENERGY:
            return BMS_GetEnergy();
        case _I2CS_BAT_OV_THRES:
            return BMS_GetOvervoltageThreshold();
        case _I2CS_BAT_UV_THRES:
            return BMS_GetUnderVoltageThreashold();
        case _I2CS_BAT_SOC:
            return BMS_GetSOC();
        case _I2CS_CHG_VOLTAGE:
            return CHG_GetChargeVoltage();
        case _I2CS_CHG_CURRENT:
            return CHG_GetChargeCurrent();
    }
    
    return 0;
}

/*
 * 
 */
static void WriteRegister(uint8_t address, uint32_t data){
    switch(address){
        case _I2CS_CELL1:   //Read only registers
        case _I2CS_CELL2:
        case _I2CS_CELL3:
        case _I2CS_BAT_VOLTAGE:
        case _I2CS_BMS_TEMP:
        case _I2CS_DISCH_CURRENT:
        case _I2CS_BAT_ENERGY:
        case _I2CS_BAT_OV_THRES:
        case _I2CS_BAT_UV_THRES:
            
        case _I2CS_CHG_VOLTAGE:
        case _I2CS_CHG_CURRENT:
            break;
    }
}