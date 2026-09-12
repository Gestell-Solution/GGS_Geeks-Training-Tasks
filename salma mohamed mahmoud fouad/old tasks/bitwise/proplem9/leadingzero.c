#include"header.h"
void count_leading_zero(uint8_t number){
    uint8_t zeroNumber=0,
    charBit=0,
    counter=0;
    for(counter=8;counter>charBit;counter--){
        if(readbit(number,counter)){
            break;
        }
        zeroNumber++;
    }
    printf("your number of leading zeros : %hhd",zeroNumber-1);
}