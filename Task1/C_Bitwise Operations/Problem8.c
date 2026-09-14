#include <stdio.h>

int main()
{  
    int number=0;
    printf("Enter any number:\n");
    scanf("%d",&number);

    int zeros_counter=0;
    int result=0;
    int counter=0;
    

    for(counter=0;counter<32;counter++)
    {
        result= (number>>counter)&1;
        if(result==0)
        {
        zeros_counter++;  
        }
        else 
        {
            break;
        }
    }
    printf("Number of trailing zeros=%d\n",zeros_counter );



}