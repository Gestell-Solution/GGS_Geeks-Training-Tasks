/**
 * @file file.c
 * @brief Implementation of all bit-manipulation task functions.
 * @details Each function below preserves the exact logic and I/O behavior
 *          of the corresponding original Task_1 .. Task_15 standalone
 *          program, just moved out of main() and into its own function
 *          so it can be invoked from main.c.
 * @version 1.0.0
 * @author Yousef Mohamed <email: yousefmohammed867@gmail.com>
 * @date 2026-09-12
 * @copyright Copyright (c) 2026, Gestell Company
 */

#include <stdio.h>
#include "file.h"

/* ---------------------------------------------------------------------- */
/* Task 1: Print the LSB of a number                                      */
/* ---------------------------------------------------------------------- */
void task1_print_lsb(void) {
    int num = 0;
    int lsb = 0;

    printf("Enter a number:");
    scanf("%d", &num);
    lsb = num & 1;
    printf("the LSB of %d is %d\n", num, lsb);
}

/* ---------------------------------------------------------------------- */
/* Task 2: Print the MSB of a number                                      */
/* ---------------------------------------------------------------------- */
void task2_print_msb(void) {
    int num = 0;
    int MSB = 0;

    printf("Enter a number: ");
    scanf("%d", &num);
    MSB = (num >> 31) & 1;
    printf("The MSB of %d is: %d\n", num, MSB);
}

/* ---------------------------------------------------------------------- */
/* Task 3: Check whether the nth bit is set                               */
/* ---------------------------------------------------------------------- */
void task3_check_nth_bit(void) {
    int num = 0;
    int nth = 0;
    int result = 0;

    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Enter nth bit to check(0-31): ");
    scanf("%d", &nth);
    result = (num >> nth) & 1;
    printf("The %d bit is set to %d\n", nth, result);
}

/* ---------------------------------------------------------------------- */
/* Task 4: Set the nth bit                                                */
/* ---------------------------------------------------------------------- */
void task4_set_nth_bit(void) {
    int num = 0;
    int nth = 0;

    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Enter nth bit to set (0-31): ");
    scanf("%d", &nth);
    printf("Bit set successfully\n");
    printf("Number before setting %d bit: %d (in decimal)\n", nth, num);
    num = num | (1 << nth);
    printf("Number after setting %d bit: %d (in decimal)\n", nth, num);
}

/* ---------------------------------------------------------------------- */
/* Task 5: Clear the nth bit                                              */
/* ---------------------------------------------------------------------- */
void task5_clear_nth_bit(void) {
    int num = 0;
    int nth = 0;

    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Enter nth bit to clear (0-31): ");
    scanf("%d", &nth);
    printf("Bit cleared successfully\n");
    printf("Number before clearing %d bit: %d (in decimal)\n", nth, num);
    num = num & ~(1 << nth);
    printf("Number after clearing %d bit: %d (in decimal)\n", nth, num);
}

/* ---------------------------------------------------------------------- */
/* Task 6: Highest order set bit                                          */
/* ---------------------------------------------------------------------- */
void task6_highest_set_bit(void) {
    int num = 0;
    int highest = 0;

    printf("Enter a number: ");
    scanf("%d", &num);
    for (int i = 31; i >= 0; i--) {
        if (num & (1 << i)) {
            highest = i;
            break;
        }
    }
    printf("Highest order set bit in %d: %d\n", num, highest);
}

/* ---------------------------------------------------------------------- */
/* Task 7: Lowest order set bit                                           */
/* ---------------------------------------------------------------------- */
void task7_lowest_set_bit(void) {
    int num = 0;
    int lowest = 0;

    printf("Enter a number: ");
    scanf("%d", &num);
    for (int i = 0; i <= 31; i++) {
        if (num & (1 << i)) {
            lowest = i;
            break;
        }
    }
    printf("Lowest order set bit in %d: %d\n", num, lowest);
}

