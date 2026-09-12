#include"header.h"
void decimal_to_binary(uint8_t number){
    uint8_t binary=0,
    counter=0,
    bitchar=8;
    for(counter=0;counter<bitchar;counter++){
        binary=readbit(number,counter);
        printf("%hhd",binary);
    }
}