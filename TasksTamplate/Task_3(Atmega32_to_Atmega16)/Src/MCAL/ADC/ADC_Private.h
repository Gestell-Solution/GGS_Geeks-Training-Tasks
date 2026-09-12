/**
 * @file ADC_Private.h
 * @brief ADC Private private definitions and internal types.
 * @details Contains module-internal constants, register bit definitions, and private types or declarations.
 * @version 1.0.0
 * @author Yousef
 * @date 2026-09-12
 * @copyright Copyright (c) 2026, Embedded Systems Project
 */

#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

/* ADMUX Bits */
/**
 * @def Adc_REFS0
 * @brief Module constant used by ADC.
 */
#define Adc_REFS0         6
/**
 * @defgroup ADC_PRIVATE_H_GROUP ADC Private definitions
 * @brief Related adc private definitions.
 * @{
 */
/**
 * @def Adc_REFS1
 * @brief Module constant used by ADC.
 */
#define Adc_REFS1         7

/**
 * @def Adc_ADLAR
 * @brief Module constant used by ADC.
 */
#define Adc_ADLAR         5

/* ADCSRA Bits */
/**
 * @def Adc_ADEN
 * @brief Module constant used by ADC.
 */
#define Adc_ADEN          7
/**
 * @def Adc_ADSC
 * @brief Module constant used by ADC.
 */
#define Adc_ADSC          6
/**
 * @def Adc_ADATE
 * @brief Module constant used by ADC.
 */
#define Adc_ADATE         5
/**
 * @def Adc_ADIF
 * @brief Module constant used by ADC.
 */
#define Adc_ADIF          4
/**
 * @def Adc_ADIE
 * @brief Module constant used by ADC.
 */
#define Adc_ADIE          3

/**
 * @def Adc_ADPS0
 * @brief Module constant used by ADC.
 */
#define Adc_ADPS0         0
/**
 * @def Adc_ADPS1
 * @brief Module constant used by ADC.
 */
#define Adc_ADPS1         1
/**
 * @def Adc_ADPS2
 * @brief Module constant used by ADC.
 */
#define Adc_ADPS2         2


/* SFIOR Bits */
/**
 * @def Adc_ADTS0
 * @brief Module constant used by ADC.
 */
#define Adc_ADTS0         5
/**
 * @def Adc_ADTS1
 * @brief Module constant used by ADC.
 */
#define Adc_ADTS1         6
/**
 * @def Adc_ADTS2
 * @brief Module constant used by ADC.
 */
#define Adc_ADTS2         7

/* Voltage Reference */
/**
 * @def Adc_AREF
 * @brief Module constant used by ADC.
 */
#define Adc_AREF          0
/**
 * @def Adc_AVCC
 * @brief Module constant used by ADC.
 */
#define Adc_AVCC          1
/**
 * @def Adc_Internal
 * @brief Module constant used by ADC.
 */
#define Adc_Internal      2

/* Result Adjustment */
/**
 * @def Adc_RightAdjust
 * @brief Module constant used by ADC.
 */
#define Adc_RightAdjust   0
/**
 * @def Adc_LeftAdjust
 * @brief Module constant used by ADC.
 */
#define Adc_LeftAdjust    1

/* Conversion Mode */
/**
 * @def SingleMode
 * @brief Mode selection constant for SingleMode.
 */
#define SingleMode        1
/**
 * @def AutoMode
 * @brief Mode selection constant for AutoMode.
 */
#define AutoMode          0

/* ADC Prescaler */
/**
 * @def Adc_Prescaler_2
 * @brief SPI/Timer clock prescaler selection: Adc_Prescaler_2.
 */
#define Adc_Prescaler_2       1
/**
 * @def Adc_Prescaler_4
 * @brief SPI/Timer clock prescaler selection: Adc_Prescaler_4.
 */
#define Adc_Prescaler_4       2
/**
 * @def Adc_Prescaler_8
 * @brief SPI/Timer clock prescaler selection: Adc_Prescaler_8.
 */
#define Adc_Prescaler_8       3
/**
 * @def Adc_Prescaler_16
 * @brief SPI/Timer clock prescaler selection: Adc_Prescaler_16.
 */
#define Adc_Prescaler_16      4
/**
 * @def Adc_Prescaler_32
 * @brief SPI/Timer clock prescaler selection: Adc_Prescaler_32.
 */
#define Adc_Prescaler_32      5
/**
 * @def Adc_Prescaler_64
 * @brief SPI/Timer clock prescaler selection: Adc_Prescaler_64.
 */
