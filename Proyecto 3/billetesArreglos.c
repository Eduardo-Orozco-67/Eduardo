// Programa 5 - corresponde al diagrama de flujo billetes 5
// 1 de Octubre del 2020
// Luis Antonio Alvarez Oval
// Aplicacion de subprocesos - funciones en C
// Uso de arreglos unidimensionales

#include <stdio.h>

// Declaraci?n de arreglos unidimensionales de tipo entero
// Variables globales
int distf1[10] = {0,0,0,0,0,0,0,0,0,0};
int distf2[10] = {0,0,0,0,0,0,0,0,0,0};
int distf3[10] = {0,0,0,0,0,0,0,0,0,0};
int distf4[10] = {0,0,0,0,0,0,0,0,0,0};

// Desplegar en pantalla el contenido de los 3 arreglos
// cada arreglo tiene un solo renglon
void mostrarArreglo(){
	printf("b500  b200  b100  b50  b20  m10  m5  m2  m1  m.50 \n");
	printf("%i    %i    %i    %i   %i   %i   %i   %i  %i  %i\n", 
	       distf1[0], distf1[1], distf1[2], distf1[3],distf1[4],distf1[5],
		   distf1[6], distf1[7], distf1[8], distf1[9] );
	printf("%i    %i    %i   %i   %i   %i  %i  %i  %i \n", 
	       distf2[0], distf2[1], distf2[2], distf2[3],distf2[4],distf2[5],
		   distf2[6], distf2[7], distf2[8], distf2[9] );
	printf("%i    %i    %i   %i   %i   %i  %i  %i  %i \n", 
	       distf3[0], distf3[1], distf3[2], distf3[3],distf3[4],distf3[5],
		   distf3[6], distf3[7], distf3[8], distf3[9] );
	printf("%i    %i    %i   %i   %i   %i  %i  %i  %i \n", 
	       distf4[0], distf4[1], distf4[2], distf4[3],distf4[4],distf4[5],
		   distf4[6], distf4[7], distf4[8], distf4[9] );
} // Fin Funcion MostrarArreglo


// Funcion que llena el arreglo
// pPos - indica la posicion en el arreglo donde se almancena cantidad de billetes
// pCant - Indica la cantidad de billetes de cada denominacion a almacenar
void llenarArreglo(int pPos, int pCant, int pRen){
	printf("Funcion llenarArr. pPos: %i, pCant: %i, pRen: %i \n", pPos, pCant, pRen);
	// llenando el arreglo 1
	if (pRen == 1){
      	distf1[pPos] = pCant;
	}
	// llenando el arreglo 2
	if (pRen == 2){
      	distf2[pPos] = pCant;
	}
	// llenando el arreglo 3
	if (pRen == 3){
      	distf3[pPos] = pCant;
	}
	// llenando el arreglo 4
	if (pRen == 4){
      	distf4[pPos] = pCant;
	}
}

// Funci?n que ejecuta la distribuci?n financiera
// la almacena en un arreglo de una dimension
void distribuir(float pcant, int pReng){
    printf("Funcion Distribuir. pCant: %f, pReng: %i \n", pcant, pReng);
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
        llenarArreglo(0, bi500, pReng );
  	} // Fin del IF
  	
  	// Calculando el numero de billetes de 200
  	bi200 = (int)(cant / 200);
  	cant  = cant - (bi200*200);
  	printf("te dare, %i billetes de 200 \n", bi200);
  	llenarArreglo(1, bi200, pReng );
  	
	// Calculando el numero de billetes de 100
 	bi100 = (int)(cant / 100);
 	cant  = cant - (bi100*100);
 	printf("te dare, %i billetes de 100 \n", bi100);
    llenarArreglo(2, bi100, pReng );
    
	// Calculando el numero de billetes de 50
  	bi50 = (int)(cant / 50);
  	cant  = cant - (bi50*50);
  	printf("te dare, %i billetes de 50 \n", bi50);
  	llenarArreglo(3, bi50, pReng );
  
  	// Calculando el numero de billetes de 20
  	bi20 = (int)(cant / 20);
  	cant  = cant - (bi20*20);
  	printf("te dare, %i billetes de 20 \n", bi20);
    llenarArreglo(4, bi20, pReng );
  
  	// Calculando el numero de monedas 10
  	m10 = (int)(cant / 10);
  	cant  = cant - (m10*10);
  	printf("te dare, %i monedas de 10 \n", m10);
  	llenarArreglo(5, m10, pReng );
  
  	// Calculando el numero de monedas 5
  	m5 = (int)(cant / 5);
  	cant  = cant - (m5*5);
  	printf("te dare, %i monedas de 5 \n", m5);
  	llenarArreglo(6, m5, pReng );
  
  	// Calculando el numero de monedas 2
  	m2 = (int)(cant / 2);
  	cant  = cant - (m2*2);
  	printf("te dare, %i monedas de 2 \n", m2);
  	llenarArreglo(7, m2, pReng );
  
  	// Calculando el numero de monedas 1
  	m1 = (int)(cant / 1);
  	cant  = cant - (m1*1);
  	printf("te dare, %i monedas de 1 \n", m1);
  	llenarArreglo(8, m1, pReng );
  
  	// Calculando el numero de monedas 10
  	m050 = (int)(cant / 0.5);
  	cant  = cant - (m050*0.5);
  	printf("te dare, %i monedas de 0.50 \n", m050);
  	llenarArreglo(9, m050, pReng );
} // Fin funcion distribuir


// Aqu? inicia el programa principal
int main(){
  	short renglon;
  	float cant = 0;
  	renglon = 1;
  	// Ciclo para capturar los 4 renglones de importes
  	while (renglon < 4){
  		// Si la condicion es verdad ejecuta estos comandos
  		// Inicializaci?n de variables
  		cant  = 0;
  		printf("valor de renglon: %i \n", renglon);
  		// Capturando el importe a distribuir
  		printf("Dame la cantidad que le debes pagar al proveedor: \n");
  		scanf("%f",&cant);
  		distribuir(cant, renglon);
  		renglon = renglon + 1;
  	} // Fin While Renglon
  	printf("Saliendo del ciclo \n");
  	// desplegar el contenido del arreglo
  	mostrarArreglo();
} // Fin del programa principal
