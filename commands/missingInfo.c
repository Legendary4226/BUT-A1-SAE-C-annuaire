#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "commands.h"



void missingInfo(struct Client** clientsArray, int* nbClients) {
    int compteur=0;
    int numClient=1;
    bool notFound=true;
    for (struct Client* client = *clientsArray; client < *clientsArray + *nbClients; ++client) {

        if (strcmp(client->first_name, "")==0){
            notFound=false;
        }
        if (strcmp(client->last_name, "")==0 && notFound){
            notFound=false;
        }
        if (strcmp(client->city, "")==0 && notFound){
            notFound=false;
        }
        if (strcmp(client->email, "")==0 && notFound){
            notFound=false;
        }
        if (strcmp(client->profession, "")==0 && notFound){
            notFound=false;
        }
        if (strcmp(client->phone, "")==0 && notFound){
            notFound=false;
        }
        if (strcmp(client->phone, "")==0 && notFound){
            notFound=false;
        }

        if(notFound==false){
            displayLine(client, numClient);
            compteur++;
        }
        numClient++;
        notFound=true;
    }

    printf("\n\nIl y a %d client(s) qui ont des informations manquantes.\n", compteur);
}