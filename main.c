#include <stdio.h>
#include <string.h>



#include "max_fields_length.h"
#include "usefull_functions.h"
#include "command_handling.h"


int main() {
    struct commande commandes[10] = {
            {"help", 1,
                {"-cmdName"}
             },
            {"add", 7,
                {"-name", "-surname", "-city", "-codepostal", "-phone", "-email", "-profession"}
                },
            {"delete", 1,
             {"-lineNumber"}
            },
            {"loadFile", 1,
                    {"-path"}
            },
            {
                "display", 0,
                    {}
            },
            {
                "filter", 2,
                    {"-champ", "-value"}
            },
            {
                "missingInfo", 0,
                    {}
            },
            {
                "save", 1,
                    {"-fileName"}
            },
            {"alter", 8,
                        {"-lineNumber", "-name", "-surname", "-city", "-codepostal", "-phone", "-email", "-profession"}
            },
            {
                "tri", 1,
                    {"-champ"}
            }
    };
    int nb_commands_templates = sizeof(commandes)/ sizeof(struct commande);


    FILE* file = NULL;
    struct Client* clients_array = NULL;
    int nbClients = 0;

    char userInput[MAX_USER_INPUT_LENGTH];
    struct commande userInputCommand;
    int resultParsing;

    bool fileLoaded = false;
    bool exitCommand = false;
    bool skip = false;

    do {
        skip = false;

        printf("\nEnter command> ");
        askUser(MAX_USER_INPUT_LENGTH, userInput);

        if (strcmp(userInput, "exit") == 0) {
            exitCommand = true;
            skip = true;
        }

        if (!skip) {
            resultParsing = parseCmd(userInput, &userInputCommand, commandes, nb_commands_templates);

            if (resultParsing == 0) {
                skip = true;
            }
            if (resultParsing == 1 && fileLoaded) {
                commandHandler(&userInputCommand, &file, &nbClients, &clients_array);
            }
            if (resultParsing == 1 && strcmp(userInputCommand.name, "loadFile") == 0 || strcmp(userInputCommand.name, "help") == 0) {
                commandHandler(&userInputCommand, &file, &nbClients, &clients_array);
                if (strcmp(userInputCommand.name, "loadFile") == 0 && clients_array != NULL) {
                    fileLoaded = true;
                }
            }
        }

        if (file != NULL) {
            fileLoaded = true;
        }
    } while(!exitCommand);

    printf("Fin de programme.");
    return 0;
}
