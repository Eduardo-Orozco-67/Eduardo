#include<stdio.h>
#include <libpq-fe.h>
#include<stdlib.h>
#include<stdio_ext.h>
#include<string.h>
#include "conection.c"
PGconn *conexion;
PGresult *resultado;
////FUNCIONES/////
char* conversor(char *nombre);
char Status();

int main(){
conectar();

int pro,x,x2,i,j,opc,dia,mes,agno,semana,temp;
char nombreaux[35],status[1],cad[100],fecha_temp[30],fecha_temp2[30];
float nominal,precio,nominal2;


	printf("BIENVENIDO SISTEMA QUESERIA ACME\n");
	do{
	    printf("\t....::::    ::::....\n\n");
		printf("Que deseas hacer?\n\n1).- Proveedor.\n2).- Precio leche .\n3).- Entrega diaria\n");
		printf("4).- Pago semanal\n5).- Denominacion.\n6).- Distribucion. \n7).- Salir\n\nEsperando opcion: ");
		scanf("%d", &x);
		printf("\n--------------------------------------------\n\n");
		getchar();
		
        
		switch(x){
			case 1: do{

						__fpurge(stdin);
					    system ("clear");
						printf("\t....:::: LISTA DE PERSONAS ::::....\n\n");
						printf("%cQue deseas hacer?\n\n1).- Ingresar un proveedor.\n2).- Eliminar proveedor.\n3).- Modificar proveedor.\n4).- Imprimir\n", 168);
						printf("5).- Salir.\n\nEsperando opcion: ");
						scanf("%d", &x);
						printf("\n--------------------------------------------\n\n");
						
						//getchar();

						switch(x){
							case 1:
							__fpurge(stdin);
							printf("Ingresa el nombre del proveedor: ");
					        gets(nombreaux);
                            strcpy(nombreaux, conversor(nombreaux));
							status[0]=Status();
                            sprintf(cad,"insert into proveedor(nombre,estado)values('%s','%c');",nombreaux,status[0]);

							
							if(PQstatus(conexion) != CONNECTION_BAD)
							PQexec(conexion,cad);
							
							
							
							break;
							case 2:
							__fpurge(stdin);
							printf("..::::BAJAS DE PROVEEDOR::::..\n");
							if(PQstatus(conexion) != CONNECTION_BAD)
							  resultado = PQexec(conexion,"select * from proveedor;");
							    if(resultado !=NULL){

						            for(i=0; i<PQntuples(resultado); i++){

						               for(j=0; j<PQnfields(resultado); j++){

						                  printf("%s\t",PQgetvalue(resultado,i,j));
						               }
						             printf("\n");
						          }
						        }
							
							getchar();
							__fpurge(stdin);
							printf("Digite el id del proveedor a Eliminar\n");
							scanf("%d",&pro);
							sprintf(cad,"delete from proveedor where idp=%d;",pro);
							PQexec(conexion, cad);
							printf("usuario eliminado\n");
							break;
							
							case 3:
							__fpurge(stdin);
							do{
								printf("..::::MODIFICACION DE PROVEEDOR::::..\n");
								puts("1-. Nombre");
	                            puts("2-. Estado");
	                            puts("3-. Regresar");
	                            scanf("%d",&opc);
	                            switch(opc){
	                            	case 1:
	                            	__fpurge(stdin);
	                            	    if(PQstatus(conexion) != CONNECTION_BAD)
							              resultado = PQexec(conexion,"select idp,nombre from proveedor;");
							              if(resultado !=NULL){

								            for(i=0; i<PQntuples(resultado); i++){

								               for(j=0; j<PQnfields(resultado); j++){

								                  printf("%s\t",PQgetvalue(resultado,i,j));
								               }
								             printf("\n");
								          }
								        }
								        printf("Digite el id del proveedor a Modificar\n");
							            scanf("%d",&pro);
							            __fpurge(stdin);
							            printf("Ingresa El Nuevo Nombre");
	                            		scanf("%s",nombreaux);
	                            		__fpurge(stdin);
                                        strcpy(nombreaux,conversor(nombreaux));
                                        sprintf(cad,"update proveedor set nombre='%s' where idp=%d;",nombreaux,pro);
                                        PQexec(conexion,cad);
                                        __fpurge(stdin);


	                            	break;
	                            	case 2:
	                            	__fpurge(stdin);
	                            	    if(PQstatus(conexion) != CONNECTION_BAD)
							              resultado = PQexec(conexion,"select idp,estado from proveedor;");
							              if(resultado !=NULL){

								            for(i=0; i<PQntuples(resultado); i++){

								               for(j=0; j<PQnfields(resultado); j++){

								                  printf("%s\t",PQgetvalue(resultado,i,j));
								               }
								             printf("\n");
								          }
								        }

								        printf("Digite el id del proveedor a Modificar Su Status :\n");
							            scanf("%d",&pro);
							            __fpurge(stdin);
							            printf("ingresa el nuevo status del porveedor\n");
							            status[0]=Status();
							            sprintf(cad,"update proveedor set estado='%c' where idp=%d;",status[0],pro);
									    PQexec(conexion,cad);
							            printf("Status Modificado\n");
							            break;

	                                     }

	                        
                                       }while(x!=3);
                                       __fpurge(stdin);
							           break;
						                case 4:
						 				if(PQstatus(conexion) != CONNECTION_BAD)
										  resultado = PQexec(conexion,"select * from proveedor;");

			                             if(resultado !=NULL){

									        for(i=0; i<PQntuples(resultado); i++){

									            
									        for(j=0; j<PQnfields(resultado); j++){

									            printf("%s\t",PQgetvalue(resultado,i,j));
									        }
									        printf("\n");
									      }
									    }
									 	getchar();
			                            break;

                           
						  }

			        getchar();

			        }while(x!=5);


			break;
			case 2:
			__fpurge(stdin);
			do{
		
				printf("\t....:::: PRECIO LITRO ::::....\n\n");
				printf("%cQue deseas hacer?\n\n1).- Ingresar un precio de litro.\n2).- Eliminar precio litro.\n3).- Modificar .\n4).- Imprimir\n", 168);
				printf("5).- Salir.\n\nEsperando opcion: ");
				scanf("%d", &x);
				printf("\n--------------------------------------------\n\n");
		
		        getchar();

				switch(x){
					__fpurge(stdin);
					case 1:
					printf("Ingresa valor al año: ");
					scanf("%d",&temp);
					
					
					if(temp>=2018){

						
						agno=temp;
						printf("ingrsa valor de semana\n");
						scanf("%d",&temp);
						semana=validar(temp,4);
						printf("ingresando fecha inicio\n");
						printf("ingresa agno : \t");scanf("%d",&agno);
                        	if (validar(agno,3)){}
                        printf("ingresa mes : \t");scanf("%d",&mes); 
							 if (validar(mes,2)!=0){}
						printf("ingresa dia : \t");scanf("%d",&dia);
							 if(validar(dia,1)!=0){}
						sprintf(fecha_temp,"%d-%d-%d",agno,mes,dia);
					    
					    printf("ingresando fecha fin\n");
					    printf("ingresa agno : \t");scanf("%d",&agno);
                        	if (validar(agno,3)){}
                        printf("ingresa mes : \t");scanf("%d",&mes); 
							 if (validar(mes,2)!=0){}
                        printf("ingresa dia : \t");scanf("%d",&dia);
							 if(validar(dia,1)!=0){}
						
                        
                        sprintf(fecha_temp2,"%d-%d-%d",agno,mes,dia);
					    

                        printf("ingresa el precio\n");
						scanf("%f",&precio);
						sprintf(cad,"insert into preciolitro values(%d,%d,'%s','%s',%f);",agno,semana,fecha_temp,fecha_temp2,precio);
						//printf("la cadena antes de ingresarla es :%s\n",cad);
						PQexec(conexion,cad);
						}else {
							printf("ingresa nuevamente los datos no son corectos\n");
						}
					__fpurge(stdin);
					break;
					case 2:
					__fpurge(stdin);
					printf("...::::ELIMINACION DE DATOS::::...\n");
					if(PQstatus(conexion) != CONNECTION_BAD)
							                resultado = PQexec(conexion,"select * from preciolitro;");

					                             if(resultado !=NULL){

											        for(i=0; i<PQntuples(resultado); i++){

											            
											        for(j=0; j<PQnfields(resultado); j++){

											            printf("%s\t",PQgetvalue(resultado,i,j));
											        }
											        printf("\n");
											  }
											}
					printf("ingresa el año a eliminar \n");
					scanf("%d",&agno);
					printf("tambien ingresa... el numero de semana\n");
					scanf("%d",&semana);
					sprintf(cad,"delete from preciolitro where anno=%d and semana=%d;",agno,semana);
					PQexec(conexion,cad);
					printf("rejistro eliminado\n");
					__fpurge(stdin);

					break;

					case 3:
					__fpurge(stdin);
					printf("...::::MODFICACION DE PRECIO LITRO::::...\n");
					do{
						puts(".-1 año");
						puts(".-2 semana");
						puts(".-3 fecha inicio");
						puts(".-4 fecha fin");
						puts(".-5 precio");
						puts(".-6 Regresar");
						scanf("%d",&x);
						switch(x){
							case 1:
							__fpurge(stdin);
							if(PQstatus(conexion) != CONNECTION_BAD)
							                resultado = PQexec(conexion,"select anno,semana,precio from preciolitro;");

					                             if(resultado !=NULL){

											        for(i=0; i<PQntuples(resultado); i++){

											            
											        for(j=0; j<PQnfields(resultado); j++){

											            printf("%s\t",PQgetvalue(resultado,i,j));
											        }
											        printf("\n");
											  }
											}
							printf("Ingresa el año a modificar \t");
							scanf("%d",&pro);
							printf("tambien... digita la el numero de semana\n");
							scanf("%d",&semana);
							printf("ingresa el nuevo valor del agno\n");
							scanf("%d",&agno);
							agno=validar(agno,3);
							sprintf(cad,"update preciolitro set anno=%d where anno=%d and semana=%d;",agno,pro,semana);
							PQexec(conexion,cad);
							printf("rejistro correctamente Modificado\n");
							__fpurge(stdin);
							break;
							case 2:
							__fpurge(stdin);
							if(PQstatus(conexion) != CONNECTION_BAD)
							                resultado = PQexec(conexion,"select anno,semana,precio from preciolitro;");

					                             if(resultado !=NULL){

											        for(i=0; i<PQntuples(resultado); i++){

											            
											        for(j=0; j<PQnfields(resultado); j++){

											            printf("%s\t",PQgetvalue(resultado,i,j));
											        }
											        printf("\n");
											  }
											}
							printf("Ingresa el numero de samana a modificar \t");
							scanf("%d",&pro);
							printf("tambien... digita el numero del año\n");
							scanf("%d",&agno);
							printf("ingresa el nuevo valor de la semana\n");
							scanf("%d",&semana);
							semana=(validar(semana,4));
							sprintf(cad,"update preciolitro set semana=%d where anno=%d and semana=%d;",semana,agno,pro);
							PQexec(conexion,cad);
							printf("rejistro correctamente Modificado\n");


							__fpurge(stdin);
							break;
							case 3:
							__fpurge(stdin);
							if(PQstatus(conexion) != CONNECTION_BAD)
							                resultado = PQexec(conexion,"select anno,semana,fec_ini,precio from preciolitro;");

					                             if(resultado !=NULL){

											        for(i=0; i<PQntuples(resultado); i++){

											            
											        for(j=0; j<PQnfields(resultado); j++){

											            printf("%s\t",PQgetvalue(resultado,i,j));
											        }
											        printf("\n");
											  }
											}
							printf("ingresa la fecha inicio a modificar\n");
							gets(fecha_temp);__fpurge(stdin);
							printf("%s\n",fecha_temp);
							printf("Ingresa el año \t");
							scanf("%d",&pro);
							printf("tambien... digita el numero de semana\n");
							scanf("%d",&semana);
							printf("digita la nueva fecha : ingresa año\t");
							scanf("%d",&agno);
							agno=validar(agno,3);
							printf("ingresa el mes\t");
							scanf("%d",&mes);
							mes=validar(mes,2);
							printf("ingresa el dia\t");
							scanf("%d",&dia);
							dia=validar(dia,1);
							sprintf(fecha_temp2,"%d-%d-%d",agno,mes,dia);
							sprintf(cad,"update preciolitro set fec_ini='%s' where anno=%d and semana=%d and fec_ini='%s';",fecha_temp2,pro,semana,fecha_temp);
							PQexec(conexion,cad);
							printf("rejistro correctamente Modificado\n");
							__fpurge(stdin);
							break;
							case 4:
							__fpurge(stdin);
							if(PQstatus(conexion) != CONNECTION_BAD)
							                resultado = PQexec(conexion,"select anno,semana,fec_fin,precio from preciolitro;");

					                             if(resultado !=NULL){

											        for(i=0; i<PQntuples(resultado); i++){

											            
											        for(j=0; j<PQnfields(resultado); j++){

											            printf("%s\t",PQgetvalue(resultado,i,j));
											        }
											        printf("\n");
											  }
											}
							printf("ingresa la fecha fin a modificar\n");
							gets(fecha_temp);__fpurge(stdin);
							printf("%s\n",fecha_temp);
							printf("Ingresa el año \t");
							scanf("%d",&pro);
							printf("tambien... digita el numero de semana\n");
							scanf("%d",&semana);
							printf("digita la nueva fecha : ingresa año\t");
							scanf("%d",&agno);
							agno=validar(agno,3);
							printf("ingresa el mes\t");
							scanf("%d",&mes);
							mes=validar(mes,2);
							printf("ingresa el dia\t");
							scanf("%d",&dia);
							dia=validar(dia,1);
							sprintf(fecha_temp2,"%d-%d-%d",agno,mes,dia);
							sprintf(cad,"update preciolitro set fec_fin='%s' where anno=%d and semana=%d and fec_fin='%s';",fecha_temp2,pro,semana,fecha_temp);
							PQexec(conexion,cad);
							printf("rejistro correctamente Modificado\n");
								__fpurge(stdin);
							break;
							case 5:
							__fpurge(stdin);
							if(PQstatus(conexion) != CONNECTION_BAD)
							                resultado = PQexec(conexion,"select anno,semana,precio from preciolitro;");

					                             if(resultado !=NULL){

											        for(i=0; i<PQntuples(resultado); i++){

											            
											        for(j=0; j<PQnfields(resultado); j++){

											            printf("%s\t",PQgetvalue(resultado,i,j));
											        }
											        printf("\n");
											  }
							__fpurge(stdin);				}
							printf("ingresa el precio\n");
						    scanf("%f",&precio);__fpurge(stdin);
						    sprintf(fecha_temp,"%f",precio);
						    printf("este es el precio ingresado : %s\n",fecha_temp);
                            printf("ingresa el año\t");
							scanf("%d",&agno);
							printf("tambien... digita la el numero de semana\t");
							scanf("%d",&semana);
							printf("ingresa el nuevo valor del precio\n");
							scanf("%f",&nominal2);
							//update preciolitro set precio=500.20 where anno=2019 and semana=1 and precio=200.40;
							sprintf(cad,"update preciolitro set precio=%f where anno=%d and semana=%d and precio=%s;",nominal2,agno,semana,fecha_temp);
							printf("la cadena a insertar es : %s\n",cad);
							PQexec(conexion,cad);
							printf("rejistro correctamente Modificado\n");
							__fpurge(stdin);
							break;

						}

					}while(x!=6);




					__fpurge(stdin);
					break;

					case 4:
					if(PQstatus(conexion) != CONNECTION_BAD)
							                resultado = PQexec(conexion,"select * from preciolitro;");

					                             if(resultado !=NULL){

											        for(i=0; i<PQntuples(resultado); i++){

											            
											        for(j=0; j<PQnfields(resultado); j++){

											            printf("%s\t",PQgetvalue(resultado,i,j));
											        }
											        printf("\n");
											  }
											}	

					break;


				}

	         }while(x!=5);




	  		__fpurge(stdin);
			break;
			case 3:
			__fpurge(stdin);
			do{
		
				printf("\t....:::: ENTREGA DIARIA ::::....\n\n");
				printf("%cQue deseas hacer?\n\n1).- Ingresar un entrega diaria.\n2).- Eliminar distribucion.\n3).- Modificar .\n4).- Imprimir\n", 168);
				printf("5).- Salir.\n\nEsperando opcion: ");
				scanf("%d", &x);
		        printf("\n--------------------------------------------\n\n");
		        switch(x){
		        	case 1:
		        	__fpurge(stdin);
		        	printf("ingresa agno : \t");scanf("%d",&agno);
                    agno=validar(agno,3);
                    printf("ingresa mes : \t");scanf("%d",&mes); 
					mes=validar(mes,2);
		        	printf("ingresa dia : \t");scanf("%d",&dia);
					dia=validar(dia,1);
					sprintf(fecha_temp,"%d-%d-%d",agno,mes,dia);
                    printf("%s\n",fecha_temp);
				    printf("ingresa cantidad\n");
					scanf("%d",&pro);
					pro=validar(pro,5);
					sprintf(cad,"insert into entrega_diaria(fecha,cantidad)values('%s',%d);",fecha_temp,pro);
					//printf("cadena ingresada : %s\n",cad);
					PQexec(conexion,cad);
					__fpurge(stdin);
		        	break;
		        	case 2:
		        	printf("...::::BAJAS ENTREGA DIARIA::::...\n");
		        	if(PQstatus(conexion) != CONNECTION_BAD)
							  resultado = PQexec(conexion,"select * from entrega_diaria;");
							    if(resultado !=NULL){

						            for(i=0; i<PQntuples(resultado); i++){

						               for(j=0; j<PQnfields(resultado); j++){

						                  printf("%s\t",PQgetvalue(resultado,i,j));
						               }
						             printf("\n");
						          }
						        }
							
					getchar();
					__fpurge(stdin);
					printf("Digite el id del proveedor a Eliminar\n");
					scanf("%d",&pro);
				    sprintf(cad,"delete from entrega_diaria where idp=%d;",pro);
					PQexec(conexion, cad);
				    printf("rejistro eliminado\n");
                    break;
                    case 3:
                    __fpurge(stdin);

							do{
								printf("..::::MODIFICACION DE ENTREGA DIARIA::::..\n");
								puts("1-. fecha");
	                            puts("2-. cantidad");
	                            puts("3-. Regresar");
	                            scanf("%d",&opc);
	                            switch(opc){
	                            	case 1:
	                            	__fpurge(stdin);
	                            	    if(PQstatus(conexion) != CONNECTION_BAD)
							              resultado = PQexec(conexion,"select idp,fecha from entrega_diaria;");
							              if(resultado !=NULL){

								            for(i=0; i<PQntuples(resultado); i++){

								               for(j=0; j<PQnfields(resultado); j++){

								                  printf("%s\t",PQgetvalue(resultado,i,j));
								               }
								             printf("\n");
								          }
								        }
								    printf("Digite el id del proveedor a Modificar\n");
							        scanf("%d",&pro);
							        __fpurge(stdin);
							        printf("Ingresa la nueva fecha");
							        printf("ingresa agno : \t");scanf("%d",&agno);
					                agno=validar(agno,3);
					                printf("ingresa mes : \t");scanf("%d",&mes); 
								    mes=validar(mes,2);
							        printf("ingresa dia : \t");scanf("%d",&dia);
									dia=validar(dia,1);
									sprintf(fecha_temp,"%d-%d-%d",agno,mes,dia);
					                printf("%s\n",fecha_temp);
					                sprintf(cad,"update entrega_diaria set fecha='%s' where idp=%d;",fecha_temp,pro);
                                    PQexec(conexion,cad);
                                     __fpurge(stdin);
                                     break;
	                            	case 2:
	                            	__fpurge(stdin);
	                            	    if(PQstatus(conexion) != CONNECTION_BAD)
							              resultado = PQexec(conexion,"select idp,cantidad from entrega_diaria;");
							              if(resultado !=NULL){

								            for(i=0; i<PQntuples(resultado); i++){

								               for(j=0; j<PQnfields(resultado); j++){

								                  printf("%s\t",PQgetvalue(resultado,i,j));
								               }
								             printf("\n");
								          }
								        }

								        printf("Digite el id del proveedor:\n");
							            scanf("%d",&pro);
							            __fpurge(stdin);
							            printf("ingresa la nueva cantidad\n");
							            scanf("%d",&temp);
							            temp=validar(temp,5);
							            sprintf(cad,"update entrega_diaria set cantidad='%d' where idp=%d;",temp,pro);
									    PQexec(conexion,cad);
							            printf("Status Modificado\n");
							            break;

	                                     }

	                        
                                       }while(x!=3);
                                       __fpurge(stdin);

                    break;
		        	case 4:
		        	if(PQstatus(conexion) != CONNECTION_BAD)
					    resultado = PQexec(conexion,"select * from entrega_diaria;");

					    if(resultado !=NULL){

		                      for(i=0; i<PQntuples(resultado); i++){

												            
				                for(j=0; j<PQnfields(resultado); j++){

								    printf("%s\t",PQgetvalue(resultado,i,j));
								}
							  printf("\n");
						    }
			            }
                    break;

		        }
		    }while(x!=5);
			__fpurge(stdin);
			break;
			case 4:
			do{
			__fpurge(stdin);
			printf("\t....::::PAGO SEMANAL::::....\n\n");
			printf("Que deseas hacer?\n\n1).- Ingresar pago semanal.\n2).- Eliminar pago semanal.\n3).- Modificar .\n4).- Imprimir\n");
			printf("5).- Salir.\n\nEsperando opcion: ");
			scanf("%d",&x);__fpurge(stdin);
			switch(x){
				case 1:
				printf("Ingresa el id del proveedor: ");
					scanf("%d",&pro);
					if(pro!=0){
						printf("ingresa el año\n");
						scanf("%d",&agno);
						agno=validar(agno,3);
						printf("ingrsa valor de semana\n");
						scanf("%d",&temp);
						temp=validar(temp,4);
						printf("ingresa el importe\n");
						scanf("%f",&precio);
						 while(precio==0.0){
						 	printf("ingresa un importe correcto\n");
						 	scanf("%f",&precio);
						  }
						printf("ingresa cantidad\n");
						scanf("%d",&opc);
						opc=validar(opc,5);
						sprintf(cad,"insert into pago_semanal values(%d,%d,%d,%f,%d);",pro,agno,temp,precio,opc);
						PQexec(conexion,cad);
 						printf("datos corectamente ingresados\n");
					}
					else{

					printf("El valor que ingreasastes no es correcto\n");
				    }	
				break;
				case 2:
				__fpurge(stdin);
				printf("..::::BAJAS DE PAGO SEMANAL::::..\n");
				if(PQstatus(conexion) != CONNECTION_BAD)
					resultado = PQexec(conexion,"select idp,anno,semana from pago_semanal;");
					if(resultado !=NULL){

					    for(i=0; i<PQntuples(resultado); i++){

						    for(j=0; j<PQnfields(resultado); j++){

						    printf("%s\t",PQgetvalue(resultado,i,j));
						    }
					      printf("\n");
						}
				    }
							
				getchar();
		        __fpurge(stdin);
			    printf("Digite el id del proveedor a Eliminar\n");
				scanf("%d",&pro);
				printf("digia la semana \t");
				scanf("%d",&semana);
				printf("tammbien..digita el año\n");
				scanf("%d",&agno);
                sprintf(cad,"delete from pago_semanal where idp=%d and anno=%d and semana=%d;",pro,agno,semana);
				PQexec(conexion,cad);
				printf("usuario eliminado\n");
				break;
				case 3:
				__fpurge(stdin);
				do{
				printf("..::::MODIFICACION DE PAGO SEMANAL:::..\n");
				puts("1-. año");
	            puts("2-. semana");
	            puts("3-. importe");
	            puts("4-. cantidad");
	            puts("5-. Regresar");
	            scanf("%d",&opc);
		            switch(opc){
				        	case 1:
				        	__fpurge(stdin);
				        	    if(PQstatus(conexion) != CONNECTION_BAD)
					              resultado = PQexec(conexion,"select idp,anno,semana from pago_semanal;");
					              if(resultado !=NULL){

						            for(i=0; i<PQntuples(resultado); i++){

						               for(j=0; j<PQnfields(resultado); j++){

						                  printf("%s\t",PQgetvalue(resultado,i,j));
						               }
						             printf("\n");
						          }
						        }
						    printf("Digite el id del proveedor a modificar\n");
							scanf("%d",&pro);
							printf("tammbien..digita el año\n");
							scanf("%d",&agno);
							printf("digia la semana \t");
							scanf("%d",&semana);
							printf("digita el nuevo año \n");
							scanf("%d",&opc);
							opc=validar(opc,3);
							sprintf(cad,"update pago_semanal set anno=%d where idp=%d and anno=%d and semana=%d;",opc,pro,agno,semana);
		                    PQexec(conexion,cad);
				            printf("datos correctamente Modificado\n");
				            __fpurge(stdin);
				            break;
				        	case 2:
				        	__fpurge(stdin);
				        	    if(PQstatus(conexion) != CONNECTION_BAD)
					              resultado = PQexec(conexion,"select idp,anno,semana from pago_semanal;");
					              if(resultado !=NULL){

						            for(i=0; i<PQntuples(resultado); i++){

						               for(j=0; j<PQnfields(resultado); j++){

						                  printf("%s\t",PQgetvalue(resultado,i,j));
						               }
						             printf("\n");
						          }
						        }
						    printf("Digite el id del proveedor a modificar\n");
							scanf("%d",&pro);
							printf("tammbien..digita el año\n");
							scanf("%d",&agno);
							printf("digia la semana \t");
							scanf("%d",&semana);
							printf("digita el valor de la nueva semana \n");
							scanf("%d",&temp);
							temp=validar(temp,4);__fpurge(stdin);
							sprintf(cad,"update pago_semanal set cantidad=%d where idp=%d and anno=%d and semana=%d;",temp,pro,agno,semana);
							printf("cadena ingresada : %s\n",cad);
		                    PQexec(conexion,cad);
				            printf("datos correctamente Modificado\n");
				            __fpurge(stdin);
				        	 break;
				        	case 3:
				        	__fpurge(stdin);
							if(PQstatus(conexion) != CONNECTION_BAD)
							                resultado = PQexec(conexion,"select anno,semana,importe from pago_semanal;");

					                             if(resultado !=NULL){

											        for(i=0; i<PQntuples(resultado); i++){

											            
											        for(j=0; j<PQnfields(resultado); j++){

											            printf("%s\t",PQgetvalue(resultado,i,j));
											        }
											        printf("\n");
											  }
							__fpurge(stdin);				}
							printf("ingresa el precio\n");
						    scanf("%f",&precio);__fpurge(stdin);
						    sprintf(fecha_temp,"%f",precio);
						    printf("ingresa el año\t");
							scanf("%d",&agno);
							printf("tambien... digita la el numero de semana\t");
							scanf("%d",&semana);
							printf("ingresa el nuevo valor del importe\n");
							scanf("%f",&nominal2);
							sprintf(cad,"update pago_semanal set importe=%f where anno=%d and semana=%d and importe=%s;",nominal2,agno,semana,fecha_temp);
							printf("la cadena a insertar es : %s\n",cad);
							PQexec(conexion,cad);
							printf("rejistro correctamente Modificado\n");
							__fpurge(stdin);
				        	break;
				        	case 4:
				        	__fpurge(stdin);
	                            	    if(PQstatus(conexion) != CONNECTION_BAD)
							              resultado = PQexec(conexion,"select idp,anno,semana,cantidad from pago_semanal;");
							              if(resultado !=NULL){

								            for(i=0; i<PQntuples(resultado); i++){

								               for(j=0; j<PQnfields(resultado); j++){

								                  printf("%s\t",PQgetvalue(resultado,i,j));
								               }
								             printf("\n");
								          }
								        }

					        printf("Digite el id del proveedor:\n");
				            scanf("%d",&pro);
				            printf("digita\n");
				            printf("ingresa el año\t");
							scanf("%d",&agno);
							printf("tambien... digita  el numero de semana\t");
							scanf("%d",&semana);
							printf("ingresa la nueva cantidad\n");
				            scanf("%d",&temp);
				            temp=validar(temp,5);
				            sprintf(cad,"update pago_semanal set cantidad=%d where idp=%d and anno=%d and semana=%d;",temp,pro,agno,semana);
				            printf("la cadena ingresada es :%s\n",cad);
						    PQexec(conexion,cad);
				            printf("Status Modificado\n");
				            __fpurge(stdin);
				        	break;
				        	__fpurge(stdin);

		            }

	    
	            }while(opc!=5);
	             __fpurge(stdin);
				break;
				case 4:
				if(PQstatus(conexion) != CONNECTION_BAD)
										  resultado = PQexec(conexion,"select * from pago_semanal;");

			                             if(resultado !=NULL){

									        for(i=0; i<PQntuples(resultado); i++){

									            
									        for(j=0; j<PQnfields(resultado); j++){

									            printf("%s\t",PQgetvalue(resultado,i,j));
									        }
									        printf("\n");
									      }
									    }
				getchar();
				break;

			 }
			}while(x!=5);
			__fpurge(stdin);
            break;
		    case 5:
                           __fpurge(stdin);
                           			do{

										printf("\t....:::: deniminacion ::::....\n\n");
										printf("Que deseas hacer?\n\n1).- Ingresar datos denominacion.\n2).-eliminar datos denominacion.\n3) modificar . \n4).-Imprimir\n");
										printf("5).- Salir.\n\nEsperando opcion: ");
										scanf("%d", &x);
										printf("\n--------------------------------------------\n\n");
										switch(x){
											case 1:
												
												printf("ingresa denominacion\n");
						                        scanf("%f",&nominal);
						                        sprintf(cad,"insert into denominacion(nominal)values('%f');",nominal);
						                        PQexec(conexion,cad);
						                        printf("inserccion correctamente\n");


											break;

											case 2:
											if(PQstatus(conexion) != CONNECTION_BAD)
							                resultado = PQexec(conexion,"select * from denominacion;");

					                             if(resultado !=NULL){

											        for(i=0; i<PQntuples(resultado); i++){

											            
											        for(j=0; j<PQnfields(resultado); j++){

											            printf("%s\t",PQgetvalue(resultado,i,j));
											        }
											        printf("\n");
											  }
											}	

											printf("ingresa el id de deniminacion a borrar\n");
											scanf("%d",&pro);
											sprintf(cad,"delete from denominacion where idd=%d;",pro);
											PQexec(conexion,cad);


											break;
											case  3:
											__fpurge(stdin);
											if(PQstatus(conexion) != CONNECTION_BAD)
							                resultado = PQexec(conexion,"select * from denominacion;");

					                             if(resultado !=NULL){

											        for(i=0; i<PQntuples(resultado); i++){

											            
											        for(j=0; j<PQnfields(resultado); j++){

											            printf("%s\t",PQgetvalue(resultado,i,j));
											        }
											        printf("\n");
											  }
											}	

											printf("ingresa el id de deniminacion para modificar\n");
											scanf("%d",&pro);
											printf("ingresa el nuevo valor nominal\n");
											scanf("%f",&nominal);
											sprintf(cad,"update denominacion set nominal='%f' where idd=%d;",nominal,pro);
											PQexec(conexion,cad);
											__fpurge(stdin);
											break;
											case 4:   
											printf("...::::INPRESION DE DATOS::::...\n");
											if(PQstatus(conexion) != CONNECTION_BAD)
							                resultado = PQexec(conexion,"select * from denominacion;");

					                             if(resultado !=NULL){

											        for(i=0; i<PQntuples(resultado); i++){

											            
											        for(j=0; j<PQnfields(resultado); j++){

											            printf("%s\t",PQgetvalue(resultado,i,j));
											        }
											        printf("\n");
											  }
											}	

                                        break;

										}

                           			}while(x!=5);
                           			__fpurge(stdin);
                           break;
            case 6:
            __fpurge(stdin);
            printf("\n\n");
            do{
            	printf("\t....::::DISTRUBUCION::::....\n\n");
				printf("Que deseas hacer?\n\n1).- Ingresar datos de distribucion.\n2).- Eliminar datos distribucion.\n3).- Imprimir\n");
				printf("4).- Salir.\n\nEsperando opcion: ");
				scanf("%d", &x);
				switch(x){
					case 1:
				    printf("Ingresa el id del proveedor: ");
					scanf("%d",&pro);
					if(pro!=0){
						printf("ingresa el año\n");
						scanf("%d",&agno);
						agno=validar(agno,3);
						printf("ingrsa valor de semana\n");
						scanf("%d",&temp);
						temp=validar(temp,4);
						printf("ingresa el id de distribucion\n");
						scanf("%d",&mes);
						mes=validar(mes,5);
						printf("ingresa cantidad\n");
						scanf("%d",&opc);
						opc=validar(opc,5);
						sprintf(cad,"insert into distribucion values(%d,%d,%d,%d,%d);",pro,agno,temp,mes,opc);
						printf("la caden ingresada es %s\n",cad);
						PQexec(conexion,cad);
 						printf("datos corectamente ingresados\n");
					}
					else{

					printf("El valor que ingreasastes no es correcto\n");
				    }	
				   break;
				   case 2:
				   __fpurge(stdin);
				   printf("..::::BAJAS DE PAGO SEMANAL::::..\n");
				   if(PQstatus(conexion) != CONNECTION_BAD)
						resultado = PQexec(conexion,"select idp,idd,anno from distribucion;");
				   if(resultado !=NULL){

					    for(i=0; i<PQntuples(resultado); i++){

						    for(j=0; j<PQnfields(resultado); j++){

						    printf("%s\t",PQgetvalue(resultado,i,j));
						    }
					      printf("\n");
						}
				    }
							
					getchar();
			        __fpurge(stdin);
			       printf("Digite el id del proveedor a Eliminar\n");
				   scanf("%d",&pro);
				   printf("digia el id de denominacion \t");
				   scanf("%d",&semana);
				   printf("tammbien..digita el año\n");
				   scanf("%d",&agno);
                   sprintf(cad,"delete from  distribucion where idp=%d and idd=%d and anno=%d;",pro,semana,agno);
				   PQexec(conexion,cad);
				   printf("usuario eliminado\n");
				   break;
				   
				   case 3:
				   if(PQstatus(conexion) != CONNECTION_BAD)
					    resultado = PQexec(conexion,"select * from distribucion;");

			                if(resultado !=NULL){

							    for(i=0; i<PQntuples(resultado); i++){

									            
								  for(j=0; j<PQnfields(resultado); j++){

									 printf("%s\t",PQgetvalue(resultado,i,j));
								  }
							    printf("\n");
							}
					}
				getchar();
				break;

				}
		    }while(x!=4);
		    __fpurge(stdin);
            break;

                           


		  }

		getchar();

	}while(x!=7);



	return 0;
}





