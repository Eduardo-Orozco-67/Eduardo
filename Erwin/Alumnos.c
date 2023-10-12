#include <stdio.h>
#include <stdlib.h>

 int filas=0, columnas=0, f=0, c=0;
 int i, x, y=0, z=0, s, m, n;
 float **semes=NULL; //variable puntero para la creacion del arreglo bidimensional dinamico
 char **nom=NULL;
                    
int main(){
int ress;
do{

printf("\nElija una opcion\n\n");
printf(" 1.-Guardar Datos\n 2.-Ver Posciciones de los Alumnos\n 3.-Ver un Alumno\n 4.-Ver todos los Alumnos\n 5.-Limpiar Pantalla\n 6.-Salir\n");
printf("\n");
printf("Digite opcion:  ");
scanf("%i", &ress); //leemos opcion
printf("\n");
printf("\n");

          switch(ress)//switch menu
              {
                   case 1:
                   	
                     //pedimos valor de las filas que sera equivalente a los alumnos
                     printf("Ingrese el numero de alumnos: ");
                         scanf("%i", &filas); //leemos filas
                         n=filas;
                      //pedimos valor de las columnas que sera equivalente a los semestres
                     printf("Ingrese el numero de materias: ");
                         scanf("%i", &columnas); //leemos columnas
                            
                    printf("\n");
                    printf("\n"); 
 
                    //declaro una matriz de tipo float para guardar calificaciones con punto flotante
                    //aqui empieza el uso de malloc y sizeof para asignar memoria a este arreglo bidimensional
                    //que lo que hace es llenar un arreglo llamdndo a un segundo arreglo, haciendo asi la matriz
                    
					 semes =(float **)malloc (filas * sizeof(float *));
					 
                     
                     //declaro un arreglo vectorial de tipo char para los nombres
                     //de igual forma le asigno memoria con malloc y sizeof
                     
                     nom=(char **)malloc (filas * sizeof(char *));
                     
                     //pregunto si la memoria es NULA
                     if (semes==NULL || nom==NULL)
                     {  printf("No se pudo asignar memoria"); }
                     else 
					 {
					 
					  //este for literalmente sirve para crear los 2 arreglos con asignacion de memoria
                     //como lo menciono antes
                       for(i=0; i<filas; i++)
                        {
					     semes[i] =(float *)malloc (columnas*sizeof(float *));
					    }	    
					   
					    for(s=0; s<filas; s++)
                        {
					     nom[s] =(char *)malloc (101*sizeof(char *));
					    }  

					    
					    //pido e inicio el llenado del arreglo nombre            
					  
					  //for para llenar la matriz de nombres
						   for(x=0; x<filas;x++)
						   {
						   	
						   	fflush(stdin);
                            printf("Ingrese el nombre del alumno %d: \n", x+1);
		                    scanf("%101[^\n]", nom[x]);	   
		                    fflush(stdin);
		                    printf("\n");
		                    printf("\n");
		                    
							}
		                printf("\n");
		                 
		                
		                //ciclos for para el llenado del arreglo dinamico de las calificaciones
						 for(f = 0; f < filas; f++){ //filas
                            
		                     for(c = 0; c < columnas; c++){ //columnas
		                    
		                     printf("Ingrese la calificacion de la materia %d del alumno %s : ", c+1, nom[f]);
		                     scanf("%f",&semes[f][c]);//llenado por teclado
	   	                     }
	   	                     printf("\n"); 
						     printf("\n");   
	                      }
	                     	     
                         }
                       
	               break;
	               
	               case 2:
	               	if( nom==NULL)
	               	{
	               		printf("Aun no hay datos");
	               		printf("\nVaya a la opcion 1 para llenar datos");
	               		printf("\n"); 
					    printf("\n");   
					}
	               	
	               	else
	               	{
	               	
	               		for(f = 0; f < filas; f++){ //filas
	               		
		                    printf("%d.- %s", f+1, nom[f]);
	   	                    printf("\n"); 
						    printf("\n");  
							 
	                      }
	                }
	               break;
	               
	               case 3:
	               	
	               	if( semes==NULL && nom==NULL)
	               	{
	               		printf("Aun no hay datos");
	               		printf("\nVaya a la opcion 1 para llenar datos");
	               		printf("\n"); 
					    printf("\n");   
					}
	               	
	               	else
	               	{

	               	 printf(" Que alumno desea ver ?:  ");
		               scanf("%d",&z);//llenado por teclado
		               
		               if(z>filas)
		               {
		               	printf("\nLo siento, no hay esa cantidad de alumnos");
	               		printf("\n"); 
					    printf("\n");   
					   }
					   else
					   {

		               if(z==1)
		               {
		               		for(f = 0; f < z; f++)//filas
							{ 
						      printf("\n");
							  printf("\n");							  
							  printf("     --------------------------------------------\n");
							  printf("     |\tKardex de %s\t|", nom[f] ); 
							  printf("\n");
							  printf("     --------------------------------------------\n");
						      printf("\n");
						      printf("\t-----------------------------------------\n");
						      printf("\t|UNACH C-IV, Facultad de Negocios, LIDTS|\n");
						      printf("\t-----------------------------------------\n");
						      printf("\n");
						      printf("\t-----------------------------------------\n"); 
		                      for(c = 0; c < columnas; c++)//columnas
							    { 
							       printf("\t|\tM%d", c+1);
		                           printf("\t|\t%f\t|\n",semes[z-1][c]);
		                           printf("\t-----------------------------------------\n");
	   	                        }
						     printf("\n");   
						     printf("\n");
						    }
					   }
					   else
					   {
	                      for(f = 0; f < 1; f++)//filas
						  { 
						   printf("\n");
						   printf("\n");
						   printf("     --------------------------------------------\n");
						   printf("     |\tKardex de %s\t|", nom[z-1] ); 
						   printf("\n");
						   printf("     --------------------------------------------\n"); 
						   printf("\n");
						   printf("\t-----------------------------------------\n");
						   printf("\t|UNACH C-IV, Facultad de Negocios, LIDTS|\n");
						   printf("\t-----------------------------------------\n");
						   printf("\n");
						   printf("\t-----------------------------------------\n"); 
		                     for(c = 0; c < columnas; c++)//columnas
							 { 
							   printf("\t|\tM%d", c+1);
		                        printf("\t|\t%f\t|\n",semes[z-1][c]);
		                        printf("\t-----------------------------------------\n");
	   	                     }

	   	                     printf("\n");
	   	                     printf("\n");
						  }
					    }
				      }
					 }
	               break;
				   
				   case 4:
				   	
				   		               	
	               	if( semes==NULL && nom==NULL)
	               	{
	               		printf("Aun no hay datos");
	               		printf("\nVaya a la opcion 1 para llenar datos");
	               		printf("\n"); 
					    printf("\n");   
					}
				   	else 
				   	{

				   	for(f = 0; f < filas; f++)//filas
						  { 
						   printf("\n");
						   printf("\n");
						   printf("     --------------------------------------------\n");
						   printf("     |\tKardex de %s\t|", nom[f] ); 
						   printf("\n");
						   printf("     --------------------------------------------\n"); 
						   printf("\n");
						   printf("\t-----------------------------------------\n");
						   printf("\t|UNACH C-IV, Facultad de Negocios, LIDTS|\n");
						   printf("\t-----------------------------------------\n");
						   printf("\n");
						   printf("\t-----------------------------------------\n"); 
		                     for(c = 0; c < columnas; c++)//columnas
							 { 
							   printf("\t|\tM%d", c+1);
		                        printf("\t|\t%f\t|\n",semes[f][c]);
		                        printf("\t-----------------------------------------\n");
	   	                     }

	   	                     printf("\n");
	   	                     printf("\n");
	   	                  }
	   	                }
				   
				   break;
				   
				   case 5:
				   	
				   	system("cls");
				   
				   break;  
				   
				   case 6:
				   	printf("Adios, tenga buen dia");
                   break;
                   default: printf("elige una opcion correcta");
	   	                    printf("\n");
	   	                    printf("\n");
				   }
	               
	}while(ress != 6); //fin del do while

free(semes);
free(nom);
return 0;
}
