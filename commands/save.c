#include <stdio.h>



#include "commands.h"


int save(struct Client** clientsArray, int* nbClients, char* fileName) {
    FILE* file = NULL;
    openFile(fileName, "w+", &file, false);

    if (file == NULL) {
        printf("Erreur lors de la création du fichier.\n");
        return 0;
    }

    for (struct Client* client = *clientsArray; client < *clientsArray + *nbClients; client++) {
        fprintf(file, "%s,%s,%s,%s,%s,%s,%s\n", client->first_name, client->last_name, client->city, client->code_postal, client->phone, client->email, client->profession);
    }

    fclose(file);

    printf("Enregistrement termine !\n");

    return 1;
}