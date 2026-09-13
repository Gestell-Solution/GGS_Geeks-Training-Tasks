/**
 * @file Bluetooth_Program.c
 * @brief Bluetooth (HC-05/HC-06-style) module driver implementation.
 * @version 1.0.0
 * @author Yousef Mohamed <email: yousefmohammed867@gmail.com>
 * @date 2026-09-14
 * @copyright Copyright (c) 2026, Gestell Company
 *
 * @details Design note - "polling with timeout, to prevent MCU blocking":
 *          every receive API here is a *bounded*-blocking call: it waits
 *          for data for at most Timeout_ms milliseconds and always returns
 *          control to the caller by then, instead of looping forever
 *          (`while (!DataReady);`) if the module is unplugged, out of
 *          range, or simply silent. That is what stands between this
 *          driver and an MCU that hangs completely whenever the phone on
 *          the other end of the link is not there.
 *          It is *not* a fully cooperative/non-blocking design (the MCU is
 *          still unavailable to other work for up to Timeout_ms) - that
 *          would require a free-running timer tick instead of
 *          UART's _delay_ms()-based wait. Keep Timeout_ms short (tens to a
 *          few hundred ms) for code that runs inside a shared superloop.
 */
#include "Bluetooth_Interface.h"
#include <string.h>

void Bluetooth_Init(Bluetooth_Config_t Bluetooth_Config)
{
    Uart_Config_t Local_UartConfig = {0};

    Local_UartConfig.ModeSelect          = Uart_AsynchronousMode;
    Local_UartConfig.StopBitSelect       = Uart_1StopBit;
    Local_UartConfig.ParitySelect        = Uart_ParityDisabled;
    Local_UartConfig.SizeCharacterSelect = Uart_8BitSize;
    Local_UartConfig.BaudRate            = Bluetooth_Config.BaudRate;
    Local_UartConfig.EnableSelect        = Uart_EnableRxAndTx;
    Local_UartConfig.SpeedMode           = Uart_NormalSpeed;
    Local_UartConfig.InterruptSelect     = Uart_InterruptDisabled; /* This driver is polling-driven. */

    UART_Init(Local_UartConfig);
}

void Bluetooth_SendString(const uint8_t * String)
{
    UART_SendStringPolling(String);
}

void Bluetooth_SendCommand(const uint8_t * Command)
{
    UART_SendStringPolling(Command);
    UART_SendStringPolling((const uint8_t *)BLUETOOTH_AT_TERMINATOR);
}

Bluetooth_Status_t Bluetooth_ReceiveByte_Timeout(uint8_t * Data, uint32_t Timeout_ms)
{
    uint16_t            Local_RawData = 0U;
    Bluetooth_Status_t  Local_Status;

    if (Data != Null)
    {
        if (UART_ReceiveBytePolling_Timeout(&Local_RawData, Timeout_ms) == UART_OK)
        {
            *Data        = (uint8_t)Local_RawData;
            Local_Status = BLUETOOTH_STATUS_OK;
        }
        else
        {
            Local_Status = BLUETOOTH_STATUS_TIMEOUT;
        }
    }
    else
    {
        Local_Status = BLUETOOTH_STATUS_ERROR;
    }

    return Local_Status;
}

Bluetooth_Status_t Bluetooth_ReceiveLine_Timeout(uint8_t * Buffer, uint32_t Timeout_ms)
{
    Bluetooth_Status_t Local_Status;

    if (Buffer != Null)
    {
        if (UART_ReceiveStringPolling_Timeout(Buffer, Timeout_ms) == UART_OK)
        {
            Local_Status = BLUETOOTH_STATUS_OK;
        }
        else
        {
            Local_Status = BLUETOOTH_STATUS_TIMEOUT;
        }
    }
    else
    {
        Local_Status = BLUETOOTH_STATUS_ERROR;
    }

    return Local_Status;
}

Bluetooth_Status_t Bluetooth_ReceiveLine(uint8_t * Buffer)
{
    return Bluetooth_ReceiveLine_Timeout(Buffer, (uint32_t)BLUETOOTH_TIMEOUT_MS);
}

Bluetooth_Status_t Bluetooth_SendCommand_CheckAck(const uint8_t * Command, uint32_t Timeout_ms)
{
    uint8_t             Local_Response[BLUETOOTH_MAX_LINE_LENGTH] = {0};
    Bluetooth_Status_t  Local_Status;

    Bluetooth_SendCommand(Command);
    Local_Status = Bluetooth_ReceiveLine_Timeout(Local_Response, Timeout_ms);

    if (Local_Status == BLUETOOTH_STATUS_OK)
    {
        if (strstr((const char *)Local_Response, BLUETOOTH_AT_OK_RESPONSE) == Null)
        {
            Local_Status = BLUETOOTH_STATUS_ERROR;
        }
        else
        {
            Local_Status = BLUETOOTH_STATUS_OK;
        }
    }
    else
    {
        /* Already BLUETOOTH_STATUS_TIMEOUT or BLUETOOTH_STATUS_ERROR - keep as-is. */
    }

    return Local_Status;
}
