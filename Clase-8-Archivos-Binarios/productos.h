#ifndef PRODUCTOS_H
#define PRODUCTOS_H

#include <stdio.h>
#include <stdlib.h>

#define ERR_ARCHIVO 1
#define TODO_OK 0
#define ARG_NOM_ARCH 1
#define ARG_PORC_ACT 2

#define ERR_INV_ARG 2

typedef struct
{
   char codigo[16];
   char descripcion[51];
   float precio;
   int cant;
}
producto;

int generarArchivo(const char* nombre);
int LeerArchivo(const char* nombre);
void mostrarProd(const producto* prod);
int actualizarPrecioProductos(const char* nombre, float porcentaje);


#endif // PRODUCTOS_H
