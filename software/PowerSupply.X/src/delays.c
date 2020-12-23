

#include <mcc.h>


void __delay_us(int x){
    while(x-- > 0){
        __asm__("NOP");
        __asm__("NOP");
        __asm__("NOP");
        __asm__("NOP");
        __asm__("NOP");
        __asm__("NOP");
        __asm__("NOP");
    }
}

void __delay_ms(int x){
    while(x-- > 0){
        __delay_us(1000);
    }
}