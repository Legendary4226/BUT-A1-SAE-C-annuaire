#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "commands.h"

void alter(struct Client** clientsArray, int* nbClients, char* lineToAlter, char* name, char* surname, char* city, char* codepostal, char* phone, char* email, char* profession) {
    int line = strtol(lineToAlter, NULL, 10);
    if (line < 0 || line > *nbClients) {
        printf("Erreur, veuillez entrer une valeur valide.\n");
        return;
    }

    struct Client* clientToModify = *clientsArray + line - 1;

    if (strcmp(name, "") != 0) {
        strcpy(clientToModify->first_name, name);
        printf("Le prenom a bien ete modifie.\n");

    }
    if (strcmp(surname, "") != 0) {
        strcpy(clientToModify->last_name, surname);
        printf("Le nom a bien été modifie.\n");
    }
    if (strcmp(city, "") != 0) {
        strcpy(clientToModify->city, city);
        printf("La ville a bien ete modifie.\n");
    }
    if (strcmp(codepostal, "") != 0) {
        strcpy(clientToModify->code_postal, codepostal);
        printf("Le code postal a bien ete modifie.\n");
    }
    if (strcmp(phone, "") != 0) {
        strcpy(clientToModify->phone, phone);
        printf("Le numero de telephone a bien ete modifie.\n");
    }
    if (strcmp(email, "") != 0) {
        strcpy(clientToModify->email, email);
        printf("L'email a bien ete modifie.\n");
    }
    if (strcmp(profession, "") != 0) {
        strcpy(clientToModify->profession, profession);
        printf("La profession a bien ete modifie.\n");
    }

    printf("\nOperation terminee avec succes.\n\n");

}
