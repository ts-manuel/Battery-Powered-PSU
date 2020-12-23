/*
 * File:    types.h
 * Author:  Manuel
 * Date:    26/06/2020
 * Device:  PIC16LF18346
 * Rev:     1.2 2020
 *
 */

#ifndef _SRC_TYPES_H_
#define	_SRC_TYPES_H_

typedef enum {
    e_STATE_INIT,           //Initialization
    e_STATE_IDLE,           //Power supply is off and not connected to external power, controller in low power mode
    e_STATE_CHARGING,       //Power supply on/off and connected to an external power source
    e_STATE_DISCHARGING,    //Power supply is on and not connected to an external power source
} state_t;

#endif	/* _SRC_TYPES_H_ */