/* ---------------------------------------------------------------------- */
/* Task 8: Count zero bits                                                */
/* ---------------------------------------------------------------------- */
void task8_count_zero_bits(void) {
    int num = 0;
    int count = 0;

    printf("Enter a number :");
    scanf("%d", &num);
    for (int i = 0; i <= 31; i++) {
        if (!(num & (1 << i))) {
            count++;
        }
    }
    printf("Number of zeros bits in %d: %d\n", num, count);
}

/* ---------------------------------------------------------------------- */
/* Task 9: Count leading zeros                                            */
/* ---------------------------------------------------------------------- */
void task9_count_leading_zeros(void) {
    int num = 0;
    int count = 0;
    int i = 31;

    printf("Enter a number: ");
    scanf("%d", &num);
    while ((num & (1 << i)) == 0) {
        i--;
        count++;
    }
    printf("Total number of leading zeros in %d: %d\n", num, count);
}

/* ---------------------------------------------------------------------- */
/* Task 10: Flip all bits                                                 */
/* ---------------------------------------------------------------------- */
void task10_flip_all_bits(void) {
    int num = 0;

    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Original number: %d(in decimal)\n", num);
    for (int i = 0; i <= 31; i++) {
        num = num ^ (1 << i);
    }
    printf("Number after bits flipped: %d(in decimal)\n", num);
}

/* ---------------------------------------------------------------------- */
/* Task 11: Count zero bits and one bits                                  */
/* ---------------------------------------------------------------------- */
void task11_count_zeros_and_ones(void) {
    int num = 0;
    int zeros = 0;
    int ones = 0;

    printf("Enter a number: ");
    scanf("%d", &num);
    for (int i = 0; i <= 31; i++) {
        if (num & (1 << i)) {
            ones++;
        } else {
            zeros++;
        }
    }
    printf("Total zero bits: %d\n", zeros);
    printf("Total one bits: %d\n", ones);
}

/* ---------------------------------------------------------------------- */
/* Task 12: Rotate number left and right                                  */
/* ---------------------------------------------------------------------- */
void task12_rotate_number(void) {
    int num = 0;
    int shift_num = 0;
    int num_left = 0;
    int num_right = 0;

    printf("Enter a number: ");
    scanf("%d", &num);
    num_left = num;
    num_right = num;
    printf("Enter number of rotations: ");
    scanf("%d", &shift_num);
    for (int i = 0; i < shift_num; i++) {
        num_left = (num_left << 1) | (num_left >> 31);
        num_right = (num_right >> 1) | (num_right << 31);
    }
    printf("%d after left rotation: %d\n", num, num_left);
    printf("%d after right rotation: %d\n", num, num_right);
}

/* ---------------------------------------------------------------------- */
/* Task 13: Swap two numbers                                              */
/* ---------------------------------------------------------------------- */
void task13_swap_numbers(void) {
    int num1 = 0;
    int num2 = 0;
    int temp = 0;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    printf("Original values num1 = %d\n", num1);
    printf("Original values num2 = %d\n", num2);
    temp = num1;
    num1 = num2;
    num2 = temp;
    printf("Values after swapping num1 = %d\n", num1);
    printf("Values after swapping num2 = %d\n", num2);
}

/* ---------------------------------------------------------------------- */
/* Task 14: Check odd or even                                             */
/* ---------------------------------------------------------------------- */
void task14_check_odd_even(void) {
    int num = 0;

    printf("Enter a number: ");
    scanf("%d", &num);
    if (num & 1) {
        printf("The number %d is odd.\n", num);
    } else {
        printf("The number %d is even.\n", num);
    }
}

/* ---------------------------------------------------------------------- */
/* Task 15: Decimal to binary                                             */
/* ---------------------------------------------------------------------- */
void task15_decimal_to_binary(void) {
    int num = 0;

    printf("Enter a number: ");
    scanf("%d", &num);
    printf("converted binary of %d: ", num);
    for (int i = 31; i >= 0; i--) {
        if (num & (1 << i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
}
