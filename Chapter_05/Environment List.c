#include<stdio.h>

int main(){

    extern char **environ;

    char **environment_list = environ;

    /* This code Helps us to prints the all the 
       Environments available in the operating system.
    */
    while(*environment_list != NULL){
        printf("%s\n", *environment_list);
        environment_list++;
    }

    return 0;
}
