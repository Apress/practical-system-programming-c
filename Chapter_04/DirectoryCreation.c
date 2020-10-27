#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>


int main(){

    int isCreated;
    char *DIR_NAME;
    printf("Enter the Directory name you want to create: ");
    scanf("%[^\n]%*c", DIR_NAME);
    // You can Set your own permissions based on your Requirements.
    isCreated = mkdir(DIR_NAME, 0777);

    if(isCreated == 0){ // The value is 0 for Successful 
        printf("Directory is Created Succesfully\n");
    }else{  // Value is -1 if it is unsuccessful.
        printf("Unable to Create Directory\n");
    }

    return 0;
}