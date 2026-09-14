/**
 * @file UART_Private.h
 * @brief Private definitions for the UART driver
 * @details This file contains the internal definitions required by the UART driver implementation.
 * @version 0.1
 * @author Malak Mohammed (malak.mohammed.esmail@gmail.com) 
 * @date 14-09-2026
 * @copyright Copyright (c) 2026, Gestell Company
 */


#ifndef _UART_PRIVATE_H
#define _UART_PRIVATE_H
#include <stdint.h>

/**
 * @defgroup UART_Private_Definitions UART Private Definitions
 * @brief Private definitions of UART driver register bits. 
 * @{
 */

#define UART_RXC 7
#define UART_TXC 6
#define UART_UDRE 5
#define UART_FE 4
#define UART_DOR 3
#define UART_PE 2 
#define UART_U2X 1
#define UART_MPCM 0

#define UART_RXCIE 7
#define UART_TXCIE 6
#define UART_UDRIE 5
#define UART_RXEN 4
#define UART_TXEN 3
#define UART_UCSZ2 2
#define UART_RXB8 1
#define UART_TXB8 0

#define UART_URSEL 7
#define UART_UMSEL 6
#define UART_UPM1 5
#define UART_UPM0 4
#define UART_USBS 3
#define UART_USCZ1 2
#define UART_USCZ0 1
#define UART_UCPOL 0
/** @} */

/**
 * @defgroup UART_Private_Definitions UART Private Definitions
 * @brief Internal definitions of UART driver operating modes and register masks. 
 * @{
 */

#define UART_NormalSpeed 0
#define UART_DoubleSpeed 1

#define UART_SynchMode 1
#define UART_AsynchMode 0

#define UART_ParityDisabled 0
#define UART_ParityEven 2
#define UART_ParityOdd 3

#define CharacterSelectMask 0x06

#define UART_1StopBit 0
#define UART_2StopBits 1

#define UART_5BitSize 0
#define UART_6BitSize 1
#define UART_7BitSize 2
#define UART_8BitSize 3
#define UART_9BitSize 7

#define UART_EnableRxOnly   0
#define UART_EnableTxOnly   1 
#define UART_EnableRxTx  2

#define UART_InterrputDisabled 0
#define UART_InterruptRxOnly 1
#define UART_InterruptTxOnly 2
#define UART_InterruptREOnly 3
#define UART_InterruptRxTx 4
#define UART_InterruptRxRE 5
#define UART_InterruptTxRE 6
#define UART_InterruptAll 7
/** @} */

/**
 * @struct UART_Config_t 
 * @brief confihuration for UART initialization 
 */


typedef struct 
{
    /**
     * @var UART_Config_t::ModeSelect
     * @brief selects whether the UART mode is synchronous or asynchronous 
     */
    uint8_t ModeSelect; 
    /**
     * @var UART_Config_t::StopBitSelect
     * @brief selects whether there is one or two stop bits
     */

    uint8_t StopBitSelect; 
    /**
     * @var UART_Config_t::CharacterSizeSelect
     * @brief selects the number of bits of the data transferred (5:9 bits)
     */
    uint8_t CharacterSizeSelect; 
    /**
     * @var UART_Config_t::SpeedMode
     * @brief selects whether the transfer speed in normal or doubled 
     */
    uint8_t SpeedMode; 
    /**
     * @var UART_Config_t::ParitySelect
     * @brief selects whether the parity checking is even/odd or no parity
     */
    uint8_t ParitySelect;
    /**
     * @var UART_Config_t::BaudRate
     * @brief Defines the UART communication speed in bits per second.
     */
    uint32_t BaudRate;
    /**
     * @var UART_Config_t::InterruptSelect
     * @brief selects which interrupt/interrupts to enable 
     */
    uint8_t InterruptSelect;
    /**
     * @var UART_Config_t::EnableSelect
     * @brief selects which communication line to enable 
     */
    uint8_t EnableSelect 

}UART_Config_t ;

/**
 * @defgroup UART_ISR UART Interrupt Service Routines 
 * @brief Interrupt Service Routines of UART Driver 
 */

//Rx
void __vector_13(void) __attribute__((signal));
//RE
void __vector_14(void) __attribute__((signal));
//Tx
void __vector_15(void) __attribute__((signal));


#endif