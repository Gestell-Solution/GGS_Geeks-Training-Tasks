/**
 * @file Atmega32regmap.h
 * @brief ATmega32 register map definitions.
 * @details Provides symbolic access to the ATmega32 memory-mapped peripheral
 *          registers used by the project. Addresses are data-space addresses
 *          (I/O address + 0x20), as listed in parentheses in the datasheet.
 * @version 1.1.0
 * @author Yousef Mohamed
 * @date 2026-09-24
 * @copyright Copyright (c) 2026, Gestell Company. All rights reserved.
 */

#ifndef ATMEGA32REGMAP_H
#define ATMEGA32REGMAP_H

#include <stdint.h>

#define SREG_Reg    (*((volatile uint8_t *)0x5FU))  
#define SPH_Reg     (*((volatile uint8_t *)0x5EU))  
#define SPL_Reg     (*((volatile uint8_t *)0x5DU))  
#define OCR0_Reg    (*((volatile uint8_t *)0x5CU)) 
#define GICR_Reg    (*((volatile uint8_t *)0x5BU)) 
#define GIFR_Reg    (*((volatile uint8_t *)0x5AU)) 
#define TIMSK_Reg   (*((volatile uint8_t *)0x59U)) 
#define TIFR_Reg    (*((volatile uint8_t *)0x58U)) 
#define SPMCR_Reg   (*((volatile uint8_t *)0x57U))
#define TWCR_Reg    (*((volatile uint8_t *)0x56U))
#define MCUCR_Reg   (*((volatile uint8_t *)0x55U))
#define MCUCSR_Reg  (*((volatile uint8_t *)0x54U))
#define TCCR0_Reg   (*((volatile uint8_t *)0x53U))
#define TCNT0_Reg   (*((volatile uint8_t *)0x52U))
#define OSCCAL_Reg  (*((volatile uint8_t *)0x51U))  
#define OCDR_Reg    (*((volatile uint8_t *)0x51U))  
#define SFIOR_Reg   (*((volatile uint8_t *)0x50U))
#define TCCR1A_Reg  (*((volatile uint8_t *)0x4FU))
#define TCCR1B_Reg  (*((volatile uint8_t *)0x4EU))
#define TCNT1H_Reg  (*((volatile uint8_t *)0x4DU))
#define TCNT1L_Reg  (*((volatile uint8_t *)0x4CU))
#define OCR1AH_Reg  (*((volatile uint8_t *)0x4BU))  
#define OCR1AL_Reg  (*((volatile uint8_t *)0x4AU)) 
#define OCR1BH_Reg  (*((volatile uint8_t *)0x49U))  
#define OCR1BL_Reg  (*((volatile uint8_t *)0x48U)) 
#define ICR1H_Reg   (*((volatile uint8_t *)0x47U)) 
#define ICR1L_Reg   (*((volatile uint8_t *)0x46U)) 
#define TCCR2_Reg   (*((volatile uint8_t *)0x45U))
#define TCNT2_Reg   (*((volatile uint8_t *)0x44U))
#define OCR2_Reg    (*((volatile uint8_t *)0x43U))
#define ASSR_Reg    (*((volatile uint8_t *)0x42U))
#define WDTCR_Reg   (*((volatile uint8_t *)0x41U))
#define UBRRH_Reg   (*((volatile uint8_t *)0x40U))  
#define UCSRC_Reg   (*((volatile uint8_t *)0x40U))  
#define EEARH_Reg   (*((volatile uint8_t *)0x3FU))
#define EEARL_Reg   (*((volatile uint8_t *)0x3EU))
#define EEDR_Reg    (*((volatile uint8_t *)0x3DU))
#define EECR_Reg    (*((volatile uint8_t *)0x3CU))
#define PORTA_Reg   (*((volatile uint8_t *)0x3BU))
#define DDRA_Reg    (*((volatile uint8_t *)0x3AU))
#define PINA_Reg    (*((volatile uint8_t *)0x39U))
#define PORTB_Reg   (*((volatile uint8_t *)0x38U))
#define DDRB_Reg    (*((volatile uint8_t *)0x37U))
#define PINB_Reg    (*((volatile uint8_t *)0x36U))
#define PORTC_Reg   (*((volatile uint8_t *)0x35U))
#define DDRC_Reg    (*((volatile uint8_t *)0x34U))
#define PINC_Reg    (*((volatile uint8_t *)0x33U))
#define PORTD_Reg   (*((volatile uint8_t *)0x32U))
#define DDRD_Reg    (*((volatile uint8_t *)0x31U))
#define PIND_Reg    (*((volatile uint8_t *)0x30U))
#define SPDR_Reg    (*((volatile uint8_t *)0x2FU))
#define SPSR_Reg    (*((volatile uint8_t *)0x2EU))
#define SPCR_Reg    (*((volatile uint8_t *)0x2DU))
#define UDR_Reg     (*((volatile uint8_t *)0x2CU))
#define UCSRA_Reg   (*((volatile uint8_t *)0x2BU))
#define UCSRB_Reg   (*((volatile uint8_t *)0x2AU))
#define UBRRL_Reg   (*((volatile uint8_t *)0x29U))
#define ACSR_Reg    (*((volatile uint8_t *)0x28U)) 
#define ADMUX_Reg   (*((volatile uint8_t *)0x27U))
#define ADCSRA_Reg  (*((volatile uint8_t *)0x26U))
#define ADCH_Reg    (*((volatile uint8_t *)0x25U))
#define ADCL_Reg    (*((volatile uint8_t *)0x24U))
#define ADCData_Reg (*((volatile uint16_t *)0x24U))
#define TWDR_Reg    (*((volatile uint8_t *)0x23U))
#define TWAR_Reg    (*((volatile uint8_t *)0x22U)) 
#define TWSR_Reg    (*((volatile uint8_t *)0x21U))
#define TWBR_Reg    (*((volatile uint8_t *)0x20U))

#endif 