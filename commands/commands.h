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
