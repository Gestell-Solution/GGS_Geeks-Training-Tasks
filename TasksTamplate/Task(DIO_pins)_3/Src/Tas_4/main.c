#include "MCAL/DIO/DIO_Interface.h"
#include <util/delay.h>



void main()
{
    uint8_t State;
    DIO_InitPin(Dio_GroupA, Dio_Pin0, Input);
    DIO_WritePin(Dio_GroupA, Dio_Pin0, High); // Internal Pull Up 
    DIO_InitPin(Dio_GroupA, Dio_Pin1, Output);
    while (1)
    {
        DIO_ReadPin(Dio_GroupA, Dio_Pin0, &State);
        if (State == Low)
        {
        DIO_WritePin(Dio_GroupA, Dio_Pin1, High);
        }
        else
        {
         DIO_WritePin(Dio_GroupA, Dio_Pin1, Low);
        }
    }

}