/************** la unica forma de generar archivo es haciendo      FILE* prodF = fopen("Productos.dat", "rb") 
y no con     FILE* prodF = fopen(nombre, "rb"); *******************************/


#include "productos.h"

/// Archivos.exe Productos.dat
int main(int argc, char* argv[])        // argc: contador de argumentos, algo asi entendi
                                        // argv[]: vector de argumentos

{
    //if( generarArchivo(argv[ARG_NOM_ARCH]) == ERR_ARCHIVO)

    if(argc != 3) // project -> set programs' arguments -> escriben Productos.dat 10 -> OK y listo deberia leer bien
    {
        puts("Error invocando al programa. Cantidad incorrecta de argumentos.");
        return ERR_INV_ARG;
    }

    puts("Antes de actualizar:");

    int ret = LeerArchivo(argv[ARG_NOM_ARCH]);

    if(ret == ERR_ARCHIVO)
    {
        puts("No se pudo leer el archivo");
        return ERR_ARCHIVO;
    }

  /********************* ACTUALIZO ********************************/
  
    float porcentaje = atof(argv[ARG_PORC_ACT]); // atof covierte cadena en float

    ret = actualizarPrecioProductos(argv[ARG_NOM_ARCH], porcentaje);

    if(ret != TODO_OK)
    {
        puts("No se pudo actualizar el archivo");
        return ret;
    }

    /************ VUELVO A MOSTRAR EL ARCHIVO ***************/

    puts("\n Despues de actualizar:");

     ret = LeerArchivo(argv[ARG_NOM_ARCH]);

    if(ret == ERR_ARCHIVO)
    {
        puts("No se pudo leer el archivo");
        return ERR_ARCHIVO;
    }


    puts("\n\n fijenseN como cambio el precio");

    // si compilan muchas veces, veran que los precios estan aumentando

    return 0;
}

