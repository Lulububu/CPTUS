#include "../include/Data.h"

void data_init(Data* data, char* sip, int sport, char* dip, int dport){
    strcpy(data->sip, sip);
    data->sport = sport;
    strcpy(data->dip, dip);
    data->dport = dport;
}

int data_encode(Data* data, char* target, int size){
    return snprintf(target, size, "%s%s%i%s%s%s%i\n", data->sip, DELIM,  data->sport, DELIM, data->dip, DELIM,  data->dport);
}

void data_decode(Data* data, char* src){
    // char* pch;

    // init
    strcpy(data->sip, "0.0.0.0");
    strcpy(data->dip, "0.0.0.0");
    data->sport = 1234;
    data->dport = 1234;

    char * pch;

    pch = strtok (src, DELIM);
    // printf ("sip %s\n", pch);
    strcpy(data->sip, pch);

    pch = strtok (NULL, DELIM);
    // printf ("sport %i\n", atoi(pch));
    data->sport = atoi(pch);

    pch = strtok (NULL, DELIM);
    // printf ("dip %s\n", pch);
    strcpy(data->dip, pch);

    pch = strtok (NULL, DELIM);
    // printf ("dport %i\n", atoi(pch));
    data->dport = atoi(pch);


    // // sip
    // pch = strtok (src, DELIM);
    // if(pch != NULL)
    //     strcpy(data->sip, pch);

    // // sport
    // pch = strtok (NULL, DELIM);
    // if(pch != NULL)
    //     data->sport = atoi(pch);

    // // dip
    // pch = strtok (NULL, DELIM);
    // if(pch != NULL)
    //     strcpy(data->dip, pch);

    // // dport
    // pch = strtok (NULL, DELIM);
    // if(pch != NULL)
    //     data->dport = atoi(pch);
}

void data_print(Data* data){
    printf("Data {\n \tsip : %s;\n\tsport : %i;\n \tdip : %s;\n\tdport : %i;\n}\n", data->sip, data->sport, data->dip, data->dport);
}
