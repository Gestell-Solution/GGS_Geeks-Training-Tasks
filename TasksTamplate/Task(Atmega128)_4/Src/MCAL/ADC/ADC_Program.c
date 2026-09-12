/**
 * @file      ADC_Program.c
 * @author    Abdulrahman Ali 
 * @author    ENG/Hesham Ahmed (Reviewer)
 * @brief     Program of the ADC (Analog-to-Digital Converter) Driver.
 * @details   This file contains the function of ADC Driver
 * @version   1.0.0
 * @date      26 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#include "ADC_Interface.h"


void ADC_Init(uint8_t Voltage_Mode) 
{
    switch(Voltage_Mode)
    {
    case ADC_AREF:  // External referen volt --> 5V
    CLEAR_BIT(ADMUX, REFS0);
    CLEAR_BIT(ADMUX, REFS1);
    break;

    case ADC_AVCC:  // AVCC from MC
    SET_BIT(ADMUX, REFS0);
    CLEAR_BIT(ADMUX, REFS1);
    break;

    case ADC_Internal:  // Internal referen volt --> 2.56V
    SET_BIT(ADMUX, REFS0);
    SET_BIT(ADMUX, REFS1);
    break;

    default:
    break;
    }
    ADC_Prescaler(ADC_PRESCALER_64 ); 
    SET_BIT(ADCSRA, ADEN);
}

void ADC_Enable()
{
    SET_BIT(ADCSRA,ADEN);
}

void ADC_Disable()
{
    CLEAR_BIT(ADCSRA,ADEN);
}

void ADC_Adjust(uint8_t Adjust_Direction)
{
    if(Adjust_Direction== ADC_RIGHT_ADJUST)
    {
        CLEAR_BIT(ADMUX, ADLAR);
    }
    else if(Adjust_Direction== ADC_LEFT_ADJUST)
    {
        SET_BIT(ADMUX, ADLAR);
    }
}

void ADC_Channel(uint8_t Channel)
{
    ADMUX = (ADMUX & ~ADC_Maskchannel) | Channel;
    /*
       Maskchannel=0x1F after ~ Maskchannel will= 0xE0
       then i will and it with ADMUX to delete MUX4:0 Bits
       then or with channel to write its value
    */
}

void ADC_StartConversion(uint8_t Mode)
{
    if(Mode==ADC_SINGLE_CONVERSION)
    {
        SET_BIT(ADCSRA,ADSC);
    }
}


void ADC_Prescaler(uint8_t Prescaler)
{
    ADCSRA=(ADCSRA&~ADC_Maskprescaler)|Prescaler;
    /*
       Maskprescaler=0x07 after ~ Maskprescaler will= 0xF8
       then i will and it with ADCSRA to delete  ADPS2:0 Bits
       then or with Prescaler to write its value
    */
}

uint16_t ADC_ReadResult()
{ 
    SET_BIT(ADCSRA, ADSC); //Start Conversion
    while(ReadBit(ADCSRA, ADIF) == 0); //Check Flag
    SET_BIT(ADCSRA, ADIF);   //Clear Flag

     uint16_t Data = 0;
     Data = ADCL;   //right adjust
     Data |= ((uint16_t)ADCH << 8);
     return Data;
}

uint16_t ADC_ReadResult_Polling(uint8_t Channel){
   uint16_t Data = 0;

    ADMUX = (ADMUX & ~ADC_Maskchannel) | Channel; // Select ADC Channel

    SET_BIT(ADCSRA, ADSC); // Start ADC Conversion
    
    while (READ_BIT(ADCSRA,ADSC)==1); // Waiting until the conversion is completed

    SET_BIT(ADCSRA, ADIF);// Clear Flag

    Data = ADCL;  // Read the ReadResult

    Data |= ((uint16_t)ADCH << 8); // ADCH+ADCL to get the complete 10BITS 

    return Data;                 

}