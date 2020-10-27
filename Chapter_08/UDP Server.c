#include <stdio.h> 
#include<unistd.h>
#include <strings.h> 
#include <sys/types.h> 
#include <arpa/inet.h> 
#include <sys/socket.h> 
#include<netinet/in.h> 

#define MAX 1024 // Maximum number of data that can transfer
#define PORT 8080 // port number to connect
#define SA struct sockaddr // Creating Macro for the socketaddr as SA
  
// Driver code 
int main() {   

    char buffer[100]; 
    char *message = "Greetings from Server"; 
    int sockfd;
    socklen_t len; 
    struct sockaddr_in servaddr, cli; 
    bzero(&servaddr, sizeof(servaddr)); 
  
    // Create a UDP Socket 
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);         
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(PORT); 
    servaddr.sin_family = AF_INET;  
   
    // bind server address to socket descriptor 
    bind(sockfd, (SA*)&servaddr, sizeof(servaddr)); 
       
    //receive the datagram 
    len = sizeof(cli); 
    int n = recvfrom(sockfd, buffer, sizeof(buffer), 0, (SA*)&cli,&len);
   //receive message from server 
    buffer[n] = '\0'; 
    puts(buffer); 
           
    // send the response 
    sendto(sockfd, message, MAX, 0, (SA*)&cli, sizeof(cli)); 

    close(sockfd);

    return 0;
}