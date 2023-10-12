#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>


int main() {

int aux, *numeros;
int i,k,j,n=101, numero; // declare the variables

printf ("Press Enter \n\n");

srand ((unsigned) time (NULL)); //created a time meter for the random numbers
  (void) getchar();
    numeros=(int*) malloc (sizeof (int) * n); // assign a memory space to the variable number
    for (i=1; i<n; i++)
    {
        numero=rand()%10000; //start the creation of the ramdom number
        numeros[i] =numero; // and save it in the variable numbers[i]
    }
    
   
    for (i=1; i<n; i++)  //started ordering the numbers from minor to major with the bubble method
    {
    	for (j=1; j<n; j++) 
    	{
    		if (numeros[j]>numeros[j+1])
    		{
    			aux=numeros[j];
    			numeros[j]=numeros[j+1];
    			numeros[j+1]= aux;
			}
		}
    	
    }
    
    printf ("Numeros ordenados: \n\n");  //print results 5 at a time
    for (i=1; i<n; i++)
    {
    	k=0;
    	while (k <1){
    	printf ("   | %d |   ", numeros[i]);
    	k++;
        }
        if (i%5==0) 
        {
        	printf ("\n");
		}
	}


}

/*#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>


int main() {
struct datos{
	int numeros;
}x[101];


int aux;
int i,k,j,n=101, numero; // declare the variables

printf ("Press Enter \n\n");
//numero=(int*) malloc (sizeof (int) * n); // assign a memory space to the variable number
srand ((unsigned) time (NULL)); //created a time meter for the random numbers
  (void) getchar();
    
    for (i=1; i<n; i++)
    {
        numero=rand()%1000; //start the creation of the ramdom number
        x[i].numeros=numero; // and save it in the variable numbers[i]
    }
    
   
    for (i=1; i<n; i++)  //started ordering the numbers from minor to major with the bubble method
    {
    	for (j=1; j<n; j++) 
    	{
    		if (x[j].numeros>x[j+1].numeros)
    		{
    			aux=x[j].numeros;
    			x[j].numeros=x[j+1].numeros;
    			x[j+1].numeros= aux;
			}
		}
    	
    }
    
    printf ("Numeros ordenados: \n\n");  //print results 5 at a time
    for (i=1; i<n; i++)
    {
    	k=0;
    	while (k <1){
    	printf ("   | %d |   ", x[i].numeros);
    	k++;
        }
        if (i%5==0) 
        {
        	printf ("\n");
		}
	}
	*/
