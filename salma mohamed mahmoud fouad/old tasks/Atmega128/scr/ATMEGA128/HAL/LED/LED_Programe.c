#include"LED_Interface.h"

static uint8_t StaticConnectionType = 0 ; 
void Led_Init(uint8_t GroupName , uint8_t PinNumber,uint8_t ConnectionType)
{
    DIO_InitPin(GroupName,PinNumber,Output);
    StaticConnectionType=ConnectionType;
}
void Led_on(uint8_t GroupName , uint8_t PinNumber )
{
    if(StaticConnectionType==SourceConnection)
        {
            DIO_WritePin(GroupName,PinNumber,High);
        }
        else if (StaticConnectionType==SinkConnection)
        {
            DIO_WritePin(GroupName,PinNumber,Low);
 
        }

}

void Led_off(uint8_t GroupName , uint8_t PinNumber)
{

    if(StaticConnectionType==SourceConnection)
        {
            DIO_WritePin(GroupName,PinNumber,Low);
        }
        else if (StaticConnectionType==SinkConnection)
        {
            DIO_WritePin(GroupName,PinNumber,High);
        }

}


void Led_Toggle(uint8_t GroupName , uint8_t PinNumber)
{

    DIO_TogglePin(GroupName,PinNumber);

}
