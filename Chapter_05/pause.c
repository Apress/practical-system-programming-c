#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void catchSignal(int);

int main(void){

    alarm(10);

    signal(SIGALRM, catchSignal);

    if(alarm(7) > 0){
        printf("An alarm has been set already.\n");
    }

    pause();

    printf("We will not see this text.\n");

    return 1;
}

void catchSignal(int signo){
    printf("Caught the signal with number: %d\n", signo);
    exit(0);
}

