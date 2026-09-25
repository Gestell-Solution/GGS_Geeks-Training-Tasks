/**
 * @file ADXL335_Program.c
 * @brief ADXL335 accelerometer driver implementation.
 * @details Implements the ADXL335 analog accelerometer driver on top of the
 *          MCAL ADC driver. The conversion follows the electrical data
 *          specified by the Analog Devices ADXL335 datasheet.
 * @version 1.1.0
 * @author Yousef Mohamed
 * @date 2026-09-25
 * @copyright Copyright (c) 2026, Gestell Company. All rights reserved.
 */

#include "ADXL335_Interface.h"
#include "ADXL335_Config.h"
#include "ADXL335_Private.h"

#include "../../MCAL/ADC/ADC_Interface.h"
#include "../../COMMON/Definition.h"

/**
 * @brief Select the ADC channel associated with an ADXL335 axis.
 * @param[in] Axis ADXL335 axis selector.
 * @return ADC channel connected to the selected axis.
 */
static uint8_t ADXL335_GetChannel(uint8_t Axis)
{
    uint8_t channel = ADXL335_X_CHANNEL;

    if (Axis == ADXL335_AXIS_Y)
    {
        channel = ADXL335_Y_CHANNEL;
    }
    else if (Axis == ADXL335_AXIS_Z)
    {
        channel = ADXL335_Z_CHANNEL;
    }
    else
    {
        channel = ADXL335_X_CHANNEL;
    }

    return channel;
}

/**
 * @brief Convert a raw ADC result to signed acceleration in milli-g.
 * @param[in] RawValue 10-bit ADC result.
 * @return Signed acceleration in milli-g.
 */
static int16_t ADXL335_ConvertToMilliG(uint16_t RawValue)
{
    int32_t voltage_mv;
    int32_t zero_g_mv;
    int32_t acceleration_mg;

    /* VOUT = ADC * ADC_VREF / 1023. */
    voltage_mv = ((int32_t)RawValue * (int32_t)ADXL335_ADC_VREF_MV) /
                 (int32_t)ADXL335_ADC_MAX_VALUE;

    /* At 0 g, ADXL335 output is nominally VS/2. */
    zero_g_mv = (int32_t)(ADXL335_SENSOR_VS_MV / ADXL335_ZERO_G_DIVISOR);

    /* Acceleration (g) = (VOUT - VZERO) / sensitivity. */
    acceleration_mg =
        ((voltage_mv - zero_g_mv) * ADXL335_MV_PER_V) /
        (int32_t)ADXL335_SENSITIVITY_MV_PER_G;

    return (int16_t)acceleration_mg;
}

/**
 * @brief Initialize the ADXL335 ADC interface.
 * @return ADXL335_OK after configuring the ADC.
 */
uint8_t ADXL335_Init(void)
{
    Adc_Config_t adc_config;

    adc_config.ReferenceSelection = ADXL335_ADC_REFERENCE;
    adc_config.AdjustResult = Adc_RightAdjust;
    adc_config.AutomaticMode = SingleMode;
    adc_config.TriggerSource = Adc_FreeRunning;
    adc_config.InterruptState = Disable;
    adc_config.PrescallerSelection = ADXL335_ADC_PRESCALER;

    ADC_Init(adc_config);

    return ADXL335_OK;
}

/**
 * @brief Read the raw ADC value of one ADXL335 axis.
 * @param[in] Axis Axis selector.
 * @param[out] RawValue Pointer to receive the ADC result.
 * @return ADXL335_OK on success; ADXL335_ERROR otherwise.
 */
uint8_t ADXL335_ReadRaw(uint8_t Axis, uint16_t *RawValue)
{
    uint16_t adc_value;

    if ((ADXL335_IS_AXIS_VALID(Axis) == 0U) || (RawValue == Null))
    {
        return ADXL335_ERROR;
    }

    adc_value = ADC_ReadChannelPolling(ADXL335_GetChannel(Axis),
                                       ADXL335_ADC_TIMEOUT);

    if ((adc_value == ADC_TIMEOUT) || (adc_value == ADC_ERROR))
    {
        return ADXL335_ERROR;
    }

    *RawValue = adc_value;

    return ADXL335_OK;
}

/**
 * @brief Read acceleration of one ADXL335 axis in milli-g.
 * @param[in] Axis Axis selector.
 * @param[out] Acceleration Pointer to receive signed acceleration.
 * @return ADXL335_OK on success; ADXL335_ERROR otherwise.
 */
uint8_t ADXL335_ReadAxis_mg(uint8_t Axis, int16_t *Acceleration)
{
    uint16_t raw_value;
    uint8_t status;

    if (Acceleration == Null)
    {
        return ADXL335_ERROR;
    }

    status = ADXL335_ReadRaw(Axis, &raw_value);

    if (status == ADXL335_OK)
    {
        *Acceleration = ADXL335_ConvertToMilliG(raw_value);
    }

    return status;
}

/**
 * @brief Read X, Y and Z acceleration in milli-g.
 * @param[out] X Pointer to receive X-axis acceleration.
 * @param[out] Y Pointer to receive Y-axis acceleration.
 * @param[out] Z Pointer to receive Z-axis acceleration.
 * @return ADXL335_OK on success; ADXL335_ERROR otherwise.
 */
uint8_t ADXL335_ReadXYZ_mg(int16_t *X, int16_t *Y, int16_t *Z)
{
    uint8_t status;

    if ((X == Null) || (Y == Null) || (Z == Null))
    {
        return ADXL335_ERROR;
    }

    status = ADXL335_ReadAxis_mg(ADXL335_AXIS_X, X);

    if (status == ADXL335_OK)
    {
        status = ADXL335_ReadAxis_mg(ADXL335_AXIS_Y, Y);
    }

    if (status == ADXL335_OK)
    {
        status = ADXL335_ReadAxis_mg(ADXL335_AXIS_Z, Z);
    }

    return status;
}
