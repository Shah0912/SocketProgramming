#include<stdio.h>
#include<stdlib.h>

#include<sys/types.h>
#include<sys/socket.h>

#include<netinet/in.h>

int main() {
    int client_socket, n;
    char recvline[256];
    struct sockaddr_in servaddr;
    /* if(argc != 2) {
        printf("Error in number of arguments");
        return 0;
    } */
    if((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("socket error");
        return 0;
    }
    // bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(9002);
    servaddr.sin_addr.s_addr = INADDR_ANY;
    /* if(inet_pton(AF_INET,argv[1],servaddr.sin_addr) <= 0) {
        printf("inet_pton error for %s: "argv[1]);
        return 0; 
    }  */
    if((connect(client_socket, (struct sockaddr* ) &servaddr, sizeof(servaddr))) < 0) {
        printf("Connection error\n");
        return 0;
    }
    if(n = recv(client_socket, &recvline, sizeof(recvline), 0) < 0) {  
        printf("error in reading");
        return 0;
    }
    printf("Date and time is : %s", recvline);
    printf("\n");
    return 0;
}