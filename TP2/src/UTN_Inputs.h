/*
 * UTN_Inputs.h
 *
 *  Created on: 11 sep. 2019
 *      Author: alumno
 */

#ifndef UTN_INPUTS_H_
#define UTN_INPUTS_H_

int getInt(	int *pResultado, char *pMensaje, char *pMensajeError, int minimo, int maximo, int reintentos);

int getChar(char* resultado,char* msg, char* msgError, int min, int max, int reintentos);

int getString(char* pMessage,char* pErrMessage, char* pString);

int getFloat(float *pResultado,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos);

#endif /* UTN_ARRAY_H_ */
