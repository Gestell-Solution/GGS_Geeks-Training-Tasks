/**
 * @file ADC_Program.c
 * @brief ADC Program driver implementation.
 * @details Contains the implementation of the module APIs and internal helper functions.
 * @version 1.0.0
 * @author Yousef
 * @date 2026-09-24
 * @copyright Copyright (c) 2026, Gestell Company. All rights reserved.
 */

#include "ADC_Interface.h"

static void (*ADC_CallBack)(uint16_t) = Null;


void ADC_Init(Adc_Config_t Configuration)
{
    /* Select Voltage Reference */
    if(Configuration.ReferenceSelection == Adc_AREF)
    {
        ClearBit(ADMUX_Reg, Adc_REFS0);
        ClearBit(ADMUX_Reg, Adc_REFS1);
    }
    else if(Configuration.ReferenceSelection == Adc_AVCC)
    {
        SetBit(ADMUX_Reg, Adc_REFS0);
        ClearBit(ADMUX_Reg, Adc_REFS1);
    }
    else if(Configuration.ReferenceSelection == Adc_Internal)
    {
        SetBit(ADMUX_Reg, Adc_REFS0);
        SetBit(ADMUX_Reg, Adc_REFS1);
    }

    /* Select Result Adjustment */
    if(Configuration.AdjustResult == Adc_LeftAdjust)
    {
        SetBit(ADMUX_Reg, Adc_ADLAR);
    }
    else if(Configuration.AdjustResult == Adc_RightAdjust)
    {
        ClearBit(ADMUX_Reg, Adc_ADLAR);
    }

    /* Select Interrupt State */
    if(Configuration.InterruptState == Enable)
    {
        SetBit(ADCSRA_Reg, Adc_ADIE);
    }
    else if(Configuration.InterruptState == Disable)
    {
        ClearBit(ADCSRA_Reg, Adc_ADIE);
    }

    /* Select Conversion Mode */
    if(Configuration.AutomaticMode == AutoMode)
    {
        SetBit(ADCSRA_Reg, Adc_ADATE);

        SFIOR_Reg = (SFIOR_Reg & ~Adc_ADTSMask) | ((Configuration.TriggerSource & 0x07) << Adc_ADTS0);
    }
    else if(Configuration.AutomaticMode == SingleMode)
    {
        ClearBit(ADCSRA_Reg, Adc_ADATE);
    }

    /* Select Prescaler */
    ADCSRA_Reg = (ADCSRA_Reg & ~Adc_PrescalerMask) | Configuration.PrescallerSelection;

    /* Enable ADC */
    SetBit(ADCSRA_Reg, Adc_ADEN);
}

uint16_t ADC_ReadChannelPolling(uint8_t Channel, uint32_t Timeout)
{
    uint16_t Local_AdcData;
    uint32_t Local_TimeoutCounter = 0;

    /* Validate Channel and Timeout */
    if(Channel > Adc_SingleEndedChannel7)
    {
        return ADC_ERROR;
    }

    if(Timeout == 0)
    {
        return ADC_TIMEOUT;
    }

    /* Select Channel */
    ADMUX_Reg = (ADMUX_Reg & ~Adc_ChannelMask) | (Channel & Adc_ChannelMask);

    /* Clear ADC Interrupt Flag before starting a new conversion */
    ClearFlag(ADCSRA_Reg, Adc_ADIF);

    /* Start Conversion */
    SetBit(ADCSRA_Reg, Adc_ADSC);

    /* Wait for Conversion Complete with Timeout */
    while(ReadFlag(ADCSRA_Reg, Adc_ADIF) != FlagUp)
    {
        Local_TimeoutCounter++;

        if(Local_TimeoutCounter >= Timeout)
        {
            return ADC_TIMEOUT;
        }
    }

    /* Read ADC Result */
    Local_AdcData = ADCData_Reg;

    /* Clear Flag */
    ClearFlag(ADCSRA_Reg, Adc_ADIF);

    return Local_AdcData;
}

void ADC_StartConversionInterrupt(uint8_t Channel)
{
    /* Select Channel */
    ADMUX_Reg = (ADMUX_Reg & ~Adc_ChannelMask) | (Channel & Adc_ChannelMask);

    /* Start Conversion */
    SetBit(ADCSRA_Reg, Adc_ADSC);
}

void ADC_SetCallBack(void (*Copy_pvCallBack)(uint16_t))
{
    if(Copy_pvCallBack != Null)
    {
        ADC_CallBack = Copy_pvCallBack;
    }
}

void __vector_14(void) __attribute__((signal));

void __vector_14(void)
{
    uint16_t Local_AdcData;
    Local_AdcData = ADCData_Reg;
    if(ADC_CallBack != Null)
    {
        ADC_CallBack(Local_AdcData);
    }
}
