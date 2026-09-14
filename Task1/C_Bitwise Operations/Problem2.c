#include <stdio.h>


int main()
{
    
   int number=0;
   printf("Enter any number:\n");
   scanf("%d",&number);
    int bits_number= sizeof(number) *8;
    int MSB_position= bits_number - 1 ;
    char result= (number>>MSB_position)&1;
    if(result==0)
    {
    printf("MSB of %d is unset(0)\n", number );
    }
    else
    {
     printf("MSB of %d is set(1)\n", number );
    }


}

//another solution (without bitwise operation)
/*
 int number=0;
    printf("Enter any number:\n");
    scanf("%d",&number);

    if(number>=0)
    {
     printf("MSB of %d is unset(0)\n", number );
    }
    else
    {
     printf("MSB of %d is set(1)\n", number );
    }

*/