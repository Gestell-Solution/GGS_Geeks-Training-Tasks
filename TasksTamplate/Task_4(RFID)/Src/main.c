/**
 * @file main.c
 * @brief Application entry point and task implementation.
 * @details Contains the application or common definitions required by the project.
 * @version 1.0.0
 * @author Yousef Mohamed <email: yousefmohammed867@gmail.com>
 * @date 2026-09-12
 * @copyright Copyright (c) 2026, Gestell Company
 */

#include "COMMON/Definition.h"
#include "COMMON/Bitmath.h"
#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/SPI/SPI_Interface.h"
#include "HAL/RFID/RFID_Interface.h"

/* LED on PORTA pin0, lights up when a card is detected */
/**
 * @def LED_GROUP
 * @brief Definition for LED_GROUP.
 */
#define LED_GROUP   Dio_GroupA
/**
 * @def LED_PIN
 * @brief Definition for LED_PIN.
 */
#define LED_PIN     Dio_Pin0

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
    uint8_t CardID[RFID_UID_LEN];
    uint8_t Status;

    SPI_Config_t SPI_Config;
    SPI_Config.ModeSelect    = Master_mode;
    SPI_Config.DataOrder     = MSB_First;
    SPI_Config.ClockPolarity = SPI_CPOL_LOW;
    SPI_Config.ClockPhase    = SPI_SAMPLE_LEADING;
    SPI_Config.ClockRate     = SPI_Prescaller16_NormalSpeed;

    DIO_InitPin(LED_GROUP, LED_PIN, Output);
    DIO_WritePin(LED_GROUP, LED_PIN, Low);

    /* SPI_Init() configures the ATmega32 hardware SPI pins. */
    SPI_Init(SPI_Config);
    RFID_Init();

    while (1)
    {
        Status = RFID_CheckCard(CardID);

        if (Status == RFID_OK)
        {
            /* card found -> turn the LED on */
            DIO_WritePin(LED_GROUP, LED_PIN, High);

            RFID_Halt();
        }
        else
        {
            DIO_WritePin(LED_GROUP, LED_PIN, Low);
        }
    }
}
