#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utn-tp.h"

int main(void)
{
	int opcion;
	int reintentos = 3;
	int numeroA;
	int numeroB;
	int resultado;
	int factoreoA;
	int factoreoB;

	imprimeMenu();
	do
	{
		__fpurge(stdin);
		scanf("%d",&opcion);
		switch(opcion)
		{
		case 1:
			if(getNumero(&numeroA)==0)
			{
				printf("Operando 1: %d",numeroA);
			}
			else
			{
				reintentos = 0;
				printf("Finalizado por cantidad de reintentos agotada");
			}
			break;
		case 2:
			if(getNumero(&numeroB)==0)
			{
				printf("Operando 1: %d",numeroA);
			}
			else
			{
				reintentos = 0;
				printf("Finalizado por cantidad de reintentos agotada");
			}
			break;
	/*	case 3:
			//funcion
			break;
		case 4:
			//funcion
			break;
		case 5:
			//funcion
			break;  */
		default:
			reintentos--;
			printf("Opcion incorrecta, cantidad de reintentos: %d",reintentos);
		}

	}while(opcion != 5 && reintentos > 0);
	printf("Finalizado");
}
