#include <stdio.h>

#include "commands.h"


void clear() {
    for (int i = 0; i < 100; ++i) {
        printf(">\n");
    }
}