/*
 * File:    bms.h
 * Author:  Manuel
 * Date:    26/06/2020
 * Device:  PIC16LF18346
 * Rev:     1.2 2020
 *
 * Driver for the Texas Instruments BQ25700ARSNR Charge controller
 * 
 */

#ifndef _CHG_H
#define	_CHG_H

#include <mcc.h>
#include "types.h"

#ifdef _BIT
#undef _BIT
#endif
#ifdef _BYTE
#undef _BYTE
#endif
#define _BIT(x) ((uint16_t)1 << x)
#define _BYTE(x) ((uint8_t)x)

#define _CHG_ADDRESS    (0x09)  //Address of the charger chip

/* _CHG_CHARGE_OPTION_0    (0x12) */
#define _CHG_OPTION0_EN_LWPWR           _BIT(15)    //Enable Low Power Mode
#define _CHG_OPTION0_WDTMR_ADJ_1        _BIT(14)    //WATCHDOG Timer Adjust, set maximum delay between consecutive write of charge voltage or cherge current:
#define _CHG_OPTION0_WDTMR_ADJ_0        _BIT(13)        //00b: Disable Watchdog Timer, 01b: Enabled 5sec, 10b: Enabled 88sec, 11b: Enabled 17sec
#define _CHG_OPTION0_IDPM_AUTO_DISABLE  _BIT(12)    //When CELL_BATPRESZ pin is LOW, the charger automatically disables the
                                                        //IDPM function by setting EN_IDPM (REG0x12[1]) to 0. The host can enable
                                                        //IDPM function later by writing EN_IDPM bit (REG0x12[1]) to 1.
                                                        //0b: Disable this function. IDPM is not disabled when CELL_BATPRESZ goes LOW. <default at POR>
                                                        //1b: Enable this function. IDPM is disabled when CELL_BATPRESZ goes LOW
#define _CHG_OPTION0_OTG_ON_CHRGOK      _BIT(11)    //Add OTG to CHRG_OK, Drive CHRG_OK to HIGH when the device is in OTG mode. 0b: Disable <default at POR>, 1b: Enable
#define _CHG_OPTION0_EN_OOA             _BIT(10)    //Out-of-Audio Enable, 0b: No limit of PFM burst frequency <default at POR>, 1b: Set minimum PFM burst frequency to above 25 kHz to avoid audio noise
#define _CHG_OPTION0_PWM_FREQ           _BIT(9)     //Switching Frequency, Two converter switching frequencies. One for small inductor and the other for big inductor.
                                                        //Recommend 800 kHz with 2.2 µH or 3.3 µH, and 1.2 MHz with 1 µH or 1.5 µH.
                                                        //0b: 1200 kHz
                                                        //1b: 800 kHz <default at POR>
#define _CHG_OPTION0_EN_LEARN           _BIT(5)     //LEARN function allows the battery to discharge while the adapter is present. It
                                                        //calibrates the battery gas gauge over a complete discharge/charge cycle.
                                                        //When the battery voltage is below battery depletion threshold, the system
                                                        //switches back to adapter input by the host. When CELL_BATPRESZ pin is
                                                        //LOW, the device exits LEARN mode and this bit is set back to 0.
                                                        //0b: Disable LEARN Mode <default at POR>
                                                        //1b: Enable LEARN Mode
#define _CHG_OPTION0_IADPT_GAIN         _BIT(4)     //IADPT Amplifier Ratio, The ratio of voltage on IADPT and voltage across ACP and ACN. 0b: 20× <default at POR>, 1b: 40×
#define _CHG_OPTION0_IBAT_GAIN          _BIT(3)     //IBAT Amplifier Ratio, The ratio of voltage on IBAT and voltage across SRP and SRN. 0b: 8×, 1b: 16× <default at POR>
#define _CHG_OPTION0_EN_LDO             _BIT(2)     //LDO Mode Enable
                                                        //When battery voltage is below minimum system voltage (REG0x3E()), the
                                                        //charger is in pre-charge with LDO mode enabled.
                                                        //0b: Disable LDO mode, BATFET fully ON. Precharge current is set by battery
                                                        //pack internal resistor. The system is regulated by the MaxChargeVoltage register.
                                                        //1b: Enable LDO mode, Precharge current is set by the ChargeCurrent register
                                                        //and clamped below 384 mA (2 cell ? 4 cell) or 2A (1 cell). The system is
                                                        //regulated by the MinSystemVoltage register. <default at POR>
