#include "../include/Data.h"

void data_init(Data* data, char* ip, int port){
    strcpy(data->ip, ip);
    data->port = port;
}

int data_encode(Data* data, char* target, int size){
    return snprintf(target, size, "%s%s%i", data->ip,DELIM,  data->port);
}

void data_decode(Data* data, char* src){
    char* pch;

    pch = strtok (src, DELIM);
    if(pch != NULL)
        strcpy(data->ip, pch);

    pch = strtok (NULL, DELIM);
    if(pch != NULL)
        data->port = atoi(pch);
}

void data_print(Data* data){
    printf("Data {\n \tip : %s;\n\tport : %i;\n}\n", data->ip, data->port);
}
