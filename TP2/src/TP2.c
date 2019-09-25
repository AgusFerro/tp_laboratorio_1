#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"

void imprimeMenu();

int main(void)
{
	int opcion,submenu,indice,j;
	int reintentos = 3;
	int ID = 0;
	Empleado listaEmpleados[cantEmpleados];

	initEmpleados(listaEmpleados,cantEmpleados);
	imprimeMenu();
	do
	{
		__fpurge(stdin);
		scanf("%d",&opcion);
		switch(opcion)
		{
		case 1:
			addEmpleado(listaEmpleados,cantEmpleados,&ID);
			imprimeMenu();
			break;

		case 2:


			for(int i=0;i<3;i++)
			{
				if(vecPersona[i].isEmpty != 0)
				{
					printf("\n %d_ Nombre %s Edad %d DNI %d",
							i,
							vecPersona[i].nombre,
							vecPersona[i].edad,
							vecPersona[i].dni);
				}
			}
			__fpurge(stdin);
			getInt(&j,"Cual desea dar de baja?","Error",0,2,1);
			vecPersona[j].isEmpty = 0;
			imprimeMenu();
			break;

		case 3:

			imprimeMenuModif();
			__fpurge(stdin);
			getInt(&submenu,"Que desea modificar?","Error",1,3,1);
			for(int i=0;i<3;i++)
			{
				if(vecPersona[i].isEmpty != 0)
				{
					printf("\n %d_ Nombre %s Edad %d DNI %d",
							i,
							vecPersona[i].nombre,
							vecPersona[i].edad,
							vecPersona[i].dni);
				}
			}
			__fpurge(stdin);
			getInt(&indice,"Cual desea modificar?","Error",0,2,1);
			switch(submenu)
			{
			case 1:
				getString("Ingrese nombre","Error",vecPersona[indice].nombre);
				break;
			case 2:
				getInt(&vecPersona[indice].edad,"Ingrese edad","Error",10,90,5);
				break;
			case 3:
				getInt(&vecPersona[indice].dni,"Ingrese DNI","Error",100,900,5);
				break;
			}

			break;

		case 4:

			for(int i=0;i<3;i++)
			{
				if(vecPersona[i].isEmpty != 0)
				{
					printf("\n %d_ Nombre %s Edad %d DNI %d",
							i,
							vecPersona[i].nombre,
							vecPersona[i].edad,
							vecPersona[i].dni);
				}
			}
			printf("\n");

			break;

		case 5:
			for(int i=0; i<3-1;i++)
			{
			  for(int k=i+1;k<3;k++)
			  {
				  if((strcmp(vecPersona[i].nombre,vecPersona[k].nombre))>0)
			    {

			    aux = vecPersona[i];
			    vecPersona[i]=vecPersona[k];
			    vecPersona[k]=aux;
			    }
			  }

		    }
			break;
		case 6:
			printf("Hasta pronto!");
			break;
		default:
			reintentos--;
			printf("Opcion incorrecta, cantidad de reintentos: %d \n",reintentos);
			imprimeMenu();
			break;
		}

	}while(opcion != 6 && reintentos > 1);
	if(reintentos <= 1)
	{
		printf("Cantidad de reintentos agotada\n");
	}
	return 0;
	}


int imprimeMenu()
{
	printf("\n1.Alta");
	printf("\n2.Baja");
	printf("\n3.Modificacion");
	printf("\n4.Listar");
	printf("\n5.Ordenar");
	printf("\n6.Salir");
	printf("\n");

}

