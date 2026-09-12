#include <util/delay.h>
#include "MCAL/DIO/DIO_Interface.h"
#include "HAL/LED/LED_Interface.h"
#include"HAL/hc05_Bluetooth_module/HC05_Interface.h"


//uart work in this folder

void main()
{
    uint16_t data=0;
    Led_Init(Dio_GroupA,Dio_Pin0,SourceConnection);
    Led_Init(Dio_GroupA,Dio_Pin1,SourceConnection);
    Led_Init(Dio_GroupA,Dio_Pin2,SourceConnection);
    HC05_Init();
    while (1)
    {
        data=HC05_Get_Data();
        if(data=='s'){
            Led_on(Dio_GroupA,Dio_Pin0);
        }
        else if(data=='p'){
            Led_on(Dio_GroupA,Dio_Pin1);
        }
        else if(data=='w'){
            Led_on(Dio_GroupA,Dio_Pin2);
        }
        else if(data=='a'){
            Led_off(Dio_GroupA,Dio_Pin0);
            Led_off(Dio_GroupA,Dio_Pin1);
            Led_off(Dio_GroupA,Dio_Pin2);
        }
    }
    
}


