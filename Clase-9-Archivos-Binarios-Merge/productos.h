#ifndef PRODUCTOS_H
#define PRODUCTOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERR_ARCHIVO 1
#define TODO_OK 0

#define ARG_NOM_ARCH_PROD 1
#define ARG_NOM_ARCH_MOV 2

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
int generarArchivoProductosMerge(const char* nombre);
int generarArchivoMovimientosMerge(const char* nombre);
int LeerArchivo(const char* nombre);
void mostrarProd(const producto* prod);
int actualizarPrecioProductos(const char* nombre, float porcentaje);
int actualizarStockProductos(const char* nombreProductos, const char* nombreMovimientos);


#endif // PRODUCTOS_H
