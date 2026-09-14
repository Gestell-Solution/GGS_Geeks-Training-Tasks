#include <stdio.h>

int main()
{
    int number=0;
    int new_number=0;

    char BitToBeSet=0;
    printf("Enter any number:\n");
    scanf("%d",&number);
    printf("Enter nth bit to set(0-31):\n");
    scanf("%hhd",&BitToBeSet);
    new_number=number;
    new_number=new_number|(1<<BitToBeSet);
    printf("Bit set successfully\n");

    printf("Number before setting %hhd bit : %d (in decimal)\n",BitToBeSet,number);
    printf("Number after setting %hhd bit : %d (in decimal)\n",BitToBeSet,new_number);


}