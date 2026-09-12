/**
 * @file main6.c
 * @brief Application entry point and task implementation.
 * @details Contains the application or common definitions required by the project.
 * @version 1.0.0
 * @author Yousef Mohamed <email: yousefmohammed867@gmail.com>
 * @date 2026-09-12
 * @copyright Copyright (c) 2026, Gestell Company
 */

#include <stdint.h>
#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/Timer0/Timer0_Interface.h"
#include "MCAL/GIE/GIE_Interface.h"

volatile uint16_t TimerTicks = 0;
volatile uint8_t DelayDone = 0;

/**
 * @fn Timer0_1SecCallback
 * @brief Executes the 1seccallback operation for Timer0.
 * @details Performs the operation required by the module while preserving the module interface.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void Timer0_1SecCallback(void)
{
    TimerTicks++;
    // CTC period = 2 ms, so 500 ticks = 1 second
    if (TimerTicks >= 500)
    {
        TimerTicks = 0;
        DelayDone = 1;
        TIMER0_Stop();
    }
}

/**
 * @fn Timer0_Delay1Sec
 * @brief Executes the delay1sec operation for Timer0.
 * @details Performs the operation required by the module while preserving the module interface.
 * @return void
 * @note Ensure module initialization is completed before calling dependent APIs.
 */
void Timer0_Delay1Sec(void)
{
    DelayDone = 0;
    TimerTicks = 0;
    TIMER0_Start(Timer0_Prescaller64);
    while (DelayDone == 0)
    {
        // Wait until 1 second is completed
    }
}

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
        Timer0_CTCMode,
        0,
        249,
        0,
        0
    };
    // Configure LED pin as output
    DIO_InitPin(Dio_GroupB, Dio_Pin1, Output);
    // Timer0 CTC: 8 MHz / 64 / 250 = 500 Hz = 2 ms
    TIMER0_Init(TimerConfig);
    TIMER0_SetCallBackFunction(Timer0_CompareMatchInterrupt, Timer0_1SecCallback);
    // Enable global interrupts
    GIE_Enable();
    while (1)
    {
        DIO_TogglePin(Dio_GroupB, Dio_Pin1);
        Timer0_Delay1Sec();
    }
    return 0;
}
