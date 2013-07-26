#ifndef SOCKET_H_INCLUDED
#define SOCKET_H_INCLUDED

#ifdef WIN32 /* si vous êtes sous Windows */

#include <winsock2.h>
#define bzero(b,len) (memset((b), '\0', (len)), (void) 0)

#elif defined (linux) /* si vous êtes sous Linux */

#include <sys/types.h>
#include <sys/socket.h>


#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> /* close */
#include <netdb.h> /* gethostbyname */
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close(s)
typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;

#else /* sinon vous êtes sur une plateforme non supportée */

#error not defined for this platform

#endif
#include <stdio.h>


// UDP data structure
typedef struct Udp {
    int sockfd;
    struct sockaddr_in servaddr;
} Udp;

// create an endpoint for communication
void udp_init(Udp* udp);

void udp_end(void);

void udp_close(Udp* udp);

// send a message on a socket
int udp_send(Udp* udp, char* ip, int port, char* message);

// bind a name to a socket
void udp_bind(Udp* udp, int port);

// receive a message from a socket
int udp_recv(Udp* udp, char* buffer, int length);

#endif
