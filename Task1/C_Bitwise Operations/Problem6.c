#include <stdio.h>

int main()
{
    int number=0;
    int count= (sizeof(number)*8)-1;
    char read_bit=0;
    printf("Enter any number:\n");
    scanf("%d",&number);

    if(number==0)
    {
        printf("There is no set bit\n");
    }
    else
    { 
    do
    {
        
        read_bit=(number>>count)&1 ;
        count--;
    } while (read_bit!=1);
    
    printf("Highest order set bit in %d is %d",number,count+1);
    }
    
   


}