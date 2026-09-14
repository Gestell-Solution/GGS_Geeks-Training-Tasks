#include <stdio.h>

int main()
{
    int number=0;
    int counter=0;
    printf("Enter any number:\n");
    scanf("%d",&number);

    char read_bit=0;

    if(number==0)
    {
        printf("There is no set bit\n");
    }
    else
    { 
    do
    {
        read_bit=(number>>counter)&1 ;
        counter++;
    } while (read_bit!=1&& counter<sizeof(number)*8);
    
    printf("Lowest order set bit in %d is %d",number,counter-1);
    }


}
