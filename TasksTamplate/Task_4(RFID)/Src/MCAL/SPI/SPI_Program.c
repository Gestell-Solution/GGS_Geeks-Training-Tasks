/**
 * @file SPI_Program.c
 * @brief SPI Program driver implementation.
 * @details Contains the implementation of the module APIs and internal helper functions.
 * @version 1.0.0
 * @author Yousef
 * @date 2026-09-12
 * @copyright Copyright (c) 2026, Embedded Systems Project
 */

#include "SPI_Interface.h"
#include "../DIO/DIO_Interface.h"


static void (*PF_SPI)(void)= Null;


/**
 * @fn SPI_Init
 * @brief Initializes the SPI peripheral.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param SPI_Config Module configuration structure.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void SPI_Init(SPI_Config_t SPI_Config)
{
// PB4 = SS, PB5 = MOSI, PB6 = MISO, PB7 = SCK
    DIO_InitPin(Dio_GroupB, Dio_Pin4, Output);
    DIO_WritePin(Dio_GroupB, Dio_Pin4, High);
    DIO_InitPin(Dio_GroupB, Dio_Pin5, Output);
    DIO_InitPin(Dio_GroupB, Dio_Pin6, Input);
    DIO_InitPin(Dio_GroupB, Dio_Pin7, Output);

if(SPI_Config.DataOrder==LSB_First)
{
    SetBit(SPCR_Reg,SPI_DORD);
}
else if (SPI_Config.DataOrder==MSB_First)
{
  ClearBit(SPCR_Reg,SPI_DORD);
}


if(SPI_Config.ModeSelect==Master_mode)
{
   SetBit(SPCR_Reg,SPI_MSTR);
}
else if(SPI_Config.ModeSelect==Slave_mode)
{
  ClearBit(SPCR_Reg,SPI_MSTR);
}


if(SPI_Config.ClockPolarity==SPI_CPOL_LOW)
{
    ClearBit(SPCR_Reg,SPI_CPOL);
}
else if(SPI_Config.ClockPolarity==SPI_CPOL_HIGH)
{
    SetBit(SPCR_Reg,SPI_CPOL);
}

if(SPI_Config.ClockPhase==SPI_SAMPLE_LEADING)
{
    ClearBit(SPCR_Reg,SPI_CPHA);
}
else if(SPI_Config.ClockPhase==SPI_SAMPLE_TRAILING)
{
    SetBit(SPCR_Reg,SPI_CPHA);
}


if (SPI_Config.ClockRate==SPI_Prescaller4_NormalSpeed)
{
ClearBit(SPSR_Reg,SPI_SPI2X);
ClearBit(SPCR_Reg,SPI_SPR1);
ClearBit(SPCR_Reg,SPI_SPR0);
}
else if(SPI_Config.ClockRate==SPI_Prescaller16_NormalSpeed)
{
ClearBit(SPSR_Reg,SPI_SPI2X);
ClearBit(SPCR_Reg,SPI_SPR1);
SetBit(SPCR_Reg,SPI_SPR0);
}
else if(SPI_Config.ClockRate==SPI_Prescaller64_NormalSpeed)
{
ClearBit(SPSR_Reg,SPI_SPI2X);
SetBit(SPCR_Reg,SPI_SPR1);
ClearBit(SPCR_Reg,SPI_SPR0);
}
else if(SPI_Config.ClockRate==SPI_Prescaller128_NormalSpeed)
{
ClearBit(SPSR_Reg,SPI_SPI2X);
SetBit(SPCR_Reg,SPI_SPR1);
SetBit(SPCR_Reg,SPI_SPR0);
}
else if(SPI_Config.ClockRate==SPI_Prescaller2_DoubleSpeed)
{
SetBit(SPSR_Reg,SPI_SPI2X);
ClearBit(SPCR_Reg,SPI_SPR1);
ClearBit(SPCR_Reg,SPI_SPR0);
}
else if(SPI_Config.ClockRate==SPI_Prescaller8_DoubleSpeed)
{
SetBit(SPSR_Reg,SPI_SPI2X);
ClearBit(SPCR_Reg,SPI_SPR1);
SetBit(SPCR_Reg,SPI_SPR0);
}
else if(SPI_Config.ClockRate==SPI_Prescaller32_DoubleSpeed)
{
SetBit(SPSR_Reg,SPI_SPI2X);
SetBit(SPCR_Reg,SPI_SPR1);
ClearBit(SPCR_Reg,SPI_SPR0);
}
else if(SPI_Config.ClockRate==SPI_Prescaller64_DoubleSpeed)
{
SetBit(SPSR_Reg,SPI_SPI2X);
SetBit(SPCR_Reg,SPI_SPR1);
SetBit(SPCR_Reg,SPI_SPR0);
}
SetBit(SPCR_Reg,SPI_SPE);
}
/**
 * @fn SPI_SendData
 * @brief Sends one byte through SPI and waits for transfer completion.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param Data Data value or data buffer used by the operation.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void SPI_SendData(uint8_t Data)
{
    SPDR_Reg = Data;

    while(ReadBit(SPSR_Reg, SPI_SPIF) == 0);
}


/**
 * @fn SPI_EnableInterrupt
 * @brief Enables the SPI interrupt.
 * @details Performs the operation required by the module while preserving the module interface.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void SPI_EnableInterrupt(void)
{
    SetBit(SPCR_Reg, SPI_SPIE);
}
/**
 * @fn SPI_DisableInterrupt
 * @brief Disables the SPI interrupt.
 * @details Performs the operation required by the module while preserving the module interface.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void SPI_DisableInterrupt(void)
{
    ClearBit(SPCR_Reg, SPI_SPIE);
}


/**
 * @fn SPI_Transfer
 * @brief Transfers one byte through SPI and returns the received byte.
 * @details Loads the transmit byte into SPDR, waits for SPIF, then returns the received byte.
 * @param Data Data value or data buffer used by the operation.
 * @return uint8_t Return value of the operation.
 * @retval 0 Operation completed successfully when a status code is used.
 * @retval Non-zero Module-specific error or status code when applicable.
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
uint8_t SPI_Transfer(uint8_t Data)
{
    // SPDR = Data ;
    SPDR_Reg = Data;
    // Start Enable for SPI
    // Waiting Flag
    while(ReadBit(SPSR_Reg, SPI_SPIF) == 0);
    // Clear Flag
    // Get the SPDR
    return SPDR_Reg;
}
/**
 * @fn SPI_SetCallBack
 * @brief Registers the SPI interrupt callback function.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param CopyFunc Callback function invoked by the module.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void SPI_SetCallBack(void (*CopyFunc)(void))
{
    PF_SPI = CopyFunc;
}
/**
 * @fn __vector_12
 * @brief Handles the interrupt service routine for __vector_12.
 * @details Performs the operation required by the module while preserving the module interface.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void __vector_12(void)
{
    if(PF_SPI != Null)
    {
        PF_SPI();
    }
}
