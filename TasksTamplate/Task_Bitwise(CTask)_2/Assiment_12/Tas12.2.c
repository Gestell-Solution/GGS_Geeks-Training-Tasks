#include<stdio.h>
#include<stdint.h>
uint8_t Find_HighestSetBit(uint8_t Number){
    uint8_t HighestBit=0;
    for(int i=7;i>=0;i--){
        if((Number>>i)&1){
            HighestBit=i;
            break;
        }
    }
    return HighestBit;
}