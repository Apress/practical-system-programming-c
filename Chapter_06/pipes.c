#include<stdio.h>
#include<string.h>
#include<unistd.h>

#define BUFFER_SIZE 1024

// Global Variables
int pipefds[2];
int status;
char writemessage[BUFFER_SIZE];
char readmessage[BUFFER_SIZE];

// pipeOperation() to perform read and write Operations.
void pipeOperation(){
   printf("Writing to pipe - Message is %s", writemessage);
   write(pipefds[1], writemessage, sizeof(writemessage));
   read(pipefds[0], readmessage, sizeof(readmessage));
   printf("Reading from pipe – Message is %s", readmessage);
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
    }

   close(pipefds[0]);
   close(pipefds[1]);
   return 0;
}

int semctl(int semid, int semnum, int cmd, …)



