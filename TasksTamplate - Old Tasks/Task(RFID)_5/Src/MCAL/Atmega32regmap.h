#ifndef _ATMEGA32REGMAP_H_
#define _ATMEGA32REGMAP_H_





#define SREG       *((volatile uint8_t *)0x5F)
#define SPH        *((volatile uint8_t *)0x5E)
#define SPL        *((volatile uint8_t *)0x5D)
#define OCR0       *((volatile uint8_t *)0x3C)
#define GICR       *((volatile uint8_t *)0x5B)
#define TIMSK      *((volatile uint8_t *)0x59)
#define TIFR       *((volatile uint8_t *)0x58)
#define SPMCR      *((volatile uint8_t *)0x57)
#define TWCR       *((volatile uint8_t *)0x56)
#define MCUCR      *((volatile uint8_t *)0x55)
#define MCUCSR     *((volatile uint8_t *)0x54)
#define TCCR0      *((volatile uint8_t *)0x53)
#define TCNT0      *((volatile uint8_t *)0x52)
#define OSCCAL     *((volatile uint8_t *)0x51)
#define OCDR       *((volatile uint8_t *)0x51)
#define SFIOR      *((volatile uint8_t *)0x50)

#define TCCR1A    *((volatile uint8_t *)0x4F)
#define TCCR1B    *((volatile uint8_t *)0x4E)
#define TCNT1H    *((volatile uint8_t *)0x4D)
#define TCNT1     *((volatile uint8_t *)0x4C)
#define OCR1AH    *((volatile uint8_t *)0x4B)
#define OCR1A     *((volatile uint8_t *)0x4A)
#define OCR1BH    *((volatile uint8_t *)0x49)
#define OCR1B     *((volatile uint8_t *)0x48)
#define ICR1H     *((volatile uint8_t *)0x47)
#define ICR1      *((volatile uint8_t *)0x46)
#define TCCR2     *((volatile uint8_t *)0x45)
#define TCNT2     *((volatile uint8_t *)0x44)
#define OCR2      *((volatile uint8_t *)0x43)
#define ASSR      *((volatile uint8_t *)0x42)
#define WDTCR     *((volatile uint8_t *)0x41)
#define UBRRH     *((volatile uint8_t *)0x40)
#define UCSRC     *((volatile uint8_t *)0x40)

#define EEARH     *((volatile uint8_t *)0x3F)
#define EEARL     *((volatile uint8_t *)0x3E)
#define EEDR      *((volatile uint8_t *)0x3D)
#define EECR      *((volatile uint8_t *)0x3C)
#define PORTA     *((volatile uint8_t *)0x3B)
#define DDRA      *((volatile uint8_t *)0x3A)
#define PINA      *((volatile uint8_t *)0x39)
#define PORTB     *((volatile uint8_t *)0x38)
#define DDRB      *((volatile uint8_t *)0x37)
#define PINB      *((volatile uint8_t *)0x36)
#define PORTC     *((volatile uint8_t *)0x35)
#define DDRC      *((volatile uint8_t *)0x34)
#define PINC      *((volatile uint8_t *)0x33)
#define PORTD     *((volatile uint8_t *)0x32)
#define DDRD      *((volatile uint8_t *)0x31)
#define PIND      *((volatile uint8_t *)0x30)

#define SPDR      *((volatile uint8_t *)0x2F)
#define SPSR      *((volatile uint8_t *)0x2E)
#define SPCR      *((volatile uint8_t *)0x2D)
#define UDR       *((volatile uint8_t *)0x2C)
#define UCSRA     *((volatile uint8_t *)0x2B)
#define UCSRB     *((volatile uint8_t *)0x2A)
#define UBRRL     *((volatile uint8_t *)0x29)
#define ACSR      *((volatile uint8_t *)0x28)
#define ADMUX     *((volatile uint8_t *)0x27)
#define ADCSRA    *((volatile uint8_t *)0x26)
#define ADCH      *((volatile uint8_t *)0x25)
#define ADCL      *((volatile uint8_t *)0x24)
#define TWDR      *((volatile uint8_t *)0x23)
#define TWAR      *((volatile uint8_t *)0x22)







#endif 