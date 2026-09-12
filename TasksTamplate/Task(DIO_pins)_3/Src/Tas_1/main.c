#include "MCAL/DIO/DIO_Interface.h"
#include <util/delay.h>
#include "MCAL/Atmega32regmap.h"
#include "LIB/Bitmath.h"

void main()
{
     DIO_InitPin( Dio_GroupA,Dio_Pin0,Output);

    while(1)
    {
    DIO_Toggle( Dio_GroupA,Dio_Pin0);
     _delay_ms(500);

    }


}