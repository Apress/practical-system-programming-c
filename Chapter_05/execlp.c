#include <unistd.h>
 
int main() {

  char *binary_executable = "ls";
  char *arg1 = "-lq";
  char *arg2 = ".";
  
  // System call to perform the ls -la operation in the
  // CWD (Current Working Directory)
  execlp(binary_executable, binary_executable, arg1, arg2, NULL);
 
  return 0;
}