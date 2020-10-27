#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

sem_t mutex;

int a = 5, b = 7;
// Function to access the global data 
void* add_two_numbers(void* arg){
    sem_wait(&mutex);
    a = a + 3;
    b = b - 1;
    printf("a value is: %d and ", a);
    printf("b value is: %d\n", b);
    sleep(1);
    sem_post(&mutex);
}

int main(){
    sem_init(&mutex, 0, 1);
    pthread_t t1, t2, t3;
    pthread_create(&t1, NULL, add_two_numbers, NULL);
    sleep(1);
    pthread_create(&t2, NULL, add_two_numbers, NULL);
    sleep(1);
    pthread_create(&t3, NULL, add_two_numbers, NULL);
    sleep(1);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    sem_destroy(&mutex);

    return 0;
}