#include<stdio.h>
#include<stdlib.h>

int main(){

    char *environment_name;
    printf("Enter the Environment name: ");
    scanf("%s", environment_name);

    printf("Environment Value: %s\n", getenv(environment_name));

    return 0;
    
}