#ifndef _UART_INTERFACE_H
#define _UART_INTERFACE_H

/**
 * @file      UART_Interface.h
 * @author    salma mohamed mahmoud fouad(salmafouadothman@gmail.com)
 * @brief     this interface have all the function that can be used in uart
 * @details   this file contain uart init is used in initialization 
 *            and uart sending for sending a charcter a string a buffer and 
 *            another function to receive them we also have interrupt 
 *            that we can enable or disable we can also enable tx or rx only or enable 
 *            both of them .
 * @version   0.2
 * @date      2026-09-12
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdint.h>
#include <util/delay.h>

#include "../../COMMON/Definition.h"
#include "../../COMMON/Bitmath.h"
#include "../Atmega32regmap.h"

#include "UART_Private.h"
#include "UART_Config.h"



/**
 * @fn      UART_Init
 * @brief   to initialize the uart by using certain things.
 * @details first we chose the mode by usins mode select 
 *          we can choose asynchronous or synchronous.second we choose
 *          parityselect we have here  even odd or disable.
 *          third speed mode we have normal or double .
 *          fourth baud rate we have 1200, 2400, 4800, 9600, 19200, 38400, 57600, 115200
 *          fifth stop bit select here we choose 1 or 2 stop bit
 *          sixth size character select we have 5,6,7,8,9,bit size
 *          seventh interrupt select you either enable or diable it
 *          eighth enable select here we either enable rx only or tx only or both  
 * @param   Uart_Config used to choose the things in struct 
 * @note    dont forget to put it or the uart wont work
 */

void UART_Init(Uart_Config_t Uart_Config);
/**
 * @fn UART_SendBytePolling
 * @brief used to send a character
 * @param Data the charaacter i want to send
 */
void UART_SendBytePolling(uint16_t Data);
/**
 * @fn  UART_ReceiveBytePolling
 * @brief receive the charcter
 * @return uint16_t any character
 */
uint16_t UART_ReceiveBytePolling();
/**
 * @fn UART_SendStringPolling
 * @brief to send string
 * @param String pointer to the string you are sending
 */
void UART_SendStringPolling(uint8_t* String); 
void UART_ReceiveStringPolling(uint8_t* Buffer, uint8_t Terminator);
void UART_SendBufferPolling(uint8_t * Buffer , uint16_t Length);
/**
 * @brief it display numbers
 * @fn UART_SendNumberPolling
 * @param number the number you want to display
 */
void UART_SendNumberPolling(int32_t number);


void UART_SendByteInterrupt(uint16_t Data);

void UART_EnableRXInterrupt();
void UART_EnableTXInterrupt();
void UART_EnableREInterrupt();

void UART_DisableRXInterrupt();
void UART_DisableTXInterrupt();
void UART_DisableREInterrupt();

void UART_SetRXCallback(void (*PF)(uint16_t));
void UART_SetTXCallback(void (*PF)(void));
void UART_SetRECallback(void (*PF)(void));
/**
 * @defgroup form the enable select
 * @brief    it either enable tx or rx only or enable both
 * @{
 */
/**
 * @fn    UART_EnableRX
 * @brief EnableRX
 */
void UART_EnableRX();
/**
 * @fn    UART_EnableTX
 * @brief EnableTX
 */
void UART_EnableTX();
/**
 * @fn    UART_DisableRX
 * @brief DisableRX
 */
void UART_DisableRX();
/**
 * @fn    UART_DisableTX
 * @brief DisableTX
 */
void UART_DisableTX();
/**
 * @}
 */

#endif