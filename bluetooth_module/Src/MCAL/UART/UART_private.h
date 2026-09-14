#ifndef _UART_PRIVATE_H_
#define _UART_PRIVATE_H_

// usart  the udr is the data register to send and recive data

// UCSRA 

typedef enum 
{
    Ucsra_MPCM = 0,  // Multi-processor Communication Mode
    Ucsra_U2X ,     // Double the USART Transmission Speed
    Ucsra_PE ,   // Parity Error
    Ucsra_DOR ,  // Data OverRun
    Ucsra_FE ,  // Frame Error
    Ucsra_UDRE , // USART Data Register Empty
    Ucsra_TXC , // USART Transmit Complete
    Ucsra_RXC ,  // USART Receive Complete
    
}UCSRA_t;

typedef enum
{
    Uart_speed_mode_normal = 0,
    Uart_speed_mode_double ,
}Uart_speed_mode_t;

typedef enum
{
    Uart_mode_async = 0,
    Uart_mode_sync ,
}Uart_mode_t;

typedef enum
{
    Ucsrb_TXB8 = 0, // Transmit Data Bit 8
    Ucsrb_RXB8 , // Receive Data Bit 8
    Ucsrb_UCSZ2 , // Character Size
    Ucsrb_TXEN , // Trans
    Ucsrb_RXEN , // Receiver Enable
    Ucsrb_UDRIE , // USART Data Register Empty Interrupt Enable
    Ucsrb_TXCIE , // TX Complete Interrupt Enable
    Ucsrb_RXCIE , // RX Complete Interrupt Enable
}UCSRB_t;

typedef enum
{
    Ucsrc_UCPOL = 0, // Clock Polarity 
    Ucsrc_UCSZ0 , // Character Size
    Ucsrc_UCSZ1 , // Character Size
    Ucsrc_USBS , // Stop Bit Select
    Ucsrc_UPM0 , // Parity Mode     
    Ucsrc_UPM1 , // Parity Mode 
    Ucsrc_UMSEL , // USART Mode Select // async or sync
    Ucsrc_URSEL , // Register Select // must be written as one to write to UCSRC

}UCSRC_t;

// clock polarity select for sync mode only
typedef enum
{
    Uart_clock_polarity_risingTX_fallingRX = 0,
    Uart_clock_polarity_fallingTX_risingRX ,
}Uart_clock_polarity_t;

// using the parity mode to select the parity type 

typedef enum
{
    Uart_parity_mode_disabled = 0,
    Uart_parity_mode_even ,
    Uart_parity_mode_odd ,
}Uart_parity_mode_t;

// stop select
typedef enum
{
    Uart_stop_bit_1 = 0,
    Uart_stop_bit_2 ,
}Uart_stop_bit_t;

// character size

typedef enum
{
    Uart_character_size_5 = 0,
    Uart_character_size_6 ,
    Uart_character_size_7 ,
    Uart_character_size_8 ,
    Uart_character_size_9 ,
}Uart_character_size_t;

// enable select
typedef enum
{
    Uart_EnableRxOnly = 0,
    Uart_EnableTxOnly ,
    Uart_EnableRxAndTx ,
}Uart_enable_select_t;

typedef struct
{
    Uart_mode_t             mode_select ; // async or sync
    Uart_stop_bit_t         stop_bit_select ; // 1 or 2 stop bits 
    Uart_parity_mode_t      parity_mode ; // even or odd or disabled 
    Uart_character_size_t   character_size ; // 5,6,7,8,9 bits 
    Uart_clock_polarity_t   clock_polarity ; // rising or falling 
    Uart_speed_mode_t       speed_mode ; // normal or double speed
    Uart_enable_select_t    enable_select ; 
    u32                     baud_rate ; // the baud rate value
}Uart_config_t;

#endif 
