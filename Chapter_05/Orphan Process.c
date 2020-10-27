#include<stdio.h>
#include <unistd.h> 
#include <stdlib.h> 
#include <sys/types.h> 

int main() { 
     
    pid_t child_pid = fork(); 
    
    // Parent process  
    if (child_pid > 0){
        printf("In Parent Process.!\n");
        
    }else{
        printf("In Child process.!\n");
        // Making the Child Process to Sleep for some time.
        sleep(10);
        printf("After Sleep Time");
    }
  
    return 0; 
} 