char Status(){
	int d;
	printf("\nEstatus:\n\n1).- Activo\n2).- Inactivo\n\nEsperando una opcion: ");
	scanf("%d",&d);

	if(d==1)
		return 'A';
	else
		return 'I';
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
int validar(int valor,int opcion){
	
	switch(opcion){
		case 1: 
		          while(valor==0 || valor>31){
	 	
					 printf("ingresa un dia comprendido entre 1 - 31 por favor\n");
					 scanf("%d",&valor);
	              }  

		break;
		case 2:   
		          while(valor==0 || valor>12){
	 	
				 	printf("ingresa un mes corectamente\n");
				 	scanf("%d",&valor);
	              }

		break;
		case 3:  
				  while(valor<2018){    
				    printf(" ingresa un año que este del 2018 en adelante \n");
				    scanf("%d",&valor);
				           			
				  }

		break;
		case 4:
				  while(valor==0||valor>52){
					printf("introduce una semana correctamente\n");
					scanf("%d",&valor);

					}
		break;
		case 5:   while(valor==0) {
					printf("introduce un valor correcto\n");
					scanf("%d",&valor);
	           	   }
		break;

	}

	return valor;

}
#include <stdlib.h>
#include <libpq-fe.h>
#include <stdio.h>

PGconn *conexion = NULL;
PGresult *resultado = NULL;

char *host = "localhost";
char *puer = "5432";
char *database = "queseria";
char *user = "postgres";
char *password = "fredy1234";


int conectar(){
	conexion = PQsetdbLogin(host,puer,NULL,NULL,database,user,password);
	printf("exito\n");
}
