#include <stdio.h>
#include <malloc.h>
#include <string.h>

#include "commands.h"


int add(struct Client** clientsArray, int* nbClients, char* name, char* surname, char* city, char* codepostal, char* phone, char* email, char* profession) {
    struct Client* newClientsArray = realloc(*clientsArray, (*nbClients + 1) * sizeof(struct Client));

    if(newClientsArray==NULL){
        printf("Erreur lors de l'ajout du nouveau client. (REALLOC)\n");
        return 0;
    }

    struct Client* lastClient = newClientsArray + *nbClients;

    strcpy(lastClient->first_name, name);
    strcpy(lastClient->last_name, surname);
    strcpy(lastClient->city, city);
    strcpy(lastClient->email, email);
    strcpy(lastClient->profession, email);
    strcpy(lastClient->phone, phone);
    strcpy(lastClient->code_postal, codepostal);
    strcpy(lastClient->profession, profession);

    printf("Nouveau client ajoute avec succes.\n");

    *clientsArray = newClientsArray;

    return *nbClients + 1;
}