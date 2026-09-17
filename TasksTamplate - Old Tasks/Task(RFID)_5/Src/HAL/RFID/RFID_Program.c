#include "RFID_Interface.h"
#include "RFID_Config.h"
#include <util/delay.h>
#include "../../MCAL/SPI/SPI_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include <stdint.h>


void RFID_Init(void)
{
    uint8_t TxControl;

// CS pin output  -->CS (Chip Select) pin is used to select the RFID module for SPI communication. It is set as an output pin to control the communication with the RFID module<---
    DIO_WritePin( RFID_CS_GROUP, RFID_CS_PIN, Output);
     
// RST pin output
    DIO_WritePin( RFID_RST_GROUP, RFID_RST_PIN, Output);
       
// CS inactive
    DIO_WritePin( RFID_CS_GROUP, RFID_CS_PIN, High);
        
// Reset RFID
    DIO_WritePin( RFID_RST_GROUP, RFID_RST_PIN, Low);

    _delay_ms(5);

    DIO_WritePin( RFID_RST_GROUP, RFID_RST_PIN, High);
        
    _delay_ms(50);

// Software reset
    RFID_WriteRegister( RFID_COMMAND_REG,RFID_CMD_SOFT_RESET);
     
    _delay_ms(50);

// Timer configuration
    RFID_WriteRegister(RFID_T_MODE_REG, 0x8D);  //0X8D to set the timer to auto-reload mode and use a 13.56 MHz clock source
    RFID_WriteRegister(RFID_T_PRESCALER_REG, 0x3E); //0X3E to set the timer prescaler to 62, which divides the clock frequency by 63 (prescaler + 1) to achieve a timer frequency of 13.56 MHz / 63 = 215.238 kHz
    RFID_WriteRegister(RFID_T_RELOAD_L_REG, 30); // Set the timer reload value to 30, which determines the duration of the timer period. The timer will count down from this value to zero before reloading and starting again.
    RFID_WriteRegister( RFID_T_RELOAD_H_REG,0); // Set the high byte of the timer reload value to 0, as the timer reload value is a 16-bit value, and the high byte is not used in this case.

// Force 100% ASK modulation so the card can read the data correctly
    RFID_WriteRegister(RFID_TX_ASK_REG,(1 << RFID_TX_ASK_FORCE_100ASK));
       

// set CRC preset configuration for error detection
    RFID_WriteRegister(RFID_MODE_REG, (1 << RFID_MODE_CRC_PRESET0) | (1 << RFID_MODE_CRC_PRESET1));
        

// Enable antenna to read current transmission control register state and check if the antenna is enabled or not. If not, enable it.
    TxControl = RFID_ReadRegister( RFID_TX_CONTROL_REG);

    if ((TxControl & 0x03) == 0)
    {
        RFID_WriteRegister( RFID_TX_CONTROL_REG,TxControl | 0x03); // Enable the antenna by setting the appropriate bits in the transmission control register
    }

}



void RFID_WriteRegister(uint8_t Address, uint8_t Data)
{
// Start communication by setting CS pin low
    DIO_WritePin( RFID_CS_GROUP, RFID_CS_PIN, Low);
       

// Write address
    SPI_Transfer((Address << 1) & 0x7E); // Shift the address left by 1 and mask it with 0x7E to ensure the read/write bit is cleared for writing

// Send data
    SPI_Transfer(Data);

// End communication by setting CS pin high
    DIO_WritePin(RFID_CS_GROUP, RFID_CS_PIN, High);
       
}


uint8_t RFID_ReadRegister(uint8_t Address)
{
   uint8_t Data;
// Start communication by setting CS pin low
    DIO_WritePin( RFID_CS_GROUP, RFID_CS_PIN, Low);

// Read address
    SPI_Transfer( ((Address << 1) & 0x7E) | 0x80); // Shift the address left by 1, mask it with 0x7E, and set the read/write bit to 1 for reading
       

// Send zero byte to receive data
    Data = SPI_Transfer(0x00);

// End communication by setting CS pin high
    DIO_WritePin( RFID_CS_GROUP, RFID_CS_PIN, High);

    return Data;
}



