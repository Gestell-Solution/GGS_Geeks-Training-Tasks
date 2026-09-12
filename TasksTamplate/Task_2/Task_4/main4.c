/**
 * @file main4.c
 * @brief Application entry point and task implementation.
 * @details Contains the application or common definitions required by the project.
 * @version 1.0.0
 * @author Yousef Mohamed <email: yousefmohammed867@gmail.com>
 * @date 2026-09-12
 * @copyright Copyright (c) 2026, Gestell Company
 */

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
    uint8_t SensorState;
    // Configure IR Sensor pin as Input
    DIO_InitPin(Dio_GroupD, Dio_Pin2, Input);
    // Configure LED pin as Output
    DIO_InitPin(Dio_GroupD, Dio_Pin3, Output);
    while(1)
    {
        // Read IR Sensor
        DIO_ReadPin(Dio_GroupD, Dio_Pin2, &SensorState);
        if(SensorState == High)
        {
            // Object detected
            DIO_WritePin(Dio_GroupD, Dio_Pin3, High);
        }
        else
        {
            // No object detected
            DIO_WritePin(Dio_GroupD, Dio_Pin3, Low);
        }
    }
    return 0;
}
