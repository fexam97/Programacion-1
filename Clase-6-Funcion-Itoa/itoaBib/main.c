#include <stdio.h>
#include <stdlib.h>


int main()
{
    int     nume,
            base = 10;  /// <-- probar con distintas bases [2, 36]
    char cad[33];

    nume = 0;
    itoa(nume, cad, base);
    puts(cad);

    nume = 28;
    itoa(nume, cad, base);
    puts(cad);

    itoa(-nume, cad, base);
    puts(cad);

    nume = 2147483647; /// <-- máximo entero;
    itoa(nume, cad, base);
    puts(cad);

    nume = -2147483648; /// <-- mínimo entero
    itoa(nume, cad, base);
    puts(cad);

    return 0;
}

