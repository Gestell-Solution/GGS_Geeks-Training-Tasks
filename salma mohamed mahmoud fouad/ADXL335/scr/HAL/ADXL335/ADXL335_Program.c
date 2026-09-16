#include"ADXL335_Interface.h"

void ADXL355_Init(){
    Uart_Config_t uart_setup={
        .ModeSelect=Uart_AsynchronousMode,
        .StopBitSelect=Uart_1StopBit,
        .ParitySelect = Uart_ParityDisabled,
        .SpeedMode = Uart_NormalSpeed,
        .BaudRate = 9600,
        .SizeCharacterSelect = Uart_8BitSize,
        .EnbaleSelect = Uart_EnableRxAndTx,
        .InterruptSelect = Uart_InterruptDisabled
    };
    UART_Init(uart_setup);
    ADC_Config_t adc_setup={
        .Reference_Selection=ADC_AVCC,
        .Adjust=ADC_rightAdjust,
        .free_running_mode_enable=Off,
        .interrupt_enable=Off,
        .prescaler_selection=ADC_Prescaler_128,
    };
    ADC_Init(adc_setup);
    DIO_InitPin(ADXL335_GROUP,ADXL335_X_PIN,Input);
    DIO_InitPin(ADXL335_GROUP,ADXL335_Y_PIN,Input);
    DIO_InitPin(ADXL335_GROUP,ADXL335_Z_PIN,Input);
    UART_SendStringPolling("where are you\r");
}
void ADXL355_PrintData(){
    uint16_t X_data =0;
    uint16_t Y_data =0;
    uint16_t Z_data =0;
    X_data=ADC_ReadChannelPolling(ADC_SINGLE_ENDED_ADC0);
    Y_data=ADC_ReadChannelPolling(ADC_SINGLE_ENDED_ADC1);
    Z_data=ADC_ReadChannelPolling(ADC_SINGLE_ENDED_ADC2);
    UART_SendStringPolling("X:");
    UART_SendNumberPolling(X_data);
    UART_SendStringPolling("Y:");
    UART_SendNumberPolling(Y_data);
    UART_SendStringPolling("Z:");
    UART_SendNumberPolling(Z_data);
    UART_SendBytePolling('\r');
    _delay_ms(500);
} 

//make the calculation and if the uart didnt work use lcd and chaneg the pin config

