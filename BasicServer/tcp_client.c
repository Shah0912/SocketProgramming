#include<stdio.h>
#include<stdlib.h>

#include<sys/types.h>
#include<sys/socket.h>

#include<netinet/in.h>

int main() {
    //Create a socket
    int network_socket;
    network_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    // Specify an address for the socket
    struct sockaddr_in server_address; 
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;
    
    //Connection
    int connnection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));
    
    //Check for error
    if(connnection_status == -1 )
        printf("there is an error making a connection to the remote socket \n");

    // Recieve data from the server
    char server_response[256];
    int r = recv(network_socket, &server_response, sizeof(server_response), 0);
    if(r<0) {
        printf("Error with receive");
        return 0;
    }
    // Print data
    printf("\nThe server sent the data: \n %s", server_response);

    //Close the socket
    // close(network_socket);
    return 0;
}