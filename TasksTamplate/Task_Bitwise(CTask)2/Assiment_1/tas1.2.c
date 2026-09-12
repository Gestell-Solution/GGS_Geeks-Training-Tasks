#include <stdint.h>
#include <stdio.h>

void Check_LSBOfNumber(uint8_t number){
if (number & 1) {
        printf("The least significant bit of %d is 1 \n", number);
    } else {
        printf("The least significant bit of %d is 0 \n", number);
    }



}