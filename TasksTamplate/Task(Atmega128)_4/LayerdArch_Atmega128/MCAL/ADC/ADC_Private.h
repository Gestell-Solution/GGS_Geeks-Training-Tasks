/**
 * @file      ADC_Private.h
 * @author    Abdulrahman Ali 
 * @author    ENG/Hesham Ahmed (Reviewer)
 * @brief     Private of the ADC (Analog-to-Digital Converter) Driver.
 * @details   This file contains the definitions of ADC register ,Prescaler ,channels and voltage REF
 * @version   1.0.0
 * @date      26 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */




#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

// ADMUX Register 
#define REFS1       7       // Reference Selection Bit 1 
#define REFS0       6       // Reference Selection Bit 0 
#define ADLAR       5       // ADC Left Adjust Result (0 = Right, 1 = Left) 
#define MUX4        4       // Analog Channel Selection Bit 4 
#define MUX3        3       // Analog Channel Selection Bit 3 
#define MUX2        2       // Analog Channel Selection Bit 2 
#define MUNCH_1     1       // Analog Channel Selection Bit 1 
#define MUX0        0       // Analog Channel Selection Bit 0 


// ADCSRA Register 
#define ADEN        7       // ADC Enable 
#define ADSC        6       // ADC Start Conversion 
#define ADFR        5       // ADC Free Running Select 
#define ADIF        4       // ADC Interrupt Flag 
#define ADIE        3       // ADC Interrupt Enable 
#define ADPS2       2       // ADC Prescaler Select Bit 2 
#define ADPS1       1       // ADC Prescaler Select Bit 1 
#define ADPS0       0       // ADC Prescaler Select Bit 0 


//Voltage Reference 
#define ADC_AREF       0       //AREF, Internal Vref turned off 
#define ADC_AVCC       1       // AVCC with external capacitor at AREF pin 
#define ADC_Internal   3       // Internal 2.56V Voltage Reference 


//ADC Prescalers
#define ADC_PRESCALER_2     1
#define ADC_PRESCALER_4     2
#define ADC_PRESCALER_8     3
#define ADC_PRESCALER_16    4
#define ADC_PRESCALER_32    5
#define ADC_PRESCALER_64    6
#define ADC_PRESCALER_128   7



//ADC Channels
#define ADC_CHANNEL0    0
#define ADC_CHANNEL1    1
#define ADC_CHANNEL2    2
#define ADC_CHANNEL3    3
#define ADC_CHANNEL4    4
#define ADC_CHANNEL5    5
#define ADC_CHANNEL6    6
#define ADC_CHANNEL7    7

// ADC Direction
#define ADC_RIGHT_ADJUST  0
#define ADC_LEFT_ADJUST   1


#define ADC_SINGLE_CONVERSION  0
#define ADC_FREE_RUNNING       1


#define ADC_Maskchannel   0x1F        // 0 0 0 1 1 1 1 1
#define ADC_Maskprescaler 0x07        // 0 0 0 0 0 1 1 1
#define ADC_ADTSMask      0xE0        // 1 1 1 0 0 0 0 0

#endif /* ADC_PRIVATE_H */