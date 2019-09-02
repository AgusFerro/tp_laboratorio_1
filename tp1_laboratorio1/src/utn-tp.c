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
	int numero = *pNumero;

	printf("\nIngrese numero 1 \n");
	__fpurge(stdin);
	scanf("%d",&numero);
	*pNumero = numero;
	return 0;
}

int realizarCalculos(int numeroA,int numeroB,int* resultado,int* factoreoA,int* factoreoB)
{
	char opcion;

	imprimeMenuCalculos();

	__fpurge(stdin);
	scanf("%c",&opcion);
	switch(opcion)
	{
		case 'a':
			//sumaDosNumeros(int numeroA,int numeroB,int* resultado);
			break;
		case 'b':
			//restaDosNumeros(int numeroA,int numeroB,int* resultado);
			break;
		case 'c':
			//multiplicaDosNumeros(int numeroA,int numeroB,int* resultado);
			break;
		case 'd':
			//divideDosNumeros(int numeroA,int numeroB,int* resultado);
				/*if(flag3 == 1)
				{
					informarResultados();
				}
				else
				{
					printf("No se pueden informar el resultado si no se realizaron los calculos previamente \n");
				}*/
			break;
		case 'e':
			//factorialDeDosNumeros(int numeroA,int numeroB,int* factoreoA,int* factoreoB);
			break;
		default:
			printf("Opcion incorrecta");
			break;
			}

	return 0;
}
int sumaDosNumeros(int numeroA,int numeroB,int* resultado)
{
}
int restaDosNumeros(int numeroA,int numeroB,int* resultado)
{
}
int multiplicaDosNumeros(int numeroA,int numeroB,int* resultado)
{
}
int divideDosNumeros(int numeroA,int numeroB,int* resultado)
{
}
int factorialDeDosNumeros(int numeroA,int numeroB,int* factoreoA,int* factoreoB)
{
}
