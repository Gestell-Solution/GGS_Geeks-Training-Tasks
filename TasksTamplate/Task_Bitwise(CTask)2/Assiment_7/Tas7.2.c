#include <stdint.h>
#include<stdio.h>

void Convert_NumberToBinary(int number , int Binary[]){
int i=0;
for(i=0;i<8;i++){
Binary[i]=number%2;
number=number/2;
}
}