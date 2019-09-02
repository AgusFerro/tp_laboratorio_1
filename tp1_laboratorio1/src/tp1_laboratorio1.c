#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utn-tp.h"

int main(void)
{
	int opcion;
	int reintentos = 3;
	int flag1 = 0;
	int flag2 = 0;
	int flag3 = 0;
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
			getNumero(&numeroA);
			printf("Operando 1: %d",numeroA);
			flag1++;
			break;
		case 2:
			getNumero(&numeroB);
			printf("Operando 1: %d",numeroA);
			flag2++;
			break;
		case 3:
			if(flag1 == 1 && flag2 == 1)
			{
				realizarCalculos(numeroA,numeroB,&resultado,&factoreoA,&factoreoB);
				flag3++;
			}
			else
			{
				printf("No se pueden realizar los calculos sin los 2 operandos \n");
			}
			break;
		case 4:
			if(flag3 == 1)
			{
				informarResultados();
			}
			else
			{
				printf("No se pueden informar el resultado si no se realizaron los calculos previamente \n");
			}
			break;
		case 5:
			printf("Hasta pronto!");
			break;
		default:
			reintentos--;
			printf("Opcion incorrecta, cantidad de reintentos: %d",reintentos);
			break;
		}

	}while(opcion != 5 && reintentos > 0);
	printf("Finalizado");
}
