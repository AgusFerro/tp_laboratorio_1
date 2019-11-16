#ifndef INPUTS_H_
#define INPUTS_H_

#include "Validaciones.h"

int getString(char* msg, char* msgError, int min, int max, int reintentos, char* resultado);
//pide al usuario que ingrese un texto

int utn_getName(char* msg,char* msgError,int min,int max,int reintentos,char* resultado);
//pide al usuario que ingrese un nombre

int utn_getInt(int *pResultado,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos);
//pide al usuario que ingrese un numero

int utn_getFloat(float *pResultado,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos);
//pide al usuario que ingrese un numero float

int utn_getCUIT(char* msg, char* msgError, int reintentos, char* input);
//pide al usuario que ingrese un cuit/cuil

int utn_getChar(char* msg, char* msgError, int min, int max, int reintentos, char* resultado);
//pide al usuario que ingrese un caracter

#endif
