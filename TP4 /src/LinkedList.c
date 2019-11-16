#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this=(LinkedList *)malloc(sizeof(LinkedList));
    if(this!=NULL)
    {
    	this->size=0;
    	this->pFirstNode=NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
    	returnAux=this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode = NULL;
	int largo = ll_len(this);

	if(this!=NULL && nodeIndex>=0 && nodeIndex<largo)
	{
		if(nodeIndex==0)					//nuevo despues del commit "TP4 %50"
		{
			pNode = this->pFirstNode;
		}
		else
		{
			pNode = this->pFirstNode;
			for(int i=0;i<nodeIndex;i++)
			{
				pNode=pNode->pNextNode;
			}
		}
	}
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    int largo = ll_len(this);
    Node* pAuxPrev = NULL;
    Node* pAuxNew = NULL;

    if(this!=NULL && nodeIndex>=0 && nodeIndex<=largo)
    {
    	pAuxNew=(Node*)malloc(sizeof(Node));
    	pAuxPrev=getNode(this,nodeIndex-1);
    	if(pAuxNew!=NULL)
    	{
    		pAuxNew->pElement=pElement;

    		if(nodeIndex==0)
    		{
    			pAuxNew->pNextNode=this->pFirstNode;
    			this->pFirstNode=pAuxNew;
    		}
    		else
    		{
    			pAuxNew->pNextNode=pAuxPrev->pNextNode;
    			pAuxPrev->pNextNode=pAuxNew;
    		}
    		this->size++;
    		returnAux=0;
    	}
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL && addNode(this,this->size,pElement)==0)
    {
    	returnAux=0;
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNode = NULL;

    if(this!=NULL && index>=0)
    {
    	pNode=getNode(this,index);
    	if(pNode!=NULL)
    	{
    		returnAux=pNode->pElement;
    	}
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    int len=ll_len(this);
    Node* pNode = NULL;

    if(this!=NULL && index>=0 && index<len)// && pElement!=NULL)
    {
    	pNode=getNode(this,index);
    	if(pNode!=NULL)
    	{
    		pNode->pElement=pElement;
    		returnAux=0;
    	}
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    int len=ll_len(this);
    Node* pNodePrev = NULL;
    Node* pNode = NULL;

    if(this!=NULL && index>=0 && index<len)
    {
    	pNode=getNode(this,index);
    	if(index==0)
    	{
    		this->pFirstNode=pNode->pNextNode;
    		free(pNode);
    		this->size--;
    	}
    	else
    	{
    		pNodePrev=getNode(this,index-1);
    		pNodePrev->pNextNode=pNode->pNextNode;
    		free(pNode);
    		this->size--;

    	}
    	returnAux=0;

    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int len=ll_len(this);

    if(this!=NULL)
    {
    	if(this->size==0)
    	{
    		returnAux=0;
    	}
    	else
    	{
    		for(int i=0;i<len;i++)
    		{
    			ll_remove(this,0); //borra siempre la primera posicion hasta vaciarse
    		}
    		returnAux=0;

    		/*for(int i=len-1;i>=0;i--)
    		{
    			ll_remove(this,i); // borra desde el final hasta el principio(menos optimo)
    		}
    		returnAux=0;*/
    	}
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
    	ll_clear(this);
    	free(this);
    	returnAux=0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len=ll_len(this);
    Node* pNode = NULL;

    if(this!=NULL)
    {
    	for(int i=0;i<len;i++)
    	{
    		pNode=getNode(this,i);
    		if(pNode!=NULL)
    		{
    			if(pNode->pElement==pElement)
    			{
    				returnAux=i;
    				break;
    			}
    		}
    	}
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    int len=ll_len(this);

    if(this!=NULL)
    {
    	if(len==0)
    	{
    		returnAux=1;
    	}
    	else
    	{
    		returnAux=0;
    	}
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int len=ll_len(this);

    if(this!=NULL && index>=0 && index<=len)
    {
    	if(addNode(this,index,pElement)==0)
    	{
    		returnAux=0;
    	}
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    int len=ll_len(this);
    Node* pNodePrev = NULL;
    Node* pNode = NULL;

    if(this!=NULL && index>=0 && index<len)
    {
    	pNode=getNode(this,index);
    	if(index==0)
    	{
    		returnAux=pNode->pElement;
    		this->pFirstNode=pNode->pNextNode;
    		free(pNode);
    		this->size--;
    	}
    	else
    	{
    		returnAux=pNode->pElement;
    		pNodePrev=getNode(this,index-1);
    		pNodePrev->pNextNode=pNode->pNextNode;
    		free(pNode);
    		this->size--;
    	}
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL)
    {
    	if(ll_indexOf(this,pElement)==-1)
   		{
   			returnAux=0;
   		}
    	else
   		{
   			returnAux=1;
   		}
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i;
    int len=ll_len(this),len2=ll_len(this2);
    void* aux;

    if(this!=NULL && this2!=NULL)
    {
    	if(len<len2)
    	{
    		returnAux=0;
    	}
    	else
    	{
    		if(this==this2)
    		{
    			returnAux=1;
    		}
    		else
    		{
    			for(i=0;i<len2;i++)
    			{
    				aux=ll_get(this2,i);
    				if(ll_contains(this,aux)==0)
    				{
    					i--;
    					break;
    				}
    			}
    			if(i==len2)
    			{
    				returnAux=1;
    			}
    			else
    			{
    				returnAux=0;
    			}
    		}
    	}
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    Node* pNode = NULL;
    int i,j;
    int len=ll_len(this);

    if(this!=NULL && from>=0 && to>from && len>=to)
    {
    	cloneArray=malloc(sizeof(LinkedList));
    	if(cloneArray!=NULL)
    	{
    		for(i=from,j=0;i<to;i++,j++)
    		{
    			pNode=getNode(this,i);
    			if(pNode!=NULL)
    			{
    				addNode(cloneArray,j,pNode->pElement);
    			}
    		}
    	}
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int len=ll_len(this);

    if(this!=NULL)
    {
    	cloneArray=ll_subList(this,0,len);
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param this LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int len=ll_len(this);
    int flag;
    void* aux;
    Node* pNode;
    Node* pNextNode;

    if(this!=NULL && (order==1 || order==0) && pFunc!=NULL && len>0)
    {
        do
        {
                flag=0;
                pNode=this->pFirstNode;
                if(pNode!=NULL)
                {
                pNextNode=pNode->pNextNode;
                    for(int i=0;i<(len-1);i++)
                    {
                        if((pFunc(pNode->pElement,pNextNode->pElement)==1 && order) ||
                            (pFunc(pNode->pElement,pNextNode->pElement)==-1 && !order))
                        {
                            aux=pNode->pElement;
                            pNode->pElement=pNextNode->pElement;
                            pNextNode->pElement=aux;
                            flag=1;
                        }
                        if(pNextNode->pNextNode!=NULL)
                        {
                            pNode=pNextNode;
                        }
                        else
                        {
                            break;
                        }
                        pNextNode=pNode->pNextNode;
                    }
                }
            }while(flag==1);
            returnAux=0;
        }
    return returnAux;
}


int ll_map(LinkedList* this, int (*pFunc)(void*))
{
	int returnAux=-1;
	int len=ll_len(this);

	if(this!=NULL && pFunc!= NULL)
	{
		for(int i=0;i<len;i++)
		{
			if(em_calcularSueldo(ll_get(this,i))==0)
			{
				returnAux=0;
			}
			else
			{
				returnAux=-1;
				break;
			}
		}

	}

	return returnAux;
}

LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*), int orden)
{
	LinkedList* returnAux= NULL;
	int len=ll_len(this);
	LinkedList* filterList = NULL;
	void* aux = NULL;

	if(this!=NULL && (orden==1 || orden==0) && pFunc!=NULL && len>0)
	{
		filterList = ll_newLinkedList();
		if(filterList!=NULL)
		{
			for(int i=0;i<len;i++)
			{
				aux=ll_get(this,i);
				if((pFunc(aux)==1 && orden==1) ||
				   (pFunc(aux)==-1 && orden==0))
				{
					ll_add(filterList,aux);
				}
			}
			returnAux=filterList;
		}
	}

	return returnAux;
}

/*
int em_calcularSueldo(void* p)
{
	int returnAux=-1;
	int horas;
	int sueldo;

	if(p!=NULL)
	{
		employee_getHorasTrabajadas(p,&horas);
		if(horas<=120)
		{
			sueldo=horas*180;
		}
		else if(horas>120 && horas<=160)
		{
			horas=horas-120;
			sueldo=(horas*240)+(120*180);
		}
		else if(horas>160)
		{
			horas=horas-160;
			sueldo=(horas*350)+(40*240)+(120*180);
		}

		if(employee_setSueldo(p,sueldo)==0)
		{
			returnAux=0;
		}
	}
	// recibo elemento empleado como void.
	// hacer calculo de sueldo y escribirlo en campo sueldo del empleado
	return returnAux;
}

int criterioSueldo(void* p)
{
    int sueldo;
    int orden=0;

    employee_getSueldo(p,&sueldo);
    if(sueldo>30000)
    {
    	orden=1;
    }

    return orden;
}
*/
