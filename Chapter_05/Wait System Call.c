#include<stdio.h> 
#include<unistd.h>
#include<sys/wait.h>  
  
int main() { 

    int status = fork();

    if (status == 0) {
        printf("Hello from child\n");
        printf("Child work is Completed and terminating.!\n"); 
    }else if(status > 0){ 
        printf("Hello from parent\n"); 
        wait(NULL); 
        printf("Parent has terminated\n"); 
    } 

    return 0; 
}