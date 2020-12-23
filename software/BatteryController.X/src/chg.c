/*
 * File:    bms.c
 * Author:  Manuel
 * Date:    26/06/2020
 * Device:  PIC16LF18346
 * Rev:     1.2 2020
 *
 * Driver for the Texas Instruments BQ25700ARSNR Charge controller
 * 
 */

#include "chg.h"
#include "bms.h"
#include "leds.h"
#include "time.h"
#include "i2cMaster.h"

static uint16_t chargeCurrent              = 3000;      //Charge current                    (mA)
static const uint16_t maxChargeCurrent     = 4000;      //Maximum allowed charge current    (mA)
static const uint16_t chargeVoltage        = (4120*3);  //Max charge voltage                (mV)
static const uint16_t minSystemVoltage     = 9000;      //Minimum system voltage            (mV)
static const uint16_t maxInputCurrent      = 4100;      //Maximum input current             (mA)
static const uint16_t minimumInputVoltage  = 9000;      //Minimum input voltage             (mV)

static const uint16_t _CHG_CHARGE_OPTION_0_INIT = 0
    | _CHG_OPTION0_EN_LWPWR
    | _CHG_OPTION0_WDTMR_ADJ_1 /*| _CHG_OPTION0_WDTMR_ADJ_0*/
    | _CHG_OPTION0_EN_OOA
    | _CHG_OPTION0_PWM_FREQ
    | _CHG_OPTION0_EN_LDO
    | _CHG_OPTION0_EN_IDPM
    | _CHG_OPTION0_CHRG_INHBIT;

static void CHG_WatchdogReset(void);
static bool CHG_IsEnabled(void);
static void CHG_WriteChargeCurrent(uint16_t current);
static void CHG_WriteChargeVoltage(uint16_t voltage);
static bool CHG_WriteWord(uint8_t addr, uint16_t data);
static uint16_t CHG_ReadWord(uint8_t addr);


/*
 * Initializes the CHG IC
 * Returns true if the initialization completed successfully
 */
bool CHG_Initialize(void){
    bool error = false;
    
    error |= CHG_WriteWord(_CHG_CHARGE_OPTION_0, 0x260C);  //0010 0110 0000 1100   WATCHDOG = 5sec, EN_OOA = 1, IADPT = 20x, IBAT = 16x, IDPM = OFF
    error |= CHG_WriteWord(_CHG_CHARGE_OPTION_1, 0x0211);  //0000 0010 0001 0001   Internal reference 2.3V,
    error |= CHG_WriteWord(_CHG_CHARGE_OPTION_2, 0x8238);  //1000 0010 0011 1000   Input overload time 10mS
    error |= CHG_WriteWord(_CHG_CHARGE_OPTION_3, 0x0000);  //0000 0000 0000 0000
    error |= CHG_WriteWord(_CHG_PROCHOT_OPTION_0, 0x4AD4); //0100 1010 1101 0100
    error |= CHG_WriteWord(_CHG_PROCHOT_OPTION_1, 0x5100); //0101 0001 0000 0000
    error |= CHG_WriteWord(_CHG_ADC_OPTION, 0xA07F);       //1010 0000 0111 1111  ADC continuous update
    CHG_WriteChargeCurrent(chargeCurrent);                                          //Charge current
    CHG_WriteChargeVoltage(chargeVoltage);                                          //Max charge voltage
    error |= CHG_WriteWord(_CHG_MIN_SYSTEM_VOLTAGE, (uint16_t)minSystemVoltage);             //Min system voltage
    error |= CHG_WriteWord(_CHG_I_IN_HOST, ((uint16_t)(maxInputCurrent / 50)) << 8);         //Maximum  allowed input current
    error |= CHG_WriteWord(_CHG_INPUT_VOLTAGE, (uint16_t)(minimumInputVoltage - 3200.0f ));  //Minimum input voltage
    error |= CHG_WriteWord(_CHG_OTG_VOLTAGE, 0x0000);
    error |= CHG_WriteWord(_CHG_OTG_CURRENT, 0x0000);
    
    uint16_t manufactureId = 0;
    manufactureId = CHG_ReadWord(_CHG_MANUFACTURE_ID);
    error |= manufactureId != 0x0040;
    
    //Put charger in low power mode
    CHG_EnableCharger(false);
    
    return !error;
}

