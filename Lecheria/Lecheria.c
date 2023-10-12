#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//#include "funciones.c"

int main(){
int f=1; 

int cont; 

int a[3] = {0,0,0} ;

for (cont=1; cont <= 3; cont++) { 

a[cont] += f; 

f = a[cont];

}

printf("%d \n", f); return 0;
}
