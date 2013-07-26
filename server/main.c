// C program
// server for rtp connections

// lib
#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>
#include <unistd.h>

// project files
#include "../include/Crypto_manager.h"
#include "../common/include/Socket.h"
#include "../common/include/Data.h"

#define BUFFER_SIZE 1400
#define UDP_PORT 5555


int RUNNING = 1;
Udp udp_serv;

void sig_handler(int signo)
{
    if (signo == SIGINT)
    {
        RUNNING = 0;
        // udp_close(&udp_serv);
        printf("Stopping...\n");
    }
}


int main(int argc, char**argv)
{
    printf("Server start\n");

    if (signal(SIGINT, sig_handler) == SIG_ERR)
        printf("\ncan't catch SIGINT\n");
    
    // UDP server initialization
    udp_init(&udp_serv);
    udp_bind(&udp_serv, UDP_PORT);
    char msg_buffer[BUFFER_SIZE];
    int size;

    // Data structure
    Data recv_data;

    // Crypto manager initialization
    Crypto_manager cm;
    cryptomanager_init(&cm);

    while(RUNNING == 1)
    {
        // receive a message from a socket
        size = udp_recv(&udp_serv, msg_buffer, BUFFER_SIZE);
        // printf("IN %s\n", msg_buffer);
        if (size > 0)
        {   
            // Decode message
            data_decode(&recv_data, msg_buffer);
            // data_print(&recv_data);

            // Add new connections thread for A and B
            cryptomanager_add_connections(&cm, &recv_data);
        }
    }

    // Clean program
    cryptomanager_destroy(&cm);
    udp_close(&udp_serv);
    udp_end();

    printf("Server stop\n");
    return 0;
}
