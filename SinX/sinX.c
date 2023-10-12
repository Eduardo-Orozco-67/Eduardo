/* Calculate sin of a function
By: Jose Eduardo Orozco Cardenas */

#include <stdio.h>
#include <stdlib.h>
#include <math.h> //includind math livrery

int main() 
{
	double x, radians, sen;
	
	printf("enter the value of x\n");
	scanf("%lf", &x);
	
	radians=x*M_PI/180; //we calculate the value in radians
	sen=sin(radians);  //we calculate sin to radians
	printf("Value of sin is: %lf \n", sen);//we print the answer 
	printf("Value of sin in radians is: %lf \a", sin(x)); //we print the answer in radians
	return 0;
	getch();
}


