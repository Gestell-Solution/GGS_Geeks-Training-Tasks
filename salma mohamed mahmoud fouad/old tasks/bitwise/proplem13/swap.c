#include"header.h"
void swap(uint8_t number,uint8_t number2){
    number=number^number2;
    number2=number2^number;
    number=number^number2;
    printf("num1 : %hhd\n",number);
    printf("num2 : %hhd",number2);
}
