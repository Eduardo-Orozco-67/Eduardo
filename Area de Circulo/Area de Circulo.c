
//definimos librerias
#include <stdio.h>
#include <stdlib.h> 

#define PI 3.1459 //definimos una constante de tipo GLOBAL
double PI2=PI;  //definimos una Variable de tipo GLOBAL, la cual obtendra el valo de la constante PI

//creamos un metodo para calcular el area
void area ()
{
	double area=0.0, radio=0.0;//declaramos variables en metodo de tipo LOCAL (notese que son de tipo double y que estan iniciadas en 0)
	
	//iniciamos la secuancia de acciones
	printf("Introduce el radio\n"); 
	
	scanf("%lf", &radio); //EN ESTE PASO ES DONDE LE ASIGNAMOS UN VALOR 
	
	//Mandamos a llamar a nuestra CONSTANTE GLOBAL (PI) para ejecutar una operacion
	area=PI*(radio*radio); 
	//EN ESTE CASO LE AGREGAMOS UN VALOR A UNA VARIBLE LUEGO DE HACER UNA OPERACION ARITMETICA 
	
	printf("El radio de tu circulo es %lf; y el area TOTAL de tu circulo es %lf\n", radio, area); 
	//Mandamos a llamar a nuestra Variables Locales, con datos ya agregados y modificados, para mostrar un resultado
	
	return;
}

int main(void) 
{
	
	area();//llamamos a nuestro metodo area
	
	//Mandamos a llamar a nuestra VARIABLE GLOBAL para imprimir un resultado
	printf("Si ve una diferencia en su resultado es debido a que manejamos a PI como: %lf\n"\a" PI2 ,);

	return 0;
	
	getch();
}
