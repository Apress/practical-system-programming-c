#include <stdio.h>
#include<stdlib.h> 
#include <dirent.h> 
  
int main() {
    // Directory Entry
    struct dirent *DIR_ENTRY;
  
    // opendir() returns a pointer of DIR type.  
    DIR *DIR_READER = opendir("."); 
  
    if (DIR_READER == NULL) { 
        printf("Could not open current directory" ); 
        exit(0);
    } 

    int status = closedir(DIR_READER);     
    if(status == 0){
        printf("Directory Closed Successfully.!");
    }else{
        printf("Unable to close the Directory.");
    }
    return 0; 
} 
