
#include "main.h"


int main()
{
    int     nume = 2059198198,
            base = 16;  /// <-- probar con distintas bases [2, 36]
    char    cad[33];

    itoaMio1(nume, cad, base);
    puts(cad);

    return 0;
}

