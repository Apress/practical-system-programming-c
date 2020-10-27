#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

// Global Data variables.
int a = 5, b = 7;

// Function that access the global data.
void* add_two_numbers(void* arg){
    a = a + 3;
    b = b - 1;
    printf("a value is: %d and ", a);
    printf("b value is: %d\n", b);
    sleep(1);
    exit(0);
}

int main(){

    // Creating the thread instances.
    pthread_t t1, t2, t3;

    pthread_create(&t1, NULL, add_two_numbers, NULL);
    pthread_create(&t2, NULL, add_two_numbers, NULL);
    pthread_create(&t3, NULL, add_two_numbers, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    //Destroying the threads.
    pthread_exit(t1);
    pthread_exit(t2);
    pthread_exit(t3);
    return 0;
}