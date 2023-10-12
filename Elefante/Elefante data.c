/*BY: JOSE EDUARDO OROZCO CARDENAS
ELEPHANT-SEAL-DATA*/

#include <stdio.h>
int main() {
	
    int e, i; //GLOBAL COUNTING VARIABLES
    
    float num[999] /*ARRAY*/, acum = 0.0, pro; //GLOBAL VARIABLES
    
    printf("insert the number of elephants to be calculated: \n"); //HOW MANY ELEPHANTS WE'LL KEEP
    scanf("%d", &e);

	
    for (i = 1; i <= e; ++i) 
	{
		printf("insert elephant weight #: %d\n", i); //WEIGHT OF ELEPHANT i (1,2,3...)
        scanf("%f", &num[i]);
        acum += num[i]; //ACCUMULATED SUM OF WEIGHTS
    }
    
	pro= acum / e; //CALCULATED AVERAGE
    printf("\nAverage = %f", pro); //PRINT AVERAGE
    return 0;
}
