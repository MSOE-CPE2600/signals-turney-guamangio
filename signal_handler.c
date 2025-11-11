/**
 * @file signal_handler.c
 * @brief Sets a signal handler for SIGINT, the handler prints a message and then quits
 */

/**
 * File: signal_alarm.c
 * Modified by: Giovanni Guaman
 * Date: 11/5/2025
 * Brief summary of program: this program is testing the signal handler for SIGINT.
 */


#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Signal handler for SIGINT - prints a message and exits
 */

 //Removing the signal handler function for the 2nd part of the 1st task.

// void handle_signal() {
//   printf("\nReceived a signal\n");
//   exit(1);
//  }

int main() {

    // Register for the signal
    // removing the signal handler.
    //signal(SIGINT, handle_signal);

    // Wait until a signal is received
    while(1) {
        printf("Sleeping\n");
        sleep(1);
    }

    return 0;
}