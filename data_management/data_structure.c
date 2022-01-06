#include <stdio.h>
#include <string.h>

#include "data_structure.h"
#include "../usefull_functions.h"
#include "../max_fields_length.h"



void fillClient(struct Client* client, char* client_info[]) {
    strcpy(client->first_name, client_info[0]);
    strcpy(client->last_name, client_info[1]);
    strcpy(client->city, client_info[2]);
    strcpy(client->email, client_info[5]);
    strcpy(client->profession, client_info[6]);
    strcpy(client->phone, client_info[4]);
    strcpy(client->code_postal, client_info[3]);
}



void fillClientArray(struct Client clients[], FILE** clientListing) {
    char client_info[FILE_MAX_LINE_LENGTH] = "";
    char* splitted_info[7];

    char separator = ',';

    int client_number = 0;
    while(feof(*clientListing) == 0) {
        fgets(client_info, FILE_MAX_LINE_LENGTH, *clientListing);

        split(client_info, separator, splitted_info);

        fillClient(&(clients[client_number]), splitted_info);

        client_number++;
    }
}



void displayLine(struct Client* client, int clientNb) {
    // Hardly optimized :
    printf("%d | %s%*c%s%*c%s%*c%s%*c  %s%*c%s%*c %s", clientNb, client->first_name, FILE_MAX_NAME_LENGTH - strlen(client->first_name), ' ', client->last_name, FILE_MAX_NAME_LENGTH - strlen(client->last_name), ' ', client->email, FILE_MAX_EMAIL_LENGTH - strlen(client->email), ' ', client->phone, FILE_MAX_PHONE_LENGTH - strlen(client->phone), ' ', client->city, FILE_MAX_CITY_LENGTH - strlen(client->city), ' ', client->code_postal, FILE_MAX_CODEPOSTAL_LENGTH - strlen(client->code_postal), ' ', client->profession);

    /*
    printf("%d | ", clientNb);

    printf("%s%*c", client->first_name, FILE_MAX_NAME_LENGTH - strlen(client->first_name), ' ');

    printf("%s%*c", client->last_name, FILE_MAX_NAME_LENGTH - strlen(client->last_name), ' ');

    printf("%s%*c", client->email, FILE_MAX_EMAIL_LENGTH - strlen(client->email), ' ');

    printf("%s%*c", client->phone, FILE_MAX_PHONE_LENGTH - strlen(client->phone), ' ');

    printf("%s%*c", client->city, FILE_MAX_CITY_LENGTH - strlen(client->city), ' ');

    printf("%s%*c", client->code_postal, FILE_MAX_CODEPOSTAL_LENGTH - strlen(client->code_postal), ' ');

    printf("%s", client->profession);
    */
}

void displayArray(struct Client* clients[], int arraySize) {
    for (int i = 0; i < arraySize; ++i) {
        displayLine(clients[i], i + 1);
    }
}