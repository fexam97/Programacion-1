/************** la unica forma de generar archivo es haciendo      FILE* prodF = fopen("Productos.dat", "rb") 
y no con     FILE* prodF = fopen(nombre, "rb"); *******************************/


#include "productos.h"

/// Archivos.exe Productos.dat

int main(int argc, char* argv[])        // argc: argumento cuenta ( no lo usó)
                                        // argv[]: vector de argumento

{
    if( generarArchivo(argv[ARG_NOM_ARCH]) == ERR_ARCHIVO)
    {
        puts("Error invocando al programa. Cantidad incorrecta de argumentos.");
        return ERR_ARCHIVO;
    }


    producto prod;

    FILE* prodF = fopen("Productos.dat", "rb");

    if(!prodF)
    {
        puts("No se pudo abrir el archivo");
        return ERR_ARCHIVO;
    }

    fread(&prod, sizeof(producto), 1, prodF);

    while(!feof(prodF))
    {
        mostrarProd(&prod);
        fread(&prod, sizeof(producto), 1 , prodF);
    }

    fclose(prodF);



    return 0;
}
