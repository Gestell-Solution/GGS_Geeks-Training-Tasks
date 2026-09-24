#ifndef _ADXL_INTERFACE_H_
#define _ADXL_INTERFACE_H_

#include "../../MCAL/ADC/ADC_interface.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/UART/UART_interface.h"

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/COMMON_MACROS.h"
#include "../../LIB/STD_TYPES.h"

#include "ADXL_config.h"
#include "ADXL_private.h"

void ADXL_init();

// f32 ADXL_get_x_pos();
// f32 ADXL_get_y_pos();
// f32 ADXL_get_z_pos();

void ADXL_uart_send_accel();

#endif