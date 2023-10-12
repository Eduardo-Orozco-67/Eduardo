  
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char inter[100];
int n;

void main(){
	printf("Inserte un numero\n");
	scanf("%d", n);
	
	printf("Inserte Una cadenas\n");
       scanf("%[^\n]s",inter); 
    printf("Su cadena es: %s", inter, "\n");
    getch();
}

