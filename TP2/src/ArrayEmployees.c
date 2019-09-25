#include "ArrayEmployees.h"

int initEmpleados(Empleado *pArray , int limite)
{
	int retorno = -1;
	int i;
	if(pArray != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			pArray[i].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
}

int empleadoBuscarEmpty(Empleado *pArray, int limite, int* posicion)
{
    int retorno=-1;
    int i;
    if(pArray!= NULL && limite>=0 && posicion!=NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(pArray[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int addEmpleados(Empleado *pArray, int limite, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(pArray!=NULL && limite>0 && contadorID!=NULL)
    {
        if(empleadoBuscarEmpty(pArray,limite,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            pArray[posicion].isEmpty=0;
            getString("\nIngrese Nombre: ","\nError",pArray[posicion].nombre);
            getString("\nIngrese Apellido: ","\nError",pArray[posicion].apellido);
            getFloat(&pArray[posicion].sueldo,"\nIngrese Sueldo: ","\nError",1500,10000,3);
            getInt(&pArray[posicion].sector,"\nIngrese Sector: ","\nError",1,10,2);
            (*contadorID)++;
            pArray[posicion].id = contadorID;
            printf("\n Posicion: %d\n ID: %d\n Nombre: %s\n Apellido: %s\n Sueldo: %f\n Sector: %d",
                   posicion, pArray[posicion].id,pArray[posicion].nombre,pArray[posicion].apellido,pArray[posicion].sueldo,pArray[posicion].sector);
            retorno=0;
        }
    }
    return retorno;
}

int removeEmpleados(Empleado *pArray, int limite)
{
	int retorno = -1;
	int ID;
	if(getInt(&ID,"Ingrese un ID para dar de baja","Error",1,2000,2)==0)
	{
		for(int i=0;i<limite;i++)
		{
			if(pArray[i].id == id)
			{
				pArray[i].isEmpty = 1;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int printEmpleados(Empleado *pArray, int limite)
{
	for(int i=0;i<limite;i++)
	{
		if(pArray[i].isEmpty != 1)
		{
			printf("\n Posicion %d_ ID %d Nombre %s Apellido %s Sueldo %f Sector %d",
					i,
					pArray[i].id,
					pArray[i].nombre,
					pArray[i].apellido,
					pArray[i].sueldo,
					pArray[i].sector);
		}
	}
	printf("\n");
	return 0;
}
