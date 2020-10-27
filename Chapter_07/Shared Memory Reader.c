#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/shm.h> 
  
int main() { 

    // ftok to generate unique key 
    key_t key = ftok("memory",67); 
  
    // shmget returns an identifier in shmid 
    int shmid = shmget(key, 1024,0666|IPC_CREAT); 
    
    if(shmid == -1){
        printf("Unable to Connect with the shared memory segment.\n");
    }
    // shmat to attach to shared memory 
    char *str = (char*) shmat(shmid,(void*)0,0); 
  
    printf("Data read from memory: %s\n",str); 
      
    //detach from shared memory  
    shmdt(str); 
    
    // destroy the shared memory 
    shmctl(shmid,IPC_RMID,NULL); 
     
    return 0; 
} 