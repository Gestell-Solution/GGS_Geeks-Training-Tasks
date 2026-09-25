# ADXL335 Accelerometer Driver — ATmega32

A layered, MISRA-C-style embedded driver for the **Analog Devices ADXL335**
3-axis analog accelerometer, built on top of the custom ATmega32 MCAL/HAL
stack (ADC, DIO, character LCD). Developed as Task 8 (21/9 – 25/9).

## Project layout

The project keeps the four-file driver structure used in the course:
`*_Config.h`, `*_Interface.h`, `*_Private.h`, and `*_Program.c`.

## Hardware wiring

| ADXL335 pin | Connects to |
|-------------|-------------|
| XOUT        | ADC0        |
| YOUT        | ADC1        |
| ZOUT        | ADC2        |
| VS          | 3.0 V       |
| GND         | GND         |

The ADXL335 must be powered from **1.8 V to 3.6 V**. Do not power the
sensor from the ATmega32 5 V supply.

The current configuration assumes:

- Sensor supply (VS) = **3.0 V**
- ATmega32 ADC reference = **AVCC = 5.0 V**

These are intentionally kept as two separate values in
`ADXL335_Config.h` because the sensor zero-g output depends on **VS**, while
ADC voltage conversion depends on the **ADC reference**.

## Sensor conversion model

For the default configuration:

```text
VOUT (mV) = ADC_raw * ADC_VREF_mV / 1023
VZERO     = SENSOR_VS_mV / 2
Accel(mg) = (VOUT - VZERO) * 1000 / SENSITIVITY_mV_per_g
```

At VS = 3 V, the ADXL335 datasheet gives 300 mV/g as the typical sensitivity,
with 270 mV/g minimum and 330 mV/g maximum. The zero-g output is nominally
VS/2. The sensitivity and zero-g output are ratiometric to the sensor supply.

If the actual hardware uses another sensor supply, update
`ADXL335_SENSOR_VS_MV` and the appropriate sensitivity value. If AVCC or the
ADC reference changes, update `ADXL335_ADC_VREF_MV` as well.

## Public API

```c
#include "HAL/ADXL335/ADXL335_Interface.h"

int16_t x;
int16_t y;
int16_t z;

(void)ADXL335_Init();
(void)ADXL335_ReadXYZ_mg(&x, &y, &z);
```

Returned values are signed milli-g. Approximately `+1000` means +1 g,
`0` means 0 g, and `-1000` means -1 g under the default sensitivity model.

## Notes

- The driver uses single-ended ADC polling.
- No per-device calibration of zero-g offset or sensitivity is implemented.
- The ADC timeout is a loop-count limit, not a fixed time in milliseconds.
- The DIO driver is not required for XOUT/YOUT/ZOUT because these pins are
  analog outputs connected to ADC inputs.
