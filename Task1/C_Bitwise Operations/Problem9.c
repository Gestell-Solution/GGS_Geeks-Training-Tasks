#include <stdio.h>

int main()
{  
    int number=0;
    printf("Enter any number:\n");
    scanf("%d",&number);
    int zeros_counter=0;
    char counter=31;
    char read_bit=0;
    do{
     read_bit= (number>>counter)&1;
     if(read_bit==0)
     {
     zeros_counter++;
     }
     counter--;
    }while(read_bit!=1&&counter>=0);

    printf("Total number of leading zeros in %d is : %d\n",number,zeros_counter);
}