#include "Spi_Interface.h"
#include <stdlib.h>
#include <stdint.h>
#include "Spi_Private.h"
#include "../../LIB/Definition.h"
#include "../../LIB/Bitmath.h"
#include "../Atmega32regmap.h"
#include "../../MCAL/DIO/DIO_Private.h"
#include "../../MCAL/DIO/DIO_Interface.h"

#include "SPI_Interface.h"
#include "SPI_Private.h"
#include "SPI_Config.h"



static void (*SPI_pvCallBackFunc)(void) = NULL;




void SPI_Init(SPI_Config_t SPI_Config)
{
// Enable SPI 
    SET_BIT(SPCR,SPI_SPE);

// Select ---> Master | Slave <------
if (SPI_Config.ModeSelect == SPI_MASTER_MODE){
    SET_BIT(SPCR, SPI_MSTR);

    DIO_WritePin(Dio_GroupB, Dio_Pin4, Output);//SS OUTWrite

    DIO_WritePin(Dio_GroupB, Dio_Pin5, Output); //MWrite

    DIO_WritePin(Dio_GroupB, Dio_Pin6, Input);//MWrite

    DIO_WritePin(Dio_GroupB, Dio_Pin7, Output);//SCK

    DIO_WritePin(Dio_GroupB, Dio_Pin4, High); //SS VCC

}
else if (SPI_Config.ModeSelect == SPI_SLAVE_MODE){

    DIO_WritePin(Dio_GroupB, Dio_Pin4, Input);  //SS INPUT

    DIO_WritePin(Dio_GroupB, Dio_Pin5, Input);  //MOSI

    DIO_WritePin(Dio_GroupB, Dio_Pin6, Output); //MISO

    DIO_WritePin(Dio_GroupB, Dio_Pin7, Input);  //SCK

    DIO_WritePin(Dio_GroupB, Dio_Pin4, Low); //SS GND


}

// Data Order 

if (SPI_Config.DataOrder == LSB){

    CLEAR_BIT(SPCR, SPI_DORD);
}
else if (SPI_Config.DataOrder == 1){

    SET_BIT(SPCR, SPI_DORD);
}



// Clock Polarity 

if (SPI_Config.ClockPolarity == Leading_Edge_First ){

    CLEAR_BIT(SPCR, SPI_CPOL);
}
else if (SPI_Config.ClockPolarity == Trailing_Edge_First){

    SET_BIT(SPCR, SPI_CPOL);

}


// Clock Phase

if (SPI_Config.CLockPhase == SPI_SAMPLE_LEADING){

    CLEAR_BIT(SPCR, SPI_CPHA);
}
else if (SPI_Config.CLockPhase == SPI_SAMPLE_TRAILING){

    SET_BIT(SPCR, SPI_CPHA);
}



// Clock Rate 
 
// Normal Speed
if (SPI_Config.ClockRate ==SPI_Prescaller4 ){

    CLEAR_BIT(SPCR, SPI_SPR1);
    CLEAR_BIT(SPCR, SPI_SPR0);
}
else if (SPI_Config.ClockRate == SPI_Prescaller16){

    CLEAR_BIT(SPCR, SPI_SPR1);
    SET_BIT(SPCR, SPI_SPR0);
}
else if ( SPI_Config.ClockRate==SPI_Prescaller64 ){

    SET_BIT(SPCR, SPI_SPR1);
    CLEAR_BIT(SPCR, SPI_SPR0);
}
else if (SPI_Config.ClockRate ==SPI_Prescaller128 ){

    SET_BIT(SPCR, SPI_SPR1);
    SET_BIT(SPCR, SPI_SPR0);
}

// Double Speed 

if(SPI_Config.ClockRate == SPI_DOUBPrescaller2){
    CLEAR_BIT(SPCR, SPI_SPR1);
    CLEAR_BIT(SPCR, SPI_SPR0);
    SET_BIT(SPSR, SPI_SPI2X);
}else if(SPI_Config.ClockRate == SPI_DOUBPrescaller8){
    CLEAR_BIT(SPCR, SPI_SPR1);
    SET_BIT(SPCR, SPI_SPR0);
    SET_BIT(SPSR, SPI_SPI2X);
}else if(SPI_Config.ClockRate == SPI_DOUBPrescaller32){
    SET_BIT(SPCR, SPI_SPR1);
    CLEAR_BIT(SPCR, SPI_SPR0);
    SET_BIT(SPSR, SPI_SPI2X);
}else if ( SPI_Config.ClockRate == SPI_DOUBPrescaller64){
    SET_BIT(SPCR, SPI_SPR1);
    SET_BIT(SPCR, SPI_SPR0);
    SET_BIT(SPSR, SPI_SPI2X);
}
}



void SPI_EnableInterrupt(void)
{
    SET_BIT(SPCR, SPI_SPIE);
  
}




void SPI_DisableInterrupt(void)
{
    CLEAR_BIT(SPCR, SPI_SPIE);
}




uint8_t SPI_SendByteAsync(uint8_t Data)
{
    SPDR = Data;

    return 0;
}




uint8_t SPI_GetReceivedData(void)
{
while(READ_BIT(SPSR, SPI_SPIF) == 0){
    // Wait for the transmission to complete
}

    return SPDR;
}



void SPI_SetCallBack(void (*PF)(void))
{
    SPI_pvCallBackFunc = PF;
}



void __vector_12(void)
{
   if (SPI_pvCallBackFunc != NULL)
    {
        SPI_pvCallBackFunc();
    }

}


uint8_t SPI_Transfer(uint8_t Data)
{
    // SPDR = Data ; 
    SPDR=Data;
    // Start Enable for SPI 
    //SET_BIT(SPCR, SPI_SPIE);
    // Waiting Flag 
     while(READ_BIT(SPSR, SPI_SPIF) == 0);
    // Clear Flag 
    
    // Get the SPDR  
    return SPDR ;
}