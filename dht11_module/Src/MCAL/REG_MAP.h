#ifndef _ATMEGA32REGMAP_H_
#define _ATMEGA32REGMAP_H_

#include "../LIB/STD_TYPES.h"

/*
    please use the register in here by typing the name 
*/

/*
    other registers to use
    1. stauts register SREG (contins I-bit)
    2. interput registers MCUCR , MCUCSR , GICR , GIFR
*/

#define SPCR           *((volatile u8*)0x2D)
#define SPSR           *((volatile u8*)0x2E)
#define SPDR           *((volatile u8*)0x2F)

#define SREG           *((volatile u8*)0x5F)

#define MCUCR          *((volatile u8*)0x55)
#define MCUCSR         *((volatile u8*)0x54)
#define GICR           *((volatile u8*)0x5B)
#define GIFR           *((volatile u8*)0x5A)


// ========================================//
// -----------------DIO--------------------//
// ========================================//
/*

the dio is the Digtal input output 

DDR  : (data direction register)  it tells us if its gonna become output or input
PORT : it allows us to output a value 
PIN  : it allwos us to recive input
*/

// gorup A
#define DDRA           *((volatile u8*)0x3A)
#define PORTA          *((volatile u8*)0x3B)
#define PINA           *((volatile u8*)0x39)
// gorup B
#define DDRB           *((volatile u8*)0x37)
#define PORTB          *((volatile u8*)0x38)
#define PINB           *((volatile u8*)0x36)
// gorup C
#define DDRC           *((volatile u8*)0x34)
#define PORTC          *((volatile u8*)0x35)
#define PINC           *((volatile u8*)0x33)
// gorup D
#define DDRD           *((volatile u8*)0x31)
#define PORTD          *((volatile u8*)0x32)
#define PIND           *((volatile u8*)0x30)


// ========================================//
// -----------------ADC--------------------//
// ========================================//

/*
    page 214 - 215
    the ADC Multiplexer - selection regiserr : ADMUX
    BIT 7 & 6 - Reference Selection Bits -- table 83 to see 
    bit 7     - REFS1 : Reference Selection Bits 1
    bit 6     - REFS0 : Reference Selection Bits 0
    bit 5     - ADLAR : ADC Left Adjust Result
    bit 4-0   - mux analog channel -- table 84 to see 
    : the change will not go in effect until this conversion is
    : complete (ADIF in ADCSRA is set)
*/

#define ADMUX          *((volatile u8*)0x27)

/*
    page 216
    ADC Control and Status Register : ADCSRA
    Bit 7 – ADEN : ADC Enable
    Bit 6 – ADSC : ADC Start Conversion
    Bit 5 – ADATE: ADC Auto Trigger Enable
    Bit 4 – ADIF : ADC Interrupt Flag
    Bit 3 – ADIE : ADC Interrupt Enable
    Bit 2 – ADPS2: ADC Prescaler Select Bit  -- table 85 
    Bit 1 – ADPS1: ADC Prescaler Select Bit
    Bit 0 – ADPS0: ADC Prescaler Select Bit
*/

#define ADCSRA         *((volatile u8*)0x26)

/*
    page 217
    The ADC Data Register – ADCL and ADCH
    ADCL is the low byte
    ADCH is the high byte
    if ADLAR = 0 
    read from 0 to 9 
    : ADC0 - ADC7 --> ADCL // bits 0 to 7 
    : ADC8 - ADC9 --> ADCH // bits 8 to 9
    if ADLAR = 1 
    read from 6 to 15
    : ADC0 - ADC1 --> ADCL // bits 6 to 7
    : ADC2 - ADC9 --> ADCH // bits 8 to 15

*/

#define ADCH           *((volatile u8*)0x25)
#define ADCL           *((volatile u8*)0x24)

/*
    page 218
    Special FunctionIO register - SFIOR 
    Bit 7:5 – ADTS2:0: ADC Auto Trigger Source  -- table 86
    Bit 4   - reserved bit (not used)

*/

#define SFIOR          *((volatile u8*)0x50)

// ========================================//
// -----------------TIMER------------------//
// ========================================//

/*
    page 80 - 82 
    Timer/Counter Control Register – TCCR0
    Bit 7 – FOC0: Force Output Compare
    Bit 6, 3 – WGM01:0: Waveform Generation Mode -- table 38
    Bit 5:4 – COM01:0: Compare Match Output Mode -- table 39 non pwm mode 
    :                                            -- table 40 fast pwm mode
    Bit 2:0 – CS02:0: Clock Select -- table 42
*/

#define TCCR0          *((volatile u8*)0x53)

