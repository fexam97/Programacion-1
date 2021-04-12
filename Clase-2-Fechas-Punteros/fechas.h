#ifndef FECHAS_H
#define FECHAS_H

typedef struct
{
    int dia;
    int mes;
    int anio;
}
Fecha;

int esFechaValida(const Fecha* f);
Fecha sumarDiasAFecha(const Fecha* f, unsigned dias);
void sumarDiasAFechaInSitu(Fecha* f, unsigned dias);


#endif // FECHAS_H
