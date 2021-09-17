#include<stdio.h>
#include<fcntl.h>

int main(){

    int file_descriptor;
    char filename[50];

    printf("Enter the filename: ");
    scanf("%[^\n]s*c", filename);
    // Setting Permission in 3rd argument only take effect if file not yet exists
    file_descriptor = creat(filename, O_RDWR | O_CREAT, 0600);

    if(file_descriptor != -1){
        printf("File Created Successfully!");
    }else{
        printf("Unable to Create the File.");
    }

    return 0;
}
