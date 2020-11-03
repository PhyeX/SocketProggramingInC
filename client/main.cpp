#include<stdio.h>
#include<string.h>
#include<winsock2.h>

void getErrorHeader();

#pragma comment(lib,"ws2_32.lib") //Winsock Library

int main() {

        WSADATA wsa;

        printf("\nInitialising Winsock...");
        if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)  // WSAStartup,winsock kütüphanesini başlatır.2parametre alır,ilki yüklemek istediğimiz versiyon,ikincisi winsock yüklendikten sonra ek bilgi tutacak bir WSADATA yapısıdır.
        {
            getErrorHeader();
            printf("Failed. Error Code : %d",WSAGetLastError()); // Herhangi bir hata oluşursa, WSAStartup işlevi sıfır olmayan bir değer döndürür ve WSAGetLastError hangi hatanın oluştuğu hakkında daha fazla bilgi almak için kullanılabilir.
            return 1;
        }

        int sock;
        struct sockaddr_in server;
        char message[1000] , server_reply[2000];
        int recv_size;

        //Create socket
        sock = socket(AF_INET , SOCK_STREAM , 0);
        if (sock == -1)
        {
            getErrorHeader();
            printf("Could not create socket");
            return 1;
        }
        puts("Socket created");

        server.sin_addr.s_addr = inet_addr("192.168.1.3"); //inet_addr: Sayı ve noktalarla ifade edilen IPv4 adreslerini ağ byte sıralamasına uygun sayı formuna dönüştürür.
        server.sin_family = AF_INET;
        server.sin_port = htons( 2222 );

        //Connect to remote server
        if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
        {
            getErrorHeader();
            perror("connect failed. Error");
            return 1;
        }

        puts("Connected\n");
        //keep communicating with server
        while(1)
        {

            printf("\nEnter message : ");
            scanf("%[^\n]%*c",message);



            //Send some data
            if( send(sock , message , strlen(message) , 0) < 0)
            {
                getErrorHeader();
                puts("Send failed");
                return 1;
            }

            //Receive a reply from the server

            if(recv_size= recv(sock , server_reply , 2000 , 0) < 0)
            {
                getErrorHeader();
                puts("Revc failed");
                break;
            }

           printf("Server reply : ");
           printf("%s",server_reply);

           memset(server_reply, 0, sizeof  server_reply);

        }

        closesocket(sock);
        WSACleanup();
        return 0;
}

void getErrorHeader() {
    printf("*****************ERROR*****************\n");
}
