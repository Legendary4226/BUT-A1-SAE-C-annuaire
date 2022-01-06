#include <stdio.h>

#include "usefull_functions.h"
#include "max_fields_length.h"


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


int countLinesInFile(FILE** file) {

    int nb_lines = 0;
    char read[FILE_MAX_LINE_LENGTH] = "";
    while(fgets(read, FILE_MAX_LINE_LENGTH, *file) != NULL){
        nb_lines++;
    }

    rewind(*file);

    return nb_lines;
}