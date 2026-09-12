#include <stdint.h>
#include<stdio.h>

uint8_t Flip_Number(uint8_t number){
    uint8_t FlipedNumber=0;
    FlipedNumber=~number;
    return FlipedNumber;
}