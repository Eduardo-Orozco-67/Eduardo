#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	//VARIABLES DECLARADAS
	int E, AA, AN;
	char nombre[25];
	float N1, N2, S;
	double M1, M2, M3 ,M4 , M5 , P;
	short xd=1;
//HOLA MUNDO + NOMBRE + CALCULO DE EDAD
	AA=2020;
	printf("Hola Mundo\n");
	printf("\nHola, porfavor dame tu nombre\n\n");
	gets(nombre);
	printf("\nTu nombre es: %s", nombre,"\n");
	printf("\n\nPor favor ahora dame tu anio de nacimiento\n\n");
	scanf("%d", &AN);
	E=AA-AN;
	printf("\n %s", nombre);
	printf(" Tu edad es: %d" , E);
	printf("\n%s", xd);
	 //VERIFICAION DE EDAD SI ES MAYOR O MENOR USANDO UNA CONDICIONAL
	     if(E>=18)
	     {
	        printf("\n\n ERES MAYOR DE EDAD");
	        
		 }
		 else
		 {
		 	printf("\n\n ERES MENOR DE EDAD\n");

		 }
		 
	//CALCULAR SUMA DE 2 NUMEROS N1 Y N2
	printf("\n\nBueno ahora necesito que me des 2 numeros para sumarlos\n");
	printf("\nDame numero 1\n");
	scanf("\n %f", &N1);
	printf("\nDame numero 2\n");
	scanf("\n %f", &N2);
	S=N1+N2;
	printf("\nTu suma da como resultado: %f", S );
	
	//CALCULAR PROMEDIO	
	printf("\n" );	
	printf( "\nAhora voy a sacar tu promedio de 5 materias\n");	
	printf("\nDame tu materia 1\n ");	
	scanf("\n %lf", &M1);
	printf("\nDame tu materia 2 \n");	
	scanf("\n %lf", &M2);
	printf("\nDame tu materia 3\n ");	
	scanf("\n %lf", &M3);
	printf("\nDame tu materia 4 \n");	
	scanf("\n %lf", &M4);
	printf("\nDame tu materia 5\n ");	
	scanf("\n %lf", &M5);
	P=(M1+M2+M3+M4+M5)/5;
	printf("\n\nTu promedio es: %lf", P);	
	
	//SABER SI EL ALUMNO APROBO USANDO UNA CONDICIONAL
	    if(P>=7)
     	{
     	  printf("\n\nFELICIDADES APROBASTE TU SEMESTRE ");	
	    }
	    else
	    {
	      printf("\n\nLO SIENTO TU REPROBASTE");	
		}
	
	//RETURN REGRESA UN VALOR
	return 0;
	//GETCH PARA O PAUSA EL PROGRAMA EJECUTADO EN LA CONSOLA
	getch();
}
