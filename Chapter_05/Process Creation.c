#include <stdio.h>
#include <unistd.h>
#include<stdlib.h>

int main() {

   int pid, my_pid, my_parent_pid;
   pid = getpid();
   printf("Before fork: Process id is %d\n", pid);

   pid = fork();

   if (pid < 0) {
      perror("Unable to create the process.\n");
      exit(1);
   }

   // Child process
   if (pid == 0) {
      printf("This is child process\n");
      my_pid = getpid();
      my_parent_pid = getppid();
      printf("Process id is %d and PPID is %d\n", my_pid, my_parent_pid);
   } else { // Parent process 
      sleep(1);
      printf("This is parent process\n");
      my_pid = getpid();
      my_parent_pid = getppid();
      printf("Process id is %d and PPID is %d\n", my_pid, my_parent_pid);
      printf("Newly created process id or child pid is %d\n", pid);
   }

   return 0;
}