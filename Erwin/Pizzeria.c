#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>// Booleanos

int i = 0, n=0, d=0, t=0, e=0, mayor,p=0, mes; //variables globales para los datos 
bool x=false;
short res, res2; //variables globales para los menus
char meses[12][110]={"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
//struct usado llamado pizzas
struct pizzas
{ 

 char nombre[ 85 ];
 int nventasmes;
 
 
}pizzeria[ 5 ]; //nombre dado para su invocacion 

int arr [5][12];

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
    printf("1.- AGREGAR NOMBRE DE VENDEDOR\n");
    printf("2.- AGREGAR NUMERO DE VENTAS\n");
    printf("3.- VER MES CON MAYOR VENTA\n");
    printf("4.- VER TODOS LOS VENDEDORES\n");
    printf("5.- LIMPIAR PANTALLA\n");
    printf("6.- SALIR\n\n");
    printf("***Teclee su opcion:  ");
    scanf("%d", &res);
    printf("\n");
	printf("\n");
    
        switch (res)
        {
        	case 1:
        		
        		
        		if (n>=0 && n <5)
        		{
        			fflush(stdin);
                    printf("Ingrese el nombre del vendedor %d: ", (n+1));
		            scanf("%85[^\n]", pizzeria[n].nombre);	   
		            fflush(stdin);
		            n++;
		            printf("\n");
		            printf("\n");
                    x=true;
				}
				else{ printf("Ya se alcanzo el maximo permitido");}
				
        		break;
        		
        	case 2:
				
				if (x==true)
				{
				
        		if (d>=0 && d<5)
        		{
                    for (t=0;t<12;t++)
				    {
				    	
                        printf("Ingrese la cantidad de venta que vendio el vendedor %d en el mes de %s:", (d+1), meses[t]);
		                scanf("%d", &pizzeria[t].nventasmes);	 
						arr[d][t] =  pizzeria[t].nventasmes;
		                printf("\n");
		                printf("\n");
		            }
		            d++;
		            x=false;
				}
				else{ printf("Ya se alcanzo el maximo permitido");}
			   }
			   else{ printf("Primero registre nombre"); printf("\n"); printf("\n");}
			   
        		break;
        		
        	case 3:
        		for(i=0;i<n;i++) //for para imprimir resultados de vector disco
                  {      
                  mayor=arr[i][p];
					for(p=0;p<12;p++)
					{	
                        if (mayor < arr[i][p])
                          {
                          	mayor=arr[i][p];
                            mes++;
						  }
				    }
				          printf("\n");
		                  printf("El mayor mes de ventas del empleado ");
		                  printf("%s es %s", pizzeria[i].nombre, meses[mes]);
		                  printf("\n");
		                  printf("\n");
        	      }
        	    
        	    break;
        	    
        	case 4:
                if( n==0 || d==0 )
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
		                  printf("ventas por mes de: ");
		                  printf("\t|\t%s  \t|\n", pizzeria[i].nombre);
		                  for (e=0;e<12;e++)
		                  {
						     printf("\t_______________________________________________________________\n");
                             printf("\t|\t%s \t|\t%d\t|\n",&meses[e], arr[i][e]);
                             printf("\t_______________________________________________________________\n");
                             
                              
                          }
                        
                      } //fin for
                      printf("\n");
		              printf("\n");
        	        }
        
        		break;
        	
        	case 5:
        		
        		system("cls");
        		
        		break;
        	
        	case 6:
        		
        		  printf("\n");
        		  printf("Adios, tenga buen dia, gracias por usar software de:\n");
                  printf("\t\tOROZCO-S PROGRAMMING");
                  printf("\n");
                  printf("\n");
        		
        		break;
        		
        	default:  printf("INCORRECTO\n\n");
		}
		
		}while(res!=6);
 return 0;
 system("pause");
}