#define _CHG_OPTION0_EN_IDPM            _BIT(1)     //IDPM Enable
                                                        //Host writes this bit to enable IDPM regulation loop. When the IDPM is disabled
                                                        //by the charger (refer to IDPM_AUTO_DISABLE), this bit goes LOW.
                                                        //0b: IDPM disabled
                                                        //1b: IDPM enabled <default at POR>
#define _CHG_OPTION0_CHRG_INHBIT        _BIT(0)     //Charge Inhibit
                                                        //When this bit is 0, battery charging will start with valid values in the
                                                        //MaxChargeVoltage register and the ChargeCurrent register.
                                                        //0b: Enable Charge <default at POR>
                                                        //1b: Inhibit Charge
/* _CHG_CHARGE_OPTION_1    (0x30) */
#define _CHG_OPTION1_EN_IBAT            _BIT(15)   //IBAT Enable
                                                        //Enable the IBAT output buffer. In low power mode (REG0x12[15] = 1), IBAT
                                                        //buffer is always disabled regardless of this bit value.
                                                        //0b Turn off IBAT buffer to minimize Iq <default at POR>
                                                        //1b: Turn on IBAT buffer
#define _CHG_OPTION1_EN_PROCHOT_LPWR_1  _BIT(14)   //Enable PROCHOT during battery only low power mode
#define _CHG_OPTION1_EN_PROCHOT_LPWR_0  _BIT(13)       //With battery only, enable IDCHG or VSYS in PROCHOT with low power
                                                        //consumption. Do not enable this function with adapter present. Refer to
                                                        //PROCHOT During Low Power Mode for more details.
                                                        //00b: Disable low power PROCHOT <default at POR>
                                                        //01b: Enable IDCHG low power PROCHOT
                                                        //10b: Enable VSYS low power PROCHOT
                                                        //11b: Reserved
#define _CHG_OPTION1_EN_PSYS            _BIT(12)   //PSYS Enable
                                                        //Enable PSYS sensing circuit and output buffer (whole PSYS circuit). In low
                                                        //power mode (REG0x12[15] = 1), PSYS sensing and buffer are always disabled
                                                        //regardless of this bit value.
                                                        //0b: Turn off PSYS buffer to minimize Iq <default at POR>
                                                        //1b: Turn on PSYS buffer
#define _CHG_OPTION1_RSNS_RAC           _BIT(11)    //Input sense resistor RAC. 0b: 10 m? <default at POR>, 1b: 20 m?
#define _CHG_OPTION1_RSNS_RSR           _BIT(10)    //Charge sense resistor RSR. 0b: 10 m? <default at POR>, 1b: 20 m?
#define _CHG_OPTION1_PSYS_RATIO         _BIT(9)     // PSYS Gain
                                                        //Ratio of PSYS output current vs total input and battery power with 10-m? sense resistor.
                                                        //0b: 0.25 µA/W
                                                        //1b: 1 µA/W <default at POR>
#define _CHG_OPTION1_CMP_REF            _BIT(7)     //Independent Comparator internal Reference. 0b: 2.3 V <default at POR>, 1b: 1.2 V
#define _CHG_OPTION1_CMP_POL            _BIT(6)     //Independent Comparator output Polarity
                                                        //0b: When CMPIN is above internal threshold, CMPOUT is LOW (internal hysteresis) <default at POR>
                                                        //1b: When CMPIN is below internal threshold, CMPOUT is LOW (external hysteresis)
#define _CHG_OPTION1_CMP_DEG_1          _BIT(5)     //Independent comparator deglitch time, only applied to the falling edge of CMPOUT (HIGH ? LOW).
#define _CHG_OPTION1_CMP_DEG_0          _BIT(4)        //00b: Independent comparator is disabled
                                                        //01b: Independent comparator is enabled with output deglitch time 1 µs <default at POR>
                                                        //10b: Independent comparator is enabled with output deglitch time of 2 ms
                                                        //11b: Independent comparator is enabled with output deglitch time of 5 sec
