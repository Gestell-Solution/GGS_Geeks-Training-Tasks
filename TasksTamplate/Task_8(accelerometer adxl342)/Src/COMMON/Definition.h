/**
 * @file Definition.h
 * @brief Common project definitions and constants.
 * @details Contains the application-wide definitions shared by all layers
 *          (logic levels, pin directions, null values and CPU clock).
 * @version 1.1.0
 * @author Yousef Mohamed
 * @date 2026-09-24
 * @copyright Copyright (c) 2026, Gestell Company. All rights reserved.
 */

#ifndef DEFINITION_H
#define DEFINITION_H

#include <stddef.h>


#define Input           0U          /**< Pin direction: input. */
#define Output          1U          /**< Pin direction: output. */

#define Low             0U          /**< Logic level low. */
#define High            1U          /**< Logic level high. */

#define Disable         0U          /**< Feature disabled. */
#define Enable          1U          /**< Feature enabled. */

#define Off             0U          /**< Switch state off. */
#define On              1U          /**< Switch state on. */

#define FlagUp          1U          /**< Flag is set. */
#define FlagDown        0U          /**< Flag is cleared. */

#define ClearRegister   0x00U       /**< Value that clears a whole 8-bit register. */

#define Null            NULL        /**< Null pointer (MISRA C:2012 Rule 11.9: NULL only). */
#define NullChar        0U          /**< String terminator value ('\\0') as unsigned 8-bit data. */

#define FCPU            8000000UL   /**< CPU clock frequency in Hz. */

#endif 
