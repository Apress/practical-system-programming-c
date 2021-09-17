#include<stdio.h>
#include<fcntl.h>

int main(){

    int file_descriptor;
    char filename[50];

    printf("Enter the filename: ");
    scanf("%[^\n]%*c", filename);
    // Open file for reading.
    file_descriptor = open(filename, O_RDONLY);
    
    if(file_descriptor != -1){
        printf("%s Opened Successfully!",filename);
    }else{
        printf("Unable to Open %s",filename);
    }

    return 0;
}
