#include<stdio.h>
#include<stdint.h>
#include "Tas12.h"

int main(){
uint8_t Number=0;
printf("Enter your Number: ");
scanf("%hhu", &Number);
uint8_t HighestBit=Find_HighestSetBit(Number);
printf("The highest set bit in %hhu is: %hhu\n", Number, HighestBit);

    return 0;
}