#include <stdio.h>
#include <stdlib.h>

char *itoa(int numero, char* cadena, int base);

int main()
{
    int     nume,
            base = 10; /// <- probar con distintas bases [2, 36]

    char cad[33];

    nume = 0;
    itoa(nume, cad, base);
    puts(cad);

    nume = 28;
    itoa(nume, cad, base);
    puts(cad);

    nume = 2147483647; /// <-- maximo entero
    itoa(nume, cad, base);
    puts(cad);

    nume = -2147483648; /// <-- minimo entero
    itoa(nume, cad, base);
    puts(cad);

    return 0;
}

/** \brief itoaMio almacena en cadena los caracteres que representan a
            numero en la base de numeracion indicada

 * \param numero    (E)     entero a representar como cadena de caracteres
 * \param cadena    (S)     donde se almacenan los caracteres
 * \param base      (S)     base de numeracion a emplear
 * \return la direccion de comienzo de la cadena originalmente recibida
 *
 * \return la cadena recibida en el segundo argumento debe tener suficiente
        espacio - la base debe pertenecer al intervalo [2, 36]
 *
 */
char *itoa(int numero, char* cadena, int base)
{
    char *actual = cadena;
    char *inicio;

    if(numero < 0 && base == 10)
    {
        *actual = '-';
        numero = -numero;
        ++actual;
    }

    inicio = actual; /// "memorizo" comiendo de los digitos a invertir

    do
    {
        int resto = (unsigned)numero % base;
        numero /= base;
        *actual = 'n'; /// Luego vemos como obteber el caracter
        ++actual;
    }
    while(numero);

    *actual = '\0'; /// IMPORTANTISIMO: marca de fin de cadena
    /// falta invertir cadena

    return cadena;
}
