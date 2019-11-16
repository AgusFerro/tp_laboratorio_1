#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

#include <string.h>

int isValidName(char* stringRecibido);
//valida que el usuario haya ingresado un nombre

int isValidNumber(char* stringRecibido,int limite);
//valida que el usuario haya ingresado un numero

int isValidFloatNumber(char* stringRecibido,int limite);
//valida que el usuario haya ingresado un numero float

int isValidCUIT(char* stringRecibido);
//valida que el usuario haya ingresado un cuit/cuil

int isValidChar(char charRecibido);
//valida que el usuario haya ingresado un caracter

#endif /* VALIDACIONES_H_ */
