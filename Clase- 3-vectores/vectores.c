#include <stdio.h>

#include "vectores.h"

int insertarEnOrden(int v[], int* ce, int cap, int elem)
{
    if(*ce == cap)
        return 0;

    int posAct = (*ce) - 1;

    while(posAct >= 0 && elem < v[posAct])
    {
        v[posAct +1] = v[posAct];
        posAct--;
    }

    v[posAct + 1] = elem;

    (*ce)++;

    return 1;
}

void mostrarVec(int v[], int ce)
{
    for(int i = 0 ; i < ce ; i++)
    {
        printf("%d\n", v[i]);
        //(*v)++;
    }
}
