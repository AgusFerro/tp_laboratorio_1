// >  <
#include <stdio_ext.h>
#include "utn-tp.h"

int imprimeMenu(void)
{
	printf("\n"MSG1_IngreseOperando1);
	printf("\n"MSG2_IngreseOperando2);
	printf("\n"MSG3_Calculos);
	printf("\n"MSG4_InformarResultados);
	printf("\n"MSG5_Salir);
	printf("\n");

	return 0;
}

int getNumero(int *pNumero)
{
	int maximo = 99;
	int minimo = 1;
	int reintentos = 3;
	int numero = *pNumero;

	printf("\nIngrese numero 1 \n");
	__fpurge(stdin);
	scanf("%d",&numero);
	while(!(numero <= maximo && numero >= minimo) && reintentos > 0)
	{
		reintentos--;
		printf("Reingrese el numero, cantidad de reintentos: %d \n",reintentos);
		__fpurge(stdin);
		scanf("%d",&numero);
	}
	if(reintentos == 0)
	{
		return -1;
	}
	else
	{
		*pNumero = numero;
		return 0;
	}
}

