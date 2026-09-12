#include"header.h"
void lowest_order_of_set_bit(uint8_t number){
    uint8_t lowestSetBit=0,
    charBit=0,
    counter=0;
    for(counter=8;counter>charBit;counter--){
        if(readbit(number,counter)){
            lowestSetBit=counter;
        }
    }
     printf("the lowest set bit is %hhd",counter);   
}
