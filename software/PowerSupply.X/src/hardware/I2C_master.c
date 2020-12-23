/* 
 * File:    I2C_master.h
 * Author:  Manuel
 * Date:    24/07/2020
 * 
 * I2C bit-banged master port
 */

#include "I2C_master.h"
#include "mcc.h"
#include "delays.h"

#define _SCL_SET(x)     {if(x) SCL_SetHigh(); else SCL_SetLow();}
#define _SDA_SET(x)     {if(x) SDA_SetHigh(); else SDA_SetLow();}
#define _SCL_VALUE()    SCL_GetValue()
#define _SDA_VALUE()    SDA_GetValue()

#define _DELAY()        __delay_us(3)

#define _I2C_START()    {_SDA_SET(0);\
                         _DELAY();\
                         _SCL_SET(0);\
                         _DELAY();}

#define _I2C_STOP()     {_SDA_SET(0);\
                         _DELAY();\
                         _SCL_SET(1);\
                         _DELAY();\
                         _SDA_SET(1);\
                         _DELAY();\
                         _DELAY();}

#define _I2C_ACK(x)     {_SDA_SET(x);\
                         _DELAY();\
                         _SCL_SET(1);\
                         _DELAY();\
                         _SCL_SET(0);}


/*
 * I2C Initialization function
 */
void I2C_Initialize(void){
    _SDA_SET(1);
    _SCL_SET(1);
}

/*
 * I2C Write function
 * writes nCount bytes of data to the slaveDeviceAddress
 */
i2c_result_t I2C_Write(uint8_t DevAddr, uint8_t* buffer, int ByteCnt){
    uint8_t ack;
    uint8_t b;
    i2c_result_t result = e_I2C_OK;
    
    //Disable interrupts
    uint8_t _GIE_ = INTCON2bits.GIE;
    INTCON2bits.GIE = 0;
    
    //Start condition
    _I2C_START();
    
    //Write Address
    DevAddr = DevAddr << 1;   //Bit 0 = 0 -> write transaction
    b = DevAddr & 0x80 ? 1 : 0;
    _SDA_SET(b);
    for(uint8_t i = 0; i < 8; i++){
        _DELAY();
        _SCL_SET(1);
        DevAddr <<= 1;
        b = DevAddr & 0x80 ? 1 : 0;
        _DELAY();
        _SCL_SET(0);
        _SDA_SET(b);
    }
    
    //Read ACK
    _SDA_SET(1);
    _DELAY();
    _SCL_SET(1);
    _DELAY();
    ack = _SDA_VALUE();
    _SCL_SET(0);
    if(ack){
        result = e_I2C_ADDR_NACK;
        goto _stop;
    }
    
    //Write data
    for(uint8_t i = 0; i < ByteCnt; i++){
        uint8_t data = buffer[i];
        
        //Write byte
        b = data & 0x80 ? 1 : 0;
        _SDA_SET(b);
        for(uint8_t j = 0; j < 8; j++){
            _DELAY();
            _SCL_SET(1);
            data <<= 1;
            b = data & 0x80 ? 1 : 0;
            _DELAY();
            _SCL_SET(0);
            _SDA_SET(b);
        }
        
        //Read ACK
        _SDA_SET(1);
        _DELAY();
        _SCL_SET(1);
        _DELAY();
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
    INTCON2bits.GIE = _GIE_;
    
    return result;
}

/*
 * I2C Read function
 * reads data from the slaveDeviceAddress
 * reads until the slave returns a NAK or the number of bytes read is equal to bufferLen
 * returns in nCount the actual number of bytes read
 */
i2c_result_t I2C_Read(uint8_t DevAddr, uint8_t* buffer, int ByteCnt){
    uint8_t ack;
    uint8_t b;
    i2c_result_t result = e_I2C_OK;
    int counter = 0;
    
    //Disable interrupts
    uint8_t _GIE_ = INTCON2bits.GIE;
    INTCON2bits.GIE = 0;
    
    //Start condition
    _I2C_START();
    
    //Write Address
    DevAddr = (DevAddr << 1) | 0x01;   //Bit 0 = 1 -> read transaction
    b = DevAddr & 0x80 ? 1 : 0;
    _SDA_SET(b);
    for(uint8_t i = 0; i < 8; i++){
        _DELAY();
        _SCL_SET(1);
        DevAddr <<= 1;
        b = DevAddr & 0x80 ? 1 : 0;
        _DELAY();
        _SCL_SET(0);
        _SDA_SET(b);
    }
    
    //Read ACK
    _SDA_SET(1);
    _DELAY();
    _SCL_SET(1);
    _DELAY();
    ack = _SDA_VALUE();
    _SCL_SET(0);
    if(ack){
        result = e_I2C_ADDR_NACK;
        goto _stop;
    }
    
    //Read data
    for(uint8_t i = 0; i < ByteCnt; i++){
        uint8_t data = 0;
        
        //Read byte
        _SDA_SET(1);
        for(uint8_t j = 0; j < 8; j++){
            _DELAY();
            _SCL_SET(1);
            
            while(_SCL_VALUE() == 0 && counter < 10){
                _DELAY();
                counter++;
            }
            
            b = _SDA_VALUE();
            data = data << 1 | b;
            _DELAY();
            _SCL_SET(0);
        }
        
        buffer[i] = data;
        
        //Sen ACK
        uint8_t ack = (i == ByteCnt - 1) ? 1 : 0;
        _I2C_ACK(ack);
    }
    
_stop:
    //Stop
    _I2C_STOP();
    
    //Restore interrupts
    INTCON2bits.GIE = _GIE_;
    
    return result;
}

i2c_result_t  I2C_Write_8(uint8_t DevAddr, uint8_t SubAddr, int ByteCnt, uint8_t *buffer){
    uint8_t data[65];
    
    data[0] = SubAddr;
    for(int i = 0; i < ByteCnt; i++){
        data[i + 1] = buffer[i];
    }
    
    return I2C_Write(DevAddr, data, ByteCnt + 1);
}
i2c_result_t  I2C_Read_8(uint8_t DevAddr, uint8_t SubAddr, int ByteCnt, uint8_t* buffer){
    i2c_result_t result = 0;

    result |= I2C_Write(DevAddr, &SubAddr, 1);
    result |= I2C_Read(DevAddr, buffer, ByteCnt);
    
    return result;
}
i2c_result_t  I2C_Write_16(uint8_t DevAddr, uint16_t SubAddr, int ByteCnt, uint8_t *buffer){
    uint8_t data[66];
    
    data[0] = SubAddr >> 8;
    data[1] = SubAddr & 0xff;
    for(int i = 0; i < ByteCnt; i++){
        data[i + 2] = buffer[i];
    }
    
    return I2C_Write(DevAddr, data, ByteCnt + 2);
}
i2c_result_t  I2C_Read_16(uint8_t DevAddr, uint16_t SubAddr, int ByteCnt, uint8_t* buffer){
    uint8_t addr[2];
    i2c_result_t result = 0;
    
    addr[0] = SubAddr >> 8;
    addr[1] = SubAddr & 0xff;
    result |= I2C_Write(DevAddr, addr, 2);
    result |= I2C_Read(DevAddr, buffer, ByteCnt);
    
    return result;
}
