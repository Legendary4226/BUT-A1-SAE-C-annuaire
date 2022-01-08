#include <stdio.h>
#include <string.h>



#include "max_fields_length.h"
#include "command_handling.h"
#include "usefull_functions.h"
#include "data_management/data_structure.h"


int main() {
    struct commande commandes[4] = {
            {"help", 1,
                {"-cmdName"}
             },
            {"add", 6,
                {"-name", "-surname", "-city", "-codepostal", "-phone", "-email"}
                },
            {"delete", 6,
             {"-name", "-surname", "-city", "-codepostal", "-phone", "-email"}
            },
            {"load", 1,
                    {"-path"}
            }
    };
    int nb_commands_templates = sizeof(commandes)/ sizeof(struct commande);


    FILE* annuaire = NULL;
    struct Client* clients_array = NULL;
    int nbClients;

    char path[MAX_PATH_LENGTH];
    char* userInput[MAX_USER_INPUT_LENGTH];
    struct commande* userInputCommand = NULL;
    int resultParsing;

    bool fileLoaded = false;
    bool exitCommand = false;
    bool skip = false;

    do {
        skip = false;

        printf("\nEnter command>");
        askUser(MAX_USER_INPUT_LENGTH, userInput);

        if (strcmp(userInput, "exit") == 0) {
            exitCommand = true;
            skip = true;
        }

        if (!skip) {
            resultParsing = parseCmd(userInput, userInputCommand, commandes, nb_commands_templates);

            if (resultParsing == 0) {
                skip = true;
            }
            if (resultParsing == 1) {
                printf("Commande acceptée !\n");
            }
        }

        if (fileLoaded) {
            displayArray(clients_array, nbClients);
        }

    } while(!exitCommand);

    printf("Fin de programme.");

    /*
    clients_array = loadFile(&nbClients, path, &annuaire);

    if (clients_array == NULL) {
        printf("Erreur durant le chargement du fichier.");
    }

    displayArray(clients_array, nbClients);
     */

    /*
    struct Client clients_array[] = reload("ddd", &annuaire);
    // MAX 12891 éléments, pk ??
    struct Client* clients_array_pointers[nb_lines_annuaire];


    loadFileData(&annuaire, clients_array, clients_array_pointers, nb_lines_annuaire);

    displayArray(clients_array_pointers, nb_lines_annuaire);
     */

    return 0;
}
