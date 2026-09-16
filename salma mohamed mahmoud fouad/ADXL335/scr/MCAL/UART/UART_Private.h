#ifndef _UART_PRIVATE_H
#define _UART_PRIVATE_H
#include <stdint.h>


/*UCSRA */
#define Uart_RXC  7 
#define Uart_TXC  6
#define Uart_UDRE 5
#define Uart_FE   4 
#define Uart_DOR  3
#define Uart_PE   2 
#define Uart_U2X  1 
#define Uart_MPCM 0 
/**
 * @brief for choosing speed
 */
#define Uart_NormalSpeed  0 
#define Uart_DoubleSpeed  1 

/*UCSRB */
#define Uart_RXCIE  7 
#define Uart_TXCIE  6
#define Uart_UDRIE  5
#define Uart_RXEN   4 
#define Uart_TXEN   3
#define Uart_UCSZ2  2 
#define Uart_RXB8   1 
#define Uart_TXB8   0 


/*UCSRC */
#define Uart_URSEL  7 
#define Uart_UMSEL  6
#define Uart_UPM1   5
#define Uart_UPM0   4 
#define Uart_USBS   3
#define Uart_UCSZ1  2 
#define Uart_UCSZ0  1 
#define Uart_UCPOL   0 

/**
 * @brief select mode
 */
#define Uart_AsynchronousMode   0
#define Uart_SynchronousMode    1

/**
 * @brief parity select mode
 */
#define Uart_ParityDisabled 0 
#define Uart_ParityEven     1 
#define Uart_ParityOdd      2
/**
 * @brief  stop bit mode
 */
#define Uart_1StopBit       0
#define Uart_2StopBit       1

/**
 * @brief character size select mode
 */
#define Uart_5BitSize       0
#define Uart_6BitSize       1
#define Uart_7BitSize       2
#define Uart_8BitSize       3
#define Uart_9BitSize       7
/**
 * @brief enable select
 */
#define Uart_EnableRxOnly   0
#define Uart_EnableTxOnly   1 
#define Uart_EnableRxAndTx  2

/**
 * @brief interrupt
 */
#define Uart_InterruptDisabled      0  
#define Uart_InterruptRxOnly        1   
#define Uart_InterruptTxOnly        2   
#define Uart_InterruptUdreOnly      3   
#define Uart_InterruptRxTx          4   
#define Uart_InterruptRxUdre        5  
#define Uart_InterruptTxUdre        6   
#define Uart_InterruptAll           7   

/**
 * @struct Uart_Config_t
 * @brief Configuration for uart initialization
 */
typedef struct 
{
    /**
     * @var Uart_Config_t::ModeSelect
     * @brief  choose either asynchronous or synchronous
     */
    uint8_t ModeSelect ; 
    /**
     * @var Uart_Config_t::StopBitSelect
     * @brief  choose either 1 or 2 stop bit
     */
    uint8_t StopBitSelect;
    /**
     * @var Uart_Config_t::ParitySelect
     * @brief  choose either even odd or disable
     */
    uint8_t ParitySelect;
     /**
     * @var Uart_Config_t::SizeCharacterSelect
     * @brief  choose either 5,6,7,8,9,bit size
     */
    uint8_t SizeCharacterSelect;
     /**
     * @var Uart_Config_t::SpeedMode
     * @brief  choose either normal or double
     */
    uint8_t SpeedMode;
     /**
     * @var Uart_Config_t::BaudRate
     * @brief  choose either 1200, 2400, 4800, 9600, 19200, 38400, 57600, 11520
     */
    uint32_t BaudRate;
     /**
     * @var Uart_Config_t::InterruptSelect
     * @brief  choose either enable disable
     */
    uint8_t InterruptSelect ;
     /**
     * @var Uart_Config_t::EnbaleSelect
     * @brief  choose either enable rx only or tx only or both
     */
    uint8_t EnbaleSelect ;
}Uart_Config_t;

/* ISR Vectors */
void __vector_13(void) __attribute__((signal,used)); 
void __vector_14(void) __attribute__((signal,used)); 
void __vector_15(void) __attribute__((signal,used)); 

#endif