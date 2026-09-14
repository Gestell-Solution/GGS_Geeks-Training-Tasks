#include "HAL/BTModule/BTModule_Interface.h"
#include "MCAL/DIO/DIO_Interface.h"



int main()
{
    //LED Configuration
    DIO_InitPin(Dio_GroupA, Dio_Pin0, Output);
    DIO_WritePin(Dio_GroupA, Dio_Pin0, Low); 

    
    Bluetooth_Init();
    Bluetooth_SendString((uint8_t*)"Bluetooth Ready!\r\n");

    while(1)
    {
        
        uint8_t receivedCommand = Bluetooth_ReceiveChar();

        if (receivedCommand == '1')
        {
            DIO_WritePin(Dio_GroupA, Dio_Pin0, High);                    
            Bluetooth_SendString((uint8_t*)"LED ON\r\n");      
        }
        else if (receivedCommand == '0')
        {
            DIO_WritePin(Dio_GroupA, Dio_Pin0, Low);                   
            Bluetooth_SendString((uint8_t*)"LED OFF\r\n");     
        }
    }
}