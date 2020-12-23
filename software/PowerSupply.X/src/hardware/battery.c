/* 
 * File:    battery.c
 * Author:  Manuel
 * Date:    31/10/2018
 * 
 * Comments:
 */

#include "battery.h"
#include "debug/log.h"
#include <stdio.h>

BatteryData_t BatteryData;

typedef enum {
    e_v1,
    e_v2,
    e_v3,
    e_current,
    e_SOC,
    e_energy,
    e_capacity
} State_t;


static float* GetFloatPointer(BatteryData_t* data, State_t state);
static State_t NextState(State_t state);


void Battery_Update(void){
    static State_t state = e_v1;
    static BatteryData_t temp;
    static char str[16];
    static int charCount = 0;
    
    //If the RX buffer has data
    if(UART2_TransferStatusGet() & UART2_TRANSFER_STATUS_RX_DATA_PRESENT){
        //Read character by character until eater ';' or '\n' are received
        do{
            char c = UART2_Read();
            if(c == ';' || c == '\n'){
                str[charCount] = 0;
                float* fp = GetFloatPointer(&temp, state);
                sscanf(str, "%f", fp);
                
                //Update values if received correctly
                if(c == '\n' && state == e_capacity)
                    BatteryData = temp;
                
                //Change state
                if(c == ';')
                    state = NextState(state);
                else
                    state = e_v1;
                
                charCount = 0;
            }
            else{
                str[charCount++] = c;
            }
        } while(UART2_TransferStatusGet() & UART2_TRANSFER_STATUS_RX_DATA_PRESENT);
    }
}

static float* GetFloatPointer(BatteryData_t* data, State_t state){
    switch(state){
        case e_v1:
            return &data->voltages[0];
        case e_v2:
            return &data->voltages[1];
        case e_v3:
            return &data->voltages[2];
        case e_current:
            return &data->current;
        case e_SOC:
            return &data->SOC;
        case e_energy:
            return &data->energy;
        case e_capacity:
            return &data->capacity;
        default:
            return NULL;
    }
}

static State_t NextState(State_t state){
    if(state != e_capacity)
        return state + 1;
    else
        return e_v1;
}


//
//#include "battery.h"
//#include "hardware/timer.h"
//#include "debug/log.h"
//#include "I2C_master.h"
//
//static uint8_t GetUnsigned8(uint8_t address);
//static uint16_t GetUnsigned16(uint8_t address);
//static int16_t GetSigned16(uint8_t address);
//static uint32_t GetUnsigned32(uint8_t address);
//
//uint8_t BATTERY_GetSOC(void){
//    return GetUnsigned8(_I2CS_BAT_SOC);
//}
//
////Returns the voltage of the n cell
//float BATTERY_GetCellVoltage(uint8_t n){
//    return (float)GetUnsigned16(_I2CS_CELL0 + (n - 1)) / 1000.0f;
//}
//
////Returns the voltage of the entire battery pack
//float BATTERY_GetVoltage(void){
//    return (float)GetUnsigned16(_I2CS_BAT_VOLTAGE) / 1000.0f;
//}
//
////Returns the temperature of the BMS IC
//float BATTERY_GetTemperature(void){
//    return (float)GetUnsigned16(_I2CS_BMS_TEMP) / 1000.0f;
//}
//
////Returns the discharging current (A)
//float BATTERY_GetDischargeCurrent(void){
//    return (float)GetSigned16(_I2CS_DISCH_CURRENT) / 1000.0f;
//}
//
////Returns the stored energy inside the battery (Wh)
//float BATTERY_GetSoredEnergy(void){
//    return (float)GetUnsigned32(_I2CS_BAT_ENERGY) / 1000.0f;
//}
//
////Returns the Overvoltage
//float BATTERY_GetOverVoltageThreshold(void){
//    return 0;
//}
//
//float BATTERY_GetUnderVoltageThreshold(void){
//    return 0;
//}
//
////Returns the Set end of charge voltage (V)
//float BATTERY_GetEndOfChargeVoltage(void){
//    return (float)GetUnsigned16(_I2CS_CHG_VOLTAGE) / 1000.0f;
//}
//
////Returns the Set Charge current (A)
//float BATTERY_GetChargeCurrent(void){
//    return (float)GetUnsigned16(_I2CS_CHG_CURRENT) / 1000.0f;
//}
//
//static uint8_t GetUnsigned8(uint8_t address){
//    /*uint8_t data;
//    
//    I2C_Read_8(_BATTERY_I2C_ADDRESS, address, 1, &data);
//            
//    return data;*/
//    
//    return 0;
//}
//
//static int16_t GetSigned16(uint8_t address){
//    return (int16_t)GetUnsigned16(address);
//}
//
//static uint16_t GetUnsigned16(uint8_t address){
//    /*uint16_t data;
//    i2c_result_t result;
//    
//    result = I2C_Read_8(_BATTERY_I2C_ADDRESS, address, 2, (uint8_t*)&data);
//    if(result != e_I2C_OK){
//        LOG_PRINT_ERROR("BATTERY_GetUnsigend16 I2C2_M_Read() returned: %d\n", result);
//        return 0;
//    }
//    
//    return data;*/
//    
//    return 0;
//}
//
//static uint32_t GetUnsigned32(uint8_t address){
//    /*uint32_t data;
//    i2c_result_t result;
//    
//    result = I2C_Read_8(_BATTERY_I2C_ADDRESS, address, 4, (uint8_t*)&data);
//    if(result != e_I2C_OK){
//        LOG_PRINT_ERROR("BATTERY_GetUnsigned32 I2C2_M_Read() returned: %d\n", result);
//        return 0;
//    }
//    
//    return data;*/
//    
//    return 0;
//}