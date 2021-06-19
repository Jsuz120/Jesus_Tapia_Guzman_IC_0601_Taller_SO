# include <stdio.h>
# include <stdlib.h>

int main(void) {
int x=10;
int *p;
int y=20;
int *puntero;

p= &x;
puntero= &y;

printf("\nESTE ES EL CONTENIDO DEL PUNTERO P --> %i \n",*p);
*p = *p + 1;
printf("\nESTE ES EL CONTENIDO DEL PUNTERO P --> %i \n",*p);
*p = *p + 2;
printf("\nESTE ES EL CONTENIDO DEL PUNTERO P --> %i \n",*p);

printf("\nESTE ES EL CONTENIDO DEL PUNTERO P --> %i \n",*puntero);



return 0;

}



