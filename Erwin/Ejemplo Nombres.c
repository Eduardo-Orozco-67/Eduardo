#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
 int filas, columnas , f=0, c=0;
 int i, x, y=0, z=0, s;
 float n;
 float **semes=NULL; //variables puntero para la creacion de los arreglos
 char **nom=NULL; 
	/*int contador;//Variable contadora de ciclos
	char nombre[5][20]; //Arreglo que guardara los nombres
	
	//Ciclo en el que solicitamos los nombres a ingresar
	for(contador=0;contador<5;contador++){
		printf("Ingresa un nombre: ");
		gets(nombre[contador]);
	}
	
	//Ciclo que imprime los nombres guardados
	printf("\nNombres ingresados: \n");	
	for(contador=0;contador<5;contador++){
		puts(nombre[contador]);
	} */
	
	nom= (char **)malloc ( c * sizeof(char) *128);
						    for(s=0; s<c; s++)
                        {
					     nom[s] =(char *)malloc (f*sizeof(char *));
					    }  
					    
					    
					    //pido e inicio el llenado del arreglo nombre            
					    for(y = 0; y < filas; y++)
						{   
						   for(x=0; x<columnas;x++)
					        fflush(stdin);
                            printf("Ingrese el nombre del alumno %d: \n", y+1);
		                    scanf("%s", &nom[y][x]);
		                }
		                
		                printf("\n");
                        printf("\n"); 
}
