#include<stdio.h>
#include<stdint.h>


uint8_t Count_NumberofTrailingZeros(uint8_t Number){
    uint8_t Count=0;
    
    for(uint8_t i=0; i<8; i++)
    {
        if((Number & 1) == 0)
        {
            Count++;
        }
        else
        {
            break;
        }
        Number >>= 1;
    }
    return Count;
}

