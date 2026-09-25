/**
 * @file LCD_Config.h
 * @brief LCD hardware configuration.
 * @details Selects the DIO pins and port used to connect the character LCD
 *          (HD44780 compatible). Change these values to match the wiring.
 * @version 1.1.0
 * @author Yousef Mohamed
 * @date 2026-09-24
 * @copyright Copyright (c) 2026, Gestell Company. All rights reserved.
 */

#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

#include "../../MCAL/DIO/DIO_Interface.h"


#define Lcd_RSPin      Dio_Pin0     /**< Register Select pin. */
#define Lcd_RSGroup    Dio_GroupC   /**< Register Select port. */
#define Lcd_RWPin      Dio_Pin1     /**< Read/Write pin (always driven low: write only). */
#define Lcd_RWGroup    Dio_GroupC   /**< Read/Write port. */
#define Lcd_EPin       Dio_Pin2     /**< Enable pin. */
#define Lcd_EGroup     Dio_GroupC   /**< Enable port. */
#define Lcd_DataGroup  Dio_GroupD   /**< Data port (D0..D7, or D4..D7 in 4-bit mode). */

#endif 
