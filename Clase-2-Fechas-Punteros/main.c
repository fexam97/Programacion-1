#include <stdio.h>

#include "fechas.h"

int main()
{
    const Fecha fecha; // = {12, 4, 2012};

    puts("ingrese una fecha: ");
    scanf("%d",&fecha.dia); fflush(stdin);
    scanf("%d",&fecha.mes); fflush(stdin);
    scanf("%d",&fecha.anio); fflush(stdin);

    int valida = esFechaValida(&fecha);

    if(valida)
        puts("La fecha es valida");
    else
        puts("la fecha es invalida");

    int dias;

    puts("Ingrese los dias a sumar");
    scanf("%d",&dias);

    sumarDiasAFechaInSitu(&fecha, dias);
    printf("\n La fecha luego de sumar: %d/%d/%d", fecha.dia, fecha.mes, fecha.anio);

    return 0;
}

// y hasta aca llego el fin de las fecha

