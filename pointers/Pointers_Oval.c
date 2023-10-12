// Programa 10
// 4 de Noviembre del 2020
// Luis Antonio Alvarez Oval
// Copia los datos de un arreglo de estructuras -> Lista Simplemente Ligada
// http://caminos.udc.es/info/asignaturas/grado_tecic/705/ApuntesYMaterialPedagogico/Apuntes/3_LenguajeC-Fortran.pdf


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

// Variables globales

// Variable para el control del renglon que se captura
// de acuerdo al problema en la tabla que se presenta
short g_renglon = 1;
char nombree[50];
char apellido[50];
// Declaraci?n de arreglo bidimensional de tipo entero 
// para la Distribucion Financiera
//    renglon,columna
int distf[4][11];
//                      // concatenar
char nombre_completo[100]; // nombre + " " + apellido
// capturar nombre por separado
//          apellido por separado

// Arreglo que almacena el importe a distribuir
float a_importe[4];

// Controla el numero de veces que se invoca la funcion recursiva
int vcontrol = 0;

// Estructura y un arreglo bidimensional que almacene las 
// cantidades de billetes por cada denominacion
// Puedo mezclar diferentes tipos de datos
// en los arreglos uni y bidimensionales todo el arreglo
// es de un solo tipo
struct{
	float importe;
	int cb500;
	int cb200;
	int cb100;
	int cb50;
	int cb20;
	int cm10;
	int cm5;
	int cm2;
	int cm1;
	int cm050;
	char nombre[101];
} a_registro[4];
   
   
// Registro para la Lista Simplemente Ligada
struct nodo{
	float importe;
	int cb500;
	int cb200;
	int cb100;
	int cb50;
	int cb20;
	int cm10;
	int cm5;
	int cm2;
	int cm1;
	int cm050;
	struct nodo *sigreg;
};

// Aqui almaceno la direccion de memoria donde
// se encuentra el primer renglon de la Lista 
// Simplemente Ligada (LSL)
struct nodo *inicio = NULL;

// Aqui empiezan las funciones ||

// Recorre la Lista Simplemente Ligada y
// despliega en pantalla los datos almacenados
void mostrarLSL(){
    struct nodo *actual   = NULL;
    // Recuperando la posici?n del primer registro de la LSL
    actual = inicio; 
    if( actual != NULL){
    	printf("Importe b500  b200  b100  b50  b20  m10  m5  m2  m1  m.50 \n");
    	// Recorrer los nodos de la LSL
    	while(actual->sigreg != NULL){
    		printf("%f  ", actual->importe);
		    printf("%i  ", actual->cb500);
		    printf("%i  ", actual->cb200);
		    printf("%i  ", actual->cb100);
		    printf("%i  ", actual->cb50);
		    printf("%i  ", actual->cb20);
		    printf("%i  ", actual->cm10);
		    printf("%i  ", actual->cm5);
		    printf("%i  ", actual->cm2);
		    printf("%i  ", actual->cm1);
		    printf("%i\n", actual->cm050);
		    actual = actual->sigreg;
		} // Fin del While
	}
	else {
		printf("No existe la Lista Simplemente Ligada \n");
	} // Fin de IF
} // Fin de la funcion


