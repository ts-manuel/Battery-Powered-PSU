/*
 * File:    bms.c
 * Author:  Manuel
 * Date:    26/06/2020
 * Device:  PIC16LF18346
 * Rev:     1.2 2020
 *
 * Driver for the Texas Instruments BQ7692006PWR BMS
 * 
 */

#include "bms.h"
#include "leds.h"
#include "time.h"
#include "i2cMaster.h"

#define _BL_START_VOLTAGE   4100    //Voltage at with the balancing turns on (mV)
#define _BL_ALLOWED_UNBAL   15      //Maximum allowed voltage umbalance between cells (mV)
#define _EOC_CURRENT        300     //End Of Charge Current (mA)
#define _SOC_CALL_LOW       3200    //Battery volatge when EMPTY (mV)
#define _CC_GAIN            0.465f  //Coulomd Counter ADC Gain calibration
#define _CC_OFFSET          0.0f    //Coulomb Counter ADC Offset calibration
#define _START_CAPACITY     56.0f   //Initial battery capacity (wh)
#define _CHG_EFFICIENCY     0.95f   //Defined as the ratio between accumulated enercy during charge and during discharge 
#define _SOC_CALL_INTERVALL (60*24) //SOC Calibration intervall in minutes (60*24 = every 24 hours)
#define _SOC_LOOKUP_POINTS  3

#define HIGHEST_CELL_INDEX()    (cellVoltages[0] > cellVoltages[1] ?\
                                (cellVoltages[0] > cellVoltages[2] ? 0 : 2) :\
                                (cellVoltages[1] > cellVoltages[2] ? 1 : 2))

#define LOWEST_CELL_INDEX()     (cellVoltages[0] < cellVoltages[1] ?\
                                (cellVoltages[0] < cellVoltages[2] ? 0 : 2) :\
                                (cellVoltages[1] < cellVoltages[2] ? 1 : 2))

typedef struct{
    bool        state;
    uint32_t    setTime_ms;
} TimeFlag_t;

static const uint16_t OV_threshold = 4200;  //Over voltage threshold   (mV)
static const uint16_t UV_threshold = 2700;  //Under voltage threshold  (mV)
static uint16_t adcGain;            //Gain of the 14 bit ADC            (uV/LSB)
static uint16_t adcOffset;          //Offset of the 14 bit ADC          (mV)
static uint16_t cellVoltages[3];    //Voltage of each individual cell   (mV)
static uint16_t batteryVoltage;     //Voltage of the whole battery pack (mV)
static uint8_t  bmsTemperature;     //Temperature of the BMS IC         (°C)
static float    current;            //Charge current                    (A)
static volatile bool alert;         //Flag set by interrupt when alert pin goes HIGH 

static float    capacity;           //Battery capacity in                   (W/h)
static float    energy;             //Energy left into the battery          (W/h)
static uint8_t  SOC;                //Battery State Of Charge in percentage
static uint32_t sleepTime;          //Time of when the device entered sleep mode or the last SOC calibration
static bool     batteryEmpty;       //Set when thw battery is empty
static bool     chargeFromEmpty;    //Set when the battery is empty, cleared when battry is fully charged or charging is interrupted prematurely
const int16_t  SOC_LookUpV[_SOC_LOOKUP_POINTS] = {3000, 3500, 4050};
const int16_t  SOC_LookUpS[_SOC_LOOKUP_POINTS] = {0, 28, 100};

#define _RETRY_DELAY        1000    //One second between retries
static TimeFlag_t SCD_Flag = {false, 0};    //Short circuit detected flag
static TimeFlag_t OCD_Flag = {false, 0};    //Over current in discharge detected flag
static TimeFlag_t UVD_Flag = {false, 0};    //Under voltage detected flag
static TimeFlag_t OVD_Flag = {false, 0};    //Over voltage detected flag

