#include<stdio.h>

int main(int argc, char * argv[]){
   
    printf("Number of Arguments Passed: %d\n", argc);
    // This loop prints the all the command line values that are passed through the program
    for(int i=0;i<argc;i++){
        printf("%s\n", argv[i]);
    }

    return 0;
}