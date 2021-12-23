#include <stdio.h>
#include <string.h>



#include "max_fields_length.h"

//#include "main.h"
#include "command_handling.h"
#include "usefull_functions.h"



int main() {
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

    printf("%d", sizeof(struct commande));


    char test[100] = "add -name aa -phone 07401511 -email aadedf -city fhurbf";

    struct commande commandeTemp;
    int resultParsing = parseCmd(test, &commandeTemp, commandes, nb_commands_templates);

    if (resultParsing == 1) {
        //commandHandler(&commandeTemp);
    }


    return 0;
}
