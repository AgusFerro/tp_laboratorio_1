/*
 * UTN_Inputs.c
 *
 *  Created on: 11 sep. 2019
 *      Author: alumno
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "UTN_Inputs.h"
#include "UTN_Validaciones.h"

int getInt(int *pResultado,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	int buffer;
	char input[50];
	int length;
	do
	{
		printf("%s",pMensaje);
		__fpurge(stdin);
		fgets(input,sizeof(input),stdin);
		length = strlen(input);
		length--;
		if(esInt(input,length)==0)
		{
			buffer = atoi(input);
			if(buffer >= minimo && buffer <= maximo)
			{
				*pResultado = buffer;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",pMensajeError);
				reintentos--;
			}

		}
		else
		{
			printf("No es un numero");
			reintentos--;
		};

	}while(reintentos >= 0);
	return retorno;
}

int getChar(char* resultado,char* msg, char* msgError, int reintentos)
{
    int retorno=-1;
    char bufferChar;

    if(msg!=NULL && msgError!=NULL && reintentos>=0 && resultado!=NULL)
    {
        do
        {	printf("%s", msg);
        	__fpurge(stdin);
			scanf("%c",&bufferChar);
        	if(esSoloChar(bufferChar)==1)
            {
               *resultado=bufferChar;
               retorno=0;
               break;
             }
             else
             {
               printf("%s 2",msgError);
               reintentos--;
             }
         }
        while(reintentos>=0);
    }
    return retorno;
}

int getFloat(float *pResultado,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	float buffer;
	char input[50];
	int length;
	do
	{
		printf("%s",pMensaje);
		__fpurge(stdin);
		fgets(input,sizeof(input),stdin);
		length = strlen(input);
		length--;
		if(esFloat(input)==0)
		{
			buffer = atof(input);
			if(buffer >= minimo && buffer <= maximo)
			{
				*pResultado = buffer;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",pMensajeError);
				reintentos--;
			}

		}
		else
		{
			printf("No es un numero");
			reintentos--;
		};

	}while(reintentos >= 0);
	return retorno;
}

int getString(char* pMessage,char* pErrMessage, char* pString)
{
	int retorno = -1;
	char buffer[100];
	if(pMessage != NULL && pErrMessage != NULL)
	{
		printf("%s", pMessage);
		__fpurge(stdin);
		fgets(buffer, sizeof(buffer), stdin);
		buffer[strlen(buffer)-1]='\0';

		if(esChar(buffer)==1)
		{
			strcpy(pString, buffer);
			retorno = 0;
		}else
		{
			printf("%s", pErrMessage);
		}
	}
	return retorno;
}


