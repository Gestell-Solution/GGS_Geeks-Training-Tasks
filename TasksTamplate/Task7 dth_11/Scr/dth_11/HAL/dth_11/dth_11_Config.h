/**
 * @file DTH_11_Config.h
 * @author Ali Sotohy (alielsotohy2006@gmail.com)
 * @brief  Compile-time configuration for the DHT11 driver (pin only).
 * @version 2.0.0
 * @date 2026-09-18
 * @copyright Copyright Gestell (c) 2026
 */
#ifndef DTH_11_CONFIG_H
#define DTH_11_CONFIG_H

#include "dth_11_Interface.h"

/** @brief DIO group/pin the DHT11 sensor's data line is wired to. */
#define DTH_11_PIN    DIO_Pin0   /* DHT11 Data Pin */
#define DTH_11_PORT   DIO_GroupD /* DHT11 Data Port */

#endif /* DTH_11_CONFIG_H */