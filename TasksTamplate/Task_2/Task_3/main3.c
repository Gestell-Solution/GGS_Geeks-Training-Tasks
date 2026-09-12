/**
 * @file main3.c
 * @brief Application entry point and task implementation.
 * @details Contains the application or common definitions required by the project.
 * @version 1.0.0
 * @author Yousef Mohamed <email: yousefmohammed867@gmail.com>
 * @date 2026-09-12
 * @copyright Copyright (c) 2026, Gestell Company
 */

#include <util/delay.h>
#include "MCAL/DIO/DIO_Interface.h"

/**
 * @fn main
 * @brief Application entry point.
 * @details Performs the operation required by the module while preserving the module interface.
 * @return int Return value of the operation.
 * @retval 0 Operation completed successfully when a status code is used.
 * @retval Non-zero Module-specific error or status code when applicable.
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
int main(void)
{
    // Configure PA2 as Output
    DIO_InitPin(Dio_GroupA, Dio_Pin2, Output);

    while(1)
    {
        // Turn Buzzer ON
        DIO_WritePin(Dio_GroupA, Dio_Pin2, High);
        // 1-second pulse
        _delay_ms(1000);
        // Turn Buzzer OFF
        DIO_WritePin(Dio_GroupA, Dio_Pin2, Low);
        // Wait before next pulse
        _delay_ms(1000);
    }
    return 0;
}
