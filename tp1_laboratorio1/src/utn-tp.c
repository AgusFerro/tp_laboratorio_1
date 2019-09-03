// >  <
#include <stdio_ext.h>
#include "utn-tp.h"

int Calculadora(void)
{
	int opcion;
	int reintentos = 3;
	int flag1 = 0;
	int flag2 = 0;
	int flag3 = 0;
	int numeroA = 0;
	int numeroB = 0;
	int resultadoSuma;
	int resultadoResta;
	int resultadoMulti;
	int resultadoDivi;
	int factoreoA;
	int factoreoB;

	imprimeMenu(numeroA,numeroB);
	do
	{
		__fpurge(stdin);
		scanf("%d",&opcion);
		switch(opcion)
		{
		case 1:
			getNumero(&numeroA);
			imprimeMenu(numeroA,numeroB);
			flag1++;
			break;
		case 2:
			getNumero(&numeroB);
			imprimeMenu(numeroA,numeroB);
			flag2++;
			break;
		case 3:
			if(flag1 == 1 && flag2 == 1)
			{
				realizarCalculos(numeroA,numeroB,&resultadoSuma,&resultadoResta
							,&resultadoMulti,&resultadoDivi,&factoreoA,&factoreoB);
				flag3++;
			}
			else
			{
				printf("No se pueden realizar los calculos sin los 2 operandos \n");
				imprimeMenu(numeroA,numeroB);
			}
			break;
		/*case 4:
			if(flag3 == 1)
			{
				informarResultados();
			}
			else
			{
				printf("No se pueden informar el resultado si no se realizaron los calculos previamente \n");
				imprimeMenu(numeroA,numeroB);
			}
			break;*/
		case 5:
			printf("Hasta pronto!");
			break;
		default:
			reintentos--;
			printf("Opcion incorrecta, cantidad de reintentos: %d",reintentos);
			imprimeMenu(numeroA,numeroB);
			break;
		}

	}while(opcion != 5 && reintentos > 1);
	if(reintentos == 0)
	{
		printf("Cantidad de reintentos agotada");
	}
	return 0;
}

int imprimeMenu(int numeroA, int numeroB)
{
	printf("\n"MSG1_IngreseOperando1,numeroA);
	printf("\n"MSG2_IngreseOperando2,numeroB);
	printf("\n"MSG3_Calculos);
	printf("\n"MSG4_InformarResultados);
	printf("\n"MSG5_Salir);
	printf("\n");

	return 0;
}

int imprimeMenuCalculos(int numeroA,int numeroB)
{
	printf("\n"MSGa_MenuCalculoSuma,numeroA,numeroB);
	printf("\n"MSGb_MenuCalculoResta,numeroA,numeroB);
	printf("\n"MSGc_MenuCalculoMulti,numeroA,numeroB);
	printf("\n"MSGd_MenuCalculoDivi,numeroA,numeroB);
	printf("\n"MSGe_MenuCalculoFacto,numeroA,numeroB);
	printf("\n");

	return 0;
}

int getNumero(int *pNumero)
{
	int numero = *pNumero;

	printf("\nIngrese algun numero \n");
	__fpurge(stdin);
	scanf("%d",&numero);
	*pNumero = numero;
	return 0;
}

int realizarCalculos(int numeroA,int numeroB,int* pResulSuma,int* pResulResta,
					int* pResulMulti,int* pResulDivi,int* pFactoreoA,int* pFactoreoB)
{
	char opcion;
	int resultadoSuma = *pResulSuma;
	int resultadoResta = *pResulResta;
	int resultadoMulti = *pResulMulti;
	int resultadoDivi = *pResulDivi;
	int factoreoA = *pFactoreoA;
	int factoreoB = *pFactoreoB;

	imprimeMenuCalculos(numeroA,numeroB);

	__fpurge(stdin);
	scanf("%c",&opcion);
	switch(opcion)
	{
		case 'a':
			sumaDosNumeros(numeroA,numeroB,&resultadoSuma);
			break;
		case 'b':
			restaDosNumeros(numeroA,numeroB,&resultadoResta);
			break;
		case 'c':
			multiplicaDosNumeros(numeroA,numeroB,&resultadoMulti);
			break;
		case 'd':
			if(divideDosNumeros(numeroA,numeroB,&resultadoDivi) == -1)
			{
				printf("No se puede divir por cero, o dividir al cero. Por favor, ingrese otro numero");
			}
			break;
		case 'e':
			factorialDeDosNumeros(numeroA,numeroB,&factoreoA,&factoreoB);
			break;
		default:
			printf("Opcion incorrecta");
			break;
			}

	return 0;
}

int sumaDosNumeros(int numeroA,int numeroB,int* pResultado)
{
	int resultado = numeroA + numeroB;

	*pResultado = resultado;
	return 0;
}

int restaDosNumeros(int numeroA,int numeroB,int* pResultado)
{
	int resultado = numeroA - numeroB;

	*pResultado = resultado;
	return 0;
}

int multiplicaDosNumeros(int numeroA,int numeroB,int* pResultado)
{
	int resultado = numeroA * numeroB;

	*pResultado = resultado;
	return 0;
}

int divideDosNumeros(int numeroA,int numeroB,int* pResultado)
{
	if(numeroA == 0 || numeroB == 0)
	{
		return -1;
	}
	else
	{
		int resultado = numeroA / numeroB;
		*pResultado = resultado;
		return 0;
	}
}

int factorialDeDosNumeros(int numeroA,int numeroB,int* pFactoreoA,int* pFactoreoB)
{
	factorialDelNumero(numeroA,&pFactoreoA)
	*pFactoreoA = factoreoA;

	factorialDelNumero(numeroB,&pFactoreoB)
	*pFactoreoB = factoreoB;
	return 0;
}
