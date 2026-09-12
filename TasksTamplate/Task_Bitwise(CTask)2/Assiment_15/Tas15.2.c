#include<stdio.h>
#include<stdint.h>


uint8_t Count_NumberofLeadingZeros(uint8_t Number){
uint8_t Count=0;
for(uint8_t i=7;i>=0;i--){
    if(((Number>>i)&1)==0){
        Count++;
    }
    else{
          break;
    }
}
return Count;
}