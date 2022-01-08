#include "command_handling.h"
#include "usefull_functions.h"

#include <string.h>
#include <stdbool.h>
#include <stdio.h>




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
            if (nb_args == 1) {
                printf("Vous n'avez saisie aucun argument.\n");
                return 0;
            }

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
            // Il reste à remplir le vide par une valeur par défaut !

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
    return 0;
}


void commandHandler(struct commande* command) {

    if (strcmp(command->name, "add") == 0) {
        //add_client(command);
    }
    if (strcmp(command->name, "delete") == 0) {

    }
    if (strcmp(command->name, "help") == 0) {

    }
    if (strcmp(command->name, "modify_client") == 0) {

    }
}
