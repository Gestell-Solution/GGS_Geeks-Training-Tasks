#include<stdio.h>
#include<stdint.h>


uint8_t Find_LowestSetBit(uint8_t Number){
    uint8_t LowestBit=0;
    for(int i=0;i<8;i++){
        if((Number>>i)&1){
            LowestBit=i;
            break;
        }
    }
    return LowestBit;
}