/*Menu de cds
by: Jose Eduardo Orozco Cardenas
USAMOS ESTRUCTURAS, ciclo do while y sub procesos*/
#include<stdio.h>
#include<stdlib.h>

//struct usado
struct datos
{
 int anio;
 double dur;
 int min;
 int seg;
 char titulo[80];
 char inter[40];
}s[0];

//sub proceso o metodo usado
void datos()
 {
 		
   int i = 1, n, res ;
  do{ //inicio ciclo do while     
  
    //menu principal
    printf("\n\t\tMENU\t\t\n");
    printf("-Que desea hacer?\n");
    printf("1.- AGREGAR\n");
    printf("2.- VER GUARDADO\n");
    printf("3.- LIMPIAR PANTALLA\n");
    printf("4.- SALIR\n\n");
    scanf("%d", &res);

    switch(res)//inicio switch
    {	
    
    case 1:
    	
 
        printf("\t\tDISCOS\t\t\n");
          printf("-cuantos discos desea guardar?\n");
          scanf("%d", &n); //cantidad a almacenar
          
		while(i<=n && n<1000) //while para repetir mensaje y toma de datos
          {
          	//entrada de datos
            printf("\n\n Inserte datos del disco %d\n",i);
            printf("\nInserte titulo del disco (NOTA: NO USE ESPACIO EN SU DEFECTO USE GUION BAJO _): \n");
               scanf("%s",s[i].titulo); //en este paso guardamos un dato en una variable estructura pasandola como paramatetro//
            printf("Inserte interprete (NOTA: NO USE ESPACIO EN SU DEFECTO USE GUION BAJO _):\n");
               scanf("%s",s[i].inter);
            printf("Inserte anio de publicacion:\n");
               scanf("%d",&s[i].anio);
            printf("Inserte la duracion en minutos\n");
               scanf("%lf",&s[i].dur);
            s[i].min=int(s[i].dur);
            s[i].seg=int((s[i].dur- s[i].min)*100);
           i++;
          }
        
          //impresion de resultados despues de llenar datos usando ciclo for
       printf("\t**********************************************************\n");
       printf("\tTITULO\t   |\tINTERPRETE   | ANIO PUBLICACION |\n");
            
         for(i=1;i<=n;i++) 
         {
             printf("  \t%s \t   |\t",s[i].titulo);
             printf("  %s \t     |",s[i].inter);
             printf("      %d \t|\n",s[i].anio);
         } 
         
       printf("\t**********************************************************\n");
       printf("\tTITULO\t   |\t MINUTOS     |     SEGUNDOS     |\n");
         for(i=1;i<=n;i++) 
         {
             printf("  \t%s \t   |\t",s[i].titulo);
             printf("  %d \t     |",s[i].min);
             printf("        %d\t|\n",s[i].seg);
         }
          printf("\nUd esta en el disco %d, para agregar mas disco sumele la cantidad de discos que desea al disco que esta\n", i-1);
           printf("EJEMPLO: esta en el disco 4, si quiero agregar 6 mas entonces teclee 10\n");
    break;

   case 2:
	    //mostrar elementos guardados
	    printf("\n\t\tGUARDADO\t\t\n\n\n");
       printf("\t**********************************************************\n");
       printf("\tTITULO\t   |\tINTERPRETE   | ANIO PUBLICACION |\n");
            
         for(i=1;i<=n;i++) 
         {
             printf("  \t%s \t   |\t",s[i].titulo);
             printf("  %s \t     |",s[i].inter);
             printf("      %d \t|\n",s[i].anio);
         } 
       printf("\t**********************************************************\n");
       printf("\tTITULO\t   |\tMINUTOS\t     |     SEGUNDOS     |\n");
        for(i=1;i<=n;i++) 
         {
             printf("  \t%s \t   |\t",s[i].titulo);
             printf("  %d \t     |",s[i].min);
             printf("        %d\t|\n",s[i].seg);
         }
          printf("\nUd esta en el disco %d, para agregar mas disco sumele la cantidad de discos que desea al disco que esta\n", i-1);
           printf("EJEMPLO: esta en el disco 4, si quiero agregar 6 mas entonces teclee 10\n");
	    
	break;
	case 3:
		//opcion de salida y fin
		system("cls");
	break;
	case 4:
		printf("\n----BYEEEE----\n");
	break;
	default: printf("INCORRECTO\n\n"); break;
}//fin switch

}while(res!=4); //fin del ciclo do while que hara que el menu se repita
 
 }//fin subproceso

//funcion principal
int main ()
{
  datos(); //llamada de funcion
  system("pause");
}
