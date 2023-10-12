// Programa 4 - corresponde al diagrama de flujo billetes 5
// 29 de Septiembre del 2020
// Luis Antonio Alvarez Oval
// Aplicacion de subprocesos - funciones en C
// Uso de arreglos unidimensionales
#include<stdio.h>

// Declaraci?n de arreglos unidimensionales de tipo entero
// Variables globales
int distf1[10]={0,0,0,0,0,0,0,0,0};
int distf2[10]={0,0,0,0,0,0,0,0,0};
int distf3[10]={0,0,0,0,0,0,0,0,0};

void mostrarArreglo(){
} // Fin Funcion MostrarArreglo


// Funci?n que ejecuta la distribuci?n financiera
// la almacena en un arreglo de una dimension
void distribuir(float pcant){
	// declaraci?n de variables locales
  	int bi200, bi100, bi50, bi20, bi500;
  	int m10, m5, m2, m1, m050;
  	float cant;
  	
  	cant = pcant;
  	
  	// Inicializando variables
  	bi500 = 0;
  	bi200 = 0;
  	bi100 = 0;
  	bi50  = 0;
  	bi20  = 0;
  	m10   = 0;
  	m5    = 0;
  	m2    = 0;
  	m1    = 0;
  	m050  = 0;
  	
  	// printf(renglon); -- error porque son variables locales
  	// Si la cantidad es mayor de 120,000 usar billetes de 500
  	if(cant>120000){
  	 	// Si la condici?n es verdad entra x aqui
      	bi500 = (int)(cant / 500);
      	cant  = cant - (bi500*500);
      	printf("te dare, %i billetes de 500 \n", bi500);
      	distf1[0] = bi500;
  	} // Fin del IF
  	
  	// Calculando el numero de billetes de 200
  	bi200 = (int)(cant / 200);
  	cant  = cant - (bi200*200);
  	printf("te dare, %i billetes de 200 \n", bi200);
  	distf1[1] = bi200;
  	
	// Calculando el numero de billetes de 100
 	bi100 = (int)(cant / 100);
 	cant  = cant - (bi100*100);
 	printf("te dare, %i billetes de 100 \n", bi100);
    distf1[2] = bi100;
    
	// Calculando el numero de billetes de 50
  	bi50 = (int)(cant / 50);
  	cant  = cant - (bi50*50);
  	printf("te dare, %i billetes de 50 \n", bi50);
  	distf1[3] = bi50;
  
  	// Calculando el numero de billetes de 20
  	bi20 = (int)(cant / 20);
  	cant  = cant - (bi20*20);
  	printf("te dare, %i billetes de 20 \n", bi20);
    distf1[4] = bi20;
  
  	// Calculando el numero de monedas 10
  	m10 = (int)(cant / 10);
  	cant  = cant - (m10*10);
  	printf("te dare, %i monedas de 10 \n", m10);
  	distf1[5] = m10;
  
  	// Calculando el numero de monedas 5
  	m5 = (int)(cant / 5);
  	cant  = cant - (m5*5);
  	printf("te dare, %i monedas de 5 \n", m5);
  	distf1[6] = m5;
  
  	// Calculando el numero de monedas 2
  	m2 = (int)(cant / 2);
  	cant  = cant - (m2*2);
  	printf("te dare, %i monedas de 2 \n", m2);
  	distf1[7] = m2;
  
  	// Calculando el numero de monedas 1
  	m1 = (int)(cant / 1);
  	cant  = cant - (m1*1);
  	printf("te dare, %i monedas de 1 \n", m1);
  	distf1[8] = m1;
  
  	// Calculando el numero de monedas 10
  	m050 = (int)(cant / 0.5);
  	cant  = cant - (m050*0.5);
  	printf("te dare, %i monedas de 0.50 \n", m050);
  	distf1[9] = m050;
} // Fin funcion distribuir


// Aqu? inicia el programa principal
void main(){
  	short renglon;
  	float cant;
  	renglon = 1;
  	// Ciclo para capturar los 4 renglones de importes
  	while (renglon < 5){
  		// Si la condicion es verdad ejecuta estos comandos
  		// Inicializaci?n de variables
  		cant  = 0;
  		printf("valor de renglon: %d \n", renglon);
  		// Capturando el importe a distribuir
  		printf("Dame la cantidad que le debes pagar al proveedor: \n");
  		scanf("%f",&cant);
  		distribuir(cant);
  		renglon ++;
  	} // Fin While Renglon
  	printf("Saliendo del ciclo \n");
} // Fin del programa principal
