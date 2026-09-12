#include<stdio.h>
#include<stdint.h>
#include "Tas11.h"

int main(){
uint32_t Number=0;
uint32_t BitNo=0;
uint32_t Result=0;
printf("Enter your Number: ");
scanf("%u", &Number);
printf("Enter nth bit to clear (0-31): ");
scanf("%u", &BitNo);
Result=Clear_nthBitofNumber(Number, BitNo);
printf("Bit Cleared Successfully\n");
printf("The number before clearing the %u bit is: %u\n", BitNo, Number);
printf("The number after clearing the %u bit is: %u\n", BitNo, Result);

    return 0;
}