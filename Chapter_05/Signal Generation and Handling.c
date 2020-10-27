#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void CUSTOM_HANDLER(int);

int main () {

    // SIGINT is used to intimate when any interrupt occurs to the program.
   signal(SIGINT, CUSTOM_HANDLER);

   while(1) {
      printf("Hello World...!\n");
      sleep(1); 
   }

   return 0;
}

// This function will call when any signal interrupt occurs.
void CUSTOM_HANDLER(int signum) {
   printf("\nCaught signal %d, coming out from Program\n", signum);
   exit(1);
}

