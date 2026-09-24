/**
 * @file SPI_Program.c
 * @brief SPI driver implementation.
 * @details Implements the ATmega32 SPI driver declared in SPI_Interface.h.
 *          The public API is documented in the header.
 * @version 1.1.0
 * @author Yousef Mohamed
 * @date 2026-09-24
 * @copyright Copyright (c) 2026, Gestell Company. All rights reserved.
 */

#include "SPI_Interface.h"
#include "../DIO/DIO_Interface.h"

/** Mask of the SPR1:SPR0 bits inside SPI_Config_t::ClockRate. */
#define SPI_RATE_SPR_MASK       0x03U
/** Bit position of the SPI2X information inside SPI_Config_t::ClockRate. */
#define SPI_RATE_2X_POS         2U

/** Callback executed by the SPI interrupt service routine. */
static SPI_Callback_t SPI_Callback = Null;

static uint8_t SPI_IsConfigValid(SPI_Config_t Config)
{
    uint8_t valid = Low;

    if ((Config.ModeSelect <= Master_mode) &&
        (Config.DataOrder <= MSB_First) &&
        (Config.ClockPolarity <= SPI_CPOL_HIGH) &&
        (Config.ClockPhase <= SPI_SAMPLE_TRAILING) &&
        (Config.ClockRate <= SPI_Prescaller64_DoubleSpeed))
    {
        valid = High;
    }

    return valid;
}

static void SPI_ConfigurePins(uint8_t Mode)
{
    if (Mode == Master_mode)
    {
        DIO_InitPin(Dio_GroupB, SPI_SS_PIN, Output);
        DIO_WritePin(Dio_GroupB, SPI_SS_PIN, High);     /* Keep SS high: avoids an unwanted switch to slave mode. */
        DIO_InitPin(Dio_GroupB, SPI_MOSI_PIN, Output);
        DIO_InitPin(Dio_GroupB, SPI_MISO_PIN, Input);
        DIO_InitPin(Dio_GroupB, SPI_SCK_PIN, Output);
    }
    else
    {
        DIO_InitPin(Dio_GroupB, SPI_SS_PIN, Input);
        DIO_InitPin(Dio_GroupB, SPI_MOSI_PIN, Input);
        DIO_InitPin(Dio_GroupB, SPI_MISO_PIN, Output);
        DIO_InitPin(Dio_GroupB, SPI_SCK_PIN, Input);
    }
}

void SPI_Init(SPI_Config_t SPI_Config)
{
    uint8_t spcr;
    uint8_t spsr;

    if (SPI_IsConfigValid(SPI_Config) == High)
    {
        SPI_ConfigurePins(SPI_Config.ModeSelect);

        /* SPR1:SPR0 come straight from the clock rate encoding. */
        spcr = (uint8_t)(SPI_Config.ClockRate & SPI_RATE_SPR_MASK);
        spsr = (uint8_t)((SPI_Config.ClockRate >> SPI_RATE_2X_POS) & 0x01U);

        if (SPI_Config.DataOrder == LSB_First)
        {
            SetBit(spcr, SPI_DORD);
        }
        if (SPI_Config.ModeSelect == Master_mode)
        {
            SetBit(spcr, SPI_MSTR);
        }
        if (SPI_Config.ClockPolarity == SPI_CPOL_HIGH)
        {
            SetBit(spcr, SPI_CPOL);
        }
        if (SPI_Config.ClockPhase == SPI_SAMPLE_TRAILING)
        {
            SetBit(spcr, SPI_CPHA);
        }
        if (ReadBit(SPCR_Reg, SPI_SPIE) == 1U)
        {
            SetBit(spcr, SPI_SPIE);                     /* Keep the interrupt enable state. */
        }

        SetBit(spcr, SPI_SPE);                          /* Enable the SPI last, all settings are ready. */

        SPSR_Reg = spsr;                                /* Only SPI2X is writable. */
        SPCR_Reg = spcr;
    }
}

uint8_t SPI_Transfer(uint8_t Data)
{
    SPDR_Reg = Data;

    while (ReadBit(SPSR_Reg, SPI_SPIF) == 0U)
    {
        /* Wait for the transfer to complete. */
    }

    return SPDR_Reg;                                    /* Reading SPDR also clears SPIF. */
}

void SPI_SendData(uint8_t Data)
{
    (void)SPI_Transfer(Data);
}

void SPI_SetCallBack(SPI_Callback_t CopyFunc)
{
    SPI_Callback = CopyFunc;
}

void SPI_EnableInterrupt(void)
{
    SetBit(SPCR_Reg, SPI_SPIE);
}

void SPI_DisableInterrupt(void)
{
    ClearBit(SPCR_Reg, SPI_SPIE);
}

void __vector_12(void) __attribute__((signal, used));
void __vector_12(void)
{
    if (SPI_Callback != Null)
    {
        SPI_Callback();
    }
}
