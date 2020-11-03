#include <windows.h>
#include <winsock2.h>
#include <stdio.h>
#include <string.h>

void getErrorHeader();

#pragma comment(lib, "Ws2_32.lib") //Winsock Library

int main() {

    WSADATA wsa;
    SOCKET main_socket , new_socket;
    struct sockaddr_in server , client;
    int read_size;
    char client_message[2000],message[2000];
//    The structure of the soccaddr_in variable.
//     * struct sockaddr_in {
//        short int sin_family; // AF_INET
//        unsigned short int sin_port; // Port numarası
//        struct in_addr sin_addr; // IPv4 adresi
//        unsigned char sin_zero[8];
//    }

    printf("\nInitialising Winsock...");
    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
    {
        getErrorHeader();
        printf("Failed. Error Code : %d",WSAGetLastError());
        return 1;
    }
    printf("\nInitialised.\n");

    //Create a socket
    printf("Creating socket...\n");
//    @Parameter  AF_UNIX=Local Machine,AF_INET= IPv4 , AF_INET6 = IPv6
//    @Parameter SOCK_STREAM == TCP, SOCK_DGRAM == UDP , SOCK_RAW = RAW
//    @Parameter 0 = 0 indicates that the caller does not want to specify the protocol and will leave it up to the service provider.
//
    if((main_socket = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET)
    {
        getErrorHeader();
        printf("Could not create socket : %d" , WSAGetLastError());
        return 1;
    }

    printf("Socket created.\n");

    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 2222 );

    printf("Binding the port %d \n",ntohs(server.sin_port));

    //Bind
    if( bind(main_socket ,(struct sockaddr *)&server , sizeof(server)) == SOCKET_ERROR)
    {
        getErrorHeader();
        printf("Bind failed with error code : %d " , WSAGetLastError());
        if( WSAGetLastError() == 10048)
            printf("(The port is already in use)\n");

        return 0;
    }
    puts("Bind done\n");

    //Listen to incoming connections
    listen(main_socket , 3);
    //Accept and incoming connection
    puts("Waiting for incoming connections...\n");

    int socket_size = sizeof(struct sockaddr_in);
    new_socket = accept(main_socket , (struct sockaddr *)&client, &socket_size);
    if (new_socket == INVALID_SOCKET)
    {
        getErrorHeader();
        printf("Accept failed with error code : %d" , WSAGetLastError());
        return 1;
    }

    puts("Connection accepted");

    // Receive until the peer closes the connection
    fflush(stdin);
    while( (read_size = recv(new_socket , client_message , 2000 , 0)) > 0 )
    {
        printf("Client reply : ",client_message);
        fprintf(stdout, "%.*s", new_socket, client_message);
        memset(client_message, 0, sizeof  client_message);
      // client_message
      int i = 0;
        printf("\nEnter message : ");
        scanf("%[^\n]%*c" , message);

        //Send some data
        if( send(new_socket, message , strlen(message) , 0) < 0)
        {
            puts("Send failed");
            return 1;
        }
    }
    getErrorHeader();
    if(read_size == 0)
    {
        puts("Client disconnected");
    }
    else if(read_size == -1)
    {
        perror("Recive failed");
    }

    closesocket(main_socket);
    WSACleanup();
    return 0;
}

void getErrorHeader() {
    printf("*****************ERROR*****************\n");
}
