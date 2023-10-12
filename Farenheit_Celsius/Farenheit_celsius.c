#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {
	int fahrenheit, celsius;
	printf("Porfavor introduce tus grados Fahrenheit como un entero\n");
	scanf("%d", &fahrenheit);
	celsius=(fahrenheit-32)/1.8;
	printf("\n Tu me diste %d grados Fahrenheit que convertidos serian %d grados Celsius", fahrenheit, celsius);
	return 0;
	getch();
}
