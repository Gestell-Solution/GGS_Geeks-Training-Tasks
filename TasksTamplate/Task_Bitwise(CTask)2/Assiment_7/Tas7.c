#include<stdio.h>
#include <stdint.h>
#include "Tas7.h"
int main(){
int number=0;
int Binary[8]={0};
printf("Enter your number : ");
scanf("%d",&number);
Convert_NumberToBinary(number,Binary);
printf("\n The Binary number is : ");
for(int i=7;i>=0;i--){
printf("%d",Binary[i]);
}

return 0;
};