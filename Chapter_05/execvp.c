#include<stdio.h> 
#include<unistd.h> 

int main() { 

        //A null terminated array of character pointers 
        char *program_name = "ls";
        char *args[]={program_name,"-la", ".", NULL}; 
        execvp(program_name,args); 
      
    return 0; 
} 