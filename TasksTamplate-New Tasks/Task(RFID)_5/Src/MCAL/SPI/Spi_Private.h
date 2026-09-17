#ifndef _SPI_PRIVATE_H
#define _SPI_PRIVATE_H
#include <stdint.h>


//SPCR Register

#define SPI_SPIE  7
#define SPI_SPE   6
#define SPI_DORD  5
#define SPI_MSTR  4
#define SPI_CPOL  3
#define SPI_CPHA  2
#define SPI_SPR1  1
#define SPI_SPR0  0

//SPSR Register
#define SPI_SPIF  7
#define SPI_WCOL  6
#define SPI_SPI2X 0

//SPDR Register 
#define SPI_MSB   7   
#define SPI_LSB   0

//PRESCALER  
/*Normal*/
#define SPI_Prescaller4        1 
#define SPI_Prescaller16       2
#define SPI_Prescaller64       3 
#define SPI_Prescaller128      4
/*Double*/ 
#define SPI_DOUBPrescaller2        5 
#define SPI_DOUBPrescaller8        6 
#define SPI_DOUBPrescaller32       7
#define SPI_DOUBPrescaller64       8 

//SPEED
#define SPI_NormalSpeed  0 
#define SPI_DoubleSpeed  1 
//SYNC
#define SPI_SynchronousMode    1


#define SPI_SLAVE_MODE    0
#define SPI_MASTER_MODE   1


// DATA ORDER
#define LSB   0
#define MSB   1

//Clock Polarity
#define Leading_Edge_First  0
#define Trailing_Edge_First 1

//CLOCK PHASE
#define SPI_SAMPLE_LEADING  0
#define SPI_SAMPLE_TRAILING 1




// ISR Vectors 
void __vector_12(void) __attribute__((signal,used));


typedef struct 
{
    uint8_t ModeSelect ; 
    uint8_t SizeCharacterSelect;
    uint8_t DataOrder;
    uint8_t ClockPolarity;
    uint8_t CLockPhase;
    uint8_t ClockRate;
    uint8_t EnbaleSelect ;
    uint8_t SpeedMode;
    uint8_t InterruptSelect ;
     
}SPI_Config_t;



#endif /* _SPI_PRIVATE_H */