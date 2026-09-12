/**
 * @file main5.c
 * @brief Application entry point and task implementation.
 * @details Contains the application or common definitions required by the project.
 * @version 1.0.0
 * @author Yousef Mohamed <email: yousefmohammed867@gmail.com>
 * @date 2026-09-12
 * @copyright Copyright (c) 2026, Gestell Company
 */

#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/Timer0/Timer0_Interface.h"

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
    Timer0_Config_t TimerConfig =
    {
        Timer0_FastPWM,
        0,
        0,
        Timer0_OC0NinInverting,
        70
    };
    // Configure PB3 / OC0 as output
    DIO_InitPin(Dio_GroupB, Dio_Pin3, Output);
    // Initialize Timer0 in Fast PWM mode
    TIMER0_Init(TimerConfig);
    // Start Timer0 with Prescaler = 8
    TIMER0_Start(Timer0_Prescaller8);
    while (1)
    {
        // Motor speed = 70%
        TIMER0_SetPWMDutyCycle(70);
    }
    return 0;
}
