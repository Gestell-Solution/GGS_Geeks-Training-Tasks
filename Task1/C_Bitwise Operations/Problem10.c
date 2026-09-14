#include <stdio.h>

int main()
{
    int number=0;
    int new_number=0;
    printf("Enter any number: ");
    scanf("%d", &number);

    new_number = ~number;
    printf("Original Number =%d (in decimal)\n",number );
    printf("Number after bits are flipped = %d (in decimal)\n", new_number);

    return 0;
}


