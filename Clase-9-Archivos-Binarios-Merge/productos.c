#include "productos.h"
#include "Movimientos.h"

#define CANT_REG 8 //cantidad registro
#define CANT_REG_PROD_MERGE 4
#define CANT_REG_MOV_MERGE 10

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


    fwrite(vecProd, sizeof(producto), CANT_REG, archF); //grabar

    fclose(archF);

    return TODO_OK;

}
int generarArchivoProductosMerge(const char* nombre)
{
    Movimiento vecProd [CANT_REG_PROD_MERGE] =
    {
        {"04",   "Banana",     40.5, 100},
        {"07",   "Pera",       50.7, 50},
        {"09",   "Manzana",    35.2, 70},
        {"12",   "Arandanos",  57.6, 30},
        {"14",   "Durazno",    78.3, 90}
    };

    FILE* archF = fopen("Productos.dat", "wb");

    if(!archF) /// archF == NULL
        return ERR_ARCHIVO;


    fwrite(vecProd, sizeof(producto), CANT_REG, archF); //grabar

    fclose(archF);

    return TODO_OK;

}
int generarArchivoMovimientosMerge(const char* nombre)
{
    Movimiento vecProd [CANT_REG_MOV_MERGE] =
    {
        {"01",    20},
        {"07",    20},
        {"08",    40},
        {"10",    40},
        {"10",    20},
        {"11",    50}
        {"12",    60},
        {"12",    70},
        {"15",    80},
        {"15",    40}
    };

    FILE* archF = fopen("Productos.dat", "wb");

    if(!archF) /// archF == NULL
        return ERR_ARCHIVO;


    fwrite(vecProd, sizeof(producto), CANT_REG, archF); //grabar

    fclose(archF);

    return TODO_OK;

}

int LeerArchivo(const char* nombre)  // al estilo elementos
{
    producto prod;

    FILE* prodF = fopen("Productos.dat", "rb");

    if(!prodF)
        return ERR_ARCHIVO;

    fread(&prod, sizeof(producto), 1, prodF);

    while(!feof(prodF))
    {
        mostrarProd(&prod);
        fread(&prod, sizeof(producto), 1 , prodF);
    }

    fclose(prodF);

    return TODO_OK;
}


void mostrarProd(const producto* prod)
{
    printf("%-15s\t%-15s\t%07.2f\t%04d\n", prod->codigo, prod->descripcion, prod->precio, prod->cant);
}


int actualizarPrecioProductos(const char* nombre, float porcentaje) // 10% de aumento
{
    producto prod;

    FILE* prodF = fopen("Productos.dat", "r+b");

    if(!prodF)
        return ERR_ARCHIVO;

    fread(&prod, sizeof(producto), 1, prodF);

    while(!feof(prodF))
    {
        prod.precio *= 1 + porcentaje / 100;
        fseek(prodF, -sizeof(producto), SEEK_CUR); // tira warning
        fwrite(&prod, sizeof(producto), 1 , prodF);
        fseek(prodF,0L, SEEK_CUR);
        fread(&prod, sizeof(producto), 1 , prodF);
    }

    fclose(prodF);

    return TODO_OK;
}

int actualizarStockProductos(const char* nombreProductos, const char* nombreMovimientos)
{
    FILE* prodF = fopen("Productos.dat", "rb");

    if(!prodF)
        return ERR_ARCHIVO;

    FILE* movF = fopen(nombreMovimientos, "rb");

    if(!movF)
        return ERR_ARCHIVO;

    FILE* prodTempF = fopen("ProductosTemp.tmp", "rb");

    if(!prodTempF)
        return ERR_ARCHIVO;

    producto prod, prodNue;
    Movimiento mov;

    prodNue.descripcion[0] = '\0';
    prodNue.precio = 0;

    int cmp; // comparacion

    fread(&prod, sizeof(producto), 1 , prodF);
    fread(&mov, sizeof(producto), 1 , movF);
    while(!feof(prodF) && !feof(movF))
    {
       cmp = strcmp(prod.codigo, mov.codigo); // comparacion entre los 2

       if(cmp == 0)
       {
           prod.cant += mov.cantidad;
           fread(&mov, sizeof(Movimiento), 1, movF);
       }

       if(cmp < 0)
       {
           fwrite(&prod, sizeof(producto), 1, prodTempF);
           fread(&prod, sizeof(producto), 1 , prodF);
       }

       if(cmp > 0)
       {
           strcpy(prodNue.codigo, mov.codigo);
           prodNue.cant = mov.cantidad;

           fread(&mov, sizeof(Movimiento), 1, movF);
           while(!feof(movF) && strcmp(mov.codigo, prodNue.codigo) == 0)
           {
               prodNue.cant += mov.cantidad;
               fread(&mov, sizeof(Movimiento),1 , movF);
           }

           fwrite(&prodNue, sizeof(producto), 1, prodTempF);
       }
    }

    while(!feof(movF))
    {
       strcpy(prodNue.codigo, mov.codigo);
           prodNue.cant = mov.cantidad;

           fread(&mov, sizeof(Movimiento), 1, movF);
           while(!feof(movF) && strcmp(mov.codigo, prodNue.codigo) == 0)
           {
               prodNue.cant += mov.cantidad;
               fread(&mov, sizeof(Movimiento),1 , movF);
           }

           fwrite(&prodNue, sizeof(producto), 1, prodTempF);
    }

    while(!feof(prodF))
    {
        fwrite(&prod, sizeof(producto), 1, prodTempF);
        fread(&prod, sizeof(producto), 1, prodF);
    }

    fclose(prodF);
    fclose(movF);
    fclose(prodTempF);

    remove(nombreProductos);
    rename("productos.tmp", nombreProductos);

    return TODO_OK;
}
