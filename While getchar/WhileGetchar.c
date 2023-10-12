#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void)
 {
	int blanks=0, digits=0, letters=0, others=0;
	int c;
	printf("GAY");
while((c=getchar())!= EOF)	
{
	if(c==' ')
     {
      blanks++;
     }
    else
      {
     		if(c>='0' && c<='9')
     		{
     		++digits;
          	}
     		 else
     		 {
     		 	if(c>='a' && c<='z' ||  c>='A' && c<='Z')
     		 	{
     		 	++letters;
     		    }
     		      	else
     		 	    {
     		 		  ++others;
			        }
			 }
		}
	 }

       printf(" blanks = %d, digits = %d ,letters = %d, ", blanks, digits, letters);
       printf(" others=%d", others);
	return 0;
	getch();
}
