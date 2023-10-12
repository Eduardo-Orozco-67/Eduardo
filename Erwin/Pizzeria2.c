#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>// Booleanos

int i = 0, n=0, d=0, t=0, e=0, mayor, mes=0; //variables globales para los datos 
bool x=false, y=true;
short res, res2; //variables globales para los menus
char meses[12][110]={"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
//struct usado llamado pizzas
struct pizzas
{ 

 char nombre[ 85 ];
 int nve, nvf, nvm, nva, nvma, nvj, nvju, nvag, nvs, nvo, nvn, nvd;
 
}pizzeria[ 5 ]; //nombre dado para su invocacion 



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
        		
        		if (y==true)
        		{
				
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
                    y=false;
				}
				else{ printf("Ya se alcanzo el maximo permitido");}
			    }
			    else{ printf("Primero termine el registro anterior"); printf("\n"); printf("\n");}
        		break;
        		
        	case 2:
				
				if (x==true)
				{
				
        		if (d>=0 && d<5)
        		{
				    t=0; 	
                    printf("Ingrese la cantidad de venta que vendio el vendedor %d en el mes de %s:", (d+1), meses[t]);
		            scanf("%d", &pizzeria[d].nve);
		            printf("\n");
		             t++;
		            printf("Ingrese la cantidad de venta que vendio el vendedor %d en el mes de %s:", (d+1), meses[t]);
		            scanf("%d", &pizzeria[d].nvf);
		            printf("\n");
		             t++;
                    printf("Ingrese la cantidad de venta que vendio el vendedor %d en el mes de %s:", (d+1), meses[t]);
		            scanf("%d", &pizzeria[d].nvm);
		            printf("\n");
		             t++;
		            printf("Ingrese la cantidad de venta que vendio el vendedor %d en el mes de %s:", (d+1), meses[t]);
		            scanf("%d", &pizzeria[d].nva);
		            printf("\n");
		             t++;
		            printf("Ingrese la cantidad de venta que vendio el vendedor %d en el mes de %s:", (d+1), meses[t]);
		            scanf("%d", &pizzeria[d].nvma);
		            printf("\n");
		             t++;
		            printf("Ingrese la cantidad de venta que vendio el vendedor %d en el mes de %s:", (d+1), meses[t]);
		            scanf("%d", &pizzeria[d].nvj);
		            printf("\n");
		             t++;
		            printf("Ingrese la cantidad de venta que vendio el vendedor %d en el mes de %s:", (d+1), meses[t]);
		            scanf("%d", &pizzeria[d].nvju);
		            printf("\n");
		             t++;
		            printf("Ingrese la cantidad de venta que vendio el vendedor %d en el mes de %s:", (d+1), meses[t]);
		            scanf("%d", &pizzeria[d].nvag);
		            printf("\n");
		             t++;
		            printf("Ingrese la cantidad de venta que vendio el vendedor %d en el mes de %s:", (d+1), meses[t]);
		            scanf("%d", &pizzeria[d].nvs);
		            printf("\n");
		             t++;
		            printf("Ingrese la cantidad de venta que vendio el vendedor %d en el mes de %s:", (d+1), meses[t]);
		            scanf("%d", &pizzeria[d].nvo);
		            printf("\n");
		             t++;
		            printf("Ingrese la cantidad de venta que vendio el vendedor %d en el mes de %s:", (d+1), meses[t]);
		            scanf("%d", &pizzeria[d].nvn);
		            printf("\n");
		             t++;
		            printf("Ingrese la cantidad de venta que vendio el vendedor %d en el mes de %s:", (d+1), meses[t]);
		            scanf("%d", &pizzeria[d].nvd);
		            printf("\n");
		            printf("\n");
                   
		            d++;
		            x=false;
		            y=true;
				}
				else{ printf("Ya se alcanzo el maximo permitido");}
			   }
			   else{ printf("Primero registre nombre"); printf("\n"); printf("\n");}
			   
        		break;
        		
        	case 3:
        		if( n==0 || d==0 )
	               	{
	               		printf("Aun no estan todos los datos");
	               		printf("\nVaya a la opcion 1 para empezar a llenar datos");
	               		printf("\n"); 
					    printf("\n");   
					}
					
				else {


        		       for(i=0;i<n;i++) //for para imprimir resultados de vector disco
                       { 
                          mayor=pizzeria[i].nve;
                                                 
                              if (mayor < pizzeria[i].nvf)
                               {
                                mes=1;
						       }
							   
                            	   if (mayor < pizzeria[i].nvm)
                                     {
                            	        mes=2;
							         }

							              if (mayor < pizzeria[i].nva)
                                             
											 {
                            	              mes=3;
							                 }

							    
							                   if (mayor < pizzeria[i].nvma)
                                                 {
                            	                    mes=4;
							                     }
							                     

							                       if (mayor < pizzeria[i].nvj)
                                                   {
                            	                       mes=5;
							      				   }

						
							                          if (mayor < pizzeria[i].nvju)
                                                      {
                            	                        mes=6;
                            	                       }
							      				       

														  
							                             if (mayor < pizzeria[i].nvag)
                                                          {
                            	                            mes=7;
                            	                          }

								  				  
							                                if (mayor < pizzeria[i].nvs)
                                                               {
                            	                                   mes=8;
																}

								  				  
							                                    if (mayor < pizzeria[i].nvo)
                                                                {
                            	                                   mes=9;
							      					            }

								  			  
							                                     if (mayor < pizzeria[i].nvn)
                                                                   {
                            	                                      mes=10;
                            	                                   } 
							      							  
							                                           if (mayor < pizzeria[i].nvd)
                                                                         {
                            	                                            mes=11;
		                                                                } 
		                                                            
		                  printf("\n");
		                  printf("El mayor mes de ventas del empleado ");
		                  printf("%s es %s,con una venta de %d", pizzeria[i].nombre, meses[mes]);
		                  printf("\n");
		                  printf("\n");
        		       }
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

						     printf("\t_______________________________________________________________\n");
                             printf("\t|\t%s    |\t%d\t|\n",&meses[e],pizzeria[i].nve );
                             printf("\t_______________________________________________________________\n");
                             e++;
						     printf("\t_______________________________________________________________\n");
                             printf("\t|\t%s    |\t%d\t|\n",&meses[e],pizzeria[i].nvf );
                             printf("\t_______________________________________________________________\n");
                             e++;
   						     printf("\t_______________________________________________________________\n");
                             printf("\t|\t%s    |\t%d\t|\n",&meses[e],pizzeria[i].nvm );
                             printf("\t_______________________________________________________________\n"); 
							 e++;                         
   						     printf("\t_______________________________________________________________\n");
                             printf("\t|\t%s    |\t%d\t|\n",&meses[e],pizzeria[i].nva );
                             printf("\t_______________________________________________________________\n");
							 e++;    
						     printf("\t_______________________________________________________________\n");
                             printf("\t|\t%s    |\t%d\t|\n",&meses[e],pizzeria[i].nvma );
                             printf("\t_______________________________________________________________\n");	
							 e++;					 
						     printf("\t_______________________________________________________________\n");
                             printf("\t|\t%s    |\t%d\t|\n",&meses[e],pizzeria[i].nvj );
                             printf("\t_______________________________________________________________\n");	
							 e++;						 
						     printf("\t_______________________________________________________________\n");
                             printf("\t|\t%s    |\t%d\t|\n",&meses[e],pizzeria[i].nvju );
                             printf("\t_______________________________________________________________\n");
							 e++;							 
						     printf("\t_______________________________________________________________\n");
                             printf("\t|\t%s    |\t%d\t|\n",&meses[e],pizzeria[i].nvag );
                             printf("\t_______________________________________________________________\n");	
							 e++;						 
						     printf("\t_______________________________________________________________\n");
                             printf("\t|\t%s    |\t%d\t|\n",&meses[e],pizzeria[i].nvs );
                             printf("\t_______________________________________________________________\n");	
                             e++;
						     printf("\t_______________________________________________________________\n");
                             printf("\t|\t%s    |\t%d\t|\n",&meses[e],pizzeria[i].nvo );
                             printf("\t_______________________________________________________________\n");	
							 e++;						 
						     printf("\t_______________________________________________________________\n");
                             printf("\t|\t%s    |\t%d\t|\n",&meses[e],pizzeria[i].nvn );
                             printf("\t_______________________________________________________________\n");	
							 e++;						 
						     printf("\t_______________________________________________________________\n");
                             printf("\t|\t%s    |\t%d\t|\n",&meses[e],pizzeria[i].nvd );
                             printf("\t_______________________________________________________________\n");							 		 						 
                           
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
