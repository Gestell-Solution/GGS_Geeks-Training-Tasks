#include <stdint.h>
#include<stdio.h>

void Swapped_Numbers(uint8_t *num1, uint8_t *num2){
    *num1=*num1^*num2;
    *num2=*num1^*num2;
    *num1=*num1^*num2;
    
}
