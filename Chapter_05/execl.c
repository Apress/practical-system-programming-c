#include <unistd.h>
 
int main() {

  char *binary_path = "/bin/ls";
  char *arg1 = "-l";
  char *arg2 = "-a";
  char *arg3 = ".";
  
  // System call to perform the ls -la operation in the CWD (Current Working Directory)
  execl(binary_path, binary_path, arg1, arg2, arg3, NULL);
 
  return 0;
}

int execle(const char *path, const char *arg, ..., NULL, char * const envp[] )
