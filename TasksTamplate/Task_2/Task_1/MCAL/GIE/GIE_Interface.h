/**
 * @file GIE_Interface.h
 * @brief GIE Interface public interface.
 * @details Declares the public APIs exposed by the module.
 * @version 1.0.0
 * @author Yousef
 * @date 2026-09-12
 * @copyright Copyright (c) 2026, Embedded Systems Project
 */


#ifndef _GIE_INTERFACE_H
#define _GIE_INTERFACE_H
#include "../../COMMON/Bitmath.h"
#include "../../COMMON/Definition.h"
#include "../Atmega32regmap.h"
#include "GIE_Private.h"

/**
 * @defgroup GIE_INTERFACE_H_GROUP GIE Interface definitions
 * @brief Related gie interface definitions.
 * @{
 */
/**
 * @fn GIE_Enable
 * @brief Enables the global interrupt flag.
 * @details Performs the operation required by the module while preserving the module interface.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void GIE_Enable();
/**
 * @fn GIE_Disable
 * @brief Disables the global interrupt flag.
 * @details Performs the operation required by the module while preserving the module interface.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void GIE_Disable();


/** @} */

#endif
