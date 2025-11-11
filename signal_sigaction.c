/**
 * File: signal_sigaction.c
 * Modified by: Giovanni Guaman
 * Date: 11/5/2025
 * Brief summary of program: This program to use sigaction instead of signal to get the information from the program.
 */


#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void handler(int sig, siginfo_t *info, void *context) {
    printf("Received a signal from SIGUSR1 PID %d.\n",info -> si_pid);
    exit(1);
}

int main(void)
{
    //get the information needed from the 2nd terminal
    struct sigaction sa;
    sa.sa_sigaction = handler;
    sa.sa_flags = SA_SIGINFO;

    //uses sigaction to send more information than what signal can do.
    sigaction(SIGUSR1, &sa, NULL);

    printf("My PID is %d. Please give me SIGUSR1's ID.\n", getpid());

    while(1);
}