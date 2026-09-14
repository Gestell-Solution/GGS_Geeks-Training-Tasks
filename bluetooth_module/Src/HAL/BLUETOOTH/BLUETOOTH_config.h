/**
 * @file Bluetooth_Config.h
 * @brief This file contains the configuration settings for the BLUETOOTH module.
 * @author Developer: beshoy esmat 
 * @author Reviewer : Eng/Hesham Ahmed
 * @copyright Copyright (c) 2026 , Gestell Company. All rights reserved.
 */

#ifndef _BLUETOOTH_CONFIG_H_
#define _BLUETOOTH_CONFIG_H_

#include "../../MCAL/DIO/DIO_interface.h"

/** @brief DIO group connected to the Bluetooth module's RX line. */
#define Bluetooth_RX_group Dio_groupD

/** @brief DIO pin connected to the Bluetooth module's RX line. */
#define Bluetooth_RX_pin   Dio_pin0

/** @brief DIO group connected to the Bluetooth module's TX line. */
#define Bluetooth_TX_group Dio_groupD

/** @brief DIO pin connected to the Bluetooth module's TX line. */
#define Bluetooth_TX_pin   Dio_pin1

#endif
