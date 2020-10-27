#include<stdio.h>   // Standard I/O Routines Library
#include<unistd.h>  // Unix Standard Library
#include<pthread.h> // POSIX Thread Creation Library

void *customThreadFunction(){

    for(int i = 0; i < 15; i++){
        printf("I am a Custom Thread Function Created By Programmer.\n");
        sleep(1);
    }

    return NULL;
}

int main(){

    pthread_t thread;   // Thread Descriptor
    int status;         // Status Variable to store the Status of the thread.

    status = pthread_create(&thread, NULL, customThreadFunction, NULL);

    /*  status = 0 ==> If thread is created Sucessfully.
        status = 1 ==> If thread is unable to create.   */

    if(!status){
        printf("Custom Created Successfully.\n");
    }else{
        printf("Unable to create the Custom Thread.\n");
        return 0;
    }

    // Main Function For loop
    for(int i = 0; i < 15; i++){
        printf("I am the process thread created by compiler By default.\n");
        sleep(1);
    }

    return 0;
}