#include"header.h"
void count_ones_and_zeros(uint8_t number){
    uint8_t ones=0,
    zeroes=0,
    counter=0,
    bitchar=8,
    result=0;
    for(counter=0;counter<bitchar;counter++){
        result=readbit(number,counter);
        if(result==0){
            zeroes++;
        }
        else if(result==1){
            ones++;
        }
    }
    printf("number of zeroes: %hhd\n",zeroes);
    printf("number of ones: %hhd",ones);
}
