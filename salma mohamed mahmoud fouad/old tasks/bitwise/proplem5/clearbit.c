#include"header.h"

void clear_the_bitNumber(uint8_t number,uint8_t bitNumber){
    uint8_t newNumber=0;
    printf("the bit have been cleared\n");
    printf("=====================================================\n");
    printf("the number before clearing bit %hhd : %hhd\n",bitNumber,number);
    newNumber=clearbit(number,bitNumber);
    printf("the number after sclearing bit %hhd : %hhd",bitNumber,newNumber);
}
