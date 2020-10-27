#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>

int rmdir(char *dirname);

int main(){

    int isRemoved;
    char *DIR_NAME;
    printf("Enter the Directory name you want to create: ");
    scanf("%[^\n]%*c", DIR_NAME);
    isRemoved = rmdir(DIR_NAME);

    if(isRemoved == 0){ // The value is 0 for Successful 
        printf("Directory is Deleted Succesfully\n");
    }else{  // Value is -1 if it is unsuccessful.
        printf("Unable to Delete Directory\n");
    }

    return 0;
}