#include<stdio.h>
#include <stdint.h>
#include "tas4.h"
int main(){
uint8_t number=0;
printf("Enter your number : ");
scanf("%d",&number);
printf(" 20 left rotated  times = %d \n", Rotate_LeftNumber(number, 2));
printf(" 20 right rotated  times = %d \n", Rotate_RightNumber(number, 2));
return 0;
};