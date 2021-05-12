#include <stdio.h>
#include "std_lib.h"

#define esBlanco( X ) ( ( X ) == ' ' || ( X ) == '\t' )
#define esSigno( X ) ( ( X ) == '+' || ( X ) == '-')
#define esDigito( X ) ( ( X ) >= '0' && ( X ) <= '9')

int a_toi(const char *cad){
    int acu = 0;
    char signo;

    // Verificar si los caracteres iniciales son blanco o tabulación
    while(esBlanco(*cad))
        cad++;

    // Verficar si existe el signo
    if(esSigno(*cad)){
        signo = *cad;
        cad++;
    }

    // Si es número, lo acumulamos
    while(esDigito(*cad)){
        acu = acu * 10 + (*cad - '0'); // Conversion
        cad++;
    }

    // Antes de devolver, verificamos si el número resultante es negativo
    return signo == '-' ? -acu : acu;
}
