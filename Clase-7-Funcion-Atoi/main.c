#include <stdio.h>
#include <stdlib.h>
#include "std_lib.h"
#include "s_tring.h"

int main()
{
    /*char cad[11] = {" \t -158fg"};
    int num;

    num = a_toi(cad);

    printf("El numero es: %d | la cadena es: \"%s\" \n", num,cad);*/

    char origen[11] = {"hola mundo"};
    char destino[6];

    int cantidad = 4;
    // init_str(destino, '\0');

    str_ncpy(destino, origen, cantidad);
    printf("La subcadena resultante es: \"%s\". ", destino);

    return 0;
}
