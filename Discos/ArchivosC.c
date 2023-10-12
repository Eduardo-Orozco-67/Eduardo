#include <stdio.h>
#include<stdlib.h>
#include<string.h>
//Used libraries

int main()
{
		printf("Hi, I am Edward, this is my homework\n");
	//declaration of variables 
	int a[5],sum=0,i,c,x,maxi;
	double prom;
	
	//creation of the txt file started in null
	FILE *varch= NULL;
    varch=fopen("varch.txt","a+");//open the file with read/write without deleting or overwriting 
     
    //file reading
	for(i=0;i<5;i++)
	{
        fscanf(varch,"%d",&a[i]);
    }
    
    //calculation of the average
    for(i=0;i<5;i++)
    {
    	sum=sum+a[i];	
	}
	prom=sum/4.0;
	for (i=1;i<5;i++)
	{
	   printf("%d ", a[i], " ");
	}
	printf("\navrage is %lf\n",prom);//show the average

	

       //search maximum number
	for(c=0;c<=4;c++)
	{
		for(i=1;i<4-c;i++)
		{
			if(a[i]>a[i+1])
			{
				x=a[i];
				a[i]=a[i+1];
				a[i+1]=x;
			}
		}
    }
    maxi=a[4];
	printf("max value is %d",maxi);//show maximum number
	
	fclose(varch);// close file
	
	getch(); //end of program
	return 0;
}
