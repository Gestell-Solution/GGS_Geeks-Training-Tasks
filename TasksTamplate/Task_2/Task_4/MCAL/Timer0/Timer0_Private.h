/**
 * @file Timer0_Private.h
 * @brief Timer0 Private private definitions and internal types.
 * @details Contains module-internal constants, register bit definitions, and private types or declarations.
 * @version 1.0.0
 * @author Yousef
 * @date 2026-09-12
 * @copyright Copyright (c) 2026, Embedded Systems Project
 */

#ifndef _TIMER0_PRIVATE_H
#define _TIMER0_PRIVATE_H


/**
 * @defgroup TIMER0_PRIVATE_H_GROUP Timer0 Private definitions
 * @brief Related timer0 private definitions.
 * @{
 */
/**
 * @def Timer0_FOC0
 * @brief Module constant used by TIMER0.
 */
#define Timer0_FOC0     7
/**
 * @def Timer0_WGM00
 * @brief Module constant used by TIMER0.
 */
#define Timer0_WGM00    6
/**
 * @def Timer0_WGM01
 * @brief Module constant used by TIMER0.
 */
#define Timer0_WGM01    3

/**
 * @def Timer0_COM01
 * @brief Module constant used by TIMER0.
 */
#define Timer0_COM01    5
/**
 * @def Timer0_COM00
 * @brief Module constant used by TIMER0.
 */
#define Timer0_COM00    4


/**
 * @def Timer0_CS02
 * @brief Module constant used by TIMER0.
 */
#define Timer0_CS02     2
/**
 * @def Timer0_CS01
 * @brief Module constant used by TIMER0.
 */
#define Timer0_CS01     1
/**
 * @def Timer0_CS00
 * @brief Module constant used by TIMER0.
 */
#define Timer0_CS00     0


/**
 * @def Timer0_NormalMode
 * @brief Module constant used by TIMER0.
 */
#define Timer0_NormalMode           0
/**
 * @def Timer0_CTCMode
 * @brief Module constant used by TIMER0.
 */
#define Timer0_CTCMode              1
/**
 * @def Timer0_FastPWM
 * @brief Module constant used by TIMER0.
 */
#define Timer0_FastPWM              2
/**
 * @def Timer0_PhaseCorrectPWM
 * @brief Module constant used by TIMER0.
 */
#define Timer0_PhaseCorrectPWM      3

/**
 * @def Timer0_OC0DisConnect
 * @brief Module constant used by TIMER0.
 */
#define Timer0_OC0DisConnect  0
/**
 * @def Timer0_OC0Toggle
 * @brief Module constant used by TIMER0.
 */
#define Timer0_OC0Toggle      1
/**
 * @def Timer0_OC0Clear
 * @brief Module constant used by TIMER0.
 */
#define Timer0_OC0Clear       2
/**
 * @def Timer0_OC0Set
 * @brief Module constant used by TIMER0.
 */
#define Timer0_OC0Set         3

/**
 * @def Timer0_OC0NinInverting
 * @brief Module constant used by TIMER0.
 */
#define Timer0_OC0NinInverting   4
/**
 * @def Timer0_OC0Inverting
 * @brief Module constant used by TIMER0.
 */
#define Timer0_OC0Inverting      5


// Reg = (Reg&~Mask)|PrescallerValue

/**
 * @def Timer0_Disable
 * @brief Module constant used by TIMER0.
 */
#define Timer0_Disable            0
/**
 * @def Timer0_Prescaller1
 * @brief SPI/Timer clock prescaler selection: Timer0_Prescaller1.
 */
#define Timer0_Prescaller1        1
/**
 * @def Timer0_Prescaller8
 * @brief SPI/Timer clock prescaler selection: Timer0_Prescaller8.
 */
#define Timer0_Prescaller8        2
/**
 * @def Timer0_Prescaller64
 * @brief SPI/Timer clock prescaler selection: Timer0_Prescaller64.
 */
#define Timer0_Prescaller64       3
/**
 * @def Timer0_Prescaller256
 * @brief SPI/Timer clock prescaler selection: Timer0_Prescaller256.
 */
#define Timer0_Prescaller256      4
/**
 * @def Timer0_Prescaller1024
 * @brief SPI/Timer clock prescaler selection: Timer0_Prescaller1024.
 */
#define Timer0_Prescaller1024     5

/**
 * @def Timer0_ExternalFalling
 * @brief Module constant used by TIMER0.
 */
#define Timer0_ExternalFalling      6
/**
 * @def Timer0_ExternalRising
 * @brief Module constant used by TIMER0.
 */
#define Timer0_ExternalRising       7

/**
 * @def ClockSelectMask
 * @brief Bit mask used for ClockSelectMask.
 */
#define ClockSelectMask 0x07


/**
 * @def Timer0_OCIE0
 * @brief Module constant used by TIMER0.
 */
#define Timer0_OCIE0     1
/**
 * @def Timer0_TOIE0
 * @brief Module constant used by TIMER0.
 */
#define Timer0_TOIE0     0




/**
 * @def Timer0_OverFlowInterrupt
 * @brief Module constant used by TIMER0.
 */
#define Timer0_OverFlowInterrupt     0
/**
 * @def Timer0_CompareMatchInterrupt
 * @brief Module constant used by TIMER0.
 */
#define Timer0_CompareMatchInterrupt 1


// //Compare Match
// void __vector_10(void)   __attribute__((signal));
// //OverFlow
// void __vector_11(void)   __attribute__((signal));


/**
 * @struct Timer0_Config_t
 * @brief Configuration structure for the module.
 */
typedef struct
{

    /**
     * @var Timer0_Config_t::TimerMode
     * @brief Configuration member TimerMode.
     */
    uint8_t TimerMode ;
    /**
     * @var Timer0_Config_t::PreloadValue
     * @brief Configuration member PreloadValue.
     */
    uint8_t PreloadValue;
    /**
     * @var Timer0_Config_t::CompareMatchValue
     * @brief Configuration member CompareMatchValue.
     */
    uint8_t CompareMatchValue;
    /**
     * @var Timer0_Config_t::PWMOutputMode
     * @brief Configuration member PWMOutputMode.
     */
    uint8_t PWMOutputMode;
    /**
     * @var Timer0_Config_t::DutyCycleInitValue
     * @brief Configuration member DutyCycleInitValue.
     */
    uint8_t DutyCycleInitValue;
} Timer0_Config_t;



/**
 * @def Timer0_MaxPWM
 * @brief Module constant used by TIMER0.
 */
#define Timer0_MaxPWM         255UL
/**
 * @def Timer0_MaxDutyCycle
 * @brief Module constant used by TIMER0.
 */
#define Timer0_MaxDutyCycle   100

/** @} */

#endif