//Static Functions
static void BMS_ProcesAlert(uint32_t time_ms);
static void BMS_ReadCellVoltageAndTemp(void);
static uint16_t BMS_ReadCellVoltageRegister(uint8_t reg);
static void BMS_EnableCoulombCounter(state_t state);
static void BMS_TriggerCoulombCounter(void);
static void BMS_Balance(state_t state);
static void BMS_ActivateBalanceFET(int8_t cell);
static uint8_t BMS_EstimateSOC(void);
static void BMS_UpdateSOC(state_t state);

static bool BMS_WriteByte(uint8_t addr, uint8_t data);
static uint8_t BMS_ReadByte(uint8_t addr);
static uint16_t BMS_ReadWord(uint8_t addr);

/* 
 * Initializes the BMS IC
 * Returns true if the initialization completed successfully
 */
bool BMS_Initialize(void){
    bool error = false;
    
    //Initialize global variables
    batteryEmpty = false;
    chargeFromEmpty = false;
    alert = true;
    energy = 0;
    SOC = 0;
    
    //Initialize registers
    error |= BMS_WriteByte(_BMS_SYS_STAT, 0xFF);     //Clear status bits
    error |= BMS_WriteByte(_BMS_CELLBAL1, 0x00);     //Cell balancing OFF
    error |= BMS_WriteByte(_BMS_SYS_CTRL1, 0x10);    //ADC enabled, Use internal temperature
    error |= BMS_WriteByte(_BMS_SYS_CTRL2, 0x43);    //Coulomb Counter continuous operation, DSC FET ON, CHG FET ON
    error |= BMS_WriteByte(_BMS_PROTECT1, 0x9F);     //Short Circuit in Discharge delay 400 uS, Short Circuit Threshold 20A
    error |= BMS_WriteByte(_BMS_PROTECT2, 0x7F);     //Over Current in Discharge delay 1280 mS, Over Current in Discharge 5A (Current limit set to 10A because the ADC reads double)
    error |= BMS_WriteByte(_BMS_PROTECT3, 0x00);     //Under Voltage delay 1S, Over Voltage delay 1S
    error |= BMS_WriteByte(_BMS_CC_CFG, 0x19);
    
    //Read ADC Gain
    uint8_t adcGain1 = BMS_ReadByte(_BMS_ADCGAIN1);
    uint8_t adcGain2 = BMS_ReadByte(_BMS_ADCGAIN2);
    uint8_t adcGain3 = ((adcGain1 << 1) & 0x18) | ((adcGain2 >> 5) & 0x07);
    adcGain = (uint16_t)adcGain3 + 365;
    //Read ADC Offset
    adcOffset = BMS_ReadByte(_BMS_ADCOFFSET);
    
    //Set OV UV
    uint16_t overVoltageTh = ((uint32_t)(OV_threshold - adcOffset) * 1000) / adcGain;
    uint16_t underVoltageTh = ((uint32_t)(UV_threshold - adcOffset) * 1000) / adcGain;
    
    error |= BMS_WriteByte(_BMS_OV_TRIP, overVoltageTh >> 4);
    error |= BMS_WriteByte(_BMS_UV_TRIP, underVoltageTh >> 4);
    
    //Turn off balancing
    BMS_ActivateBalanceFET(-1);

    //Read voltages and compute SOC
    BMS_ReadCellVoltageAndTemp();
    
    //Initialize battery capacity and estimate state of charge
    capacity = _START_CAPACITY;
    sleepTime = 0;
    SOC = BMS_EstimateSOC();
    energy = capacity * ((float)SOC / 100.0f);
    
    return !error;
}

/*
 * Reads Battery voltages, charge current and dials with faults,
 * this function must be called in the main loop
 */
