#include <stdio.h>
#include <stdlib.h>

int main() 
{
	char nombre[50];
	int AN, AA, TE;
	AA=2020;
	printf("Por favor digita tu nombre \n");
	scanf("%50[^\n]", nombre);
	fflush(stdin);
	printf("\n\nHola: %s \n\n", &nombre);
	system("pause");
}