#define _CHG_OPTION1_FORCE_LATCHOFF     _BIT(3)     // Force Power Path Off
                                                        //When independent comparator triggers, charger turns off Q1 and Q4 (same as
                                                        //disable converter) so that the system is disconnected from the input source. At
                                                        //the same time, CHRG_OK signal goes to LOW to notify the system.
                                                        //0b: Disable this function <default at POR>
                                                        //1b: Enable this function
#define _CHG_OPTION1_EN_SHIP_DCHG       _BIT(1)     //Discharge SRN for Shipping Mode
                                                        //When this bit is 1, discharge SRN pin down below 3.8 V in 140 ms. When 140ms is over, this bit is reset to 0.
                                                        //0b: Disable shipping mode <default at POR>
                                                        //1b: Enable shipping mode
#define _CHG_OPTION1_AUTO_WAKEUP_EN     _BIT(0)     //Auto Wakeup Enable
                                                        //When this bit is HIGH, if the battery is below minimum system voltage
                                                        //(REG0x3E()), the device will automatically enable 128 mA charging current for
                                                        //30 mins. When the battery is charged up above minimum system voltage, charge
                                                        //will terminate and the bit is reset to LOW.
                                                        //0b: Disable
                                                        //1b: Enable <default at POR>
/* _CHG_CHARGE_OPTION_2    (0x31) */
#define _CHG_OPTION2_PKPWR_TOVLD_DEG_1  _BIT(15)    //Input Overload time in Peak Power Mode
#define _CHG_OPTION2_PKPWR_TOVLD_DEG_0  _BIT(14)        //00b: 1 ms <default at POR>
                                                        //01b: 2 ms
                                                        //10b: 10 ms
                                                        //11b: 20 ms
#define _CHG_OPTION2_EN_PKPWR_IDPM      _BIT(13)    //Enable Peak Power Mode triggered by input current overshoot
                                                        //If REG0x31[13:12] are 00b, peak power mode is disabled. Upon adapter removal, the bits are reset to 00b.
                                                        //0b: Disable peak power mode triggered by input current overshootn <default at POR>
                                                        //1b: Enable peak power mode triggered by input current overshoot.
#define _CHG_OPTION2_EN_PKPWR_VSYS      _BIT(12)    //Enable Peak Power Mode triggered by system voltage under-shoot
                                                        //If REG0x31[13:12] are 00b, peak power mode is disabled. Upon adapter removal, the bits are reset to 00b.
                                                        //0b: Disable peak power mode triggered by system voltage under-shoot <default at POR>
                                                        //1b: Enable peak power mode triggered by system voltage under-shoot.
#define _CHG_OPTION2_PKPWR_OVLD_STAT    _BIT(11)    //Indicator that the device is in overloading cycle. Write 0 to get out of overloading cycle.
                                                        //0b: Not in peak power mode. <default at POR>
                                                        //1b: In peak power mode.
#define _CHG_OPTION2_PKPWR_RELAX_STAT   _BIT(10)    //Indicator that the device is in relaxation cycle. Write 0 to get out of relaxation cycle.
                                                        //0b: Not in relaxation cycle. <default at POR>
                                                        //1b: In relaxation mode.
#define _CHG_OPTION2_PKPWR_TMAX_1       _BIT(9)     //Peak power mode overload and relax cycle time.
#define _CHG_OPTION2_PKPWR_TMAX_0       _BIT(8)        //When REG0x31[15:14] is programmed longer than REG0x31[9:8], there is no relax time.
                                                        //00b: 5 ms
                                                        //01b: 10 ms
                                                        //10b: 20 ms <default at POR>
                                                        //11b: 40 ms
#define _CHG_OPTION2_EN_EXTILIM         _BIT(7)     //Enable ILIM_HIZ pin to set input current limit
                                                        //0b: Input current limit is set by REG0x3F.
                                                        //1b: Input current limit is set by the lower value of ILIM_HIZ pin and REG0x3F. <default at POR>
#define _CHG_OPTION2_EN_ICHG_IDCHG      _BIT(6)     //0b: IBAT pin as discharge current. <default at POR>, 1b: IBAT pin as charge current.
#define _CHG_OPTION2_Q2_OCP             _BIT(5)     //Q2 OCP threshold by sensing Q2 VDS
                                                        //0b: 210 mV
                                                        //1b: 150 mV <default at POR>
