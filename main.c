#include <stdio.h>

#include "include/Socket.h"
#include "include/Data.h"
#include "include/Socket.h"


int main(int argc, char**argv)
{
    Udp udp_client;
    udp_init(&udp_client);

    Udp udp_serv;
    udp_init(&udp_serv);
    udp_bind(&udp_serv, 5555);


    Data data;
    data_init(&data, "192.168.1.27", 3245);

    int input;
    char buffer[500];
    data_encode(&data, buffer, 500);


    printf("waiting for input\n");
    scanf("%i", &input);

    while (input != 0)
    {
        int nb = udp_send(&udp_client, "localhost", 5555, buffer);
        //udp_recv(&udp_serv, buffer, 500);

        printf("%s\n", buffer);
        printf("waiting for input\n");
        scanf("%i", &input);
    }
    udp_end();

    return 0;
}
