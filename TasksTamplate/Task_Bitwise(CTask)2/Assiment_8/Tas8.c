#include<stdio.h>
#include<stdint.h>
#include "Tas8.h"

int main(){
uint8_t Number=0;
printf("Enter your number : ");
scanf("%d", &Number);   
Check_MSBofNumber(Number);


    return 0;
}