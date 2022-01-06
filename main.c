#include <stdio.h>
#include <string.h>



#include "max_fields_length.h"
#include "command_handling.h"
#include "usefull_functions.h"
#include "data_management/data_structure.h"


int main() {
    struct commande commandes[3] = {
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

    /*
    char test[100] = "add -name aa -phone 07401511 -email aadedf -city fhurbf";

    struct commande commandeTemp;
    int resultParsing = parseCmd(test, &commandeTemp, commandes, nb_commands_templates);
     */

    FILE* annuaire;
    openFile("../annuaire5000.csv", "r", &annuaire, true);


    int nb_lines_annuaire = countLinesInFile(&annuaire);
    if (nb_lines_annuaire > 12891) {
        printf("Il y a plus de 12891 lignes /!\\");
    }
    struct Client clients_array[nb_lines_annuaire];
    struct Client* clients_array_pointers[nb_lines_annuaire];

    fillClientArray(clients_array, &annuaire);

    int i = 0;
    for (struct Client* address = clients_array; address < clients_array + nb_lines_annuaire; ++address) {
        clients_array_pointers[i] = address;
        i++;
    }

    displayArray(clients_array_pointers, nb_lines_annuaire);

    return 0;
}
