/**
 * @file SPI_Private.h
 * @brief SPI Private private definitions and internal types.
 * @details Contains module-internal constants, register bit definitions, and private types or declarations.
 * @version 1.0.0
 * @author Yousef
 * @date 2026-09-12
 * @copyright Copyright (c) 2026, Embedded Systems Project
 */

#ifndef _SPI_PRIVATE_H
#define _SPI_PRIVATE_H
#include <stdint.h>

/**
 * @defgroup SPI_PRIVATE_H_GROUP SPI Private definitions
 * @brief Related spi private definitions.
 * @{
 */
/**
 * @def SPI_SPIE
 * @brief Module constant used by SPI.
 */
#define SPI_SPIE      7
/**
 * @def SPI_SPE
 * @brief Module constant used by SPI.
 */
#define SPI_SPE       6
/**
 * @def SPI_DORD
 * @brief Module constant used by SPI.
 */
#define SPI_DORD      5
/**
 * @def SPI_MSTR
 * @brief Module constant used by SPI.
 */
#define SPI_MSTR      4
/**
 * @def SPI_CPOL
 * @brief Module constant used by SPI.
 */
#define SPI_CPOL      3
/**
 * @def SPI_CPHA
 * @brief Module constant used by SPI.
 */
#define SPI_CPHA      2
/**
 * @def SPI_SPR1
 * @brief Module constant used by SPI.
 */
#define SPI_SPR1      1
/**
 * @def SPI_SPR0
 * @brief Module constant used by SPI.
 */
#define SPI_SPR0      0

/**
 * @def SPI_SPIF
 * @brief Module constant used by SPI.
 */
#define SPI_SPIF      7
/**
 * @def SPI_WCOL
 * @brief Module constant used by SPI.
 */
#define SPI_WCOL      6
/**
 * @def SPI_SPI2X
 * @brief Module constant used by SPI.
 */
#define SPI_SPI2X     0


/**
 * @def SPI_MSB
 * @brief Module constant used by SPI.
 */
#define SPI_MSB       7
/**
 * @def SPI_LSB
 * @brief Module constant used by SPI.
 */
#define SPI_LSB       0


/**
 * @def SPI_Prescaller4_NormalSpeed
 * @brief SPI/Timer clock prescaler selection: SPI_Prescaller4_NormalSpeed.
 */
#define SPI_Prescaller4_NormalSpeed        0
/**
 * @def SPI_Prescaller16_NormalSpeed
 * @brief SPI/Timer clock prescaler selection: SPI_Prescaller16_NormalSpeed.
 */
#define SPI_Prescaller16_NormalSpeed       1
/**
 * @def SPI_Prescaller64_NormalSpeed
 * @brief SPI/Timer clock prescaler selection: SPI_Prescaller64_NormalSpeed.
 */
#define SPI_Prescaller64_NormalSpeed       2
/**
 * @def SPI_Prescaller128_NormalSpeed
 * @brief SPI/Timer clock prescaler selection: SPI_Prescaller128_NormalSpeed.
 */
#define SPI_Prescaller128_NormalSpeed      3

/**
 * @def SPI_Prescaller2_DoubleSpeed
 * @brief SPI/Timer clock prescaler selection: SPI_Prescaller2_DoubleSpeed.
 */
#define SPI_Prescaller2_DoubleSpeed        4
/**
 * @def SPI_Prescaller8_DoubleSpeed
 * @brief SPI/Timer clock prescaler selection: SPI_Prescaller8_DoubleSpeed.
 */
#define SPI_Prescaller8_DoubleSpeed        5
/**
 * @def SPI_Prescaller32_DoubleSpeed
 * @brief SPI/Timer clock prescaler selection: SPI_Prescaller32_DoubleSpeed.
 */
#define SPI_Prescaller32_DoubleSpeed       6
/**
 * @def SPI_Prescaller64_DoubleSpeed
 * @brief SPI/Timer clock prescaler selection: SPI_Prescaller64_DoubleSpeed.
 */
#define SPI_Prescaller64_DoubleSpeed       7

/**
 * @def LSB_First
 * @brief Definition for LSB_First.
 */
#define LSB_First 0
/**
 * @def MSB_First
 * @brief Definition for MSB_First.
 */
#define MSB_First 1

/**
 * @def Master_mode
 * @brief SPI Master mode selection.
 */
#define Master_mode 1
/**
 * @def Slave_mode
 * @brief SPI Slave mode selection.
 */
#define Slave_mode  0

/**
 * @def SPI_CPOL_LOW
 * @brief Module constant used by SPI.
 */
#define SPI_CPOL_LOW  0
/**
 * @def SPI_CPOL_HIGH
 * @brief Module constant used by SPI.
 */
#define SPI_CPOL_HIGH 1

/**
 * @def SPI_SAMPLE_LEADING
 * @brief Module constant used by SPI.
 */
#define SPI_SAMPLE_LEADING  0
/**
 * @def SPI_SAMPLE_TRAILING
 * @brief Module constant used by SPI.
 */
#define SPI_SAMPLE_TRAILING 1

/**
 * @fn __vector_12
 * @brief Handles the interrupt service routine for __vector_12.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param signal Input parameter.
 * @param CopyFunc Callback function invoked by the module.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void __vector_12(void) __attribute__((signal,used));

/**
 * @struct SPI_Config_t
 * @brief Configuration structure for the module.
 */
typedef struct
{

    /**
     * @var SPI_Config_t::ModeSelect
     * @brief Configuration member ModeSelect.
     */
    uint8_t ModeSelect ;
    /**
     * @var SPI_Config_t::DataOrder
     * @brief Configuration member DataOrder.
     */
    uint8_t DataOrder ;
    /**
     * @var SPI_Config_t::ClockPolarity
     * @brief Configuration member ClockPolarity.
     */
    uint8_t ClockPolarity ;
    /**
     * @var SPI_Config_t::ClockPhase
     * @brief Configuration member ClockPhase.
     */
    uint8_t ClockPhase ;
    /**
     * @var SPI_Config_t::ClockRate
     * @brief Configuration member ClockRate.
     */
    uint8_t ClockRate ;


} SPI_Config_t;

/** @} */

#endif
