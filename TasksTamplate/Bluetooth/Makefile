MCU = atmega32
F_CPU = 8000000UL

CC = avr-gcc
OBJCOPY = avr-objcopy
SIZE = avr-size

CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Wall -Wextra -Os

TARGET = Bluetooth

SRC = Src/main.c \
      Src/Hal/Bluetooth/Bluetooth.c \
      Src/Mcal/USART/USART.c \
      Src/Mcal/Timer/Timer.c \
      Test/Bluetooth_Test.c

OBJ = $(SRC:.c=.o)

all: $(TARGET).hex

$(TARGET).elf: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@
	$(SIZE) $<

%.o: %.c
	$(CC) $(CFLAGS) -I Src/Common -I Src/Hal/Bluetooth -I Src/Mcal/USART -I Src/Mcal/Timer -c $< -o $@

clean:
	del /Q $(OBJ) $(TARGET).elf $(TARGET).hex 2>NUL