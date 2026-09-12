#include"HC05_Interface.h"

void HC05_Init(){
    DIO_InitPin(Dio_GroupD,Dio_Pin0,Input);
    DIO_InitPin(Dio_GroupD,Dio_Pin1,Output);
    Uart_Config_t Config={
        .ModeSelect=Uart_AsynchronousMode,
        .StopBitSelect=Uart_1StopBit,
        .ParitySelect = Uart_ParityDisabled,
        .SpeedMode = Uart_NormalSpeed,
        .BaudRate = 9600,
        .SizeCharacterSelect = Uart_8BitSize,
        .EnbaleSelect = Uart_EnableRxAndTx,
        .InterruptSelect = Uart_InterruptDisabled   
    };
    UART_Init(Config);
    _delay_ms(500);
    UART_SendStringPolling("welcome\r");
    _delay_ms(500);
}
 
uint16_t HC05_Get_Data(){
    uint16_t data=0;
    data=UART_ReceiveBytePolling();
    return data;
}
