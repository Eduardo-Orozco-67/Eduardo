#include <stdlib.h>
#include <stdio.h>
#include<string.h>

float alumno[10][6];
char nombre[10][100];
char meterias[6][300]={"Estructura de datos: ","Programacion orientada a objetos: ","Electricidad y Electronica: ","Calculo diferencial: ","Algebra Lineal: ","Metodologia de la investigacion: "};
int main() {
    int i, a, x,op;

    
        //Menú
        do{
            printf("\n-º-º-º-º-º-º-º-º-º-º-º-º-º-º-º-º-º-º-º-º-º-º-º-º\n");
            printf("\t- - - - - - - -MENU OPCIONES- - - - - - - - - - \n");
            printf("\t-|Elige la tarea que desaes realizar- - - - - - \n");
            printf("\n1.-|Ingresar datos de alumnos \n2.-|Mostrar los datosde los alumnos \n3.-|Salir\n");
            printf("\n-º-º-º-º-º-º-º-º-º-º-º-º-º-º-º-º-º-º-º-º-º-º-º-º\n");
            scanf("%i",&op);
        switch(op){
            case 1:
            
			for(x=0;x<10;x++)
			{
				fflush(stdin);
                printf("\n-º-º-º-º-º-º-º-º-º-º-º-º-º-º-º-º-º-º-º-º-º-º-º-º\n");
                printf("\n-|Ingrese el nombre del alumno %i: \n",(x+1));
                scanf("%100[^\n]",&nombre[x]);
                fflush(stdin);
			}	
            	
            for(i=0;i<10;i++){
            	printf("\n\n");
            	printf("\n-Alumno %s: \n",&nombre[i]);
            	for (a=0;a<6;a++)
            	{
                printf("\n-º-º-º-º-º-º-º-º-º-º-º-º-º-º-º-º-º-º-º-º-º-º-º-º\n");
                printf("-|Ingrese la califiacion de %s \n", &meterias[a]);
                scanf("%f", &alumno[i][a]);
               }
           }
        break;
            case 2:
                for(i=0;i<10;i++){
                printf("\n-|Alumno %s :\n",&nombre[i]);
                	for(a=0;a<6;a++)
            	{
                printf("-|%s %f \n", &meterias[a], alumno[i][a]);

             }
           }
           break;
            case 3:
                printf("-|Finalizando....");
                break;
            }
        }while (op!=3);
    
    return 0;
}
