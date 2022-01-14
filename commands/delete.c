#include <stdio.h>
#include <stdlib.h>

#include "commands.h"

int delete(struct Client** clientsArray, int* nbClients, char* lineNumber) {

    int num = strtol(lineNumber, NULL, 10);

    if (num == 0) {
        printf("Erreur lors de la suppression du client.\n");
        return *nbClients;
    }

    *(clientsArray + num) = *(clientsArray + *nbClients);
    struct Client* newClientsArray = realloc(*clientsArray, (*nbClients - 1) * sizeof(struct Client));

    if (newClientsArray == NULL) {
        printf("Erreur lors de la suppression (REALLOC). Toutes les opérations ont été perdues.\n");
        return 0;
    }

    *clientsArray = newClientsArray;

    printf("La suppression du client a ete effectue avec succes.\n");
    return *nbClients - 1;
}
