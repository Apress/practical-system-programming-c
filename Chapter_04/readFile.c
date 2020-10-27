#include<stdio.h> 
#include<stdlib.h>
#include<unistd.h>
#include <fcntl.h> 

int main() { 
  
  int file_descriptor, size;
  char *filename;
  char *content = (char *) calloc(100, sizeof(char)); 

  printf("Enter the filename to read:");
  scanf("%[^\n]%*c",filename);

  file_descriptor = open(filename, O_RDONLY); 
  // Program will exit if the given file not found.
  if (file_descriptor == -1) {
       perror("File Not found.");
       exit(1);
    } 
  // Helps us to read the Content from a given file descriptor.
  size = read(file_descriptor, content, 100); 

  printf("Number of bytes returned are: %d\n", size); 
  content[size] = '\0'; 
  printf("File Content: %s\n", content); 

  // Closes the file descriptor.
  close(file_descriptor);

  return 0;
} 