/* 
 * File:    epmp.h
 * Author:  Manuel
 * Date:    07/10/2018
 * 
 * Comments: Enhanced Parallel Master Port driver
 */

#include "epmp.h"

#define _CS1_BASE_ADDRESS               (0x200000L)//(0x8000)//(0x200000L)
#define _EXTERNAL_RESOURCE_SIZE         (4)
#define _END_OF_RESERVED_ADDRESS_SPACE  (_CS1_BASE_ADDRESS + _EXTERNAL_RESOURCE_SIZE)

__eds__ uint8_t epmp_data[_EXTERNAL_RESOURCE_SIZE] __attribute__((space(eds), address(_CS1_BASE_ADDRESS), noload)); 

//Initializes the Enhanced Parallel Master Port
void EPMP_Initialize(void){
    //PMCON1: EPMP CONTROL REGISTER 1
    PMCON1bits.PMPEN    = 1;    //Parallel Master Port Enable bit
    PMCON1bits.PSIDL    = 1;    //Parallel Master Port Stop in Idle Mode
    PMCON1bits.ADRMUX   = 0;    //Address/Data Multiplexing Selection bits, 0 = Address and data appear on separate pins
    PMCON1bits.MODE     = 3;    //Parallel Port Mode Select bits, 11 = Master mode
    PMCON1bits.CSF      = 0;    //Chip Select Function bits, 0 = PMCS2 is used for Chip Select 2, PMCS1 is used for Chip Select 1
    PMCON1bits.ALP      = 0;    //Address Latch Polarity bit, 0 = Active-low
    PMCON1bits.ALMODE   = 0;    //Address Latch Strobe Mode bit, 0 = Disables "smart" address strobes
    PMCON1bits.BUSKEEP  = 0;    //Bus Keeper bit, 1 = Data bus keeps its last value when not actively being driven
    PMCON1bits.IRQM     = 0;    //Interrupt Request Mode bits, 0 = No interrupt is generated
    
    //PMCON2: EPMP CONTROL REGISTER 2
    EPMP_IsErrorSetAndClear();              //Clear error flag
    EPMP_IsTimeoutSetAndClear();            //Clear timeout flag
    EPMP_SetEndOfReservedAddressSpace(_END_OF_RESERVED_ADDRESS_SPACE);    //Set end of reserved address space
    
    //PMCON3: EPMP CONTROL REGISTER 3
    PMCON3bits.PTWREN   = 1;    //Write/Enable Strobe Port Enable bit, 1 = PMWR/PMENB port is enabled
    PMCON3bits.PTRDEN   = 1;    //Read/Write Strobe Port Enable bit. 1 = PMRD/PMWR port is enabled
    PMCON3bits.PTBE1EN  = 0;    //High Nibble/Byte Enable Port Enable bit, 1 = PMBE1 port is disabled
    PMCON3bits.PTBE0EN  = 0;    //Low Nibble/Byte Enable Port Enable bit, 0 = PMBE1 port is disabled
    PMCON3bits.AWAITM   = 0;    //Address Latch Strobe Wait States bits, 0 = Wait of 1/2 Tcy
    PMCON3bits.AWAITE   = 0;    //Address Hold After Address Latch Strobe Wait States bits, 0 = Wait of 1/4 Tcy
    
    //PMCON4: EPMP CONTROL REGISTER 4
    PMCON4bits.PTEN15   = 0;    //PMA15 Port Enable bit, 0 = PMA15 function as port I/O
    PMCON4bits.PTEN14   = 0;    //PMA14 Port Enable bit, 1 = PMA14 function as port I/O
    PMCON4bits.PTEN13   = 0;    //PMA13 Port Enable bit, 0 = PMA13 function as port I/O
    PMCON4bits.PTEN12   = 0;    //PMA12 Port Enable bit, 0 = PMA12 function as port I/O
    PMCON4bits.PTEN11   = 0;    //PMA11 Port Enable bit, 0 = PMA11 function as port I/O
    PMCON4bits.PTEN10   = 0;    //PMA10 Port Enable bit, 0 = PMA10 function as port I/O
    PMCON4bits.PTEN9    = 0;    //PMA9  Port Enable bit, 0 = PMA9  function as port I/O
    PMCON4bits.PTEN8    = 0;    //PMA8  Port Enable bit, 0 = PMA8  function as port I/O
    PMCON4bits.PTEN7    = 0;    //PMA7  Port Enable bit, 0 = PMA7  function as port I/O
    PMCON4bits.PTEN6    = 0;    //PMA6  Port Enable bit, 0 = PMA6  function as port I/O
    PMCON4bits.PTEN5    = 0;    //PMA5  Port Enable bit, 0 = PMA5  function as port I/O
    PMCON4bits.PTEN4    = 0;    //PMA4  Port Enable bit, 0 = PMA4  function as port I/O
    PMCON4bits.PTEN3    = 0;    //PMA3  Port Enable bit, 0 = PMA3  function as port I/O
    PMCON4bits.PTEN2    = 0;    //PMA2  Port Enable bit, 0 = PMA2  function as port I/O
    PMCON4bits.PTEN1    = 0;    //PMA1  Port Enable bit, 0 = PMA1  function as port I/O
    PMCON4bits.PTEN0    = 1;    //PMA0  Port Enable bit, 1 = PMA0  function as address lines or address latch strobes

    //PMCS1CF: EPMP CHIP SELECT 1 CONFIGURATION REGISTER
    PMCS1CFbits.CSDIS   = 0;    //Chip Select 1 Disable bit, 0 = Enables the Chip Select 1 functionality
    PMCS1CFbits.CSP     = 0;    //Chip Select 1 Polarity bit, 0 = Active-low
    PMCS1CFbits.CSPTEN  = 1;    //PMCS1 Port Enable bit, 1 = PMCS1 port is enabled
    PMCS1CFbits.BEP     = 0;    //Chip Select 1 Nibble/Byte Enable Polarity bit, 0 = Nibble/byte enable is active-low
    PMCS1CFbits.WRSP    = 1;    //Chip Select 1 Write Strobe Polarity bit, 1 = Enable strobe is active-high (PMENB)
    PMCS1CFbits.RDSP    = 1;    //Chip Select 1 Read Strobe Polarity bit, 1 = Read/write strobe is active-high
    PMCS1CFbits.SM      = 1;    //Chip Select 1 Strobe Mode, 1 = Read/write and enable strobe (PMRD/PMWR and PMENB)
    PMCS1CFbits.ACKP    = 1;    //Chip Select 1 Acknowledge Polarity bit, 1 = ACK is active-high (PMACK1)
    PMCS1CFbits.PTSZ    = 0;    //Chip Select 1 Port Size bits, 0 = 8-bit port size (PMD<7:0>)
    
    //PMCS1BS: EPMP CHIP SELECT 1 BASE ADDRESS REGISTER
    EPMP_SetBaseAddressChipSelect1(_CS1_BASE_ADDRESS);

    //PMCS1MD: EPMP CHIP SELECT 1 MODE REGISTER
    PMCS1MDbits.ACKM    = 0;    //Chip Select 1 Acknowledge Mode bits, 0 = PMACK1 is not used
    PMCS1MDbits.AMWAIT  = 0;    //Chip Select 1 Alternate Master Wait States bits, 0 = Wait of 3 alternate master cycles
    PMCS1MDbits.DWAITB  = 0;    //Chip Select 1 Data Setup Before Read/Write Strobe Wait States bits, 0 = Wait of 1/4 Tcy
    PMCS1MDbits.DWAITM  = 2;    //Chip Select 1 Data Read/Write Strobe Wait States bits
    PMCS1MDbits.DWAITE  = 1;    //Chip Select 1 Data Hold After Read/Write Strobe Wait States bits
    
    //PMCS2CF: EPMP CHIP SELECT 2 CONFIGURATION REGISTER
    PMCS2CFbits.CSDIS   = 1;    //Chip Select 2 Disable bit, 1 = Disables the Chip Select 2 functionality
    PMCS2CFbits.CSPTEN  = 0;    //PMCS2 Port Enable bit, 0 = PMCS2 port is disabled
    
    //PADCON: PAD CONFIGURATION CONTROL REGISTER (this bit is used by the interrupt on pin change)
    PADCONbits.PMPTTL   = 0;    //EPMP Module TTL Input Buffer Selection bit, 0 = EPMP module inputs use Schmitt Trigger input buffers
}

