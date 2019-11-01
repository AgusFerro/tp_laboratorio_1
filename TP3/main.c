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
    LinkedList* listaEmpleados = ll_newLinkedList();

    imprimirMenu();
    do{
    	utn_getInt(&option,"\nIngrese opcion","\nError",1,10,2);
        switch(option)
        {
            case 1:
                if(controller_loadFromText("data.csv",listaEmpleados)==0)
                {
                	printf("\nCargado con exito");
                }
                else
                {
                	printf("\nError al cargar");
                }
                break;

            case 2:
                if(controller_loadFromBinary("data.csv",listaEmpleados)==0)
                {
                	printf("\nCargado con exito");
                }
                else
                {
                	printf("\nError al cargar");
                }
                break;
            case 3:
                if(controller_addEmployee(listaEmpleados)==0)
                {
                	printf("\nEmpleado dado de alta");
                }
                else
                {
                	printf("\nError al dar de alta");
                }
                break;
            case 4:
                if(controller_editEmployee(listaEmpleados)==0)
                {
                	printf("\nEmpleado modificado");
                }
                else
                {
                	printf("\nError al dar de alta");
                }
            	break;
            case 6:
            	controller_ListEmployee(listaEmpleados);
                break;
            case 7:
            	controller_sortEmployee(listaEmpleados);
                break;
            case 9:
            	break;
            case 10:
            	printf("\nSalir");
            	break;
        }
    }while(option != 10);

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
