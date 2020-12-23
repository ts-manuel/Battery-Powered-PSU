/*
 * File:    leds.c
 * Author:  Manuel
 * Date:    26/06/2020
 * Device:  PIC16LF18346
 * Rev:     1.2 2020
 *
 * LEDs manipulation functions
 * 
 */

#include "leds.h"
#include "bms.h"
#include "time.h"

#define LED_FULL_SetHigh()      IO_LED0_SetHigh()
#define LED_FULL_SetLow()       IO_LED0_SetLow()
#define LED_FULL_Set(x)         { IO_LED0_PORT = (x); }
#define LED_BT3_BL_SetHigh()    IO_LED1_SetHigh()
#define LED_BT3_BL_SetLow()     IO_LED1_SetLow()
#define LED_BT3_BL_Set(x)       { IO_LED1_PORT = (x); }
#define LED_BT3_CH_SetHigh()    IO_LED2_SetHigh()
#define LED_BT3_CH_SetLow()     IO_LED2_SetLow()
#define LED_BT3_CH_Set(x)       { IO_LED2_PORT = (x); }
#define LED_BT2_BL_SetHigh()    IO_LED3_SetHigh()
#define LED_BT2_BL_SetLow()     IO_LED3_SetLow()
#define LED_BT2_BL_Set(x)       { IO_LED3_PORT = (x); }
#define LED_BT2_CH_SetHigh()    IO_LED4_SetHigh()
#define LED_BT2_CH_SetLow()     IO_LED4_SetLow()
#define LED_BT2_CH_Set(x)       { IO_LED4_PORT = (x); }
#define LED_BT1_BL_SetHigh()    IO_LED5_SetHigh()
#define LED_BT1_BL_SetLow()     IO_LED5_SetLow()
#define LED_BT1_BL_Set(x)       { IO_LED5_PORT = (x); }
#define LED_BT1_CH_SetHigh()    IO_LED6_SetHigh()
#define LED_BT1_CH_SetLow()     IO_LED6_SetLow()
#define LED_BT1_CH_Set(x)       { IO_LED6_PORT = (x); }

#define _LED_COUNT  7

typedef struct{
    bool state; //LED ON or OFF
    bool blink; //LED has to blink
} led_data_t;

//Global variables
static led_data_t leds[_LED_COUNT];
static led_state_t state = e_LED_IDLE;
static uint32_t setTime_ms;

/*
 * Initialize LEDs
 */
void LEDS_Initialize(void) {
    LEDS_SetToDefault();
}

/*
 * Set the LEDs to default state
 */
void LEDS_SetToDefault(void) {
    for (uint8_t i = 0; i < _LED_COUNT; i++) {
        leds[i].state = false;
        leds[i].blink = false;
    }

    LEDS_ClearAll();
}

/*
 * Switch to battery level display mode
 */
void LEDS_ShowBatteryLevel(void) {
    setTime_ms = TIME_Millis();
    state = e_LED_BATTERY_LEVEL;
    LEDS_Update();
}

/*
 * Set LED state
 */
void LEDS_SetState(led_t led, bool b){
    leds[(uint8_t)led].state = b;
    LEDS_Update();
}

/*
 * Set LED blink mode
 */
void LEDS_SetBlinkMode(led_t led, bool b){
    leds[(uint8_t)led].blink = b;
    LEDS_Update();
}

/*
 * Function called periodically to update the state of the LEDs
 */
led_state_t LEDS_Update(void) {
    //Change state
    if(TIME_Millis() - setTime_ms > 2000)
        state = e_LED_IDLE;

    //Drive LEDs according to the state
    if (state == e_LED_BATTERY_LEVEL) {
        uint8_t soc = BMS_GetSOC();
        
        LED_FULL_Set(soc > 90);
        LED_BT3_BL_Set(soc > 75);
        LED_BT3_CH_Set(soc > 60);
        LED_BT2_BL_Set(soc > 45);
        LED_BT2_CH_Set(soc > 30);
        LED_BT1_BL_Set(soc > 15);
        LED_BT1_CH_Set(true);
    } else {
        static uint32_t last = 0;
        uint32_t time = TIME_Millis();
        
        //Toggle LEDs
        if(time - last > 1000){
            last = time;
            
            for (uint8_t i = 0; i < _LED_COUNT; i++) {
                if (leds[i].blink)
                    leds[i].state = !leds[i].state;
            }
        }

        //Update states
        IO_LED0_PORT = leds[0].state;
        IO_LED1_PORT = leds[1].state;
        IO_LED2_PORT = leds[2].state;
        IO_LED3_PORT = leds[3].state;
        IO_LED4_PORT = leds[4].state;
        IO_LED5_PORT = leds[5].state;
        IO_LED6_PORT = leds[6].state;
    }

    return state == e_LED_BATTERY_LEVEL;
}

/*
 * Clear all the LEDs
 */
void LEDS_ClearAll(void) {
    LED_FULL_SetLow();
    LED_BT3_BL_SetLow();
    LED_BT3_CH_SetLow();
    LED_BT2_BL_SetLow();
    LED_BT2_CH_SetLow();
    LED_BT1_BL_SetLow();
    LED_BT1_CH_SetLow();
}