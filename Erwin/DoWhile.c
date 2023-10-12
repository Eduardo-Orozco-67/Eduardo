#include <stdio.h>
#include <stdlib.h>

//Jose Eduardo Orozco Cradenas, B200077, 2.-E, Estructura de datos

int main(){ 

    int n, a=0, m; //variables locales 
	printf("\n");
	printf("Que numero va usar: \n\n");
	scanf("%i", &n); //leemos teclado
	printf("\n");
do{ // do while 
        a++;
		m=n*a;
		printf("%i * %i = %i\n", n, a, m); //impresion de la tabla
		printf("\n");
		m=0;
}while(a<10);
return 0;
}