#define _CHG_OPTION2_ACX_OCP            _BIT(4)     //Input current OCP threshold by sensing ACP-ACN.
                                                        //0b: 280 mV
                                                        //1b: 150 mV <default at POR>
#define _CHG_OPTION2_EN_ACOC            _BIT(3)     //ACOC Enable
                                                        //Input overcurrent (ACOC) protection by sensing the voltage across
                                                        //ACP and ACN. Upon ACOC (after 100-µs blank-out time), converter is disabled.
                                                        //0b: Disable ACOC <default at POR>
                                                        //1b: ACOC threshold 125% or 200% ICRIT
#define _CHG_OPTION2_ACOC_VTH           _BIT(2)     //ACOC Limit
                                                        //Set MOSFET OCP threshold as percentage of IDPM with current sensed from RAC.
                                                        //0b: 125% of ICRIT
                                                        //1b: 200% of ICRIT <default at POR>
#define _CHG_OPTION2_EN_BATOC           _BIT(1)     //BATOC Enable
                                                        //Battery discharge overcurrent (BATOC) protection by sensing the
                                                        //voltage across SRN and SRP. Upon BATOC, converter is disabled.
                                                        //0b: Disable BATOC
                                                        //1b: BATOC threshold 125% or 200% PROCHOT IDCHG <default at POR>
#define _CHG_OPTION2_BATOC_VTH          _BIT(0)     //Set battery discharge overcurrent threshold as percentage of PROCHOT battery discharge current limit.
                                                        //0b: 125% of PROCHOT IDCHG
                                                        //1b: 200% of PROCHOT IDCHG <default at POR>
/* _CHG_CHARGE_OPTION_3    (0x32) */
#define _CHG_OPTION3_EN_HIZ             _BIT(15)    //Device Hi-Z Mode Enable
                                                        //When the charger is in Hi-Z mode, the device draws minimal quiescent current.
                                                        //With VBUS above UVLO. REGN LDO stays on, and system powers from battery.
                                                        //0b: Device not in Hi-Z mode <default at POR>
                                                        //1b: Device in Hi-Z mode
#define _CHG_OPTION3_RESET_REG          _BIT(14)    //Reset Registers
                                                        //All the registers go back to the default setting except the VINDPM register.
                                                        //0b: Idle <default at POR>
                                                        //1b: Reset all the registers to default values. After reset, this bit goes back to 0.
#define _CHG_OPTION3_RESET_VINDPM       _BIT(13)    //Reset VINDPM Threshold
                                                        //0b: Idle
                                                        //1b: Converter is disabled to measure VINDPM threshold. After VINDPM measurement is done, this bit goes back to 0 and converter starts.
#define _CHG_OPTION3_EN_OTG             _BIT(12)    //OTG Mode Enable
                                                        //Enable device in OTG mode when EN_OTG pin is HIGH.
                                                        //0b: Disable OTG <default at POR>
                                                        //1b: Enable OTG mode to supply VBUS from battery
#define _CHG_OPTION3_EN_ICO_MODE        _BIT(11)    //Enable ICO Algorithm
                                                        //0b: Disable ICO algorithm. <default at POR>
                                                        //1b: Enable ICO algorithm.
#define _CHG_OPTION3_BATFETOFF_HIZ      _BIT(1)     //Control BATFET during HIZ mode.
                                                        //0b: BATFET on during Hi-Z <default at POR>
                                                        //1b: BATFET off during Hi-Z
#define _CHG_OPTION3_PSYS_OTG_IDCHG     _BIT(0)     //PSYS function during OTG mode.
                                                        //0b: PSYS as battery discharge power minus OTG output power <default at POR>
                                                        //1b: PSYS as battery discharge power only
