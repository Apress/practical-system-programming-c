#include <unistd.h>
 
int main() {

  char *binary_path = "/bin/bash";
  // Argument Array
  char *const args[] = {binary_path, "-c", "echo \"Visit $HOSTNAME:$PORT from your browser.\"", NULL};
 // Environment Variable Array
  char *const env[] = {"HOSTNAME=www.netflix.com", "PORT=80", NULL};
 
  execve(binary_path, args, env);
 
  return 0;
}