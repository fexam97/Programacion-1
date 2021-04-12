#include "fechas.h"
#define esBisiestoM(a) ((a % 4 == 0 && a % 100 != 0)||a % 400 == 0)

int cantDiasMes(int mes, int anio); //No es necesario que esté en el main.c
int esBisiesto(int anio);

int esFechaValida(const Fecha* f) //const siempre se usa cada vez que no se modifique una variable
{
    if(f->anio < 1601) // (*f).anio < 1601
        return 0;

    if(f->mes < 1 || f->mes > 12)
        return 0;

    if(f->dia < 1 || f->dia > cantDiasMes(f->mes, f->anio)) //necesito el mes y el año para comprarar y obtener el dia
        return 0;

    //*(Fecha*(f))->dia = 45;
    return 1;
}


Fecha sumarDiasAFecha(const Fecha* f, unsigned dias) //unsigned = numeros sin signo
{
    Fecha fSuma = *f;

    sumarDiasAFechaInSitu(&fSuma, dias);

    return fSuma;
}
void sumarDiasAFechaInSitu(Fecha* f, unsigned dias)
{
    f->dia += dias;

    int cdm; //C.d.m = Cantidad dias mes

    while(f->dia > (cdm = cantDiasMes(f->mes, f->anio)))
    {
        //f->dia += cantDiasMes(f->mes, f->anio);
        f->dia -= cdm;// depende cuantos dias tenga el mes se resta, para saber el dia(numero) del nuevo mes
        f->mes++;

        if(f->mes > 12)
        {
            f->mes = 1; //enero
            f->anio++;
        }
    }
}
////////////////////////////////////////////////////////////////////////////
int cantDiasMes(int mes, int anio)
{
    // nose que es el static
    static int diasMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //muy importante el 0 al principio

    if(mes == 2 && esBisiestoM(anio)) //MACRO
        return 29;

    return diasMes[mes];
}


