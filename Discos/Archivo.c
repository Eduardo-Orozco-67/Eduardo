
#include <stdio.h>
#include <stdlib.h>
int main() {
    int i=3;    
    char cadena1 [] = "Aprender a programar (linea 1)\n";
    char cadena2 [] = "requiere esfuerzo (linea 2)\n";
    char cadena3 [] = "y dedicacion (linea 3)\n";
    FILE* fichero;     
    fichero = fopen("cursoAF1.txt", "wt");
    fprintf (fichero, "%s%s%sEscritas %d+1 lineas en fichero", cadena1, cadena2, cadena3, i);
    fclose(fichero);     printf("Proceso completado");
    return 0;
}
