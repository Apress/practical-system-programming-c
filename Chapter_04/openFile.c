#include<stdio.h>
#include<fcntl.h>

int main(){

    int file_descriptor;
    char *filename;

    printf("Enter the filename: ");
    scanf("%s", filename);
    // Setting Permission to Read Only for the file.
    file_descriptor = open(filename, O_RDONLY);
    
    if(file_descriptor == 3){
        printf("%s Opened Successfully!",filename);
    }else{
        printf("Unable to Open %s",filename);
    }

    return 0;
}
