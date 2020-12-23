/*
 * File:    leds.h
 * Author:  Manuel
 * Date:    26/06/2020
 * Device:  PIC16LF18346
 * Rev:     1.2 2020
 *
 * LEDs manipulation functions
 * 
 */

#ifndef _SRC_LEDS_H
#define	_SRC_LEDS_H

#include <mcc.h>
#include <stdbool.h>

typedef enum {
    e_LED_FULL,
    e_LED_BT3_BL,
    e_LED_BT3_CH,
    e_LED_BT2_BL,
    e_LED_BT2_CH,
    e_LED_BT1_BL,
    e_LED_BT1_CH,
} led_t;

typedef enum {
    e_LED_IDLE,
    e_LED_BATTERY_LEVEL
} led_state_t;


void LEDS_Initialize(void);
void LEDS_SetToDefault(void);
void LEDS_ShowBatteryLevel(void);
void LEDS_SetState(led_t led, bool b);
void LEDS_SetBlinkMode(led_t led, bool b);
led_state_t LEDS_Update(void);
void LEDS_ClearAll(void);

#endif	/* _SRC_LEDS_H */

