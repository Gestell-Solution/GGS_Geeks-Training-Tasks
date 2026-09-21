/**
 * @file ADXL335_Interface.h
 * @author salma mohamed mahmoud fouad(salmafouadothman@gmail.com)
 * @brief driver to initazle the asxl335 sensor and print the data
 * @version 0.1
 * @date 2026-09-21
 * @copyright Copyright (c) 2026
 */
#ifndef ADXL355_INTERFACE_H_
#define ADXL355_INTERFACE_H_

#include"../../MCAL/UART/UART_Interface.h"
#include"../../MCAL/ADC/ADC_Interface.h"
#include"../../MCAL/DIO/DIO_Interface.h"
#include"ADXL335_Config.h"
#include<util/delay.h>
#include"../../COMMON/stdtype.h"
#include<math.h>

/**
 * @brief initaze the adxl335 uart and adc 
 * @fn ADXL335_Init 
 * @note dont forget to put it 
 */
void ADXL335_Init();
/**
 * @brief print the data
 * @fn ADXL335_PrintData 
 */
void ADXL335_PrintData();

#endif