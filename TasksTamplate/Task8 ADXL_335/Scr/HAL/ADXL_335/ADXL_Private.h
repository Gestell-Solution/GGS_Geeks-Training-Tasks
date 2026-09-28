/**
 * @file ADXL_Private.h
 * @brief Having the private defination for the ADXL Sensor driver 
 * @details This file contains the internal definitions required by ADXL Sensor driver.
 * @version 1.0.0
 * @author Ali Sotohy (alielsotohy2006@gmail.com) 
 * @date 22-09-2026 
 * @copyright Copyright (c) 2026, Gestell Company
 */


#ifndef ADXL_PRIVATE_H
#define ADXL_PRIVATE_H

/** @brief Typical sensitivity from the datasheet, in volts per g,
 *         measured at ADXL335_NOMINAL_SUPPLY_V. */
#define ADXL335_NOMINAL_SENSITIVITY   0.3f

/** @brief Supply voltage the datasheet's nominal sensitivity was measured at. */
#define ADXL335_NOMINAL_SUPPLY_V      3.3f

/**
 * @brief The ADXL335 CHIP's own analog supply voltage.
 * @warning If you're using a breakout board with an onboard 3.3V
 *          regulator, this stays 3.3f even if you feed the BOARD 5V -
 *          the sensor's analog output is ratiometric to the regulated
 *          3.3V it actually runs on, not to whatever you fed the board.
 *          Only set this to 5.0f if you're using the bare ADXL335 IC
 *          with no onboard regulator, powered directly at 5V.
 */
#define ADXL335_SUPPLY_VOLTAGE        3.3f

#endif /* ADXL335_PRIVATE_H */