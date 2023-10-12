/*Menu de cds
by: Jose Eduardo Orozco Cardenas
USAMOS ESTRUCTURAS, ciclo do while, switch, arrays y funciones*/

#include<stdio.h>
#include<stdlib.h>

int i = 1, n ; //variables globales para los datos y ciclos for
short  res, res2; //variables globales para los contadores

int discos[999][6];

//struct usado llamado datos
struct datos
{
 int anio;
 double dur;
 int min;
 int seg;
 int ho;
 char titulo[ 80 ];
 char inter[ 40 ];
}s[ 1000 ]; //nombre dado para su invicacion 

struct{
 int anioo;
 int minu;
 int segu;
 char tituloo[ 80 ];
 char interp[ 40 ];
} a_registro[ 1000 ];



void menu() //funcion para hacer la estructura del menu                      |
{
	    //menu principal
    printf("\n\t\tMENU\t\t\n");
    printf("-Que desea hacer?\n");
    printf("1.- AGREGAR\n");
    printf("2.- VER GUARDADO\n");
    printf("3.- COPIAR TODO A UN ARCHIVO TXT\n");
    printf("4.- LIMPIAR PANTALLA\n");
    printf("5.- SALIR\n\n");
    scanf("%d", &res);
} //fin funcion menu




void capturaDiscos(){
    short j=1;
  	int anio;
    double dur;
    int min;
    int seg;
    int ho;
    char titulo[ 80 ];
    char inter[ 40 ];
     //sub menu
    	  printf("\n-Que desea hacer?\n");
    	  printf("1.- AGREGAR\n");
          printf("2.- REGRESAR\n");
    	  scanf("%d", &res2);
    	  
       switch(res2) //switch del submenu
       {
       	case 1:
         if(j>999) //no aceptamos mas de 999 discos
          {
          	printf("\nERROR, NO ACEPTO MAS DE 999 DISCOS\n");
		  }
          else
		  {
  		    while(j<1000) //while para repetir los mensajes de la toma de datos
             {
          	   //entrada de datos 1 por 1
          	   printf("valor de renglon: %i \n", j);
               printf("\n\n Inserte datos del disco %d\n",j);
               printf("\nInserte titulo del disco (NOTA: NO USE ESPACIO EN SU DEFECTO USE GUION BAJO _): \n");
                 scanf("%s",titulo);
				 lenarArreglo(j, titulo, pReng ); //en este paso guardamos un dato en una variable estructura pasandola como paramatetro//
               printf("Inserte interprete (NOTA: NO USE ESPACIO EN SU DEFECTO USE GUION BAJO _:\n");
                  scanf("%s",inter); 
                  lenarArreglo(j, iner, pReng );
               printf("Inserte anio de publicacion:\n");
                  scanf("%d",&anio);
                  lenarArreglo(j, bi50, pReng );
                printf("Inserte la duracion en minutos\n");
                  scanf("%lf",&dur);
                  lenarArreglo(j, iner, pReng );
                min=(dur); //conversion a minutos y segundos
                ho=(min/60);
                seg=((dur- min)*100);
                j++; 
             } //fin while
		  }
		  break;
       }
  }
  
  void llenarArreglo(int pCol, int nt anio;
    double dur;
    int min;
    int seg;
    int ho;
    char titulo[ 80 ];
    char inter[ 40 ];, int pRen)
	{
	int vren;
	// Renglon del arreglo
	vren = pRen - 1;
	// Llenando el arreglo
	distf[vren][pCol] = pCant;
} // Fin funcion llenarArrelo
 

/*	int Archivo(){
             	int a=1;
             	// Apuntador a la estructura de tipo Per Process File Table
	        FILE *varch = NULL ;
	        //  w - write, r - read
	        varch = fopen("C:\\Users\\vikig\\OneDrive\\Documentos\\C\\distFin.txt", "r+");
	         if( varch == NULL ){
		      printf("No se pudo abrir para escritura el archivo \n");
		      return 0;
	        }
	        while(a<=n && n<1000){
	        	printf("n=%d", n);
	        	printf("I=%d",i);
		    fprintf( varch, "%s|%s|%d|%d|%d|\n", s[i].titulo, s[i].inter, s[i].anio, s[i].min,s[i].seg);
		     a++;
	        } // fin de while
	       // cerrando el archivo
	       fclose( varch );
	    }// fin de la funcion
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
    		        capturaDiscos();
	            }while(res2!=2);//fin do while 2, para submenu
           break;

           case 2://mostrar elementos guardados
	         
			     guardado();
			 
	       break;//fin case 2
	  
	       case 3:
		     
			    Archivo();
			  
	       break;//fin case 3
	       
	       case 4://opcion borrar pantalla
	       	    
	       	    system("cls");
	       	    
	       	break;
	
	       case 5://SALIDA
	
	             printf("\n----BYEEEE----\n");
		
	       break;//fin cas 4
	
	       default: printf("INCORRECTO\n\n"); break; //DEFAULT
       }//fin switch
   }while(res!=5); //fin del ciclo do while que hara que el menu se repita
}//fin funcion datos
 
 

//funcion principal
int main ()
{
  datos(); //llamada de funcion datos que almacena las demas funciones
  system("pause");
}
