#include<stdio.h>
#include<stdlib.h>

int main(){

    char variable_name[15];
    char variable_value[255];
    int overwrittenValue;
    printf("Enter your Variable name:");
    scanf("%s", variable_name);
    printf("Enter the Variable Value: ");
    scanf("%s", variable_value);
    
    // 1 ---> Represents the Overridden of Value.
    // 0 ---> Doesn't override the value
    printf("Enter the Overridden Value: ");
    scanf("%d", &overwrittenValue);

    // Returns 0 --> On Success || -1 on failure
    int status = setenv(variable_name, variable_value, overwrittenValue);

    if(status == 0){
        printf("Environment variable Created Successfully.!\n");
    }else if(status == -1){
        printf("Environment variable Created Successfully.!\n");
    }

    return 0;
}