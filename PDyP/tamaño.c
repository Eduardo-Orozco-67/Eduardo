
#include <stdio.h>

#include <stdlib.h>

int main() {

    int i = 0; int j=0; char pruebaCadena [] = "abc";

    while (pruebaCadena[i] != '\0') { printf ("%c", pruebaCadena[i]); i=i+1; }

    printf ("%cUsando \\0: ", '\n');

    while (pruebaCadena[j] != '\0') { printf ("Iteracion %d - ", j+1); j=j+1; }

    printf ("%cUsando sizeof: ", '\n');

    j= 0; //Reinicializar j

    while (j < sizeof(pruebaCadena)) { printf ("Iteracion %d - ", j+1); j=j+1; }

    printf ("\nsizeof pruebaCadena es %d", sizeof(pruebaCadena));

    return 0; // Ejemplo aprenderaprogramar.com

}
