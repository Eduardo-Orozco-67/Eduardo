#include <stdio.h>
#include <stdlib.h>

enum day{Dom, Lun, Mar, Mie, Jue, Vie, Sab};
typedef enum day day;
void print_day(enum day d)
{
	switch(d){
	      case Dom: printf("Domingo"); break;
	      case Lun: printf("Lunes"); break;
	      case Mar: printf("Martes"); break;
	      case Mie: printf("Miercoles"); break;
	      case Jue: printf("Jueves"); break;
	      case Vie: printf("Viernes"); break;
	      case Sab: printf("Sabado"); break;
	      default: printf("%d esto es un error", d);
		  	
	}
}

enum day next_day(enum day d)
{
	return (d+1%7);
}

int main() 
{
	enum day today=Vie;
	print_day(today);
	printf("\n\n");
	print_day(7);
	printf("\n\n");
	print_day( next_day(today));
	printf("\n\n");
	
	return 0;
	getch();
}
