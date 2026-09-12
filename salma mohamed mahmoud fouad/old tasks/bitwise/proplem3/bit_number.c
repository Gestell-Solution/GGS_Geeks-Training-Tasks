#include"header.h"
void bitNumber_f(uint8_t number,uint8_t bit_number){
    uint8_t check_bit_number=0;
    check_bit_number=readbit(number,bit_number);
    if(check_bit_number==0){
        printf("the bit %hhd is (0)",bit_number);
    }
    else{
        printf("the bit %hhd is (1)",bit_number);
    }
}
