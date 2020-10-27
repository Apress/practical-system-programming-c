#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){

    printf("Current Running Process ID: %d\n", getpid());
    _Exit(0);
    printf("Nothing will execute\n");
    return 0;
}
