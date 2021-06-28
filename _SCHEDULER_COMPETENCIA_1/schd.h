#ifndef __SCHD_H
#define __SCHD_H


#include<stdio.h>

int numProcesos= 12, proc[10][2];		
	double tf = 0, time;

void PProcesos(){

//PEDIMOS AL USUARIO QUE INGRESE EL NUMERO DE PROCESOS
	while (numProcesos > 11 || numProcesos <= 0) {
		printf("\n****************************\n");
		printf("\nDETERMINA EL NUMERO DE PROCESOS: ");
		scanf("%d", &numProcesos);
	}

	// DEFINIMOS EL TIEMPO DE EJECUCION
	for(int i=0; i<numProcesos; i++) {
		printf("****************************\n");
		printf("\nINSERTE EL PROCESO %d :", i+1);
		scanf("%d", &proc[i][0]);
		proc[i][1] = i+1;
	}


}


void Oprocess(){


//ORDENAMOS DE MENOR A MAYOR
	for (int i=0; i<numProcesos-1; i++) {
		for(int j=i+1; j<numProcesos; j++) {
			if (proc[j][0]<proc[i][0]) {
				int aux[2] = {proc[j][0], proc[j][1]};
				proc[j][0] = proc[i][0];
				proc[j][1] = proc[i][1];
				proc[i][0] = aux[0];
				proc[i][1] = aux[1];
			}
		}
	}




}


#endif
