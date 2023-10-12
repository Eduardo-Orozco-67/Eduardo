#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	enum meses{ene, feb, mar, abr, may, jun, jul, ago, sep, oct, nov, dic};
	enum meses next_meses(enum meses m)
	{
		return((m + 1) % 12);
	}
	printf("%u\n", next_meses(ene));

	return 0;
}
