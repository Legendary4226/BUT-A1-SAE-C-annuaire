#include "../usefull_functions.h"
#include "../data_management/data_structure.h"

/*
 * Essaye de charger un fichier avec un chemin donné.
 * Retourne 1 si le fichier est chargé avec succès, 0 sinon.
 */
struct Client* cmdLoadFile(int* nbClients, struct Client* clientsArray, FILE** file, char* path);



/*
 * Permet d'afficher toute les lignes de l'annuaire contenant la valeur de recherche/filtre
 * selon un certain champ.
 * Posibilitées de trouver les noms commencant par "Ade" par exemple.
 * Le filtre fait une difference entre majuscules et minuscules.
 */
void cmdFilter(int* nbClients, struct Client* clientsArray, char* champ, char* value);



/*
 * Permet d'ajouter un client. La fonction commence pas réallouer la liste des clients, et le nouveau client est ajouté en fin de liste.
 */
int add(struct Client** clientsArray, int* nbClients, char* name, char* surname, char* city, char* codepostal, char* phone, char* email, char* profession);



/*
 * Affiche tout les clients donc au moins une information est manquante.
 */
void missingInfo(struct Client** clientsArray, int* nbClients);



/*
 * "Supprime un client" en supprimant les données de ce dernier
 * et les remplacant par les données du dernier client de la liste.
 * La valeur de retour est : *nbClients - 1
 */
int delete(struct Client** clientsArray, int* nbClients, char* lineNumber);



/*
 * Affiche de l'aide sur les commandes.
 * Exemple :
 * --> help -cmdName add
 * Ou encore :
 * --> help -cmdName list // Pour une liste de toute les commandes
 */
void help(char* commandName);



/*
 * Sauvegarde la liste actuelle dans un fichier dont le nom est filename.
 * Ouverture en w+, attention a ne pas écraser un fichier existant.
 */
int save(struct Client** clientsArray, int* nbClients, char* fileName);



/*
 * Modifie un client, n'écrase que les champs données en paramètres étant différent d'une chaine vide ("\0")
 */
void alter(struct Client** clientsArray, int* nbClients, char* lineToAlter, char* name, char* surname, char* city, char* codepostal, char* phone, char* email, char* profession);

/*
 * Permute simplement les données de deux structures.
 */
void permuteClients(struct Client* client1, struct Client* client2);



/*
 * Trie la liste en entrée en fonction d'un champ.
 */
void triSelection(struct Client** clientsArray, int* nbClients, char* champStr);



/*
 * Compare deux structures Client par un seul de ses membres (first_name, last_name, phone, ...).
 * La valeur de retour correspond à strcpm de string.h
 */
int compareChamps(int champ, struct Client* client1, struct Client* client2);



/*
 * Permet d'afficher du vide.
 */
void clear();
