/*  
	Name:Lista simplemente enlazada
	Author: Jose Eduardo Orozco Cardenas
	Date: 17/05/21 20:36
	Description: Uso de lista simplemente enlazada
	con elminicacion y edicion 
*/

#include <stdio.h>
#include <stdlib.h>

//declaramos nuestra estructura
struct nodo
{
    int dato;
    struct nodo *siguiente;
};

typedef struct nodo *NODO;//lo declaramos como puntero con el nombre NODO

//declaramos nuestros punteros de la lista NODO
//ESTOS 3 PRIMEROS SON USADOS PARA MARACSR EL FINAL, INICIO Y DONDE NOS ENCONTRAMOS EN LA LISTA
NODO NPInicial=NULL;
NODO NPFinal=NULL;
NODO NPActual=NULL; 

//ESTOS 2 SON USADOS PARA BUSCAR 1 ELEMENTO DE LA LISTA Y ELIMINARLO
//y para recorrer la estructura
NODO actual=NULL;
NODO anterior=NULL;
NODO aux = NULL;

//metodo para crear un nuevo nodo y agregarlo a la lista
	void NuevoNodo()
	{
		//le decimos que poscision actual es NULA
		NPActual=NULL;
		//Lo decimpos que asigne un bloque de memoria con un tamaño de la estructura NODO
		NPActual=(NODO)malloc(sizeof(NODO));
		//pedimos N dato
		printf("Inserte un numero: ");
		scanf("%i",&NPActual->dato);
		fflush(stdin);
	    NPActual->siguiente=NULL;
	    //si el inicial es nulo entonces el dato introducido sera el inicio y el fin 
		if(NPInicial==NULL)	
		{
			NPInicial=NPActual;
			NPFinal=NPActual;
		}
		else
		{
			//si no metemos el nuevo dato en el siguiente de final
			NPFinal->siguiente=NPActual;	
			//ahora el final sera el nuevo dato que le sigue a final
			NPFinal=NPFinal->siguiente;	
		}
	}

	void imprimir()
	{
		//verificamos si la lista no esta vacia
		if(NPInicial!=NULL)
		{
			NPActual=NPInicial;
			do
			{
				//comenzamos el recorrido e impresion
				printf("%i -> ",NPActual->dato );
				NPActual=NPActual->siguiente;
			}while(NPActual);
			printf("NULL");
		}
		else
		{
			printf("\n La lista se encuentra vacia\n");
		}
	}

    //eliminacion de nodo en pila, elimina el ultimo
	void ENodoPi()
	{
		//verificamos la lista no este vacia
		if(NPInicial!=NULL)
		{
			NPActual=NPInicial;
			if(NPActual==NPFinal)
			{//si solo hay un elemento, lo vaciamos 
				free(NPFinal);
				NPInicial=NULL;
				NPActual=NULL;
			}
			else
			{
				while(NPActual)
				{
					//recorremos la lista hasta llegar al dato final
					if(NPActual->siguiente==NPFinal)
					{
						//si el nodo que le sigue al actual es el final
						//le decimos que el siguiente de actual se convierta en null
						NPActual->siguiente=NULL;
						//esto separa el ultimo nodo y lo eliminamos
						free(NPFinal);
						//el final ahora sera el actual
						NPFinal=NPActual;
					}
					NPActual=NPActual->siguiente;
				}
			}
			printf("\n Nodo eliminado con exito \n");
		}
		else
		{
			printf("\n La lista se encuentra vacia \n");
		}
	}

	void ENodoCo()
	{
		//verificamos si la lista no esta vacia
		if(NPInicial!=NULL)
		{
			//pocisionamos el nodo actual en el inicial
			NPActual=NPInicial;
			//si el actual es el final, solo hay un dato
			if(NPActual==NPFinal)
			{
				//lo eliminamos
				free(NPFinal);
				//inicial y actual ahora so nulos
				NPInicial=NULL;
				NPActual=NULL;
			}
			else
			{
				//si no, pasamos el actual al siguiente dato que le sigue a inicial
				NPActual=NPActual->siguiente;
				//separa el nodo inicial y lo eliminamos
				free(NPInicial);
				//inicial ahora es actual 
				NPInicial=NPActual;
			}
			printf("\n Nodo eliminado con exito \n");
		}
		else
		{
			printf("\n La lista se encuentra vacia \n");
		}
	}


	void buscarNodo()
	{
		//declaramos y reservamos memoria estos 2 nodos que nos ayudaran 
		actual = (NODO) malloc(sizeof(NODO));
		anterior = (NODO) malloc(sizeof(NODO));
		//actual ahora sera inicial
		actual = NPInicial;
		//declaramos una variable que servira como comparador y una bandera
		int nodoBuscado = 0, encontrado = 0;
		//pedimos dato
		printf(" Ingrese el dato del nodo a Buscar: ");
		scanf("%i", &nodoBuscado);
        //verificamos que la lista no este vacia
		if(NPInicial!=NULL)
		{
			while(actual != NULL && encontrado != 1)
			{

                //si el dato que esta en actual es igual a nodoBuscado(comparador) procemos a validar
				if(actual->dato == nodoBuscado)
				{   
                    //si actual es igual al nodo inicial
					if(actual == NPInicial)
					{
						//ahora el inicial sera el que le sigue
						NPInicial = NPInicial->siguiente;
					}
					//si no, si actual es el final 
					else if(actual == NPFinal)
					{
						//la poscision que le sigue a anterior ahora es nula, marcando el nuevo fin de la lista
						anterior->siguiente = NULL;
						//el nodo final ahora sera anterior
						NPFinal = anterior;
					}
					else
					{
						//si no, aqui hacemos que lo que le sigue a anterior apunte a lo que le sigue a actual
						//aparta el dato que este en medio de ellos
						//abajo en la linea 202 le declaramos que anterior valga este dato
						//y que actual apunte a Null
						anterior->siguiente = actual->siguiente;
					}
				
					printf("\n Nodo eliminado con exito");
					//si encuentra el nodo esta variable cambia a 1 y activa la bandera
					encontrado = 1;
				}
				//aqui le decimos que el nodo anterior tome el valor de actual
				anterior = actual;
				//y que actual se recorra al siguiente
				actual = actual->siguiente;
			}
			
			//si esta variable sigue siendo 0, nunca se encontro el dato
			if(encontrado == 0)
			{
				printf("\n Nodo no encontrado\n\n");
			}
			else
			{
				//si no, elimina lo que esta almacenado en anterior
				free(anterior);
			}
		}
		
		else
		{
		printf("\n La lista se encuentra vacia\n\n");
		}
	}


	void modificarNodo()
	{
		//declaramos y reservamos memoria este nodo que nos ayudara
		aux = (NODO) malloc(sizeof(NODO));
		//aux sera igual al nodo inicial
		aux = NPInicial;
		//declaramos una variable que servira como comparador y una bandera
		int nodoBuscado1 = 0, encontrado1 = 0;
		printf(" Ingrese el dato del nodo a Buscar para Modificar: ");
		scanf("%i", &nodoBuscado1);
		//verificamos que la lista no este vacia
		if(NPInicial!=NULL)
		{
			while(aux != NULL && encontrado1 != 1)
			{
			    //si el dato que esta en aux es igual a nodoBuscado1(comparador) ...
				if(aux->dato == nodoBuscado1)
				{
					printf("\n El nodo con el dato ( %d ) fue Encontrado", nodoBuscado1);
					printf("\n Ingrese el nuevo dato para este Nodo: ");
					//actualizamos el dato que esta en aux
					scanf("%i", &aux->dato);
					printf("\n Nodo modificado con exito\n\n");
					//activamos la bandera
					encontrado1 = 1;
				}
				//mientras no se encuentre seguimos recorriendo, aunque al final tambien lo hace
				aux = aux->siguiente;
			}
		
		    //si encontrado1 aun es 0, nunca se encontro el nodo
			if(encontrado1 == 0)
			{
				printf("\n Nodo no encontrado\n\n");
			}
		}
		
		else
		{
		printf("\n La lista se encuentra vacia\n\n");
		}
	}


