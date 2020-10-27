#include <stdio.h>
#include<stdlib.h>
#include <pthread.h>

// Data Collector.
struct arguments {
    char* name;
    int age;
    char *bloodGroup;
};

// Thread Function
void *sayGreetings(void *data) {
    printf("Name: %s", ((struct arguments*)data)->name);
    printf("Age: %d\n", ((struct arguments*)data)->age);
    printf("Blood Group: %s\n", ((struct arguments*)data)->bloodGroup);
    return NULL;
}

int main() {

    struct arguments *person = (struct arguments *)malloc(sizeof(struct arguments));
    printf("This is a Simple Data Collection Application\n");
    char bloodGroup[5], name[50];
    int age;
    printf("Enter the name of the person: ");
    fgets(name, 50, stdin);
    printf("Enter the age of the person: ");
    scanf("%d",&age);
    printf("Enter the person's Blood Group: ");
    scanf("%s", bloodGroup);

    person->name = name;
    person->age = age;
    person->bloodGroup = bloodGroup;

    pthread_t thread;
    pthread_create(&thread, NULL, sayGreetings, (void *)person);
    pthread_join(thread, NULL);
    return 0;
}