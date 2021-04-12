#include "fecha.h"
#define esBisiestoM(a) ((a % 4 == 0 && a % 100 != 0)||a % 400 == 0) //las macro llevan parentesis

int cantDiasMes(int mes, int anio); //No es necesario que esté en el main.c
int esBisiesto(int anio);

int esFechaValida(Fecha f)
{
    if(f.anio < 1601)
        return 0;

    if(f.mes < 1 || f.mes > 12)
        return 0;

    if(f.dia < 1 || f.dia > cantDiasMes(f.mes, f.anio)) //necesito el mes y el año para comprarar y obtener el dia
        return 0;

    return 1;
}

int cantDiasMes(int mes, int anio)
{
    // nose que es el static
    static int diasMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //muy importante el 0 al principio

    if(mes == 2 && esBisiestoM(anio)) //MACRO
        return 29;

    return diasMes[mes];
}


