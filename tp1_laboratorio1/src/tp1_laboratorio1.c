#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utn-tp.h"

int opcion;
int reintentos = 3;
int numeroA;
int numeroB;
int resultado;
int factoreoA;
int factoreoB;

int main(void)
{


	imprimeMenu();
	do
	{
		__fpurge(stdin);
		scanf("%d",&opcion);
		switch(opcion)
		{
		case 1:
		/*	if(getNumero()==0){}
			else{} */

			break;
		case 2:
			//funcion
			break;
		case 3:
			//funcion
			break;
		case 4:
			//funcion
			break;
		case 5:
			//funcion
			break;
		}

	}while(opcion != 5 || reintentos == 0);
}
