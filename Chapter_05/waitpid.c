#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){

    int pid;
    int status;

    pid = fork();

    // Terminates the Child process.
    if(!pid){
        printf("My PID: %d\n",getpid()); 
        _exit(0); 
    }

    waitpid(pid,&status,WUNTRACED);

    if(WIFEXITED(status)) { 
        printf("Exit Normally\n");
        printf("Exit status: %d\n",WEXITSTATUS(status)); 
        _exit(0);
    }else { 
        printf("Exit NOT Normal\n"); 
        _exit(1);
    } 
    return 0;
}