int main()
{
	
  int res;
  
  printf("\n");	
  printf("\t\t-----BIENVENIDO-----\n");
  printf("\tGracias por elegiir usar software de:\n");
  printf("\t\tOROZCO-S PROGRAMMING");
  printf("\n");
  printf("\n");
  
   do
   { 	
       //menu principal
       printf("\n\t\tMENU\t\t\n");
       printf("-Que desea hacer?\n");
       printf("1.- INSERTAR NODO\n");
       printf("2.- MODIFICAR NODO\n");
       printf("3.- ELIMINAR NODO EN PILAS\n");
       printf("4.- ELIMINAR NODO EN COLA\n");
       printf("5.- BUSCAR NODO PARA ELIMINAR\n");
       printf("6.- MOSTRAR LISTA\n");
       printf("7.- SALIR\n\n");
       printf("Teclee su opcion:  ");
       scanf("%d", &res);
       printf("\n");
	   printf("\n");
    
        switch (res)
        {
        	case 1:
        		NuevoNodo();
        		printf("\n\n");
            break;
            
            case 2:
            	modificarNodo();
            	printf("\n");
            break;
            
            case 3:
                ENodoPi();
                printf("\n\n");
            break;
            
            case 4:
            	ENodoCo();
                printf("\n\n");
            break;
            
            case 5:
            	buscarNodo();
            	printf("\n\n");
            break;
            
            case 6:
            	imprimir();
            	printf("\n\n");
            break;
            
            case 7:
        		printf("\n");
        		printf("Adios, tenga buen dia, gracias por usar software de:\n");
                printf("\t\tOROZCO-S PROGRAMMING");
                printf("\n");
                printf("\n");
        	break;
        		
        	default:  printf("TECLEE UNA OPCION VALIDA\n\n");
        }
   }while(res!=7);
   NODO(free);
   system("pause");
}
