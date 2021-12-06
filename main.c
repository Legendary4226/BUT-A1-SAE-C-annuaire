#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>


// Fichier d'en tête
#include "main.h"


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

int main() {
    printf("%d", FILE_MAX_LINE_LENGTH);

    FILE* f = NULL;
    openFile("../annuaire5000.csv", "r", &f, true);

    char test[500];
    fgets(test, 500, f);

    printf("%s", test);

    int size = 50;
    int* woaw = malloc(size * sizeof(int));

    for (int i = 0; i < size; ++i) {
        woaw[i] = i;
    }
    for (int i = 0; i < size; ++i) {
        printf("%d\n", woaw[i]);
    }

    return 0;
}


void* askMemory(int nb_octets) {
    void* assigned_adress = (void*) malloc(nb_octets);
    assert(assigned_adress != NULL && strcat(strcat("Memory Allocation Error on ask_memory function. ", nb_octets), " octets asked."));
    return assigned_adress;
}

void openFile(const char *path, const char *mode, FILE** file,bool assertIfFail) {
    // FILE** représente le pointer de FILE*, donc cela permet de modifier la valeur de FILE*
    *file = fopen(path, mode);

    if (assertIfFail) {
        assert(*file != NULL && "Failed to open file.");
    }
}