/**
 * @file Atmega32regmap.h
 * @brief ATmega register map definitions.
 * @details Provides symbolic access to the ATmega32 memory-mapped peripheral registers used by the project.
 * @version 1.0.0
 * @author Yousef Mohamed <email: yousefmohammed867@gmail.com>
 * @date 2026-09-14
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef _ATMEGA32REGMAP_H_
/**
 * @defgroup ATMEGA32REGMAP_H_GROUP Atmega32regmap definitions
 * @brief Related atmega32regmap definitions.
 * @{
 */
/**
 * @def _ATMEGA32REGMAP_H_
 * @brief Definition for _ATMEGA32REGMAP_H_.
 */
#define _ATMEGA32REGMAP_H_

#include <stdint.h>

/**
 * @def SREG_Reg
 * @brief Memory-mapped register definition for SREG_Reg.
 */
#define SREG_Reg            *((volatile uint8_t*)0x5F)
/**
 * @def SPH_Reg
 * @brief Memory-mapped register definition for SPH_Reg.
 */
#define SPH_Reg             *((volatile uint8_t*)0x5E)
/**
 * @def SPL_Reg
 * @brief Memory-mapped register definition for SPL_Reg.
 */
#define SPL_Reg             *((volatile uint8_t*)0x5D)
/**
 * @def OCR0_Reg
 * @brief Memory-mapped register definition for OCR0_Reg.
 */
#define OCR0_Reg            *((volatile uint8_t*)0x5C)
/**
 * @def GICR_Reg
 * @brief Memory-mapped register definition for GICR_Reg.
 */
#define GICR_Reg            *((volatile uint8_t*)0x5B)
/**
 * @def GIFR_Reg
 * @brief Memory-mapped register definition for GIFR_Reg.
 */
#define GIFR_Reg            *((volatile uint8_t*)0x5A)
/**
 * @def TIMSK_Reg
 * @brief Memory-mapped register definition for TIMSK_Reg.
 */
#define TIMSK_Reg           *((volatile uint8_t*)0x59)
/**
 * @def TIFR_Reg
 * @brief Memory-mapped register definition for TIFR_Reg.
 */
#define TIFR_Reg            *((volatile uint8_t*)0x58)
/**
 * @def SPMCR_Reg
 * @brief Memory-mapped register definition for SPMCR_Reg.
 */
#define SPMCR_Reg           *((volatile uint8_t*)0x57)
/**
 * @def TWCR_Reg
 * @brief Memory-mapped register definition for TWCR_Reg.
 */
#define TWCR_Reg            *((volatile uint8_t*)0x56)
/**
 * @def MCUCR_Reg
 * @brief Memory-mapped register definition for MCUCR_Reg.
 */
#define MCUCR_Reg           *((volatile uint8_t*)0x55)
/**
 * @def MCUCSR_Reg
 * @brief Memory-mapped register definition for MCUCSR_Reg.
 */
#define MCUCSR_Reg          *((volatile uint8_t*)0x54)
/**
 * @def TCCR0_Reg
 * @brief Memory-mapped register definition for TCCR0_Reg.
 */
#define TCCR0_Reg           *((volatile uint8_t*)0x53)
/**
 * @def TCNT0_Reg
 * @brief Memory-mapped register definition for TCNT0_Reg.
 */
#define TCNT0_Reg           *((volatile uint8_t*)0x52)
/**
 * @def OSCCAL_Reg
 * @brief Memory-mapped register definition for OSCCAL_Reg.
 */
#define OSCCAL_Reg          *((volatile uint8_t*)0x51)
/**
 * @def OCDR_Reg
 * @brief Memory-mapped register definition for OCDR_Reg.
 */
#define OCDR_Reg            *((volatile uint8_t*)0x51)
/**
 * @def SFIOR_Reg
 * @brief Memory-mapped register definition for SFIOR_Reg.
 */
#define SFIOR_Reg           *((volatile uint8_t*)0x50)
/**
 * @def TCCR1A_Reg
 * @brief Memory-mapped register definition for TCCR1A_Reg.
 */
#define TCCR1A_Reg          *((volatile uint8_t*)0x4F)
/**
 * @def TCCR1B_Reg
 * @brief Memory-mapped register definition for TCCR1B_Reg.
 */
#define TCCR1B_Reg          *((volatile uint8_t*)0x4E)
/**
 * @def TCNT1H_Reg
 * @brief Memory-mapped register definition for TCNT1H_Reg.
 */
