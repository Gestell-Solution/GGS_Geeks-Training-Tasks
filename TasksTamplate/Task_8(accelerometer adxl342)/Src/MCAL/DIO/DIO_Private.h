/**
 * @file DIO_Private.h
 * @brief DIO private definitions.
 * @details Contains the port group and pin identifiers used by the DIO API.
 *          The file is included by DIO_Interface.h so the identifiers are
 *          available to every user of the driver.
 * @version 1.1.0
 * @author Yousef Mohamed
 * @date 2026-09-24
 * @copyright Copyright (c) 2026, Gestell Company. All rights reserved.
 */

#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

#define Dio_GroupA      0U      /**< Port A. */
#define Dio_GroupB      1U      /**< Port B. */
#define Dio_GroupC      2U      /**< Port C. */
#define Dio_GroupD      3U      /**< Port D. */

#define Dio_Pin0        0U      /**< Pin 0 of a port. */
#define Dio_Pin1        1U      /**< Pin 1 of a port. */
#define Dio_Pin2        2U      /**< Pin 2 of a port. */
#define Dio_Pin3        3U      /**< Pin 3 of a port. */
#define Dio_Pin4        4U      /**< Pin 4 of a port. */
#define Dio_Pin5        5U      /**< Pin 5 of a port. */
#define Dio_Pin6        6U      /**< Pin 6 of a port. */
#define Dio_Pin7        7U      /**< Pin 7 of a port. */

#define Dio_AllInput    0x00U   /**< All 8 pins of the port are inputs. */
#define Dio_AllOutput   0xFFU   /**< All 8 pins of the port are outputs. */

#endif
