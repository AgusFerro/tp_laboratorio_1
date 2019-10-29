#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Inputs.h"
#include "Validaciones.h"

Employee* employee_new()
{
	Employee* this;
	this=malloc(sizeof(Employee));
	return this;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* emp=employee_new();
	if(emp!=NULL)
	{
		employee_setIdchar(emp,idStr);
		employee_setNombre(emp,nombreStr);
	    employee_setHorasTrabajadaschars(emp,horasTrabajadasStr);
	    employee_setSueldochar(emp,sueldoStr);
	}
	return emp;
}

int employee_delete(Employee* this)
{
	int retorno=-1;

	if(this!=NULL)
	{
		free(this);
		retorno=0;
	}

	return retorno;
}

int employee_setId(Employee* this,int id)
{
	int retorno=-1;

	if(this != NULL && id >= 0)
	{
        this->id = id;
        retorno = 0;
	}
	return retorno;
}
int employee_getId(Employee* this,int* id)
{
	int retorno = -1;

	if(this != NULL)
	{
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && isValidName(nombre))
	{
		strncpy(this->nombre,nombre,sizeof(this->nombre));
		retorno = 0;
	}
	return retorno;
}
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL)
	{
	   strncpy(nombre,this->nombre,sizeof(this->nombre));
	   retorno = 0;
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas >= 0)
	{
		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo >= 0)
	{
		this->sueldo = sueldo;
		retorno = 0;
	}
	return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;
	if(this != NULL)
	{
		*sueldo = this->sueldo;
		retorno = 0;
	}
	return retorno;
}


