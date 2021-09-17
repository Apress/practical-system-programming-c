#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){

    int file_descriptor;
    char filename[50];

    printf("Enter the filename: ");
    scanf("%[^\n]%*c", filename);
    // Opening for read and write (3rd argument ignored as there is no O_CREAT)
    file_descriptor = open(filename, O_RDWR, 0);

    if(file_descriptor != -1){
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