void BMS_Update(state_t state){
    static uint32_t last = 0;
    uint32_t time_ms = TIME_Millis();
    uint32_t time_min = TIME_Minutes();
    
    //Process alert
    if(alert){
        alert = false;
        BMS_ProcesAlert(time_ms);
    }
    
    //Enable / Disable coulomb counter
    BMS_EnableCoulombCounter(state);
    
    //Read battery info and compute SOC every second
    if(state != e_STATE_IDLE && (time_ms - last >= 1000)){
        last = time_ms;
        BMS_ReadCellVoltageAndTemp();   //Read voltage and temperature
    }
    
    //Compute SOC
    if(state == e_STATE_IDLE){
        if(time_min - sleepTime >= _SOC_CALL_INTERVALL){
            sleepTime = time_min;
            
            //Calibrate SOC
            SOC = BMS_EstimateSOC();
            energy = capacity * ((float)SOC / 100.0f);
        }
    }
    else{
        sleepTime = time_min;
        
        //Update SOC
        BMS_UpdateSOC(state);
    }
    
    //Keep track of wheter the battery has been charging from completelly empty or not
    if(batteryEmpty){
        if(state == e_STATE_CHARGING){
            batteryEmpty = false;
            chargeFromEmpty = true;
        }
    }
    else if(chargeFromEmpty && state != e_STATE_CHARGING){
        chargeFromEmpty = false;
    }
    
    //Balance battery
    BMS_Balance(state);
        
    //If a short circuit has been detected wait 1S and try re enable power
    if(SCD_Flag.state && (time_ms - SCD_Flag.setTime_ms) > _RETRY_DELAY){
        uint8_t reg = BMS_ReadByte(_BMS_SYS_CTRL2) & ~_SYS_DSG_ON;
        BMS_WriteByte(_BMS_SYS_CTRL2, reg | _SYS_DSG_ON);
        SCD_Flag.state = false;
        printf("Recovering from Short Circuit: enabling DSG FET\n");
    }

    //If a over current has been detected wait 1S and try re enable power
    if(OCD_Flag.state && (time_ms - OCD_Flag.setTime_ms) > _RETRY_DELAY){
        uint8_t reg = BMS_ReadByte(_BMS_SYS_CTRL2) & ~_SYS_DSG_ON;
        BMS_WriteByte(_BMS_SYS_CTRL2, reg | _SYS_DSG_ON);
        OCD_Flag.state = false;
        printf("Recovering from Over Current: enabling DSG FET\n");
    }

    //If an under voltage has been detected wait 1S and try re enable power
    if(UVD_Flag.state && (time_ms - UVD_Flag.setTime_ms) > _RETRY_DELAY){
        uint16_t lowestCellVolatge = 5000;
        for(uint8_t i = 0; i < 3; i++){
            if(cellVoltages[i] < lowestCellVolatge)
                lowestCellVolatge = cellVoltages[i];
        }

        if(lowestCellVolatge > BMS_GetUnderVoltageThreashold() + 200){
            uint8_t reg = BMS_ReadByte(_BMS_SYS_CTRL2) & ~_SYS_DSG_ON;
            BMS_WriteByte(_BMS_SYS_CTRL2, reg | _SYS_DSG_ON);
            printf("Recovering from Under Voltage: enabling DSG FET\n");
            //Calibrate battery empty
            energy = 0;
            batteryEmpty = true;
            UVD_Flag.state = false;
        }
        else{
            UVD_Flag.state = true;
            UVD_Flag.setTime_ms = time_ms;
        }
    }

    //If an over voltage has been detected wait 1S and try re enable power
    if(OVD_Flag.state  && (time_ms - OVD_Flag.setTime_ms) > _RETRY_DELAY){
        uint16_t highestCellVoltage = 0;
        for(uint8_t i = 0; i < 3; i++){
            if(cellVoltages[i] > highestCellVoltage)
                highestCellVoltage = cellVoltages[i];
        }

        if(highestCellVoltage < BMS_GetOvervoltageThreshold() - 200){
            uint8_t reg = BMS_ReadByte(_BMS_SYS_CTRL2) & ~_SYS_CHG_ON;
            BMS_WriteByte(_BMS_SYS_CTRL2, reg | _SYS_CHG_ON);
            OVD_Flag.state = false;
            printf("Recovering from Over Voltage: enabling CHG FET\n");
        }
        else{
            OVD_Flag.state = true;
            OVD_Flag.setTime_ms = time_ms;
        }
    }
}

/* 
 * ISR called when the ALLERT pin goes high
 */
