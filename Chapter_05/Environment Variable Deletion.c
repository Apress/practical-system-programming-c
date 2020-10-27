#include<stdio.h>
#include<stdlib.h>

int main(){

    char *variable_name;
    printf("Enter the variable to Delete:");
    scanf("%s",variable_name);
    // Returns 0 --> On Success || -1 on failure
    int status = unsetenv(variable_name);

    if(status == 0){
        printf("Environment Variable is Deleted Successfully.!\n");
    }else{
        printf("Unable to Delete the Environment variable.\n");
    }

    return 0;
}