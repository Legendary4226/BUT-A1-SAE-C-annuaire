#ifndef SAE_S1_01_02_MAIN_H
#define SAE_S1_01_02_MAIN_H

#endif //SAE_S1_01_02_MAIN_H


/*
 * Fonction permettant l'allocation de mémoire
 * Si l'allocation échoue, le programme s'arrête.
 */
void* askMemory(int nb_octets);


/*
 * Permet d'ouvrir un fichier avec le chemin donné, et permet de choisir avec assertIfFail si on arrête le code en cas
 * d'erreur d'ouverture
 */
void openFile(const char *path, const char *mode, FILE** file, bool assertIfFail);



/*
 *
 */
char askUser(int max_length);