#include "ArrayEmployees.h"

void imprimeMenu()
{
	printf("\n1.Alta");
	printf("\n2.Baja");
	printf("\n3.Modificacion");
	printf("\n4.Informar");
	printf("\n5.Salirr");
	printf("\n");

}

void imprimeMenuModif()
{
	printf("\nA.Nombre");
	printf("\nB.Apellido");
	printf("\nC.Sueldo");
	printf("\nD.Sector");
	printf("\nS.Salir");
	printf("\n");

}

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
            fflush(stdin);
            getString("\nIngrese Nombre: ","\nError",pArray[posicion].nombre);
            fflush(stdin);
            getString("\nIngrese Apellido: ","\nError",pArray[posicion].apellido);
            fflush(stdin);
            getFloat(&pArray[posicion].sueldo,"\nIngrese Sueldo: ","\nError",1500,10000,3);
            fflush(stdin);
            getInt(&pArray[posicion].sector,"\nIngrese Sector: ","\nError",1,10,2);
            fflush(stdin);
            pArray[posicion].id = (*contadorID)++;
            pArray[posicion].isEmpty=0;
            printf("\n Posicion: %d\n ID: %d\n Nombre: %s\n Apellido: %s\n Sueldo: %f\n Sector: %d",
                   posicion, pArray[posicion].id,pArray[posicion].nombre,pArray[posicion].apellido,pArray[posicion].sueldo,pArray[posicion].sector);
            retorno=0;
        }
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

int removeEmpleados(Empleado *pArray, int limite)
{
	int retorno = -1;
	int ID;
	if(getInt(&ID,"Ingrese un ID para dar de baja","Error",1,2000,2)==0)
	{
		for(int i=0;i<limite;i++)
		{
			if(pArray[i].id == ID && pArray[i].isEmpty == 0)
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

int empleado_modificar(Empleado *pArray, int limite)
{
    int retorno=-1;
    int posicion;
    int id;
    char opcion;
    if(pArray!=NULL && limite>0)
    {
        getInt(&id,"\nID a modificar: ","\nError",1,2000,2);
        if(findEmpleadosById(pArray,limite,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {
            	printf("\n Posicion %d_ ID %d Nombre %s Apellido %s Sueldo %f Sector %d",
            						posicion,
            						pArray[posicion].id,
            						pArray[posicion].nombre,
            						pArray[posicion].apellido,
            						pArray[posicion].sueldo,
            						pArray[posicion].sector);
            	imprimeMenuModif();
                getChar(&opcion,"\nIngrese una opcion: ","\nError",'A','Z',1);
                switch(opcion)
                {
                    case 'A':
                        getString("\nIngrese nombre: ","\nError",pArray[posicion].nombre);
                        break;
                    case 'B':
                        getString("\nIngrese apellido: ","\nError",pArray[posicion].apellido);
                        break;
                    case 'C':
                        getFloat(&pArray[posicion].sueldo,"\nIngrese sueldo ","\nError",1500,10000,2);
                        break;
                    case 'D':
                        getInt(&pArray[posicion].sector,"\nIngrese sector: ","\nError",1,10,2);
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}

int sortEmpleados(Empleado *pArray,int limite)
{
    int retorno=-1;
    int i;
    char orden;
    Empleado buffer;
    int flagSwap;

    if(pArray!=NULL && limite>=0)
    {
    	getChar(&orden,"\nIngrese orden asc/desc (A/D)","\nError",'A','Z',3);
    	switch(orden)
    	{
    	case 'A':
    		do
    		{
    			flagSwap=0;
    			for (i = 1; i < limite-1; i++)
    		    {
    				if(strcmp(pArray[i].apellido,pArray[i+1].apellido) > 0)

    				{
    					flagSwap=1;
    		    		buffer = pArray[i];
    		    		pArray[i] = pArray[i+1];
    		    		pArray[i+1] = buffer;
    				}
    				else if(strcmp(pArray[i].apellido,pArray[i+1].apellido) == 0)
    				{
    					if(pArray[i].sector > pArray[i+1].sector)
    		    		{
    		    		   flagSwap=1;
    		    		   buffer = pArray[i];
    		    		   pArray[i] = pArray[i+1];
    		    		   pArray[i+1] = buffer;
    		    		}
    				}
    		    }
    		}while(flagSwap);
    		break;

    	case 'D':
    		do
    		{
    		  flagSwap=0;
    		  for (i = 1; i < limite-1; i++)
    		  {
    		      if(strcmp(pArray[i].apellido,pArray[i+1].apellido) < 0)
    		      {
    		        flagSwap=1;
    		        buffer = pArray[i];
    		        pArray[i] = pArray[i+1];
    		        pArray[i+1] = buffer;
    		      }
    		      else if(strcmp(pArray[i].apellido,pArray[i+1].apellido) == 0)
    		      {
    		         if(pArray[i].sector < pArray[i+1].sector)
    		         {
    		           flagSwap=1;
    		           buffer = pArray[i];
    		           pArray[i] = pArray[i+1];
    		           pArray[i+1] = buffer;
    		          }
    		       }
    		   }
    		 }while(flagSwap);
    		break;
    	}

        retorno=0;
    }
    return retorno;
}

int findEmpleadosById(Empleado *pArray, int limite, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(pArray!= NULL && limite>=0)
    {
        for(i=0;i<limite;i++)
        {
            if(pArray[i].isEmpty==1)
                continue;
            else if(pArray[i].id==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int promedioEmpleados(Empleado *pArray, int limite)
{
	int retorno=-1;
	int i,j;
	int contador = 0,contadorSueldo = 0;
	float acumulador = 0, promedio;

	if(pArray!= NULL && limite>=0)
	{
		for(i=0;i<limite;i++)
		{
			if(pArray[i].isEmpty != 1)
			{
				acumulador = acumulador + pArray[i].sueldo;
				contador++;
			}
		}

		promedio = acumulador/contador;
		printf("\nTotal de sueldos acumulados: %f",acumulador);
		printf("\nPromedio de sueldos: %f",promedio);

		for(j=0;j<limite;j++)
		{
			if(pArray[j].isEmpty != 1 && pArray[j].sueldo > promedio)
			{
				contadorSueldo++;
			}
		}
		printf("\nCantidad de empleados que superan el promedio: %d",contadorSueldo++);
		retorno = 0;
	}
	return retorno;
}
