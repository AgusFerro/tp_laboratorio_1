#ifndef UTN_TP_H_
#define UTN_TP_H_

#define MSG1_IngreseOperando1 "1.Ingrese operando 1"
#define MSG2_IngreseOperando2 "2.Ingrese operando 2"
#define MSG3_Calculos "3.Calcular todas las operaciones"
#define MSG4_InformarResultados "4.Informar resultados"
#define MSG5_Salir "5.Salir"

int imprimeMenu(void);
int getNumero(int *pNumero);
int realizarCalculos(int numeroA,int numeroB,int* resultado,int* factoreoA,int* factoreoB);
int informarResultados(void);
int imprimeMenuCalculos(void);
int sumaDosNumeros(int numeroA,int numeroB,int* resultado);
int restaDosNumeros(int numeroA,int numeroB,int* resultado);
int multiplicaDosNumeros(int numeroA,int numeroB,int* resultado);
int divideDosNumeros(int numeroA,int numeroB,int* resultado);
int factorialDeDosNumeros(int numeroA,int numeroB,int* factoreoA,int* factoreoB);

#endif /* UTN_TP_H_ */
