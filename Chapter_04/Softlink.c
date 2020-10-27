#include<stdio.h>
#include<unistd.h>

int main(){

    int link_status;
    char filepath[50], linkname[50];
    // Taking User Input for file path
    printf("Enter the filepath: ");
    scanf("%[^\n]%*c", filepath);
    printf("Enter the linkname: ");
    scanf("%[^\n]%*c", linkname);
    
    link_status = symlink(filepath,linkname);
    // 0 ---> On Success || -1 ---> If Any Error Occurs
    if(link_status == 0){
        printf("Softlink is Created Succesfully.!");
    }else{
        printf("Unable to Create the Link.");
    }

    return 0;
}

