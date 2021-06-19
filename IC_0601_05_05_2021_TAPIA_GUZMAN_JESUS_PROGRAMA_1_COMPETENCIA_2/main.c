#include "scheduler.h"

void reproducir_musica(void);
void abrir_youtube(void);
void escribir_texto_word(void);
void descargar_archivo(void);
void subiendo_archivo(void);
void compilando_programa(void);
void ejecutando_programa(void);
void usando_terminal(void);
//ACCIONES DE LOS HILOS
void *thread_reproducir_musica(void *args);
void *thread_abrir_youtube(void *args);
void *thread_escribir_texto_word(void *args);
void *thread_descargar_archivo(void *args);
void *thread_subiendo_archivo(void *args);
void *thread_compilando_programa(void *args);
void *thread_ejecutando_programa(void *args);
void *thread_usando_terminal(void *args);

int main(int argc, char const *argv[]){
	//GREAMOS EL PROCESO
	process *p1 = crear_Proceso(1, UN_SEGUNDO, "Proceso_1", reproducir_musica, ACTIVO); 		//<--
	process *p2 = crear_Proceso(1, DOS_SEGUNDOS, "Proceso_1", abrir_youtube, NO_ACTIVO);
	process *p3 = crear_Proceso(3, TRES_SEGUNDOS, "Proceso_2", escribir_texto_word, ACTIVO); 	//<--
	process *p4 = crear_Proceso(4, TRES_SEGUNDOS, "Proceso_3", descargar_archivo, ACTIVO);   	//<--
	process *p5 = crear_Proceso(3, TRES_SEGUNDOS, "Proceso_4", subiendo_archivo, ACTIVO);		
	process *p6 = crear_Proceso(4, TRES_SEGUNDOS, "Proceso_5", compilando_programa, NO_ACTIVO);
	process *p7 = crear_Proceso(0, TRES_SEGUNDOS, "Proceso_6", ejecutando_programa, ACTIVO);	//<--	
	process *p8 = crear_Proceso(2, CUATRO_SEGUNDOS, "Proceso_7", usando_terminal, ACTIVO);		//<--
	process *p9 = crear_Proceso(5, CUATRO_SEGUNDOS, "Proceso_8", usando_terminal, NO_ACTIVO);	//<--

	array_procesos *array = crear_ArrayProcesos();
	//AGRERGAMOS EL PROCESO
	agregar_Proceso(array, *p1);
	agregar_Proceso(array, *p2);
	agregar_Proceso(array, *p3);
	agregar_Proceso(array, *p4);
	agregar_Proceso(array, *p5);
	agregar_Proceso(array, *p6);
	agregar_Proceso(array, *p7);
	agregar_Proceso(array, *p8);
	agregar_Proceso(array, *p9);
	//EJECUTAMOS PROCESO
	ejecutar_Procesos(array);

	free(array);
	free(p1);
	free(p2);
	free(p3);
	free(p4);
	free(p5);
	free(p6);
	free(p7);
	free(p8);
	free(p9);

	return 0;
}
//DENTRO DE CADA FUNCION CREAMOS EL HILO
void reproducir_musica(void){
	pthread_t thread_ReproducirMusica;
	pthread_create(&thread_ReproducirMusica,NULL,thread_reproducir_musica,NULL);
	pthread_join(thread_ReproducirMusica,NULL);
}

void abrir_youtube(void){
	pthread_t thread_AbrirYoutube;
	pthread_create(&thread_AbrirYoutube,NULL,thread_abrir_youtube,NULL);
	pthread_join(thread_AbrirYoutube,NULL);
}

void escribir_texto_word(void){
	pthread_t thread_EscribirTextoWord;
	pthread_create(&thread_EscribirTextoWord,NULL,thread_escribir_texto_word,NULL);
	pthread_join(thread_EscribirTextoWord,NULL);
}

void descargar_archivo(void){
	pthread_t thread_DescargarArchivo;
	pthread_create(&thread_DescargarArchivo,NULL,thread_descargar_archivo,NULL);
	pthread_join(thread_DescargarArchivo,NULL);
}

void subiendo_archivo(void){
	pthread_t thread_SubiendoArchivo;
	pthread_create(&thread_SubiendoArchivo,NULL,thread_subiendo_archivo,NULL);
	pthread_join(thread_SubiendoArchivo,NULL);
}

void compilando_programa(void){
	pthread_t thread_CompilandoPrograma;
	pthread_create(&thread_CompilandoPrograma,NULL,thread_compilando_programa,NULL);
	pthread_join(thread_CompilandoPrograma,NULL);
}

void ejecutando_programa(void){
	pthread_t thread_EjecutandoPrograma;
	pthread_create(&thread_EjecutandoPrograma,NULL,thread_ejecutando_programa,NULL);
	pthread_join(thread_EjecutandoPrograma,NULL);
}

void usando_terminal(void){
	pthread_t thread_UsandoTerminal;
	pthread_create(&thread_UsandoTerminal,NULL,thread_usando_terminal,NULL);
	pthread_join(thread_UsandoTerminal,NULL);
}
//ESTAS FUNCIONES REPRESENTAN LA ACCION QUE REALIZARA CADA HILO
void *thread_reproducir_musica(void *args){
	char *Accion= "Reproduciendo Música";
	int i;
	printf("HILO EJECUTANDOSE....");
	for(i=0; i < strlen(Accion);i++){
		printf("%c",Accion[i]);
	}
	printf("\n");
	return NULL;
}

void *thread_abrir_youtube(void *args){
	char *Accion= "Usando Youtube";
	int i;
	printf("HILO EJECUTANDOSE....");
	for(i=0; i < strlen(Accion);i++){
		printf("%c",Accion[i]);
	}
	printf("\n");
	return NULL;
}

void *thread_escribir_texto_word(void *args){
	char *Accion= "Escribiendo Texto en Word";
	int i;
	printf("HILO EJECUTANDOSE....");
	for(i=0; i < strlen(Accion);i++){
		printf("%c",Accion[i]);
	}
	printf("\n");
	return NULL;
}

void *thread_descargar_archivo(void *args){
	char *Accion= "Descargando Archivo";
	int i;
	printf("HILO EJECUTANDOSE....");
	for(i=0; i < strlen(Accion);i++){
		printf("%c",Accion[i]);
	}
	printf("\n");
	return NULL;
}

void *thread_subiendo_archivo(void *args){
	char *Accion= "Subiendo Archivo";
	int i;
	printf("HILO EJECUTANDOSE....");
	for(i=0; i < strlen(Accion);i++){
		printf("%c",Accion[i]);
	}
	printf("\n");
	return NULL;
}

void *thread_compilando_programa(void *args){
	char *Accion= "Compilando programa";
	int i;
	printf("HILO EJECUTANDOSE....");
	for(i=0; i < strlen(Accion);i++){
		printf("%c",Accion[i]);
	}
	printf("\n");
	return NULL;
}

void *thread_ejecutando_programa(void *args){
	char *Accion= "Ejecutando programa";
	int i;
	printf("HILO EJECUTANDOSE....");
	for(i=0; i < strlen(Accion);i++){
		printf("%c",Accion[i]);
	}
	printf("\n");
	return NULL;
}

void *thread_usando_terminal(void *args){
	char *Accion= "Usando la terminal";
	int i;
	printf("HILO EJECUTANDOSE....");
	for(i=0; i < strlen(Accion);i++){
		printf("%c",Accion[i]);
	}
	printf("\n");
	return NULL;
}
