/**
 * @file BLUETOOTH_program.c
 * @brief Implementation of the BLUETOOTH module driver.
 * @author Developer: beshoy esmat
 * @author Reviewer : Eng/Hesham Ahmed
 */

#include "BLUETOOTH_interface.h"

/** @brief Status of the most recently completed Bluetooth operation. */
static bluetooth_status_t bluetooth_status = Bluetooth_not_started;

/**
 * @brief Initializes the UART peripheral and Bluetooth RX/TX pin directions.
 * @see BLUETOOTH_interface.h for full documentation.
 */
void BLUETOOTH_init()
{
    Uart_config_t config_t =
    {
        .baud_rate = 9600,
        .character_size = Uart_character_size_8,
        .clock_polarity = Uart_clock_polarity_fallingTX_risingRX,
        .enable_select = Uart_EnableRxAndTx,
        .mode_select = Uart_mode_async,
        .parity_mode = Uart_parity_mode_disabled,
        .speed_mode = Uart_speed_mode_normal,
        .stop_bit_select = Uart_stop_bit_1
    };
    UART_init(config_t);
    DIO_set_pin_direction(Bluetooth_RX_group, Bluetooth_RX_pin, input);
    DIO_set_pin_direction(Bluetooth_TX_group, Bluetooth_TX_pin, output);
    bluetooth_status = Bluetooth_OK;
}

/**
 * @brief Sends a single byte over UART (blocking).
 * @see BLUETOOTH_interface.h for full documentation.
 */
void BLUETOOTH_send_byte(u8 data)
{
    if (data != Null)
    {
        UART_send_byte_polling(data);
        bluetooth_status = Bluetooth_send_complete;
    }
    else
    {
        bluetooth_status = Bluetooth_NULL;
    }
}

/**
 * @brief Waits for and reads a single byte, aborting after @p timeout iterations.
 *
 * @note @p timeout counts busy-wait loop iterations, not milliseconds;
 *       actual elapsed time depends on clock speed and compiler optimization.
 *
 * @see BLUETOOTH_interface.h for full documentation.
 */
bluetooth_status_t BLUETOOTH_receive_byte(u8 *data, u32 timeout)
{
    if (data != Null)
    {
        while (UART_read_flag_RX_complete() == FlagDown)
        {
            if (timeout == 0)
            {
                bluetooth_status = Bluetooth_TIMEOUT;
                return Bluetooth_TIMEOUT;
            }
            timeout--;
        }
        *data = (u8)UART_receive_byte_polling();
        bluetooth_status = Bluetooth_recive_complete;
        return Bluetooth_recive_complete;
    }
    else
    {
        bluetooth_status = Bluetooth_NULL;
        return Bluetooth_NULL;
    }
}

/**
 * @brief Sends a null-terminated string over UART (blocking).
 * @see BLUETOOTH_interface.h for full documentation.
 */
void BLUETOOTH_send_string(u8 *str)
{
    if (str != Null)
    {
        UART_send_string_polling(str);
        bluetooth_status = Bluetooth_send_complete;
    }
    else
    {
        bluetooth_status = Bluetooth_NULL;
    }
}

/**
 * @brief Receives a string byte-by-byte until the terminator or a per-byte timeout.
 *
 * Implemented on top of BLUETOOTH_receive_byte() so each character gets
 * its own timeout window, rather than a single timeout for the whole string.
 *
 * @see BLUETOOTH_interface.h for full documentation.
 */
bluetooth_status_t BLUETOOTH_receive_string(u8 *str, u8 terminator, u32 timeout)
{
    u8 LocalCount = 0;
    bluetooth_status_t LocalStatus;

    if (str != Null)
    {
        LocalStatus = BLUETOOTH_receive_byte(&str[LocalCount], timeout);

        while ((LocalStatus == Bluetooth_recive_complete) && (str[LocalCount] != terminator))
        {
            LocalCount++;
            LocalStatus = BLUETOOTH_receive_byte(&str[LocalCount], timeout);
        }

        if (LocalStatus == Bluetooth_recive_complete)
        {
            str[LocalCount] = '\0';
        }

        bluetooth_status = LocalStatus;
        return LocalStatus;
    }
    else
    {
        bluetooth_status = Bluetooth_NULL;
        return Bluetooth_NULL;
    }
}

/**
 * @brief Returns the status of the last Bluetooth operation.
 * @see BLUETOOTH_interface.h for full documentation.
 */
bluetooth_status_t BLUETOOTH_check_status()
{
    return bluetooth_status;
}

/**
 * @brief Returns the status of the last Bluetooth operation as a readable string.
 * @see BLUETOOTH_interface.h for full documentation.
 */
const u8* BLUETOOTH_check_string()
{
    bluetooth_status_t local_check_status = BLUETOOTH_check_status();

    if (local_check_status == Bluetooth_NULL)
    {
        return "Bluetooth_NULL";
    }
    else if (local_check_status == Bluetooth_OK)
    {
        return "Bluetooth_OK";
    }
    else if (local_check_status == Bluetooth_TIMEOUT)
    {
        return "Bluetooth_TIMEOUT";
    }
    else if (local_check_status == Bluetooth_send_complete)
    {
        return "Bluetooth_send_complete";
    }
    else if (local_check_status == Bluetooth_recive_complete)
    {
        return "Bluetooth_recive_complete";
    }
    else
    {
        return "Bluetooth_not_started";
    }
}