#include <stdio.h>
#include<stdlib.h>
#include <pthread.h>

// Data Collector.
struct arguments {
    char name[50];
    int age;
    char bloodGroup[5];
};

// Thread Function
void *sayGreetings(void *data) {
    printf("Name: %s", ((struct arguments*)data)->name);
    printf("Age: %d\n", ((struct arguments*)data)->age);
    printf("Blood Group: %s\n", ((struct arguments*)data)->bloodGroup);
    return NULL;
}

int main() {

    struct arguments person;
    printf("This is a Simple Data Collection Application\n");
    printf("Enter the name of the person: ");
    fgets(person.name, 50, stdin);
    printf("Enter the age of the person: ");
    scanf("%d",person.age);
    printf("Enter the person's Blood Group: ");
    scanf("%s", person.bloodGroup);

    pthread_t thread;
    pthread_create(&thread, NULL, sayGreetings, (void *)&person);
    pthread_join(thread, NULL);
    return 0;
}
