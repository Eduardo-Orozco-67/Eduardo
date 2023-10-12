#include <stdio.h>
#include <math.h> //we need to use math library
 
int main()
{
    double I; //declare the variable in duplicate in order to transport the input
    printf("give a number between 0 and 1 "); // we need to ask the user
    scanf("%lf",&I); //computer need to read the number 
    
	if(I<=1&&I>=0) //we must put an interval 
     {  
        printf("Sin(%lf)=%lf\n",I,sin(I));//sin is used thanks to the math library the number will be automatically calculated
        
     }
    else 
     {
     printf("the given number is not between 0 and 1"); //condition of no-existence
     }
    return 0;
    getch();
}
