#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>

int main(){
    
    int status = fork();

    if(status == 0){
        printf("Child Process ID: %d\n", getpid());
    }else if(status > 0){
        printf("Parent Process ID: %d\n", getpid());
    }

    abort();
    printf("Due to abnormal termination this line will not execute.\n");

    return 0;
}