/*
    page 82
    Timer/Counter Register – TCNT0
    all bits are read/write 
*/

#define TCNT0          *((volatile u8*)0x52)

/*
    page 82
    Output Compare Register – OCR0
    compared with the counter tcnt0 a match can genearte a wave form
*/

#define OCR0           *((volatile u8*)0x5C)

/*
    page 82
    Timer/Counter Interrupt Mask Register – TIMSK
    Bit 1 – OCIE0: Timer/Counter0 Output Compare Match Interrupt Enable 
    : when OCIE0 is 1 & I-bit in status register is 1 
    : the timer compare match is enabled 
    : the interput is excuted if a compared is matched (happens)
    : when the OCF0 in TIFR is 1 
    Bit 0 – TOIE0: Timer/Counter0 Overflow Interrupt Enable
    : when TOIE0 is 1 & I-bit in status register is 1 
    : the timer interput overflow is enabled 
    : when the TOV0 in TIFR is 1
*/

#define TIMSK          *((volatile u8*)0x59)

/*
    page 83
    Timer/Counter Interrupt Flag Register - TIFR 
    used with the TIMSK regiseter
    Bit 1 – OCF0: Output Compare Flag 0
    Bit 0 – TOV0: Timer/Counter0 Overflow Flag
*/

#define TIFR           *((volatile u8*)0x58)
#define TCCR1A         *((volatile u8*)0x4F)
#define TCCR1B         *((volatile u8*)0x4E)
#define TCNT1H         *((volatile u8*)0x4D)
#define TCNT1L         *((volatile u8*)0x4C)
#define OCR1AH         *((volatile u8*)0x4B)
#define OCR1AL         *((volatile u8*)0x4A)
#define OCR1BH         *((volatile u8*)0x49)
#define OCR1BL         *((volatile u8*)0x48)
#define ICR1H          *((volatile u8*)0x47)
#define ICR1L          *((volatile u8*)0x46)
#define TCCR2          *((volatile u8*)0x45)
#define TCNT2          *((volatile u8*)0x44)
#define OCR2           *((volatile u8*)0x43)
#define ASSR           *((volatile u8*)0x42)

// ========================================//
// -----------------UART-------------------//
// ========================================//

/*
    page 159 
    USART I/O Data Register – UDR
*/

#define UDR           *((volatile u8*)0x2C)

/*
    page 160 
    USART Control and Status Register A – UCSRA
    Bit 7 – RXC: USART Receive Complete
    Bit 6 – TXC: USART Transmit Complete
    Bit 5 – UDRE: USART Data Register Empty
    Bit 4 – FE: Frame Error
    Bit 3 – DOR: Data OverRun
    Bit 2 – PE: Parity Error
    Bit 1 – U2X: Double the USART Transmission Speed
    Bit 0 – MPCM: Multi-processor Communication Mode
*/

#define UCSRA         *((volatile u8*)0x2B)

/*
    page 161
    USART Control and Status Register B – UCSRB
    Bit 7 – RXCIE: RX Complete Interrupt Enable
    Bit 6 – TXCIE: TX Complete Interrupt Enable
    Bit 5 – UDRIE: USART Data Register Empty Interrupt Enable
    Bit 4 – RXEN: Receiver Enable
    Bit 3 – TXEN: Transmitter Enable
    Bit 2 – UCSZ2: Character Size
    Bit 1 – RXB8: Receive Data Bit 8
    Bit 0 – TXB8: Transmit Data Bit 8
*/

#define UCSRB         *((volatile u8*)0x2A)

/*
    page 162 - 164
    USART Control and Status Register C – UCSRC
    Bit 7 – URSEL: Register Select
    Bit 6 – UMSEL: USART Mode Select 
    -- >  0 : Asynchronous operation
    :     1 : synchronous opeartion
    Bit 5:4 – UPM1:0: Parity Mode -- table 64
    Bit 3 – USBS: Stop Bit Select 
    -->   0 : 1 bit stop
    :     1 : 2 bit stop
    Bit 2:1 – UCSZ1:0: Character Size -- table 66
    Bit 0 – UCPOL: Clock Polarity

*/

#define UCSRC         *((volatile u8*)0x40)

/*
    page 164 
    USART Baud Rate Registers – UBRRL and UBRRH
    Bit 15 – URSEL: Register Select
    Bit 14:12 – Reserved Bits
    Bit 11:0 – UBRR11:0: USART Baud Rate Register
*/

#define UBRRL         *((volatile u8*)0x29)
#define UBRRH         *((volatile u8*)0x40)


#endif 