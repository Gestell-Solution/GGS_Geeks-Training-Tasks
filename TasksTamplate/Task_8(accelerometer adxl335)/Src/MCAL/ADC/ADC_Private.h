/**
 * @file ADC_Private.h
 * @brief ADC Private private definitions and internal types.
 * @details Contains module-internal constants, register bit definitions, and private types or declarations.
 * @version 1.0.0
 * @author Yousef
 * @date 2026-09-24
 * @copyright Copyright (c) 2026, Gestell Company. All rights reserved.
 */

#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

/* ADMUX Bits */
#define Adc_REFS0         6
#define Adc_REFS1         7
#define Adc_ADLAR         5
#define Adc_ADEN          7
#define Adc_ADSC          6
#define Adc_ADATE         5
#define Adc_ADIF          4
#define Adc_ADIE          3
#define Adc_ADPS0         0
#define Adc_ADPS1         1
#define Adc_ADPS2         2


/* SFIOR Bits */
#define Adc_ADTS0         5
#define Adc_ADTS1         6
#define Adc_ADTS2         7


#define Adc_AREF          0
#define Adc_AVCC          1
#define Adc_Internal      2

/* Result Adjustment */
#define Adc_RightAdjust   0
#define Adc_LeftAdjust    1

/* Conversion Mode */
#define SingleMode        1
#define AutoMode          0

/* ADC Prescaler */
#define Adc_Prescaler_2       1
#define Adc_Prescaler_4       2
#define Adc_Prescaler_8       3
#define Adc_Prescaler_16      4
#define Adc_Prescaler_32      5
#define Adc_Prescaler_64      6
#define Adc_Prescaler_128     7

/* Masks */
#define Adc_ChannelMask        0x07
#define Adc_PrescalerMask      0x07
#define Adc_ADTSMask           0xE0


/* ADC Return Values */
#define ADC_TIMEOUT   0xFFFF
#define ADC_ERROR     0xFFFE

/* Single Ended ADC Channels */
#define Adc_SingleEndedChannel0    0
#define Adc_SingleEndedChannel1    1
#define Adc_SingleEndedChannel2    2
#define Adc_SingleEndedChannel3    3
#define Adc_SingleEndedChannel4    4
#define Adc_SingleEndedChannel5    5
#define Adc_SingleEndedChannel6    6
#define Adc_SingleEndedChannel7    7


/* Auto Trigger Sources */

#define Adc_FreeRunning                0
#define Adc_AnalogComparator           1
#define Adc_EXTI0                      2
#define Adc_Timer0CompareMatch         3
#define Adc_Timer0Overflow             4
#define Adc_Timer1CompareMatchB        5
#define Adc_Timer1Overflow             6
#define Adc_Timer1CaptureEvent         7

typedef struct
{

    uint8_t ReferenceSelection;
    uint8_t AdjustResult;
    uint8_t AutomaticMode;
    uint8_t TriggerSource;
    uint8_t InterruptState;
    uint8_t PrescallerSelection;

} Adc_Config_t;

#endif
