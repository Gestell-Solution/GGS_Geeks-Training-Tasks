#include"LED_Interface.h"

void Led_Init(uint8_t GroupName , uint8_t PinNumber)
{
    DIO_InitPin(GroupName,PinNumber,Output);
}


void Led_on(uint8_t GroupName , uint8_t PinNumber , uint8_t ConnectionType)
{
    if(ConnectionType==SourceConnection)
        {
            DIO_WritePin(GroupName,PinNumber,High);
        }
        else if (ConnectionType==SinkConnection)
        {
            DIO_WritePin(GroupName,PinNumber,Low);
 
        }

}

void Led_off(uint8_t GroupName , uint8_t PinNumber , uint8_t ConnectionType)
{

    if(ConnectionType==SourceConnection)
        {
            DIO_WritePin(GroupName,PinNumber,Low);
        }
        else if (ConnectionType==SinkConnection)
        {
            DIO_WritePin(GroupName,PinNumber,High);
        }

}


//  void Led_Toggle(uint8_t GroupName , uint8_t PinNumber)
// {
//  DIO_TogglePin(GroupName,PinNumber);
// }