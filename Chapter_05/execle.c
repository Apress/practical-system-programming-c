#include <unistd.h>
 
int main() {

  char *binary_path = "/bin/zsh";
  char *arg1 = "-c";
  char *arg2 = "echo \"Visit $HOSTNAME:$PORT from your browser.\"";
  char *const envp[] = {"HOSTNAME=www.netflix.com", "PORT=80", NULL};
  
    // execle() System call can able to access
    // the envp environment variables.

  execle(binary_path, binary_path, arg1, arg2, NULL, envp);
 
  return 0;
}