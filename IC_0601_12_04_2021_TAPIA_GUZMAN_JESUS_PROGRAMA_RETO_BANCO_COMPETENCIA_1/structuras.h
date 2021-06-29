#ifndef __STRUCTURAS_H
#define __STRUCTURAS_H

#include "variables.h"

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

#endif
