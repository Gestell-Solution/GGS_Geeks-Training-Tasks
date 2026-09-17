#include<stdio.h>
#include <stdint.h>
#include "tas5.h"
int main(){
uint8_t num1=0;
uint8_t num2=0;
printf("Enter your first number : ");
scanf("%hhd",&num1);
printf("Enter your second number : ");
scanf("%hhd",&num2);
Swapped_Numbers(&num1, &num2);
printf("The first number after swapping is : %hhd \n",num1 );
printf("The second number after swapping is : %hhd \n",num2);




return 0;
};