void BMS_AlertISR(void){
    alert = true;
}

/* 
 * Enable or disable coulomb counter
 */
static void BMS_EnableCoulombCounter(state_t state){
    static bool CC_Enabled = true;
    uint8_t reg;
    
    if(state == e_STATE_IDLE && CC_Enabled){
        reg = BMS_ReadByte(_BMS_SYS_CTRL2);
        BMS_WriteByte(_BMS_SYS_CTRL2, reg & ~_SYS_CC_EN);
        current = 0;
        CC_Enabled = false;
    }
    else if(state != e_STATE_IDLE && !CC_Enabled){
        reg = BMS_ReadByte(_BMS_SYS_CTRL2);
        BMS_WriteByte(_BMS_SYS_CTRL2, reg | _SYS_CC_EN);
        CC_Enabled = true;
    }
}

/*
 * Triggers a Coulomb conversion
 */
static void BMS_TriggerCoulombCounter(void){
    uint8_t reg = BMS_ReadByte(_BMS_SYS_CTRL2);
    reg |= _SYS_CC_ONESHOT;
    BMS_WriteByte(_BMS_SYS_CTRL2, reg);
}

/*
 * Read status register and process alert condition
 */
static void BMS_ProcesAlert(uint32_t time_ms){
    uint8_t sysStat = BMS_ReadByte(_BMS_SYS_STAT);
    
    if(sysStat & _SYS_CC_READY){        //Coulomb counter sample ready
        int16_t CCValue = BMS_ReadWord(_BMS_CC_HI);
        
        current = (float)CCValue  * (0.00000844f / 0.01f) * _CC_GAIN + _CC_OFFSET;
        float de = (current * ((float)batteryVoltage / 1000.0f)) * (0.25f * (1.0f / 3600.0f));

        energy += (current > 0.0f) ? de * _CHG_EFFICIENCY : de;
    }
    if(sysStat & _SYS_DEVICE_XREADY){   //Internal chip fault indicator
        printf("BMS_SYS_InternalFault\n");
    }
    if(sysStat & _SYS_OVRD_ALLERT){     //External pin ALLERT overload
        printf("BMS_SYS_ExternalAllertOverload\n");
    }
    if(sysStat & _SYS_UV){              //Under Voltage detected
        UVD_Flag.state = true;
        UVD_Flag.setTime_ms = time_ms;
        printf("BMS_SYS_UV Detected\n");
    }
    if(sysStat & _SYS_OV){              //Over voltage detected
        OVD_Flag.state = true;
        OVD_Flag.setTime_ms = time_ms;
        printf("BMS_SYS_OV Detected\n");
    }
    if(sysStat & _SYS_SCD){             //Short Circuit in Discharge detected
        SCD_Flag.state = true;
        SCD_Flag.setTime_ms = time_ms;
        printf("BMS_SYS_SC Detected\n");
    }
    if(sysStat & _SYS_OCD){             //Over Current in Discharge detected
        OCD_Flag.state = true;
        OCD_Flag.setTime_ms = TIME_Millis();
        printf("BMS_SYS_OC Detected\n");
    }
    
    //Clear all errors
    BMS_WriteByte(_BMS_SYS_STAT, 0xFF);
}

/*
 * Reads the battery voltage and temperature
 */
static void BMS_ReadCellVoltageAndTemp(void){
    //Read voltages
    cellVoltages[2] = BMS_ReadCellVoltageRegister(_BMS_VC1_HI);
    cellVoltages[1] = BMS_ReadCellVoltageRegister(_BMS_VC2_HI);
    cellVoltages[0] = BMS_ReadCellVoltageRegister(_BMS_VC5_HI);
    batteryVoltage = (uint32_t)cellVoltages[0] + (uint32_t)cellVoltages[1] + (uint32_t)cellVoltages[2];
    
    //Read  DIE temperature
    int32_t val = BMS_ReadWord(_BMS_TS1_HI) & 0x3FFF;
    bmsTemperature = (310714 - val * 91) / 1000;
}

