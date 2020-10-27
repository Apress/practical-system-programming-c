#include<stdio.h>
#include<unistd.h>

int main(){

    char DIR[75];

    printf("Working Directory Before Operation: %s\n", getcwd(DIR, 75));

    int status = chdir("..");

    if(status == 0){
        printf("Directory Changed Sucessfully.!\n");
    }else{
        printf("Unable to change the Directory.\n");
    }

     printf("Working Directory After Operation: %s\n", getcwd(DIR, 75));
    return 0;
}