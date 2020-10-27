#include<stdio.h>
#include<unistd.h> 
#include<stdlib.h>
#include<string.h>
#include <fcntl.h>

int main() { 
  
  char filename[255];
  printf("Enter the filename to open:");
  scanf("%[^\n]%*c", filename);
  int file_descriptor = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0777); 
  if (file_descriptor == -1) { 
     perror("File not Found.!"); 
     exit(1); 
  }
  char content[1024];

  printf("Enter the content to write on a given file: ");
  scanf("%[^\n]%*c", content);

  int size = write(file_descriptor, content, strlen(content)); 
  
  printf("%d %lu %d\n", file_descriptor, strlen(content), size); 
  
  close(file_descriptor); 

  return 0;
} 