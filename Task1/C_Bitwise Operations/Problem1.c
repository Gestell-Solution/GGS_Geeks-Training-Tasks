#include <stdio.h>

int main()
{
    int number=0;
    printf("Enter any number:\n");
    scanf("%d",&number);
    char result= (number>>0)&1;
    if(result==0)
    {
     printf("LSB of %d is unset(0)\n", number );
    }
    else
    {
     printf("LSB of %d is set(1)\n", number );
    }
}