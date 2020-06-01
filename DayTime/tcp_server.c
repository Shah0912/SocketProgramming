#include<stdio.h>
#include<stdlib.h>

#include<sys/types.h>
#include<sys/socket.h>

#include<netinet/in.h>
#include<time.h>


int main() {

    int server_socket;
    if((server_socket = socket(AF_INET, SOCK_STREAM, 0)) <= 0) {
        printf("Error in socket");
        return 0;
    }
    time_t tick;
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;

    if(bind(server_socket, (struct sockaddr* ) &server_address, sizeof(server_address)) < 0) {
        printf("error in binding");
        return 0;
    }


    listen(server_socket, 5);
    int client_socket, len, ch;
    char server_message[256];
    for(;;) {
        client_socket = accept(server_socket, NULL,NULL);
        tick = time(NULL);
        snprintf(server_message,sizeof(server_message),"%s",ctime(&tick));
        printf("%s",server_message);
        send(client_socket,server_message,sizeof(server_message), 0);
    }

    return 0;
}