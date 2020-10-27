#include<stdio.h>
#include<unistd.h>


int main(){

    int link_status;

    char filepath[50], linkname[50];
    printf("Enter the filename: ");
    scanf("%[^\n]%*c", filepath);
    printf("Enter the linkname: ");
    scanf("%[^\n]%*c", linkname);

    link_status = link(filepath, linkname);
    // Hardlink will be Created.
    // 0 ---> Successful || -1 ---> Failure.

    if(link_status == 0){
        printf("HardLink is Created Succesfully.!");
    }else{
        printf("Unable to Create the Hard Link.");
    }

    return 0;
}