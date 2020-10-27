#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char trim(char *filename, const char *sep);

int main(){

    char old_filename[50], new_filename[50];
    printf("Enter the old filename: ");
    scanf("%[^\n]%*c", old_filename);
    printf("Enter the new filename you want to put: ");
    scanf("%[^\n]%*c",new_filename);

    
    int status = rename(old_filename, new_filename);

    if(status == 0){
        printf("Filename Changed Sucessfully.");
    }else{
        printf("Unable to change the filename.");
    }

    return 0;
}