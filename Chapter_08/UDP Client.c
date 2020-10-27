#include<stdio.h> 
#include<unistd.h> 
#include<strings.h> 
#include<sys/types.h> 
#include<arpa/inet.h> 
#include<sys/socket.h> 
#include<netinet/in.h> 

#define MAX 1024 // Maximum number of data that can transfer
#define PORT 8080 // port number to connect
#define SA struct sockaddr // Creating Macro for the socketaddr as SA
  
// Driver code 
int main() {  

    char buffer[100]; 
    char *message = "Greetings from Client"; 
    int sockfd, n; 
    struct sockaddr_in servaddr; 
      
    // clear servaddr 
    bzero(&servaddr, sizeof(servaddr)); 
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    servaddr.sin_port = htons(PORT); 
    servaddr.sin_family = AF_INET; 
      
    // create datagram socket 
    sockfd = socket(AF_INET, SOCK_DGRAM, 0); 
      
    // connect to server 
    if(connect(sockfd, (SA *)&servaddr, sizeof(servaddr)) < 0) { 
        printf("\n Something went wrong Connection Failed \n"); 
        _exit(0); 
    } 
  
    // request to send datagram 
    // no need to specify server address in sendto 
    // connect stores the peers IP and port 
    sendto(sockfd, message, MAX, 0, (SA*)NULL, sizeof(servaddr)); 
      
    // waiting for response 
    recvfrom(sockfd, buffer, sizeof(buffer), 0, (SA*)NULL, NULL); 
    puts(buffer); 
  
    // close the descriptor 
    close(sockfd); 

    return 0;
} 