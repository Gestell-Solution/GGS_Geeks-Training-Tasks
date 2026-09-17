#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/TIMER0/Timer0_Interface.h"
#include "MCAL/GIE/GIE_Interface.h"
#include "LIB/Bitmath.h"

// Requirment 1 Second
// Prescaler 64
//Freq 8MHz
// CLK Time=Pre/Fre =64/8000000=8Ms
// CTC value= Req/CLK Time = 1000Ms/8Ms=125 


void TIMER0_1Sec()
{
    TIMER0_Start(Timer0_Prescaller64);

    for(uint16_t i = 0; i < 1000; i++)
    {
       while(READ_BIT(TIFR, OCF0) == 0);
           SET_BIT(TIFR, OCF0);
    }

    TIMER0_Stop();
}

void main()
{
    Timer0_Config_t TimerConfig =
    {
        .TimerMode            = Timer0_CTCMode,
        .PreloadValue         = 0,
        .CompareMatchValue    = 124,
        .PWMOutputMode        = Timer0_OC0NinInverting,
        .DutyCycleInitValue   = 0,
    };
     DIO_InitPin( Dio_GroupB, Dio_Pin0,Output);
     TIMER0_Init(TimerConfig);

    while(1)
    {
        DIO_Toggle(Dio_GroupB, Dio_Pin0);
        TIMER0_1Sec();
       
    }
    
}
