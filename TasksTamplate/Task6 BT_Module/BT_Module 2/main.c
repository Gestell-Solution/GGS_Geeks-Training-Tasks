#include "MCAL/Uart/Uart_Interface.h"
#include "MCAL/DIO/DIO_Interface.h"
#include "HAL/CH_05/CH_05_Interface.h"

#define LED_GROUP     DIO_GroupA
#define LED_PIN       DIO_Pin0

#define BUTTON_GROUP  DIO_GroupA
#define BUTTON_PIN    DIO_Pin1

int main(void)
{
    uint8_t Local_ButtonState     = High;
    uint8_t Local_PrevButtonState = High; /* previous reading, for edge detection */

    DIO_InitPin(LED_GROUP, LED_PIN, Output);
    DIO_InitPin(BUTTON_GROUP, BUTTON_PIN, Input);

    Bluetooth_Init();
    Bluetooth_SendString("Ali Sotohy!\r\n");

    while (1)
    {
        DIO_ReadPin(BUTTON_GROUP, BUTTON_PIN, &Local_ButtonState);

        
        if (Local_ButtonState == Low && Local_PrevButtonState == High)
        {
            
             Bluetooth_SendString("Button Pressed!\r\n");
            DIO_WritePin(LED_GROUP, LED_PIN, High);
        }
        else if (Local_ButtonState == High && Local_PrevButtonState == Low)
        {
            Bluetooth_SendString("Button Released!\r\n");
            DIO_WritePin(LED_GROUP, LED_PIN, Low);
        }

        Local_PrevButtonState = Local_ButtonState;
    }
}