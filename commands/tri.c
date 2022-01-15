#include <stdio.h>
#include <string.h>

#include "commands.h"



void triSelection(struct Client** clientsArray, int* nbClients, char* champStr) {
    int champ = -1;
    if (strcmp(champStr, "name") == 0) {
        champ = 1;
    }
    if (strcmp(champStr, "surname") == 0) {
        champ = 2;
    }
    if (strcmp(champStr, "city") == 0) {
        champ = 3;
    }
    if (strcmp(champStr, "email") == 0) {
        champ = 4;
    }
    if (strcmp(champStr, "profession") == 0) {
        champ = 5;
    }
    if (strcmp(champStr, "phone") == 0) {
        champ = 6;
    }
    if (strcmp(champStr, "codepostal") == 0) {
        champ = 7;
    }

    if (champ == -1) {
        printf("\nErreur, le champ specifie n'existe pas.\n");
        return;
    }

    int countCycle = 0;
    struct Client* lowestValue;

    int compareResult;

    while (countCycle < *nbClients) {
        lowestValue = *clientsArray + countCycle;
        // Déterminer la plus petite valeur
        for (struct Client* client = *clientsArray + countCycle + 1; client < *clientsArray + *nbClients; client++) {
            compareResult = compareChamps(champ, lowestValue, client);

            if (compareResult > 0) {
                lowestValue = client;
            }
        }

        // Permuter
        permuteClients(*clientsArray + countCycle, lowestValue);

        countCycle++;
    }

    printf("\nListe triee avec succes.\n");
}


int compareChamps(const int champ, struct Client* client1, struct Client* client2) {
    switch (champ) {
        case 1:
            return strcmp(client1->first_name, client2->first_name);
        case 2:
            return strcmp(client1->last_name, client2->last_name);
        case 3:
            return strcmp(client1->city, client2->city);
        case 4:
            return strcmp(client1->email, client2->email);
        case 5:
            return strcmp(client1->profession, client2->profession);
        case 6:
            return strcmp(client1->phone, client2->phone);
        case 7:
            return strcmp(client1->code_postal, client2->code_postal);
        default:
            return 0;
    }
}


void permuteClients(struct Client* client1, struct Client* client2) {
    struct Client temp;

    strcpy(temp.first_name, client1->first_name);
    strcpy(temp.last_name, client1->last_name);
    strcpy(temp.city, client1->city);
    strcpy(temp.email, client1->email);
    strcpy(temp.profession, client1->profession);
    strcpy(temp.phone, client1->phone);
    strcpy(temp.code_postal, client1->code_postal);


    strcpy(client1->first_name, client2->first_name);
    strcpy(client1->last_name, client2->last_name);
    strcpy(client1->city, client2->city);
    strcpy(client1->email, client2->email);
    strcpy(client1->profession, client2->profession);
    strcpy(client1->phone, client2->phone);
    strcpy(client1->code_postal, client2->code_postal);


    strcpy(client2->first_name, temp.first_name);
    strcpy(client2->last_name, temp.last_name);
    strcpy(client2->city, temp.city);
    strcpy(client2->email, temp.email);
    strcpy(client2->profession, temp.profession);
    strcpy(client2->phone, temp.phone);
    strcpy(client2->code_postal, temp.code_postal);
}