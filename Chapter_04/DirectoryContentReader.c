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
  
    while ((DIR_ENTRY = readdir(DIR_READER)) != NULL) 
            printf("%s\n", DIR_ENTRY->d_name); 
  
    closedir(DIR_READER);     
    return 0; 
} 
