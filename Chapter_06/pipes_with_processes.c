#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>

#define BUFFER_SIZE 1024

// Global Variables
int pipefds[2];
int status, pid;
char writemessage[BUFFER_SIZE];
char readmessage[BUFFER_SIZE];

void pipeOperation(){
    pid = fork();
    // Child Process to Read the Data.
    if(pid == 0){
        read(pipefds[0], readmessage, sizeof(readmessage));
        printf("Child Process: Reading from pipe – Message is %s", readmessage);
    }else{  // Parent Process to write the data.
        printf("Parent Process: Writing to pipe - Message is %s", writemessage);
        write(pipefds[1], writemessage, sizeof(writemessage));
    }

}

int main() {

   status = pipe(pipefds);
   if (status == -1) {
      printf("Unable to create pipe\n");
      return 1;
   }

   printf("Enter the message to write into Pipe\n");
   printf("To exit type \"quit\" \n");

   fgets(writemessage, BUFSIZ, stdin);

   while (strcmp(writemessage, "quit\n") != 0) {
        pipeOperation();
        fgets(writemessage, BUFSIZ, stdin);
        kill(pid, SIGKILL); // Killling 
    }
   
   return 0;
}