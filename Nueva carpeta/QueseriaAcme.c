#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct lista1{
int id_p;
char nombre[35];
char status;
struct l1 *sig;
struct l1 *ant;
}l1;
typedef struct lista2{
int agno;
int semana;
char fecha_inicio[30];
char fecha_fin[30];
float precio;
struct l2 *sig2;
struct l2 *ant2;
}l2;
typedef struct lista3{
int id_p;
char fecha[30];
int cantidad;
struct l3 *sig3;
struct l3 *ant3;
}l3;
typedef struct lista4{
int id_p;
int agno;
int semana;
float importe;
int cantidad;
struct l1 *sig4;
struct l1 *ant4;
}l4;
typedef struct lista5{
 int id_no;
float nominal;
struct denominacion *sig5;
struct denominacion *ant5;
}de;
typedef struct lista6{
int id_p;
int agno;
int semana;
int id_distri;
int cantidad;
struct l6 *sig6;
struct l6 *ant6;
}l6;
//-----VARIABLES PARA USAR LAS ESTRUCTURAS-------
l1 *nodo = NULL, *inicio = NULL, *ultimo = NULL, *aux = NULL;
l2 *nodo2 = NULL, *inicio2 = NULL, *ultimo2 = NULL, *aux2 = NULL;
l3 *nodo3 = NULL, *inicio3 = NULL, *ultimo3 = NULL, *aux3 = NULL;
l4 *nodo4 = NULL, *inicio4 = NULL, *ultimo4 = NULL, *aux4 = NULL;
de *nodo5 = NULL, *inicio5 = NULL, *ultimo5 = NULL, *aux5 = NULL;
l6 *nodo6 = NULL, *inicio6 = NULL, *ultimo6 = NULL, *aux6 = NULL;
char* conversor(char *nombre); // Pasa de minúsculas a mayúsculas
int validacion(l1 **inicio, l1 **ultimo, char *name),validar(int valor,int opcion); // Validación de nombre
void impresion(l1 **inicio, l1 **ultimo),impresion2(l2 **inicio2, l2 **ultimo2);
void impresion3(l3 **inicio3, l3 **ultimo3),impresion4(l4 **inicio4, l4 **ultimo4);
void impresion5(de **inicio5, de **ultimo5),impresion6(l6 **inicio6, l6 **ultimo6);
char Status();
//------ VaARIABLES MANEJABLES -------
int opc,res,id_actual=0,idd_actual=0,x,y,temp,dia,mes,agno,n=0,id_temp,cant_temp,id_nomina=0;
float pre_temp,imp_tem;
char nombreaux[35],fecha_temp[30];
void a1(),mod1(),e1(),a2(),mod2(),e2(),a3(),mod3(),e3(),a4(),mod4(),e4(),a5(),/*mod5(),*/e5(),a6(),mod6(),e6();
//--------------------------------------------------------------
void a1(){
printf("Ingresa el nombre: "); scanf("%s",nombreaux);
strcpy(nombreaux, conversor(nombreaux)); // Conversion de minúsculas a mayúsculas
if(validacion(&inicio, &ultimo, nombreaux)==0){
nodo=(l1*)malloc(sizeof(l1));
strcpy(nodo->nombre, nombreaux);
nodo->status = Status();
nodo->id_p = ++id_actual;
nodo -> sig = NULL;
if(inicio == NULL){
nodo -> ant = NULL;
inicio = nodo;
}else{
nodo -> ant = ultimo;
ultimo -> sig = nodo;
}
ultimo = nodo;
}else{
printf("El nombre ya existe");
}
getchar();
}
void mod1(){
if(inicio == NULL){
printf("\aNo hay registros... :(\n");
}else{
do{
aux = NULL; y=0;
if(inicio -> sig == NULL){
printf("Deseas modificar a %s?\n\n", inicio->nombre);
printf("1.- Si.\n2.- No.\n\nEsperando opcion: ");
scanf ("%d",&x);
switch (x){
case 1: aux=inicio; break;
case 2: x=0; break;
default: printf("\n\nOpcion invalida.\n"); x=1; break;
}
}else{
printf("Que persona deseas modificar: \n\n");
for(nodo = inicio; nodo != NULL ; nodo = nodo -> sig)
printf("%d.- %s\n", ++y, nodo-> nombre);
printf("%d.- REGRESAR\n\nEsperando valor: ",y+1); scanf ("%d", &x);
if((x<1) || (x>(y+1)) ){
printf("\n\nOpcion invalida.\n"); x=1;
}
else if(x==(y+1)) x=0;
else if(x==1){ aux = inicio; }
else if(x==y){ aux=ultimo; }
else{ y=1;
for(nodo = inicio; nodo != NULL ; nodo = nodo -> sig){
if(y==x){ aux = nodo; break; } y++;
}
}
}if(aux!=NULL){ int d;
do{
system("clear");
printf("Nombre: %s\nStatus: %c\n\n", aux->nombre, aux->status);
printf("Que desas modificar?\n\n1.- Nombre\n2.- Status\n3.- Salir\n\nEsperando opcion: ");
scanf("%d",&d);
switch(d){
case 1:
printf("\nIngresa el nuevo nombre: "); scanf("%s",nombreaux);
printf("\n%s\n",nombreaux);
strcpy(nombreaux, conversor(nombreaux)); // Conversion de minúsculas a mayúsculas
if(validacion(&inicio, &ultimo, nombreaux)==0){
strcpy(aux->nombre, nombreaux);
}else{ printf("\n\nEl nombre ya existe");}
break;
case 2:
if(aux->status=='A')
printf("\nDeseas desactivar ");
else
printf("\nDeseas activar ");
printf("el status de %s?\n\n1).- Si\n2).- No\n\nEsperando opcion: ",aux->nombre);
scanf("%d", &x);
switch(x){
case 1:
if(aux->status == 'A')
aux->status =
'I';
else
aux->status =
'A';
break;
default: printf("\n\nOpcion invalida"); break;
} x=1; break;
case 3: if(inicio->sig==NULL) x=0; else x=1; break;
default: printf("\n\nOpcion ivalida"); getchar(); break;
}
}while(d!=3);
}
}while(x!=0);
}
}
void e1(){
if(inicio == NULL){
printf("\aNo hay registros... :(\n");
}
else{
do{
if(inicio -> sig == NULL){ // SI inicio-> sig es = NULL, entoces solo hay un registro... xD
printf("Deseas eliminar a %s?\n\n", inicio->nombre);
printf("1.- Si.\n2.- No.\n\nEsperando opcion: ");
scanf ("%d", &x);
switch (x){
case 1:// Si x = 1, entoces se elimina el unico registro
printf("\n\nSe ha extraido a %s", inicio-> nombre); inicio = NULL;
break;
case 2: x=0; break;
default: printf("\n\nOpcion invalida.\n"); x=1; break;
}
}
else{ // Si inicio-> sig es != NULL, entoces hay mas de un registro... xD
printf("Que persona deseas Eliminar: \n\n"); y=0;
for(nodo = inicio; nodo != NULL ; nodo = nodo -> sig) // Impresion de todos los alumnos posibles a eliminar
printf("%d.- %s\n", ++y, nodo-> nombre);
printf("%d.- REGRESAR\n\nEsperando valor: ", y+1);
scanf ("%d", &x);
if((x<1) || (x>(y+1)) ){ // Si x (valor seleccionado) no esta dentro de los valores permitidos es invalido... :(
printf("\n\nOpcion invalida.\n"); x=1;
}
else if(x==(y+1)) x=0;// Si x es = (y + 1) entoces se sale de la opcion extraer sin extraer nada... xD
else if(x==1){ // Si x es = a 1, entonces se extraer el primer elemento.
printf("\n\nPersona extraida: %s", inicio-> nombre);
inicio = inicio->sig;
inicio -> ant = NULL;
}
else if(x==y){ // Si x es = a "y", entonces se extrae el ultimo elemento.
printf("\n\nPersona extraida: %s", ultimo-> nombre);
ultimo = ultimo -> ant;
ultimo -> sig = NULL;
}
else{ y=1; // Encaso de no ser ningna de las opciones anteriores... se extraer un elemento de enmedio...
for(nodo = inicio; nodo != NULL ; nodo = nodo -> sig){
if(y==x){ aux = nodo; break; }
y++;
}
nodo = aux;
printf("\n\nPersoan extraida: %s", nodo-> nombre);
aux = aux -> ant;
nodo = nodo -> sig;
aux -> sig = nodo;
nodo -> ant = aux;
}
}
}while(x!=0 && inicio!=NULL);
}
}
void a2(){
printf("Ingresa valor al año: "); scanf("%d",&temp);
if(temp>=2018){
nodo2=(l2*)malloc(sizeof(l2));
nodo2->agno=temp;
printf("ingrsa valor de semana\n"); scanf("%d",&temp);
if (validar(temp,4)!=0){}
nodo2->semana=temp;
printf("ingresando fecha inicio\n");
printf("ingresa dia : \t");scanf("%d",&dia);
if(validar(dia,1)!=0){}
printf("ingresa mes : \t"); scanf("%d",&mes);
if (validar(mes,2)!=0){}
printf("ingresa agno : \t");scanf("%d",&agno);
if (validar(agno,3)){}
sprintf(fecha_temp,"%d-%d-%d",dia,mes,agno);
strcpy(nodo2->fecha_inicio,fecha_temp);
printf("ingresando fecha fin\n");
printf("ingresa dia : \t"); scanf("%d",&dia);
if(validar(dia,1)!=0){}
printf("ingresa mes : \t");scanf("%d",&mes);
if (validar(mes,2)!=0){}
printf("ingresa agno : \t");scanf("%d",&agno);
if (validar(agno,3)){}
sprintf(fecha_temp,"%d-%d-%d",dia,mes,agno);
strcpy(nodo2->fecha_fin,fecha_temp);
printf("ingresa el precio\n");
scanf("%f",&nodo2->precio);
nodo2 -> sig2 = NULL;
if(inicio2 == NULL){
nodo2 -> ant2 = NULL;
inicio2 = nodo2;
}else{
nodo2 -> ant2 = ultimo2;
ultimo2 -> sig2 = nodo2;
}
ultimo2 = nodo2;
}else{
printf("El valor que ingreasastes no es correcto\n");
}
}
void mod2(){
if(inicio2 == NULL){
printf("\aNo hay registros... :(\n");
}else{
do{
aux2 = NULL; y=0;
if(inicio2 -> sig2 == NULL){
printf("Deseas modificar año %d\t semana: %d\t con fecha_inicio : %s\t?\n",inicio2->agno,inicio2->semana,inicio2->fecha_inicio);
printf(" con fecha_inicio : %s\t y precio %.2f?\n\n",inicio2->fecha_fin,inicio2->precio);
printf("1.- Si.\n2.- No.\n\nEsperando opcion: ");
scanf ("%d", &x);
switch (x){
case 1: aux2=inicio2; break;
case 2: x=0; break;
default: printf("\n\nOpcion invalida.\n");
x=1; break;
}
}else{
printf("Que persona deseas modificar: \n\n");
for(nodo2 = inicio2; nodo2 != NULL ; nodo2 = nodo2 -> sig2)
printf("%d.- %d.- %d .- %s .- %.2f\n", ++y,nodo2->agno,nodo2->semana,nodo2->fecha_inicio,nodo2->precio);
 printf("%d.- REGRESAR\n\nEsperando valor: ", y+1);
scanf ("%d", &x);
if((x<1) || (x>(y+1)) ){
printf("\n\nOpcion invalida.\n"); x=1;
}
else if(x==(y+1)) x=0;
else if(x==1){ aux2 = inicio2; }
else if(x==y){ aux2 = ultimo2; }
else{ y=1;
for(nodo2 = inicio2; nodo2 != NULL ; nodo2 = nodo2 -> sig2){
if(y==x){
aux2 = nodo2;
break;
} y++;
}
}
}
if(aux2!=NULL){
int d;
do{
system("clear");
printf("agno: %d\t semana : %d\n fecha inicio: %s\n", aux2->agno, aux2->semana,aux2->fecha_inicio);
printf("fecha fin: %s\t precio : %.2f\n", aux2->fecha_fin, aux2->precio);
printf("a quien desas modificar?\n\n1.- agno\n2.- semana\n3.- fecha inicio\n4.-fecha fin\n5.-precio\n6.-Salir\n\nEsperando opcion: ");
scanf("%d", &d);
switch(d){
case 1:
printf("\nIngresa el nuevo valor del año: ");
scanf("%d",&temp);
if (validar(temp,3)!=0){}
aux2->agno=temp;
break;
 case 2:
 printf("\nIngresa el nuevo de la semana: ");
scanf("%d",&temp);
if (validar(temp,4)!=0){}
aux2->semana=temp;
 break;
case 3:
printf("ingresa nueva fecha inicio\n");
printf("ingresa dia : \t");scanf("%d",&dia);
 if(validar(dia,1)!=0){}
 printf("ingresa mes : \t");scanf("%d",&mes);
 if (validar(mes,2)!=0){}
 printf("ingresa agno : \t");scanf("%d",&agno);
 if (validar(agno,3)){}
 sprintf(fecha_temp,"%d-%d-%d",dia,mes,agno);
 strcpy(aux2->fecha_inicio,fecha_temp);
 printf("fecha esta correctamente modificada\n");
break;
case 4:
printf("ingresa nueva fecha fin\n");
printf("ingresa dia : \t");scanf("%d",&dia);
 if(validar(dia,1)!=0){}
 printf("ingresa mes : \t");scanf("%d",&mes);
 if (validar(mes,2)!=0){}
 printf("ingresa agno : \t");scanf("%d",&agno);
 if (validar(agno,3)){}
 sprintf(fecha_temp,"%d-%d-%d",dia,mes,agno);
 strcpy(aux2->fecha_fin,fecha_temp);
 printf("fecha esta correctamente modificada\n");
break;
case 5:
printf("ingresa nuevo precio\n");
scanf("%f",&pre_temp);
while(pre_temp==0.0){printf("ingresa cantidadoorecta\n"); 
scanf("%f",&pre_temp);
}
 aux2->precio=pre_temp;
break;
case 6: if(inicio2->sig2==NULL) x=0; else x=1; break;
default: printf("\n\nOpcion ivalida"); break;
}
}while(d!=6);
}
}while(x!=0);
}
}
void e2(){
if(inicio2 == NULL){
printf("\aNo hay registros... :(\n");
}else{
do{
if(inicio2 -> sig2 == NULL){ // SI inicio-> sig es = NULL, entoces solo hay un registro... xD
printf("Deseas eliminar año : %d\t con semana : %d\t fecha_inicio : %s y precio : %f \n?\n\n",
inicio2->agno,inicio2->semana,inicio2->fecha_inicio,inicio2->precio);
printf("1.- Si.\n2.- No.\n\nEsperando opcion: ");
scanf ("%d", &x);
switch (x){
case 1:// Si x = 1, entoces se elimina el unico registro
printf("\n\nSe ha extraido a %d con semana :%d y precio : %.2f", inicio2->agno,inicio2->semana,inicio2->precio);
inicio2 = NULL;
break;
case 2: x=0; break;
default: printf("\n\nOpcion invalida.\n"); x=1; break;
}
}
else{ // Si inicio-> sig es != NULL, entoces hay mas de un registro... xD
printf("a quien deseas Eliminar: \n\n"); y=0;
for(nodo2 = inicio2; nodo2 != NULL ; nodo2 = nodo2 -> sig2) // Impresion detodos los alumnos posibles a eliminar
printf("%d.- %d .- %d .- %s .- %.2f\n", ++y,nodo2->agno,nodo2->semana,nodo2->fecha_inicio,nodo2->precio);
printf("%d.- REGRESAR\n\nEsperando valor: ", y+1);
scanf ("%d", &x);
if((x<1) || (x>(y+1)) ){ // Si x (valorseleccionado) no esta dentro de los valores permitidos es invalido... :(pinvalida.\n"); x=1;
}
else if(x==(y+1)) x=0; // Si x es = (y + 1) entoces se sale de la opcion extraer sin extraer nada... xD
else if(x==1){ // Si x es = a 1, entonces seextraer el primer elemento.
printf("\n\n valor extraida:año : %d\t semana %d\t con fecha inicio : %s\t y con cantidad: %.2f", inicio2->agno,inicio2->semana,inicio2->fecha_inicio,inicio2->precio);
inicio2 = inicio2->sig2;
inicio2 -> ant2 = NULL;
}
else if(x==y){ // Si x es = a "y", entonces se extrae el ultimo elemento.
printf("\n\ndato extraido: agno :%d\t con fecha inicio :%s\t y con precio : %.2f", ultimo2->agno,ultimo2->fecha_inicio,ultimo2->precio);
ultimo2 = ultimo2 -> ant2;
ultimo2 -> sig2 = NULL;
}else{ // Encaso de no ser ningna de las opciones anteriores... se extraer un elemento de enmedio...
y=1;
for(nodo2 = inicio2; nodo2 !=
NULL ; nodo2 = nodo2 -> sig2){
if(y==x){
aux2 = nodo2; break; } y++;
}
nodo2 = aux2;
printf("\n\nvalor extraido: %d con semana %d\t fecha : %s\t y precio \t%.2f",
nodo2->agno,nodo2->semana,nodo2->fecha_inicio,nodo2->precio);
aux2 = aux2 -> ant2;
nodo2 = nodo2 -> sig2;
aux2 -> sig2 = nodo2;
nodo2 -> ant2 = aux2;
}
}
}while(x!=0 && inicio2!=NULL);
}
}
void a3(){
printf("Ingresa id del proveedor: "); scanf("%d",&id_temp);
if(id_temp>0){
nodo3=(l3*)malloc(sizeof(l3));
nodo3->id_p=id_temp;
printf("ingresa dia : \t"); scanf("%d",&dia);
if(validar(dia,1)!=0){}
printf("ingresa mes : \t"); scanf("%d",&mes);
if (validar(mes,2)!=0){}
printf("ingresa agno : \t"); scanf("%d",&agno);
if (validar(agno,3)){}
sprintf(fecha_temp,"%d-%d-%d",dia,mes,agno);
strcpy(nodo3->fecha,fecha_temp);
printf("ingresa cantidad\n");
scanf("%d",&nodo3->cantidad);
nodo3 -> sig3 = NULL;
if(inicio3 == NULL){
nodo3 -> ant3 = NULL;
inicio3 = nodo3;
}else{
nodo3 -> ant3 = ultimo3;
ultimo3 -> sig3 = nodo3;
}
ultimo3 = nodo3;
}else{
printf("El valor que ingreasastes no es correcto\n");
}
}
void mod3(){
if(inicio3 == NULL){
printf("\aNo hay registros... :(\n");
}else{
do{ aux3 = NULL; y=0;
if(inicio3 -> sig3 == NULL){
printf("Deseas modificar a %d\t con fecha: %s\t con cantidad : %d\n?\n\n",inicio3->id_p,inicio3->fecha,inicio3->cantidad);
printf("1.- Si.\n2.- No.\n\nEsperando opcion: ");
scanf ("%d", &x);
switch (x){
case 1: aux3=inicio3; break;
case 2: x=0; break;
default: printf("\n\nOpcion invalida.\n"); x=1; break;
}
}else{
printf("Que persona deseas modificar: \n\n");
for(nodo3 = inicio3; nodo3 != NULL ; nodo3 = nodo3 -> sig3)
printf("%d %d.- %s .- %d\n", ++y,nodo3->id_p,nodo3->fecha,nodo3->cantidad);
printf("%d.- REGRESAR\n\nEsperando valor: ", y+1);
scanf ("%d", &x);
if((x<1) || (x>(y+1)) ){ printf("\n\nOpcion invalida.\n"); x=1; }
else if(x==(y+1)) x=0;
else if(x==1){ aux3 = inicio3; }
else if(x==y){ aux3 = ultimo3; }
else{ y=1;
for(nodo3 = inicio3; nodo3 != NULL ; nodo3 = nodo3 -> sig3){
if(y==x){ aux3 = nodo3; break; }
y++;
}
}
}
if(aux3!=NULL){ int d;
do{
system("clear");
printf("id proveedor: %d\nfecha : %s\n cantidad : %d\n\n", aux3->id_p, aux3->fecha,aux3->cantidad);
printf("Que desas modificar?\n\n1.- id_p\n2.- fecha\n3.- cantidad\n4.-Salir\n\nEsperando opcion: ");
scanf("%d", &d);
switch(d){
case 1:
printf("\nIngresa el nuevo id del proveedor: "); scanf("%d",&id_temp);
while(id_temp==0){
printf("\nIngresa el nuevo id correcto: ");
scanf("%d",&id_temp);
}
aux3->id_p=id_temp;
break;
case 2:
printf("ingresa nueva fecha\n");
printf("ingresa dia : \t");scanf("%d",&dia);
if(validar(dia,1)!=0){}
printf("ingresa mes : \t");scanf("%d",&mes);
if (validar(mes,2)!=0){}
printf("ingresa agno : \t");scanf("%d",&agno);
if (validar(agno,3)){}
sprintf(fecha_temp,"%d-%d-%d",dia,mes,agno);
strcpy(aux3->fecha,fecha_temp);
printf("fecha esta correctamente modificada\n");
break;
case 3:
printf("ingresa nueva cantidad\n");
scanf("%d",&cant_temp);
while(cant_temp==0){
printf("ingresa cantidad coorecta\n");
scanf("%d",&cant_temp);
}
aux3->cantidad=cant_temp;
break;
case 4: if(inicio3->sig3==NULL) x=0; else x=1; break;
default: printf("\n\nOpcion ivalida"); break;
}
}while(d!=4);
}
}while(x!=0);
}
}
void e3(){
if(inicio3 == NULL){
printf("\aNo hay registros... :(\n");
}else{
do{
if(inicio3 -> sig3 == NULL){ // SI inicio-> sig es = NULL, entoces solo hay un registro... xD
printf("Deseas eliminar a : %d\t con fecha : %s\t y cantidad : %d \n?\n\n", inicio3->id_p,inicio3->fecha,inicio3->cantidad);
printf("1.- Si.\n2.- No.\n\nEsperando opcion: "); scanf ("%d", &x);
switch (x){
case 1:// Si x = 1, entoces se elimina el unico registro
printf("\n\nSe ha extraido a %d", inicio3->id_p);
inicio3 = NULL;
break;
case 2: x=0; break;
default: printf("\n\nOpcion invalida.\n"); x=1; break;
}
}else{ // Si inicio-> sig es != NULL, entoces hay mas de un registro... xD
printf("a quien deseas Eliminar: \n\n"); y=0;
for(nodo3 = inicio3; nodo3 != NULL ; nodo3 = nodo3 -> sig3) // Impresion de todos los alumnos posibles a eliminar
printf("%d ID: %d FECHA: %s CANTIDAD: %d\n", ++y,nodo3->id_p,nodo3->fecha,nodo3->cantidad);
printf("%d.- REGRESAR\n\nEsperando valor: ", y+1);
scanf ("%d", &x);
if((x<1) || (x>(y+1)) ){ // Si x (valor seleccionado) no esta dentro de los valores permitidos es invalido... :(
printf("\n\nOpcion invalida.\n"); x=1;
}
else if(x==(y+1)) x=0; // Si x es = (y + 1) entoces se sale de la opcion extraer sin extraer nada...xD
else if(x==1){ // Si x es = a 1, entonces se extraer el primer elemento.
printf("\n\n valor extraida: id : %d\t con fecha : %s\t y con cantidad: %d", inicio3->id_p,inicio3->fecha,inicio3->cantidad);
inicio3 = inicio3->sig3;
inicio3 -> ant3 = NULL;
}else if(x==y){ // Si x es = a "y", entonces se extrae el ultimo elemento.
printf("\n\ndato extraido: id : %d\t con fecha :%s\t y con cantidad : %d", ultimo3->id_p,ultimo3->fecha,ultimo3->cantidad);
ultimo3 = ultimo3 -> ant3;
ultimo3 -> sig3 = NULL;
}else{ y=1;// Encaso de no ser ningna de las opciones anteriores... se extraer un elemento de enmedio...
for(nodo3 = inicio3; nodo3 != NULL ; nodo3 = nodo3 -> sig3){
if(y==x){ aux3 = nodo3; break; } y++;
} nodo3 = aux3;
printf("\n\nvalor extraido: %d %s", nodo3->id_p,nodo3->fecha);
aux3 = aux3 -> ant3;
nodo3 = nodo3 -> sig3;
aux3 -> sig3 = nodo3;
nodo3 -> ant3 = aux3;
}
}
}while(x!=0 && inicio3!=NULL);
}
}
void a4(){
printf("Ingresa el año: "); scanf("%d",&temp);
if(temp>=2018){
nodo4=(l4*)malloc(sizeof(l4));
nodo4->id_p = ++id_actual;
nodo4->agno=temp;
printf("ingrsa valor de semana\n"); scanf("%d",&temp);
if (validar(temp,4)!=0){}
nodo4->semana=temp;
printf("ingresa el importe\n"); scanf("%f",&imp_tem);
while(imp_tem==0.0){
printf("ingresa un importe correcto\n"); scanf("%f",&imp_tem);
}
nodo4->importe=imp_tem;
 printf("ingresa cantidad\n");
scanf("%d",&nodo4->cantidad);
nodo4-> sig4 = NULL;
if(inicio4 == NULL){
nodo4 -> ant4 = NULL;
inicio4= nodo4;
}else{
nodo4 -> ant4 = ultimo4;
ultimo4 -> sig4 = nodo4;
}
ultimo4 = nodo4;
}else{
printf("El valor que ingreasastes no es correcto\n");
}
}
void mod4(){
if(inicio4 == NULL){
printf("\aNo hay registros... :(\n");
}else{
do{
aux4 = NULL; y=0;
if(inicio4 -> sig4 == NULL){
printf("Deseas modificar a %d\t con año: %d\t con semana : %d\n?\n\n",inicio4->id_p,inicio4->agno,inicio4->semana);
printf("1.- Si.\n2.- No.\n\nEsperando opcion: ");
scanf ("%d", &x);
switch (x){
case 1: aux4=inicio4; break;
case 2: x=0; break;
default: printf("\n\nOpcion invalida.\n"); x=1; break;
}
}else{
printf("a quien deseas modificar: \n\n");
for(nodo4 = inicio4; nodo4 != NULL ; nodo4 = nodo4 -> sig4)
printf("%d id : %d.- año : %d .- semana : %d.-\n", ++y,nodo4->id_p,nodo4->agno,nodo4->semana);
printf("%d.- REGRESAR\n\nEsperando valor: ", y+1);
scanf ("%d", &x);
if((x<1) || (x>(y+1)) ){
printf("\n\nOpcion invalida.\n"); x=1;
}
else if(x==(y+1)) x=0;
else if(x==1){ aux4 = inicio4; }
else if(x==y){ aux4 = ultimo4; }
else{ y=1;
for(nodo4 = inicio4; nodo4 != NULL ; nodo4 = nodo4 -> sig4){
if(y==x){ aux4 = nodo4;
break; } y++;
}
}
}
if(aux4!=NULL){ int d;
do{
system("clear");
printf("id proveedor: %d\n año : %d\n semana : %d\n importe: %.3f\n cantidad : %d\n\n", aux4->id_p, aux4->agno,aux4->semana,aux4->importe,aux4->cantidad);
printf("Que desas modificar?\n\n1.- agno\n2.- semana \n3.- importe\n4.- cantidad\n5.-Salir\n\nEsperando opcion: ");
scanf("%d", &d);
switch(d){
case 1:
printf("\nIngresa el nuevo valor del año: "); scanf("%d",&temp);
if (validar(temp,3)!=0){}
aux4->agno=temp;
 break;
case 2:
printf("\nIngresa el nuevo de la semana: "); scanf("%d",&temp);
if (validar(temp,4)!=0){}
aux4->semana=temp;
break;
case 3:
 printf("ingresa el nuevo importe a ingresar\n"); scanf("%f",&imp_tem);
 while(imp_tem==0.0){
printf("ingresa un importe correcto\n");
scanf("%f",&imp_tem);
 }
 aux4->importe=imp_tem;
break;
case 4:
printf("ingresa nueva cantidad\n");
scanf("%d",&cant_temp);
while(cant_temp==0){
printf("ingresa cantidad coorecta\n");
scanf("%d",&cant_temp);
}
 aux4->cantidad=cant_temp;
break;
case 5: if(inicio4->sig4==NULL) x=0; else x=1; break;
default: printf("\n\nOpcion ivalida"); break;
}
}while(d!=5);
}
}while(x!=0);
}
}
void e4(){
if(inicio4 == NULL){
printf("\aNo hay registros... :(\n");
}else{
do{
if(inicio4 -> sig4 == NULL){ // SI inicio-> sig es = NULL, entoces solo hay un registro... xD
printf("Deseas eliminar a : %d\t con agno : %d\t semana : %d\t importe :%.3f\t\n?\n\n", inicio4->id_p,inicio4->agno,inicio4->semana,inicio4->importe);
printf("1.- Si.\n2.- No.\n\nEsperando opcion: ");
scanf ("%d", &x);
switch (x){
case 1:// Si x = 1, entoces se elimina el unico registro
printf("\n\nSe ha extraido a %d", inicio4->id_p);
inicio4 = NULL;
break;
case 2: x=0; break;
default: printf("\n\nOpcion invalida.\n"); x=1; break;
}
}else{ // Si inicio-> sig es != NULL, entoces hay mas de un registro... xD
printf("a quien deseas Eliminar: \n\n"); y=0;
for(nodo4 = inicio4; nodo4 != NULL ; nodo4 = nodo4 -> sig4) // Impresion de todos los alumnos posibles a eliminar
printf("%d.- id: %d año: %d semana: %d importe: %.3f\n", ++y,nodo4->id_p,nodo4->agno,nodo4->semana,nodo4->importe);
printf("%d.- REGRESAR\n\nEsperando valor: ", y+1);
scanf ("%d", &x);
if((x<1) || (x>(y+1)) ){ // Si x (valor seleccionado) no esta dentro de los valores permitidos es invalido... :(
printf("\n\nOpcion invalida.\n"); x=1;
}
else if(x==(y+1)) // Si x es = (y + 1) entoces se sale de la opcion extraer sin extraer nada... xD
x=0;
else if(x==1){ // Si x es = a 1, entonces se extraer el primer elemento.
printf("\n\n valor extraida: id : %d\t con año : %d\t con semana: %d", inicio4->id_p,inicio4->agno,inicio4->semana);
inicio4 = inicio4->sig4;
inicio4 -> ant4 = NULL;
}
else if(x==y){ // Si x es = a "y", entonces se extrae el ultimo elemento.
printf("\n\ndato extraido: id : %d\t con año :%d\t y con semana : %d", ultimo4->id_p,ultimo4->agno,ultimo4->semana);
ultimo4 = ultimo4 -> ant4;
ultimo4 -> sig4 = NULL;
}else{ y=1; // Encaso de no ser ningna de las opciones anteriores... se extraer unelemento de enmedio...
for(nodo4 = inicio4; nodo4 != NULL ; nodo4 = nodo4 -> sig4){
if(y==x){ aux4 = nodo4; break; }
y++;
}
nodo4 = aux4;
printf("\n\nvalor extraido: %d\t con año %d\t y importe %.3f\n",
nodo4->id_p,nodo4->agno,nodo4->importe);
aux4 = aux4 -> ant4;
nodo4 = nodo4 -> sig4;
aux4 -> sig4 = nodo4;
nodo4 -> ant4 = aux4;
}
}
}while(x!=0 && inicio!=NULL);
}
}
void a5(){
nodo5=(de*)malloc(sizeof(de));
printf("ingresa denominacion\n"); scanf("%f",&nodo5->nominal);
nodo5->id_no=++id_nomina;
if(inicio5 == NULL){
nodo5 -> ant5 = NULL;
inicio5 = nodo5;
}else{
nodo5 -> ant5 = ultimo5;
ultimo5 -> sig5 = nodo5;
}
ultimo5 = nodo5;
}
void e5(){
if(inicio5 == NULL){
printf("\aNo hay registros... :(\n");
}else{
 do{
if(inicio5 -> sig5 == NULL){ // SI inicio-> sig es = NULL, entoces solo hay un registro... xD
printf("Deseas eliminar a %d?\n\n", inicio5->id_no);
printf("con valor de nomina %.2f\n",inicio5->nominal );
printf("1.- Si.\n2.- No.\n\nEsperando opcion: ");
scanf ("%d", &x);
switch (x){
case 1:// Si x = 1, entoces se elimina el unico registro
printf("\n\nSe ha extraido a %f", inicio5->nominal); inicio5 = NULL;
break;
case 2: x=0; break;
default: printf("\n\nOpcion invalida.\n"); x=1; break;
}
}else{ // Si inicio-> sig es != NULL, entoces hay mas de un registro... xD
printf("Que persona id de nomina deseas eliminar: \n\n"); y=0;
for(nodo5 = inicio5; nodo5 != NULL ; nodo5 = nodo5 -> sig5) // Impresion de todos los alumnos posibles a eliminar
printf("%d.- %d\n", ++y, nodo5->id_no);
printf("%d.- REGRESAR\n\nEsperando valor: ", y+1);
scanf ("%d", &x);
if((x<1) || (x>(y+1)) ){ // Si x (valor seleccionado) no esta dentro de los valores permitidos es invalido... :(
printf("\n\nOpcion invalida.\n"); x=1;
}
else if(x==(y+1)) x=0; // Si x es = (y + 1) entoces se sale de la opcion extraer sin extraer nada... xD
else if(x==1){ // Si x es = a 1, entonces se extraer el primer elemento.
printf("\n\nPersona extraida: %d", inicio5->id_no);
inicio5 = inicio5->sig5;
inicio5 -> ant5 = NULL;
}else if(x==y){ // Si x es = a "y", entonces se extrae el ultimo elemento.
printf("\n\nid denominacion extraido: %d", ultimo5->id_no);
ultimo5 = ultimo5-> ant5;
ultimo5 -> sig5 = NULL;
}else{ y=1; // Encaso de no ser ningna de las opciones anteriores... se extraer un elemento de enmedio...
for(nodo5 = inicio5; nodo5 != NULL ; nodo5 = nodo5 -> sig5){
if(y==x){ aux5 = nodo5; break; } y++;
}
nodo5 = aux5;
printf("\n\nid denominacion extraido: %d", nodo5->id_no);
aux5 = aux5 -> ant5;
nodo5 = nodo5 -> sig5;
aux5 -> sig5 = nodo5;
nodo5-> ant5= aux5;
}
}
}while(x!=0 && inicio5!=NULL);
}
}
void a6(){
printf("Ingresa el año: "); scanf("%d",&temp);
if(temp>=2018){
nodo6=(l6*)malloc(sizeof(l6));
nodo6->id_p = ++id_actual;
nodo6->id_distri=++idd_actual;
nodo6->agno=temp;
printf("ingrsa valor de semana\n"); scanf("%d",&temp);
if (validar(temp,4)!=0){}
nodo6->semana=temp;
printf("ingresa cantidad\n");
scanf("%d",&nodo6->cantidad);
nodo6 -> sig6 = NULL;
if(inicio6 == NULL){
nodo6 -> ant6 = NULL;
inicio6 = nodo6;
}else{
nodo6 -> ant6 = ultimo6;
ultimo6 -> sig6 = nodo6;
}
ultimo6 = nodo6;
}else{
printf("El valor que ingreasastes no es correcto\n");
}
}
void mod6(){
if(inicio6 == NULL){
printf("\aNo hay registros... :(\n");
getchar();
}else{
do{
aux6 = NULL; y=0;
if(inicio6 -> sig6 == NULL){
printf("Deseas modificar a %d\t con año: %d\t con semana : %d\n?\n\n",inicio6->id_p,inicio6->agno,inicio6->semana);
printf("1.- Si.\n2.- No.\n\nEsperando opcion: ");
scanf ("%d", &x);
switch (x){
case 1: aux6=inicio6; break;
case 2: x=0; break;
default: printf("\n\nOpcion invalida.\n"); x=1; break;
}
}else{
printf("a quien deseas modificar: \n\n");
for(nodo6 = inicio6; nodo6 != NULL ; nodo6 = nodo6 -> sig6)
printf("%d id : %d.- año : %d .- semana : %d.-\n", ++y,nodo6->id_p,nodo6->agno,nodo6->semana);
printf("%d.- REGRESAR\n\nEsperando valor: ", y+1);
scanf ("%d", &x);
if((x<1) || (x>(y+1)) ){ printf("\n\nOpcion invalida.\n"); x=1; }
else if(x==(y+1)) x=0;
else if(x==1){ aux6 = inicio6; }
else if(x==y){ aux6 = ultimo6; }
else{ y=1;
for(nodo6 = inicio6; nodo6 != NULL ; nodo6 = nodo6 -> sig6){
if(y==x){ aux6 = nodo6; break; } y++;
}
}
}
if(aux6!=NULL){
int d;
do{
printf("id proveedor: %d\n año : %d\n semana : %d\n id distribucion: %d\n cantidad : %d\n\n", aux6->id_p, aux6->agno,aux6->semana,aux6->id_distri,aux6->cantidad);
printf("Que desas modificar?\n\n1.- agno\n2.- semana \n3.-cantidad\n4.-Salir\n\nEsperando opcion: ");
scanf("%d", &d);
switch(d){
case 1:
printf("\nIngresa el nuevo valor del año: "); scanf("%d",&temp);
if (validar(temp,3)!=0){}
aux6->agno=temp;
 break;
case 2:
printf("\nIngresa el nuevo de la semana: "); scanf("%d",&temp);
if (validar(temp,4)!=0){}
aux6->semana=temp;
break;
case 3:
printf("ingresa nueva cantidad\n"); scanf("%d",&cant_temp);
while(cant_temp==0){
printf("ingresa cantidad coorecta\n"); scanf("%d",&cant_temp);
}
 aux6->cantidad=cant_temp;
break;
case 4: if(inicio6->sig6==NULL) x=0; else x=1; break;
default: printf("\n\nOpcion ivalida"); break;
}
}while(d!=4);
}
}while(x!=0);
}
}
void e6(){
if(inicio6 == NULL){
printf("\aNo hay registros... :(\n");
}else{
do{
if(inicio6 -> sig6 == NULL){ // SI inicio-> sig es = NULL, entoces solo hay un registro... xD
printf("Deseas eliminar a : %d\t con agno : %d\t semana : %d\t cantidad :%d\t\n?\n\n", inicio6->id_p,inicio6->agno,inicio6->semana,inicio6->cantidad);
printf("1.- Si.\n2.- No.\n\nEsperando opcion: ");
scanf ("%d", &x);
switch (x){
case 1:// Si x = 1, entoces se elimina el unico registro
printf("\n\nSe ha extraido a %d", inicio6->id_p);
inicio6 = NULL;
break;
case 2: x=0; break;
default: printf("\n\nOpcion invalida.\n"); x=1; break;
}
}else{ // Si inicio-> sig es != NULL, entoces hay mas de un registro... xD
printf("a quien deseas Eliminar: \n\n"); y=0;
for(nodo6 = inicio6; nodo6 != NULL ; nodo6 = nodo6 -> sig6) // Impresion de todos los alumnos posibles a eliminar
printf("%d.- id : %d .- año :%d.- semana :%d .-cantidad : %d\n", ++y,nodo6->id_p,nodo6->agno,nodo6->semana,nodo6->cantidad);
printf("%d.- REGRESAR\n\nEsperando valor: ", y+1);
scanf ("%d", &x);
if((x<1) || (x>(y+1)) ){ // Si x (valor seleccionado) no esta dentro de los valores permitidos es invalido... :(
printf("\n\nOpcion invalida.\n"); x=1;
}
else if(x==(y+1)) x=0; // Si x es = (y + 1) entoces se sale de la opcion extraer sin extraer nada... xD
else if(x==1){ // Si x es = a 1, entonces se extraer el primer elemento.
printf("\n\n valor extraida: id : %d\t con año : %d\t con semana: %d", inicio6->id_p,inicio6->agno,inicio6->semana);
inicio6 = inicio6->sig6;
inicio6 -> ant6 = NULL;
}
else if(x==y){ // Si x es = a "y", entonces se extrae el ultimo elemento.
printf("\n\ndato extraido: id : %d\t con año :%d\t y con semana : %d", ultimo6->id_p,ultimo6->agno,ultimo6->semana);
ultimo6 = ultimo6 -> ant6;
ultimo6 -> sig6 = NULL;
}else{ y=1; // Encaso de no ser ningna de las opciones anteriores... se extraer un elemento de enmedio...
for(nodo6 = inicio6; nodo6 != NULL ; nodo6 = nodo6 -> sig6){
if(y==x){ aux6 = nodo6; break; } y++;
}
nodo6 = aux6;
printf("\n\nvalor extraido: %d\t con año %d\t y cantidad %d\n", nodo6->id_p,nodo6->agno,nodo6->cantidad);
aux6 = aux6 -> ant6;
nodo6 = nodo6 -> sig6;
aux6 -> sig6 = nodo6;
nodo6-> ant6 = aux6;
}
}
}while(x!=0 && inicio6!=NULL);
}
}
char* conversor(char *nombre){
int x=0;
do{
if(nombre[x]>= 'a' && nombre[x]<= 'z')
nombre[x] = (int)(nombre[x]) - 32;
x++;
}while(x < strlen(nombre));
return nombre;
}
int validacion(l1 **inicio, l1 **ultimo, char *name){
l1 *aux= NULL;
int d=0;
for(aux=*inicio ; aux != NULL ; aux = aux->sig){
if(strcmp(aux->nombre, name)==0){ d=1; break; }
}
return d;
}
void impresion(l1 **inicio, l1 **ultimo){
l1 *aux= NULL;
if(*inicio==NULL){ printf("\aNo hay registros... :(\n");
}else{
for(aux=*inicio ; aux != NULL ; aux = aux->sig){
printf("ID: %d\n", aux->id_p);
printf("Nombre: %s\n", aux->nombre);
printf("Status: %c\n\n", aux->status);
}
}
}
void impresion2(l2 **inicio2, l2 **ultimo2){
l2 *aux2= NULL;
if(*inicio2==NULL){
printf("\aNo hay registros... :(\n");
}else{
for(aux2=*inicio2 ; aux2 != NULL ; aux2 = aux2->sig2){
printf("año: %d\n", aux2->agno);
printf("semana: %d\n", aux2->semana);
printf("fecha inicio: %s\n", aux2->fecha_inicio);
printf("fecha fin: %s\n", aux2->fecha_fin);
printf("precio: %.2f\n\n\n", aux2->precio);
}
}
}
void impresion3(l3 **inicio3, l3 **ultimo3){
l3 *aux3= NULL;
if(*inicio3==NULL){
printf("\aNo hay registros... :(\n");
}else{
for(aux3=*inicio3 ; aux3 != NULL ; aux3 = aux3->sig3){
printf("Identificador: %d\n", aux3->id_p);
printf("fecha: %s\n", aux3->fecha);
printf("Cantidad: %d\n\n", aux3->cantidad);
}
}
}
void impresion4(l4 **inicio4, l4 **ultimo4){
l4 *aux4= NULL;
if(*inicio4==NULL){
printf("\aNo hay registros... :(\n");
}else{
for(aux4=*inicio4 ; aux4 != NULL ; aux4 = aux4->sig4){
printf("Identificador: %d\n", aux4->id_p);
printf("año: %d\n", aux4->agno);
printf("semana: %d\n", aux4->semana);
printf("importe: %.2f\n", aux4->importe);
printf("cantidad: %d\n\n", aux4->cantidad);
}
}
}
void impresion5(de **inicio5, de **ultimo5){
de *aux5= NULL;
if(*inicio5==NULL){
printf("\aNo hay registros... :(\n");
}else{
for(aux5=*inicio5 ; aux5!= NULL ; aux5 = aux5->sig5){
	printf("Identificador: %d\n", aux5->id_no);
printf("Nominacion: %.2f\n", aux5->nominal);
}
}
}
void impresion6(l6 **inicio6, l6 **ultimo6){
l6 *aux6= NULL;
if(*inicio6==NULL){
printf("\aNo hay registros... :(\n");
}else{
for(aux6=*inicio6 ; aux6 != NULL ; aux6 = aux6->sig6){
printf("Identificador: %d\n", aux6->id_p);
printf("año: %d\n", aux6->agno);
printf("semana: %d\n", aux6->semana);
printf("Identificador de distribucion: %.d\n", aux6->id_distri);
printf("cantidad: %d\n\n", aux6->cantidad);
}
}
}
char Status(){
int d;
printf("\nEstatus:\n\n1).- Activo\n2).- Inactivo\n\nEsperando una opcion: "); scanf("%d",&d);
if(d==1) return 'A';
else return 'I';
}
int validar(int valor,int opcion){
switch(opcion){
case 1:
while(valor==0 || valor>31){
printf("ingresa un dia comprendido entre 1 - 31 por favor\n"); scanf("%d",&valor);
}
break;
case 2:
while(valor==0 || valor>12){
printf("ingresa un mes corectamente\n"); scanf("%d",&valor);
}
break;
case 3:
while(valor<2018){
printf(" ingresa un año que este del 2018 en adelante \n"); scanf("%d",&valor);
}
break;
case 4:
while(valor==0||valor>52){
printf("introduce una semana correctamente\n"); scanf("%d",&valor);
}
break;
}
return valor;
}