// Copia el arreglo de registros a la LSL
// La LSL es construida con apuntadores
// Un apuntador ocupa memoria y esta no es 
// liberada durante la ejecucion del programa
// el comando que libera la memoria es FREE(apuntador)
void copiarAR_LSL(){
	struct nodo *anterior = NULL;
	struct nodo *actual   = NULL;
	// Recorrer el Arreglo de Registros
	short vr = 0;
	// Evaluar si ya est? construida la lista
	// Si inicio es NULL... la LSL no ha sido construida
	if (inicio == NULL){
	   while(vr<4){
   	      // Crear un nodo para la LSL
   	      actual = (struct nodo*) malloc( sizeof(struct nodo) );
   	      /* si fuera Java
   	         Nodo actual = new Nodo();
   	      */
   	      // Almaceno la direccion del primer registro
   	      if (inicio == NULL){
   	      	 inicio   = actual;
		  } // fin del IF
	      // Enlazar el nodo anterior con el nodo actual
	      if(anterior != NULL){
	      	// la segunda vez... enlazo el nodo anterior con el nodo actual
	      	anterior->sigreg = actual;
		  } // Fin del if
		  anterior = actual;
	      // Copiar Datos del Arreglo a la LSL
	      actual->importe = a_registro[vr].importe;
	      actual->cb500   = a_registro[vr].cb500;
		  actual->cb200   = a_registro[vr].cb200;
		  actual->cb100   = a_registro[vr].cb100;
		  actual->cb50    = a_registro[vr].cb50;
		  actual->cb20    = a_registro[vr].cb20;
		  actual->cm10    = a_registro[vr].cm10;
		  actual->cm5     = a_registro[vr].cm5;
		  actual->cm2     = a_registro[vr].cm2;
		  actual->cm1     = a_registro[vr].cm1;
		  actual->cm050   = a_registro[vr].cm050;
		  actual->sigreg  = NULL;
	      vr = vr + 1;
       } // Fin del ciclo
	}
    else {
	   printf("La LSL solo puede ser construida UNA VEZ \n");
    } // Fin del IF
} // Fin de la funcion


// Funcion que copia los datos del arreglo bidimensional
// al arreglo de registros   
void copiarABD_AR(){
	short vr = 0;
	while(vr<4){
		a_registro[vr].importe = a_importe[vr];
  	    // arreglo registros <- arreglo bidimensional
		a_registro[vr].cb500  = distf[vr][0];
		a_registro[vr].cb200  = distf[vr][1];
		a_registro[vr].cb100  = distf[vr][2];
		a_registro[vr].cb50   = distf[vr][3];
		a_registro[vr].cb20   = distf[vr][4];
		a_registro[vr].cm10   = distf[vr][5];
		a_registro[vr].cm5    = distf[vr][6];
		a_registro[vr].cm2    = distf[vr][7];
		a_registro[vr].cm1    = distf[vr][8];
		a_registro[vr].cm050  = distf[vr][9];

		vr = vr + 1;
	} // Fin del ciclo
} // Fin de la funcion copiarABD_AR
   

// Mostrar en pantalla el contenido del arreglo de registros
// ejemplos para formatear salida: http://agora.pucp.edu.pe/inf2170681/3.htm
void mostrarAR(){
	int vr = 0;
	printf("Importe b500  b200  b100  b50  b20  m10  m5  m2  m1  m.50   nombre \n");
	while(vr<4){
		printf("%f  ", a_registro[vr].importe);
		printf("%i  ", a_registro[vr].cb500);
		printf("%i  ", a_registro[vr].cb200);
		printf("%i  ", a_registro[vr].cb100);
		printf("%i  ", a_registro[vr].cb50);
		printf("%i  ", a_registro[vr].cb20);
		printf("%i  ", a_registro[vr].cm10);
		printf("%i  ", a_registro[vr].cm5);
		printf("%i  ", a_registro[vr].cm2);
		printf("%i  ", a_registro[vr].cm1);
		printf("%i\n", a_registro[vr].cm050);
		//mostramos nombre
		printf("%i\n", a_registro[vr].nombre);
      
		
		vr = vr + 1;
	} // Fin del ciclo 
} // Final de la funcion

   
// Version RECURSIVA de la funcion que obtiene el total a pagar
float sumar(int pcontrol){
	float vtotal = 0;
	if (pcontrol < 4){
		return a_importe[pcontrol] + sumar(pcontrol +1);
	}
	else {
		return 0;
	}// Fin de si
}// Fin de la funcion sumar


// Version simple de la funcion que obtiene el total a pagar
float sumarTotalSim(){
	// variables locales
	int vr = 0;
	float vtotal = 0.0;
	for(vr = 0; vr < 4; vr = vr + 1){
		vtotal = vtotal + a_importe[vr];
	} // Fin del for
	// Devolver el importe
	return vtotal;
} // Fin de funcion sumarTotalSim


