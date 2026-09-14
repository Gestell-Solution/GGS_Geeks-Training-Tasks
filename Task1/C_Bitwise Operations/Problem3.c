#include <stdio.h>

int main()
{
    int number=0;
    char check_bit=0;
    printf("Enter any number:\n");
    scanf("%d",&number);
    printf("Enter nth bit to check(0-31):\n");
    scanf("%hhd",&check_bit);
    char result= (number>>check_bit)&1;

    if(result==0)
    {
    printf("The %hhd bit is set to 0",check_bit);
    }
    else 
    {
    printf("The %hhd bit is set to 1",check_bit);
    }


}