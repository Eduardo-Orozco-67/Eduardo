
#include <stdio.h>

int main (void)
{
    int numero_binario, numero_decimal;
    printf ("Ingrese el valor de numero binario: ");
    scanf ("%d", &numero_binario);
    (void) getchar ();
    numero_decimal=(numero_binario%1000-numero_binario%100)/25+(numero_binario%100-numero_binario%10)/5+numero_binario%10;
    printf ("Valor de numero decimal: %d\n", numero_decimal);
    putchar ('\n');
    system ("pause");
    return 0;
}

