#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// Permissions for the Message Queue.
#define PERMISSIONS 0644

struct messageBuffer {
   long messageType;
   char data[1024];
};

int main() {
   struct messageBuffer buf;
   int msqid;
   int len;
   key_t key;
   system("touch messagequeue.txt");
   
   if ((key = ftok("messagequeue.txt", 'B')) == -1) {
      perror("ftok");
      exit(1);
   }
   
   if ((msqid = msgget(key, PERMISSIONS | IPC_CREAT)) == -1) {
      perror("msgget");
      exit(1);
   }
   printf("Message Queue is ready to send messages.\n");
   printf("Enter lines of text, ^D to quit:\n");
   buf.messageType = 1; /* we don't really care in this case */
   
   while(fgets(buf.data, sizeof buf.data, stdin) != NULL) {
      len = strlen(buf.data);
      // Removing the newline at end if it exists 
      if (buf.data[len-1] == '\n') buf.data[len-1] = '\0';
      if (msgsnd(msqid, &buf, len+1, 0) == -1) /* +1 for '\0' */
      perror("msgsnd");
   }
   strcpy(buf.data, "end");
   len = strlen(buf.data);
   if (msgsnd(msqid, &buf, len+1, 0) == -1) /* +1 for '\0' */
   perror("msgsnd");
   
   if (msgctl(msqid, IPC_RMID, NULL) == -1) {
      perror("msgctl");
      exit(1);
   }
   printf("Message Queue is done with sending messages.\n");
   return 0;
}





