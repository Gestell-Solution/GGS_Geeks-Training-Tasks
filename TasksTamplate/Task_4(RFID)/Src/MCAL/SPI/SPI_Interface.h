/**
 * @file SPI_Interface.h
 * @brief SPI Interface public interface.
 * @details Declares the public APIs exposed by the module.
 * @version 1.0.0
 * @author Yousef
 * @date 2026-09-12
 * @copyright Copyright (c) 2026, Embedded Systems Project
 */

#ifndef _SPI_INTERFACE_H
#define _SPI_INTERFACE_H

#include <stdint.h>

#include "../../COMMON/Definition.h"
#include "../../COMMON/Bitmath.h"
#include "../Atmega32regmap.h"

#include "SPI_Private.h"
#include "SPI_Config.h"


/**
 * @defgroup SPI_INTERFACE_H_GROUP SPI Interface definitions
 * @brief Related spi interface definitions.
 * @{
 */
/**
 * @fn SPI_Init
 * @brief Initializes the SPI peripheral.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param SPI_Config Module configuration structure.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void SPI_Init(SPI_Config_t SPI_Config);

/**
 * @fn SPI_SendData
 * @brief Sends one byte through SPI and waits for transfer completion.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param Data Data value or data buffer used by the operation.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void SPI_SendData(uint8_t Data);


/**
 * @fn SPI_SetCallBack
 * @brief Registers the SPI interrupt callback function.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param CopyFunc Callback function invoked by the module.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void SPI_SetCallBack(void (*CopyFunc)(void));

/**
 * @fn SPI_EnableInterrupt
 * @brief Enables the SPI interrupt.
 * @details Performs the operation required by the module while preserving the module interface.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void SPI_EnableInterrupt(void);

/**
 * @fn SPI_DisableInterrupt
 * @brief Disables the SPI interrupt.
 * @details Performs the operation required by the module while preserving the module interface.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void SPI_DisableInterrupt(void);

/**
 * @fn SPI_Transfer
 * @brief Transfers one byte through SPI and returns the received byte.
 * @details Loads the transmit byte into SPDR, waits for SPIF, then returns the received byte.
 * @param Data Data value or data buffer used by the operation.
 * @return uint8_t Return value of the operation.
 * @retval 0 Operation completed successfully when a status code is used.
 * @retval Non-zero Module-specific error or status code when applicable.
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
uint8_t SPI_Transfer(uint8_t Data);





/** @} */

#endif
