#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Inputs.h"
#include "Validaciones.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


/*
int f1(int *a, int b,int (*foo)(int,int)) {
	*a = *a * 2;
	*a = foo(*a,b);
	return (*a);
}

int f2(int a, int b) {
	 a = b*b;
	 return a;
}


enum colors {lets,find,course};
int main()
{
	printf("%d %d %d",course,lets,find);
	return 0;
}
*/
void imprimirMenu(void);

int main()
{
    int option;
    char var1[50],var2[50],var3[50],var4[50];
    LinkedList* listaEmpleados = ll_newLinkedList();
    FILE* data = fopen("data.csv","r");

    imprimirMenu();
    do{
    	utn_getInt(&option,"Ingrese opcion","Error",1,10,2);
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 2:
                controller_loadFromBinary("data.csv",listaEmpleados);
                break;
            case 6:
            	controller_ListEmployee(listaEmpleados);
                break;
            case 7:
            	controller_sortEmployee(listaEmpleados);
                break;
            case 9:
            	do{
            	fscanf(data,"%[^,],%[^,],%[^,],%[^\n]",var1,var2,var3,var4);
            	printf("%s %s %s %s",var1,var2,var3,var4);
            	}while(!feof(data));
            	break;
            case 10:
            	printf("salir");
            	break;
        }
    }while(option != 10);

    controller_ListEmployee(listaEmpleados);
    return 0;
}

void imprimirMenu (void)
{
	printf("\nMenu:"
     "\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)."
     "\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)."
     "\n3. Alta de empleado"
     "\n4. Modificar datos de empleado"
     "\n5. Baja de empleado"
     "\n6. Listar empleados"
     "\n7. Ordenar empleados"
     "\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto)."
     "\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario)."
     "\n10. Salir");
}