// Desplegar en pantalla el contenido de los 3 arreglos
// cada arreglo tiene un solo renglon
void mostrarArreglo(){
	// variables locales
	// Control del renglon
	int vr = 0;
	// Control de la columna
	int vc = 0;
	
	// Desplegar en pantalla el contenido del arreglo bidimensional
	printf("Importe b500  b200  b100  b50  b20  m10  m5  m2  m1  m.50 nombre\n");
	// Aqui recorro los renlones
	for(vr = 0; vr < 4; vr = vr + 1){
		// Aqui se imprime el importe
		printf("%f  ", a_importe[vr] );
		// Aqui se recorren de las columnas
		for(vc = 0; vc < 11; vc = vc + 1){
		   printf("%i     ", distf[vr][vc] );
		 
		} // Fin del For para las columnas
		printf("\n");
	} // Fin del For para renglon
} // Fin Funcion MostrarArreglo


// Funcion que llena el arreglo
// pCol - indica la COLUMNA en el arreglo donde se almancena cantidad de billetes
// pCant - Indica la cantidad de billetes de cada denominacion a almacenar
// pRen - Indica el renglon de la hoja de calculo del laboratorio
// pImp - indica el importe a pagar que se distribuye
void llenarArreglo(int pCol, int pCant, int pRen, float pImp){
	int vren;
	// Renglon del arreglo
	vren = pRen - 1;
	// Almacenando el importe a pagar
	if (a_importe[vren] == 0){
		a_importe[vren] = pImp;
	} // Fin de si
	// Llenando el arreglo
	distf[vren][pCol] = pCant;
	
} // Fin funcion llenarArrelo


// Funci?n que ejecuta la distribucion financiera
// la almacena en un arreglo de una dimension
void distribuir(float pcant, int pReng){
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
        llenarArreglo(0, bi500, pReng, pcant );
  	} // Fin del IF
  	
  	// Calculando el numero de billetes de 200
  	bi200 = (int)(cant / 200);
  	cant  = cant - (bi200*200);
  	llenarArreglo(1, bi200, pReng, pcant);
  	
	// Calculando el numero de billetes de 100
 	bi100 = (int)(cant / 100);
 	cant  = cant - (bi100*100);
    llenarArreglo(2, bi100, pReng, pcant);
    
	// Calculando el numero de billetes de 50
  	bi50 = (int)(cant / 50);
  	cant  = cant - (bi50*50);
  	llenarArreglo(3, bi50, pReng, pcant);
  
  	// Calculando el numero de billetes de 20
  	bi20 = (int)(cant / 20);
  	cant  = cant - (bi20*20);
    llenarArreglo(4, bi20, pReng, pcant);
  
  	// Calculando el numero de monedas 10
  	m10 = (int)(cant / 10);
  	cant  = cant - (m10*10);
  	llenarArreglo(5, m10, pReng, pcant);
  
  	// Calculando el numero de monedas 5
  	m5 = (int)(cant / 5);
  	cant  = cant - (m5*5);
  	llenarArreglo(6, m5, pReng, pcant);
  
  	// Calculando el numero de monedas 2
  	m2 = (int)(cant / 2);
  	cant  = cant - (m2*2);
  	llenarArreglo(7, m2, pReng, pcant);
  
  	// Calculando el numero de monedas 1
  	m1 = (int)(cant / 1);
  	cant  = cant - (m1*1);
  	llenarArreglo(8, m1, pReng, pcant);
  
  	// Calculando el numero de monedas 10
  	m050 = (int)(cant / 0.5);
  	cant  = cant - (m050*0.5);
  	llenarArreglo(9, m050, pReng, pcant);
  	
  	
  	
    
   
} // Fin funcion distribuir



