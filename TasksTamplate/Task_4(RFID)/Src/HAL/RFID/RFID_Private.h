/**
 * @file RFID_Private.h
 * @brief RFID Private private definitions and internal types.
 * @details Contains module-internal constants, register bit definitions, and private types or declarations.
 * @version 1.0.0
 * @author Yousef
 * @date 2026-09-12
 * @copyright Copyright (c) 2026, Embedded Systems Project
 */

#ifndef _RFID_PRIVATE_H
#define _RFID_PRIVATE_H

#include <stdint.h>

/* MFRC522 registers (only the ones this driver actually uses) */
/**
 * @def RFID_REG_COMMAND
 * @brief Module constant used by RFID.
 */
#define RFID_REG_COMMAND            0x01
/**
 * @defgroup RFID_PRIVATE_H_GROUP RFID Private definitions
 * @brief Related rfid private definitions.
 * @{
 */
/**
 * @def RFID_REG_COM_IRQ_EN
 * @brief Module constant used by RFID.
 */
#define RFID_REG_COM_IRQ_EN         0x02
/**
 * @def RFID_REG_COM_IRQ
 * @brief Module constant used by RFID.
 */
#define RFID_REG_COM_IRQ            0x04
/**
 * @def RFID_REG_DIV_IRQ
 * @brief Module constant used by RFID.
 */
#define RFID_REG_DIV_IRQ            0x05
/**
 * @def RFID_REG_ERROR
 * @brief Module constant used by RFID.
 */
#define RFID_REG_ERROR              0x06
/**
 * @def RFID_REG_FIFO_DATA
 * @brief Module constant used by RFID.
 */
#define RFID_REG_FIFO_DATA          0x09
/**
 * @def RFID_REG_FIFO_LEVEL
 * @brief Module constant used by RFID.
 */
#define RFID_REG_FIFO_LEVEL         0x0A
/**
 * @def RFID_REG_CONTROL
 * @brief Module constant used by RFID.
 */
#define RFID_REG_CONTROL            0x0C
/**
 * @def RFID_REG_BIT_FRAMING
 * @brief Module constant used by RFID.
 */
#define RFID_REG_BIT_FRAMING        0x0D
/**
 * @def RFID_REG_MODE
 * @brief Module constant used by RFID.
 */
#define RFID_REG_MODE               0x11
/**
 * @def RFID_REG_TX_CONTROL
 * @brief Module constant used by RFID.
 */
#define RFID_REG_TX_CONTROL         0x14
/**
 * @def RFID_REG_TX_ASK
 * @brief Module constant used by RFID.
 */
#define RFID_REG_TX_ASK             0x15
/**
 * @def RFID_REG_CRC_RESULT_MSB
 * @brief Module constant used by RFID.
 */
#define RFID_REG_CRC_RESULT_MSB     0x21
/**
 * @def RFID_REG_CRC_RESULT_LSB
 * @brief Module constant used by RFID.
 */
#define RFID_REG_CRC_RESULT_LSB     0x22
/**
 * @def RFID_REG_T_MODE
 * @brief Module constant used by RFID.
 */
#define RFID_REG_T_MODE             0x2A
/**
 * @def RFID_REG_T_PRESCALER
 * @brief SPI/Timer clock prescaler selection: RFID_REG_T_PRESCALER.
 */
#define RFID_REG_T_PRESCALER        0x2B
/**
 * @def RFID_REG_T_RELOAD_H
 * @brief Module constant used by RFID.
 */
#define RFID_REG_T_RELOAD_H         0x2C
/**
 * @def RFID_REG_T_RELOAD_L
 * @brief Module constant used by RFID.
 */
#define RFID_REG_T_RELOAD_L         0x2D

/* PCD = reader commands */
/**
 * @def PCD_IDLE
 * @brief Module constant used by PCD.
 */
#define PCD_IDLE                    0x00
/**
 * @def PCD_AUTHENT
 * @brief Module constant used by PCD.
 */
#define PCD_AUTHENT                 0x0E
/**
 * @def PCD_TRANSCEIVE
 * @brief Module constant used by PCD.
 */
#define PCD_TRANSCEIVE               0x0C
/**
 * @def PCD_RESETPHASE
 * @brief Module constant used by PCD.
 */
#define PCD_RESETPHASE              0x0F
/**
 * @def PCD_CALCCRC
 * @brief Module constant used by PCD.
 */
#define PCD_CALCCRC                 0x03

/* PICC = card commands */
/**
 * @def PICC_REQIDL
 * @brief Module constant used by PICC.
 */
#define PICC_REQIDL                 0x26   /* request idle cards      */
/**
 * @def PICC_WUPA
 * @brief Module constant used by PICC.
 */
