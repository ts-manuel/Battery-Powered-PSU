/*
 * File:    i2cMaster.c
 * Author:  Manuel
 * Date:    26/06/2020
 * Device:  PIC16LF18346
 * Rev:     1.2 2020
 *
 * Bit-Banged I2C bus
 * 
 * MSSP2 does not work on PIC16LF18346 see errata
 * http://ww1.microchip.com/downloads/en/DeviceDoc/80000709D.pdf
 * 
 */

#include "i2cMaster.h"

#define _SCL_SET(x)     {I2C_SCL_LAT = (x);}
#define _SDA_SET(x)     {I2C_SDA_LAT = (x);}
#define _SDA_VALUE()    I2C_SDA_PORT

#define _I2C_START()    {_SDA_SET(0);\
                         asm("nop");\
                         asm("nop");\
                         asm("nop");\
                         asm("nop");\
                         _SCL_SET(0);}

#define _I2C_STOP()     {_SDA_SET(0);\
                         asm("nop");\
                         asm("nop");\
                         asm("nop");\
                         asm("nop");\
                         _SCL_SET(1);\
                         asm("nop");\
                         asm("nop");\
                         asm("nop");\
                         asm("nop");\
                         _SDA_SET(1);}

#define _I2C_ACK(x)     {_SDA_SET(x);\
                         asm("nop");\
                         asm("nop");\
                         asm("nop");\
                         asm("nop");\
                         _SCL_SET(1);\
                         asm("nop");\
                         asm("nop");\
                         asm("nop");\
                         asm("nop");\
                         _SCL_SET(0);}

/*
 * I2C Write function
 * writes nCount bytes of data to the slaveDeviceAddress
 */
i2c_result_t I2C_Write(uint8_t slaveDeviceAddress, uint8_t* pData, uint8_t nCount){
    uint8_t ack;
    uint8_t b;
    i2c_result_t result = e_I2C_OK;
    
    //Disable interrupts
    uint8_t _INTCON = INTCON;
    INTCONbits.GIE = 0;
    
    //Start condition
    _I2C_START();
    
    //Write Address
    slaveDeviceAddress = slaveDeviceAddress << 1;   //Bit 0 = 0 -> write transaction
    b = slaveDeviceAddress & 0x80 ? 1 : 0;
    _SDA_SET(b);
    for(uint8_t i = 0; i < 8; i++){
        _SCL_SET(1);
        slaveDeviceAddress <<= 1;
        b = slaveDeviceAddress & 0x80 ? 1 : 0;
        _SCL_SET(0);
        _SDA_SET(b);
    }
    
    //Read ACK
    _SDA_SET(1);
    _SCL_SET(1);
    ack = _SDA_VALUE();
    _SCL_SET(0);
    if(ack){
        result = e_I2C_ADDR_NACK;
        goto _stop;
    }
    
    //Write data
    for(uint8_t i = 0; i < nCount; i++){
        uint8_t data = pData[i];
        
        //Write byte
        b = data & 0x80 ? 1 : 0;
        _SDA_SET(b);
        for(uint8_t j = 0; j < 8; j++){
            _SCL_SET(1);
            data <<= 1;
            b = data & 0x80 ? 1 : 0;
            _SCL_SET(0);
            _SDA_SET(b);
        }
        
        //Read ACK
        _SDA_SET(1);
        _SCL_SET(1);
        ack = _SDA_VALUE();
        _SCL_SET(0);
        if(ack){
            result = e_I2C_DATA_NACK;
            goto _stop;
        }
    }
    
_stop:
    //Stop
    _I2C_STOP();
    
    //Restore interrupts
    INTCON = _INTCON;
    
    return result;
}

/*
 * I2C Read function
 * reads data from the slaveDeviceAddress
 * reads until the slave returns a NAK or the number of bytes read is equal to bufferLen
 * returns in nCount the actual number of bytes read
 */
i2c_result_t I2C_Read(uint8_t slaveDeviceAddress, uint8_t* pData, uint8_t nCount){
    uint8_t ack;
    uint8_t b;
    i2c_result_t result = e_I2C_OK;
    
    //Disable interrupts
    uint8_t _INTCON = INTCON;
    INTCONbits.GIE = 0;
    
    //Start condition
    _I2C_START();
    
    //Write Address
    slaveDeviceAddress = (slaveDeviceAddress << 1) | 0x01;   //Bit 0 = 1 -> read transaction
    b = slaveDeviceAddress & 0x80 ? 1 : 0;
    _SDA_SET(b);
    for(uint8_t i = 0; i < 8; i++){
        _SCL_SET(1);
        slaveDeviceAddress <<= 1;
        b = slaveDeviceAddress & 0x80 ? 1 : 0;
        _SCL_SET(0);
        _SDA_SET(b);
    }
    
    //Read ACK
    _SDA_SET(1);
    _SCL_SET(1);
    ack = _SDA_VALUE();
    _SCL_SET(0);
    if(ack){
        result = e_I2C_ADDR_NACK;
        goto _stop;
    }
    
    //Read data
    for(uint8_t i = 0; i < nCount; i++){
        uint8_t data = 0;
        
        //Read byte
        _SDA_SET(1);
        for(uint8_t j = 0; j < 8; j++){
            _SCL_SET(1);
            asm("nop");
            b = _SDA_VALUE();
            data = data << 1 | b;
            _SCL_SET(0);
        }
        
        pData[i] = data;
        
        //Sen ACK
        uint8_t ack = (i == nCount - 1) ? 1 : 0;
        _I2C_ACK(ack);
    }
    
_stop:
    //Stop
    _I2C_STOP();
    
    //Restore interrupts
    INTCON = _INTCON;
    
    return result;
}