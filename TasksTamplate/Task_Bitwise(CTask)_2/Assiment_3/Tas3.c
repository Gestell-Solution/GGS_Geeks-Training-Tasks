#include<stdio.h>
#include <stdint.h>
#include "tas3.h"
int main(){

uint8_t number=0;
uint8_t ones_Count=0;
uint8_t zeroes_Count=0;
printf("Enter your number : ");
scanf("%d",&number);
CountNumberofonesANDzeroes(number);
return 0;
};