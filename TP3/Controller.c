#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Inputs.h"
#include "Validaciones.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE*pArchivo;
	int retorno=-1;
	if(path != NULL && pArrayListEmployee != NULL)
	{
	   pArchivo=fopen(path,"r");
	   if(pArchivo != NULL)
	   {
	      if(parser_EmployeeFromText(pArchivo,pArrayListEmployee)==0)
	      {
	    	  fclose(pArchivo);
	    	  retorno=0;
	      }
	      else
	      {
	    	  printf("\nNo se pudo cargar la lista");
	      }

	   }
	   else
	   {
	      printf("\nNo se pudo abrir el archivo...");
	   }
	}
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pFile;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"rb");
        if(pFile!=NULL)
        {
            parser_EmployeeFromBinary(pFile,pArrayListEmployee);
            retorno=0;
        }
        else
        {
            printf("\nEl archivo no pudo abrirse");
        }

    }
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    Employee* empleado;
    char bufferNombre[50];
    int bufferHoras;
    int bufferSueldo;
    if(pArrayListEmployee!=NULL &&
        utn_getName("\nIngrese el nombre: ","\nError",1,50,2,bufferNombre)==0 &&
        utn_getInt(&bufferHoras,"\nIngrese cantidad de horas: ","\nError",1,9999,2)==0 &&
        utn_getInt(&bufferSueldo,"\nIngrese el sueldo: ","\nError",1,99999,2)==0)
    {
            empleado=employee_new();
            if(empleado!=NULL && employee_setNombre(empleado,bufferNombre)==0 &&
                employee_setId(empleado,(employee_buscarMaxId(pArrayListEmployee)+1))==0 && employee_setSueldo(empleado,bufferSueldo)==0 &&
                employee_setHorasTrabajadas(empleado,bufferHoras)==0)
            {
                    retorno=0;
                    ll_add(pArrayListEmployee,empleado);
                    printf("id %d",empleado->id);
            }
            else
            {
                employee_delete(empleado);
                empleado=NULL;
            }
    }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int len;
    int i;
    Employee* empleado;
    char bufferNombre[50];
    int bufferHoras;
    int bufferSueldo;
    int bufferId;
    int auxId;
    if(pArrayListEmployee!= NULL)
    {
    	utn_getInt(&auxId,"\nIngrese el id del empleado a modificar: ","\nError",0,9999,2);
        len=ll_len(pArrayListEmployee);
        for(i=0;i<len;i++)
        {
            empleado=(Employee*)ll_get(pArrayListEmployee,i);
            employee_getId(empleado,&bufferId);
            if(bufferId==auxId)
            {
            	employee_getSueldo(empleado,&bufferSueldo);
            	employee_getHorasTrabajadas(empleado,&bufferHoras);
            	employee_getNombre(empleado,bufferNombre);
            	printf("Id - %d,Nombre - %s,Horas - %d,Sueldo - %d\n",bufferId,bufferNombre,bufferHoras,bufferSueldo);
            	utn_getName("\nIngrese el nombre: ","\nError",1,50,2,bufferNombre);
                utn_getInt(&bufferHoras,"\nIngrese cantidad de horas: ","\nError",1,9999,2);
                utn_getInt(&bufferSueldo,"\nIngrese el sueldo: ","\nError",1,9999,2);
                employee_setNombre(empleado,bufferNombre);
                employee_setSueldo(empleado,bufferSueldo);
                employee_setHorasTrabajadas(empleado,bufferHoras);

                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int len;
    int i;
    int sueldo,horas;
    char nombre[50];
    Employee* empleado;
    int bufferId;
    int auxId;
    if(pArrayListEmployee!= NULL)
    {
    	utn_getInt(&auxId,"\nIngrese el id del empleado a modificar: ","\nError",0,9999,2);
        len=ll_len(pArrayListEmployee);
        for(i=0;i<len;i++)
        {
            empleado=(Employee*)ll_get(pArrayListEmployee,i);
            employee_getId(empleado,&bufferId);
            if(bufferId==auxId)
            {
            	employee_getSueldo(empleado,&sueldo);
            	employee_getHorasTrabajadas(empleado,&horas);
            	employee_getNombre(empleado,nombre);
            	printf("Se ha removido este empleado: Id - %d,Nombre - %s,Horas - %d,Sueldo - %d\n",bufferId,nombre,horas,sueldo);
                ll_remove(pArrayListEmployee,i);
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int len;
    int i;
    int id;
    int sueldo;
    char nombre[50];
    int horas;
    Employee* bufferEmployee;
    if(pArrayListEmployee != NULL)
    {
        len=ll_len(pArrayListEmployee);
        for(i=0;i<len;i++)
        {
            bufferEmployee=(Employee*)ll_get(pArrayListEmployee,i);
            if(bufferEmployee!=NULL)
            {
            	employee_getId(bufferEmployee,&id);
            	employee_getSueldo(bufferEmployee,&sueldo);
            	employee_getHorasTrabajadas(bufferEmployee,&horas);
            	employee_getNombre(bufferEmployee,nombre);
            	printf("Id - %d,Nombre - %s,Horas - %d,Sueldo - %d\n",id,nombre,horas,sueldo);
            }
        }
        retorno=0;
    }
    return retorno;

}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

