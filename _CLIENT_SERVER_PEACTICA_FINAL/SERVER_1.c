//CABECERA
#include "head.h"

int main(int argc, char const *argv[]) {
	if (argc < 2){
		printf("\t***********************************************\n");
		printf("\t////////NO HAZ DETERMINADO EL PUERTO ////////\n");
		printf("\t***********************************************\n");
		return 1;
	}
	
	//PARAMETO PARA ALMACENAR EL PUERTO
	int puerto = atoi(argv[1]);

	int fd_servidor, fd_cliente, VLEER;
    	struct sockaddr_in dir;
    	int opt = 1;
    	int addrlen = sizeof(dir);
    	char buffer[MAX] = {0};
    	
       
    	//CREAMOS EL SOCKET
    	if ((fd_servidor = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        	printf("\t***********************************************\n");
		printf("\t//////// NO SE PUEDE ABRIR EL SOCKET ////////\n");
		printf("\t***********************************************\n");
		exit(EXIT_FAILURE);
    	}else{

		printf("\t***********************************************\n");
		printf("\t//////// SOCKET ABIERTO////////\n");
		printf("\t***********************************************\n");
	}
       
    	
    	if (setsockopt(fd_servidor, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,&opt, sizeof(opt))) {
        	perror("setsockopt");
        	exit(EXIT_FAILURE);
    	}
    	dir.sin_family = AF_INET;
    	dir.sin_addr.s_addr = INADDR_ANY;
    	dir.sin_port = puerto;
       
    	//OBTENEMOPS EL IP Y EL PUERTO
    	if (bind(fd_servidor, (struct sockaddr *)&dir,sizeof(dir))<0) {
        printf("\t***********************************************\n");
	printf("\t//////// NO SE ESTABLECIO LA IP Y EL PUERTO ////////\n");
	printf("\t***********************************************\n");
	exit(EXIT_FAILURE);

	}else{

	printf("\t**********************************************************\n");
	printf("\t//////// SE ESTABLECIO LA IP Y EL PUERTO  ////////\n");
	printf("\t***********************************************************\n");

}
	//COLOCAMOS EL SERVIDOR EN MODO ESCUCHA
    	if (listen(fd_servidor, 3) < 0) {
        printf("\t**********************************************************\n");
	printf("\t//////// NO SE PUDO ESTABLECER EN MODO ESCUCHA ////////\n");
	printf("\t***********************************************************\n");
	exit(EXIT_FAILURE);
	}else{

	printf("\t***************************************************************+*\n");
	printf("\t//////// SERVIDOR EN MODO ESCUCHA |Esperando conexion| ////////\n");
	printf("\t*****************************************************************\n");

}
	//ACEPTAMOS LA CONEXION CON EL CLIENTE
	if ((fd_cliente = accept(fd_servidor, (struct sockaddr *)&dir, (socklen_t*)&addrlen))<0) {
        printf("\t**********************************************************\n");
	printf("\t//////// CONEXION NO ACEPTADA ////////\n");
	printf("\t***********************************************************\n");
	exit(EXIT_FAILURE);
	}else{

	printf("\t**********************************************************\n");
	printf("\t//////// CONEXION ACEPTADA ////////\n");
	printf("\t***********************************************************\n");


}
    	//LLAMADA A LA FUNCION _sumaNum() 
	 char str1[MAX];
	char str2[MAX];
	
	
	bzero(buffer, MAX);
	VLEER = read( fd_cliente , buffer, MAX);
    	printf("%s\n",buffer );
	strcpy(str1, buffer);
	
	
	bzero(buffer, MAX);
	VLEER = read( fd_cliente , buffer, MAX);
    	printf("%s\n",buffer );
	strcpy(str2, buffer);
    	
	// Longitud de los strings
	int len1 = strlen(str1);
	int len2 = strlen(str2);

	int num1[MAX];
	int num2[MAX];	
	int nSuma[MAX];	
	
	// Extrayendo los números de los caracteres
	int i = 0;
	while (i <= len1){
		num1[i] = str1[i] - '0';
		i++;
	}

	i = 0;
	while(i <= len2){
		num2[i] = str2[i] - '0';
		i++;
	}
	
	// Realizando la suma, el ciclo de la suma cambia dependiendo cual es el numero mayor
        int tmporal = 0;
	if (len1 < len2) {
        	int carry = 0;
        	int j = len1 - 1;
        	for (int i = len2 - 1; i >= 0; i--){
                	tmporal = num2[i] + num1[j] + carry;
                	if (tmporal >= 10){
                        	carry = tmporal/10;
                        	tmporal = tmporal%10;
                	} else {
                        	carry = 0;
                	}
                	j--;
                	nSuma[i] = tmporal;
        	}
        	if (carry != 0){
                	nSuma[0] = nSuma[0]+(carry*10);
        	}

	} else {
        	tmporal = 0;
        	int carry = 0;
        	int j = len2 - 1;
        	for (int i = len1 - 1; i >= 0; i--){
                	tmporal = num1[i] + num2[j] + carry ;
                	if (tmporal >= 10){
                        	carry = tmporal/10;
                        	tmporal = tmporal%10;
                	} else {
                        	carry = 0;
                	}
                	j--;
                	nSuma[i] = tmporal;
        	}
        	if (carry != 0){
                	nSuma[0] = nSuma[0]+(carry*10);
        	}

	}

	// Limpiando el buffer
	bzero(buffer, MAX);
	// aqui se hace el proceso inverso, los números (int) se convierten a char
	// y se almacenan en el arreglo char nSuma
	if (len1 < len2) {
        	int i = 0;
	        int j = 0;
        	if ((nSuma[i]) >= 10){
	                tmporal = nSuma[i];
	                buffer[0] = (tmporal/10) + '0';
	                buffer[1] = (tmporal%10) + '0';
	                len2++;
	                i = i + 2;
	                j++;
        	}
	        while(i != len2){
	                buffer[i] = nSuma[j] + '0';
        	        i++;
	                j++;
        	}
	} else {
	        int i = 0;
        	int j = 0;
	        if ((nSuma[i]) >= 10){
        	        tmporal = nSuma[i];
                	buffer[0] = (tmporal/10) + '0';
	                buffer[1] = (tmporal%10) + '0';
        	        len1++;
                	i = i + 2;
	                j++;
        	}
	        while(i != len1){
        	        buffer[i] = nSuma[j] + '0';
	                i++;
        	        j++;
	        }	
	}
	



	//SE MUESTRA LA SUMA Y SE ENVIA EL RESULTADO AL CLIENTE
	send(fd_cliente, buffer, strlen(buffer), 0);
    	printf("\nLa suma es = %s\n", buffer);
    	printf("\nCliente Desconectado\n");
	//CERRAMOS EL CLIENTE
	close(fd_cliente);
    	return 0;
}










