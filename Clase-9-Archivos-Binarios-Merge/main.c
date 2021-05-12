#include "productos.h"

/// Archivos.exe Productos.dat Movimientos.dat
int main(int argc, char* argv[])        // argc: argumento cuenta
                                        // argv[]: vector de argumento

{
    //if( generarArchivo(argv[ARG_NOM_ARCH]) == ERR_ARCHIVO)

    if(argc != 3) // era 3 en actualizar precio
    {
        puts("Error invocando al programa. Cantidad incorrecta de argumentos.");
        return ERR_INV_ARG;
    }
/*
    puts("Antes de actualizar:");

    int ret = LeerArchivo(argv[ARG_NOM_ARCH]);

    if(ret == ERR_ARCHIVO)
    {
        puts("No se pudo leer el archivo");
        return ERR_ARCHIVO;
    }

    float porcentaje = atof(argv[ARG_PORC_ACT]); // atof covierte cadena en float

    ret = actualizarPrecioProductos(argv[ARG_NOM_ARCH], porcentaje);

    if(ret != TODO_OK)
    {
        puts("No se pudo actualizar el archivo");
        return ret;
    }

     VUELVO A MOSTRAR EL ARCHIVO



    puts("\n Despues de actualizar:");

     ret = LeerArchivo(argv[ARG_NOM_ARCH]);

    if(ret == ERR_ARCHIVO)
    {
        puts("No se pudo leer el archivo");
        return ERR_ARCHIVO;
    }


    puts("\n\n fijenseN como cambio el precio");

    // si compilan muchas veces, veran que los precios estan aumentando
*/

    if( generarArchivoProductosMerge(argv[ARG_NOM_ARCH_PROD]) == ERR_ARCHIVO)
    {
        puts("No se pudo abrir el archivo");
        return ERR_ARCHIVO;
    }

    if( generarArchivoMovimientosMerge(argv[ARG_NOM_ARCH_MOV]) == ERR_ARCHIVO)
    {
        puts("No se pudo abrir el archivo");
        return ERR_ARCHIVO;
    }



    puts("Antes de Actualizar");

    int ret = mostrarProd(argv[ARG_NOM_ARCH_PROD]);

    if(ret == ERR_ARCHIVO)
    {
        puts("No se pudo leer el archivo");
        return ret;
    }

    ret = actualizarStockProductos(argv[ARG_NOM_ARCH_PROD], argv[ARG_NOM_ARCH_MOV]);

    puts("\n Despues de actualizar");

    ret = mostrarProd(argv[ARG_NOM_ARCH_PROD]);

    if(ret == ERR_ARCHIVO)
    {
        puts("No se pudo leer el archivo");
        return ret;
    }

    return 0;
}
