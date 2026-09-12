#include<stdio.h>
#include<stdint.h>
//CLEAR_BIT ------ Register &= ~(1 << BitNo)


uint32_t Clear_nthBitofNumber(uint32_t Number, uint32_t BitNo){
    Number &= ~(1 << BitNo);
    return Number;
}