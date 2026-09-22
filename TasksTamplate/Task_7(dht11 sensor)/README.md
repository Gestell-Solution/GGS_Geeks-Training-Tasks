# DHT11 Sensor Driver

## Connection
- DHT11 DATA -> PB0
- Use an external pull-up resistor (about 4.7 kOhm to 10 kOhm) from DATA to VCC.
- VCC -> 5V
- GND -> GND

The data pin can be changed from `DHT11_Config.h`.

## Driver files
- `DHT11_Config.h` : pin and timing configuration.
- `DHT11_Interface.h` : public functions and return status.
- `DHT11_Private.h` : internal frame definitions.
- `DHT11_Program.c` : driver implementation.

## Test
The included `main.c` reads the sensor every 2 seconds.
- PC0 = successful reading.
- PC1 = error.

Humidity and temperature values are stored in `Humidity` and `Temperature` in `main.c` and can be checked using the debugger.

## Frame
The DHT11 sends 5 bytes:
1. Humidity integer
2. Humidity decimal
3. Temperature integer
4. Temperature decimal
5. Checksum

Checksum = sum of the first four bytes.
