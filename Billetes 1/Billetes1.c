#include <stdio.h>
 int main ()
{
   
   int bi200, bi100, bi50, bi20, mo10, mo5, mo2, mo1;
   int billetes;
     bi200=0;
     bi100=0;
     bi50=0;
     bi20=0;
     mo10=0;
     mo5=0;
     mo2=0;
     mo1=0;
    
    printf ("Ingrese el monto a dar a su provedor: ");
    scanf ("%d", &billetes);
 	
 	 if  (billetes>=200)
     {
    bi200=(billetes-billetes%200)/200;
    billetes=billetes%200;
   
     }

 
        if (billetes>=100)
         {
           bi100=(billetes-billetes%100)/100;
           billetes=billetes%100;
           
         }
      
	  
          if (billetes>=50)
           {
              bi50=(billetes-billetes%50)/50;
              billetes=billetes%50;
              
           }    
        
		
              if (billetes>=20)
               {
                 bi20=(billetes-billetes%20)/20;
                 billetes=billetes%20;
                
               }  
        
		
                 if (billetes>=10)
                  {
                    mo10=(billetes-billetes%10)/10;
                    billetes=billetes%10;
                   
                  }
            
    
                    if (billetes>=5)
                     {
                       mo5=(billetes-billetes%5)/5;
                       billetes=billetes%5;
                       
                     }
                 
   
                       if (billetes>=2)
 	                    {
                          mo2=(billetes-billetes%2)/2;
                          billetes=billetes%2;
                          
                        }  
                    
                          if (billetes>=1)
                           {
                             mo1=(billetes-billetes%1)/1;
                             billetes=billetes%1;
                             
                           }
                           
                printf ("Valor de billetes de 200: %d\n", bi200);
                printf ("Valor de billetes de 100: %d\n", bi100);
                printf ("Valor de billetes de 50: %d\n", bi50);
                printf ("Valor de billetes de 20: %d\n", bi20);
                printf ("Valor de monedas de 10: %d\n", mo10);
                printf ("Valor de monedas de 5: %d\n", mo5);
                printf ("Valor de monedas de 2: %d\n", mo2);
                printf ("Valor de monedas de 1: %d\n", mo1);
                       
	return 0;
	getch();
	
}
