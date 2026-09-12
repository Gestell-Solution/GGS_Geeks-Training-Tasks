#include"header.h"
void set_the_bitNumber(uint8_t number,uint8_t bitNumber){
    uint8_t newNumber=0;
    printf("the bit have been set\n");
    printf("=====================================================\n");
    printf("the number before setting bit %hhd : %hhd\n",bitNumber,number);
    newNumber=setbit(number,bitNumber);
    printf("the number after setting bit %hhd : %hhd",bitNumber,newNumber);
}
