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
				imprimeMenu(numeroA,numeroB);
				flag3++;
			}
			else
			{
				printf("No se pueden realizar los calculos sin los 2 operandos \n");
				imprimeMenu(numeroA,numeroB);
			}
			break;
		case 4:
			if(flag3 == 1)
			{
				informarResultados(numeroA,numeroB,resultadoSuma,resultadoResta
							,resultadoMulti,resultadoDivi,factoreoA,factoreoB);
				imprimeMenu(numeroA,numeroB);
			}
			else
			{
				printf("No se pueden informar el resultado si no se realizaron los calculos previamente \n");
				imprimeMenu(numeroA,numeroB);
			}
			break;
		case 5:
			printf("Hasta pronto!");
			break;
		default:
			reintentos--;
			printf("Opcion incorrecta, cantidad de reintentos: %d \n",reintentos);
			imprimeMenu(numeroA,numeroB);
			break;
		}

	}while(opcion != 5 && reintentos > 1);
	if(reintentos == 0)
	{
		printf("Cantidad de reintentos agotada\n");
	}
	return 0;
}

int imprimeMenu(int numeroA, int numeroB)
{
	printf("\n"MSG1_IngreseOperando1,numeroA);
	printf("\n"MSG2_IngreseOperando2,numeroB);
	printf("\n"MSG3_Calculos);
	imprimeMenuCalculos(numeroA,numeroB);
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
	int resultadoSuma = *pResulSuma;
	int resultadoResta = *pResulResta;
	int resultadoMulti = *pResulMulti;
	int resultadoDivi = *pResulDivi;
	int factoreoA = *pFactoreoA;
	int factoreoB = *pFactoreoB;

	sumaDosNumeros(numeroA,numeroB,&resultadoSuma);
	restaDosNumeros(numeroA,numeroB,&resultadoResta);
	multiplicaDosNumeros(numeroA,numeroB,&resultadoMulti);
	if(divideDosNumeros(numeroA,numeroB,&resultadoDivi) == -1)
	{
		printf("No se puede divir por cero, o dividir al cero. Por favor, ingrese otro numero\n");
	}
	factorialDeDosNumeros(numeroA,numeroB,&factoreoA,&factoreoB);

	*pResulSuma = resultadoSuma;
	*pResulResta = resultadoResta;
	*pResulMulti = resultadoMulti;
	*pResulDivi = resultadoDivi;
	*pFactoreoA = factoreoA;
	*pFactoreoB = factoreoB;

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
	int valorA = numeroA;
	int valorB = numeroB;
	int factoreoA = *pFactoreoA;
	int factoreoB = *pFactoreoB;
	if(numeroA <= 0)
	{
		printf("No se puede obtener el factorial de este numero: %d\n",numeroA);
	}
	else
	{
		factorialDelNumero(valorA,&factoreoA);
	}

	if(numeroB <= 0)
	{
		printf("No se puede obtener el factorial de este numero: %d\n",numeroB);
	}
	else
	{
		factorialDelNumero(valorB,&factoreoB);
	}
	return 0;
}
int factorialDelNumero(int numero,int* pFactoreo)
{
	int factorNumero = 1;
	int factorialDeNumero;
	for (factorialDeNumero = 1; factorialDeNumero <= numero; factorialDeNumero++)
	{
		factorNumero = factorNumero * factorialDeNumero;
	}
	*pFactoreo = factorNumero;
	return 0;
}
int informarResultados(int numeroA,int numeroB,int resulSuma,int resulResta,
						int resulMulti,int resulDivi,int factoreoA,int factoreoB)
{
	printf("El resultado de %d+%d es: %d \n",numeroA,numeroB,resulSuma);
	printf("El resultado de %d-%d es: %d \n",numeroA,numeroB,resulResta);
	printf("El resultado de %d*%d es: %d \n",numeroA,numeroB,resulMulti);
	printf("El resultado de %d/%d es: %d \n",numeroA,numeroB,resulDivi);
	printf("El resultado de %d! es: %d, y el de %d es: %d \n",numeroA,factoreoA,numeroB,factoreoB);

	return 0;
}