// Funcion que ejecuta la captura de un renglon
// de la descripcion del proyecto
void capturaRenglon(){
  	float cant = 0;
  	// Solo se pueden capturar 4 renglones
  	if(g_renglon < 5){
  		// Si la condicion es verdad ejecuta estos comandos
  		// Inicializaci?n de variables
  		cant  = 0;
  		printf("valor de renglon: %i \n", g_renglon);
  		// Capturar el nombre del proveedor
  		printf("Dame nombre del proveedor: \n");
  		scanf("%s",nombree);
  		printf("Dame apellido del proveedor: \n");
  		scanf("%s",apellido);
  		
  		// concatenar Nombre + " " + Apellido
  		strcpy( nombre_completo, nombree );
	    strcat( nombre_completo, " " );
	    strcat( nombre_completo, apellido );
	    strcat( nombre, nombre_completo );
  		// almacenar en arreglo nombre_completo
  		// Capturando el importe a distribuir
  		printf("Dame la cantidad que le debes pagar al proveedor: \n");
  		scanf("%f",&cant);
  		// Se ejecuta la funcion distribuir
  		distribuir(cant, g_renglon);
  		g_renglon = g_renglon + 1;
  	}
  	else {
  		printf("Solo se permite capturar hasta 4 renglones \n");
  	} // Fin del IF de validacion del renglon
} // Fin de funcion capturaRenglon



// Modificar el importe almacenado en el arreglo bidimensional
void cambio1Registro(){
	// Variables locales de la funcion
	int   vren = 0;
	int   vra  = 0;
	// Nuevo importe
	float vnuevo = 0;
	printf("---------------------------------------- \n");
	printf("Iniciando la modificacion de un registro \n");
	printf("---------------------------------------- \n");
	// Pedir el numero de renglon a modificar
	printf("Dame el renglon del lab a modificar, 0->Cancelar, 1-4 No renglon: ");
	scanf("%i", &vren);
	if ( vren > 0 ){
		// Limitando el alcance de la variable VREN
		if (vren >= 0 && vren <= 4){
			// Copiar el valor almacenado en el arreglo a vnuevo
			vra = vren - 1;
			vnuevo = a_importe[vra];
			printf("Importe a modificar: %i \n", vnuevo);
			printf("Nuevo importe: ");
			scanf("%i", &vnuevo);
			a_importe[vra] = vnuevo;
			// ejecutar la distribucion financiero
			// Aqui se afecta al arreglo bidimensional
	        distribuir(vnuevo, vren);
		    // Copiar el arreglo de bidimensional -> arreglo de estructuras
		    copiarABD_AR();
		} // Fin de IF - 1< VREN <5
	} // Fin de IF
	else {
		printf("Se cancela la modificacion de un renglon \n");
	} // Fin de ELSE
}// Fin de Funci?n 


// Aqu? inicia el programa principal
void main(){
	short vopc = 0;
	int vsalir = 0;
	// Ciclo mientras vsalir tenga el valor de cero
	while (vsalir == 0){
		printf("Opciones que el usuario puede seleccionar: \n");
		printf("1. Capturar renglon \n");
		printf("2. Desplegar arrreglo \n");
		printf("3. Limpiar pantalla \n");
		printf("4. Salir \n");
		printf("5. Obtener el total a pagar SIMPLE\n");
		printf("6. Obtener el total a pagar RECURSIVA\n");
		printf("7. Copiar arreglo Bidim al Arreglo Registros \n");
		printf("8. Mostrar el Arreglo Registros \n");
		printf("9. Modificar un renglon \n");
		printf("10. Copiar AR a LSL \n");
		printf("11. Mostrar contenido de la LSL \n");
		vopc = 0;
		printf("Opcion: ");
		scanf("%i", &vopc);
		switch(vopc){
			case 1:
				capturaRenglon();
				break;
			case 2:
				mostrarArreglo();
				break;
			case 3:
				system("cls");
				break;
			case 4:
				vsalir = 1;
				break;
			case 5:
				printf("Total a pagar: %f \n", sumarTotalSim() );
				// uso alternativo de una funcion que devuelve valores
				// float vtot;
				// vtot = sumarTotalSim();
				// printf("Total a pagar: %f \n", vtot );
				break;
			case 6:
				printf("Total a pagar: %f \n", sumar(0) );
				break;
			case 7:
				copiarABD_AR();
				break;
			case 8:
				mostrarAR();
				break;	
			case 9:
				cambio1Registro();
				break;		
			case 10:
				copiarAR_LSL();
				break;
			case 11:
				mostrarLSL();
				break;
		} // fin de switch
		vopc = 0;
		printf("\n");
	} // Fin ciclo 
} // Fin del programa principal