#define TCNT1H_Reg          *((volatile uint8_t*)0x4D)
/**
 * @def TCNT1L_Reg
 * @brief Memory-mapped register definition for TCNT1L_Reg.
 */
#define TCNT1L_Reg          *((volatile uint8_t*)0x4C)
/**
 * @def OCR1AH_Reg
 * @brief Memory-mapped register definition for OCR1AH_Reg.
 */
#define OCR1AH_Reg          *((volatile uint8_t*)0x4B)
/**
 * @def OCR1AL_Reg
 * @brief Memory-mapped register definition for OCR1AL_Reg.
 */
#define OCR1AL_Reg          *((volatile uint8_t*)0x4A)
/**
 * @def OCR1BH_Reg
 * @brief Memory-mapped register definition for OCR1BH_Reg.
 */
#define OCR1BH_Reg          *((volatile uint8_t*)0x49)
/**
 * @def OCR1BL_Reg
 * @brief Memory-mapped register definition for OCR1BL_Reg.
 */
#define OCR1BL_Reg          *((volatile uint8_t*)0x48)
/**
 * @def ICR1H_Reg
 * @brief Memory-mapped register definition for ICR1H_Reg.
 */
#define ICR1H_Reg           *((volatile uint8_t*)0x47)
/**
 * @def ICR1L_Reg
 * @brief Memory-mapped register definition for ICR1L_Reg.
 */
#define ICR1L_Reg           *((volatile uint8_t*)0x46)
/**
 * @def TCCR2_Reg
 * @brief Memory-mapped register definition for TCCR2_Reg.
 */
#define TCCR2_Reg           *((volatile uint8_t*)0x45)
/**
 * @def TCNT2_Reg
 * @brief Memory-mapped register definition for TCNT2_Reg.
 */
#define TCNT2_Reg           *((volatile uint8_t*)0x44)
/**
 * @def OCR2_Reg
 * @brief Memory-mapped register definition for OCR2_Reg.
 */
#define OCR2_Reg            *((volatile uint8_t*)0x43)
/**
 * @def ASSR_Reg
 * @brief Memory-mapped register definition for ASSR_Reg.
 */
#define ASSR_Reg            *((volatile uint8_t*)0x42)
/**
 * @def WDTCR_Reg
 * @brief Memory-mapped register definition for WDTCR_Reg.
 */
#define WDTCR_Reg           *((volatile uint8_t*)0x41)
/**
 * @def UBRRH_Reg
 * @brief Memory-mapped register definition for UBRRH_Reg.
 */
#define UBRRH_Reg           *((volatile uint8_t*)0x40)
/**
 * @def UCSRC_Reg
 * @brief Memory-mapped register definition for UCSRC_Reg.
 */
#define UCSRC_Reg           *((volatile uint8_t*)0x40)
/**
 * @def EEARH_Reg
 * @brief Memory-mapped register definition for EEARH_Reg.
 */
#define EEARH_Reg           *((volatile uint8_t*)0x3F)
/**
 * @def EEARL_Reg
 * @brief Memory-mapped register definition for EEARL_Reg.
 */
#define EEARL_Reg           *((volatile uint8_t*)0x3E)
/**
 * @def EEDR_Reg
 * @brief Memory-mapped register definition for EEDR_Reg.
 */
#define EEDR_Reg            *((volatile uint8_t*)0x3D)
/**
 * @def EECR_Reg
 * @brief Memory-mapped register definition for EECR_Reg.
 */
#define EECR_Reg            *((volatile uint8_t*)0x3C)
/**
 * @def PORTA_Reg
 * @brief Memory-mapped register definition for PORTA_Reg.
 */
#define PORTA_Reg           *((volatile uint8_t*)0x3B)
/**
 * @def DDRA_Reg
 * @brief Memory-mapped register definition for DDRA_Reg.
 */
#define DDRA_Reg            *((volatile uint8_t*)0x3A)
/**
 * @def PINA_Reg
 * @brief Memory-mapped register definition for PINA_Reg.
 */
#define PINA_Reg            *((volatile uint8_t*)0x39)
/**
 * @def PORTB_Reg
 * @brief Memory-mapped register definition for PORTB_Reg.
 */
#define PORTB_Reg           *((volatile uint8_t*)0x38)
/**
 * @def DDRB_Reg
 * @brief Memory-mapped register definition for DDRB_Reg.
 */
