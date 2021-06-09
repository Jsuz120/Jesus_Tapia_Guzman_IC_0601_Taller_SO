//CABECERAS
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_NAME 100
#define SIZE_WORD 25

//DEFINIMOS LAS ESTRUCTURAS NECESARIAS 
typedef struct componente{
  	char Cad[SIZE_WORD];
  	struct componente *next;
}Nodo;

typedef struct {
  char Cad[SIZE_WORD];
}Str;
//PROTOTIPOS DE FUNCIONES
int existe_archivo(char *file_in);
int tiene_datos_arch(char *file_in);
Nodo *ListaDatos(Nodo *LISTA);
Nodo *Anadir(Nodo *LISTA, char *Palabras);
void Orden_burbuja(Nodo *LISTA);
//VARIABLES GLOBALES
int c=0;
Str array_ordenado[1000];


// FUNCION MAIN
int main(int argc, char *argv[]){
//VARIABLES DE LA FUNCION MAIN
char *name_file[SIZE_NAME];
FILE *arch_in,*arch_out;
int file_exist=0;
Nodo *WORDS = ListaDatos(WORDS);
char te[50];
//PASAMOS EL PRIMER ARGUMENTO // entrada.txt //
*name_file=argv[1];
file_exist = existe_archivo(*name_file);
// COMPROBAMOS SI EXISTE EL ARCHIVO // entrada.txt //
if(file_exist){
	       printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
               printf("\tEL ARCHIVO // %s // EXISTE\n",*name_file);
              printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	}else{
	       printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
               printf("\tEL ARCHIVO // %s // NO EXISTE\n",*name_file);
               printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");

}
// COMPROBAMOS SI TIENE DATOS EL ARCHIVO // entrada.txt //
if(tiene_datos_arch(*name_file)){
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
		printf("\tEL ARCHIVO // %s // TIENE DATOS.\n", *name_file);		
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");				
		arch_in = fopen(*name_file, "r");
		if(arch_in == NULL){
			printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
			printf("\tEl ARCHIVO // %s // NO SE ABRIO.\n", *name_file);			
			printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
		}
		else{
			printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
			printf("\tARCHIVO // %s // ABIERTO.\n", *name_file);			
			printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
			printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
			printf("\tSE CIERRA EL ARCHIVO\n");					
			printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
			while(!feof(arch_in)){
				fscanf(arch_in, "%s", te);
				if(strcmp(te,"")!=0){
					WORDS = Anadir(WORDS,te);				
				}
				memset(te,0,50);
			}				
		}
	//UTILIZAMOS E METODO DE ORDEN BURBUJA PARA ORDENAR LAS PALABRAS DEL ARCHIVO // entrada.txt // EN EL ARCHIVO // salida.txt //
	Orden_burbuja(WORDS);
	fclose(arch_in);
	//ASIGNAMOS EL SEGUNDO PARAMETRO
	arch_out = fopen(argv[2],"w");
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	printf("\tARCHIVO // %s // ABIERTO.\n",argv[2]);			
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
  	for(int i=0; i<=c; i++){
    		strcpy(te,array_ordenado[i].Cad);
   		if(strcmp(te,"") != 0){
      			fprintf(arch_out,"%s\n",te);
    		}
  	}
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	printf("\tESCRIBIENDO DATOS EN ARCHIVO // %s //.\n",argv[2]);			
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	printf("\tARCHIVO // %s // CERRADO.\n",argv[2]);			
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
  	fclose(arch_out);				
	}
	else{
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
		printf("\tEL ARCHIVO -> %s <- NO TIENE DATOS.\n", *name_file);
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	}
		
	printf("\n");


}

//FUNCIONES
int existe_archivo(char *nombre_archivo){
	FILE *arch_in;
	int existe = 0;
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	printf("\tARCHIVO // %s //  ABIERTO.\n", nombre_archivo);
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	arch_in = fopen(nombre_archivo, "r");
	if( arch_in != NULL){
		existe = 1;
		fclose(arch_in);
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
		printf("\tARCHIVO // %s //  CERRADO.\n", nombre_archivo);
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	}
	
	return existe;
}



int tiene_datos_arch(char *nombre_archivo){
	int Tiene_contenido = 0;
	FILE *arch_in;
	int lee_linea = 0, contador = 0;
	arch_in = fopen(nombre_archivo, "r");
	if( arch_in == NULL ){
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");;
		printf("\tEL ARCHIVO // %s // NO PUDO ABRIRSE EN MODO LECTURA.\n", nombre_archivo);
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	}	
	else{	
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
		printf("\tEL ARCHIVO // %s // SE ABRIO EN MODO LECTURA.\n", nombre_archivo);
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	}
	if(arch_in == NULL){
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
		printf("\tEL ARCHIVO // %s // NO SE PUDO ABRIR PARA VEIFICAR SI TIENE DATOS.\n", nombre_archivo);
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");			
		Tiene_contenido = 0;
	}
	else{	
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
		printf("\tARCHIVO // %s // ABIERTO PARA VERIFICAR SI TIENE DATOS.\n", nombre_archivo);
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
		// leo si hay datos
		fscanf(arch_in, "%d", &lee_linea);
		// mientras no sea fin de archivo.
		while(!feof(arch_in)){
			contador++;
			// leo si hay datos
			fscanf(arch_in, "%d", &lee_linea);
			if(contador > 0){
				Tiene_contenido = 1;
				break;
			}
		}
		fclose(arch_in);
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
		printf("\tARCHIVO // %s //  CERRADO.\n", nombre_archivo);
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	}	
	return Tiene_contenido;
 }

Nodo *ListaDatos(Nodo *LISTA){
  LISTA = NULL;
  return LISTA;
};

Nodo *Anadir(Nodo *LISTA, char *Palabras){
  Nodo *n_Componente, *aux; 
  n_Componente = (Nodo*)malloc(sizeof(Nodo));
  strcpy(n_Componente->Cad,Palabras);
  n_Componente->next = NULL;
  
  if(LISTA == NULL){
    LISTA = n_Componente;
  }else{
    aux = LISTA;
    while(aux->next != NULL){ 
      aux = aux->next;
    }
    aux->next = n_Componente; 
  }
  return LISTA;
};
void Orden_burbuja(Nodo *LISTA){
  Str array[1000];
  while(LISTA->next != NULL){
    strcpy(array[c].Cad,LISTA->Cad); 
    LISTA = LISTA->next;
    c++;
  }
  strcpy(array[c].Cad,LISTA->Cad);
  
  char te[SIZE_WORD];
  for(int i=0; i<c; i++){
    for(int j=0; j<c; j++){
      if(strcmp(array[j].Cad,array[j+1].Cad) >= 0){
	strcpy(te,array[j].Cad);
	strcpy(array[j].Cad,array[j+1].Cad);
	strcpy(array[j+1].Cad,te);
      }
    }
  } 
  for(int i=0; i<=c; i++){ 
      strcpy(array_ordenado[i].Cad,array[i].Cad);
  }
};