/* _CHG_PROCHOT_OPTION_0   (0x33) */
#define _CHG_PROCHOT_OPTION0_ILIM2_VTH_4    _BIT(15)    //ILIM2 Threshold
#define _CHG_PROCHOT_OPTION0_ILIM2_VTH_3    _BIT(14)        //5 bits, percentage of IDPM in 0x3FH. Measure current between ACP and ACN. Trigger when the current is above this threshold:
#define _CHG_PROCHOT_OPTION0_ILIM2_VTH_2    _BIT(13)        //00001b - 11001b: 110% - 230%, step 5%
#define _CHG_PROCHOT_OPTION0_ILIM2_VTH_1    _BIT(12)        //11010b - 11110b: 250% - 450%, step 50%
#define _CHG_PROCHOT_OPTION0_ILIM2_VTH_0    _BIT(11)        //11111b: Out of Range (Ignored)
#define _CHG_PROCHOT_OPTION0_ICRIT_DEG_1    _BIT(10)    //ICRIT Deglitch time
#define _CHG_PROCHOT_OPTION0_ICRIT_DEG_0    _BIT(9)         //ICRIT threshold is set to be 110% of ILIM2.
                                                            //Typical ICRIT deglitch time to trigger PROCHOT.
                                                            //00b: 15 µs
                                                            //01b: 100 µs <default at POR>
                                                            //10b: 400 µs (max 500 us)
                                                            //11b: 800 µs (max 1 ms)
#define _CHG_PROCHOT_OPTION0_VSYS_VTH_1     _BIT(7)     //VSYS Threshold
#define _CHG_PROCHOT_OPTION0_VSYS_VTH_0     _BIT(6)         //Measure on VSYS with fixed 20-µs deglitch time. Trigger when SYS pin voltage is below the threshold.
                                                            //00b: 5.75 V (2-4 s) or 2.85 V (1 s)
                                                            //01b: 6 V (2-4 s) or 3.1 V (1 s) <default at POR>
                                                            //10b: 6.25 V (2-4 s) or 3.35 V (1 s)
                                                            //11b: 6.5 V (2-4 s) or 3.6 V (1 s)
#define _CHG_PROCHOT_OPTION0_EN_PROCHOT_EXT _BIT(5)     //PROCHOT Pulse Extension Enable
                                                            //When pulse extension is enabled, keep the PROCHOT pin voltage LOW until host writes 0x33[2] = 0.
                                                            //0b: Disable pulse extension <default at POR>
                                                            //1b: Enable pulse extension
#define _CHG_PROCHOT_OPTION0_PROCHOT_WIDTH_1 _BIT(4)    //PROCHOT Pulse Width
#define _CHG_PROCHOT_OPTION0_PROCHOT_WIDTH_0 _BIT(3)        //Minimum PROCHOT pulse width when REG0x33[5] = 0
                                                            //00b: 100 µs
                                                            //01b: 1 ms
                                                            //10b: 10 ms <default at POR>
                                                            //11b: 5 ms
#define _CHG_PROCHOT_OPTION0_PROCHIT_CLEAR  _BIT(2)     //PROCHOT Pulse Clear
                                                            //Clear PROCHOT pulse when 0x33[5] = 1.
                                                            //0b: Clear PROCHOT pulse and drive PROCHOT pin HIGH.
                                                            //1b: Idle <default at POR>
#define _CHG_PROCHOT_OPTION0_INOM_DEG       _BIT(1)     //INOM Deglitch Time
                                                            //INOM is always 10% above IDPM in 0x3FH. Measure current between ACP and ACN.
                                                            //Trigger when the current is above this threshold.
                                                            //0b: 1 ms (must be max) <default at POR>
                                                            //1b: 50 ms (max 60 ms)
/* _CHG_PROCHOT_OPTION_1   (0x34) */
#define _CHG_PROCHOT_OPTION1_IDCHG_VTH_5    _BIT(15)    //IDCHG Threshold
#define _CHG_PROCHOT_OPTION1_IDCHG_VTH_4    _BIT(14)        //6 bit, range, range 0 A to 32256 mA, step 512 mA. There is a 128 mA offset
#define _CHG_PROCHOT_OPTION1_IDCHG_VTH_3    _BIT(13)        //Measure current between SRN and SRP.
#define _CHG_PROCHOT_OPTION1_IDCHG_VTH_2    _BIT(12)        //Trigger when the discharge current is above the threshold.
#define _CHG_PROCHOT_OPTION1_IDCHG_VTH_1    _BIT(11)        //If the value is programmed to 000000b PROCHOT is always triggered
#define _CHG_PROCHOT_OPTION1_IDCHG_VTH_0    _BIT(10)        //Default: 16384 mA or 100000b
#define _CHG_PROCHOT_OPTION1_IDCHG_DEG_1    _BIT(9)     //IDCHG Deglitch Time
#define _CHG_PROCHOT_OPTION1_IDCHG_DEG_0    _BIT(8)         //00b: 1.6 ms
                                                            //01b: 100 µs <default at POR>
                                                            //10b: 6 ms
                                                            //11b: 12 ms
