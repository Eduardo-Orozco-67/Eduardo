/*Menu de cds
by: Jose Eduardo Orozco Cardenas
USAMOS ESTRUCTURAS, ciclo do while, switch, arrays y funciones*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int i = 1, n ; //variables globales para los datos y ciclos for
short  res, res2; //variables globales para los contadores
FILE *varch = NULL ;
//struct usado llamado datos
struct datos
{ 
 int anio;
 double dur;
 int min;
 int seg;
 int ho;
 char titulo[ 85 ];
 char inter[ 85 ];
}s[ 1000 ]; //nombre dado para su invicacion 

typedef struct datos2{
 int an;
 int mi;
 int se;
 char *ti;
 char *in;
}est;

 
 est *e;

void menu() //funcion para hacer la estructura del menu                      |
{
	    //menu principal
    printf("\n\t\tMENU\t\t\n");
    printf("-Que desea hacer?\n");
    printf("1.- AGREGAR\n");
    printf("2.- VER GUARDADO\n");
    printf("3.- COPIAR TODO A UN ARCHIVO TXT\n");
    printf("4.- LEER UN ARCHIVO TXT Y LLENAR ARREGLO\n");
    printf("5.- LIMPIAR PANTALLA\n");
    printf("6.- SALIR\n\n");
    scanf("%d", &res);
} //fin funcion menu


void llenado() //funcion usada para el guardado de los datos                  |
{
	char b='_';
	
	      //sub menu
    	  printf("\n-Que desea hacer?\n");
    	  printf("1.- AGREGAR\n");
          printf("2.- REGRESAR\n");
    	  scanf("%d", &res2);
    	  
       switch(res2) //switch del submenu
       {
		   case 1:
          
          printf("\t\t\tDISCOS\t\t\n");
          printf("\n-Que disco desea guardar? O en su defecto, cuantos discos quiere guardar?\n");
          scanf("%d", &n); //cantidad a almacenar
          
          if(n>=1000) //no aceptamos mas de 999 discos
          {
          	printf("\nERROR, NO ACEPTO MAS DE 999 DISCOS\n");
		  }
          else
		  {
		  
		  	while(i<=n && n<1000) //while para repetir los mensajes de la toma de datos
            {
            	
          	   //entrada de datos 1 por 1
          	   
               printf("\n\n Inserte datos del disco %d\n",i);
               printf("\nInserte titulo del disco (NOTA: NO USE ESPACIO EN SU DEFECTO USE GUION BAJO _): \n");
                 scanf("%[^\n]s",s[i].titulo); 
				 //en este paso guardamos un dato en una variable estructura pasandola como paramatetro//
               printf("Inserte interprete (NOTA: NO USE ESPACIO EN SU DEFECTO USE GUION BAJO _:\n");
                  scanf("%[^\n]s",s[i].inter); 
               printf("Inserte anio de publicacion:\n");
                  scanf("%d",&s[i].anio);
                printf("Inserte la duracion en minutos\n");
                  scanf("%lf",&s[i].dur);
                s[i].min=(s[i].dur); //conversion a minutos y segundos
                s[i].ho=(s[i].min/60);
                s[i].seg=((s[i].dur- s[i].min)*100);
                i++; 
                
            } //fin while
             
             //impresion de resultados despues de llenar datos usando ciclo for asimilando una especie de tabla
             printf("\n\n\t\tVECTOR DISCOS COMPACTOS");
             printf("\n\t*****************************************************************************************\n");
             printf("\t#\t|\tTITULO\t\t|\tINTERPRETE\t|\tANIO PUBLICACION\t|\n");
             printf("\t*****************************************************************************************\n");
        
              for(i=1;i<=n;i++) //for para imprimir resultados de vector disco 
            {
               printf("\t_______________________________________________________________________________________\n");
               printf("\t%d\t|",i);
               printf("\t%s\t|\t",s[i].titulo);
               printf("%s\t|",s[i].inter);
               printf("\t%d\t  |\n",s[i].anio);
               printf("\t_______________________________________________________________________________________\n");
            } //fin for
            
             printf("\n\n\t\tVECTOR DURACION");
             printf("\n\t*****************************************************************************************\n");
             printf("\t#\t|\tTITULO\t\t|\tMINUTOS\t\t|\t  SEGUNDOS\t  |\n");
             printf("\t*****************************************************************************************\n");
              for(i=1;i<=n;i++) //for para imprimir resultados de vector duracion
            {
               printf("\t_______________________________________________________________________________________\n");
               printf("\t%d\t|",i);
               printf("\t%s\t|\t",s[i].titulo);
               printf("%d\t|",s[i].min);
               printf("\t%d\t  |\n",s[i].seg);
               printf("\t_______________________________________________________________________________________\n");
            }//fin for
             printf("\n\nUd esta en el disco %d, para agregar mas disco sumele la cantidad de discos que desea al disco que esta\n", i-1);
             printf("EJEMPLO: esta en el disco 4, si quiero agregar 6 mas entonces teclee 10\n");
		  	
		  	

		  }
	
           
		  break;
	     } //fin switch 2
}//fin de la funcion para el guardado de los datos


 void guardado() //funcion para ver los datos guardados  
        
		//impresion de resultados despues de llenar datos usando ciclo for asimilando una especie de tabla
  {
	         printf("\t\t\tGUARDADO\t\t\n");   
			 printf("\n\n\t\tVECTOR DISCOS COMPACTOS");  
             printf("\n\t*****************************************************************************************\n");
             printf("\t#\t|\tTITULO\t\t|\tINTERPRETE\t|\tANIO PUBLICACION\t|\n");
             printf("\t*****************************************************************************************\n");
        
              for(i=1;i<=n;i++) //for para imprimir resultados de vector disco
            { 
               printf("\t_______________________________________________________________________________________\n");
               printf("\t%d\t|",i);
               printf("\t%s\t|\t",s[i].titulo);
               printf("%s\t|",s[i].inter);
               printf("\t%d\t  |\n",s[i].anio);
               printf("\t_______________________________________________________________________________________\n");
            } //fin for
            
            
             printf("\n\n\t\tVECTOR DURACION");
             printf("\n\t*****************************************************************************************\n");
             printf("\t#\t|\tTITULO\t  |\tMINUTOS\t\t|\t\tSEGUNDOS\t|\n");
             printf("\t*****************************************************************************************\n");
             
              for(i=1;i<=n;i++) //for para imprimir resultados de vector duracion
            {
               printf("\t_______________________________________________________________________________________\n");
               printf("\t%d\t|",i);
               printf("\t%s\t|\t",s[i].titulo);
               printf("%d\t|",s[i].min);
               printf("\t%d\t  |\n",s[i].seg);
               printf("\t_______________________________________________________________________________________\n");
            } //fin for 
			    
          printf("\n\nUd esta en el disco %d, para agregar mas disco sumele la cantidad de discos que desea al disco que esta\n", i-1);
          printf("EJEMPLO: esta en el disco 4, si quiero agregar 6 mas entonces teclee 10\n");
  } //Fin funcion guardar


	void Archivo(){
             	int a=1;
             	// Apuntador a la estructura de tipo Per Process File Table
	        
	        //  w - write, r - read
	        varch = fopen("C:\\Users\\vikig\\OneDrive\\Documentos\\C\\distFin.txt", "a+");
	         if( varch == NULL ){
		      printf("No se pudo abrir para escritura el archivo \n");
	        }
	        while(a<=n && n<1000){
;
		    fprintf( varch, "%s|%s|%d|%d|%d|\n", s[a].titulo, s[a].inter, s[a].anio, s[a].min,s[a].seg);
		     a++;
	        } // fin de while
	       // cerrando el archivo
	       fclose( varch );
	    }// fin de la funcion
	    
	
	
void leerArchivo(){
 //SE INICIALIZAN LAS VARIABLES LOCALES
 	short op=0;
 	
 	int c=1;


	//SE ABRE ARCHIVO
	varch = fopen("C:\\Users\\vikig\\OneDrive\\Documentos\\C\\distFin.txt","r");
		if (varch == NULL) 
	  {
	  	//ENVIA UN MENSAJE DE ERROR
		printf( "No se pudo abrir para escritura el archivo \n" );//si no se ecuentra el archivo muestra este mensaje
		
      } 
      char leer;
      //SE INICIA CICLO WHILE PARA MOSTRAR DATOS DEL ARCHIVO
      while(feof(varch)==0)
      {
      
      	
      	leer= fgetc(varch);
      	printf("%c", leer);
        
	  }
	  //CIERRA FICHERO
	  fclose(varch);
	  printf("Archivo leido correctamente\n");

	       // cerrando el archivo
	       rewind(varch);
	       fclose( varch );
}

/*void vaciar(char leer[]){
	int r;
	for(r=0; r<999; r++)
	{
		leer[r]='\0';
	}
}

void copiar(char leer[], int o){
	int m= strlen(leer)+1;
	e[o].ti=(char*)malloc(m*sizeof(char));
	  if(e[o].ti==NULL)
	  {
	  	printf("No se ha podido reservar la memoria\n");
	  }
	  
	  strcpy(e[o].ti,leer);
	  strcpy(e[o].in,leer);
}


void leerArchivoDos(){
 //SE INICIALIZAN LAS VARIABLES LOCALES
 	int o,j;
 	int c=1;


	//SE ABRE ARCHIVO
	varch = fopen("C:\\Users\\vikig\\OneDrive\\Documentos\\C\\distFin.txt","r");
		if (varch == NULL) 
	  {
	  	//ENVIA UN MENSAJE DE ERROR
		printf( "No se pudo abrir para escritura el archivo \n" );//si no se ecuentra el archivo muestra este mensaje
	
      } 

      char leer[999];
      char aux;
      //SE INICIA CICLO WHILE PARA MOSTRAR DATOS DEL ARCHIVO
      
      while(!feof(varch))
      {
         fgets(leer,999,varch);
         c++;
        
	  }
	  
	  rewind(varch);
	  
	  e = (est*)malloc(c*sizeof(est));
	  if(e==NULL)
	  {
	  	printf("No se ha podido reservar la memoria\n");
	  }
	  
	  for(o=0; !feof(varch);o++)
	  {
	  	vaciar(leer);
	  	aux='0';
	  	   for(j=0; aux != '|'; j++)
	     {
	  	   aux = fgetc(varch);
	  	     if(aux!='|')
	  	     {
	  		    leer[j]=aux;
	  		    
		     } 
	     }
	     copiar(leer,o);
	     fgets(leer,999,varch);
	     e[o].an=atoi(leer);
	     e[o].mi=atoi(leer);
	     e[o].se=atoi(leer);
         printf("\t%c\t|\t",e[o].ti); 
		 printf("%c\t|",e[o].in);
         printf("\t%d\t  |\n",e[o].an);
         printf("%d\t|",e[o].mi);
         printf("\t%d\t  |\n",e[o].se);
	  }
	  
	  //CIERRA FICHERO
	  fclose(varch);
	  printf("Archivo leido correctamente\n");

}

*/

//funcion usada para juntar las funciones de menu, guardado y llenado de los datos 
void datos()
 {
   
  do{ //inicio ciclo do while     
    
      menu();//llamado del metodo menu

      switch(res)//inicio switch
       {	
    
           case 1:
    	        do{
    		        llenado();
	            }while(res2!=2);//fin do while 2, para submenu
           break;

           case 2://mostrar elementos guardados
	         
			     guardado();
			 
	       break;//fin case 2
	  
	       case 3://guardar datos en un archivo txt
		     
			    Archivo();
			  
	       break;//fin case 3
	       
	       case 4://leer archivo txt
	       	    
	       	    leerArchivo();
	       	    
	       	break;//fin case 4
	       	
	       	case 5://opcion borrar pantalla
	       		
	       		system("cls");
	       		
	       	break;//fin case 5
	
	       case 6://SALIDA
	
	             printf("\n----BYEEEE----\n");
		
	       break;//fin case 6
	
	       default: printf("INCORRECTO\n\n"); break; //DEFAULT
       }//fin switch
   }while(res!=6); //fin del ciclo do while que hara que el menu se repita
}//fin funcion datos
 
 

//funcion principal
int main ()
{
  datos(); //llamada de funcion datos que almacena las demas funciones
  system("pause");
}
