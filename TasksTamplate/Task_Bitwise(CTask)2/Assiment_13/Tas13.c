#include<stdio.h>
#include<stdint.h>
#include "Tas13.h"

int main(){
uint8_t Number=0;
printf("Enter your Number: ");
scanf("%hhu", &Number);
uint8_t LowestBit=Find_LowestSetBit(Number);
printf("The lowest set bit in %hhu is: %hhu\n", Number, LowestBit);

    return 0;
}