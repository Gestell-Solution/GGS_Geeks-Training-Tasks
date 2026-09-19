/**
 * @file DTH_11_Interface.h
 * @author Ali Sotohy (alielsotohy2006@gmail.com)
 * @brief  Public interface for the DHT11 temperature & humidity driver.
 * @version 2.0.0
 * @date 2026-09-18
 * @copyright Copyright Gestell (c) 2026
 */
#ifndef DTH_11_INTERFACE_H
#define DTH_11_INTERFACE_H

#include "../../MCAL/DIO/DIO_Interface.h"
#include "DTH_11_Config.h"
#include "DTH_11_Private.h"
#include <util/delay.h>
#include <stdint.h>

/**
 * @brief Sends the MCU start signal to wake the DHT11 up.
 */
void DTH_11_SendRequest();

/**
 * @brief Waits for the sensor's acknowledgement pulses after a request.
 * @return 1 if the sensor acknowledged in time, 0 if it timed out.
 */
uint8_t DTH_11_ReceiveResponse();

/**
 * @brief Reads the 40-bit data frame and verifies its checksum.
 * @param data Pointer to a 5-byte buffer: [Humidity, 0, Temperature, 0, Checksum].
 * @return 1 if the full frame was read and the checksum matched, 0 otherwise.
 */
uint8_t DTH_11_ReadData(uint8_t *data);

#endif /* DTH_11_INTERFACE_H */