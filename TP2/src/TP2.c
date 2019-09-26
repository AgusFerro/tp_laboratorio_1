#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"

int main(void)
{
	int opcion,opcionListar;
	int reintentos = 3;
	int ID = 0, flag1 = 0;
	Empleado listaEmpleados[CANT_EMP];

	initEmpleados(listaEmpleados,CANT_EMP);
	imprimeMenu();
	do
	{
		__fpurge(stdin);
		scanf("%d",&opcion);
		switch(opcion)
		{
		case 1:
			addEmpleados(listaEmpleados,CANT_EMP,&ID);
			flag1++;
			imprimeMenu();
			break;

		case 2:
			if(flag1<1)
			{
				printf("\nNo hay datos cargados");
				imprimeMenu();
			}
			else
			{
				removeEmpleados(listaEmpleados, CANT_EMP);
				imprimeMenu();
			}
			break;

		case 3:
			if(flag1<1)
			{
				printf("\nNo hay datos cargados");
				imprimeMenu();
			}
			else
			{
			empleado_modificar(listaEmpleados,CANT_EMP);
			imprimeMenu();
			}
			break;

		case 4:
			if(flag1<1)
			{
				printf("\nNo hay datos cargados");
			}
			else
			{
				getInt(&opcionListar,"\n1.PromedioSueldos - 2.ListaEmpleados ","\nError",1,2,2);
				switch(opcionListar)
				{
				case 1:
					promedioEmpleados(listaEmpleados,CANT_EMP);
					break;
				case 2:
					sortEmpleados(listaEmpleados, CANT_EMP);
					printEmpleados(listaEmpleados, CANT_EMP);
					break;
				}

			}
			imprimeMenu();
			break;

		case 5:
			printf("Hasta pronto!");
			break;
		default:
			reintentos--;
			printf("Opcion incorrecta, cantidad de reintentos: %d \n",reintentos);
			imprimeMenu();
			break;
		}

	}while(opcion != 5 && reintentos > 1);
	if(reintentos <= 1)
	{
		printf("Cantidad de reintentos agotada\n");
	}
	return 0;
	}

