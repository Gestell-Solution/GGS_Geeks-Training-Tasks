#ifndef RFID_PRIVATE_H_
#define RFID_PRIVATE_H_

#include <stdint.h>


/*=========MFRC522 REGISTER MAP============*/



// Command and Status Registers
#define RFID_COMMAND_REG             0x01 // Command register for controlling the MFRC522's operations
#define RFID_COM_IEN_REG             0x02 // Command interrupt enable register
#define RFID_DIV_IEN_REG             0x03 // Div interrupt enable register
#define RFID_COM_IRQ_REG             0x04 // Command interrupt request register
#define RFID_DIV_IRQ_REG             0x05 // Div interrupt request register
#define RFID_ERROR_REG               0x06 // Error register
#define RFID_STATUS1_REG             0x07 // Status register 1
#define RFID_STATUS2_REG             0x08 // Status register 2
#define RFID_FIFO_DATA_REG           0x09 // FIFO data register for reading/writing data to/from the FIFO buffer
#define RFID_FIFO_LEVEL_REG          0x0A // FIFO level register
#define RFID_WATER_LEVEL_REG         0x0B // Water level register
#define RFID_CONTROL_REG             0x0C // Control register
#define RFID_BIT_FRAMING_REG         0x0D // Bit framing register
#define RFID_COLL_REG                0x0E // Collision register


//Communication
#define RFID_MODE_REG                0x11 // Mode register
#define RFID_TX_MODE_REG             0x12 // Transmitter mode register
#define RFID_RX_MODE_REG             0x13 // Receiver mode register
#define RFID_TX_CONTROL_REG          0x14 // Transmitter control register
#define RFID_TX_ASK_REG              0x15 // Transmitter ASK register
#define RFID_TX_SEL_REG              0x16 // Transmitter selection register
#define RFID_RX_SEL_REG              0x17 // Receiver selection register
#define RFID_RX_THRESHOLD_REG        0x18 // Receiver threshold register
#define RFID_DEMOD_REG               0x19 // Demodulator register
#define RFID_SERIAL_SPEED_REG        0x1F // Serial speed register


//Configuration
#define RFID_CRC_RESULT_H_REG        0x21 // CRC result high register -->CRC IS CYCLIC REDUNDANCY CHECK USED FOR ERROR DETECTION<--
#define RFID_CRC_RESULT_L_REG        0x22 // CRC result low register
#define RFID_MOD_WIDTH_REG           0x24 // Modulation width register
#define RFID_RF_CONFIG_REG           0x26 // RF configuration register
#define RFID_GS_N_REG                0x27 // Guard time N register
#define RFID_CWGS_P_REG              0x28 // Carrier wave generation settings register
#define RFID_MOD_GS_P_REG            0x29 // Modulation guard time settings register
#define RFID_T_MODE_REG              0x2A // Timer mode register
#define RFID_T_PRESCALER_REG         0x2B // Timer prescaler register
#define RFID_T_RELOAD_H_REG          0x2C // Timer reload high register
#define RFID_T_RELOAD_L_REG          0x2D // Timer reload low register


//Test
#define RFID_TEST_SEL1_REG           0x31 // Test selection 1 register
#define RFID_TEST_SEL2_REG           0x32 // Test selection 2 register
#define RFID_TEST_PIN_EN_REG         0x33 // Test pin enable register
#define RFID_TEST_PIN_VALUE_REG      0x34 // Test pin value register
#define RFID_TEST_BUS_REG            0x35 // Test bus register
#define RFID_AUTO_TEST_REG           0x36 // Auto test register
#define RFID_VERSION_REG             0x37 // Version register
#define RFID_ANALOG_TEST_REG         0x38 // Analog test register
#define RFID_TEST_DAC1_REG           0x39 // Test DAC 1 register
#define RFID_TEST_DAC2_REG           0x3A // Test DAC 2 register
#define RFID_TEST_ADC_REG            0x3B // Test ADC register


//COMMANDS
#define RFID_CMD_IDLE                0x00 // No action, cancels current command execution
#define RFID_CMD_MEM                 0x01 // Memory command
#define RFID_CMD_GENERATE_RANDOM     0x02 // Generate random number command
#define RFID_CMD_CALC_CRC            0x03 // Calculate CRC command
#define RFID_CMD_TRANSMIT            0x04 // Transmit command
#define RFID_CMD_NO_CMD_CHANGE       0x07 // No command change
#define RFID_CMD_RECEIVE             0x08 // Receive command
#define RFID_CMD_TRANSCEIVE          0x0C // Transceive command
#define RFID_CMD_MF_AUTHENT          0x0E // Mifare authentication command
#define RFID_CMD_SOFT_RESET          0x0F // Software reset command


//COMMAND REG BITS
#define RFID_COMMAND_REG_START       4  // Used to start specific command execution
#define RFID_COMMAND_REG_POWER_DOWN  4  // Used to power down the MFRC522
#define RFID_COMMAND_REG_RCV_OFF     5  // Used to disable reception


