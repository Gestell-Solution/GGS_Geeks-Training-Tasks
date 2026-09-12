#include<stdio.h>
#include <stdint.h>
#include "tas6.h"
int main(){
uint8_t number=0;
printf("Enter your number : ");
scanf("%hhd",&number);
Check_NumberIsEvenOROdd(number);
return 0;
};