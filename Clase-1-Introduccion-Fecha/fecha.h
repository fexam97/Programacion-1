#ifndef FECHA_H_
#define FECHA_H_

typedef struct
{
    int dia;
    int mes;
    int anio;
}
Fecha;

int esFechaValida(Fecha f);

#endif // FECHA_H_
