#include <stdio.h>
#include<stdlib.h>
#include <signal.h>

void SIGNAL_HANDLER(int);

int main () {

    signal(SIGINT, SIGNAL_HANDLER);


    printf("Raising a new signal\n");

    int status = raise(SIGINT);

    if(status != 0){
        printf("Something went wrong Unable to raise the new signal\n");
    }
   
   return 0;
}

void SIGNAL_HANDLER(int signal) {
   printf("signal caught and handled gracefully\n");
}