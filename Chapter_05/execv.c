#include<stdio.h> 
#include<unistd.h> 

int main() { 

        //A null terminated array of character pointers 
        char *args[]={"./hello",NULL}; 
        execv(args[0],args); 
      
    return 0; 
} 