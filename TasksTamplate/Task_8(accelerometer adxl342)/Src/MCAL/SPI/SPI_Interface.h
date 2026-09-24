/**
 * @file SPI_Interface.h
 * @brief SPI public interface.
 * @details Declares the types and APIs of the ATmega32 SPI driver
 *          (master or slave, polling or interrupt driven).
 * @version 1.1.0
 * @author Yousef Mohamed
 * @date 2026-09-24
 * @copyright Copyright (c) 2026, Gestell Company. All rights reserved.
 */

#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#include <stdint.h>

#include "../../COMMON/Definition.h"
#include "../../COMMON/Bitmath.h"
#include "../Atmega32regmap.h"

#include "SPI_Private.h"
#include "SPI_Config.h"


typedef void (*SPI_Callback_t)(void);

typedef struct
{
    uint8_t ModeSelect;     /**< ::Master_mode or ::Slave_mode. */
    uint8_t DataOrder;      /**< ::LSB_First or ::MSB_First. */
    uint8_t ClockPolarity;  /**< ::SPI_CPOL_LOW or ::SPI_CPOL_HIGH. */
    uint8_t ClockPhase;     /**< ::SPI_SAMPLE_LEADING or ::SPI_SAMPLE_TRAILING. */
    uint8_t ClockRate;      /**< One of @ref SPI_CLOCK_RATE (used in master mode). */
} SPI_Config_t;

void SPI_Init(SPI_Config_t SPI_Config);

void SPI_SendData(uint8_t Data);

uint8_t SPI_Transfer(uint8_t Data);

void SPI_SetCallBack(SPI_Callback_t CopyFunc);

void SPI_EnableInterrupt(void);

void SPI_DisableInterrupt(void);

#endif 
