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
