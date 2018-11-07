#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handle_alarm_signal() {
    printf("in alarm\n");
}


void handle_ctrlc_signal() {
    printf("\nCTRL + C handled\n");
}

/**
 * Name: Ahmed Radwan
 * Class: CS4540
 * Assignment: 4
 */
int main(int argc, char **argv) {
    // Sleep counter
    int sc = 0;
    
    // Grab signals
    signal(SIGALRM, handle_alarm_signal);
    signal(SIGINT, handle_ctrlc_signal);
    
    // 20->19->18->17
    alarm(3);
    sc = sleep(20);

    printf("Seconds after interrupt: %d\n", sc);
    fflush(stdout); // Force printf

    // 20->19->18
    alarm(2);
    sc = sleep(20);

    printf("Seconds after interrupt: %d\n", sc);
    fflush(stdout); // Force printf
    
    // Pause program to hit "ctrl + c"
    pause();
    printf("Returned to main!\n");
    return 0;
}