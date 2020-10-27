#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){

    pid_t status;
    status = vfork();
    printf("Process is Executing: %d\n", getpid());
    if(status == 0){
        printf("Process is executing: %d\n", getpid());
        exit(0);
    }
    
    return 0;
}