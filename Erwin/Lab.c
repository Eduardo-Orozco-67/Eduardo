#include <stdio.h>
#include <stdlib.h>

//	by: Jose Eduardo Orozco Cradenas, B200077, 2.-E, Estructura de datos

		char nom[40]; //variable nombre de tipo cadena de texto
		 int  res; //variables 
void menu(){
	  
			printf("\n");
		printf("     -----   MENU   -----   ");
			printf("\n");
		printf("\n");
		printf(" 1) |  TABLAS DE MULTIPLICAR  |\n 2) |    TABLA DE PITAGORAS   |\n 3) |    REGISTRAR NOMBRE     |\n 4) |   VER NOMBRE GUARDADO   |\n 5) |         LIMPIEZA        | \n 6) |          SALIR          | \n");
		printf("\n");
		printf("Digite una opcion: \n");
		scanf("%i", &res); //leemos opcion
		printf("\n");
}

void multiplicaciones(){ 
	int n, a, m; //variables locales 
	printf("\n");
	printf("Que numero va usar: \n\n");
	scanf("%i", &n); //leemos teclado
	printf("\n");
	for( a = 1; a <= 10; a++) // for que imprime los resultados 
	{
		m=n*a;
		printf("%i * %i = %i\n", n, a, m); //impresion de la tabla
		printf("\n");
		m=0;
	}
	printf("\n");
} 

void pitagoras(){ 

	int tabla [10][10]; //matriz 
	int g, j; //variables contadoras
	
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

void nombre(){

		fflush(stdin); //limpia el buffer 
				printf("\n");
				printf("Porfavor ingresa tu nombre completo: \n");
				scanf("%[^\n]", nom); //hack, xd, para leer cadenas de texto con la funcion scanf(%[^\n]
				printf("\n");
}

void alerta()
{
				if(nom[40] >  nom[1])
				{ //revisamos si por lo menos hay un caracter guardado en la variable de nombre
					printf("\n");
					printf(" No has guardado un nombre. por favor hazlo \n\n"); //impresion de mensaje 
				}
				else
				{
					printf("\n");
					printf("Tu nombres es: %s\n\n", nom); //impresion de nombre
				}
}


void swwitch()
{
	do{ // do while 
        menu();
		switch(res){
			case 1:
				multiplicaciones(); //llama a la fun multi
			break; 
			
			case 2:
				pitagoras(); //llamada a la fun pita
			break; 
			
			case 3:
				nombre();
			break;
			
			case 4:
				alerta();
			break;
			
			case 5:
				system("cls"); //limpiamos la pantalla 
			break;
			
			case 6:
				printf("\n");
				printf("Adios, buen dia\n\n");
			break;
			
			default:
				printf("\n");
				printf("Opcion Ivalida, elige una opcion correcta \n\n"); //invalido
		}
	}while(res != 6); //fin del do while

	
}


void main(){ 
	 swwitch();

} //fin de la funcion main 
