
#include<stdio.h>
#include<stdlib.h>


struct datos{
   int anio;
 double duracion;
 char titulo[80];
 char inter[40];
}s[0];

 


int main ()
{
	
   int i=1, n, res ;
  do{      
    printf("\n\t\tMENU\t\t\n");
    printf("Que desea hacer?\n");
    printf("1.- AGREGAR\n");
    printf("2.- VER GUARDADO\n");
    printf("3.- SALIR\n");
    scanf("%d", &res);

    switch(res)
    {	
    
    case 1:
    	
 
        printf("\t\tDISCOS\t\t\n");
          printf("¿cuantos discos desea guardar?\n");
          scanf("%d", &n);
		while(i<=n && n<1000) 
          {
            printf("\n\n Inserte datos del disco %d\n",i);
            printf("\nInserte titulo del disco (NOTA: NO USE ESPACIO EN SU DEFECTO USE GUION BAJO _): \n");
               scanf("%s",s[i].titulo);
            printf("Inserte interprete (NOTA: NO USE ESPACIO EN SU DEFECTO USE GUION BAJO _):\n");
               scanf("%s",s[i].inter);
            printf("Inserte anio de publicacion:\n");
               scanf("%d",&s[i].anio);
           i++;
          }
          
       printf("\t\t**********************************************************\n");
       printf("\tTITULO\t\t INTERPRETE\t ANIO PUBLICACION\n");
            
         for(i=1;i<=n;i++) 
         {
             printf("\t%s\t\t",s[i].titulo);
             printf("%s\t\t",s[i].inter);
             printf("%d\t\t\n",s[i].anio);
         }
    break;

   case 2:
	
	      printf("\t\t**********************************************************\n");
          printf("\tTITULO\t\t INTERPRETE\t ANIO PUBLICACION\n");
	     	for(i=1;i<=n;i++) 
            {
             printf("\t%s\t\t",s[i].titulo);
             printf("%s\t\t",s[i].inter);
             printf("%d\t\t\n",s[i].anio);
	        }
	break;
	case 3:
		printf("BYEEEE\n");
	break;
	default: printf("INCORRECTO\n\n"); break;
}

}while(res!=3);
 return 0; 
}
