#include<stdio.h>
#include<unistd.h>

int main(){

    char WORKING_DIR[75];

    printf("Current Working Directory is: %s\n", getcwd(WORKING_DIR, 75));

    return 0;
}