#include "../include/Socket.h"

#include <string.h>

void udp_init(Udp* udp)
{
#ifdef WIN32
    WSADATA wsa;
    int err = WSAStartup(MAKEWORD(2, 2), &wsa);
    if(err < 0)
    {
        puts("WSAStartup failed !");
        exit(EXIT_FAILURE);
    }
#endif
    // create an endpoint for communication
    udp->sockfd = socket(AF_INET,SOCK_DGRAM,0);
}

void udp_end(void)
{
#ifdef WIN32
    WSACleanup();
#endif
}

int udp_send(Udp* udp, char* ip, int port, char* message){
    // Configure server address
    bzero(&(udp->servaddr),sizeof(udp->servaddr));
    (udp->servaddr).sin_family = AF_INET;
    (udp->servaddr).sin_addr.s_addr=inet_addr(ip);
    (udp->servaddr).sin_port=htons(port);

    // send a message on a socket
    return sendto(udp->sockfd,message,strlen(message),0,(struct sockaddr *)&(udp->servaddr),sizeof(udp->servaddr));
}

void udp_bind(Udp* udp, int port){
    // Configure server address
    bzero(&(udp->servaddr),sizeof(udp->servaddr));
    (udp->servaddr).sin_family = AF_INET;
    (udp->servaddr).sin_addr.s_addr=INADDR_ANY;
    (udp->servaddr).sin_port=htons(port);

    // bind a name to a socket
    bind(udp->sockfd, (struct sockaddr *)&udp->servaddr, sizeof udp->servaddr);
}

int udp_recv(Udp* udp, char* buffer, int length){
    // receive a message from a socket
    return recv(udp->sockfd, buffer, length, 0);
}
