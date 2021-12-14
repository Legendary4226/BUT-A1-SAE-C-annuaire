#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>



#include "main.h"




int main() {
    /* Initialiser les commandes */
    struct commande commandes[] = {
            {"help", 1,
                {"-cmdName"}
             },
            {"add", 6,
                {"-name", "-surname", "-city", "-codepostal", "-phone", "-email"}
                },
            {"delete", 6,
             {"-name", "-surname", "-city", "-codepostal", "-phone", "-email"}
            }
    };
    int nb_commands_templates = sizeof(commandes)/ sizeof(struct commande);

    //struct commande testData = {"add", {"-name", "Test", "-phone", "0541505178", "-email", "escgjbkuge@gmail.ces"}, 6};


    char test[100] = "delete -name aa -phone 07401511 -city aadedf";

    struct commande commandeTemp;
    int resultParsing = parseCmd(test, &commandeTemp, commandes, nb_commands_templates);

    if (resultParsing) {
        commandHandler(&commandeTemp);
    }

    //commandHandler();

    return 0;
}


int parseCmd(char* userInput, struct commande* command, struct commande* commandsTemplate, int nb_commands) {
    // Split la commande
    int nb_args = countChar(userInput, ' ') + 1;
    char* splittedInput[nb_args];
    split(userInput, ' ', splittedInput);

    // Déterminer quelle commande doit être analysé

    int compareStr;

    for (int cmd_id = 0; cmd_id < nb_commands; ++cmd_id) {
        compareStr = strcmp(splittedInput[0], commandsTemplate[cmd_id].name);
        if (compareStr == 0){
            // On a trouvé la commande, ajouter son nom dans la structure
            command->name = commandsTemplate[cmd_id].name;
            command->argsNumber = commandsTemplate[cmd_id].argsNumber;

            // Maintenant vérifier les arguments

            int check_arg_id = 1;
            char* to_check;
            bool exists = false;

            int arg_id_temp;

            int args_found[command->argsNumber];
            for (int i = 0; i < command->argsNumber; ++i) {
                args_found[i] = 0;
            }

            do {
                to_check = splittedInput[check_arg_id];
                /*
                 * Il existe deux types d'arguments :
                 * -argName value
                 * Donc un argument suivie d'une valeur associée
                 * *argName
                 * Donc un argument étant présent ou non (true ou false) changeant le fonctionnement du code
                 */

                printf("to_check = %s, arg_id = %d\n", to_check, check_arg_id);


                if (*to_check != '-' && *to_check != '*') {
                    printf("Attention, format de commande invalide. Une argument commencant par un - est toujours suivit par une valeur.");
                    return 0;
                }

                // Vérifier si l'argument existe
                exists = false;
                for (int i = 0; i < commandsTemplate[cmd_id].argsNumber; ++i) {
                    if (strcmp(to_check, commandsTemplate[cmd_id].args[i]) == 0){
                        exists = true;
                        arg_id_temp = i;
                    }
                }
                if (!exists) {
                    printf("Erreur, l'argument \"%s\" n'existe pas", to_check);
                    return 0;
                }

                // Cas -argName value
                if (*to_check == '-') {
                    // Vérifier si on ne sort pas de la liste
                    if (check_arg_id + 1 >= nb_args){
                        // On le dépasse donc la commande n'est pas dans une forme valide
                        printf("Attention, format de commande invalide. Une argument commencant par un - est toujours suivit par une valeur.");
                        return 0;
                    }

                    // L'argument existe et une valeur (check_arg_id + 1) a été donné pour cet argument
                    // l'ajouter dans la structure
                    strcpy(command->args[arg_id_temp], splittedInput[check_arg_id + 1]);
                    // Référencer l'argument
                    args_found[arg_id_temp] += 1;

                    // Incrémenter pour ce retrouver à la "fin" de l'argument sans dépasser la taille de la liste
                    check_arg_id++;
                }
                // Cas *argName
                if (*to_check == '*') {
                    // Comme ces arguments sont là ou pas là il valent "true" ou "false". Ici il est présent : 1
                    strcpy(command->args[arg_id_temp], "true");
                    args_found[arg_id_temp] += 1;
                }


                // Passer à l'argument suivant, si il n'existe pas la boucle s'arrêtera
                check_arg_id++;

            } while(check_arg_id < nb_args);

            // Si on est sorti de la boucle while c'est que tout les arguments ont été vérifié sans erreurs
            // Il reste à remplir le vide par des valeurs par défaut !

            /*
             * Comment savoir lesquels sont vide ?
             * Il va falloir initialiser un tableau de taille nb_args - 1
             * rempli de 0
             * et quand on trouvent un argument on incrémente le nombre lié par l'ID
             * si après la boucle while des nombres sont à :
             * 0 --> l'argument n'a pas été spécifié
             * 1 --> l'argument a été donné
             * x>1 --> l'argument a été donné plusieurs fois ! Erreur
             */

            for (int i = 0; i < command->argsNumber; ++i) {
                // Un argument a été spécifié plusieurs fois
                if (args_found[i] == 2){
                    printf("Erreur, l'argument %s a ete specifie %d fois.\n", commandsTemplate->args[i], args_found[i]);
                    return 0;
                }

                // Ignorer les 1, simplement prendre les vides donc 0
                if (args_found[i] == 0) {
                    strcpy(command->args[i], "null");
                }
            }
            
            return 1;
        }
    }
    printf("Commande inconnue.\n");
}



/* Fonctions usuelles */
void* askMemory(int nb_octets) {
    void* assigned_adress = (void*) malloc(nb_octets);
    assert(assigned_adress != NULL && "Memory Allocation Error on ask_memory function. ");
    return assigned_adress;
}

void openFile(const char *path, const char *mode, FILE** file,bool assertIfFail) {
    // FILE** représente le pointer de FILE*, donc cela permet de modifier la valeur de FILE*
    *file = fopen(path, mode);

    if (assertIfFail) {
        assert(*file != NULL && "Failed to open file.");
    }
}

void askUser(int max_length, char* chaine) {

    fgets(chaine, max_length, stdin);

    // Déterminer emplacement en mémoire du retour à la ligne
    char* line_break = strchr(chaine, '\n');
    if(line_break != NULL) {
        // Supprimer le retour à la ligne
        *line_break = '\0';
    }
}

void split(char* chaine, char separator, char* splitted[]) {
    int arg_nb = 0;
    char* read = &chaine[arg_nb];
    splitted[arg_nb] = read;
    arg_nb++;

    int i = 0;

    do {
        if(*read == separator){
            *read = '\0';
            splitted[arg_nb] = read + 1;
            arg_nb++;
        }
        i++;
        read = &chaine[i];
    } while(*read != '\0');
}


int countChar(char* chaine, char toCount) {
    // Conter les espaces pour définir le nombre d'arguments
    int count_spaces = 0;
    for (int i = 0; i < strlen(chaine); ++i) {
        if(chaine[i] == toCount) {
            count_spaces++;
        }
    }
    return count_spaces;
}

