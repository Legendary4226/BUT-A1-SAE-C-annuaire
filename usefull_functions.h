#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>
#include <assert.h>


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
split(test, separator, splitted);

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
 * Conte le nombre de lignes dans une fichier texte.
 */
int countLinesInFile(FILE** file);
