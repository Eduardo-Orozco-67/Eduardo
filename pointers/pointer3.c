#include <stdio.h>
main()
{
	int a, b;
	int *punt1, *punt2;
	a = 5; b = 5;
	punt1 = &a; punt2 = &b;

	if ( *punt1 == *punt2 )
	{
	printf( "Son iguales\n" );
	printf( "a = %p b = %p", punt1, punt2 );
    }      
	else{printf( "Son desiguales\n" );}


}
/*
int foobar(int* n){
     *n = *n +1;
     return *n;
}
int main(){
int k = 6;
printf("foobar(k) = %d,",foobar(&k) );
printf(" k = %d\n", k);
}*/
