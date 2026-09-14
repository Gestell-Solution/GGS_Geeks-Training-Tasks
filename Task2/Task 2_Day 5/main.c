#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/Timer0/Timer0_Interface.h"
#include <util/delay.h>

void main()
{

Timer0_Config_t PWM_Config =
{
.TimerMode=Timer0_FastPWM,
.PWMOutputMode=Timer0_OC0NonInverting
};
TIMER0_Init(PWM_Config);
DIO_InitPin(Dio_GroupB,Dio_Pin3,Output);
TIMER0_Start(Timer0_Prescaler8);



while(1)
{
    TIMER0_SetPWMDutyCycle(20);
     _delay_ms(3000);
     
    TIMER0_SetPWMDutyCycle(40);
     _delay_ms(3000);

    TIMER0_SetPWMDutyCycle(60);
     _delay_ms(3000);

    TIMER0_SetPWMDutyCycle(80);
     _delay_ms(3000);

}


}