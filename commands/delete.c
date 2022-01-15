#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "commands.h"

int delete(struct Client** clientsArray, int* nbClients, char* lineNumber) {

    int num = strtol(lineNumber, NULL, 10);

    if (num == 0) {
        printf("\nErreur lors de la suppression du client.\n");
        return *nbClients;
    }

    struct Client* lastClient = *clientsArray + *nbClients - 1;
    struct Client* toDelete = *clientsArray + num - 1;

    // Clear le client a supprimer
    strcpy(toDelete->profession, "\0");
    strcpy(toDelete->phone, "\0");
    strcpy(toDelete->last_name, "\0");
    strcpy(toDelete->first_name, "\0");
    strcpy(toDelete->city, "\0");
    strcpy(toDelete->code_postal, "\0");
    strcpy(toDelete->email, "\0");


    // Remplir le client a supprimer par le dernier client de la liste
    strcpy(toDelete->profession, lastClient->profession);
    strcpy(toDelete->phone, lastClient->phone);
    strcpy(toDelete->last_name, lastClient->last_name);
    strcpy(toDelete->first_name, lastClient->first_name);
    strcpy(toDelete->city, lastClient->city);
    strcpy(toDelete->code_postal, lastClient->code_postal);
    strcpy(toDelete->email, lastClient->email);

    printf("\nLa suppression du client %d a ete effectue avec succes.\n", num);
    return *nbClients - 1;
    // Décrémenter le nombre de clients permet "d'oublier" le dernier client de la liste sans realloc
}
