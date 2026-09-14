#include <stdio.h>


int main()
{
int num=0;

printf("Enter any no: \n");
scanf("%d", &num );


int LSB_Value= (num>>0)&1;
if(LSB_Value==0)
{
    printf("Number is even\n");
    
}
else 
    {
    printf("Number is odd\n"); 
    }

}