#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	Employee* empleado;
	char id[50];
	char nombre[50];
	char horas[50];
	char sueldo[50];
	int registro;

	fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,sueldo);
	while(!feof(pFile))
	{
	    registro = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,sueldo);

	    if(registro == 4)
	    {
	       empleado = employee_newParametros(id,nombre,horas,sueldo);
	       if(empleado!=NULL)
	       {
	    	   ll_add(pArrayListEmployee,empleado);
	       }
	       else
	       {
	    	   printf("\nNo se pudo crear empleado");
	    	   retorno = -1;
	    	   break;
	       }

	    }
	    else
	    {
	    	printf("\nNo se pudo leer empleado correctamente");
	        retorno = -1;
	        break;
	    }
	}
	return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int leidos=0;
	Employee* pEmpleado;

	    if(pFile!=NULL && pArrayListEmployee!= NULL)
	    {
	    	do
	    	{
	    	 	 pEmpleado=employee_new();
	    	 	 leidos=fread(pEmpleado,sizeof(Employee),1,pFile);
	    	 	 if(leidos==1 && employee_validarEmpleado(pEmpleado)==0)
	    	 	 {
	    	 		ll_add(pArrayListEmployee,pEmpleado);
	    	 	 }
	    	 	 else
	    	 	 {
	    	 		 printf("\nEl empleado no pudo ser cargado");
	                employee_delete(pEmpleado);
	    	 	 }
	    	}while(!feof(pFile));
	    	retorno=0;
	    }
	    return retorno;
}
