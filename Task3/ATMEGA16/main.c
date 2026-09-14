//Testing DIO&EXTI Drivers:

#include "MCAL/EXTI/EXTI_Interface.h"
#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/GIE/GIE_Interface.h"
#include <util/delay.h>

 
void main()
{
    DIO_InitPin(Dio_GroupA,Dio_Pin0,Output);
    DIO_InitPin(Dio_GroupA,Dio_Pin1,Output);
    DIO_InitPin(Dio_GroupD,Dio_Pin2,Input);

    
    EXTI_Init(Exti_Interrupt0,Exti_AnyChange);
    EXTI_Enable(Exti_Interrupt0);
    GIE_Enable();

    while(1)
    {

    DIO_TogglePin(Dio_GroupA,Dio_Pin0);
    _delay_ms(1000);
    }
    

}
    void __vector_1(void) __attribute__((signal));
    void __vector_1(void)
    {

    
    static uint8_t LED_State=0;
    if(LED_State==Low)
    {
     DIO_WritePin(Dio_GroupA,Dio_Pin1,High);
     LED_State=High;
     
    }
    else if(LED_State==High) 
    {
     DIO_WritePin(Dio_GroupA,Dio_Pin1,Low);
     LED_State=Low;
     
    }


    }

