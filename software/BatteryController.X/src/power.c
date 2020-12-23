/* 
 * File:    power.h
 * Author:  Manuel
 * Date:    10/04/2019
 */

#include "time.h"
#include "power.h"
#include "leds.h"
#include "bms.h"
#include "chg.h"

#define _EXCEL_LOG false
#define _LOG_VOLTAGES_ON_STANDBY    false
#define _LOG_VOLTAGES_ON_CHARGE     true
#define _LOG_VOLTAGES_ON_DISCHARGE  true
#define _STATUS_DURATION_MS 2000UL

//Static variables
const uint16_t lowVoltageThreshold = 2800;  //Below this the LEDs will start blink during discharge  (mV))
volatile TimedBool_t showStatus = {true, 0, _STATUS_DURATION_MS}; //Flag set when the button is pressed

//State Machine states
typedef enum {e_StandBy, e_Charging, e_Discharging} t_batteryState;
static t_batteryState batteryState;

//Static functions prototypes
static void StandBy(void);
static void Charging(void);
static void Discharging(void);
static t_batteryState PWR_ComputeNextState(void);
static void showBatteryCharge(void);
inline void printCellVoltages(void);

//Initialize the State Machine
void PWR_Initialize(void){
    batteryState = e_StandBy;
}

//Update the State Machine
inline void PWR_Update(void){
    switch(batteryState){
        case e_StandBy:
            StandBy();
            break;
        case e_Charging:
            Charging();
            break;
        case e_Discharging:
            Discharging();
            break;
    }
    
    //Change state
    batteryState = PWR_ComputeNextState();
    
    //Update variable time variables
    TIME_UpdateTimedBool(&showStatus);
}

/* State machine functions */
static void StandBy(void){
#if _LOG_VLTAGES_ON_STANDBY == true
    printf("State: StandBy, DischargeCurrent %d mA\t", -(int16_t)BMS_GetDischargeCurrent());
    printCellVoltages();
#endif
    LEDS_SetToDefault();
    
    if(showStatus.state){  //Light up the LEDs
        showBatteryCharge();
    }
}

static void Charging(void){
#if _EXCEL_LOG == true
    static uint8_t counter = 60;
    if(++counter >= 60){
        printf("%d;%d;%d;", BMS_GetCellVoltage(1), BMS_GetCellVoltage(2), BMS_GetCellVoltage(3));
        printf("%d;", BMS_GetDischargeCurrent());
        printf("\n");
        counter = 0;
    }
#elif _LOG_VOLTAGES_ON_CHARGE == true
    printf("State: Charging, Charge current: %d mA \t", (int16_t)BMS_GetDischargeCurrent());
    printCellVoltages();
#endif
    
    //LEDS_SetAllLow();
    
    //Monitor voltages
    uint16_t    hightestCellVoltage = 0;
    uint16_t    lowestCellVoltage   = 5000;
    uint8_t     hightestCellIndx = 0;
    for(uint8_t i = 1; i <= 3; i++){
        uint16_t cellVoltage = BMS_GetCellVoltage(i);
        
        if(cellVoltage > hightestCellVoltage){
            hightestCellVoltage = cellVoltage;
            hightestCellIndx = i;
        }
        
        if(cellVoltage < lowestCellVoltage){
            lowestCellVoltage = cellVoltage;
        }
    }
    
    uint16_t endOfChargeCellVoltage  = CHG_GetSetChargeVoltage() / 3;
    uint16_t overVoltageThreshold    = BMS_GetOvervoltageThreshold();
    
    
    if(CHG_IsEnabled()){                                                //If the charger is enabled
        if((BMS_GetDischargeCurrent() < ((int16_t)CHG_GetChargeCurrent() / 10) || 
            BMS_GetDischargeCurrent() < 400) &&
            hightestCellVoltage > (endOfChargeCellVoltage - 50)){       //If the battery is full
            CHG_EnableCharger(false);                                   //Turn off charger
            BMS_BalanceCell(-1);                                        //Turn off balancing FETs
            //printf("Battery FULL -> Turn OFF\n");
        }
        else{                                                           //Else check if balancing is needed
            //printf("Charger ON\n");
            LEDS_SetState(e_LED_BT1_CH, true);      //Turn ON charge LEDs
            LEDS_SetState(e_LED_BT2_CH, true);
            LEDS_SetState(e_LED_BT3_CH, true);
            LEDS_SetBlinkMode(e_LED_FULL, true);    //Blink FULL led
            
            //Check if balancing is needed
            int8_t balanceIndex = -1;
            if(hightestCellVoltage > endOfChargeCellVoltage)        //If the highest cell voltage is above the end of charge voltage
                balanceIndex = hightestCellIndx;                    //Enable balance FET
            else if(hightestCellVoltage > 4000 &&                   //If the highest cell voltage is greater than 4V and
                    (hightestCellVoltage - lowestCellVoltage) > 10) //the difference between the highest and lowest cell voltages is greater than 40mV
                balanceIndex = hightestCellIndx;                    //Enable balance FET
            
            //Activate LEDs
            LED_BT1_BL_SetLow();
            LED_BT2_BL_SetLow();
            LED_BT3_BL_SetLow();
            if(balanceIndex == 1) LEDS_SetState(e_LED_BT1_BL, true);
            if(balanceIndex == 2) LEDS_SetState(e_LED_BT2_BL, true);
            if(balanceIndex == 3) LED_BT3_BL_SetHigh();
            BMS_BalanceCell(balanceIndex);
            
            //Set an appropriate charge current
            if(hightestCellVoltage > (overVoltageThreshold - 10))   //If the highest cell voltage is above 4.190V
                CHG_ReduceChargeCurrent(true);                      //Reduce charge current
            /*else if((hightestCellVoltage > 4000) &&
                    (hightestCellVoltage - lowestCellVoltage) > 40) //If the difference between the highest and lowest cell voltage is greater than 60mV
                CHG_ReduceChargeCurrent(true);*/
            else if((hightestCellVoltage < (overVoltageThreshold - 40)
                    && (hightestCellVoltage - lowestCellVoltage) < 20)
                    || (hightestCellVoltage < 4000))
                CHG_ReduceChargeCurrent(false);
        }
    }
    //Charger is not enabled but needs to be
    else if(BMS_GetBatteryVoltage() < (CHG_GetSetChargeVoltage() - 100)){
        CHG_EnableLowPowerMode(true);
        CHG_EnableCharger(true);
        //printf("Charger OFF -> Turn ON\n");
    }
    //Battery is fully charged, charger is not needed
    else{
        LEDS_SetToDefault();
        LEDS_SetState(e_LED_FULL, true);         //LED_FULL ON
        CHG_EnableCharger(false);   //Turn off charger
        BMS_BalanceCell(-1);        //Turn off balancing FETs
        //printf("Battery FULL\n");
    }
    
    if(showStatus.state){  //Light up the LEDs
        showBatteryCharge();
    }
    
    CHG_WatchdogReset();   //Update charger parameters
}

