/**
 * @file ADC_Private.h
 * @brief Private definitions for ADC Peripheral driver
 * @details This file contains the internal definitions required by ADC Peripheral driver implementation.
 * @version 0.1
 * @author Malak Mohammed (malak.mohammed.esmail@gmail.com) 
 * @date 21-09-2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef ADC_PRIVATE_H 
#define ADC_PRIVATE_H 

#include <stdint.h>

/** @brief ADC Reference Selection Bit 0 */
#define Adc_REFS0    6  
/** @brief ADC Reference Selection Bit 1 */
#define Adc_REFS1    7 

/** @brief selects AREF Pin as the ADC Reference */
#define Adc_AREF          0
/** @brief selects AVCC Pin as the ADC Reference */
#define Adc_AVCC          1
/** @brief selects the internal voltage reference as the ADC Reference */
#define Adc_Internal      2

/** @brief ADC Result Adjust Direction Selection Bit */
#define Adc_ADLAR         5 

/** @brief Adjusts the result of conversion to right */
#define Adc_RightAdjust   0 
/** @brief Adjusts the result of conversion to left */
#define Adc_LeftAdjust    1 

/** @brief ADC Enable Bit */
#define Adc_ADEN  7

/** @brief ADC Start Conversion Bit */
#define Adc_ADSC  6 

/** @brief ADC Auto Trigger Enable Bit */
#define Adc_ADATE 5

/** @brief ADC Interrupt Flag Bit  */
#define Adc_ADIF  4

/** @brief ADC Interrupt Enable Bit */
#define Adc_ADIE  3

/** @brief ADC Prescaler Select Bit 0 */
#define Adc_ADPS0     0
/** @brief ADC Prescaler Select Bit 1 */
#define Adc_ADPS1     1
/** @brief ADC Prescaler Select Bit 2 */
#define Adc_ADPS2     2

/** 
 * @defgroup ADC_Prescaler_Selection ADC Prescaler Selection 
 * @brief Selects an ADC Clock prescaler
 * @{ */
#define Adc_Prescaler_2      1
#define Adc_Prescaler_4      2
#define Adc_Prescaler_8      3
#define Adc_Prescaler_16     4
#define Adc_Prescaler_32     5
#define Adc_Prescaler_64     6
#define Adc_Prescaler_128    7
/** @} */

/** @brief ADC Auto Trigger Source Selection Bit 0  */
#define Adc_ADTS0    5
/** @brief ADC Auto Trigger Source Selection Bit 1  */
#define Adc_ADTS1    6
/** @brief ADC Auto Trigger Source Selection Bit 2  */
#define Adc_ADTS2    7

/** @brief Selects single conversion mode */
#define SingleMode 1
/** @brief Selects automatic conversion mode */
#define AutoMode 0

/** @brief Mask for selecting a single-ended channel (0:7)  */
#define Adc_ChannelMask   0x1F

/** @brief Mask for selecting a clock prescaler */
#define Adc_PrescalerMask    0x07

/** @brief Mask for selecting a trigger source */
#define Adc_TriggerMask          0xE0

/** @defgroup ADC_Channel_Selection ADC Channel Selection
 * @brief Selects which single-ended channel to convert
 * @{
 */
#define Adc_SingleEndedChannel0       0 
#define Adc_SingleEndedChannel1       1
#define Adc_SingleEndedChannel2       2
#define Adc_SingleEndedChannel3       3
#define Adc_SingleEndedChannel4       4
#define Adc_SingleEndedChannel5       5
#define Adc_SingleEndedChannel6       6
#define Adc_SingleEndedChannel7       7
/** @} */

/** @struct Adc_Config_t
 * @brief Configuration for ADC Initialization 
 */
typedef struct 
{
/** @var Adc_Config_t::ReferenceSelection 
 * @brief 
 */
uint8_t ReferenceSelection ;

/** @var Adc_Config_t::AdjustResult
 * @brief Selects Left or right to adjust Conversion result
 */
uint8_t AdjustResult ;

/** @var Adc_Config_t::ConversionMode
 * @brief Selects Single or automatic conversion mode 
 */
uint8_t ConversionMode;

/** @var Adc_Config_t::InterruptState
 * @brief Selests whether to enable or disable an interrupt
 */
uint8_t InterruptState;

/** @var Adc_Config_t::TriggerSource
 * @brief Selects an auto triggersource
 */
uint8_t TriggerSource;

/** @var Adc_Config_t::PrescalerSelection
 * @brief Selects a clock prescaler value
 */
uint8_t PrescalerSelection;
} Adc_Config_t;



#endif