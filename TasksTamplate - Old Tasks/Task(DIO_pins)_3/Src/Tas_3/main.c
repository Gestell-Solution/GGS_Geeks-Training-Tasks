#include <util/delay.h>
#include "MCAL/DIO/DIO_Interface.h"



void main()
{
        DIO_InitPin(Dio_GroupA, Dio_Pin1, Output);
    while(1)
    {
         DIO_WritePin(Dio_GroupA, Dio_Pin1, High);
        _delay_ms(1000);
        DIO_WritePin(Dio_GroupA, Dio_Pin1, Low);
        _delay_ms(1000);
    }

    
}