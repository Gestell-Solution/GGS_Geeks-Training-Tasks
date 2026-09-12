# ATmega32 → ATmega16 Migration Notes

Notes on the differences found while porting the **DIO**, **EXTI**, and **ADC** MCAL drivers from ATmega32 to ATmega16.

## Summary

| Area | Difference |
|---|---|
| Memory | ATmega16 has half the Flash/SRAM/EEPROM of ATmega32 (16KB/1KB/512B vs 32KB/2KB/1KB) |
| DIO registers | Identical (`PORTx`/`DDRx`/`PINx`, same addresses) — no driver changes needed |
| EXTI registers | Identical bit positions in `MCUCR`, `MCUCSR`, `GICR`, `GIFR` — no driver changes needed |
| ADC registers | Identical (`ADMUX`, `ADCSRA`, `ADCH`, `ADCL`, `SFIOR`) — no driver changes needed |
| **Interrupt vector numbers** | **Different** — see below |
| `MCUCR` sleep bits | `SE`/`SM2` are swapped (bit 7/6 vs bit 6/7) — not used by these drivers |

## Interrupt Vector Numbers (the actual gotcha)

Register layout is the same between the two MCUs, but each interrupt sits at a **different position in the vector table**, so any code that references a vector directly (`__vector_N`) must be updated:

| Interrupt | ATmega16 | ATmega32 |
|---|---|---|
| `INT2` | Vector 19 (`__vector_18`) | Vector 4 (`__vector_3`) |
| `ADC`  | Vector 15 (`__vector_14`) | Vector 17 (`__vector_16`) |

**Caught while migrating:** the ADC conversion-complete ISR in `ADC_Program.c` was still wired to `__vector_16` (the ATmega32 ADC vector). On ATmega16 that vector belongs to the Analog Comparator, not the ADC — so `ADC_StartConversionInterrupt()` would never trigger the callback. Fixed by changing it to `__vector_14`.

## ADC Driver — Assignment Requirement

The ADC driver (`ADC_ReadChannelPolling`) is implemented as **polling with a timeout**: it starts a conversion, polls `ADIF`, and returns `ADC_TIMEOUT` if the flag isn't set within the caller-supplied loop-count limit, instead of blocking forever.

## Bottom Line

Most of the DIO/EXTI/ADC driver code ported over unchanged since ATmega16 and ATmega32 share the same register map for these peripherals. The only thing that actually needs care on migration is **interrupt vector numbers** when interrupt-driven code is used.

## References

- [ATmega16 Datasheet](https://ww1.microchip.com/downloads/en/DeviceDoc/doc2466.pdf)
- [ATmega32 Datasheet](https://www.microchip.com/en-us/product/atmega32)
