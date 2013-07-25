#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Data delimiter
#define DELIM ","

// Data structure
typedef struct Data {
     char sip[16];
     int sport;
     char dip[16];
     int dport;
} Data;


// init a data with ip and port values
void data_init(Data* data, char* sip, int sport, char* dip, int dport);

// serialize data
int data_encode(Data* data, char* target, int size);

// decode serialize data
void data_decode(Data* data, char* src);

// print Data structure
void data_print(Data* data);

#endif // DATA_H_INCLUDED
