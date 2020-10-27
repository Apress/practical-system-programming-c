#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){

    for(int i=0; i<5; i++){
        printf("Hello World.\n");
        sleep(1);
    }

    return 0;
}
