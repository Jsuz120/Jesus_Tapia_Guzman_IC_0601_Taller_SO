#ifndef __BANK_H
#define __BANK_H

#include<stdlib.h>
#include<string.h>

#include"menu.h"
#include"structuras.h"



void menuActualizar(){
	printf("\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	printf("\n\t\t$$$$ Menu Actualizar $$$$\n");
    printf("\t\t 1 Mostrar menu.\n");
    printf("\t\t 2 Actualizar Nombre.\n");
    printf("\t\t 3 Actualizar Sexo.\n");
    printf("\t\t 4 Regresar a menu principal.\n");
    printf("\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
	
	
}



void bnk(){

	int i,j,cont;
	char pais[50];
	printf("Porfavor, introduce el numero de paises: ");
	scanf("%i",&NumPaises);
	
	for(i = 0; i < NumPaises; i++){
		fflush(stdin);
		printf("\nCual es el nombre del pais? %i: ",i);
		gets(Pais[i].pais);

		printf("\n Introduce el numero de clientes %i:",i);
		scanf("%i",&Pais[i].clientes);





}


for(i=0;i<NumPaises;i++){
		printf("\nDel pais  %s, existen %i clientes.\n ",Pais[i].pais,Pais[i].clientes);
	}

	menu();
	int op,opcionesAc;
	printf("\nSelecciona una opcion: ");
	scanf("%i",&op);
	while(op != 15){
		switch(op){
			case 1:menu();
				break;
			case 2:
				printf("\n +++ ALTA +++\n");
				printf("++++++++++++++++++++\n");
				printf("\nPor favor, introduzca el nombre del pais: ");
				fflush(stdin);
				gets(pais);
				for(i=0;i<NumPaises;i++){
					if(strcmp(pais,Pais[i].pais)==0){
						for(j=0;j<Pais[i].clientes;j++){
							if(Pais[i].alta[j].ocupado!=true){
								printf("\nPor favor, introduzca el nombre del cliente: ");
								gets(Pais[i].alta[j].nombre);
								printf("\nPor favor, introduzca el sexo F/M: ");
								scanf("%c",&Pais[i].alta[j].sexo);
								printf("\nPor favor, introduzca el sueldo: ");
								scanf("%d",&Pais[i].alta[j].sueldo);
								Pais[i].alta[j].id=j;
								Pais[i].alta[j].ocupado=true;
								break;
							}
						}
					}
				}
				break;



			case 3:
				printf("\n +++ OPCION BAJA +++");
				printf("++++++++++++++++++++\n");
				fflush(stdin);
				printf("\nPor favor, introduzca el nombre del pais:  ");
				gets(pais);
				int cliente;
				for(i=0;i<NumPaises;i++){
					if(strcmp(pais,Pais[i].pais)==0){
						printf("\nPor favor, introduzca el ID del cliente:  ");
						scanf("%i",&cliente);
						for(j=0;j<Pais[i].clientes;j++){
							if (cliente==Pais[i].alta[j].id){
							printf("\nEl cliente %s con el ID %i ha sido dado de baja.",Pais[i].alta[j].nombre,Pais[i].alta[j].id);
							int k;
							int x = sizeof(Pais[i].alta[j].nombre)/sizeof(*Pais[i].alta[j].nombre);
							for(k=0;k<x;k++){
								Pais[i].alta[j].nombre[k]='\0';
							}
							Pais[i].alta[j].sexo=' ';
							Pais[i].alta[j].sueldo=0;
							Pais[i].alta[j].ocupado=false;
							}
						}
					}
				}
				break;



			case 4:
			
				printf("\n +++ OPCION MOSTRAR TODO +++");
				printf("+++++++++++++++++++++++++++\n");
				for(i=0;i<NumPaises;i++){
					printf("\t\nPAIS %s",Pais[i].pais);
			        for(j= 0; j< Pais[i].clientes; j++){
			            printf("\n\tEL CLIENTE %i ES: ",Pais[i].alta[j].id);
			            printf("\n\t\tNOMBRE: %s \tSEXO: %c \t SALDO: %d \t%s\n",Pais[i].alta[j].nombre, 
						Pais[i].alta[j].sexo, Pais[i].alta[j].sueldo, Pais[i].alta[j].ocupado?"true":"false");
			        }
				}
				break;



			case 5:
				printf("\n +++ MOSTRAR CLIENTE EN ESPECIFICO +++");
				printf("++++++++++++++++++++++++++++++++++++++\n");
				fflush(stdin);
				printf("\nPor favor, introduzca el nombre del pais: ");
				gets(pais);
				cliente=0;
				for(i=0;i<NumPaises;i++){
					if(strcmp(pais,Pais[i].pais)==0){
						printf("\nIntroduce el id del cliente: ");
						scanf("%i",&cliente);
						for(j=0;j<Pais[i].clientes;j++){
							if (cliente==Pais[i].alta[j].id){
							printf("\n\tEl cliente %i es: ",Pais[i].alta[j].id);
			            	printf("\n\t\tNombre: %s \tSexo: %c \t Saldo: %d \tOcupado: %s\n",Pais[i].alta[j].nombre, 
							Pais[i].alta[j].sexo, Pais[i].alta[j].sueldo, Pais[i].alta[j].ocupado?"true":"false");
							}
						}
					}
				}
				break;



			case 6:
				printf("\n +++ CLIENTES DADOS DE ALTA +++");
				printf("+++++++++++++++++++++++++++++++\n");
				fflush(stdin);
				cliente=0;
				for(i=0;i<NumPaises;i++){
					for(j=0;j<Pais[i].clientes;j++){
						if (true==Pais[i].alta[j].ocupado){
							printf("\t\nPAIS %s",Pais[i].pais);
							printf("\n\tEL CLIENTE %i es: ",Pais[i].alta[j].id);
			            	printf("\n\t\tNOMBRE: %s \tSEXO: %c \t SALDO: %d \t%s\n",Pais[i].alta[j].nombre, 
							Pais[i].alta[j].sexo, Pais[i].alta[j].sueldo, Pais[i].alta[j].ocupado?"true":"false");
						}
					}
				}	
				
				break;



			case 7:
				printf("\n\n +++ ABONAR +++");
				printf("++++++++++++++++++++\n");
				fflush(stdin);
				printf("\nPor favor, introduzca el nombre del pais: ");
				gets(pais);
				cliente=0;
				Abonar=0;
				for(i=0;i<NumPaises;i++){
					if(strcmp(pais,Pais[i].pais)==0){
						printf("\nIntroduzca el ID del cliente: ");
						scanf("%i",&cliente);
						for(j=0;j<Pais[i].clientes;j++){
							if (cliente==Pais[i].alta[j].id){
							printf("\n\tIngrese la cantidad que desea abonar: ");
							scanf("%d",&Abonar);
							Pais[i].alta[j].sueldo = Pais[i].alta[j].sueldo + Abonar;
							}
						}
					}
				} 
				break;



			case 8:
				printf("\n\n +++ RETIRAR +++");
				printf("++++++++++++++++++++\n");
				fflush(stdin);
				printf("\n\tPor favor, introduzca el nombre del pais: ");
				gets(pais);
				cliente=0;
				Abonar=0;
				for(i=0;i<NumPaises;i++){
					if(strcmp(pais,Pais[i].pais)==0){
						printf("\n\tIntroduzca el ID del cliente: ");
						scanf("%i",&cliente);
						for(j=0;j<Pais[i].clientes;j++){
							if (cliente==Pais[i].alta[j].id){
							printf("\n\t\tIntroduzca la cantidad que desea retirar: ");
							scanf("%d",&Abonar);
							if(Abonar<=Pais[i].alta[j].sueldo){
								Pais[i].alta[j].sueldo = Pais[i].alta[j].sueldo - Abonar;
							}else{
								printf("\n\t\tCuidado!!!, El saldo es insuficiente para retirar %d. \n",Abonar);
							}
							}
						}
					}
				}
				break;
			case 9:
				
				printf("\n\n +++BUSCAR INDICE VAVIO EN TODA LA ESTRUCTURA+++\n");
				printf("++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
				for(i=0;i<NumPaises;i++){
					for(j=0;j<Pais[i].clientes;j++){
						if(false==Pais[i].alta[j].ocupado){
							printf("\t\nPAIS %s CONTIENE AL CLIENTE [%i] VACIO.",Pais[i].pais,Pais[i].alta[j].id);
						}

					}
				}
				break;



			case 10:				
				cont=0;
				lleno=false;
				printf("\n +++ MOSTRAR SI LA ESTRUCTURA ESTA LLENA +++\n");
				printf("++++++++++++++++++++++++++++++++++++++++++++++\n");
				for(i=0;i<NumPaises;i++){
					for(j=0;j<Pais[i].clientes;j++){
						if(Pais[i].alta[j].ocupado==true){
							cont++;
						}
					}
					if(Lleno==cont){
						lleno=true;
					}
				}
				if(lleno==true){
					printf("\n\tEstructura llena.\n");
				}else{
					printf("\n\tEstructura sin elementos..\n");
				}
				break;




			case 11:
				printf("\n +++ MOSTRAR SI LA ESTRUCTURA ESTA VACIA +++\n");
				printf("++++++++++++++++++++++++++++++++++++++++++++++\n");
				cont=0;
				lleno=false;
				for(i=0;i<NumPaises;i++){
					for(j=0;j<Pais[i].clientes;j++){
						if(Pais[i].alta[j].ocupado==false){
							cont++;
						}
					}
					if(Lleno==cont){
						lleno=true;
					}
				}
				if(lleno==true){
					printf("\n\tEstructura vacia.\n");
				}else{
					printf("\n\tEstructura con elementos.\n");
				}
				
				break;



			case 12:
				printf(" +++MOSTRAR EL NOMBRE DE LOS PAISES+++");
				printf("++++++++++++++++++++++++++++++++++++++");
				for(i=0;i<NumPaises;i++){
				printf("\n\tPAIS [%i] %s.",NPais[i],Pais[i].pais);
				}
				break;



			case 13:
				printf(" +++MOSTRAR LONGITUDES+++\n");
				printf("++++++++++++++++++++++++++++");
				for(i=0;i<NumPaises;i++){
					printf("\n\tDEL PAIS  %s, EXISTEN %i CLIENTES.\n ",Pais[i].pais,Pais[i].clientes);
				}
				printf("\n");


				break;



			case 14:
				printf("\n +++ACTUALIZAR CLIENTE ESPECIFICO+++");
				printf("++++++++++++++++++++++++++++++++++++++");
				fflush(stdin);
				printf("\n\tPor favor, introduzca el nombre del pais: ");
				gets(pais);
				cliente=0;
				for(i=0;i<NumPaises;i++){
					if(strcmp(pais,Pais[i].pais)==0){
						printf("\n\tPor favor, introduzca el ID del cliente: ");
						scanf("%i",&cliente);
						for(j=0;j<Pais[i].clientes;j++){
							int option;
							if(cliente==Pais[i].alta[j].id){
								menuActualizar();
								printf("\n\t\tSelecciona una opcion: ");
								fflush(stdin);
								scanf("%i",&option);
								while(option !=4){
									switch(option){
										case 1:
											menuActualizar();
											break;
										case 2:
											printf("\n\t\t\tIntroduzca el nombre del cliente: ");
											fflush(stdin);
											gets(Pais[i].alta[j].nombre);
											break;
										case 3:
											printf("\n\t\t\tIntroduzca el sexo del cliente F/M: ");
											fflush(stdin);
											scanf("%c",&Pais[i].alta[j].sexo);
											break;
										case 4:
											break;
									}
									printf("\n\t\tSelecciona una opcion: ");
									scanf("%i",&option);
								}
							}
						}
					}
				}
				break;



			case 15:printf("\nGRACIAS POR VISITAR JZS-BANCK! ");
				break;
		}
		printf("\nSelecciona una opcion: ");
		scanf("%i",&op);
	}
	
}
#endif
