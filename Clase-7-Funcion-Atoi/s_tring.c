#include <stdio.h>
#include "s_tring.h"

char *str_ncpy(char *dest, const char *orig, int cant){
    char *aux = dest;

    // Copiar N (cant) caracteres desde 'orig' a 'dest'
    while(cant && *orig){
        *dest = *orig;
        dest++;
        orig++;
        cant--;
    }

    init_str(dest, '\0');

    return aux;
}

void init_str(char *cad, char val){
    while(*cad){
        *cad = val;
        cad++;
    }
}
