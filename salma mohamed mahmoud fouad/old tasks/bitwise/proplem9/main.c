#include"header.h"
int main(){
    uint8_t number=0;
    printf("enter number: ");
    scanf(" %hhd",&number);
    count_leading_zero(number);
}