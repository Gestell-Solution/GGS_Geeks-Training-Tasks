/*
 * @file    main.c
 * @brief   
 * @details 
 * @copyright Copyright (c) {year} Gestell-Co. All rights reserved.
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-09-09
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#include "Timer.h"
#include "Bluetooth.h"

/**
 * @brief Runs the Bluetooth driver test.
 */
void Bluetooth_Test(void);

int main(void)
{
    Timer_Init();
    Bluetooth_Init();

    Bluetooth_Test();

    while (1)
    {
        /* Main loop */
    }

    return 0;
}