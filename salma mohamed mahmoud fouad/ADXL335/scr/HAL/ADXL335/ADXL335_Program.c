#include"ADXL335_Interface.h"

void ADXL355_Init(){
    Uart_Config_t uart_setup={
        .
    }
    UART_Init(uart_setup);
    ADC_Config_t adc_setup={
        .
    }
    ADC_Init(adc_setup);
    DIO_InitPin(ADXL335_GROUP,ADXL335_X_PIN)
}