#define _CHG_PROCHOT_OPTION1_PROCHOT_PROFILE_COMP   _BIT(6)//PROCHOT Profile
                                                            //When all the REG0x34[6:0] bits are 0, PROCHOT function is disabled. Bit6 Independent comparator
                                                            //0b: disable <default at POR>
                                                            //1b: enable
#define _CHG_PROCHOT_OPTION1_PROCHOT_PROFILE_ICRIT  _BIT(5)//0b: disable, 1b: enable <default at POR>
#define _CHG_PROCHOT_OPTION1_PROCHOT_PROFILE_INOM   _BIT(4)//0b: disable <default at POR>, 1b: enable
#define _CHG_PROCHOT_OPTION1_PROCHOT_PROFILE_IDCHG  _BIT(3)//0b: disable <default at POR>, 1b: enable
#define _CHG_PROCHOT_OPTION1_PROCHOT_PROFILE_VSYS   _BIT(2)//b 0b: disable <default at POR>, 1b: enable
#define _CHG_PROCHOT_OPTION1_PROCHOT_PROFILE_BATPRES _BIT(1)//0b: disable <default at POR>
                                                                //1b: enable (one-shot falling edge triggered)
                                                                //If BATPRES is enabled in PROCHOT after the battery is removed, it will immediately send out one-shot PROCHOT pulse.
#define _CHG_PROCHOT_OPTION1_PROCHOT_PROFILE_ACOK   _BIT(0)//0b: disable <default at POR>
                                                                //1b: enable
                                                                //ChargeOption0[15] = 0 to assert PROCHOT pulse after adapter removal.
                                                                //If PROCHOT_PROFILE_ACOK is enabled in PROCHOT after the adapter is removed, it will be pulled low.
/* _CHG_ADC_OPTION         (0x35) */
#define _CHG_ADCA_OPTION_ADC_CNV            _BIT(15)    //Typical ADC conversion time is 10 ms.
                                                            //0b: One-shot update. Do one set of conversion updates to registers
                                                            //REG0x23(), REG0x24(), REG0x25(), and REG0x26() after ADC_START = 1.
                                                            //1b: Continuous update. Do a set of conversion updates to registers
                                                            //REG0x23(), REG0x24(), REG0x25(), and REG0x26() every 1 sec.
#define _CHG_ADCA_OPTION_ADC_START          _BIT(14)    //0b: No ADC conversion
                                                            //1b: Start ADC conversion. After the one-shot update is complete, this bit automatically resets to zero
#define _CHG_ADCA_OPTION_ADC_FULLSCALE      _BIT(13)    //ADC input voltage range. When input voltage is below 5 V, or battery is 1S, full scale 2.04 V is recommended.
                                                            //0b: 2.04 V
                                                            //1b: 3.06 V <default at POR>
#define _CHG_ADCA_OPTION_EN_ADC_CMPIN       _BIT(7)     //0b: Disable <default at POR>, 1b: Enable
#define _CHG_ADCA_OPTION_EN_ADC_VBUS        _BIT(6)     //0b: Disable <default at POR>, 1b: Enable
#define _CHG_ADCA_OPTION_EN_ADC_PSYS        _BIT(5)     //0b: Disable <default at POR>, 1b: Enable
#define _CHG_ADCA_OPTION_EN_ADC_IIN         _BIT(4)     //0b: Disable <default at POR>, 1b: Enable
#define _CHG_ADCA_OPTION_EN_ADC_IDCHG       _BIT(3)     //0b: Disable <default at POR>, 1b: Enable
#define _CHG_ADCA_OPTION_EN_ADC_ICHG        _BIT(2)     //0b: Disable <default at POR>, 1b: Enable
#define _CHG_ADCA_OPTION_EN_ADC_VSYS        _BIT(1)     //0b: Disable <default at POR>, 1b: Enable
#define _CHG_ADCA_OPTION_EN_ADC_VBAT        _BIT(0)     //0b: Disable <default at POR>, 1b: Enable
/* _CHG_CHARGER_STATUS     (0x20) */
#define _CHG_CHARGER_STATUS_AC_STAT         _BIT(1 << 15)   //Input source status, same as CHRG_OK pin
                                                            //0b: Input not present
                                                            //1b: Input is present
