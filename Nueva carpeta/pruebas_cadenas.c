#include <stdio.h>
#include <string.h>

#define ELEMENTOS 5


main()
{
	char cadena[]="El puerto paralelo del PC";
	char *p;
	int espacios = 0, letras_e = 0;

	p = cadena;
	while (*p != '\0') {
		if (*p == ' ') espacios++;
		if (*p == 'e') letras_e++;
		p++;
	}

	printf( "En la cadena \"%s\" hay:\n", cadena );
	printf( "  %i espacios\n", espacios );
	printf( "  %i letras e\n", letras_e );
	printf( "\n\n\n\n");
	
	
	char *dichos[ELEMENTOS] = {
		"La avaricia rompe el saco",
		"Mas vale pájaro en mano que ciento volando",
		"No por mucho madrugar amanece más temprano",
		"Anio de nieves, año de bienes",
		"A caballo regalado no le mires el diente"
		};
	char *temp;
	int i, j;

	printf( "Lista desordenada:\n" );
	for( i=0; i<ELEMENTOS; i++ )
		printf( "  %s.\n", dichos[i] );

	for( i=0; i<ELEMENTOS-1; i++ )
		for( j=i+1; j<ELEMENTOS; j++ )
			if ( strcmp(dichos[i], dichos[j]) > 0 ) {
				temp = dichos[i];
				dichos[i] = dichos[j];
				dichos[j] = temp;
			}

	printf( "Lista ordenada:\n" );
	for( i=0; i<ELEMENTOS; i++ )
		printf( "  %s.\n", dichos[i] );
}
