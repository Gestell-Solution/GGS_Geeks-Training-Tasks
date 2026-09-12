#include<stdio.h>
#include<stdint.h>
#include "Tas15.h"

int main(){
   uint8_t Number=0;
    uint8_t Result=0;
    printf("Enter your Number: ");
    scanf("%hhu", &Number);
    Result=Count_NumberofLeadingZeros(Number);
    printf("Total number of leading zeros in %hhu is: %hhu\n", Number, Result);

    return 0;
}