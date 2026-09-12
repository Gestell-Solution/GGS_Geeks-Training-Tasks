#include"header.h"
void check_odd_or_even(uint8_t number){
    uint8_t check =0,
    LSB=0;
    check=readbit(number,LSB);
    if(check==0){
        printf("even number");
    }
    else if(check==1){
        printf("odd number");
    }
}