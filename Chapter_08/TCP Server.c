#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h>
#include<string.h> 
#include<sys/socket.h> 
#include<sys/types.h> 
#include<netdb.h> 
#include<netinet/in.h> 

#define MESSAGE_LENGTH 1024 // Maximum number of data that can transfer
#define PORT 8888 // port number to connect
#define SA struct sockaddr // Creating Macro for the socketaddr as SA

struct sockaddr_in serveraddress, client;
socklen_t length;
int sockert_file_descriptor, connection, bind_status, connection_status;
char message[MESSAGE_LENGTH];

int main(){
    
    // Creating the Socket
    sockert_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);

    if(sockert_file_descriptor == -1){
        printf("Scoket creation failed.!\n");
        exit(1);
    }

    // Erases the memory
    bzero(&serveraddress, sizeof(serveraddress));

    // Server Properties
    serveraddress.sin_addr.s_addr = htonl(INADDR_ANY);
    // Setting the port number
    serveraddress.sin_port = htons(PORT);
    // Protocol family
    serveraddress.sin_family = AF_INET;

    // Binding the newly created socket with the given Ip Address
    bind_status = bind(sockert_file_descriptor, (SA*)&serveraddress, sizeof(serveraddress));

    if(bind_status == -1){
        printf("Socket binding failed.!\n");
        exit(1);
    }

    // Server is listening for new creation
    connection_status = listen(sockert_file_descriptor, 5);

    if(connection_status == -1){
        printf("Socket is unable to listen for new connections.!\n");
        exit(1);
    }else{
        printf("Server is listening for new connection: \n");
    }

    length =  sizeof(client);

    connection = accept(sockert_file_descriptor, (SA*)&client, &length);

    if(connection == -1){
        printf("Server is unable to accept the data from client.!\n");
        exit(1);
    }

    // Communication Establishment
    while(1){
        
        bzero(message, MESSAGE_LENGTH);

        read(connection, message, sizeof(message));

        if (strncmp("end", message, 3) == 0) { 
            printf("Client Exited.\n"); 
            printf("Server is Exiting..!\n");
            break;
        }

        printf("Data received from client: %s\n", message);
        bzero(message, MESSAGE_LENGTH);

        printf("Enter the message you want to send to the client: ");
        scanf("%[^\n]%*c", message);

         // Sending the data to the server by storing the number of bytes transferred in bytes variable 
        ssize_t bytes = write(connection, message, sizeof(message));
        
        // If the number of bytes is >= 0 then the data is sent successfully
        if(bytes >= 0){
            printf("Data successfully sent to the client.!\n");
        }
        
    }
    // Closing the Socket Connection
    close(sockert_file_descriptor);

    return 0;
}