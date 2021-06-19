# include <stdio.h>

int main() {

int arrayInt[5];
int i;
int *punteroInt,*punteroIntDos;

for(i=0;i<5;i++){ 
	arrayInt[i]=i;
}
punteroInt= arrayInt;
punteroIntDos = &arrayInt[0];

printf("\n1ER ELEMENTO DEL ARRAY --arrayInt--:%i",arrayInt[0]);
printf("\n1ER ELEMENTO DEL PONTERO --punteroInt-- %d: ",*punteroInt);
printf("\n1ER ELEMENTO DEL PUNTERO --punteroIntDos-- %d: ",*punteroIntDos);
printf("\n5TO ELEMENTO DEL ARRAY --arrayInt-- %i:",arrayInt[4]);
printf("\n5TO ELEMENTO DEL PONTERO --punteroInt-- %i: ",punteroInt[4]);
printf("\n5TO ELEMENTO DEL PUNTERO --punteroIntDos-- %i: ",punteroIntDos[4]);

for(i=0;i<5;i++){
	punteroIntDos[i]=i;
	printf("--\n punteroIntSos-- *%i* *%i*: ",i,punteroIntDos[i]);

}

for(i=0;i<5;i++){ 
	punteroIntDos[i]=i; 
	printf("--\n punteroIntDos-- *%i* *%i*: ",i,punteroIntDos[i]);
}
printf("\n");
return 0;

}
