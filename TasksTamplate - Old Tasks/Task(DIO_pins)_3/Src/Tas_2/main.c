#include <util/delay.h>
#include "MCAL/TIMER0/Timer0_Interface.h"
#include "MCAL/TIMER0/Timer0_Private.h"
#include "MCAL/DIO/DIO_Interface.h"


void main()
{
    DIO_InitPin( Dio_GroupB,Dio_Pin3,Output);
    Timer0_Config_t TimerConfig =
    {
        .TimerMode            = Timer0_FastPWM,
        .PreloadValue         = 0,
        .CompareMatchValue    = 0,
        .DutyCycleInitValue   = 50,
    };
     TIMER0_Init(TimerConfig);
     TIMER0_Start(Timer0_Prescaller8);

    while(1)
    {
   TIMER0_SetPWMDutyCycle(50);
   _delay_ms(15);
   TIMER0_SetPWMDutyCycle(75); 
    _delay_ms(15);
   TIMER0_SetPWMDutyCycle(100);  
    _delay_ms(15);

    }
}