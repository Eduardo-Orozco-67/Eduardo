#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int opc, res, idd, id_pro, sm, id_dis, year, total, id_p, id, id1, anno, an, semana, sem, i, cant, can;
char nom[1], sta[1], fi[10], ff[10], fecha[10];
float precio, imp, bt;
int main(int argc, char const *argv[]){
printf("Bienvenido.....\n\n");
do{
puts("-.-.-.-.- M E N U -.-.-.-.-");
puts("1-. Proveedor");
puts("2-. Precio Leche");
puts("3-. Entrega Diaria");
puts("4-. Pago Semanal");
puts("5-. Denominación");
puts("6-. Distribución");
puts("7-. Salir");
scanf("%d",&opc);
switch(opc){
case 1:
do{
puts("---- PROVEEDOR ----");
puts("1-. Alta");
puts("2-. Consulta");
puts("3-. Modificar");
puts("4-. Baja");
puts("5-. Regresar");
scanf("%d",&res);
switch(res){
case 1:
printf("---- Alta de Proveedor ----\n");
printf("Ingrese id del proveedor: \t");
scanf("%d",&id_p);
printf("Ingrese nombre del proveedor: \t");
scanf("%s",nom);
printf("Ingrese status del proveedor: \t");
scanf("%s",sta);
break;
case 2:
printf("---- Informacion de los Proveedores ----\n");
printf("id_p:\t%d\n",id_p);
for (i=0; nom[i]; i++){
nom[i] =
toupper(nom[i]);
}
printf("Nombre:\t%s\n",nom);
for (i=0; sta[i]; i++){
sta[i] =
toupper(sta[i]);
}
printf("Status:\t%s\n",sta);
break;
case 3:
printf("---- Modificar Proveedor ----\n");
printf("Nombre nuevo: \t");
scanf("%s",nom);
printf("Status nuevo: \t");
scanf("%s",sta);
break;
case 4:
puts("---- Baja de Proveedor ----");
id_p = 0;
printf("ID: [%d]\n",id_p);
printf("Nombre: [%s]\n",strcpy(nom,""));
printf("Status: [%s]\n",strcpy(sta,""));
break;
}
}while (res != 5);
break;
case 2:
do{
puts("---- PRECIO LECHE ----");
puts("1-. Alta");
puts("2-. Consulta");
puts("3-. Modificar");
puts("4-. Baja");
puts("5-. Regresar");
scanf("%d",&res);
switch(res){
case 1:
puts("---- Alta del precio de leche ----");
printf("Ingresa año de registro:\t");
scanf("%d",&anno);
printf("Ingresa número de semana:\t");
scanf("%d",&semana);
printf("Ingresa fecha de inicio:\t");
scanf("%s",fi);
printf("Ingresa fecha de de fin:\t");
scanf("%s",ff);
printf("Ingresa precio de leche:\t");
scanf("%f",&precio);
break;
case 2:
puts("---- Información ----");
printf("Año: %d\n",anno);
printf("Semana: %d\n",semana);
printf("fecha inicio: %s\n",fi);
printf("fecha fin: %s\n",ff);
printf("Precio: %.2f\n",precio);
break;
case 3:
puts("---- Modificar ----");
printf("Ingresa año de registro:\t");
scanf("%d",&anno);
printf("Ingresa número de semana:\t");
scanf("%d",&semana);
printf("Ingresa fecha de inicio:\t");
scanf("%s",fi);
printf("Ingresa fecha de de fin:\t");
scanf("%s",ff);
printf("Ingresa precio de leche:\t");
scanf("%f",&precio);
break;
case 4:
puts("---- Baja ----");
anno = 0;
semana = 0;
precio = 0;
printf("Año: %d\n",anno);
printf("Semana: %d\n",semana);
printf("fecha inicio: %s\n",strcpy(fi,""));
printf("fecha fin: %s\n",strcpy(ff,""));
printf("Precio: %.2f\n",precio);
break;
}
}while(res != 5);
break;

case 3:
do{
puts("---- ENTREGA DIARIA ----");
puts("1-. Alta");
puts("2-. Consulta");
puts("3-. Modificar");
puts("4-. Baja");
puts("5-. Regresar");
scanf("%d",&res);
switch(res){
case 1:
puts("---- Alta de Entrega diaria ----");
printf("Id del proveedor:\t");
scanf("%d",&id);
printf("Ingrese fecha:\t");
scanf("%s",fecha);
printf("Cantidad:\t");
scanf("%d",&cant);
break;
case 2:
puts("---- Información de Entregas----");
printf("ID: %d\n",id);
printf("Fecha: %s\n",fecha);
printf("Cantidad: %d\n",cant);
break;
case 3:
puts("---- Modificar Entrega ----");
printf("Ingrese fecha:\t");
scanf("%s",fecha);
printf("Cantidad:\t");
scanf("%d",&cant);
break;
case 4:
puts("---- Baja ----");
id = 0;
cant = 0;
printf("ID: %d\n",id);
printf("Fecha: %s\n",strcpy(fecha,""));
printf("Cantidad: %d\n",cant);
break;
}
}while(res != 5);
break;
case 4:
do{
puts("---- PAGO SEMANAL ----");
puts("1-. Alta");
puts("2-. Consulta");
puts("3-. Modificar");
puts("4-. Baja");
puts("5-. Regresar");
scanf("%d",&res);
switch(res){
case 1:
puts("---- Alta de Pago ----");
printf("Id del proveedor:\t");
scanf("%d",&id1);
printf("Año:\t");
scanf("%d",&an);
printf("Semana:\t");
scanf("%d",&sem);
printf("Importe:\t");
scanf("%f",&imp);
printf("Cantidad:\t");
scanf("%d",&can);
break;
case 2:
puts("---- Información de Pagos----");
printf("ID: [%d]\n",id1);
printf("Año: [%d]\n",an);
printf("Semana: [%d]\n",sem);
printf("Importe: [%.2f]\n",imp);
printf("Cantidad: [%d]\n",can);
break;
case 3:

puts("---- Modificar Entrega ----");
printf("Año:\t");
scanf("%d",&an);
printf("Semana:\t");
scanf("%d",&sem);
printf("Importe:\t");
scanf("%f",&imp);
printf("Cantidad:\t");
scanf("%d",&can);
break;
case 4:
puts("---- Baja de Entrega----");
id1 = 0;
an = 0;
sem = 0;
imp = 0;
can = 0;
printf("ID: [%d]\n",id1);
printf("Año: [%d]\n",an);
printf("Semana: [%d]\n",sem);
printf("Importe: [%.2f]\n",imp);
printf("Cantidad: [%d]\n",can);
break;
}
}while(res != 5);
break;
case 5:
do{
puts("---- DENOMINACIÓN ----");
puts("1-. Alta");
puts("2-. Consulta");
puts("3-. Modificar");
puts("4-. Baja");
puts("5-. Regresar");
scanf("%d",&res);
switch(res){
case 1:
puts("---- Alta ----");
printf("Id de Denominacion:\t");
scanf("%d",&idd);
printf("Valor de Billete:\t");
scanf("%f",&bt);
break;
case 2:
puts("---- Información de Pagos----");
printf("ID: [%d]\n",idd);
printf("Nominal: [%.2f]\n",bt);
break;
case 3:
puts("---- Modificar Entrega ----");
printf("Ingrese nuevo valor de Billete:\t");
scanf("%f",&bt);
break;
case 4:
puts("---- Baja de Entrega----");
idd = 0;
bt = 0;
printf("ID: [%d]\n",idd);
printf("Billete: [%.2f]\n",bt);
break;
}
}while(res != 5);
break;
case 6:
do{
puts("---- DISTRIBUCIÓN ----");
puts("1-. Alta");
puts("2-. Consulta");
puts("3-. Modificar");
puts("4-. Baja");
puts("5-. Regresar");
scanf("%d",&res);
switch(res){
case 1:
puts("---- Alta ----");

printf("Ingresa id del proveedor:\t");
scanf("%d",&id_pro);
printf("Ingresa año:\t");
scanf("%d",&year);
printf("Ingresa semana:\t");
scanf("%d",&sm);
printf("Ingresa id de Distribución:\t");
scanf("%d",&id_dis);
printf("Ingresa la cantidad:\t");
scanf("%d",&total);
break;
case 2:
puts("---- Información ----");
printf("Id del proveedor:%d\t",id_pro);
printf("Año:%d\t ",year);
printf("Semana:%d\t ",sm);
printf("Id de la Distribucion: %d\t ",id_dis);
printf("Cantidad:%d\t ",total);
break;
case 3:
puts("---- Modificar Entrega ----");
printf("Ingresa año:\t");
scanf("%d",&year);
printf("Ingresa semana:\t");
scanf("%d",&sm);
printf("Ingresa id de Distribución:\t");
scanf("%d",&id_dis);
printf("Ingresa la cantidad:\t");
scanf("%d",&total);
break;
case 4:
puts("---- Baja de Entrega----");
id_pro = 0;
year = 0;
sm = 0;
id_dis = 0;
total = 0;
printf("Id del proveedor:%d\t",id_pro);
printf("Anio:%d\t ",year);
printf("Semana:%d\t ",sm);
printf("Id de la Distribucion: %d\t ",id_dis);
printf("Cantidad:%d\t ",total);
break;
}
}while(res != 5);
break;
default:
puts("Bey.............");
break;
}
} while (opc != 7);
return 0;
getch();
}
