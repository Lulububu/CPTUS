#ifndef CRYPTO_MANAGER_H
#define CRYPTO_MANAGER_H

#include <pthread.h>

#include "../../common/include/Data.h"
#include "../../common/include/Socket.h"

// Minimum : 10
#define TAB_START_SIZE 8

// parameter for one crypto thread
typedef struct
{
    char ip[16];
    int port;
    int running;
    Udp udp_serv;
}Thread_parameters;

// Connection with A and B
typedef struct
{
    Thread_parameters client_A_param;
    pthread_t client_A_thread;

    Thread_parameters client_B_param;
    pthread_t client_B_thread;
}Crypto_communication;

// General stucture
typedef struct
{
    Crypto_communication* tab_communications;
    int tab_size;
    int tab_pos;
}Crypto_manager;

// Create a new manager for threads
void cryptomanager_init(Crypto_manager*);
// stop thread and clean memory
void cryptomanager_destroy(Crypto_manager*);

// launch 2 new threads to listen A and B
void cryptomanager_add_connections(Crypto_manager*, Data*);

// check threads tab size and reallocate if necessary
void cryptomanager_check_tabsize(Crypto_manager*);

// Thread function
void *crypto(void *data);

#endif