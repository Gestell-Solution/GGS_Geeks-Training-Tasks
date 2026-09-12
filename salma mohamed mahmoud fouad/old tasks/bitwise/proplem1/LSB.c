#include"header.h"

void LSB_f(uint8_t number){
     if(number&1){
      printf("the LSB of %hhd is (1)",number);
    }
    else{
      printf("the LSB of %hhd is (0)",number);
    }
}
