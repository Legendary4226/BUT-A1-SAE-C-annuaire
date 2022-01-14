#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#include "commands/commands.h"

#define MAX_COMMAND_ARGS 8
#define MAX_ARG_LENGTH 70

/*
 * Description générale d'une commande,
 * permet de dynamiquement créer une nouvelle commande.
 */
struct commande {
    char* name;
    int argsNumber;

    char args[MAX_COMMAND_ARGS][MAX_ARG_LENGTH]; // Une liste de string étant les noms des arguments
};

/*
 * Analyse de la saisie de l'utilisateur
 * modifie une structure représentant la commande et ses arguments
 * retourne 0 si le parsing a échoué, 1 sinon
 */
int parseCmd(char* userInput, struct commande* command, struct commande* commandsTemplate, int nb_commands);


/*
 * Envoie les données analysée a la bonne fonction.
 */
void commandHandler(struct commande* command, FILE** file, int* nbClients, struct Client** clientsArray);
