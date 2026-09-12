#include"header.h"
void countzero(uint8_t number){
    uint8_t zeroNumber=0,
    charBit=0,
    counter=0;
    for(counter=8;counter>charBit;counter--){
        if(readbit(number,counter)){
                zeroNumber=counter;
        }
    }
    printf("your number of zero after the last 1 from the left : %hhd",zeroNumber);
}