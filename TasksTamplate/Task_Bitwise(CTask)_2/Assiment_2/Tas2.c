#include<stdio.h>
#include <stdint.h>
#include "tas2.h"
int main(){
uint8_t number=0;
printf("Enter your number : ");
scanf("%d",&number);
uint8_t FlipedNumber=Flip_Number(number);
printf("The Original number is : %d \n",number );
printf("The Flipped number is : %d \n",FlipedNumber);

return 0;
};