/*
 * Returns the value read from the Cell ADC register
 */
static uint16_t BMS_ReadCellVoltageRegister(uint8_t reg){
    return ((uint32_t)(BMS_ReadWord(reg) & 0x3FFF) * adcGain) / 1000 + adcOffset;
}

/*
 * Monitor cell voltage during charge and balance if needed
 */
static void BMS_Balance(state_t state){
    static int8_t balancingCellNumber = -1;
    int8_t hightestCellIndx = HIGHEST_CELL_INDEX();
    int8_t lowestCellIndx = LOWEST_CELL_INDEX();
    uint16_t highestCellVoltage = cellVoltages[hightestCellIndx];
    uint16_t lowestCellVoltage = cellVoltages[lowestCellIndx];
    uint16_t deltaV = highestCellVoltage - lowestCellVoltage;
    
    if(state == e_STATE_CHARGING){
        //Enable balancing when cell voltage > 4.1V and deltaV > 15mV,
        //Disable balancing when deltaV == 0
        if(balancingCellNumber == -1){
            if(highestCellVoltage > _BL_START_VOLTAGE && deltaV > _BL_ALLOWED_UNBAL){

                //Activate balancing FET
                BMS_ActivateBalanceFET(hightestCellIndx);
                balancingCellNumber = hightestCellIndx;
            }
        }
        else{
            int16_t bl_voltage = (int16_t)BMS_GetCellVoltage(balancingCellNumber);
            int16_t lw_voltage = (int16_t)lowestCellVoltage;

            //Disable balancing when cell voltage equals lowest cell voltage
            if(bl_voltage - lw_voltage <= 0){
               BMS_ActivateBalanceFET(-1);
               balancingCellNumber = -1;
            }
        }
    }
    else if(state != e_STATE_CHARGING && balancingCellNumber != -1){
        BMS_ActivateBalanceFET(-1);
        balancingCellNumber = -1;
    }
}

/*
 * Activates the balancing FET for the cell specified (0, 1, 2),
 * if cell == -1 no cell is balanced
 */
static void BMS_ActivateBalanceFET(int8_t cell){
    switch(cell){
        case 1:
            BMS_WriteByte(_BMS_CELLBAL1, 0x10);
            LEDS_SetState(e_LED_BT1_BL, true);
            LEDS_SetState(e_LED_BT2_BL, false);
            LEDS_SetState(e_LED_BT3_BL, false);
            break;
        case 2:
            BMS_WriteByte(_BMS_CELLBAL1, 0x02);
            LEDS_SetState(e_LED_BT1_BL, false);
            LEDS_SetState(e_LED_BT2_BL, true);
            LEDS_SetState(e_LED_BT3_BL, false);
            break;
        case 3:
            BMS_WriteByte(_BMS_CELLBAL1, 0x01);
            LEDS_SetState(e_LED_BT1_BL, false);
            LEDS_SetState(e_LED_BT2_BL, false);
            LEDS_SetState(e_LED_BT3_BL, true);
            break;
        default:
            BMS_WriteByte(_BMS_CELLBAL1, 0x00);
            LEDS_SetState(e_LED_BT1_BL, false);
            LEDS_SetState(e_LED_BT2_BL, false);
            LEDS_SetState(e_LED_BT3_BL, false);
            break;
    }
}

/*
 * Estimates the State Of Carge based upon the battery voltage
 */
static uint8_t BMS_EstimateSOC(void){
    uint8_t soc;
    int32_t x0, x1, y0, y1;
    int32_t v = (int32_t)(batteryVoltage / 3);
    
    //Return if voltage is out off range
    if(v <= SOC_LookUpV[0])
        return 0;
    if(v >= SOC_LookUpV[_SOC_LOOKUP_POINTS - 1])
        return 100;
    
    for(uint8_t i = 0; i < _SOC_LOOKUP_POINTS; i++){
        if(v >= SOC_LookUpV[i]){
            x0 = (int32_t)SOC_LookUpV[i];
            x1 = (int32_t)SOC_LookUpV[i+1];
            y0 = (int32_t)SOC_LookUpS[i];
            y1 = (int32_t)SOC_LookUpS[i+1];
        }
    }
    
    soc = ((((y1 - y0) * 100) / (x1 - x0))*(v - x0)) / 100 + y0;

    return (uint8_t)soc;
}

