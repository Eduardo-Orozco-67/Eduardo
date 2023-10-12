#include <stdio.h>
#include <stdint.h>
#include <math.h>
 
 //SUBMETHOD FOR CALCULATION
void sin_cos(double n) 
{
    double x;
    for (x=0;x<=n;x+=n) 
	{
    	//SINE AND COSINE CALCULATION
        printf("sin(%f)=%f\n", x, sin(x));
        printf("cos(%f)=%f\n", x, cos(x));
    }
}

int main()
{
    double N;
    //ASK FOR NUMBER BETWEEN 0 AND 1
    printf("Enter Number inside 0 or 1\n");
    scanf("%lf",&N);
    //CONDITIONAL
    if (N>=0 && N<=1 )
    {
        sin_cos(N);//CALL SUBMETHOD
    }
    else
    {
        printf("SORRY");
    }
}
