// UDP client
// send serialize string of DATA to server via UDP socket

#include <stdio.h>

#include "../common/include/Socket.h"
#include "../common/include/Data.h"

#define BUFFER_SIZE 1400
#define UDP_PORT 5555
#define IP_ADDR "127.0.0.1"


int main(int argc, char**argv)
{
    // initialize udp socket
    Udp udp_client;
    udp_init(&udp_client);

    // data structure to serialize information
    Data data;
    // encoded data
    char buffer[BUFFER_SIZE];
    

    // loop to send UDP packet on demand
    char sip[80] = "clientA\0";
    char dip[80] = "clientB\0";
    int sport;
    int res;
    do {
        // get entry
        printf ("PORT : ");
        res = scanf("%i", &sport);
        // printf ("D-PORT : ");
        // res2 = scanf("%i",&dport);

        if (res == 1)
        {
            int dport = sport+1;
            // encode data
            data_init(&data, sip, sport, dip, dport);
            data_encode(&data, buffer, BUFFER_SIZE);
            // send packet
            udp_send(&udp_client, IP_ADDR, UDP_PORT, buffer);
            printf("--->SEND %s %i %s %i\n", sip, sport, dip, dport);
        }else
            printf("Bad data !\n");
        
    } while (1);

    udp_end();

    return 0;
}
