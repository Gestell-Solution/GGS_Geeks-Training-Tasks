#include<stdio.h>
#include<stdint.h>


uint32_t Check_nthBitofNumber(uint32_t Number, uint32_t BitNo){
uint32_t BitValue=0;
BitValue=(Number>>BitNo)&1;
return BitValue;

}
