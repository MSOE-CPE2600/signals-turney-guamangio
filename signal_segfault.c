/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * File: signal_segfault.c
 * Modified by: Giovanni Guaman
 * Date: 11/5/2025
 * Brief summary of program: This is to show how a program doesn't need to crash when encountering a segmentation fault.
*/

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void handle_sigsegv() {
    printf("Received a segemantation fault.\n");
    exit(1);
}


int main (int argc, char* argv[]) {
    // Declare a null pointer
    int* i = NULL;

    // Sets the signal of segamantation violation to the signal handler function.
    signal(SIGSEGV, handle_sigsegv);
    
    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);


    // Return to exit the program
    return 0;
}