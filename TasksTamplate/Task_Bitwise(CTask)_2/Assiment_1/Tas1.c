#include<stdio.h>
#include <stdint.h>
#include "tas1.h"
int main(){

uint8_t number=0;
printf("Enter your number : ");
scanf("%d",&number);
Check_LSBOfNumber(number);

return 0;
};