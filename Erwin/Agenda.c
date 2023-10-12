
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int i = 0, n=0, d=0, t=0, e=0, dain ; //variables globales para los datos 
short res, res2; //variables globales para los menus

//struct usado llamado agenda
struct agenda
{ 

 char nombre[ 85 ];
 char direccion[ 100 ];
 char telefono[ 11 ];
 char email[ 60 ];
 
}datos[ 10 ]; //nombre dado para su invocacion 

int main ()
{
  
  printf("\n");	
  printf("\t\t-----BIENVENIDO-----\n");
  printf("\tGracias por elegiir usar software de:\n");
  printf("\t\tOROZCO-S PROGRAMMING");
  printf("\n");
  printf("\n");
  
   do{ 	
     //menu principal
    printf("\n\t\tMENU\t\t\n");
    printf("-Que desea hacer?\n");
    printf("1.- AGREGAR NOMBRE\n");
    printf("2.- AGREGAR DIREECCION\n");
    printf("3.- AGREGAR TELEFONO\n");
    printf("4.- AGREGAR EMAIL\n");
    printf("5.- MOSTRAR DATOS\n");
    printf("6.- LIMPIAR PANTALLA\n");
    printf("7.- SALIR\n\n");
    printf("***Teclee su opcion:  ");
    scanf("%d", &res);
    printf("\n");
	printf("\n");
    
        switch (res)
        {
        	case 1:
        		if (n==0)
        		{
        			fflush(stdin);
                    printf("Ingrese el nombre %d: ", (n+1));
		            scanf("%85[^\n]", datos[n].nombre);	   
		            fflush(stdin);
		            n++;
		            printf("\n");
		            printf("\n");
				}
				else if (n>0 && n<10)
				{
					fflush(stdin);
                    printf("Ingrese el nombre %d: ", (n+1));
		            scanf("%85[^\n]", datos[n].nombre);	   
		            fflush(stdin);
		            n++;
		            printf("\n");
		            printf("\n");
				}
				else{ printf("Ya se alcanzo el maximo permitido");}
				
        		break;
        		
        	case 2:
				
        		if (d==0)
        		{
        			fflush(stdin);
                    printf("Ingrese la direccion %d: ", (d+1));
		            scanf("%100[^\n]", datos[d].direccion);	   
		            fflush(stdin);
		            d++;
		            printf("\n");
		            printf("\n");
				}
				else if (d>0 && d<10)
				{
					fflush(stdin);
                    printf("Ingrese la direccion %d: ", (d+1));
		            scanf("%100[^\n]", datos[d].direccion);	   
		            fflush(stdin);
		            d++;
		            printf("\n");
		            printf("\n");
				}
				else{ printf("Ya se alcanzo el maximo permitido");}
			   
        		break;
        		
        	case 3:
        		if (t==0)
        		{
        			fflush(stdin);
                    printf("Ingrese el telefono %d (Porfavor solo 10 digitos y sin espacios): ", (t+1));
		            scanf("%11[^\n]", datos[t].telefono);   
		            fflush(stdin);
		            t++;
		            printf("\n");
		            printf("\n");
				}
				else if (t>0 && t<10)
				{
					fflush(stdin);
                    printf("Ingrese el telefono %d (Porfavor solo 10 digitos y sin espacios):", (t+1));
		            scanf("%11[^\n]", datos[t].telefono);	   
		            fflush(stdin);
		            t++;
		            printf("\n");
		            printf("\n");
				}
				else{ printf("Ya se alcanzo el maximo permitido");}
        		
        		break;
        		
        	case 4:
        		if (e==0)
        		{
        			fflush(stdin);
                    printf("Ingrese el email %d: ", (e+1));
		            scanf("%60[^\n]", datos[e].email);	   
		            fflush(stdin);
		            e++;
		            printf("\n");
		            printf("\n");
				}
				else if (e>0 && e<10)
				{
					fflush(stdin);
                    printf("Ingrese el email %d: ", (e+1));
		            scanf("%60[^\n]", datos[e].email);	   
		            fflush(stdin);
		            e++;
		            printf("\n");
		            printf("\n");
				}
				else{ printf("Ya se alcanzo el maximo permitido");}
        
        		break;
        	
        	case 5:
        		if( n==0 || d==0 || t==0 || e==0)
	               	{
	               		printf("Aun no estan todos los datos");
	               		printf("\nVaya a la opcion 1 para empezar a llenar datos");
	               		printf("\n"); 
					    printf("\n");   
					}
				else {
			
			printf("NOTA: Si ha registrado datos sin hacer un registro de nombre\n");
			printf("No podra ver los detalles de contacto guardado\n");

        		 for(i=0;i<n;i++) //for para imprimir resultados de vector disco
            { 
               printf("\n");
		       printf("\n");
               printf("\t____________________________________________________________________________________________________________\n");
               printf("\t%s\t|\t", datos[i].nombre);
               printf("  %s\t|",datos[i].direccion);
               printf("\t%s\t  |",datos[i].telefono);
               printf("\t%s\t |\n",datos[i].email);
               printf("\t____________________________________________________________________________________________________________\n");
            } //fin for
               printf("\n");
		       printf("\n");
        	}
        		break;
        	
        	case 6:
        		
        		system("cls");
        		
        		break;
        	
        	case 7:
        		
        		  printf("\n");
        		  printf("Adios, tenga buen dia, gracias por usar software de:\n");
                  printf("\t\tOROZCO-S PROGRAMMING");
                  printf("\n");
                  printf("\n");
        		
        		break;
        		
        	default:  printf("INCORRECTO\n\n");
		}
		
		}while(res!=7);
 return 0;
 system("pause");
 agenda(free);
}
