#include "../include/Crypto_manager.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void cryptomanager_init(Crypto_manager* cm)
{
    // init the structure
    cm->tab_communications = (Crypto_communication*) malloc(sizeof(Crypto_communication) * TAB_START_SIZE);
    cm->tab_size = TAB_START_SIZE;
    cm->tab_pos = 0;
}

void cryptomanager_destroy(Crypto_manager* cm)
{
    // free memory
    free(cm->tab_communications);
}

void cryptomanager_add_connections(Crypto_manager* cm, Data* data)
{
    Crypto_communication* comm = &(cm->tab_communications[cm->tab_pos]);

    // complete parameters for the two threads
    strcpy(comm->client_A_param.ip, data->sip);
    comm->client_A_param.port = data->sport;

    strcpy(comm->client_B_param.ip, data->dip);
    comm->client_B_param.port = data->dport;

    // launch thread
    if(pthread_create(&(comm->client_A_thread), NULL, crypto, &(comm->client_A_param))) {
        fprintf(stderr, "Error creating thread - 1\n");
        exit(1);
    }
    if(pthread_create(&(comm->client_B_thread), NULL, crypto, &(comm->client_B_param))) {
        fprintf(stderr, "Error creating thread - 2\n");
        exit(1);
    }

    cm->tab_pos += 1;
    cryptomanager_check_tabsize(cm);
}

void cryptomanager_check_tabsize(Crypto_manager* cm)
{
    // Reallocation more memory
    if (cm->tab_pos >= cm->tab_size/2)
    {
        cm->tab_size *= 2;
        Crypto_communication* res = (Crypto_communication*) realloc(cm->tab_communications, sizeof(Crypto_communication) * cm->tab_size);
        if (res != NULL)
            cm->tab_communications = res;
    }
}

void *crypto(void *data)
{
    Thread_parameters param = *((Thread_parameters*)data);

    printf("Crypto on ip %s and port %i\n", param.ip, param.port);

    // Crypto operations

    return NULL;
}
