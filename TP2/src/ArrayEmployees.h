/*
 * ArrayEmployees.h
 *
 *  Created on: 24 sep. 2019
 *      Author: agustin
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "UTN_Inputs.h"
#include "UTN_Validaciones.h"
#define cantEmpleados 1000

typedef struct
{
	int id;
	char nombre[51];
	char apellido[51];
	float sueldo;
	int sector;
	int isEmpty;
}Empleado;

int initEmpleados(Empleado *pArray , int limite);
int addEmpleados(Empleado *pArray, int limite,int id, char *nombre, char *apellido, float suledo,int sector);
int findEmpleadosById(Empleado *pArray, int limite,int id);
int removeEmpleados(Empleado *pArray, int limite);
int sortEmpleados(Empleado *pArray, int limite, int orden);
int printEmpleados(Empleado *pArray, int limite);


#endif /* ARRAYEMPLOYEES_H_ */
