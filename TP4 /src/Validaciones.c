#include "Validaciones.h"

int isValidName(char* stringRecibido)
{
    int retorno=0;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {

        if(stringRecibido[i]<'A' || (stringRecibido[i]>'Z' && stringRecibido[i]<'a') || stringRecibido[i]>'z')// o ((stringRecibido[i]<'A' || (stringRecibido[i]>'Z') && (stringRecibido[i]<'a' || stringRecibido[i]>'z'))
        {
            retorno=-1;
            break;
        }
    }
    return retorno;
}

int isValidNumber(char* stringRecibido,int limite)
{
	int retorno = -1;
		int i;
		if(stringRecibido != NULL && limite > 0)
		{
			for(i=0;i<limite;i++)
			{
				if(stringRecibido[i]>='0' && stringRecibido[i]<='9')
				{
					retorno = 0;
				}
				else
				{
					retorno = -1;
					break;
				}
			}

		}

    return retorno;
}

int isValidFloatNumber(char* stringRecibido, int limite)
{
    int retorno=0;
    int i;
    for(i=0;i<limite;i++)
    {
        if((stringRecibido[i]<'0' || stringRecibido[i]>'9') && (stringRecibido[i]!='.'))
        {
            retorno=-1;
            break;
        }
    }
    return retorno;
}

int isValidCUIT(char* stringRecibido)
{
    int retorno=0;
    int i;
    char buffer[14];
    strncpy(buffer,stringRecibido,14);

    for(i=0;buffer[i]!='\0';i++)
    {
        if(buffer[i]!='-' && (i == 2 || i == 11))
        {
        	retorno=-1;
        	break;
        }

        if((buffer[i]<'0' || buffer[i]>'9') && (i > 2 && i < 11))
        {
            retorno=-2;
            break;
        }

        if((buffer[i]<'0' || buffer[i]>'9') && i==12)
		{
        	retorno=-3;
        	break;
		}
    }

    return retorno;
}

/*int isValidEmail(char* stringRecibido)
{
    int retorno=0;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'-' && stringRecibido[i]!='+') || (stringRecibido[i]>'9' && stringRecibido[i]<'@') ||
           (stringRecibido[i]>'Z' && stringRecibido[i]!='_' && stringRecibido[i]<'a')|| stringRecibido[i]>'z')
        {
            retorno=-1;
            break;
        }
    }
    return retorno;
}*/

/*int isValidTexto(char* stringRecibido)
{
    int retorno=0;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if(stringRecibido[i]<' ' || stringRecibido[i]>'z')
        {
            retorno=-1;
            break;
        }
    }
    return retorno;
}*/

/*int isValidAlphanumeric(char* stringRecibido)
{
    int retorno=0;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if(stringRecibido[i]<'0' || (stringRecibido[i]>'9' && stringRecibido[i]<'A') || (stringRecibido[i]>'Z' && stringRecibido[i]<'a') || stringRecibido[i]>'z' )
        {
            retorno=-1;
            break;
        }
    }
    return retorno;
}*/

int isValidChar(char charRecibido)
{
    int retorno=0;
    if(charRecibido<'A' || (charRecibido>'Z' && charRecibido<'a') || charRecibido>'z')
        retorno=-1;
    return retorno;
}
