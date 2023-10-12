#include <stdio.h>
#include <conio.h>
int main()
 {
    int bi200, bi100, bi50, bi20, mo10, mo5, mo2, mo1, mo50;
     double billetes;
    
    printf ("Ingrese el monto a dar a su provedor: ");
    scanf ("%lf", &billetes);
   
   //calculando bi200
    bi200=(int)(billetes/200);
    billetes=billetes-(bi200*200);
    printf ("Valor de billetes de 200: %d\n", bi200);
    
    //calculando bi100
    bi100=(int)(billetes/100);
    billetes=billetes-(bi100*100);
    printf ("Valor de billetes de 100: %d\n", bi100);
    
    //calculando bi50
    bi50=(int)(billetes/50);
    billetes=billetes-(bi50*50);
    printf ("Valor de billetes de 50: %d\n", bi50);
    
    //calculando bi20
    bi20=(int)(billetes/200);
    billetes=billetes-(bi20*200);
    printf ("Valor de billetes de 20: %d\n", bi20);
    
    //calculando mo10
    mo10=(int)(billetes/10);
    billetes=billetes-(mo10*10);
    printf ("Valor de monedas de 10: %d\n", mo10);
    
    //calculando mo5
    mo5=(int)(billetes/5);
    billetes=billetes-(mo5*5);
    printf ("Valor de monedas de 5: %d\n", mo5);
    
    //calculando mo2
    mo2=(int)(billetes/2);
    billetes=billetes-(mo2*2);
    printf ("Valor de monedas de 2: %d\n", mo2);
    
    //calculando mo1
    mo1=(int)(billetes/1);
    billetes=billetes-(mo1*1);
    printf ("Valor de monedas de 1: %d\n", mo1);
    
    //calculando mo50
    mo50=(int)(billetes/.50);
    billetes=billetes-(mo50*.50);
    printf ("Valor de monedas de 50c: %d\n", mo50);
    getch();
}