/*
 * Updates Battery State Of Charge
 */
static void BMS_UpdateSOC(state_t state){
    static state_t lastState = e_STATE_IDLE;
    static bool full = false;
    float soc;
    uint16_t celVoltage = batteryVoltage / 3;
    uint32_t time = TIME_Millis();
    static uint32_t last = 0;
    
    //Detect when the battery is fully charged
    if(state == e_STATE_CHARGING){
        if(lastState == e_STATE_CHARGING && time - last > 1000){
            if(current < ((float)_EOC_CURRENT / 1000.f) && celVoltage > 3700){
                if(chargeFromEmpty){
                    chargeFromEmpty = false;
                    capacity = energy;
                }
                else{
                    energy = capacity;
                }
                full = true;
            }
        }
        else if(lastState != e_STATE_CHARGING){
            last = time;
        }
    }
    else{
        full = false;
    }
    lastState = state;
    
    //Calibrate battery stored energy when empty
    if(state == e_STATE_DISCHARGING && celVoltage < _SOC_CALL_LOW){
        energy = 0;
        batteryEmpty = true;
    }
    
    //Clamp energy
    if(state != e_STATE_CHARGING){
        energy = energy > capacity ? capacity : energy;
    }
    
    //Compute State Of Charge
    soc = (energy / capacity) * 100.f;
    if(state == e_STATE_CHARGING && !full)
        soc = soc < 100.0f ? soc : 99.0f;
    
    //Clamp SOC between 0 and 100
    soc = soc > 100.0f ? 100.0f : soc;
    soc = soc < 0.0f ? 0.0f : soc;
    SOC = (uint8_t)soc;
}

/*
 * Writes 1 byte to the BMS trough the I2C bus
 */
static bool BMS_WriteByte(uint8_t addr, uint8_t data){
    uint8_t buffer[2];
    buffer[0] = addr;
    buffer[1] = data;
    
    i2c_result_t res = I2C_Write(_BMS_ADDRESS, buffer, 2);

    return res != e_I2C_OK;
}

/*
 * Read 1 byte from the BMS trough the I2C bus
 */
static uint8_t BMS_ReadByte(uint8_t addr){
    uint8_t data;

    I2C_Write(_BMS_ADDRESS, &addr, 1);
    I2C_Read(_BMS_ADDRESS, &data, 1);
    
    return data;
}

/*
 * Read 2 byte from the BMS trough the I2C bus
 */
static uint16_t BMS_ReadWord(uint8_t addr){
    uint8_t data[2];

    I2C_Write(_BMS_ADDRESS, &addr, 1);
    I2C_Read(_BMS_ADDRESS, data, 2);
    
    return ((uint16_t)data[0] << 8) | (uint16_t)data[1];
}


/*
 * I2C slave interface
 */
inline uint16_t BMS_GetCellVoltage(uint8_t cell){
    return cellVoltages[cell - 1];
}
inline uint16_t BMS_GetBatteryVoltage(void){
    return batteryVoltage;
}
inline uint16_t BMS_GetTemperature(void){
    return bmsTemperature;
}
inline int16_t BMS_GetCurrent(void){
    return (int16_t)(current * 1000.0f);    //Return current in (mA)
}
inline int32_t BMS_GetEnergy(void){
    return (int32_t)(energy * 1000.0f);     //Return energy in (mW/h)
}
inline int32_t  BMS_GetCapacity(void){
    return (int32_t)(capacity * 1000.0f);   //Return capacity in (mW/h)
}
inline uint16_t BMS_GetOvervoltageThreshold(void){
    return OV_threshold;
}
inline uint16_t BMS_GetUnderVoltageThreashold(void){
    return UV_threshold;
}
inline uint8_t  BMS_GetSOC(void){
    return SOC;
}