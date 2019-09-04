#ifndef UTN_TP_H_
#define UTN_TP_H_

#define MSG1_IngreseOperando1 "1.Ingrese operando 1(A = %d)"
#define MSG2_IngreseOperando2 "2.Ingrese operando 2(B = %d)"
#define MSG3_Calculos "3.Calcular todas las operaciones"
#define MSG4_InformarResultados "4.Informar resultados"
#define MSG5_Salir "5.Salir"

#define MSGa_MenuCalculoSuma "a.Suma dos numeros (%d + %d)"
#define MSGb_MenuCalculoResta "b.Resta dos numeros (%d - %d)"
#define MSGc_MenuCalculoMulti "c.Multiplica dos numeros (%d * %d)"
#define MSGd_MenuCalculoDivi "d.Divide dos numeros (%d / %d)"
#define MSGe_MenuCalculoFacto "e.Factorial de dos numeros (%d! y %d!)"

int Calculadora(void);
// funcion principal

int imprimeMenu(int numeroA, int numeroB);
// funcion que imprime el primer menu de opciones

int imprimeMenuCalculos(int numeroA,int numeroB);
// funcion que imprime

int getNumero(int *pNumero);
// funcion que obtiene el numero del usuario

int realizarCalculos(int numeroA,int numeroB,int* pResulSuma,int* pResulResta,
					int* pResulMulti,float* pResulDivi,int* pFactoreoA,int* pFactoreoB);
// funcion que realiza los calculos correspondientes para la calculadora

int sumaDosNumeros(int numeroA,int numeroB,int* pResultado);
// funcion que suma dos numeros

int restaDosNumeros(int numeroA,int numeroB,int* pResultado);
//funcion que resta dos numeros

int multiplicaDosNumeros(int numeroA,int numeroB,int* pResultado);
// funcion que multiplica dos numeros

int divideDosNumeros(int numeroA,int numeroB,float* pResultado);
// funcion que divide dos numeros

int factorialDeDosNumeros(int numeroA,int numeroB,int* pFactoreoA,int* pFactoreoB);
//funcion que ejecuta la funcion "factorialDelNumero()" con dos valores distintos

int factorialDelNumero(int numero,int* pFactoreo);
//funcion que obtiene el factorial de un numero

int informarResultados(int numeroA,int numeroB,int resulSuma,int resulResta,
						int resulMulti,float resulDivi,int factoreoA,int factoreoB);
//funcion que informa el resultado de todos los resultados


#endif /* UTN_TP_H_ */
