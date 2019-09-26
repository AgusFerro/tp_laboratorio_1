#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"

int main(void)
{
	int opcion,submenu,indice,j;
	int reintentos = 3;
	int ID, contadorID = 0, flag1 = 0;
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
			addEmpleados(listaEmpleados,cantEmpleados,&ID);
			imprimeMenu();
			break;

		case 2:
			removeEmpleados(listaEmpleados, cantEmpleados);
			imprimeMenu();
			break;

		case 3:
			empleado_modificar(listaEmpleados,cantEmpleados);
			imprimeMenu();
			break;

		case 4:
			empleado_ordenarPorDobleCriterio(listaEmpleados, cantEmpleados);
			printEmpleados(listaEmpleados, cantEmpleados);
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

