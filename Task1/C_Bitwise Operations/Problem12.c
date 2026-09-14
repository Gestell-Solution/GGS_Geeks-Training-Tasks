#include <stdio.h>

int main()
{
    int number=0;
    int rotations_number=0;

    printf("Enter any number: ");
    scanf("%d", &number);
    
    printf("Enter number of rotations: ");
    scanf("%d", &rotations_number);

    int left_rotated= number<<rotations_number;
    int right_rotated=number>>rotations_number ;

printf("%d left rotated %d times = %d\n", number,rotations_number,left_rotated );
printf("%d right rotated %d times = %d\n", number,rotations_number,right_rotated );



}