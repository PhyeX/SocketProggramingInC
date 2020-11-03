# Socket Proggraming In C

  Öncelikle programımızda kullandığımız ve alışkın olmadığımız  struct yapılarını daha iyi tanıyalım.

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
