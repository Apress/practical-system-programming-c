#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>

int chmod(char *path, mode_t mode);

int main(){

    int permission_status, new_permission_value;
    char filepath[100];
    
    // Taking the Input from the user
    printf("Enter the filename with path: ");
    scanf("%[^\n]%*c", filepath);
    printf("Enter the new permission set: ");
    // Permission Set value starts with 0.
    // Eg: if i want to set 444 to a particular file then i need to give like 0444.
    scanf("%d", &new_permission_value);

    // Setting the Permissions
    permission_status = chmod(filepath, new_permission_value);
    // 0 ---> On Success || -1 ---> On Failure.
    if (permission_status == 0){
         printf("New permissions are Setted Successfully.!");
    }else{
        printf("Permissions Changed Sucessfully");
    }

    return 0;
}