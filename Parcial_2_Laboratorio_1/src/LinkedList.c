#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void){

    LinkedList* this = (LinkedList*)malloc(sizeof(LinkedList*));
    if(this != NULL){
    	this->pFirstNode = NULL;
    	this->size = 0;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this){

    int returnAux = -1;

    if(this != NULL){
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
static Node* getNode(LinkedList* this, int nodeIndex){

	Node* pNode = NULL;

	if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this)){
		pNode = this->pFirstNode;
		for(int i = 0; i < nodeIndex; i++){
			pNode = pNode->pNextNode;
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
Node* test_getNode(LinkedList* this, int nodeIndex){
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
static int addNode(LinkedList* this, int nodeIndex,void* pElement){

	int returnAux = -1;
    Node* pAddNode = NULL;
    Node* pAuxNode = NULL;

	if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this)){
		pAddNode = (Node*)malloc(sizeof(Node*));
		if(pAddNode != NULL){
			pAddNode->pNextNode = NULL;
			if(nodeIndex == 0){
				pAddNode->pNextNode = this->pFirstNode;
				this->pFirstNode = pAddNode;
				pAddNode->pElement = pElement;
				this->size++;
				returnAux = 0;
			}else{
				pAuxNode = getNode(this, nodeIndex-1);
				if(pAuxNode != NULL){
					pAddNode->pNextNode = pAuxNode->pNextNode;
					pAuxNode->pNextNode = pAddNode;
					pAddNode->pElement = pElement;
					this->size++;
					returnAux = 0;
				}
			}
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
int test_addNode(LinkedList* this, int nodeIndex,void* pElement){
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement){

	int returnAux = -1;

	if(this != NULL){
		returnAux = addNode(this, ll_len(this), pElement);
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
void* ll_get(LinkedList* this, int index){

    void* returnAux = NULL;
    Node* auxNode = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this)){
    	auxNode = getNode(this, index);
    	if(auxNode != NULL){
    		returnAux = auxNode->pElement;
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
int ll_set(LinkedList* this, int index,void* pElement){

	int returnAux = -1;
	Node* auxNode = NULL;

   if(this != NULL && index >= 0 && index < ll_len(this)){
		auxNode = getNode(this, index);
		if(auxNode != NULL){
			auxNode->pElement = pElement;
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
int ll_remove(LinkedList* this,int index){

    int returnAux = -1;
	Node* pAuxNode = NULL;
	Node* pAuxPreNode = NULL;

	if(this != NULL && index >= 0 && index < ll_len(this)){
		pAuxNode = getNode(this, index);
		if(pAuxNode != NULL){
			if(index == 0){
				this->pFirstNode = pAuxNode->pNextNode;
			}else{
				pAuxPreNode = getNode(this, index-1);
				if(pAuxPreNode != NULL){
					pAuxPreNode->pNextNode = pAuxNode->pNextNode;
				}
			}
			this->size--;
			free(pAuxNode);
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
int ll_clear(LinkedList* this){

    int returnAux = -1;
    int len;

    if(this != NULL){
    	len = ll_len(this);
    	if(len > 0){
    		for(int i = 0; i < len; i++){
    			ll_remove(this, i);
    		}
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
int ll_deleteLinkedList(LinkedList* this){

	int returnAux = -1;

	if(this != NULL && ll_clear(this) == 0){
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
int ll_indexOf(LinkedList* this, void* pElement){

    int returnAux = -1;
    int len;

    if(this != NULL){
    	len = ll_len(this);
    	for(int i = 0; i < len; i++){
    		if(ll_get(this, i) == pElement){
    			returnAux = i;
    			break;
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
int ll_isEmpty(LinkedList* this){

    int returnAux = -1;

    if(this != NULL){
    	if(ll_len(this) > 0){
    		returnAux = 0;
    	}else{
    		returnAux = 1;
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
int ll_push(LinkedList* this, int index, void* pElement){

    int returnAux = -1;

    if(this != NULL && index >= 0 && index <= ll_len(this)){
    	returnAux = addNode(this, index, pElement);
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
void* ll_pop(LinkedList* this,int index){

    void* returnAux = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this)){
    	returnAux = ll_get(this, index);
    	ll_remove(this, index);
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
int ll_contains(LinkedList* this, void* pElement){

    int returnAux = -1;

    if(this != NULL){
    	if(ll_indexOf(this, pElement) != -1){
    		returnAux = 1;
    	}else{
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
int ll_containsAll(LinkedList* this,LinkedList* this2){

	int returnAux = -1;
	void* auxElement;

	if(this != NULL && this2 != NULL){
		returnAux = 1;
		for(int i = 0; i < ll_len(this2); i++){
			auxElement = ll_get(this2, i);
			if(ll_contains(this, auxElement) == 0){
				returnAux = 0;
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
LinkedList* ll_subList(LinkedList* this,int from,int to){

    LinkedList* subList = NULL;
    void* auxElement = NULL;

    if(this != NULL && from >= 0 &&  from < ll_len(this) && to > from && to <= ll_len(this)){
    	subList = ll_newLinkedList();
    	if(subList != NULL){
    		for(int i = from; i < to; i++){
    			auxElement = ll_get(this, i);
    			ll_add(subList, auxElement);
    		}
    	}
    }
    return subList;
}


/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this){

    LinkedList* clone = NULL;

    if(this != NULL){
    	clone = ll_subList(this, 0, ll_len(this));
    }
    return clone;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * retorna <0 si el primero es mayor, 0 si son iguales y >0 si el segundo mayor
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order){

    int returnAux =-1;
    int itsOk;
    int len;
    void* auxElement = NULL;
    void* auxElement2 = NULL;

    if(this != NULL && (order == 0 || order == 1) && pFunc != NULL){
    	len = ll_len(this);
    	do {
    		itsOk = 1;
			len--;
			for (int i = 0; i < len; i++) {
				auxElement = ll_get(this, i);
				auxElement2 = ll_get(this, i+1);
				if ((order == 1 && pFunc(auxElement, auxElement2) > 0) || (order == 0 && pFunc(auxElement, auxElement2) < 0)){
					ll_set(this, i, auxElement2);
					ll_set(this, i+1, auxElement);
					itsOk = 0;
				}
			}
		} while (itsOk == 0);
    	returnAux = 0;
	}
    return returnAux;
}

int ll_count(LinkedList* this, int (*fn)(void*)){

	int returnAux = -1;
	int count = 0;
	void* auxElement = NULL;

	 if(this != NULL && fn != NULL){
		 for(int i = 0; i < ll_len(this); i++){
			 auxElement = ll_get(this, i);
<<<<<<< HEAD
			 if(auxElement != NULL){
				  returnAux = fn(auxElement);
				 if(returnAux > 0){
					 count++;
				 }
=======
			 returnAux = fn(auxElement);
			 if(returnAux > 0){
				 count = count + returnAux;
>>>>>>> dfe91bc242991b2de07f0ddcbc0b775246c50bca
			 }
		 }
	 }
	 return count;
}

int LibroMostrarLibroMinotauro(eLibro* this,LinkedList* pArrayListEditorials)
{
	Editorial* editorialName;
	int id;
	char title [MAX_CHAR];
	char author [MAX_CHAR];
	float price;
	int editorialId;
	char editorial[MAX_CHAR];
	int state;

<<<<<<< HEAD
	LinkedList* list = NULL;
	void* auxElement = NULL;

	if(this != NULL && fn != NULL){
		list = ll_newLinkedList();
		if(list != NULL){
			for(int i = 0; i < ll_len(this); i++){
			auxElement = ll_get(this, i);
				if(fn(auxElement) == 1){
					ll_add(list, auxElement);
				}
			}
		}
	}
	return list;
}

LinkedList* ll_map(LinkedList* this, void* (*fn)(void*)){

	LinkedList* list = NULL;
	void* auxElement= NULL;

	if(this != NULL && fn != NULL){
		list = ll_newLinkedList();
		if(list != NULL){
			for(int i = 0; i < ll_len(this);i++){
				auxElement = ll_get(this,i);
				if(auxElement != NULL){
					auxElement = fn(auxElement);
					ll_add(list, auxElement);
				}
			}
=======
	state = -1;

	LibroGetID(this, &id);
	LibroGetTitulo(this, title);
	LibroGetAutor(this, author);
	LibroGetPrecio(this, &price);
	LibroGetIdEditorial(this, &editorialId);
	editorialName = bringEditorials(pArrayListEditorials, editorialId);
	EDI_getEditorialName(editorialName, editorial);

	printf("\t\t\t|%4d  |%30s   | %22s         |   %9.2f  |    %18s   |\n",id,title,author,price,editorial);

	state = -1;

	return state;
}


int LibroMostrarListaMinotauro(LinkedList* minotaurosBooks, LinkedList* pArrayListEditorials)
{
	eLibro* aux;
	int state;
	int booksQty;

	state = -1;

	if(minotaurosBooks != NULL)
	{
		booksQty = ll_len(minotaurosBooks);

		printf("\n\n\t\t\t|  ID  |              Title              |             Author             |    Price     |         Editorial       |\n");
		printf("\t\t\t|______|_________________________________|________________________________|______________|_________________________|\n");

		for(int i = 0; i < booksQty; i++)
		{
			aux = ll_get(minotaurosBooks, i);

			LibroMostrarLibroMinotauro(aux,pArrayListEditorials);
>>>>>>> dfe91bc242991b2de07f0ddcbc0b775246c50bca
		}
		state = 0;
	}

	return state;
}

int libros_Contados(void* unLibro){
	int isOk;
	eLibro* auxiliarLibro;
	float precio;

	isOk = 0;

	if(unLibro != NULL)
	{
		auxiliarLibro = (eLibro*)unLibro;

		if(!LibroGetPrecio(auxiliarLibro, &precio))
		{
			if(precio > 500)
			{
				isOk = 1;
				puts("libro +");

			}
		}
	}

	return isOk;
}

int ll_filter(LinkedList* this, int (*pFunc)(void*)){

	int i;
	void* pAuxiliar;
	int retornoFuncionCriterio;
	int retorno = -1;

	if(this != NULL && pFunc != NULL)
	{
		for(i = ll_len(this)-1; i >= 0; i--)
		{
			pAuxiliar = ll_get(this, i);
			retornoFuncionCriterio = pFunc(pAuxiliar);
			if(!retornoFuncionCriterio)
			{
				retorno = ll_remove(this, i);
			}
		}
	}
	return retorno;
}

LinkedList* ll_filter(LinkedList* this,int (*pfunc)(void*))
{
  //retorna una lista
  //itera el objeto para filtrar por medio de la funcion pasada como parametro
  LinkedList* aux = NULL;
  void* element = NULL;
  int i;
  int tam;

  if(this!=NULL)
    {
      aux = ll_newLinkedList();
      tam = ll_len(this);
      if(aux!=NULL)
	{
	  for(i=0;i<tam;i++)
	    {
	      element = ll_get(this,i);
	      if(pfunc(element)==1)
		{
		  ll_add(aux,element);
		}
	    }
	}
    }
  return aux;
}

LinkedList* ll_filter(LinkedList* this, int (*fn)(void* element))
{
	LinkedList* Aux;
	int catcher;
	LinkedList* minotaurosBook;

	minotaurosBook = ll_newLinkedList();

	if(this != NULL)
	{
		for(int i = 0; i < ll_len(this); i++)
		{
			Aux = ll_get(this,i);
			catcher = fn(Aux);

			if(catcher == 1)
			{
				ll_add(minotaurosBook, Aux);

			}
		}
	}

	return minotaurosBook;
}

int controllerMinotauroFiltro (LinkedList* booksList, LinkedList* editorialsList)
{
	int state;
	LinkedList* minotaurosBookList;

	state = -1;

	if(booksList != NULL && editorialsList != NULL)
	{
	  minotaurosBookList = ll_filter(booksList,EDI_criterio);
	  if(minotaurosBookList != NULL)
	  {
		  LibroMostrarListaMinotauro(minotaurosBookList, editorialsList);
		  controllerGuardarComoTexto("LibrosEditorialMinotauro.csv", minotaurosBookList, editorialsList);
	  }
	  state = 0;
	}

	return state;
}

int librosFiltrarPearson(void* unLibro)
{
	int isOk;
	eLibro* auxiliarLibro;
	int idEditorial;
	float precioLibro;
	int acumulador=0;

	isOk = 0;

	if(unLibro != NULL)
	{
		auxiliarLibro = (eLibro*)unLibro;

		if(!LibroGetIdEditorial(auxiliarLibro, &idEditorial))
		{
			if(idEditorial == 3 && !LibroGetPrecio(auxiliarLibro, &precioLibro))
			{
				acumulador += precioLibro;
				puts("Acumule un libro pearson");
				isOk = 1;
			}
		}

		printf("el acumulador es : %f", acumulador);
	}



	return isOk;
}


int ll_map(LinkedList* this, int(*pFunc)(void*)){

	int retorno = -1;
	void* pAuxiliar;

	if(this != NULL && pFunc != NULL)
	{
		for(int i = 0; i < ll_len(this); i++)
		{
			pAuxiliar = ll_get(this, i);
			if(!pFunc(pAuxiliar))
			{
				retorno = 0;
			}
		}
	}
	return retorno;
}

LinkedList* ll_map(LinkedList* this, void* (*pFunc)(void*))
{
  LinkedList* Aux = NULL;
  void* element= NULL;
  int i;
  int tam = ll_len(this);
    if(this!=NULL && tam>0 )
      {
	Aux = ll_newLinkedList();
	if(Aux!=NULL)
	  {
	    for(i=0;i<tam;i++)
	      {
		element = ll_get(this,i);
		  if(element!=NULL)
		    {
		      element = pFunc(element);
		      ll_add(Aux,element);
		    }
	      }
	  }
      }
    return Aux;
}

int ll_map(LinkedList* this, int (*fn)(void* element))
{
	void* catcher;
	int state;

	state = -1;

	if(this != NULL)
	{
		for(int i = 0; i < ll_len(this); i++)
		{
			catcher = ll_get(this,i);
			if(fn(catcher)==0)
			{
				state = 0;
			}
		}
	}

	return state;
}

int controllerGuardarMapeoTexto(char* path , LinkedList* pArrayListBooks, LinkedList* pArrayListEditorialsList)
{
	int state;
	FILE* pFile;

	state = -1;

	if(path != NULL && pArrayListBooks != NULL)
	{
		pFile = fopen(path,"w");

		if(pFile != NULL)
		{
			parserGuardarComoMap(pFile, pArrayListBooks,pArrayListEditorialsList);
			state = 0;
		}
			fclose(pFile);
	}

	return state;
}

int controllerLlamarMapeado(LinkedList* pArrayListBooks, LinkedList* pArrayListEditorialsList)
{
	int state;

	state = -1;

	if(pArrayListBooks != NULL && pArrayListEditorialsList != NULL)
	{
		 ll_map(pArrayListBooks, EDIBOOKPRICE_criterio);
		 controllerGuardarMapeoTexto("mapeado.csv", pArrayListBooks, pArrayListEditorialsList);
		 state = 0;
	}

	return state;
}

LinkedList* ll_map(LinkedList* this, void* (pFunc)(void*))
{
	int i;
	int len;
    void* pElement;
    LinkedList* mapeado = NULL;

    if(this!=NULL && pFunc!=NULL)
    {
        mapeado = ll_newLinkedList();
        len=ll_len(this);

        for (i = 0; i < len; i++)
        {
            pElement = ll_get(this, i);//busco todos los elementos de la linkedlist
            pElement = pFunc(pElement);//se los paso a mi funcion

            if(pElement!=NULL)
            {
                ll_add(mapeado, pElement);//los agrego a mi nueva linkedlist
            }
        }
    }

    return mapeado;
}

int controller_mapeadoDescuentos(LinkedList* pArrayListLibro)
{
	int isOk = -1;

	if(pArrayListLibro!=NULL)
	{
		pArrayListLibro=ll_map(pArrayListLibro,libro_descuentos);
		printf("Se ha aplicado el descuento con exito");
		isOk=0;
	}
	return isOk;
}

//---------------------------------------------MAPEO---------------------------------------------
void* libro_descuentos(void* libros)
{
	eLibro* pElement = NULL;
	int auxId;
	float auxPrecio;
	float newPrecio=0;
	char auxNombre[128];

	if(libros!=NULL)
	{
		pElement= (eLibro*) libros;
		if(!libro_getEditorialId(pElement,&auxId))
		{
			BuscarNombreEditorial(auxId,auxNombre);
			if(stricmp(auxNombre,"Planeta")==0)
			{
				libro_getPrecio(pElement,&auxPrecio);
				if(auxPrecio>=300)
				{
					newPrecio=auxPrecio-(auxPrecio*20/100);
					libro_setPrecio(pElement,newPrecio);
				}
			}
			else
			{
				if(stricmp(auxNombre,"SIGLO XXI EDITORES")==0)
				{
					libro_getPrecio(pElement,&auxPrecio);
					if(auxPrecio<=200)
					{
						newPrecio=auxPrecio-(auxPrecio*10/100);
						libro_setPrecio(pElement,newPrecio);
					}
				}
			}
		}
	}

	return pElement;
}
