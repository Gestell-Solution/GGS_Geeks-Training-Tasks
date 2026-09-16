#include"ADC_Interface.h"

void ADC_Init(ADC_Config_t config){
    if(config.Reference_Selection==ADC_AREF){
        ClearBit(ADMUX_Reg,ADC_REFS1);
        ClearBit(ADMUX_Reg,ADC_REFS0);
    }
    else if(config.Reference_Selection==ADC_AVCC){
        ClearBit(ADMUX_Reg,ADC_REFS1);
        SetBit(ADMUX_Reg,ADC_REFS0);
    }
    else if(config.Reference_Selection==ADC_INTERNAL){
        SetBit(ADMUX_Reg,ADC_REFS1);
        SetBit(ADMUX_Reg,ADC_REFS0);
    }
    if(config.Adjust==ADC_leftAdjust){
         SetBit(ADMUX_Reg,ADC_ADLAR);
    }
    else if(config.Adjust==ADC_rightAdjust){
        ClearBit(ADMUX_Reg,ADC_ADLAR);
    }
    if(config.free_running_mode_enable==ADC_FREErunningMode){
        SetBit(ADCSRA_Reg,ADC_ADFR);
    }
    else{
        ClearBit(ADCSRA_Reg,ADC_ADFR);
    }
    if(config.interrupt_enable==Enable_interrupt){
        SetBit(ADCSRA_Reg,ADC_ADIE);
    }
    else{
        ClearBit(ADCSRA_Reg,ADC_ADIE);
    }
    ADCSRA_Reg=(ADCSRA_Reg&~ADC_prescaler_mask)|config.prescaler_selection;
    SetBit(ADCSRA_Reg,ADC_ADEN);
}
uint16_t ADC_ReadChannelPolling(uint8_t Channel){
    ADMUX_Reg=(ADMUX_Reg&~ADC_Channel_mask)|Channel;
    SetBit(ADCSRA_Reg,ADC_ADSC);
    while(ReadFlag(ADCSRA_Reg,ADC_ADIF)!=FlagUp); 
    ClearFlag(ADCSRA_Reg,ADC_ADIF);
    uint16_t AdcData =  ADCL_Reg;
    AdcData = AdcData| (ADCH_Reg<<8);
    return AdcData;
}
void ADC_StartConvserionInterrupt(uint8_t Channel){
    ADMUX_Reg=(ADMUX_Reg&~ADC_Channel_mask)|Channel;
    SetBit(ADCSRA_Reg,ADC_ADSC);
}