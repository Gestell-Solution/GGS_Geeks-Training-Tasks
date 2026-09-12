#include"header.h"
int main(){
    uint8_t number=0;
    printf("enter number: ");
    scanf(" %hhd",&number);
    highest_order_of_set_bit(number);
}