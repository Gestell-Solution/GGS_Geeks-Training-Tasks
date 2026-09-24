#ifndef _UART_INTERFACE_H_
#define _UART_INTERFACE_H_


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/COMMON_MACROS.h"
#include "../REG_MAP.h"

#include "UART_config.h"
#include "UART_private.h"

void UART_init(Uart_config_t Uart_config);
void UART_send_string_polling(u8* String);
void UART_receive_string_polling(u8* Buffer, u8 Terminator);
void UART_send_number_polling(u8 Number);

void UART_send_byte_polling(u16 Data);
u16 UART_receive_byte_polling();

u8 UART_read_flag_RX_complete();

#endif