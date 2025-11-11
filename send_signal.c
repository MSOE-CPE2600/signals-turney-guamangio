/**
* File: send_signal.c
* Modified by: Giovanni Guaman
* Date: 11/5/2025
* Brief summary of program: This program sends a signal to the reciever to communicate.
*/

//I have made sure to make a random number generator that is sent to the reciever.

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>


int main(int argc, char *argv[])
{
    if(argc != 2){
        //please insert the PID 
        printf(" Please use put the code in this format with the PID number: %s <PID>\n", argv[0]);
        return 1;
    }
    //sets the random number by seed the number generator.
    srand((unsigned)time(NULL));
    int randomValue = rand();

    // converts the pid from where it came from into a string
    int pid = atoi(argv[1]);

    //union the signal value to be able to send over a number with the other terminals signal.
    union sigval usig;
    //value that is going to be sent over
    usig.sival_int = randomValue;

    //tells user it's sending the number to the other terminal
    printf("Sending value %d to PID %d\n", usig.sival_int, pid);

    //use sigqueue to send the values back to the reciever, and if it doesn't work it will tell user the queue failed.
    if(sigqueue(pid, SIGUSR1, usig) == -1)
    {
        perror("sigqueue failed");
        return 1;
    }

    return 0;
}