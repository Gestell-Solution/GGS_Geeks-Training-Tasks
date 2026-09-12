/**
 * @file RFID_Config.h
 * @brief RFID Config configuration definitions.
 * @details Contains configuration values used to adapt the module to the target hardware.
 * @version 1.0.0
 * @author Yousef
 * @date 2026-09-12
 * @copyright Copyright (c) 2026, Embedded Systems Project
 */

#ifndef _RFID_CONFIG_H
#define _RFID_CONFIG_H

#include "../../MCAL/DIO/DIO_Private.h"

/* SDA / CS pin of the module */
/**
 * @def RFID_CS_GROUP
 * @brief Module constant used by RFID.
 */
#define RFID_CS_GROUP     Dio_GroupB
/**
 * @defgroup RFID_CONFIG_H_GROUP RFID Config definitions
 * @brief Related rfid config definitions.
 * @{
 */
/**
 * @def RFID_CS_PIN
 * @brief Module constant used by RFID.
 */
#define RFID_CS_PIN       Dio_Pin4

/* RST pin of the module */
/**
 * @def RFID_RST_GROUP
 * @brief Module constant used by RFID.
 */
#define RFID_RST_GROUP    Dio_GroupB
/**
 * @def RFID_RST_PIN
 * @brief Module constant used by RFID.
 */
#define RFID_RST_PIN      Dio_Pin3

/** @} */

#endif
