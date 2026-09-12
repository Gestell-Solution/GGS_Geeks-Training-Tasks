#include "BUZZER_Interface.h"
#include "BUZZER_Config.h"

void Buzzer_Init(uint8_t Group_name ,uint8_t Pin_number)
{
    DIO_InitPin(Group_name, Pin_number, Output);
}

void Buzzer_On(uint8_t Group_name ,uint8_t Pin_number)
{
    DIO_WritePin(Group_name, Pin_number, High);
}

void Buzzer_Off(uint8_t Group_name ,uint8_t Pin_number)
{
    DIO_WritePin(Group_name, Pin_number, Low);
}
void Buzzer_toggle(uint8_t Group_name ,uint8_t Pin_number){
    DIO_TogglePin(Group_name, Pin_number);
}