static void Discharging(void){
#if _EXCEL_LOG == true
    static uint8_t counter = 60;
    if(++counter >= 60){
        counter = 0;
        printf("%d;%d;%d;", BMS_GetCellVoltage(1), BMS_GetCellVoltage(2), BMS_GetCellVoltage(3));
        printf("%d;", -BMS_GetDischargeCurrent());
        printf("\n");
    }
#elif _LOG_VOLTAGES_ON_DISCHARGE == true
    printf("State: Discharging, Discharge current: %d mA\t", -(int16_t)BMS_GetDischargeCurrent());
    printCellVoltages();
#endif
    
    LEDS_SetToDefault();
    
    //Blink the led that corresponds to the low cell
    if(BMS_GetCellVoltage(1) < lowVoltageThreshold)
        LED_BT1_CH_Blink();

    if(BMS_GetCellVoltage(2) < lowVoltageThreshold)
        LED_BT2_CH_Blink();

    if(BMS_GetCellVoltage(3) < lowVoltageThreshold)
        LED_BT3_CH_Blink();

    if(showStatus.state)  //Light up the LEDs
        showBatteryCharge();
}

static t_batteryState PWR_ComputeNextState(void){
    if(!IO_CHG_OK_GetValue())                   //Check if charger is present
        return e_Charging;                      //Go into charge state
    else if(BMS_GetDischargeCurrent() < -1){    //If discharge current is greater than 10mA
        if(batteryState != e_Discharging){
            BMS_BalanceCell(-1);
            CHG_EnableCharger(false);
            CHG_EnableLowPowerMode(true);
            CHG_WatchdogReset();
        }
        return e_Discharging;                   //Go into discharge state
    }
    else{                                       //else
        if(batteryState != e_StandBy){
            BMS_BalanceCell(-1);
            CHG_EnableCharger(false);
            CHG_EnableLowPowerMode(true);
            CHG_WatchdogReset();
        }
        return e_StandBy;                       //Go into standBy state
    }
}

static void showBatteryCharge(void){
    uint16_t batteryVoltage = BMS_GetBatteryVoltage();
    
    LEDS_SetToDefault();
    
    if(batteryVoltage > 4100 * 3)
        LEDS_SetState(e_LED_FULL, true);
    if(batteryVoltage > 3800 * 3)
        LED_BT3_BL_SetHigh();
    if(batteryVoltage > 3650 * 3)
        LEDS_SetState(e_LED_BT3_CH, true);
    if(batteryVoltage > 3450 * 3)
        LEDS_SetState(e_LED_BT2_BL, true);
    if(batteryVoltage > 3300 * 3)
        LEDS_SetState(e_LED_BT2_CH, true);
    if(batteryVoltage > 3150 * 3)
        LEDS_SetState(e_LED_BT1_BL, true);
    if(batteryVoltage > 3000 * 3)
        LEDS_SetState(e_LED_BT1_CH, true);
}

inline void printCellVoltages(void){
    printf("Cell1: %dmV, Cell2: %dmV, Cell3: %dmV\n", BMS_GetCellVoltage(1), BMS_GetCellVoltage(2), BMS_GetCellVoltage(3));
}

void PWR_ShowBatteryLevel(void){
    TIME_SetTimedBool(&showStatus);
}