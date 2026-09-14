#include "MCAL/Timer0/Timer0_Interface.h"
#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/GIE/GIE_Interface.h"


        //Timer = 8bit ,systemfreq= 8Mhz, prescaller= 8 
        //Req=1sec 
        //CLKTIME      = Prescaller/SystemFreq -> 1uSec
        //OverFlowtime = 2^Size * CLKTIME = 256uSec
        //RelationReq&Over => Req>OverFlow 
        //No OF OVF Count =   ReqTime/OverFlowTime = 1000000/256 
        //                   =   3906.25 => 3907
        //Preload          =    2^Size *(1-0.y) = 256 * (1-0.25) = 192
void ToggleLed ()
{
    static uint32_t count=0;
    count++;
    if(count==3907)
    {
        DIO_TogglePin(Dio_GroupB,Dio_Pin0);
        TIMER0_SetPreload(192);
        count=0;
    }
}

void main()
{
    Timer0_Config_t ToggleSystemConf=
    {
    .TimerMode=Timer0_NormalMode,
    .PreloadValue=192
    };

DIO_InitPin(Dio_GroupB,Dio_Pin0,Output);
TIMER0_Init(ToggleSystemConf);
TIMER0_SetCallBackFunction(Timer0_OverFlowInterrupt,ToggleLed);
GIE_Enable();
TIMER0_Start(Timer0_Prescaler8);

while (1)
    {
        // Infinite loop to keep the MCU running while ISR fires in the background 
    }

}