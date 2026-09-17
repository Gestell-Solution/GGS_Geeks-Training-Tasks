#include "MCAL/SPI/SPI_Interface.h"
#include "MCAL/UART/UART_Interface.h"
#include "HAL/RFID/RFID_Interface.h"
#include <util/delay.h>

int main(void)
{
uint8_t UID[5];
uint8_t uidSize=0;

SPI_Config_t SPI_Config = {
    .ModeSelect = SPI_MASTER_MODE,
    .SizeCharacterSelect = 8,
    .DataOrder = MSB,
    .ClockPolarity = Leading_Edge_First,
    .CLockPhase = SPI_SAMPLE_LEADING,
    .ClockRate = SPI_Prescaller16,
    .SpeedMode = SPI_NormalSpeed,
};

Uart_Config_t UART_Config = {
    .ModeSelect = Uart_AsynchronousMode,
    .StopBitSelect = Uart_1StopBit,
    .ParitySelect = 0,
    .SizeCharacterSelect = Uart_8BitSize,
    .BaudRate = 9600,
    .EnbaleSelect = 0,
    .SpeedMode= Uart_NormalSpeed,
    .InterruptSelect = 0
};
RFID_Init();
SPI_Init(SPI_Config);   
UART_Init(UART_Config);

UART_SendStringPolling((uint8_t*)"RFID Reader Initialized\n");

while (1) {
  uidSize = RFID_GetUID(UID);
  if (uidSize > 0) {
    UART_SendStringPolling((uint8_t*)"UID: ");
    for (uint8_t i = 0; i < uidSize; i++) {
        char buffer[3];
      UART_SendStringPolling((uint8_t*)buffer);
    }
  } else {
    UART_SendStringPolling((uint8_t*)"No Card Detected\n");
  }
_delay_ms(1000); // Delay for 1 second before checking again   
UART_SendStringPolling((uint8_t*)"Checking for Card...\n");
}

    return 0;
}