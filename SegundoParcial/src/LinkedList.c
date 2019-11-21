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
    LinkedList* this= NULL;
    this = malloc(sizeof(LinkedList));
    this->size=0;
    this->pFirstNode=NULL;
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
    if(this != NULL)
    {
        returnAux = this->size;
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
	int saltos;
	Node* pNodo = NULL;
	if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
	{
		pNodo = this->pFirstNode;
		for(saltos=0;saltos<nodeIndex;saltos++)
		{
			pNodo = pNodo->pNextNode;
		}
	}
    return pNodo;
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
    Node* pNodo;
    Node* pNodoAnterior;

	if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
	{
		pNodo = malloc(sizeof(Node));
		if(pNodo == NULL)
		{
			return -1;
		}
		this->size++;
		pNodo->pElement = pElement;
		if(nodeIndex == 0)
		{
			pNodo->pNextNode = this ->pFirstNode;
			this->pFirstNode = pNodo;
		}
		else
		{
			pNodoAnterior = getNode(this,nodeIndex-1);
			pNodo->pNextNode = pNodoAnterior->pNextNode;
			pNodoAnterior->pNextNode = pNodo;
		}
		returnAux = 0;
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

    if(this != NULL)
    {
    	addNode(this, this->size, pElement);
    	returnAux = 0;
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
    Node* pNodo;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	pNodo = getNode(this,index);
    	if(pNodo != NULL)
    	{
    		returnAux = pNodo->pElement;
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
    Node* pNodo;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	pNodo = getNode(this, index);
    	if(pNodo != NULL)
    	{
    		pNodo->pElement = pElement;
    		returnAux = 0;
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
    Node* pNode;
    Node* pNodeAuxAnt;
    Node* pNodeAuxSig;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	pNode = getNode(this, index);
		{
    		if(index==0)
    		{
    			pNodeAuxSig = getNode(this, index+1);
    			pNode = pNodeAuxSig;
    			this->pFirstNode=pNodeAuxSig;

    		}
    		else if(index>0 && index <= ll_len(this))
    		{
    	    	pNodeAuxAnt = getNode(this, index-1);
    	    	pNodeAuxSig = getNode(this, index+1);
    			pNodeAuxAnt->pNextNode = pNodeAuxSig;
    			free(pNode);
    		}
    		this->size--;
    		returnAux = 0;
		}
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
    int i;

    if(this != NULL)
    {
    	for(i=0;i<ll_len(this);i++)
    	{
    		ll_remove(this,i);
    		returnAux = 0;
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

    if(this != NULL)
    {
    	ll_clear(this);
    	free(this);
    	returnAux = 0;
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
    int i;
    void* pElementAux;

    if(this != NULL)
    {
    	for(i=0;i<ll_len(this);i++)
    	{
    		pElementAux = ll_get(this,i);
    		if(pElement == pElementAux)
    		{
    			returnAux = i;
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

    if(this != NULL)
    {
    	if(ll_len(this)==0)
    	{
    		returnAux = 1;
    	}
    	else
    	{
    		returnAux = 0;
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

    if(this != NULL && index >= 0 && index <= ll_len(this))
    {
    	addNode(this, index, pElement);
    	returnAux = 0;
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

    if(this != NULL && index >= 0 && index <= ll_len(this))
    {
    	returnAux = ll_get(this,index);
    	ll_remove(this,index);
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

    if(this != NULL)
    {
    	if(ll_indexOf(this,pElement) >= 0)
    	{
    		returnAux = 1;
    	}
    	else
    	{
    		returnAux = 0;
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
    void* pElement;

    if(this != NULL && this2 != NULL)
    {

    	if(this2->size == 0)
    	{
        	returnAux=0;
    	}
    	returnAux=1;
    	for(i=0;i<ll_len(this2);i++)
    	{
    		pElement = ll_get(this2,i);
    		if(ll_contains(this,pElement)!=1)
    		{
    			returnAux=0;
    			break;
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
    int i;

    if(this != NULL && from >= 0 && from < to && to <= ll_len(this))
    {
    	cloneArray = ll_newLinkedList();
    	if(cloneArray!=NULL)
    	{
        	for(i=from;i<to;i++)
        	{
        		ll_add(cloneArray,ll_get(this,i));
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

    if(this != NULL)
    {
    	cloneArray = ll_newLinkedList();
    	cloneArray = ll_subList(this,0,ll_len(this));
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1;
	int j;
	int flagNoEstaOrdenadoAsc = 1;
	int flagNoEstaOrdenadoDes = 1;

	void* aux;
	void* pElementUno;
	void* pElementDos;

    if(this != NULL && pFunc != NULL && ll_len(this) > 0 && (order == 1 || order == 0))
    {
        if (order == 1)
        {

       	while (flagNoEstaOrdenadoAsc==1)
          	 {
      			 flagNoEstaOrdenadoAsc = 0;
      			 for (j = 0; j < ll_len(this)-1; j++)
      			 {
      				 pElementUno=ll_get(this,j);
      				 pElementDos=ll_get(this,j+1);
      				 if(pFunc(pElementUno, pElementDos) > 0)
          			{
                       		aux=pElementUno;
                       		pElementUno=ll_set(this,j,pElementDos);
                       		pElementDos=ll_set(this,j+1,aux);
          					flagNoEstaOrdenadoAsc = 1;
          			}
      			}
          	 }
        }
        else
        {

          	while (flagNoEstaOrdenadoDes==1)
             	 {
          		flagNoEstaOrdenadoDes = 0;
         			 for (j = 0; j < ll_len(this)-1; j++)
         			 {
         				 pElementUno=ll_get(this,j);
         				 pElementDos=ll_get(this,j+1);

            				 if(pFunc((pElementUno), (pElementDos)) <0)
            				 {
                            		aux=pElementUno;
                            		ll_set(this,j,pElementDos);
                            		ll_set(this,j+1,aux);
               					flagNoEstaOrdenadoDes = 1;
            				}


         			 }
             	 }
        }
        returnAux = 0;



    }

    return returnAux;

}

/** \brief Modifica un campo del elemento utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */


int ll_map(LinkedList* this, void (*pFunc)(void*))
{
	int returnAux = -1;
	int i;
	void* pElement;

	if(this != NULL && pFunc != NULL && ll_len(this) > 0)
	{
		for(i=0;i<ll_len(this);i++)
		{
			pElement = ll_get(this,i);
			pFunc(pElement);
			returnAux = 0;
		}
	}

	return returnAux;
}

/** \brief Crea una nueva lista con elementos filtrados de una lista base, utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista original
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
 */


LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
	LinkedList* listaFiltrada = NULL;
	int i;
	void* pElement;


	listaFiltrada = ll_newLinkedList();

	if(this != NULL && pFunc != NULL && ll_len(this) > 0 && listaFiltrada != NULL)
	{
		for(i=0;i<ll_len(this);i++)
		{
			pElement = ll_get(this,i);
			if(pFunc(pElement)==1)
			{
				ll_add(listaFiltrada,pElement);
			}
		}
	}

	return listaFiltrada;
}

/** \brief Reduce la lista, dando de baja elementos, utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista original
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (lista modificada) Si ok
 */

LinkedList* ll_reduce(LinkedList* this,int (*pFunc)(void*))
{
	int i;
	void* pElement;

	if(this != NULL && pFunc != NULL && ll_len(this) > 0)
	{
		for(i=0;i<ll_len(this);i++)
		{
			pElement = ll_get(this,i);
			if(pFunc(pElement)==1)
			{
				ll_remove(this,i);
				i--;
			}
		}
	}

	return this;
}
