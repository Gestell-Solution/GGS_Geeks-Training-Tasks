#include <stdint.h>
#include<stdio.h>


void Check_NumberIsEvenOROdd(uint8_t number){
if((number & 1)==0){
    printf("The number is Even \n");

}
else{
    printf("The number is Odd \n");

}
}