#define _CHG_CHARGER_STATUS_ICO_DONE        _BIT(1 << 14)   //After the ICO routine is successfully executed, the bit goes 1.
                                                            //0b: ICO is not complete
                                                            //1b: ICO is complete
#define _CHG_CHARGER_STATUS_IN_VINDPM       _BIT(12)    //0b: Charger is not in VINDPM during forward mode, or voltage regulation during OTG mode
                                                            //1b: Charger is in VINDPM during forward mode, or voltage regulation during OTG mode
#define _CHG_CHARGER_STATUS_IN_IINDPM       _BIT(11)    //0b: Charger is not in IINDPM, 1b: Charger is in IINDPM
#define _CHG_CHARGER_STATUS_IN_FCHRG        _BIT(10)    //0b: Charger is not in fast charge, 1b: Charger is in fast charger
#define _CHG_CHARGER_STATUS_IN_PCHRG        _BIT(9)     //0b: Charger is not in pre-charge, 1b: Charger is in pre-charge
#define _CHG_CHARGER_STATUS_IN_OTG          _BIT(8)     //0b: Charger is not in OTG, 1b: Charge is in OTG
#define _CHG_CHARGER_STATUS_FAULT_ACOV      _BIT(7)     //The faults are latched until a read from host.
                                                            //0b: No fault
                                                            //1b: ACOV
#define _CHG_CHARGER_STATUS_FAULT_BATOC     _BIT(6)     //The faults are latched until a read from host.
                                                            //0b: No fault
                                                            //1b: BATOC
#define _CHG_CHARGER_STATUS_FAULT_ACOC      _BIT(5)     //The faults are latched until a read from host.
                                                            //0b: No fault
                                                            //1b: ACOC
#define _CHG_CHARGER_STATUS_SYSOVP_STAT     _BIT(4)     //SYSOVP Status and Clear
                                                            //When the SYSOVP occurs, this bit is HIGH. During the SYSOVP, the converter is disabled.
                                                            //After the SYSOVP is removed, the user must write a 0 to this bit or
                                                            //unplug the adapter to clear the SYSOVP condition to enable the converter again.
                                                            //0b: Not in SYSOVP <default at POR>
                                                            //1b: In SYSOVP. When SYSOVP is removed, write 0 to clear the SYSOVP latch
#define _CHG_CHARGER_STATUS_FAULT_LATCHOFF  _BIT(2)     //The faults are latched until a read from host.
                                                            //0b: No fault
                                                            //1b: Latch off (REG0x30[3])
#define _CHG_CHARGER_STATUS_FAULT_OTG_OVP   _BIT(1)     //The faults are latched until a read from host.
                                                            //0b: No fault
                                                            //1b: OTG OVP
#define _CHG_CHARGER_STATUS_FAULT_OTG_OCP   _BIT(0)     //The faults are latched until a read from host.
                                                            //0b: No fault
                                                            //1b: OTG OCP
/* _CHG_PROCHOT_STATUS     (0x21) */
#define _CHG_PROCHOT_STATUS_STAT_COMP       _BIT(6)     //0b: Not triggered, 1b: Triggered
#define _CHG_PROCHOT_STATUS_STAT_ICRIT      _BIT(5)     //0b: Not triggered, 1b: Triggered
#define _CHG_PROCHOT_STATUS_STAT_INOM       _BIT(4)     //0b: Not triggered, 1b: Triggered
#define _CHG_PROCHOT_STATUS_STAT_IDCHG      _BIT(3)     //0b: Not triggered, 1b: Triggered
#define _CHG_PROCHOT_STATUS_STAT_VSYS       _BIT(2)     //0b: Not triggered, 1b: Triggered
#define _CHG_PROCHOT_STATUS_STAT_BAT_REMOV  _BIT(1)     //0b: Not triggered, 1b: Triggered
#define _CHG_PROCHOT_STATUS_STAT_ADA_REMOV  _BIT(0)     //0b: Not triggered, 1b: Triggered


