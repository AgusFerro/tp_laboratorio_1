
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "UTN_Validaciones.h"

int esInt(char *pArray,int limite)
{
	int retorno = -1;
	int i;
	if(pArray != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(pArray[i]>='0' && pArray[i]<='9')
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

int esChar(char* string)
{
	int retorno = 1;
	int i = 0;
	while(string[i] != '\0')
	{
		if((string[i] < 'a' || string[i] > 'z') &&
		   (string[i] < 'A' || string[i] > 'Z') &&
		   (string[i] != ' '))
		{
			retorno = 0;
		}
		i++;
	}
	return retorno;
}

int esFloat(char *pArray)
{
    int retorno=1;
    int i;
    for(i=0;pArray[i]!='\0';i++)
    {
        if((pArray[i]<'0' || pArray[i]>'9') && (pArray[i]!='.'))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}
