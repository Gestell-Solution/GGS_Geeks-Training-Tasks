/**
 * @file main.c
 * @brief Application entry point.
 * @details Presents a menu of all bit-manipulation tasks (Task_1 .. Task_15)
 *          and dispatches to the corresponding function declared in file.h
 *          and implemented in file.c. Replaces the old layout where every
 *          task lived in its own folder with its own main().
 * @version 1.0.0
 * @author Yousef Mohamed <email: yousefmohammed867@gmail.com>
 * @date 2026-09-12
 * @copyright Copyright (c) 2026, Gestell Company
 */

#include <stdio.h>
#include "file.h"

/**
 * @fn print_menu
 * @brief Prints the list of available tasks to the console.
 * @return void
 */
static void print_menu(void) {
    printf("\n===================================\n");
    printf("      Bit Manipulation Tasks\n");
    printf("===================================\n");
    printf(" 1.  Print LSB of a number\n");
    printf(" 2.  Print MSB of a number\n");
    printf(" 3.  Check if the nth bit is set\n");
    printf(" 4.  Set the nth bit\n");
    printf(" 5.  Clear the nth bit\n");
    printf(" 6.  Get highest order set bit\n");
    printf(" 7.  Get lowest order set bit\n");
    printf(" 8.  Count zero bits\n");
    printf(" 9.  Count leading zeros\n");
    printf("10.  Flip all bits\n");
    printf("11.  Count zero bits and one bits\n");
    printf("12.  Rotate number left/right\n");
    printf("13.  Swap two numbers\n");
    printf("14.  Check if a number is odd or even\n");
    printf("15.  Convert decimal number to binary\n");
    printf(" 0.  Exit\n");
    printf("===================================\n");
    printf("Enter your choice: ");
}

/**
 * @fn main
 * @brief Application entry point.
 * @details Loops, showing the menu and running the chosen task, until the
 *          user chooses to exit (option 0).
 * @return int 0 on successful (normal) program termination.
 */
int main(void) {
    int choice = -1;

    while (choice != 0) {
        print_menu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:  task1_print_lsb();              break;
            case 2:  task2_print_msb();               break;
            case 3:  task3_check_nth_bit();           break;
            case 4:  task4_set_nth_bit();             break;
            case 5:  task5_clear_nth_bit();           break;
            case 6:  task6_highest_set_bit();         break;
            case 7:  task7_lowest_set_bit();          break;
            case 8:  task8_count_zero_bits();         break;
            case 9:  task9_count_leading_zeros();     break;
            case 10: task10_flip_all_bits();          break;
            case 11: task11_count_zeros_and_ones();   break;
            case 12: task12_rotate_number();          break;
            case 13: task13_swap_numbers();           break;
            case 14: task14_check_odd_even();         break;
            case 15: task15_decimal_to_binary();      break;
            case 0:  printf("Goodbye!\n");            break;
            default: printf("Invalid choice, please try again.\n"); break;
        }
    }

    return 0;
}
