/**
 * File: signal_alarm.c
 * Modified by: Giovanni Guaman
 * Date: 11/5/2025
 * Brief summary of program: This program is to show how the OS can set alarm signals.
 */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


void handle_sigalarm() {
    printf("Received an alarm signal.\n");
    exit(1);
}


int main(void)
{
    //handles the alarm with a signal
    signal(SIGALRM, handle_sigalarm);
    printf("Setting the alarm for 5 seconds.\n");
    alarm(5);
    
    while(1);
}