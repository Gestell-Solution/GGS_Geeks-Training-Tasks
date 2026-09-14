#include <stdio.h>

int main()
{
int num=0;

printf("Enter any no: \n");
scanf("%d", &num );
int SIZE =sizeof(num)*8 ;
int arr[SIZE];

int counter=SIZE-1;
for(counter=SIZE-1;counter>=0;counter--)
{
arr[counter]= (num>>counter)&1;
}



printf("Converted Binary:" );

for(counter=SIZE-1;counter>=0;counter--)
{
printf("%d",arr[counter]);
}

}