// CABECERA
#include "head.h"

int main(int argc, char const *argv[]) {
	
	if (argc < 3){
		printf("\t******************************************************\n");
		printf("\t////////NO HAZ DETERMINADO LA IP Y  EL PUERTO ////////\n");
		printf("\t******************************************************\n");
		return -1;
	}
	//PARAMETRO PARA ALMACENAR EL PUERTO
	int puerto = atoi(argv[2]);

	int servidor = 0, VLEER;
    	struct sockaddr_in serv_addr;
    	char buffer[1024] = {0};

	//CREMOS EL SOCKET
    	if ((servidor = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        	printf("\t***********************************************\n");
		printf("\t//////// NO SE PUEDE ABRIR EL SOCKET ////////\n");
		printf("\t***********************************************\n");
		return -1;

		}else{

		printf("\t***********************************************\n");
		printf("\t//////// SOCKET ABIERTO////////\n");
		printf("\t***********************************************\n");

}	
	//CONFIGURAMOS EL SOQUET CLIENTE
    	serv_addr.sin_family = AF_INET; //TCP/IP
    	serv_addr.sin_port = puerto;// DETERMINAMOS EL PUERTO
    	serv_addr.sin_addr.s_addr = inet_addr(argv[1]); //DETERMINAMOS LA IP
	
   	//CONECTAMOS AL SERVIDOR
    	if (connect(servidor, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
       		printf("\t**********************************************************\n");
		printf("\t//////// CONEXION NO ACEPTADA ////////\n");
		printf("\t***********************************************************\n");
		return -1;
	} else {
		printf("\t**********************************************************\n");
		printf("\t//////// CONEXION ACEPTADA ////////\n");
		printf("\t***********************************************************\n");	
	}
    	

	
	char num1[MAX] = {0};
	char num2[MAX] = {0};
	printf("DIGITE EL 1ER NUMERO: ");
	scanf("%s", num1);
	printf("DIGITE EL 2DO NUMERO: ");
	scanf("%s", num2);
	send(servidor , num1 , strlen(num1) , 0 );
	send(servidor , num2 , strlen(num2) , 0 );
	printf("Números enviados al servidor...\n");

	VLEER = read( servidor , buffer, MAX);
	printf("\t+++++++++++++++++++++++++SUMA RESUELTA++++++++++++++++++++++++++++++++\n");
    	printf("\tEL RESULTADO ES--------> %s\n",buffer );
	//CERRAMOS EL SERVIDOR
	close(servidor);

    	return 0;
}
