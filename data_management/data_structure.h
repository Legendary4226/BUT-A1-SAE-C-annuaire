#include "../max_fields_length.h"

struct Client {
    char first_name[FILE_MAX_NAME_LENGTH];
    char last_name[FILE_MAX_NAME_LENGTH];
    char city[FILE_MAX_CITY_LENGTH];
    char email[FILE_MAX_EMAIL_LENGTH];
    char profession[FILE_MAX_PROFESSION_LENGTH];
    char phone[FILE_MAX_PHONE_LENGTH];
    char code_postal[FILE_MAX_CODEPOSTAL_LENGTH];
};


/*
 * Permet d'attribuer à une structure Client les données d'une ligne du fichier csv
 */
void fillClient(struct Client* client, char* client_info[]);


/*
 * Permet de remplir un tableau de Client.
 */
void fillClientArray(struct Client clients[], FILE** clientListing);


/*
 * Permet d'afficher correctement les informations d'un client sur une ligne.
 */
void displayLine(struct Client* client, int clientNb);



/*
 * Permet d'afficher correctement les informations des clients référencé dans le tableau.
 */
void displayArray(struct Client* clients[], int arraySize);