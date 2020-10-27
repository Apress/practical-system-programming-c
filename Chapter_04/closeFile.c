#include<stdio.h>
#include<fcntl.h>

int close(int file_descriptor);

int main(){

    int file_descriptor;
    char *filename;

    printf("Enter the filename: ");
    scanf("%s", filename);
    // Setting Permission to Read Write for the file.
    file_descriptor = open(filename, O_RDWR, 0);

    if(file_descriptor == 3){
        printf("File Opened Successfully!\n");
    }else{
        printf("Unable to Open the File.\n");
    }

    int close_status = close(file_descriptor);

    if(close_status == 0){
        printf("File Descriptor is closed Succesfully\n");
    }else{
        printf("File Descriptor is not closed\n");
    }

    return 0;
}
