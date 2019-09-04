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
#define MSGe_MenuCalculoFacto "e.Factorial de dos numeros (! %d ! %d)"

int Calculadora(void);
int imprimeMenu(int numeroA, int numeroB);
int imprimeMenuCalculos(int numeroA,int numeroB);
int getNumero(int *pNumero);
int realizarCalculos(int numeroA,int numeroB,int* pResulSuma,int* pResulResta,
					int* pResulMulti,int* pResulDivi,int* pFactoreoA,int* pFactoreoB);
int sumaDosNumeros(int numeroA,int numeroB,int* pResultado);
int restaDosNumeros(int numeroA,int numeroB,int* pResultado);
int multiplicaDosNumeros(int numeroA,int numeroB,int* pResultado);
int divideDosNumeros(int numeroA,int numeroB,int* pResultado);
int factorialDeDosNumeros(int numeroA,int numeroB,int* pFactoreoA,int* pFactoreoB);
int factorialDelNumero(int numero,int* pFactoreo);
int informarResultados(int numeroA,int numeroB,int resulSuma,int resulResta,
						int resulMulti,int resulDivi,int factoreoA,int factoreoB);


#endif /* UTN_TP_H_ */
