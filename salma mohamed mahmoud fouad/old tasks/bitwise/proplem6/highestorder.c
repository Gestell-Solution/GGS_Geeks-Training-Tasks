#include"header.h"
void highest_order_of_set_bit(uint8_t number){
    uint8_t highestSetBit=0,
    charBit=8,
    counter=0;
    for(counter=0;counter<charBit;counter++){
        if(readbit(number,counter)){
        highestSetBit=counter;
        }
    }
     printf("the highest set bit is %hhd",highestSetBit);
}
