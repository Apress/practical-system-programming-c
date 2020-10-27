#include<stdio.h>
#include<unistd.h>
#include<signal.h>

int main(){

    int pid = fork();

    if(pid == 0){
        printf("Child PID: %d\n",getpid());
    }else{
        printf("Parent PID: %d\n", getppid());
    }
    sleep(3);
    kill(getpid(), SIGQUIT);
    
    return 0;
}