#define PICC_WUPA                   0x52   /* wake up idle/halted cards */
/**
 * @def PICC_ANTICOLL
 * @brief Module constant used by PICC.
 */
#define PICC_ANTICOLL               0x93   /* anti-collision / UID    */
/**
 * @def PICC_HALT
 * @brief Module constant used by PICC.
 */
#define PICC_HALT                   0x50   /* put the card to sleep   */

/* --- internal helpers, not part of the public API --- */
/**
 * @fn RFID_WriteRegister
 * @brief Writes a value to an MFRC522 register.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param Reg Register address or register identifier.
 * @param Value Value to be written or configured.
 * @return void Return value of the operation.
 * @retval 0 Operation completed successfully when a status code is used.
 * @retval Non-zero Module-specific error or status code when applicable.
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
static void    RFID_WriteRegister(uint8_t Reg, uint8_t Value);
/**
 * @fn RFID_ReadRegister
 * @brief Reads a value from an MFRC522 register.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param Reg Register address or register identifier.
 * @return uint8_t Return value of the operation.
 * @retval 0 Operation completed successfully when a status code is used.
 * @retval Non-zero Module-specific error or status code when applicable.
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
static uint8_t RFID_ReadRegister(uint8_t Reg);
/**
 * @fn RFID_SetBitMask
 * @brief Sets selected bits in an MFRC522 register.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param Reg Register address or register identifier.
 * @param Mask Input parameter.
 * @return void Return value of the operation.
 * @retval 0 Operation completed successfully when a status code is used.
 * @retval Non-zero Module-specific error or status code when applicable.
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
static void    RFID_SetBitMask(uint8_t Reg, uint8_t Mask);
/**
 * @fn RFID_ClearBitMask
 * @brief Clears selected bits in an MFRC522 register.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param Reg Register address or register identifier.
 * @param Mask Input parameter.
 * @return void Return value of the operation.
 * @retval 0 Operation completed successfully when a status code is used.
 * @retval Non-zero Module-specific error or status code when applicable.
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
static void    RFID_ClearBitMask(uint8_t Reg, uint8_t Mask);
/**
 * @fn RFID_AntennaOn
 * @brief Enables the MFRC522 RF antenna.
 * @details Performs the operation required by the module while preserving the module interface.
 * @return void Return value of the operation.
 * @retval 0 Operation completed successfully when a status code is used.
 * @retval Non-zero Module-specific error or status code when applicable.
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
static void    RFID_AntennaOn(void);

/**
 * @fn RFID_ToCard
 * @brief Exchanges a command and data frame with an RFID card.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param Command Input parameter.
 * @param SendData Data value or data buffer used by the operation.
 * @param SendLen Length of the data in bytes or bits, as applicable.
 * @param BackData Data value or data buffer used by the operation.
 * @param BackLenBits Length of the data in bytes or bits, as applicable.
 * @return uint8_t Return value of the operation.
 * @retval 0 Operation completed successfully when a status code is used.
 * @retval Non-zero Module-specific error or status code when applicable.
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
static uint8_t RFID_ToCard(uint8_t Command, uint8_t *SendData, uint8_t SendLen,
                            uint8_t *BackData, uint16_t *BackLenBits);

/**
 * @fn RFID_Request
 * @brief Requests an RFID card in the field.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param ReqMode Operating mode selection.
 * @param TagType Input parameter.
 * @return uint8_t Return value of the operation.
 * @retval 0 Operation completed successfully when a status code is used.
 * @retval Non-zero Module-specific error or status code when applicable.
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
static uint8_t RFID_Request(uint8_t ReqMode, uint8_t *TagType);
/**
 * @fn RFID_Anticoll
 * @brief Performs RFID anti-collision and reads the card UID.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param SerNum Input parameter.
 * @return uint8_t Return value of the operation.
 * @retval 0 Operation completed successfully when a status code is used.
 * @retval Non-zero Module-specific error or status code when applicable.
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
static uint8_t RFID_Anticoll(uint8_t *SerNum);
/**
 * @fn RFID_CalculateCRC
 * @brief Requests CRC calculation from the MFRC522.
 * @details Performs the operation required by the module while preserving the module interface.
 * @param Data Data value or data buffer used by the operation.
 * @param Len Length of the data in bytes or bits, as applicable.
 * @param Result Input parameter.
 * @return void Return value of the operation.
 * @retval 0 Operation completed successfully when a status code is used.
 * @retval Non-zero Module-specific error or status code when applicable.
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
static void    RFID_CalculateCRC(uint8_t *Data, uint8_t Len, uint8_t *Result);

/** @} */

#endif
