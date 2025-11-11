/**
* File: recv_signal.c
* Modified by: Giovanni Guaman
* Date: 11/5/2025
* Brief summary of program: This is to receieve a signal from the sender.
*/

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void handler(int sig, siginfo_t *info, void *context) {
    printf("Received SIGUSR1 from PID %d from with value of %d.\n", info -> si_pid, info -> si_value.sival_int);
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

    //Tells the user that the reciever is running.
    printf("Reciever is running with PID: %d\n", getpid());
    printf("Waiting for a signal from SIGUSR1.\n");

    //cause the program to keep running while waiting for the signal.
    while(1);
}