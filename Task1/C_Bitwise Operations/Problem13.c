#include <stdio.h>
int main()
{

int num1=0;
int num2=0;
printf("Enter any two numbers: \n");
scanf("%d %d", &num1,&num2);

printf("Original value of num1= %d\n",num1);
printf("Original value of num2= %d\n",num2);

num1=num1^num2;
num2=num1^num2;
num1=num1^num2;

printf("Num1 after swapping:%d \n",num1);
printf("Num2 after swapping:%d \n",num2);



}