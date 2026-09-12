#include"header.h"

void MSB_f(signed char number){
    uint8_t Bitchar=7,
    msb=0;
    msb=readbit(number,Bitchar);
    if(msb==1){
        printf("the MSB of %hhd is (1)",number);
    }
    else {
        printf("the MSB of %hhd is (0)",number);
    }
}
