#include"header.h"
int main(){
    uint8_t number=0,
    rotation_number=0;
    printf("enter number: ");
    scanf(" %hhd",&number);
    printf("enter rotation number: ");
    scanf(" %hhd",&rotation_number);
    rotation(number,rotation_number);
}