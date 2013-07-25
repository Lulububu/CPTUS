#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DELIM "|"

typedef struct Data {
     char ip[16];
     int port;
} Data;



void data_init(Data* data, char* ip, int port);

int data_encode(Data* data, char* target, int size);

void data_decode(Data* data, char* src);

void data_print(Data* data);

#endif // DATA_H_INCLUDED
