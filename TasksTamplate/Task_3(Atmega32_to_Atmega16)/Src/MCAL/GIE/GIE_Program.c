/**
 * @file GIE_Program.c
 * @brief GIE Program driver implementation.
 * @details Contains the implementation of the module APIs and internal helper functions.
 * @version 1.0.0
 * @author Yousef
 * @date 2026-09-12
 * @copyright Copyright (c) 2026, Embedded Systems Project
 */

#include "GIE_Interface.h"



/**
 * @fn GIE_Enable
 * @brief Enables the global interrupt flag.
 * @details Performs the operation required by the module while preserving the module interface.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void GIE_Enable()
{
    SetBit(SREG_Reg,I_Bit);
}
/**
 * @fn GIE_Disable
 * @brief Disables the global interrupt flag.
 * @details Performs the operation required by the module while preserving the module interface.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void GIE_Disable()
{
    ClearBit(SREG_Reg,I_Bit);
}
