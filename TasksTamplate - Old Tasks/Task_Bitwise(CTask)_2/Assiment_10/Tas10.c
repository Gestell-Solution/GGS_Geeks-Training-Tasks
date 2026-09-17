#include<stdio.h>
#include<stdint.h>
#include "Tas10.h"

int main(){
uint32_t Number=0;
uint32_t BitNo=0;
uint32_t Result=0;
printf("Enter your Number: ");
scanf("%u", &Number);
printf("Enter nth bit to set (0-31): ");
scanf("%u", &BitNo);
Result=Set_nthBitofNumber(Number, BitNo);
printf("Bit Set Successfully\n");
printf("The number before setting the %u bit is: %u\n", BitNo, Number);
printf("The number after setting the %u bit is: %u\n", BitNo, Result);

    return 0;
}