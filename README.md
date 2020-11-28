# Socket Proggraming In C

  <b> Öncelikle programımızda kullandığımız ve alışkın olmadığımız  struct yapılarını daha iyi kullanabilmek için yakından inceleyelim. </b>
  
  ![image](https://user-images.githubusercontent.com/45934056/97986814-537aaa00-1deb-11eb-9f9e-7c574a1e5fb0.png)


   ## WSADATA: 
    typedef struct WSAData {
        WORD                    wVersion;
        WORD                    wHighVersion;
        char                    szDescription[WSADESCRIPTION_LEN+1];
        char                    szSystemStatus[WSASYS_STATUS_LEN+1];
        unsigned short          iMaxSockets;
        unsigned short          iMaxUdpDg;
        char FAR *              lpVendorInfo;
    } WSADATA;
    
  ## SOCKET
    SOCKET WSAAPI socket(
    int af,
    int type,
    int protocol
    );
    
  ## SOCKADDR_IN
    struct sockaddr_in {
    sa_family_t    sin_family; 
    in_port_t      sin_port;   
    struct in_addr sin_addr;  
    };
    

  ### WSASTARTUP ( Parameter a , Parameter b )
  <ul><b><li> Winsock kütüphanesini başlatır. </li></b></ul>
  
  ![image](https://user-images.githubusercontent.com/45934056/98133195-5a2e1d80-1ece-11eb-862a-2049bda51652.png)
  
     WSAStartup,winsock kütüphanesini başlatır.2 parametre almaktadır.
     Parameter a : (MAKEWORD(2,2)) Yüklemek istediğimiz versiyon. (2.2)
     Parameter b : (&wsa) İkincisi winsock yüklendikten sonra ek bilgi tutacak bir WSADATA yapısıdır.
     
  ### socket (int domain, int type, int protocol);
  <ul><b><li> Bir soket oluşturur. </li></b></ul>
  
  ![image](https://user-images.githubusercontent.com/45934056/98134949-54d1d280-1ed0-11eb-9ea3-8fa63c8d6f90.png)
  
    Parameter domain : AF_UNIX (UNIX internal protocols)
    
     (Bu parametre için olası diğer örnekleri)
     AF_UNIX ( AF_LOCAL )----- Aynı makinedeki işlemler arasında verimli bir şekilde iletişim kurmak için kullanılır.
     AF_INET (ARPA Internet protocols)-----IPv4 yoluyla ağ üzerinden iletişim kurmak için kullanılır.
     AF_INET6 (ARPA Internet protocols)-----IPv6 yoluyla ağ üzerinden iletişim kurmak için kullanılır.
  
    Parameter type : SOCK_STREAM
    
    (Diğer olası parametreler)
     SOCKTREAM :  Bağlantı Yönelimli
                  TCP protokolü kullanılır.
                  Veriler sıralı gönderilir.
                  Veri bütünlüğü korunur.
                 
     SOCK_DGRAM : Bağlantısız soketler.
                  UDP protokolü kullanılır.
                  Veriler sıra halinde yollanılanamayabilir.
                  Veri bütünlüğü garanti edilmez. 
                  
      SOCK_RAW :  Saf,ham bir ağ protokol erişimi sağlar.
                  Dahili protokollere (IP ve ICMP gibi) arayüz sağlar.
                  Kullanmak için root olmak gereklidir.
                  Sadece AF_INET ve AF_INET6 alanlarında desteklenmektedir.
      
     Parameter protocol : 0
                  
       IPPROTO_TCP veya 0 TCP socketleri için kullanılabilir. tcp_socket = socket(AF_INET, SOCK_STREAM, ( 0 || IPPROTO_TCP ));
       IPPROTO_UDP veya 0 Udp socketleri için kullanıabilir . udp_socket = socket(AF_INET, SOCK_DGRAM, ( 0 || IPPROTO_UDP ));
       RFC 1700 protokolü tanımlı bir IANA IP'si tanımlamak gerekir. raw_socket = socket(AF_INET, SOCK_RAW, protocol);
       
   ### bind( int sockfd, const struct sockaddr *addr,socklen_t addrlen);
   <ul><b><li>Soketi bir İP ve Port numarası ile ilişkilendirir. </li></b></ul> 
   
   ![image](https://user-images.githubusercontent.com/45934056/100515232-836b6200-318b-11eb-8a63-2f20f352ed4e.png)

      

             

                                   

                                    

                                    
    
    
