#include <stdio.h>

int main()
{
    int number=0;
    int zeros_counter=0;
    int ones_counter=0;
    printf("Enter any number: ");
    scanf("%d", &number);

int counter=0;
int MSB_Position=(sizeof(number)*8)-1;

for(counter=0;counter<=MSB_Position;counter++)
{
    int read_bit= (number>>counter)&1;
    if(read_bit==0)
    {
        zeros_counter++;
    }
    else 
    {
        ones_counter++;
    }
}

printf("total number of ones : %d\n", ones_counter);
printf("total number of zeros : %d\n", zeros_counter);

}