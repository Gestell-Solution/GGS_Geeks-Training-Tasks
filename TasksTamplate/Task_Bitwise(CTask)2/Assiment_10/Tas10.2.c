#include<stdio.h>
#include<stdint.h>
//SET_BIT ------ Register |= (1 << BitNo)


uint32_t Set_nthBitofNumber(uint32_t Number, uint32_t BitNo){
    Number |= (1 << BitNo);
    return Number;
}