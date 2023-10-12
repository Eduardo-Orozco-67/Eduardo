#include<stdio.h>
#include<conio.h>

struct producto {
    int codigo;
    char descripcion[41];
    float precio;
};

void cargar(struct producto *pprod)
{
    printf("Ingrese codigo:");
    scanf("%i",&pprod->codigo);
    fflush(stdin);
    printf("Ingrese descripcion:");
    gets(pprod->descripcion);
    printf("Ingrese precio:");
    scanf("%f",&pprod->precio);
}

void imprimir(struct producto prod)
{
    printf("Codigo:%i\n",prod.codigo);
    printf("Descripcion:%s\n",prod.descripcion);
    printf("Precio:%0.2f",prod.precio);
}


int main()
{
    struct producto prod;
    cargar(&prod);
    imprimir(prod);
    getch();
    return 0;
}
