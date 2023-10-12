#include<stdio.h>

int main()
{
    int vec[5]={10,20,30,40,50};
    int *pe;
    int f;
    pe=vec;
    for(f=0;f<5;f++)
    {
        printf("%i ",pe[f]);
    }
    getch();
    return 0;
}
