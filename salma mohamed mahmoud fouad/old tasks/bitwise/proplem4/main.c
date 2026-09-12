#include"header.h"
int main(){
    uint8_t number=0,
    bitNumber=0;
    printf("enter number: ");
    scanf(" %hhd",&number);
    printf("enter bit number: ");
    scanf(" %hhd",&bitNumber);
    set_the_bitNumber(number,bitNumber);
}