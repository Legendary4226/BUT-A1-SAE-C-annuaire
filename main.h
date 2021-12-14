#ifndef SAE_S1_01_02_MAIN_H
#define SAE_S1_01_02_MAIN_H

#endif //SAE_S1_01_02_MAIN_H



#define FILE_MAX_NAME_LENGTH 35
#define FILE_MAX_CITY_LENGTH 25
#define FILE_MAX_CODEPOSTAL_LENGTH 5
#define FILE_MAX_PHONE_LENGTH 14
#define FILE_MAX_EMAIL_LENGTH 70
#define FILE_MAX_PROFESSION_LENGTH 30

#define FILE_MAX_LINE_LENGTH FILE_MAX_NAME_LENGTH \
    + FILE_MAX_CITY_LENGTH                        \
    + FILE_MAX_CODEPOSTAL_LENGTH                  \
    + FILE_MAX_PHONE_LENGTH                       \
    + FILE_MAX_EMAIL_LENGTH                       \
    + FILE_MAX_PROFESSION_LENGTH

#define MAX_COMMAND_ARGS 10
#define MAX_ARG_LENGTH 20




/*
 * Fonction permettant l'allocation de mémoire
 * Si l'allocation échoue, le programme s'arrête.
 */
void* askMemory(int nb_octets);


/*
 * Permet d'ouvrir un fichier avec le chemin donné, et permet de choisir avec assertIfFail si on arrête le code en cas
 * d'erreur d'ouverture.
 * Affecte au pointeur de la variable file passé en paramètre le fichier.
 */
void openFile(const char *path, const char *mode, FILE** file, bool assertIfFail);


/*
 * Récupère l'entrée d'un utilisateur de taille spécifiée max_length
 * Enlève le caractère '\n' en fin de chaine pour le remplacer par un '\0'
 */
void askUser(int max_length, char* chaine);


/*
 * Fonction Split selon un caractère précis
 */
void split(char* chaine, char separator, char* splitted[]);
/*
 * EXEMPLE d'UTILISATION :

char stringInput[100] = "a simple example";
int nb_args = countChar(stringInput, ' ') + 1; // + 1 car il y a deux espaces mais 3 mots à séparer
char* splitted[nb_args];

// Splitter la chaine stringInput
split(test, &separator, splitted);

// Afficher le résultat
for (int i = 0; i < nb_args; ++i) {
    printf("%s\n", splitted[i]);
}

## Résultat :
// a
// simple
// example
 */


/*
 * Compte le nombre d'occurences d'un caractère donné dans une chaine.
 */
int countChar(char* chaine, char toCount);



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
 *
 */
int commandHandler(struct commande* command);