uint8_t RFID_GetUID(uint8_t *UID)
{
    uint8_t i;
    uint8_t IRQ;
    uint8_t Error;
    uint8_t FIFOLevel;
    uint8_t BCC;

// Enable Rx, Idle and Timer interrupts 
    RFID_WriteRegister(RFID_COM_IEN_REG, (1 << RFID_COM_IRQ_RX) | (1 << RFID_COM_IRQ_IDLE) |(1 << RFID_COM_IRQ_TIMER));
        
// Clear all interrupt flags 
    RFID_WriteRegister(RFID_COM_IRQ_REG, 0x7F);

//Flush FIFO 
    RFID_WriteRegister( RFID_FIFO_LEVEL_REG,(1 << RFID_FIFO_FLUSH_BIT));
    
//Put RC522 in Idle 
    RFID_WriteRegister(RFID_COMMAND_REG, RFID_CMD_IDLE);

//Put REQA command into FIFO 
    RFID_WriteRegister(RFID_FIFO_DATA_REG,  RFID_PICC_REQIDL);

// REQA = 7 bits 
    RFID_WriteRegister(RFID_BIT_FRAMING_REG,0X07);

//Start Transceive 
    RFID_WriteRegister(RFID_COMMAND_REG, RFID_CMD_TRANSCEIVE);

// Start sending REQA 
    RFID_WriteRegister( RFID_BIT_FRAMING_REG,  (1 << RFID_BIT_FRAMING_START_SEND) | 0x07);

//Wait for response 
    for (i = 0; i < 100; i++)
    {
        IRQ = RFID_ReadRegister(RFID_COM_IRQ_REG);

        if (IRQ & (1 << RFID_COM_IRQ_RX))
        {
            break;
        }

        if (IRQ & (1 << RFID_COM_IRQ_TIMER))
        {
            return 0;
        }
    }

// No response 
    if (i == 100)
    {
        return 0;
    }

// Check errors
    Error = RFID_ReadRegister(RFID_ERROR_REG);

    if (Error & RFID_ERROR_MASK)
    {
        return 0;
    }

// Clear FIFO 
    RFID_WriteRegister(RFID_FIFO_LEVEL_REG,(1 << RFID_FIFO_FLUSH_BIT));


// Clear interrupt flags 
    RFID_WriteRegister( RFID_COM_IRQ_REG, 0x7F);
 
// Send Anti-Collision command 
    RFID_WriteRegister( RFID_FIFO_DATA_REG, RFID_PICC_ANTICOLL);

// Cascade Level 1 
    RFID_WriteRegister(RFID_FIFO_DATA_REG,0X20);
      
// Full bytes 
    RFID_WriteRegister( RFID_BIT_FRAMING_REG, 0x00);

// Start Transceive 
    RFID_WriteRegister( RFID_COMMAND_REG, RFID_CMD_TRANSCEIVE);

// Start sending 
    RFID_WriteRegister(  RFID_BIT_FRAMING_REG, (1 << RFID_BIT_FRAMING_START_SEND));

// Wait for UID response 
    for (i = 0; i < 100; i++)
    {
        IRQ = RFID_ReadRegister(RFID_COM_IRQ_REG);

        if (IRQ & (1 << RFID_COM_IRQ_RX))
        {
            break;
        }

        if (IRQ & (1 << RFID_COM_IRQ_TIMER))
        {
            return 0;
        }
    }

// Timeout 
    if (i == 100)
    {
        return 0;
    }

// Check errors 
    Error = RFID_ReadRegister(RFID_ERROR_REG);

    if (Error & RFID_ERROR_MASK)
    {
        return 0;
    }

// Read FIFO level
    FIFOLevel = RFID_ReadRegister(RFID_FIFO_LEVEL_REG);

// 4 UID bytes + 1 BCC byte
    if (FIFOLevel < 5)
    {
        return 0;
    }

// Read UID
    for (i = 0; i < 4; i++)
    {
        UID[i] = RFID_ReadRegister(RFID_FIFO_DATA_REG);
    }

// Read BCC
    BCC = RFID_ReadRegister(RFID_FIFO_DATA_REG);

// Check BCC
    if ((UID[0] ^ UID[1] ^ UID[2] ^ UID[3]) != BCC)
    {
        return 0;
    }

// Return UID length 
    return 4;
}




