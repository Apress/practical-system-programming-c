#include<stdio.h>
#include<unistd.h>

int main(){

    int unlink_status;
    char linkname[100];
    // Taking the Link name as Input from the user to unlink
    printf("Enter the link name to unlink:");
    scanf("%[^\n]%*c", linkname);

    unlink_status = unlink(linkname);
    // 0 --->On Success || -1 ---> Failure.
    if(unlink_status == 0){
        printf("File is unlinked Successfully.!");
    }else{
        printf("Unable to unlink the file.");
    }

    return 0;
}
