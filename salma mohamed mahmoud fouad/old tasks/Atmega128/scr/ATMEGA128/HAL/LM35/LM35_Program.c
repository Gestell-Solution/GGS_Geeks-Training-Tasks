#include"LM35_Interface.h"

void LM35_Init(){
    DIO_InitPin(LM35_Group,LM35_PIN,Input);
    ADC_Config_t LM35={
       .Reference_Selection=ADC_AVCC,
       .prescaler_selection=ADC_Prescaler_128,
       .Adjust=ADC_rightAdjust,
       .free_running_mode_enable=Off,
       .interrupt_enable=Off,
    };
    ADC_Init(LM35);
}

uint8_t LM35_Read(){
    uint16_t data =0;
    uint16_t temp =0;
    data=ADC_ReadChannelPolling(ADC_SINGLE_ENDED_ADC0);
    temp=(data*4.88);
    temp=temp/10;
    return temp;
}

