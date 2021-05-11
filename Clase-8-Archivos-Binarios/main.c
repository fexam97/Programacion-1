/************** la unica forma de generar archivo es haciendo      FILE* prodF = fopen("Productos.dat", "rb") 
y no con     FILE* prodF = fopen(nombre, "rb"); *******************************/


#include "productos.h"

/// Archivos.exe Productos.dat
int main(int argc, char* argv[])        // argc: argumento cuenta
                                        // argv[]: vector de argumento

{
    if( generarArchivo(argv[ARG_NOM_ARCH]) == ERR_ARCHIVO)
    {
        puts("Error invocando al programa. Cantidad incorrecta de argumentos.");
        return ERR_ARCHIVO;
    }


    if(LeerArchivo(argv[ARG_NOM_ARCH]) == ERR_ARCHIVO) // argv[1] == 1
    {
        puts("No se pudo leer el archivo");
        return ERR_ARCHIVO;
    }


    return 0;
}

