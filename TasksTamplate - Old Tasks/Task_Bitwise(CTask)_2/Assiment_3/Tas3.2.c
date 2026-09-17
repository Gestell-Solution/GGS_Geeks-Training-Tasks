#include <stdint.h>
#include<stdio.h>

void CountNumberofonesANDzeroes(uint8_t number){
   uint8_t i=0;
   uint8_t ones_Count=0;
   uint8_t zeroes_Count=0;
   for(i=0;i<8;i++){
    if((number>>i)&1){
        ones_Count++;
    }
    else{
        zeroes_Count++;
    }
   }
   printf("Total number of ones: %d\n", ones_Count);
   printf("Total number of zeroes: %d\n", zeroes_Count);
}




