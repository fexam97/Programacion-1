#include "productos.h"

#define CANT_REG 8 //cantidad registro

int generarArchivo(const char* nombre)
{
    producto vecProd [CANT_REG] =
    {
        {"PAPA",        "Papa",         40.5, 24},
        {"BATATA",      "Batata",       50.7, 34},
        {"ZANAHORIA",   "Zanahoria",    35.2, 120},
        {"FRUTILLA",    "Frutilla",     50.6, 100},
        {"BANANA",      "Banana",       78.3, 50},
        {"PERA",        "Pera",         45.5, 139},
        {"UVA",         "Uva",          47.8, 150},
        {"DAMASCO",     "Damasco",      40.7, 120}
    };


    FILE* archF = fopen("Productos.dat", "wb");

    if(!archF) /// archF == NULL
        return ERR_ARCHIVO;

    /// el problema de los archivos binario no se puede editar con el block de notas

    /// NO abrir un bloc de notas un archivo binario


    fwrite(vecProd, sizeof(producto), CANT_REG, archF); //grabar

    fclose(archF);

    return TODO_OK;

}

int LeerArchivo(const char* nombre)  // al estilo elementos
{
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
}


void mostrarProd(const producto* prod)
{
    printf("%-15s\t%-15s\t%07.2f\t%04d\n", prod->codigo, prod->descripcion, prod->precio, prod->cant);
}
