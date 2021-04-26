
#include "stdiomio.h"

/** \brief itoaMio almacena en cadena los caracteres que representan a numero
 *      en la base de numeración indicada
 * \param numero    (E)     entero a representar como cadena de caracteres
 * \param cadena    (S)     dónde se almacenan los caracteres
 * \param base      (S)     base de numeración a emplear
 * \return la dirección de comienzo de la cadena originalmente recibida
 *
 * \remark  la cadena recibida en el segundo argumento debe tener suficiente
 *      espacio - la base debe pertenecer al intervalo [2, 36]
 */
char *itoaMio1(int numero, char *cadena, int base)
{
    char   *actual = cadena,
           *inicio;
    static const char letras[36] = { "0123456789abcdefghijklmnopqrstuvwxyz" };

    if(numero < 0 && base == 10)
    {
        *actual = '-';
        numero = -numero;
        ++actual;
    }
    inicio = actual;
    do
    {
        int resto = (unsigned)numero % base;
        numero /= base;
        *actual = letras[resto];
        ++actual;
    } while(numero);
    *actual = '\0';
    --actual;
    while(inicio < actual)
    {
        char    aux = *inicio;
        *inicio = *actual;
        *actual = aux;
        ++inicio;
        --actual;
    }
    return cadena;
}

