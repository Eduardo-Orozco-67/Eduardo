#include <stdio.h>
#include <stdlib.h>

//	by: Jose Eduardo Orozco Cradenas, B200077, 2.-E, Estructura de datos

int main(){

int tabla [10][10]; //matriz 
	int g, j; //variables contadoras
	printf("Hola buen dia\n");
	printf("Aqui esta la tebla de pitagoras\n");
	// hacermos las operaciones para llenar la tabla
	for(j = 0; j < 10; j++){ //filas
	
		for(g = 0; g < 10; g++){ //columnas
			tabla[j][g] = (j + 1) * (g + 1); //hacemos cada operacion matematica para cada espacio
		}
	}

	//iniciamos ciclos for para la impresion de resultados 
	for(j = 0; j < 10 ; j++){ 
		printf("\n");
		for(g = 0; g < 10; g ++){ 
			printf("\t %i", tabla[j][g]); //impresion de la tabla 
		}
		printf("\n"); //salto de linea
	}
	printf("\n\n");
} 
