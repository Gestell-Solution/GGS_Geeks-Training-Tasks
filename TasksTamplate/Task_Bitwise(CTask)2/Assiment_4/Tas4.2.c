#include <stdint.h>
#include<stdio.h>

uint8_t Rotate_RightNumber(uint8_t number, uint8_t Rotate){
uint8_t Num=0;
Num=(number>>Rotate)|(number<< (8-Rotate));
return Num;
}

uint8_t Rotate_LeftNumber(uint8_t number, uint8_t Rotate){
uint8_t Num=0;
Num=(number<<Rotate)|(number>> (8-Rotate));
return Num;
}
