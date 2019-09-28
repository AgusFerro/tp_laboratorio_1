#ifndef UTN_INPUTS_H_
#define UTN_INPUTS_H_

int getInt(	int *pResultado, char *pMensaje, char *pMensajeError, int minimo, int maximo, int reintentos);
//funcion que pide un dato al usuario y valide que sea del tipo INT
int getChar(char* resultado,char* msg, char* msgError, int reintentos);
//funcion que pide un dato al usuario y valide que sea del tipo CHAR
int getString(char* pMessage,char* pErrMessage, char* pString, int reintentos);
//funcion que pide un dato al usuario y valide que sea del tipo STRING
int getFloat(float *pResultado,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos);
//funcion que pide un dato al usuario y valide que sea del tipo FLOAT

#endif /* UTN_ARRAY_H_ */
