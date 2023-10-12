#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//CREAMOS ESTE METODO QUE NOS AYUDARA A LIMPIAR EL BUFFER PARA LAS CADENAS DE TEXTO
void empty_stdin() {
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}


//metodo principal
int main ()
{
	//variables para submenu operaciones
	 int res, res2, res3;
	 int x, suma, z,n;
	 
	 float a, b, resultado_negativo, resultado_positivo;
	 
	 float n1, n2, producto;
	 
	 float w1, q2,t;

    //variables para factorial y serie fibonacci
	  int i, numero;
      int factorial = 1;
      int y, d;
      long f1=0, f2=1, f3;
      
      //variables para la concatenadcion
      char nombre[20]="Eduardo";
      char apellido[20]="Orozco1";
      
      int c;
      
      //variables para la comparacion
      char xd1[20];
      char xd2[20];
      
      //variable para medir la longitud
      char lon1[100];
      
     char s1[20] = "Lenguaje C";
     char s2[20] = "NULL";
 

 

  //mensaje de bienvenida
  printf("\n");	
  printf("\t\t-----BIENVENIDO-----\n");
  printf("\tGracias por elegiir usar software de:\n");
  printf("\t\tOROZCO-S PROGRAMMING");
  printf("\n");
  printf("\n");
	 do//do while principal para menu semi infinito
   { 	
       //menu principal con opciones
       printf("\n\t\tMENU\t\t\n");
       printf("-Que desea hacer?\n");
       printf("1.- OPERACIONES BASICAS\n");
       printf("2.- CADENAS\n");
       printf("3.- SERIE FIBONACCI\n");
       printf("4.- FACTORIAL\n");
       printf("5.- SALIR\n\n");
       printf("Teclee su opcion:  ");
       scanf("%d", &res);
       printf("\n");
	   printf("\n");
	   
	   //switch principal
	   switch (res)
        {
        	case 1:
        		do{
        			  //sub-menu operaciones
                    printf("\n\t\tMENU\t\t\n");
                    printf("-Que desea hacer?\n");
                    printf("1.- SUMA\n");
                    printf("2.- RESTA\n");
                    printf("3.- MULTIPLICACION\n");
                    printf("4.- DIVISION\n");
                    printf("5.- REGRESAR\n\n");
                    printf("Teclee su opcion:  ");
                    scanf("%d", &res2);
                    printf("\n");
	                printf("\n");
	                
	                switch (res2)
                    {
                    	
                       case 1:
                       	//caso 1 de sumas de n numeros
                       	     suma = 0;
                       	     printf("Cuantos numeros va a Sumar?:  ");
                             scanf("%d", &z);
                             for (x=1; x<=z; x++)
                             {
                             	
                                 printf ("Inserte numero %d\n", x);
                                 scanf("%d",&n);
                                 suma=suma+n;
                             }
                             printf ("TOTAL: %d\n", suma);
                       break; 
                       case 2:
                       	//caso de resta de 2 numeros
        		           printf ("Ingresa el valor de N1: ");
                           scanf ("%f", &a);
                           printf ("Ingresa el valor de N2: ");
                           scanf ("%f", &b);

                            if(a>b)
                            {
                              resultado_positivo=a-b;
                              printf ("TOTAL: %g\n", resultado_positivo);
                            }
                            else
                            {
                            resultado_negativo=a-b;
                            printf ("TOTAL: %g\n", resultado_negativo);
                            }                      
                       break; 
                       case 3:
                       	//caso 3 para multiplicacion
                       	    printf( "Introduzca Numero 1: " );
                            scanf( "%f", &n1 );
                            printf( "\nIntroduzca Numero 2: " );
                            scanf( "%f", &n2 );

                             producto = n1 * n2;

                             printf( "\nLa multiplicaciocn es: %f \n", producto );
                       break; 
                       case 4:
                       	//caso 4 divisiones
        		             printf ("Ingresa el valor de N1: ");
                             scanf ("%lf", &w1);
                             printf ("Ingresa el valor de N2: ");
                             scanf ("%lf", &q2);
                             if(w1<q2)
                              {
                              	t=q2/w1;
                                 printf("se dividio n2 entre n1, su total es: %lf",&t);
                              }
                              else
                              {
                                 t=w1/q2;
                                 printf("se dividio n1 entre n2, su total es: %lf", &t);
                              }
                       break; 
                       case 5:
        		       
                       break; 
                       
                       default:printf("Elija una opcion correcta");
                    }
                    
        			
				}while(res2!=5);
            break;      
			
			case 2:
				do{
				
        		  //sub-menu de cadenas
                    printf("\n\t\tMENU\t\t\n");
                    printf("-Que desea hacer?\n");
                    printf("1.- CONCATENAR\n");
                    printf("2.- COMPARACION\n");
                    printf("3.- LONGITUD\n");
                    printf("4.- COPIAR\n");
                    printf("5.- REGRESAR\n\n");
                    printf("Teclee su opcion:  ");
                    scanf("%d", &res3);
                    printf("\n");
	                printf("\n");
	                
	                switch (res3)
                    {
                    	case 1:
                    		//caso 1 de concatenar
                    	     //strcpy(nombre, apellido); //Lo que hay en apellido se copia a nombre
                    	     printf("Cadena 1: %s \n", nombre);
                    	     printf("Cadena 2: %s \n", apellido);
   
                    		 strcat(nombre, " "); //concateno con un espacio en blanco
                             strcat(nombre, apellido); //le añado la cadena apellido
                             printf("Cadena concatenada: %s \n", nombre);
                    		
                    		break;
                    	
                    	case 2:
                    		//caso 2 de comparacion
                    	     c = 0;
                             printf("Ingrese el texto 1: ");
				             scanf("%s",xd1);
				             printf("Ingrese el texto 2: ");
			                 scanf("%s",&xd2);
				             c = strcmp(xd1,xd2);//con strcmp comparamos los textos, sin identicos pasamos un 0
				                                 //como parametro a la variable c
			              	if(c==0)//si c es 0, entonces son identicos
							  {
					              printf("\nEl texto es identico");;
					              empty_stdin();
			                  }
							  else
							  {
				      	         printf("\nEl texto no es identico");
				      	         empty_stdin();
			 	              }
                    		
                    		break;
                    	
                    	case 3:
                    		//caso 3 de longitud
                    		printf("\nIngrese un texto para conocer la longitud: ");
				             scanf("%s",&lon1);
				             empty_stdin();
				             printf("\nLa Longitud de su testo es de: %d caracteres incluido el NULL",strlen(lon1));
                    		
                    		break;
                    		
                    	case 4:
                    		//caso 4 de copiar
                    		 printf("esto esta en s1: %s \n\n",&s1);
                    		 printf("esto esta en s2: %s \n\n",&s2);
                             memcpy(s2, s1, strlen(s1));
                             printf("Ahora esto esta en S2: %s\n", s2);
                    		
                    		break;
                    	
                    	case 5:
                    		
                    		break;
                    	
						default: printf("Elija una opcion correcta ");	
                    }
                    
                }while(res3!=5);
                    
            break; 
			
			case 3:
				//serie fibonacci
	
               printf ("Ingrese la cantidad de terminos en la serie Fibonacci: ");
               scanf ("%d", &d);
               printf ("\nf0 = 0\n");
               //ciclo for que realiza la secuencia
               for (y=0; y<d; y++)
                 {
                   printf ("%ld\n", f2);              //prueba de escritorio de serie fibonacci de 5
                    f3 = f1 + f2;                     //   f1             f2               f3
                    f1 = f2;                          //    0              1                1
                    f2 = f3;                          //    1              1                2
                                                      //    1              2                3
                                                      //    2              3                5
                                                      //    3              5                8
                                                      //se imprime solo f2 = 1 - 1 - 2 - 3 - 5
                 }   		
            break; 
			
			case 4:
				//factorial de un numero

                 printf ("Ingrese un numero: ");
                 scanf ("%d", &numero);
                 printf ("\n%d! = 1", numero);
                 
                 //for de la secuencia factorial
                 for (i=2; i<=numero; i++)
                 {
                    factorial *= i; 
                    printf ("!  %d", i);
                 }
                  //prueba de escritorio de factorial de 4
                                                      //    i           factorial         numero
                                                      //    2              1                 4
                                                      //    3              2                 4 
                                                      //    4              6                 4  
													  //    5              2                 4       
                                                      //se imprime solo f2 = !1 - !2 - !3 - !4 = 24
                  printf (" = %ld\n\n", factorial);
            break; 
			
			case 5:
        		
            break;   
            
            default: printf("Elija una opcion validad");
        }
	   
	   
   }while(res!=5);
	return 0;
}

