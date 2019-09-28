
#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "UTN_Inputs.h"
#include "UTN_Validaciones.h"

#define CANT_EMP 1000
#define MIN_SUELD 1000
#define MAX_SUELD 15000
#define MIN_SECT 1
#define MAX_SECT 10
#define MIN_ID 1
#define MAX_ID 2000

typedef struct
{
	int id;
	char nombre[51];
	char apellido[51];
	float sueldo;
	int sector;
	int isEmpty;
}Empleado;

void imprimeMenu();
//funcion que imprime menu de abm
void imprimeMenuModif();
//funcion que imprime menu de modificaciones del Empleado

int abmEmpleados(void);
//funcion ABM
int initEmpleados(Empleado *pArray , int limite);
//funcion que inicializa el array de la estructura Empleado
int empleadoBuscarEmpty(Empleado *pArray, int limite, int* posicion);
//funcion que busca una posicion vacia en el array de la estructura Empleado
int addEmpleados(Empleado *pArray, int limite,int *contadorID);
//funcion que agrega un nuevo empleado al array de la estructura Empleado
int findEmpleadosById(Empleado *pArray, int limite,int id,int *posicion);
//funcion que busca por ID en el array de la estructura Empleado
int removeEmpleados(Empleado *pArray, int limite);
//funcion que da de baja logica un elemento del array de la estructura Empleado
int empleado_modificar(Empleado *pArray, int limite);
//funcion que modifica los elementos de un Empleado
int sortEmpleados(Empleado *pArray, int limite);
//funcion que ordena el array de la estructura Empleado
int printEmpleados(Empleado *pArray, int limite);
//funcion que imprime por pantalla cada elemento del array de la estructura Empleado
int promedioEmpleados(Empleado *pArray, int limite);
//funcion que calcula e imprime el promedio de sueldos en el array de la estructura Empleado


#endif /* ARRAYEMPLOYEES_H_ */
