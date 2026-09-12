#ifndef HC05_INTERFACE_H_
#define HC05_INTERFACE_H_
/**
 * @file HC05_Interface.h
 * @author salma mohamed mahmoud fouad(salmafouadothman@gmail.com)
 * @brief driver to initialize uart and receive data for the bluetooth module
 * @version 0.1
 * @date 2026-09-12
 * @copyright Copyright (c) 2026
 */
#include <util/delay.h>
#include "../../MCAL/UART/UART_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"
/**
 * @brief it initialze the hc05
 * @fn HC05_Init
 * @note the hc05 wont work without it
 */
void HC05_Init();
/**
 * @brief receive character to use it in something else
 * @fn HC05_Get_Data
 * @return data the received character 
 */
uint16_t HC05_Get_Data();

#endif