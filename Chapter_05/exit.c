#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    
    int pid = fork();

    if(pid == 0){
        // Prints the Child Process ID.
        printf("Child Process ID: %d\n", getpid());
        exit(0);
    }else{
        // Prints the Parent Process ID.
        printf("Parent Process Id: %d\n", getppid());
        exit(0);
    }

    printf("Processes are exited and this line will not print\n");

    return 0;
}