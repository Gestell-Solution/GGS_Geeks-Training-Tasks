#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

#include "../../MCAL/DIO/DIO_Interface.h"

//RS
#define LCD_RSPin       DIO_Pin0
#define LCD_RSGroup     DIO_GroupA

//RW
#define LCD_RWPin       DIO_Pin1
#define LCD_RWGroup     DIO_GroupA

//Enable
#define LCD_EPin       DIO_Pin2
#define LCD_EGroup     DIO_GroupA

//Data
#define LCD_DataGroup  DIO_GroupB


#endif