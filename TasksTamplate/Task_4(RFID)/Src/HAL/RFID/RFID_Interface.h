/**
 * @file RFID_Interface.h
 * @brief RFID Interface public interface.
 * @details Declares the public APIs exposed by the module.
 * @version 1.0.0
 * @author Yousef
 * @date 2026-09-12
 * @copyright Copyright (c) 2026, Embedded Systems Project
 */

#ifndef _RFID_INTERFACE_H
#define _RFID_INTERFACE_H

#include <stdint.h>

#include "../../COMMON/Definition.h"
#include "../../COMMON/Bitmath.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/SPI/SPI_Interface.h"

#include "RFID_Private.h"
#include "RFID_Config.h"

/* return codes for RFID_CheckCard() / RFID_Init() */
/**
 * @def RFID_OK
 * @brief Module constant used by RFID.
 */
#define RFID_OK          0     // card found, UID is valid
/**
 * @defgroup RFID_INTERFACE_H_GROUP RFID Interface definitions
 * @brief Related rfid interface definitions.
 * @{
 */
/**
 * @def RFID_NOTAGERR
 * @brief Module constant used by RFID.
 */
#define RFID_NOTAGERR    1     // no card in the field
/**
 * @def RFID_ERR
 * @brief Module constant used by RFID.
 */
#define RFID_ERR         2     // communication / CRC error

/**
 * @def RFID_UID_LEN
 * @brief Module constant used by RFID.
 */
#define RFID_UID_LEN     4     // UID length for Mifare Classic 1K/4K

/* Sets up the SPI pins (CS, RST) and configures the MFRC522.
 * Call this once before using any other RFID function.               */
/**
 * @fn RFID_Init
 * @brief Initializes the MFRC522 RFID reader.
 * @details Performs the operation required by the module while preserving the module interface.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void RFID_Init(void);

/* Polls for a card in the field. On RFID_OK, CardID holds the 4-byte
 * UID of the card. CardID must point to a buffer of RFID_UID_LEN.    */
/**
 * @fn RFID_CheckCard
 * @brief Checks for an RFID card and retrieves its UID.
 * @details Requests a card and performs anti-collision when a card is detected.
 * @param CardID Input parameter.
 * @return uint8_t Return value of the operation.
 * @retval 0 Operation completed successfully when a status code is used.
 * @retval Non-zero Module-specific error or status code when applicable.
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
uint8_t RFID_CheckCard(uint8_t *CardID);

/* Puts the currently selected card back to sleep (HALT state).       */
/**
 * @fn RFID_Halt
 * @brief Requests the selected RFID card to enter the HALT state.
 * @details Builds the HALT command, calculates its CRC, and transmits it to the card.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void RFID_Halt(void);

/** @} */

#endif
