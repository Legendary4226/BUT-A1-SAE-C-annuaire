#include "../usefull_functions.h"
#include "../data_management/data_structure.h"

/*
 * Essaye de charger un fichier avec un chemin donné.
 * Retourne 1 si le fichier est chargé avec succès, 0 sinon.
 */
struct Client* cmdLoadFile(int* nbClients, struct Client* clientsArray, FILE** file, char* path);



/*
 *
 */
void cmdFilter(int* nbClients, struct Client* clientsArray, char* champ, char* value);



/*
 *
 */
int add(struct Client** clientsArray, int* nbClients, char* name, char* surname, char* city, char* codepostal, char* phone, char* email, char* profession);



/*
 *
 */
void missingInfo(struct Client** clientsArray, int* nbClients);



/*
 *
 */
int delete(struct Client** clientsArray, int* nbClients, char* lineNumber);



/*
 *
 */
void help(char* commandName);



/*
 *
 */
int save(struct Client** clientsArray, int* nbClients, char* fileName);



/*
 *
 */
void alter(struct Client** clientsArray, int* nbClients, char* lineToAlter, char* name, char* surname, char* city, char* codepostal, char* phone, char* email, char* profession);
