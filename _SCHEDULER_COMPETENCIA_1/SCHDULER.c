
#include "schd.h"

int main() {
	

			printf("****************************\n");
			printf("PLANIFICADOR DE PROCESOS\n");
			printf("****************************\n");


	 PProcesos();
	
	 Oprocess();
	
	for (int i=0; i<numProcesos; i++) {
		tf += proc[i][0];
		time = time + tf;
		printf("**********************************************************\n");
		printf("\n EL PROCESO %d, TERMINA EN %2.1f, SEGUNDOS.\n", proc[i][1], tf);
		printf("**********************************************************\n");	
	}

	printf("\n");
	printf("****************************\n");
	printf("TIEMPO TRANSCURRIDO %2.1f \n", time);
	printf("****************************\n");	
	time = time / numProcesos;
	printf("\n\nTIEMPO PROMEDIO DE EJCUCION DE LOS PROCESOS: %2.2f SEGUNDOS\n:", time);
	return 0;
}
