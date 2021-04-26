#include <stdio.h>
#include <stdlib.h>

char *itoaMio1(int numero, char *cadena, int base);


int main()
{
    int     nume = 0x7ABCDEF6,
            base = 16;  /// <-- probar con distintas bases [2, 36]
    char    cad[33];

    itoaMio1(nume, cad, base);
    puts(cad);

    return 0;
}

/** \brief itoaMio almacena en cadena los caracteres que representan a numero
 *      en la base de numeraci�n indicada
 * \param numero    (E)     entero a representar como cadena de caracteres
 * \param cadena    (S)     d�nde se almacenan los caracteres
 * \param base      (S)     base de numeraci�n a emplear
 * \return la direcci�n de comienzo de la cadena originalmente recibida
 *
 * \remark  la cadena recibida en el segundo argumento debe tener suficiente
 *      espacio - la base debe pertenecer al intervalo [2, 36]
 */
char *itoaMio1(int numero, char *cadena, int base)
{
    char   *actual = cadena,
           *inicio;

    if(numero < 0 && base == 10)
    {
        *actual = '-';
        numero = -numero;
        ++actual;
    }
    inicio = actual;    /// "memorizo" comienzo de los d�gitos a invertir
    do
    {
        int resto = (unsigned)numero % base;
        numero /= base;
///     *actual = 'n'; /// luego vemos c�mo obtener el car�cter
        if(resto < 10)
            *actual = '0' + resto;
        else
            *actual = 'a' + resto - 10;
        ++actual;
    } while(numero);
    *actual = '\0';    /// IMPORTANT�SIMO: marca de fin de cadena
    /// falta invertir la cadena
    return cadena;
}

