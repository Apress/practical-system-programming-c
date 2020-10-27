#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void raisedAlarm(int sig);

int main(){

    alarm(5);

    signal(SIGALRM, raisedAlarm);

    while(1){
        printf("Hello World...!\n");
        sleep(1);
    }

    return 0;
}

void raisedAlarm(int sig){
    printf("The Alarm has Raised.\n");
    exit(0);
}