# Socket Proggraming In C

  <b> Öncelikle programımızda kullandığımız ve alışkın olmadığımız  struct yapılarını daha iyi kullanabilmek için yakından tanıyalım. </b>
  
  ![image](https://user-images.githubusercontent.com/45934056/97986814-537aaa00-1deb-11eb-9f9e-7c574a1e5fb0.png)



   ## WSADATA: 
    typedef struct WSAData {
    WORD           wVersion;
    WORD           wHighVersion;
    #if ...
    unsigned short iMaxSockets;
    #if ...
    unsigned short iMaxUdpDg;
    #if ...
    char           *lpVendorInfo;
    #if ...
    char           szDescription[WSADESCRIPTION_LEN + 1];
    #if ...
    char           szSystemStatus[WSASYS_STATUS_LEN + 1];
    #else
    char           szDescription[WSADESCRIPTION_LEN + 1];
    #endif
    #else
    char           szSystemStatus[WSASYS_STATUS_LEN + 1];
    #endif
    #else
    unsigned short iMaxSockets;
    #endif
    #else
    unsigned short iMaxUdpDg;
    #endif
    #else
    char           *lpVendorInfo;
    #endif
    } WSADATA;
    
  ## SOCKET
    SOCKET WSAAPI socket(
    int af,
    int type,
    int protocol
    );
  ## SOCKADDR_IN
    typedef struct sockaddr_in {
    #if ...
      short          sin_family;
    #else
      ADDRESS_FAMILY sin_family;
    #endif
      USHORT         sin_port;
      IN_ADDR        sin_addr;
      CHAR           sin_zero[8];
    }
    
    
  <b> Şimdi ise  programımızda kullandığımız   WSAStartup Kütüphanesinin fonksiyonlarını  daha iyi kullanabilmek yakından tanıyalım. </b>
  ### WSASTARTUP ( Parameter a , Parameter b )
  ![image](https://user-images.githubusercontent.com/45934056/98133195-5a2e1d80-1ece-11eb-862a-2049bda51652.png)
  
     WSAStartup,winsock kütüphanesini başlatır.2 parametre almaktadır.
     Parameter a : (MAKEWORD(2,2)) Yüklemek istediğimiz versiyon. (2.2)
     Paramter : (&wsa) İkincisi winsock yüklendikten sonra ek bilgi tutacak bir WSADATA yapısıdır.
