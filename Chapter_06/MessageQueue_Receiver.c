#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define PERMISSIONS 0644

struct messageBuffer {
   long mtype;
   char data[1024];
};

int main() {
   struct messageBuffer buf;
   int msqid;
   int toend;
   key_t key;
   
   if ((key = ftok("messagequeue.txt", 'B')) == -1) {
      
      perror("ftok");
      exit(1);
   }
   
   if ((msqid = msgget(key, PERMISSIONS)) == -1) { 
    
      // connect to the queue
      printf("Unable to Create the Message Queue.\n");
      perror("msgget");
      exit(1);
   }
   printf("Message Queue: ready to receive messages.\n");
   
   for(;;) { /* normally receiving never ends but just to make conclusion this program ends wuth string of end */
      if (msgrcv(msqid, &buf, sizeof(buf.data), 0, 0) == -1) {
         perror("msgrcv");
         exit(1);
      }
      printf("received: \"%s\"\n", buf.data);
      toend = strcmp(buf.data,"end");
      if (toend == 0)
      break;
   }
   printf("message queue: done receiving messages.\n");
   system("rm messagequeue.txt");
   return 0;
}
