#include "ADC_Interface.h"

static void (*ADC_CallBackPtr)(uint16_t) = 0;

void ADC_Init(Adc_Config_t Configuration)
{
if (Configuration.ReferenceSelection==Adc_AREF)
{
ClearBit(ADMUX_Reg,Adc_REFS1);
ClearBit(ADMUX_Reg,Adc_REFS0);
}
else if(Configuration.ReferenceSelection==Adc_AVCC)
{
ClearBit(ADMUX_Reg,Adc_REFS1);
SetBit(ADMUX_Reg,Adc_REFS0);
}
else if(Configuration.ReferenceSelection==Adc_Internal)
{
SetBit(ADMUX_Reg,Adc_REFS1);
SetBit(ADMUX_Reg,Adc_REFS0);
}

if(Configuration.AdjustResult==Adc_LeftAdjust)
{
SetBit(ADMUX_Reg,Adc_ADLAR);
}
else if(Configuration.AdjustResult==Adc_RightAdjust)
{
ClearBit(ADMUX_Reg,Adc_ADLAR);
}

if(Configuration.ConversionMode==SingleMode)
{
ClearBit(ADCSRA_Reg,Adc_ADATE);
}
else if(Configuration.ConversionMode==AutoMode)
{
SetBit(ADCSRA_Reg,Adc_ADATE);
SFIOR_Reg=(SFIOR_Reg&~Adc_TriggerMask)|(Configuration.TriggerSource<<Adc_ADTS0);
}

if(Configuration.InterruptState==Disable)
{
ClearBit(ADCSRA_Reg,Adc_ADIE);
}
else if(Configuration.InterruptState==Enable)
{
SetBit(ADCSRA_Reg,Adc_ADIE);
}

//Selecting Prescaler
ADCSRA_Reg=ADCSRA_Reg&~Adc_PrescalerMask|Configuration.PrescalerSelection ;

//Enabling ADC
SetBit(ADCSRA_Reg,Adc_ADEN);

}



uint16_t ADC_ReadChannelPolling(uint8_t Channel)
{
    uint32_t Timeout_Counter = 0;

ADMUX_Reg=(ADMUX_Reg &~Adc_ChannelMask)|Channel ;
SetBit(ADCSRA_Reg,Adc_ADSC);

while((ReadFlag(ADCSRA_Reg,Adc_ADIF)!=FlagUp)&&(Timeout_Counter<ADC_TIMEOUT))
{
Timeout_Counter++;
}

  if(Timeout_Counter >= ADC_TIMEOUT)
  {
    return ADC_TIMEOUT_ERROR;
  }

   ClearFlag(ADCSRA_Reg,Adc_ADIF);
    return ADCData_Reg;
}



void ADC_StartConvserionInterrupt(uint8_t Channel)
{

ADMUX_Reg=(ADMUX_Reg &~Adc_ChannelMask)|Channel ;
SetBit(ADCSRA_Reg,Adc_ADSC);

}

void ADC_SetCallback(void (*CopyFuncPtr)(uint16_t))
{
ADC_CallBackPtr=CopyFuncPtr;
}




void __vector_14(void) __attribute__((signal));

void __vector_14(void)
{
if(ADC_CallBackPtr!=Null)
{
    ADC_CallBackPtr(ADCData_Reg);
}

}