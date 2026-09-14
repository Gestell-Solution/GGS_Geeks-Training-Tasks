#include <stdio.h>

int main()
{
    int number=0;
    int new_number=0;

    char BitToBeCleared=0;
    printf("Enter any number:\n");
    scanf("%d",&number);
    printf("Enter nth bit to set(0-31):\n");
    scanf("%hhd",&BitToBeCleared);
    new_number=number;
    new_number&=~(1<<BitToBeCleared);
    printf("Bit set successfully\n");

    printf("Number before clearing %hhd bit : %d (in decimal)\n",BitToBeCleared,number);
    printf("Number after clearing %hhd bit : %d (in decimal)\n",BitToBeCleared,new_number);


}