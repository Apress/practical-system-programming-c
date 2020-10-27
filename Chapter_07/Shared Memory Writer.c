#include<stdio.h>
#include<string.h>
#include <sys/ipc.h> 
#include <sys/shm.h> 
  
int main() { 
    // ftok to generate unique key 
    key_t key = ftok("memory",67); 
  
    // shmget returns an identifier in shmid 
    int shmid = shmget(key, 1024,0666|IPC_CREAT); 
    
    if(shmid == -1){
        printf("Unable to create the Shared Memory Segment.\n");
    }

    // shmat to attach to shared memory 
    char *str = (char*) shmat(shmid,(void*)0,0); 
  
    printf("Enter Data to write into the Shared Memory Segment: "); 
    scanf("%[^\n]s", str);
  
    printf("Data written in memory: %s\n",str); 
      
    //detach from shared memory  
    shmdt(str); 
  
    return 0; 
} 