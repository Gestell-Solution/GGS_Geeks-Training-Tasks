#include<stdio.h>
#include<stdint.h>
#include "Tas9.h"

int main(){
uint32_t Number=0;
uint32_t BitNo=0;
uint32_t BitValue=0;
printf("Enter your Number: ");
scanf("%u", &Number);
printf("Enter nth bit to check (0-31): ");
scanf("%u", &BitNo);
BitValue=Check_nthBitofNumber(Number, BitNo);
printf("The %u bit is set to %u\n", BitNo, BitValue);
    return 0;
}