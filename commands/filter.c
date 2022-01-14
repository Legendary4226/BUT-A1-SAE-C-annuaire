#include <stdio.h>
#include <string.h>

#include "commands.h"


void cmdFilter(int* nbClients, struct Client* clientsArray, char* champ, char* value) {
    // Vérifier le champ :
    char champs[6][11] = {
            "name",
            "surname",
            "city",
            "codepostal",
            "phone",
            "email"
    };
    int champIndex = -1;
    for (int i = 0; i < 6; ++i) {
        if (strcmp(champ, champs[i]) == 0) {
            champIndex = i;
        }
    }
    if (champIndex == -1) {
        printf("Le champ n'existe pas.\n");
        return;
    }

    int nbResults = 0;
    int clientNumber = 0;
    for (struct Client* client = clientsArray; client < clientsArray + *nbClients; ++client) {
        switch (champIndex) {
            case 0:
                if (strstr(client->first_name, value) != NULL) {
                    displayLine(client, clientNumber);
                    nbResults++;
                }
                break;
            case 1:
                if (strstr(client->last_name, value) != NULL) {
                    displayLine(client, clientNumber);
                    nbResults++;
                }
                break;
            case 2:
                if (strstr(client->city, value) != NULL) {
                    displayLine(client, clientNumber);
                    nbResults++;
                }
                break;
            case 3:
                if (strstr(client->code_postal, value) != NULL) {
                    displayLine(client, clientNumber);
                    nbResults++;
                }
                break;
            case 4:
                if (strstr(client->phone, value) != NULL) {
                    displayLine(client, clientNumber);
                    nbResults++;
                }
                break;
            case 5:
                if (strstr(client->email, value) != NULL) {
                    displayLine(client, clientNumber);
                    nbResults++;
                }
                break;
        }

        clientNumber++;
    }

    printf("\n\n-- %d resultat(s).\n", nbResults);
}