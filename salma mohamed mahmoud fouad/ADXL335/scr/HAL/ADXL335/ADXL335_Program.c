/**
 * @file ADXL335_Program.c
 * @author salma mohamed mahmoud fouad(salmafouadothman@gmail.com)
 * @brief driver to initazle the asxl335 sensor and print the data
 * @version 0.1
 * @date 2026-09-21
 * @copyright Copyright (c) 2026  
 */
#include"ADXL335_Interface.h"
/**
 * @brief number from the data sheet to help initazeling they can be changed
 */
#define VREF    5.0F
#define ZERO_G  1.5F   
#define SENS    0.300F    
#define divide  1024.0F


void ADXL335_Init(){
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
}
void ADXL335_PrintData(){
    U16 X_data =0;
    U16 Y_data =0;
    U16 Z_data =0;
    F32 x_axis=0;
    F32 y_axis=0;
    F32 z_axis=0;


    X_data=ADC_ReadChannelPolling(ADC_SINGLE_ENDED_ADC0);
    Y_data=ADC_ReadChannelPolling(ADC_SINGLE_ENDED_ADC1);
    Z_data=ADC_ReadChannelPolling(ADC_SINGLE_ENDED_ADC2);

    x_axis=((((F32)X_data*VREF)/divide)-ZERO_G)/SENS;
    y_axis=((((F32)Y_data*VREF)/divide)-ZERO_G)/SENS;
    z_axis=((((F32)Z_data*VREF)/divide)-ZERO_G)/SENS;

    UART_SendStringPolling("X: ");
    UART_SendNumberPolling(x_axis);
    UART_SendStringPolling(" Y: ");
    UART_SendNumberPolling(y_axis);
    UART_SendStringPolling(" Z: ");
    UART_SendNumberPolling(z_axis);
    UART_SendBytePolling('\r');
    _delay_ms(500);
} 