//Registers
#define _CHG_CHARGE_OPTION_0    _BYTE(0x12)  //R/W Charge option 0
#define _CHG_CHARGE_CURRENT     _BYTE(0x14)  //R/W 7-bit charge current setting LSB 64mA, Range 8128 mA
#define _CHG_MAX_CHARGE_VOLTAGE _BYTE(0x15)  //R/W 11-bit charge voltage setting LSB 16mV, Default 12.592V
#define _CHG_CHARGE_OPTION_1    _BYTE(0x30)  //R/W Charge option 1
#define _CHG_CHARGE_OPTION_2    _BYTE(0x31)  //R/W Charge option 2
#define _CHG_CHARGE_OPTION_3    _BYTE(0x32)  //R/W Charge option 3
#define _CHG_PROCHOT_OPTION_0   _BYTE(0x33)  //R/W PROCHOT Option 0
#define _CHG_PROCHOT_OPTION_1   _BYTE(0x34)  //R/W PROCHOT Option 1
#define _CHG_ADC_OPTION         _BYTE(0x35)  //R/W ADC Option
#define _CHG_CHARGER_STATUS     _BYTE(0x20)  //R   Charge status
#define _CHG_PROCHOT_STATUS     _BYTE(0x21)  //R   Prochot status
#define _CHG_I_IN_DPM           _BYTE(0x22)  //R   7-bit input current limit in use LSB 50mA, Range 50mA - 6400mA
#define _CHG_ADC_VBUS_PSYS      _BYTE(0x23)  //R   8-bit digital output of input voltage VBUS: LSB 64mV Range 3.2V - 19.52V
                                        //    8-bit digital output of system power  PSYS: LSB 12mV Range 3.06V
#define _CHG_ADC_I_BAT          _BYTE(0x24)  //R   8-bit digital output of battery charge current    ICHG: LSB 64mA Range 8.128A
                                        //    8-bit digital output of battery discharge current IDCHG: LSB 256mA Range 32.512A
#define _CHG_ADC_I_IN_CMP_IN    _BYTE(0x25)  //R   8-bit digital output of input current POR: LSB 50mA Range 12.75A
                                        //    8-bit digital output of CMPIN voltage CMPIN: LSB 12mV Range 3.06V
#define _CHG_ADC_VSYS_VBAT      _BYTE(0x26)  //R   8-bit digital output of system voltage    VSYS: LSB 64mV Range 2.88V - 19.2V
                                        //    8-bit digital output of battery voltage   VBAT: LSB 64mV Range 4480mV - 20800mV
#define _CHG_OTG_VOLTAGE        _BYTE(0x3B)  //R/W 8-bit OTG voltage setting LSB 64mV Range 4480mV - 20800mV
#define _CHG_OTG_CURRENT        _BYTE(0x3C)  //R/W 7-bit OTG output current setting LSB 50mV Range 0V - 6350mA
#define _CHG_INPUT_VOLTAGE      _BYTE(0x3D)  //R/W 8-bit input voltage setting LSB 64mV Range 3200mV - 19520mV
#define _CHG_MIN_SYSTEM_VOLTAGE _BYTE(0x3E)  //R/W 6-bit minimum system volatage setting LSB 256mV Range 1024mV - 16182mV Default 9.216V
#define _CHG_I_IN_HOST          _BYTE(0x3F)  //R/W 6-bit input current limit set by host LSB 50mA Range 50mA - 6400mA
#define _CHG_MANUFACTURE_ID     _BYTE(0xFE)  //R   Manufacture ID - 0x0040
#define _CHG_DEVICE_ID          _BYTE(0xFF)  //R   Device ID

bool CHG_Initialize(void);
void CHG_Update(state_t state);
void CHG_SetChargeCurrent(uint16_t current);
void CHG_EnableCharger(bool b);

//I2C slave interface
inline uint16_t CHG_GetChargeVoltage(void);
inline uint16_t CHG_GetChargeCurrent(void);

#endif	/* _CHG_H */

