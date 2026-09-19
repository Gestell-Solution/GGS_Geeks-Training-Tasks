#include "ADC_interface.h"

void ADC_init(Adc_config_t config)
{
    //select the voltage refernce
    ADC_volt_reference(config.volt_reference);
    // adjust the direction
    ADC_adjust_direction(config.adjust_direction);
    // soruce selction
    ADC_source_selection(config.source);
    // prescaler 
    ADC_Prescaler(config.prescaler);
    // choose the channel
    ADC_channel(config.channel);
    // lastly enable the adc
    ADC_enable();
}

void ADC_volt_reference (Adc_voltage_reference_t reference)
{
    switch (reference)
    {
        case AREF : 
            ClearBit(ADMUX,Adc_REFS0 );
            ClearBit(ADMUX,Adc_REFS1 );
            break;
        case AVCC :
            SetBit(ADMUX,Adc_REFS0 );
            ClearBit(ADMUX,Adc_REFS1 );
            break;
        case INTERNAL :
            SetBit(ADMUX,Adc_REFS0 );
            SetBit(ADMUX,Adc_REFS1 );
            break;
        default: 
            break;  
    }
}

void ADC_enable()
{
    SetBit(ADCSRA ,Adc_ADEN );
}

void ADC_disable()
{
    ClearBit(ADCSRA ,Adc_ADEN );
}

u8 direction_of_adjust = 0 ;
void ADC_adjust_direction(Adc_adjust_t direction)
{
    switch (direction)
    {
        case Adc_left_adjust :
            SetBit(ADMUX,Adc_ADlAR);
            direction_of_adjust = Adc_left_adjust ;
            break;
        case Adc_right_adjust :
            ClearBit(ADMUX,Adc_ADlAR);
            direction_of_adjust = Adc_right_adjust ;
            break;  
        default :
            break;
    }
}

void ADC_start_conversion()
{
    SetBit(ADCSRA , Adc_ADSC) ;
}

void ADC_channel(Adc_channel_t channel)
{
    ADMUX = (ADMUX &~ Adc_mask_channel) | channel ; 
}

void ADC_Prescaler(Adc_prescaler_t Prescaler)
{
    ADCSRA = (ADCSRA &~ Adc_mask_prescaler) | Prescaler ;
}

void ADC_source_selection(Adc_interput_source_t source)
{
    SFIOR = (SFIOR &~ Adc_mask_interput_sources) | source ;
}

u16 ADC_read_result()
{
    u16 data = 0;
    u8 low_byte  = ADCL;
    u8 high_byte = ADCH;

    ADC_start_conversion();

    while (ReadBit(ADCSRA, Adc_ADIF) != FlagUp);

    SetBit(ADCSRA, Adc_ADIF);

    // if (direction_of_adjust == Adc_right_adjust)
    // {
    //     data = ADCL;
    //     data |= ((u16)ADCH << 8);
    // }
    // else
    // {
    //     lower = ADCL;   // must read ADCL first to unlatch ADCH
    //     higher = ADCH;
    //     data = ((u16)high << 8) | low;
    //     data >>= 6;      // shift result right to align the 10 bits in left-adjust format

    // }



    if (direction_of_adjust == Adc_right_adjust)
        data = ((u16)high_byte << 8) | low_byte;
    else
        data = (((u16)high_byte << 8) | low_byte) >> 6;


    return data;
}

// void ADC_is_busy()
// {
//     return ReadBit(ADCSRA, Adc_ADSC);
// }


void ADC_auto_trigger_enable()
{
    SetBit(ADCSRA, Adc_ADATE);
}
void ADC_auto_trigger_disable()
{
    ClearBit(ADCSRA, Adc_ADATE);
}
void ADC_interrupt_enable()
{
    SetBit(ADCSRA, Adc_ADIE);
}
void ADC_interrupt_disable()
{
    ClearBit(ADCSRA, Adc_ADIE);
}

