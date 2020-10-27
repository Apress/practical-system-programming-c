#include<stdio.h>
#include<fcntl.h>

int main(){

    int file_descriptor;
    char *filename;

    printf("Enter the filename: ");
    scanf("%s", filename);
    // Setting Permission to Read Write for the file.
    file_descriptor = creat(filename, O_RDWR | O_CREAT);

    if(file_descriptor == 3){
        printf("File Created Successfully!");
    }else{
        printf("Unable to Create the File.");
    }

    return 0;
}
