#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define TAM 30

int NumPaises;
bool ocup=false;
double Abonar;

struct ALTA{
	char nombre[TAM];
	char sexo;
	double sueldo;
	int id;
	bool ocupado;
}ALTA[TAM];
struct Pais{
	
	char pais[20];
	int clientes;
	struct ALTA alta[TAM];
}Pais[TAM];

void menu(){
        printf("\n$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
        printf("$$$$$$ Menu $$$$$$$$$$$$$$$$$$\n");
        printf(" 1) Mostrar menu.\n");
        printf(" 2) Dar de alta Cliente.\n");
        printf(" 3) Dar de baja Cliente.\n");
        printf(" 4) Mostrar todos los clientes.\n");
        printf(" 5) Mostrar cliente en especifico.\n");
        printf(" 6) Mostrar solo clientes dados de alta.\n");
        printf(" 7) Abonar saldo a cliente.\n");
        printf(" 8) Retirar saldo de cliente.\n");
        printf(" 9) Buscar indice vacio en toda la estructura.\n");
        printf(" 10) Mostrar si esta toda llena la estructura.\n");
        printf(" 11) Mostrar si esta toda vacia la estructura.\n");
        printf(" 12) Mostrar nombre de paises.\n");
        printf(" 13) Mostrar longitudes.\n");
        printf(" 14) Actualizar datos de cliente especifico.\n");
        printf(" 15) Salir.\n");
        printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
}
void menuActualizar(){
	printf("\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	printf("\n\t\t$$$$ Menu Actualizar $$$$\n");
    printf("\t\t 1 Mostrar menu.\n");
    printf("\t\t 2 Actualizar Nombre.\n");
    printf("\t\t 3 Actualizar Sexo.\n");
    printf("\t\t 4 Regresar a menu principal.\n");
    printf("\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
	
	
}
void darAlta(){
	char pais[50];
	int i,j;
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
	
}
void darBaja(){
	int i,j;
	char pais[50];
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
	
}
void mostrarTodo(){
	int i,j;
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
	
}
void mostrarClenteEspecifico(){
	int i,j,cliente;
	char pais[50];
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
	
}
void mostrarDadosDeAlta(){
	int i,j,cliente;
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
}
void abonarSaldoCliente(){
	int i,j,cliente;
	char pais[50];
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
}
void retirarSaldoCliente(){
	printf("\n\n +++ RETIRAR +++");
	printf("++++++++++++++++++++\n");
		int i,j,cliente;
		char pais[50];
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
}
void indiceVacioEnLaEstructura(){
	int i,j;
		printf("\n\n +++BUSCAR INDICE VAVIO EN TODA LA ESTRUCTURA+++\n");
		printf("++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
				for(i=0;i<NumPaises;i++){
					for(j=0;j<Pais[i].clientes;j++){
						if(false==Pais[i].alta[j].ocupado){
							printf("\t\nPAIS %s CONTIENE AL CLIENTE [%i] VACIO.",Pais[i].pais,Pais[i].alta[j].id);
						}

					}
				}
}
void mostrarEstructuraLlena(){
				bool lleno=false;
				int cont,LLENO,i,j;				
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
					if(LLENO==cont){
						lleno=true;
					}
				}
				if(lleno==true){
					printf("\n\tEstructura llena.\n");
				}else{
					printf("\n\tEstructura sin elementos..\n");
				}
	
}
void mostrarEstructuraVacia(){
	printf("\n +++ MOSTRAR SI LA ESTRUCTURA ESTA VACIA +++\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++\n");
				int cont,i,j,LLENO;
				bool lleno=false;
				cont=0;
				lleno=false;
				for(i=0;i<NumPaises;i++){
					for(j=0;j<Pais[i].clientes;j++){
						if(Pais[i].alta[j].ocupado==false){
							cont++;
						}
					}
					if(LLENO==cont){
						lleno=true;
					}
				}
				if(lleno==true){
					printf("\n\tEstructura vacia.\n");
				}else{
					printf("\n\tEstructura con elementos.\n");
				}
}
void mostrarNombrePaises(){
	printf(" +++MOSTRAR EL NOMBRE DE LOS PAISES+++");
	printf("++++++++++++++++++++++++++++++++++++++");
	int i;
	char NPais[TAM];
	for(i=0;i<NumPaises;i++){
	printf("\n\tPAIS [%i] %s.",NPais[i],Pais[i].pais);
	}		
}
void mostrarLongitudes(){
	printf(" +++MOSTRAR LONGITUDES+++\n");
	printf("++++++++++++++++++++++++++++");
	int i;
	for(i=0;i<NumPaises;i++){
	printf("\n\tDEL PAIS  %s, EXISTEN %i CLIENTES.\n ",Pais[i].pais,Pais[i].clientes);
	}
	printf("\n");
}
void actualizarDatosClienteEspecifico(){
	int i,j,cliente;
	char pais[50];
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
								printf("\n\t\tSelecciona una opción: ");
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
									printf("\n\t\tSelecciona una opción: ");
									scanf("%i",&option);
								}
							}
						}
					}
				}
	
}


int main(){
	
	int i,j;
	printf("Porfavor, introduce el numero de paises: ");
	scanf("%i",&NumPaises);
	
	for(i = 0; i < NumPaises; i++){
		fflush(stdin);
		printf("¿Cual es el nombre del pais? %i: ",i);
		gets(Pais[i].pais);

		printf("Introduce el numero de clientes %i:",i);
		scanf("%i",&Pais[i].clientes);
    }
	
	for(i=0;i<NumPaises;i++){
		printf("\nDel pais  %s, existen %i clientes.\n ",Pais[i].pais,Pais[i].clientes);
	}
	menu();
	
	int op;
	printf("\nSelecciona una opcion: ");
	scanf("%i",&op);
	while(op != 15){
		switch(op){
			case 1:menu();
				break;
			case 2:darAlta();
				break;
			case 3:darBaja();
				break;
			case 4:mostrarTodo();
				break;
			case 5:mostrarClenteEspecifico();
				break;
			case 6:mostrarDadosDeAlta();
				break;
			case 7:abonarSaldoCliente();
				break;
			case 8:retirarSaldoCliente();
				break;
			case 9:indiceVacioEnLaEstructura();
				break;
			case 10:mostrarEstructuraLlena();
				break;
			case 11:mostrarEstructuraVacia();
				break;
			case 12:mostrarNombrePaises();
				break;
			case 13:mostrarLongitudes();
				break;
			case 14:actualizarDatosClienteEspecifico();
				break;
			case 15:printf("¡GRACIAS POR VISITAR JZS-BANCK! ")
				break;
		}
		printf("\nSelecciona una opcion: ");
		scanf("%i",&op);
	}
	
	
	
	
	return 0;
}
