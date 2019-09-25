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
int findEmployeeById(Empleado pArray, int len,int id);
int removeEmployee(Empleado *pArray, int len, int id);


#endif /* ARRAYEMPLOYEES_H_ */
