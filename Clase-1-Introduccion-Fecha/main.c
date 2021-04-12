//puts("Hello world!"); //no hace falta poner el \n
#include <stdio.h>

#include "fecha.h"
//typedef int entero;
int main()
{
    //entero varEnt = 8;

    Fecha hoy = {28,2,2000};

    int valida = esFechaValida(hoy);

    if(valida)
        puts("La fecha es valida");
    else
        puts("la fecha es invalida");

    return 0;
}
