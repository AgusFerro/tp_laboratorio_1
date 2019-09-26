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
		fflush(stdin);
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

int getChar(char* resultado,char* msg, char* msgError, int min, int max, int reintentos)
{
    int retorno=-1;
    char bufferChar[0];

    if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {	printf("%s", msg);
        	fflush(stdin);
			fgets(bufferChar, sizeof(bufferChar), stdin);
			bufferChar[strlen(bufferChar)-1]='\0';
        	if(esChar(bufferChar)==1)
            {
               printf("OK");
               *resultado=bufferChar[0];
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
		fflush(stdin);
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
		fflush(stdin);
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