#define Adc_Prescaler_64      6
/**
 * @def Adc_Prescaler_128
 * @brief SPI/Timer clock prescaler selection: Adc_Prescaler_128.
 */
#define Adc_Prescaler_128     7

/* Masks */
/**
 * @def Adc_ChannelMask
 * @brief Module constant used by ADC.
 */
#define Adc_ChannelMask        0x07
/**
 * @def Adc_PrescalerMask
 * @brief SPI/Timer clock prescaler selection: Adc_PrescalerMask.
 */
#define Adc_PrescalerMask      0x07
/**
 * @def Adc_ADTSMask
 * @brief Module constant used by ADC.
 */
#define Adc_ADTSMask           0xE0


/* ADC Return Values */
/**
 * @def ADC_TIMEOUT
 * @brief Module constant used by ADC.
 */
#define ADC_TIMEOUT   0xFFFF
/**
 * @def ADC_ERROR
 * @brief Module constant used by ADC.
 */
#define ADC_ERROR     0xFFFE

/* Single Ended ADC Channels */
/**
 * @def Adc_SingleEndedChannel0
 * @brief Module constant used by ADC.
 */
#define Adc_SingleEndedChannel0    0
/**
 * @def Adc_SingleEndedChannel1
 * @brief Module constant used by ADC.
 */
#define Adc_SingleEndedChannel1    1
/**
 * @def Adc_SingleEndedChannel2
 * @brief Module constant used by ADC.
 */
#define Adc_SingleEndedChannel2    2
/**
 * @def Adc_SingleEndedChannel3
 * @brief Module constant used by ADC.
 */
#define Adc_SingleEndedChannel3    3
/**
 * @def Adc_SingleEndedChannel4
 * @brief Module constant used by ADC.
 */
#define Adc_SingleEndedChannel4    4
/**
 * @def Adc_SingleEndedChannel5
 * @brief Module constant used by ADC.
 */
#define Adc_SingleEndedChannel5    5
/**
 * @def Adc_SingleEndedChannel6
 * @brief Module constant used by ADC.
 */
#define Adc_SingleEndedChannel6    6
/**
 * @def Adc_SingleEndedChannel7
 * @brief Module constant used by ADC.
 */
#define Adc_SingleEndedChannel7    7


/* Auto Trigger Sources */
/**
 * @def Adc_FreeRunning
 * @brief Module constant used by ADC.
 */
#define Adc_FreeRunning                0
/**
 * @def Adc_AnalogComparator
 * @brief Module constant used by ADC.
 */
#define Adc_AnalogComparator           1
/**
 * @def Adc_EXTI0
 * @brief Module constant used by ADC.
 */
#define Adc_EXTI0                      2
/**
 * @def Adc_Timer0CompareMatch
 * @brief Module constant used by ADC.
 */
#define Adc_Timer0CompareMatch         3
/**
 * @def Adc_Timer0Overflow
 * @brief Module constant used by ADC.
 */
#define Adc_Timer0Overflow             4
/**
 * @def Adc_Timer1CompareMatchB
 * @brief Module constant used by ADC.
 */
#define Adc_Timer1CompareMatchB        5
/**
 * @def Adc_Timer1Overflow
 * @brief Module constant used by ADC.
 */
#define Adc_Timer1Overflow             6
/**
 * @def Adc_Timer1CaptureEvent
 * @brief Module constant used by ADC.
 */
#define Adc_Timer1CaptureEvent         7

/**
 * @struct Adc_Config_t
 * @brief Configuration structure for the module.
 */
typedef struct
{

    /**
     * @var Adc_Config_t::ReferenceSelection
     * @brief Configuration member ReferenceSelection.
     */
    uint8_t ReferenceSelection;
    /**
     * @var Adc_Config_t::AdjustResult
     * @brief Configuration member AdjustResult.
     */
    uint8_t AdjustResult;
    /**
     * @var Adc_Config_t::AutomaticMode
     * @brief Configuration member AutomaticMode.
     */
    uint8_t AutomaticMode;
    /**
     * @var Adc_Config_t::TriggerSource
     * @brief Configuration member TriggerSource.
     */
    uint8_t TriggerSource;
    /**
     * @var Adc_Config_t::InterruptState
     * @brief Configuration member InterruptState.
     */
    uint8_t InterruptState;
    /**
     * @var Adc_Config_t::PrescallerSelection
     * @brief Configuration member PrescallerSelection.
     */
    uint8_t PrescallerSelection;

} Adc_Config_t;

/** @} */

#endif
