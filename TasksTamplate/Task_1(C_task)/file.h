/**
 * @file file.h
 * @brief Public interface for all bit-manipulation task functions.
 * @details Declares every task function implemented in file.c so that
 *          main.c (or any other translation unit) can call them after
 *          including this header. Each function corresponds 1:1 to one
 *          of the original Task_1 .. Task_15 programs, with the same
 *          input/output behavior preserved.
 * @version 1.0.0
 * @author Yousef Mohamed <email: yousefmohammed867@gmail.com>
 * @date 2026-09-12
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef FILE_H
#define FILE_H

/**
 * @fn task1_print_lsb
 * @brief Reads an integer from the user and prints its LSB (Least Significant Bit).
 * @details Equivalent to the original Task_1 program.
 * @return void
 */
void task1_print_lsb(void);

/**
 * @fn task2_print_msb
 * @brief Reads an integer from the user and prints its MSB (Most Significant Bit, bit 31).
 * @details Equivalent to the original Task_2 program.
 * @return void
 */
void task2_print_msb(void);

/**
 * @fn task3_check_nth_bit
 * @brief Reads an integer and a bit index, then prints whether that bit is set.
 * @details Equivalent to the original Task_3 program.
 * @return void
 */
void task3_check_nth_bit(void);

/**
 * @fn task4_set_nth_bit
 * @brief Reads an integer and a bit index, then sets that bit and prints before/after.
 * @details Equivalent to the original Task_4 program.
 * @return void
 */
void task4_set_nth_bit(void);

/**
 * @fn task5_clear_nth_bit
 * @brief Reads an integer and a bit index, then clears that bit and prints before/after.
 * @details Equivalent to the original Task_5 program.
 * @return void
 */
void task5_clear_nth_bit(void);

/**
 * @fn task6_highest_set_bit
 * @brief Reads an integer and prints the index of its highest-order set bit.
 * @details Equivalent to the original Task_6 program.
 * @return void
 */
void task6_highest_set_bit(void);

/**
 * @fn task7_lowest_set_bit
 * @brief Reads an integer and prints the index of its lowest-order set bit.
 * @details Equivalent to the original Task_7 program.
 * @return void
 */
void task7_lowest_set_bit(void);

/**
 * @fn task8_count_zero_bits
 * @brief Reads an integer and prints how many of its 32 bits are zero.
 * @details Equivalent to the original Task_8 program.
 * @return void
 */
void task8_count_zero_bits(void);

/**
 * @fn task9_count_leading_zeros
 * @brief Reads an integer and prints its number of leading zero bits.
 * @details Equivalent to the original Task_9 program.
 * @return void
 */
void task9_count_leading_zeros(void);

/**
 * @fn task10_flip_all_bits
 * @brief Reads an integer, flips all of its bits, and prints the result.
 * @details Equivalent to the original Task_10 program.
 * @return void
 */
void task10_flip_all_bits(void);

/**
 * @fn task11_count_zeros_and_ones
 * @brief Reads an integer and prints its total count of zero bits and one bits.
 * @details Equivalent to the original Task_11 program.
 * @return void
 */
void task11_count_zeros_and_ones(void);

/**
 * @fn task12_rotate_number
 * @brief Reads an integer and a rotation count, then prints it rotated left and right.
 * @details Equivalent to the original Task_12 program.
 * @return void
 */
void task12_rotate_number(void);

/**
 * @fn task13_swap_numbers
 * @brief Reads two integers and prints them after swapping their values.
 * @details Equivalent to the original Task_13 program.
 * @return void
 */
void task13_swap_numbers(void);

/**
 * @fn task14_check_odd_even
 * @brief Reads an integer and prints whether it is odd or even.
 * @details Equivalent to the original Task_14 program.
 * @return void
 */
void task14_check_odd_even(void);

/**
 * @fn task15_decimal_to_binary
 * @brief Reads an integer and prints its 32-bit binary representation.
 * @details Equivalent to the original Task_15 program.
 * @return void
 */
void task15_decimal_to_binary(void);

#endif /* FILE_H */
