#include"header.h"
int main(){
    uint8_t number=0,
    number2=0;
    printf("enter number: ");
    scanf(" %hhd",&number);
    printf("enter number: ");
    scanf(" %hhd",&number2);
    swap(number,number2);
}