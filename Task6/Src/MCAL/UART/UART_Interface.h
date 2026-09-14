/**
 * @file UART_Interface.h
 * @brief  Interface of the UART Peripheral driver
 * @details This file contains function prototypes required to interface with the driver  
 * @version 0.1
 * @author Malak Mohammed (malak.mohammed.esmail@gmail.com) 
 * @date 14-09-2026
 * @copyright Copyright (c) 2026, Gestell Company
 */


#ifndef _UART_INTERFACE_H
#define _UART_INTERFACE_H

#include "../../Common/Definition.h"
#include "../../Common/Bitmath.h"
#include "../Atmega32regmap.h"

#include "UART_Private.h"
#include "UART_Config.h"

/**
 * @defgroup UART_Driver UART Driver
 * @brief Public interface of the UART peripheral driver 
 * @{
 */

 /**
  * @brief Initializes the UART peripheral
  * @param UART_Config configuration struct
  */

void UART_Init (UART_Config_t UART_Config);

/**
 * @brief Sends data over UART using polling method
 * @param Data to be transmitted 
 */
void UART_SendBytePolling (uint16_t Data);

/**
 * @brief Receives data over UART using polling method
 * @return the data received 
 */
uint16_t UART_ReceiveBytePolling();

/**
 * @brief Sends string over UART using polling method
 * @param string pointer to the transmitted string
 */
void UART_SendStringPolling(uint8_t* string);

/**
 * @brief receives string over UART using polling method
 * @param Buffer pointer to the buffer where the receives string is stored
 * @param Terminator character that indicates the end of the received string 
 */
void UART_ReceiveStringPolling(uint8_t* Buffer,uint8_t Terminator);

/**
 * @brief sends buffer over UART using polling method
 * @param  Buffer pointer to the buffer where the sent data is stored
 * @param Length the length of the sent data
 */
void UART_SendBufferPolling(uint8_t* Buffer, uint16_t Length);

/**
 * @brief Sends data over UART using interrupt method
 * @param Data The data sent 
 */
void UART_SendByteInterrupt(uint16_t Data);

/**
 * @brief Enables the UART receive line
 */
void UART_RxEnable(void);

/**
 * @brief Enables the UART transmission line
 */
void UART_TxEnable(void);

/**
 * @brief Disables the UART receive line
 */
void UART_RxDisable(void);

/**
 * @brief Disables the UART transmission line
 */
void UART_TxDisable(void);

/**
 * @brief Enables the UART receive interrupt 
 */
void UART_RxInterruptEnable(void);

/**
 * @brief Enables the UART transmission interrupt 
 */
void UART_TxInterruptEnable(void);

/**
 * @brief Enables the UART (Data Register Empty) interrupt 
 */
void UART_REInterruptEnable(void);

/**
 * @brief Disables the UART receive interrupt
 */
void UART_RxInterruptDisable(void);

/**
 * @brief Disables the UART transmission interrupt 
 */
void UART_TxInterruptDisable(void);

/**
 * @brief Disables the UART (Data Register Empty) interrupt 
 */
void UART_REInterruptDisable(void);



/**
 * @brief Registers a callback function for the UART receive complete interrupt
 * @param PF pointer to the callback function to be executed when data is received 
 */
void UART_SetRxCallBack(void (*PF)(uint16_t ));

/**
 * @brief  Registers a callback function for the UART Transmission complete interrupt
 * @param PF pointer to the callback function to be executed when data is transmitted 
 */
void UART_SetTxCallBack(void (*PF)(void));

/**
 * @brief Registers a callback function for the UART Data Register Empty interrupt
 * @param PF pointer to the callback function to be executed when Data register is empty 
 */
void UART_SetRECallBack(void (*PF)(void));
/** @} */



#endif