#define DDRB_Reg            *((volatile uint8_t*)0x37)
/**
 * @def PINB_Reg
 * @brief Memory-mapped register definition for PINB_Reg.
 */
#define PINB_Reg            *((volatile uint8_t*)0x36)
/**
 * @def PORTC_Reg
 * @brief Memory-mapped register definition for PORTC_Reg.
 */
#define PORTC_Reg           *((volatile uint8_t*)0x35)
/**
 * @def DDRC_Reg
 * @brief Memory-mapped register definition for DDRC_Reg.
 */
#define DDRC_Reg            *((volatile uint8_t*)0x34)
/**
 * @def PINC_Reg
 * @brief Memory-mapped register definition for PINC_Reg.
 */
#define PINC_Reg            *((volatile uint8_t*)0x33)
/**
 * @def PORTD_Reg
 * @brief Memory-mapped register definition for PORTD_Reg.
 */
#define PORTD_Reg           *((volatile uint8_t*)0x32)
/**
 * @def DDRD_Reg
 * @brief Memory-mapped register definition for DDRD_Reg.
 */
#define DDRD_Reg            *((volatile uint8_t*)0x31)
/**
 * @def PIND_Reg
 * @brief Memory-mapped register definition for PIND_Reg.
 */
#define PIND_Reg            *((volatile uint8_t*)0x30)
/**
 * @def SPDR_Reg
 * @brief Memory-mapped register definition for SPDR_Reg.
 */
#define SPDR_Reg            *((volatile uint8_t*)0x2F)
/**
 * @def SPSR_Reg
 * @brief Memory-mapped register definition for SPSR_Reg.
 */
#define SPSR_Reg            *((volatile uint8_t*)0x2E)
/**
 * @def SPCR_Reg
 * @brief Memory-mapped register definition for SPCR_Reg.
 */
#define SPCR_Reg            *((volatile uint8_t*)0x2D)
/**
 * @def UDR_Reg
 * @brief Memory-mapped register definition for UDR_Reg.
 */
#define UDR_Reg             *((volatile uint8_t*)0x2C)
/**
 * @def UCSRA_Reg
 * @brief Memory-mapped register definition for UCSRA_Reg.
 */
#define UCSRA_Reg           *((volatile uint8_t*)0x2B)
/**
 * @def UCSRB_Reg
 * @brief Memory-mapped register definition for UCSRB_Reg.
 */
#define UCSRB_Reg           *((volatile uint8_t*)0x2A)
/**
 * @def UBRRL_Reg
 * @brief Memory-mapped register definition for UBRRL_Reg.
 */
#define UBRRL_Reg           *((volatile uint8_t*)0x29)
/**
 * @def ACSR_Reg
 * @brief Memory-mapped register definition for ACSR_Reg.
 */
#define ACSR_Reg            *((volatile uint8_t*)0x28)
/**
 * @def ADMUX_Reg
 * @brief Memory-mapped register definition for ADMUX_Reg.
 */
#define ADMUX_Reg           *((volatile uint8_t*)0x27)
/**
 * @def ADCSRA_Reg
 * @brief Memory-mapped register definition for ADCSRA_Reg.
 */
#define ADCSRA_Reg          *((volatile uint8_t*)0x26)
/**
 * @def ADCH_Reg
 * @brief Memory-mapped register definition for ADCH_Reg.
 */
#define ADCH_Reg            *((volatile uint8_t*)0x25)
/**
 * @def ADCL_Reg
 * @brief Memory-mapped register definition for ADCL_Reg.
 */
#define ADCL_Reg            *((volatile uint8_t*)0x24)
/**
 * @def ADCData_Reg
 * @brief Memory-mapped register definition for ADCData_Reg.
 */
#define ADCData_Reg         *((volatile uint16_t*)0x24)
/**
 * @def TWDR_Reg
 * @brief Memory-mapped register definition for TWDR_Reg.
 */
#define TWDR_Reg            *((volatile uint8_t*)0x23)
/**
 * @def TWAR_Reg
 * @brief Memory-mapped register definition for TWAR_Reg.
 */
#define TWAR_Reg            *((volatile uint8_t*)0x22)
/**
 * @def TWSR_Reg
 * @brief Memory-mapped register definition for TWSR_Reg.
 */
#define TWSR_Reg            *((volatile uint8_t*)0x21)
/**
 * @def TWBR_Reg
 * @brief Memory-mapped register definition for TWBR_Reg.
 */
#define TWBR_Reg            *((volatile uint8_t*)0x20)






/** @} */

#endif
