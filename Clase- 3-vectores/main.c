#include <math.h>
#include <time.h>

#include "vectores.h"

#define TAM_VEC 100

int main()
{
    int vec[TAM_VEC];
    int cantElem = 0;

    srand(time(NULL));
    /*
        int inserto;
        int i-1;

        do
        {
            inserto = insertarEnOrdenAsc(vec, &cantElem, TAM_VEC, rand() % 100);
            i++;
        }
        while(inserto && i <= TAM_VEC);

        if(!inserto)
            puts("El vector se lleno y no se insertaron los elementos");
    */

    for(int i = 1; i < TAM_VEC; i ++)
        insertarEnOrden(vec, &cantElem, TAM_VEC, rand() % 100);



    mostrarVec(vec, cantElem);

    return 0;
}
