#include <stdio.h>

#include "commands.h"


struct Client* cmdLoadFile(int* nbClients, struct Client* clientsArray, FILE** file, char* path) {
    clientsArray = loadFile(nbClients, path, file);

    if (clientsArray == NULL) {
        printf("Echec du chargement du fichier.");
    }

    printf("Fichier charge avec succes.");
    return clientsArray;
}