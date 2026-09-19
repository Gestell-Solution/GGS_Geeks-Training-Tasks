#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/COMMON_MACROS.h"
#include "../REG_MAP.h"

#include "DIO_config.h"
#include "DIO_private.h"


void DIO_set_pin_direction(u8 group_name , u8 pin_number , u8 direction);  
void DIO_set_pin_value(u8 group_name , u8 pin_number , u8 value);  
u8   DIO_get_pin_value(u8 group_name , u8 pin_number);   
void DIO_tog_pin(u8 group_name , u8 pin_number);   

void DIO_set_group_direction(u8 group_name , u8 direction);
void DIO_set_group_value(u8 group_name , u8 value);
u8   DIO_get_group_value(u8 group_name);


#endif