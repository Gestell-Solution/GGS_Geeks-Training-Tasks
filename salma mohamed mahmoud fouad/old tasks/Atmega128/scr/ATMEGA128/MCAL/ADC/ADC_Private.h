#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#include"ADC_Interface.h"

//ADMUX_REG
#define ADC_REFS1 7
#define ADC_REFS0 6
//VOLTAGE SELCET
 #define ADC_AREF     0
 #define ADC_AVCC     1 
 #define ADC_INTERNAL 3 
#define ADC_ADLAR 5
#define ADC_MUX4  4
#define ADC_MUX3  3
#define ADC_MUX2  2
#define ADC_MUX1  1
#define ADC_MUX0  0
//INPUT CHANNEL AND GAIN 
 #define ADC_SINGLE_ENDED_ADC0 0
 #define ADC_SINGLE_ENDED_ADC1 1
 #define ADC_SINGLE_ENDED_ADC2 2
 #define ADC_SINGLE_ENDED_ADC3 3
 #define ADC_SINGLE_ENDED_ADC4 4
 #define ADC_SINGLE_ENDED_ADC5 5
 #define ADC_SINGLE_ENDED_ADC6 6
 #define ADC_SINGLE_ENDED_ADC7 7
//ADCSRA_REG
#define ADC_ADEN  7//by giving it 1 the adc is enabled 
#define ADC_ADSC  6
#define ADC_ADFR  5
 #define ADC_FREErunningMode 1
#define ADC_ADIF  4
#define ADC_ADIE  3
 #define Enable_interrupt 1
#define ADC_ADPS2 2
#define ADC_ADPS1 1
#define ADC_ADPS0 0
 #define ADC_Prescaler_2   0
 #define ADC_Prescaler_2   1
 #define ADC_Prescaler_4   2
 #define ADC_Prescaler_8   3
 #define ADC_Prescaler_16  4
 #define ADC_Prescaler_32  5
 #define ADC_Prescaler_64  6
 #define ADC_Prescaler_128 7

#define ADC_Channel_mask   0x1F
#define ADC_prescaler_mask 0x07

//adlar
#define ADC_leftAdjust   1
#define ADC_rightAdjust  0

typedef struct 
{
    uint8_t Reference_Selection;
    uint8_t Adjust;
    uint8_t free_running_mode_enable;
    uint8_t interrupt_enable;
    uint8_t prescaler_selection;
}ADC_Config_t;


#endif