/*
 * Updates the state of the charger,
 * this function must be called in the main loop
 */
void CHG_Update(state_t state){
    static uint32_t last = 0;
    uint32_t time = TIME_Millis();
    
    //Disable charger in IDLE state
    if(state == e_STATE_CHARGING){
        //Run every second
        if(time - last > 1000){
            last = time;
            //If the charger is enabled
            if(CHG_IsEnabled()){
                //If battery is full turn off charger
                if(BMS_GetSOC() == 100){
                    CHG_EnableCharger(false);
                    LEDS_SetToDefault();
                    printf("Battery FULL -> Turn OFF\n");
                }
                else{
                    //Turn ON charge LEDs and blink LED full
                    LEDS_SetState(e_LED_BT1_CH, true);      
                    LEDS_SetState(e_LED_BT2_CH, true);
                    LEDS_SetState(e_LED_BT3_CH, true);
                    LEDS_SetBlinkMode(e_LED_FULL, true);

                    //Reset charger watchdog timer
                    CHG_WatchdogReset();
                }
            }
            //Charger is not enabled but needs to be
            else if(BMS_GetSOC() < 95){
                CHG_EnableCharger(true);
                CHG_WatchdogReset();
                printf("Charger OFF -> Turn ON\n");
            }
            //Battery is fully charged
            else{
                LEDS_SetState(e_LED_FULL, true);    //LED_FULL ON
            }
        }
    }
}

/*
 * Enables charger if b == true else the charger is put into low power mode
 */
void CHG_EnableCharger(bool b){
    uint16_t reg = CHG_ReadWord(_CHG_CHARGE_OPTION_0);
    reg &= ~_CHG_OPTION0_CHRG_INHBIT;
    reg &= ~_CHG_OPTION0_EN_LWPWR;
    reg |= b ? 0 : _CHG_OPTION0_CHRG_INHBIT | _CHG_OPTION0_EN_LWPWR;
    
    CHG_WriteWord(_CHG_CHARGE_OPTION_0, reg);
}

/*
 * Changes the charge current
 */
void CHG_SetChargeCurrent(uint16_t current){
    chargeCurrent = current;
}

/*
 * Updates the charge current and voltage in order to reset the charger watchdog timer
 */
static void CHG_WatchdogReset(void){
    CHG_WriteChargeCurrent(chargeCurrent);
    CHG_WriteChargeVoltage(chargeVoltage);
}

/*
 * Returns true if the charger is enabled
 */
static bool CHG_IsEnabled(void){
    return !(CHG_ReadWord(_CHG_CHARGE_OPTION_0) & _CHG_OPTION0_CHRG_INHBIT);
}

/*
 * Writes the charge current value to the charger
 */
static void CHG_WriteChargeCurrent(uint16_t current){
    CHG_WriteWord(_CHG_CHARGE_CURRENT, (uint16_t)current);
}

/*
 * Writes the charge voltage value to the charger
 */
static void CHG_WriteChargeVoltage(uint16_t voltage){
    CHG_WriteWord(_CHG_MAX_CHARGE_VOLTAGE, (uint16_t)chargeVoltage);
}

/*
 * Write 2 bytes to the CHG trough the I2C bus
 */
static bool CHG_WriteWord(uint8_t addr, uint16_t data){
    uint8_t buffer[3];
    i2c_result_t res;
    
    buffer[0] = addr;
    buffer[1] = data;
    buffer[2] = data >> 8;
    
    res = I2C_Write(_CHG_ADDRESS, buffer, 3);
    
    return res != e_I2C_OK;
}

/*
 * Reads 2 bytes from the CHG trough the I2C bus
 */
static uint16_t CHG_ReadWord(uint8_t addr){
    uint8_t data[2];
    
    I2C_Write(_CHG_ADDRESS, &addr, 1);
    I2C_Read(_CHG_ADDRESS, data, 2);
    
    return ((uint16_t)data[1] << 8) | (uint16_t)data[0];
}


//I2C slave interface
inline uint16_t CHG_GetChargeVoltage(void){
    return chargeVoltage;
}
inline uint16_t CHG_GetChargeCurrent(void){
    return chargeCurrent;
}