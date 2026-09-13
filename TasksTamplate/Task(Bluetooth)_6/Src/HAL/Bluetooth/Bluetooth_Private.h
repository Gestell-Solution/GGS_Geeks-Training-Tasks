/**
 * @file Bluetooth_Private.h
 * @brief  This file contains the private definitions for the BLUETOOTH module.
 * @author Developer: Abdulrahman Ali 
 * @author Reviewer : Eng/Hesham Ahmed
 * @date 9/13/2026
 * @copyright Copyright (c) 2026 , Gestell Company. All rights reserved.
 * @version 1.0.0
 */

#ifndef BLUETOOTH_PRIVATE_H_
#define BLUETOOTH_PRIVATE_H_

#define BLUETOOTH_CR             '\r'
#define BLUETOOTH_LF             '\n'

typedef enum {
    BLUETOOTH_OK,
    BLUETOOTH_TIMEOUT,
    BLUETOOTH_NULL
} Bluetooth_Status_t;


#endif /* BLUETOOTH_PRIVATE_H_ */