//Returns true if the port is busy
bool EPMP_IsBusy(void){
    return PMCON2bits.BUSY;
}

//Returns true if an error has occurred and clears the flag bit
bool EPMP_IsErrorSetAndClear(void){
    bool error = PMCON2bits.ERROR;
    PMCON2bits.ERROR = 0;
    return error;
}

//Returns true if a timeout condition has occurred and clears the flag bit
bool EPMP_IsTimeoutSetAndClear(void){
    bool timeout = PMCON2bits.TIMEOUT;
    PMCON2bits.TIMEOUT = 0;
    return timeout;
}

//Sets the end of the reserved address used by the module,
//The address must be greater than 0xFFFFFF
void EPMP_SetEndOfReservedAddressSpace(uint32_t endAddress){
    PMCON2bits.RADDR = endAddress - 0xFFFFFF;
}

//Sets the base address for the Chip select 1
//Default value on POR is 0x0800
//Valid bits as <23:15> and <11>
void EPMP_SetBaseAddressChipSelect1(uint32_t baseAddress){
    PMCS1BS = baseAddress >> 8;
}

//Writes a byte using the Enhanced Parallel Master Port at the specified address
void EPMP_WriteByte(uint8_t data, uint32_t address){
    epmp_data[address << 1] = data;
}

//Reads a byte from the Enhanced Parallel Master Port at the specified address
uint8_t EPMP_ReadByte(uint32_t address){ 
    while(EPMP_IsBusy());   //Wait until the port is busy
    return epmp_data[address];
}