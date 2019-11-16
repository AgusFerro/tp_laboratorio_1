#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"

/*
getString
utn_getName
utn_getInt
utn_getFloat
utn_getChar
*/

int getString(char* msg, char* msgError, int min, int max, int reintentos, char* resultado)
{
    int retorno=-1;
    char bufferStr[max+10];

    if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            printf("%s",msg);
            __fpurge(stdin);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1]='\0';

            if(strlen(bufferStr)>=min && strlen(bufferStr)<max)
            {
                strncpy(resultado,bufferStr,max);
                retorno=0;
                break;
            }
            printf("%s 1",msgError);
            reintentos--;
        }
        while(reintentos>=0);
    }
    return retorno;
}
//------------------------------
int utn_getName(char* msg, char* msgError, int min, int max, int reintentos, char* resultado)
{
    int retorno=-1;
    char bufferStr[max];

    if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,min,max,reintentos,bufferStr)) //==0
            {
                if(isValidName(bufferStr)==0)
                {
                    strncpy(resultado,bufferStr,max);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}


//-----------------------------------------
int utn_getInt(int *pResultado,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos)
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
		if(isValidNumber(input,length)==0)
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

int utn_getFloat(float *pResultado,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos)
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
		if(isValidFloatNumber(input,length)==0)
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
//***************************************
int utn_getCUIT(char* msg, char* msgError, int reintentos, char* input)
{
    int maxSize=14;
    int minSize=12;
    int retorno=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,minSize,maxSize,reintentos,bufferStr))
            {
            	if(isValidCUIT(bufferStr)==0)
                {
                    strncpy(input,bufferStr,maxSize);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int utn_getChar(char* msg, char* msgError, int min, int max, int reintentos, char* resultado)
{
    int retorno=-1;
    char bufferChar[256];

    if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,1,3,reintentos,bufferChar))
            {
                if(isValidChar(bufferChar[0])==0)
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
        }
        while(reintentos>=0);
    }
    return retorno;
}