//ERROR REG BITS
#define RFID_ERROR_WR_ERR            7  // Write error
#define RFID_ERROR_TEMP_ERR          6  // Temperature sensor error
#define RFID_ERROR_BUFFER_OVFL       4  // Buffer overflow error
#define RFID_ERROR_COLL_ERR          3  // Collision detected during communication
#define RFID_ERROR_CRC_ERR           2  // CRC Calculation error
#define RFID_ERROR_PARITY_ERR        1  // Parity error
#define RFID_ERROR_PROTOCOL_ERR      0  // Protocol error



//FIFO LEVEL REG BITS
#define RFID_FIFO_FLUSH_BIT          4 // Used to flush the FIFO buffer


//CONTROL REG BITS
#define RFID_CONTROL_T_STOP_NOW      7  // Used to stop the timer immediately
#define RFID_CONTROL_T_START_NOW     6  // Used to start the timer immediately



// BIT FRAMING REG BITS
#define RFID_BIT_FRAMING_START_SEND  7  // Used to start sending data in the FIFO buffer
#define RFID_BIT_FRAMING_RX_ALIGN2   6  // Used to set the bit position for the first bit received in the last received byte
#define RFID_BIT_FRAMING_RX_ALIGN1   5  // Used to set the bit position for the second bit received in the last received byte
#define RFID_BIT_FRAMING_RX_ALIGN0   4  // Used to set the bit position for the third bit received in the last received byte
#define RFID_BIT_FRAMING_TX_LAST2    2  // Used to set the last bit of the transmitted data
#define RFID_BIT_FRAMING_TX_LAST1    1  // Used to set the second-to-last bit of the transmitted data
#define RFID_BIT_FRAMING_TX_LAST0    0  // Used to set the third-to-last bit of the transmitted data


//TX CONTROL REG BITS
#define RFID_TX_CONTROL_TX1_RF_EN    0  // Used to enable the RF field for transmission 1
#define RFID_TX_CONTROL_TX2_RF_EN    1  // Used to enable the RF field for transmission 2



//TX ASK REG BITS
#define RFID_TX_ASK_FORCE_100ASK     6  // Used to force 100% ASK modulation for proper data transmission to the card


//MODE REG BITS
#define RFID_MODE_TX_WAIT_RF         3  // Used to wait for the RF field to be stable before transmitting data
#define RFID_MODE_CRC_PRESET0        0  // Used to preset the CRC calculation bit 0
#define RFID_MODE_CRC_PRESET1        1  // Used to preset the CRC calculation bit 1
#define RFID_MODE_CRC_PRESET2        2  // Used to preset the CRC calculation bit 2



#define RFID_SPI_READ_BIT            7  // Bit position for the read/write bit in the SPI communication protocol

#define RFID_SPI_ADDRESS_MASK        0x7E //Mask to isolate and format the address bits for SPI communication with the RFID module
#define RFID_SPI_READ_MASK           0x80 //Mask to set the read/write bit for SPI communication with the RFID module


#define RFID_SPI_WRITE_ADDRESS(Address) \
    ((uint8_t)((Address << 1) & RFID_SPI_ADDRESS_MASK)) // Macro to format the address for SPI write operation by shifting it left and masking it with RFID_SPI_ADDRESS_MASK

#define RFID_SPI_READ_ADDRESS(Address) \
    ((uint8_t)(((Address << 1) & RFID_SPI_ADDRESS_MASK) | RFID_SPI_READ_MASK)) // Macro to format the address for SPI read operation by shifting it left, masking it with RFID_SPI_ADDRESS_MASK, and setting the read/write bit to 1
  

#define RFID_PICC_REQIDL       0x26  // Request command for idle state cards
#define RFID_PICC_REQALL       0x52  // Request command for all cards
#define RFID_PICC_ANTICOLL     0x93  // Anti-collision command for card selection   
#define RFID_CMD_TRANSCEIVE    0x0C  // Transceive command for sending and receiving data
#define RFID_ERROR_MASK        0x1B  // Error mask for checking specific error conditions in the error register

#define RFID_COM_IRQ_RX       5  // Bit position for the receive interrupt request in the command interrupt request register
#define RFID_COM_IRQ_IDLE     4  // Bit position for the idle interrupt request in the command interrupt request register
#define RFID_COM_IRQ_TX       6  // Bit position for the transmit interrupt request in the command interrupt request register
#define RFID_COM_IRQ_TIMER    0  // Bit position for the timer interrupt request in the command interrupt request register


//FIFO / UID
#define RFID_FIFO_SIZE               64 // Size of the FIFO buffer in bytes
#define RFID_UID_MAX_SIZE            10 // Maximum size of the UID in bytes (4 bytes for single size, 7 bytes for double size, 10 bytes for triple size)


#endif 