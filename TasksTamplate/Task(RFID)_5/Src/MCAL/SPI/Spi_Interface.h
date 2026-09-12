#ifndef _SPI_INTERFACE_H
#define _SPI_INTERFACE_H
#include <stdint.h>
#include "Spi_Private.h"
#include "../../LIB/Definition.h"
#include "../../LIB/Bitmath.h"
#include "../Atmega32regmap.h"




void SPI_Init(SPI_Config_t SPI_Config);

void SPI_EnableInterrupt();

void SPI_DisableInterrupt();

uint8_t SPI_SendByteAsync(uint8_t Data);

uint8_t SPI_GetReceivedData();

uint8_t SPI_Transfer(uint8_t Data);

void SPI_SetCallBack(void (*Copy_pvCallBackFunc)(void));



#endif /* _SPI_INTERFACE_H */