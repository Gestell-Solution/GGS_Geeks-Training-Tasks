#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/TIMER0/Timer0_Interface.h"
#include "HAL/DC_MOTOR/DC_MOTOR_Interface.h"




void main()
{
    Timer0_Config_t TimerConfig =
    {
        .TimerMode            = Timer0_FastPWM,
        .PreloadValue         = 0,
        .CompareMatchValue    = 0,
        .PWMOutputMode        = Timer0_OC0NinInverting,
        .DutyCycleInitValue   = 90,
    };
     DIO_InitPin( Dio_GroupB,Dio_Pin3,Output);
     TIMER0_Init(TimerConfig);
     TIMER0_Start(Timer0_Prescaller8);

    while(1)
    {
    TIMER0_SetPWMDutyCycle(90);
    }
    
}