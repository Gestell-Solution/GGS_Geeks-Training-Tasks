#include<stdio.h>
#include<stdint.h>


void Check_MSBofNumber(uint8_t Number){
if ((Number >> 7)&1){
    printf("The most significant bit of %d is 1 \n", Number);
}
else{
    printf("The most significant bit of %d is 0 \n", Number);
}
}




