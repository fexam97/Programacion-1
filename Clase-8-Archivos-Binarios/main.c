#include "productos.h"

/// Archivos.exe Productos.dat
int main(int argc, char* argv[])        // argc: argumento cuenta
                                        // argv[]: vector de argumento

{
    if(argc != 2)
    {
        puts("Error invocando al programa. Cantidad incorrecta de argumentos.");
        return ERR_INV_ARG;
    }

/*
  if(generarArchivo(argv[ARG_NOM_ARCH]) == ERR_ARCHIVO)
    {
      puts("No se pudo abrir el archivo.");
      return ERR_ARCHIVO;
    }
*/

    printf("puto");

    producto prod;

    FILE* prodF = fopen(argv[ARG_NOM_ARCH], "rb");

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
