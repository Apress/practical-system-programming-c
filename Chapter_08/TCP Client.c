#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h>
#include<string.h> 
#include<sys/socket.h> 
#include<netdb.h> 
#include<arpa/inet.h>

#define MESSAGE_LENGTH 1024 // Maximum number of data that can transfer
#define PORT 8888 // port number to connect
#define SA struct sockaddr // Creating Macro for the socketaddr as SA

// Global Data
int socket_file_descriptor, connection;
struct sockaddr_in serveraddress, client;
char message[MESSAGE_LENGTH];

int main(){

    // Socket Creation
    socket_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_file_descriptor == -1){
        printf("Creation of Socket failed.!\n");
        exit(1);
    }

    // Erases the memory
    bzero(&serveraddress, sizeof(serveraddress));

    // Setting the Server Properties
    serveraddress.sin_addr.s_addr = inet_addr("127.0.0.1");
    // Setting the port numeber
    serveraddress.sin_port = htons(PORT);
    // Protocol family
    serveraddress.sin_family = AF_INET;

    // Establishing the Connection with server
    connection = connect(socket_file_descriptor, (SA*)&serveraddress, sizeof(serveraddress));

    if(connection == -1){
        printf("Connection with the server failed.!\n");
        exit(1);
    }

    // Interacting with the server
    
    while(1){

        bzero(message, sizeof(message));
        
        printf("Enter the message you want to send to the server: ");
        scanf("%[^\n]%*c", message);

         if ((strncmp(message, "end", 3)) == 0) { 
            write(socket_file_descriptor, message, sizeof(message)); 
            printf("Client Exit.\n"); 
            break; 
        }

        // Sending the data to the server by storing the number of bytes transferred in bytes variable 
        ssize_t bytes = write(socket_file_descriptor, message, sizeof(message));
        
        // If the number of bytes is >= 0 then the data is sent successfully
        if(bytes >= 0){
            printf("Data send to the server succesfully.!\n");
        }

        bzero(message, sizeof(message));

        // Reading the response from the server.
        read(socket_file_descriptor, message, sizeof(message));

        printf("Data received from server: %s\n", message);

    }
    // Closing the Socket Connection
    close(socket_file_descriptor);

    return 0;
}