#include <stdio.h>
#include <unistd.h>

int main() {

   int pid = fork();

   if(pid > 0){
       printf("Parent Process is created\n");
   }else if(pid == 0){
       printf("Child Process is created\n");
    }
 
   return 0;
}