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

void imprimirMenu(void);

int main()
{
    int option;
    int flagAdd = 0, flagText = 0, flagBin = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    imprimirMenu();
    do{
    	utn_getInt(&option,"\nIngrese opcion","\nError",1,10,2);
        switch(option)
        {
            case 1:
            	if(flagText==0 && flagBin==0)
            	{
            		if(controller_loadFromText("data.csv",listaEmpleados)==0)
            		{
            			printf("\nCargado en modo Texto con exito");
            			flagText++;
            		}
            		else
            		{
            			printf("\nError al cargar");
            		}
            	}
            	else
            	{
            		printf("\nLa lista ya fue cargada");
            	}
            	imprimirMenu();
                break;

            case 2:
            	if(flagText==0 && flagBin==0)
                {
            		if(controller_loadFromBinary("data_prueba.bin",listaEmpleados)==0)
                    {
                    	printf("\nCargado en modo Binario con exito");
                    	flagBin++;
                    }
                    else
                    {
                    	printf("\nError al cargar");
                    }
               	}
                else
                {
                	printf("\nLa lista ya fue cargada");
                }
            	imprimirMenu();
                break;

            case 3:
            	if(flagText==1 || flagBin==1)
            	{
            		if(controller_addEmployee(listaEmpleados)==0)
            		{
            			printf("\nEmpleado dado de alta");
            			flagAdd++;
            		}
            		else
            		{
            			printf("\nError al dar de alta");
            		}
            	}
            	else
            	{
            		printf("\nTodavia hay informacion que no fue cargada");
            	}
            	imprimirMenu();
                break;

            case 4:
            	if(flagText==1 || flagBin==1 || flagAdd>0)
            	{
            		if(controller_editEmployee(listaEmpleados)==0)
            		{
            			printf("\nEmpleado modificado");
            		}
            		else
            		{
            			printf("\nError al modificar");
            		}
            	}
            	else
            	{
            		printf("\nNo hay datos para modificar");
            	}
            	imprimirMenu();
            	break;

            case 5:
            	if(flagText==1 || flagBin==1 || flagAdd>0)
            	{
            		if(controller_removeEmployee(listaEmpleados)==0)
            		{
            			printf("\nEmpleado dado de baja");
            		}
            		else
            		{
            			printf("\nError al dar de baja");
            		}
            	}
            	else
            	{
            		printf("\nNo hay datos para dar de baja");
            	}
            	imprimirMenu();
            	break;

            case 6:
            	if(flagText==1 || flagBin==1)
            	{
            		controller_ListEmployee(listaEmpleados);
            	}
            	else
            	{
            		printf("\nNo hay datos para listar");
            	}
            	imprimirMenu();
                break;

            case 7:
            	if(flagText==1 || flagBin==1)
            	{
            		controller_sortEmployee(listaEmpleados);
            	}
            	else
            	{
            		printf("\nNo hay datos para ordenar");
            	}
            	imprimirMenu();
                break;

            case 8:
            	if(flagText==1 || flagBin==1)
            	{
            		controller_saveAsText("data_prueba.csv",listaEmpleados);
            	}
            	else
            	{
            		printf("\nNo hay datos para guardar en archivo");
            	}
            	imprimirMenu();
            	break;

            case 9:
            	if(flagText==1 || flagBin==1)
            	{
            		controller_saveAsBinary("data_prueba.bin",listaEmpleados);
            	}
            	else
            	{
            		printf("\nNo hay datos para guardar en archivo");
            	}
            	imprimirMenu();
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
