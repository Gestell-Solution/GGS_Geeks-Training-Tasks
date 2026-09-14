#include "MCAL/DIO/DIO_Interface.h"
#include <util/delay.h>


void main()
{ 
    DIO_InitPin(Dio_GroupB, Dio_Pin0, Output);

    while(1)
    {
    DIO_TogglePin(Dio_GroupB,Dio_Pin0);
    _delay_ms(500);
    }

}

