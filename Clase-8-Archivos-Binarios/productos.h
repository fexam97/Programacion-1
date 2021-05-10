#ifndef PRODUCTOS_H
#define PRODUCTOS_H

#include <stdio.h>
#include <stdlib.h>

#define ERR_ARCHIVO 1
#define TODO_OK 0
#define ARG_NOM_ARCH 1
#define ERR_INV_ARG 1

typedef struct
{
   char codigo[16];
   char descripcion[51];
   float precio;
   int cant;
}
producto;

int generarArchivo(const char* nombre);
void mostrarProd(const producto* prod);


#endif // PRODUCTOS_H
