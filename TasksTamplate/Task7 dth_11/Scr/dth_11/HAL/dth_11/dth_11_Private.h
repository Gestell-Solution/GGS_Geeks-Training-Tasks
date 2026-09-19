/**
 * @file DTH_11_Private.h
 * @author Ali Sotohy (alielsotohy2006@gmail.com)
 * @brief  Private (non-configurable) constants for the DHT11 driver.
 * @version 2.0.0
 * @date 2026-09-18
 * @copyright Copyright Gestell (c) 2026
 */
#ifndef DTH_11_PRIVATE_H
#define DTH_11_PRIVATE_H

/** @brief Start-signal low time required by the DHT11 datasheet, in
 *         MILLISECONDS - used with _delay_ms(), not _delay_us(). */
#define DTH_11_ReqestTime       18U

/** @brief Release time before switching the pin to input, in MICROSECONDS. */
#define DTH_11_Receivedtime     30U

/** @brief Loop-iteration timeout guard for every busy-wait, so a
 *         disconnected/faulty sensor can never hang the MCU forever. */
#define DTH_11_MaxTimeOut     50000U

/**
 * @brief Loop-iteration threshold that decides whether a bit's high
 *        pulse was a logic 0 (short) or logic 1 (long).
 * @warning This is NOT a real time unit - it depends on your clock
 *          speed and compiler optimization level. Calibrate it on your
 *          actual board (see the calibration build) before trusting
 *          any reading - do not assume this default is correct.
 */
#define DTH_11_BitThreshold   8U

/** @brief One DHT11 frame is 5 bytes / 40 bits:
 *         [0] Humidity int  [1] Humidity dec (always 0)
 *         [2] Temp int      [3] Temp dec (always 0)
 *         [4] Checksum = ([0]+[1]+[2]+[3]) & 0xFF */
#define DTH_11_FrameBytes   5U
#define DTH_11_FrameBits    40U

#endif /* DTH_11_PRIVATE_H */