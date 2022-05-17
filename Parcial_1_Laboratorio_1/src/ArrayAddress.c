/*
 * ArrayAddress.c
 *
 *  Created on: 14 may. 2022
 *      Author: A. Beggi
 */

#include "ArrayAddress.h"

//INICIALIZACIÓN
int initAddress(Address* list, int len){

	int retorno = -1;//FALSE
	Address aux;

	if(list !=NULL && len > 0){
		aux.isEmpty = EMPTY;
		for(int i = 0; i < len; i++){
			list[i] = aux;
			if(list[i].isEmpty == EMPTY){
				retorno = 0;//TRUE
			}
		}
	}
	return retorno;
}

//AGREGAR
int addAddress(Address* list, int len, int id, char street[], int streetNumber, char neighborhood[], int index){

	int retorno = -1;//FALSE
	Address aux;

	if(list != NULL && len > 0 && id != -1 && street != NULL &&
			streetNumber != -1 && neighborhood != NULL && index != -1){

		aux.idElement = id;
		strncpy(aux.street, street, sizeof(aux.street));
		aux.streetNumber = streetNumber;
		strncpy(aux.neighborhood, neighborhood, sizeof(aux.neighborhood));
		aux.isEmpty = FULL;

		for(int i = 0; i < len; i++){
			if(i == index){
				list[i] = aux;
				retorno = 0;//TRUE
			}
		}
	}
	return retorno;
}

//BUSQUEDA
int findAddressEmpty(Address* list, int len){

	int index = -1;//RETURNS AN ILLOGICAL VALUE

	if(list !=NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == EMPTY){
				index = i;//RETURNS FIRST POSITION EMPTY
				break;
			}
		}
	}
	return index;
}

int findAddressByIdElement(Address* list, int len, int idElement){

	int index = -1;//RETURNS AN ILLOGICAL VALUE

	if(list !=NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].idElement == idElement){
				index = i;//RETURNS POSITION OF ID ELEMENT FOUND
				break;
			}
		}
	}
	return index;
}

//MODIFICACIONES
int modifyAddressStreet(Address* list, int len, int idElement, char street[]){

	int retorno = -1;//FALSE

	if(list != NULL && len > 0 && idElement != -1 && street != NULL){

		for(int i = 0; i < len; i++){
			if(list[i].idElement == idElement){
				strncpy(list[i].street, street, sizeof(list[i].street));
				retorno = 0;//TRUE
			}
		}
	}
	return retorno;
}

//SUPRIMIR
int removeAddress(Address* list, int len, int id){

	int retorno = -1;//FALSE
	int index;

	if(list !=NULL && len > 0 && id != -1){
		index = findAddressByIdElement(list, len, id);
		for(int i = 0; i < len; i++){
			if(i == index){
				list[i].isEmpty = EMPTY;
				retorno = 0;//TRUE
				break;
			}
		}
	}
	return retorno;
}

int modifyAddressStreetNumber(Address* list, int len, int idElement, int streetNumber){

	int retorno = -1;//FALSE

	if(list != NULL && len > 0 && idElement != -1 && streetNumber != -1){

		for(int i = 0; i < len; i++){
			if(list[i].idElement == idElement){
				list[i].streetNumber = streetNumber;
				retorno = 0;//TRUE
			}
		}
	}
	return retorno;
}

int modifyAddressNeighborhood(Address* list, int len, int idElement, char neighborhood[]){

	int retorno = -1;//FALSE

	if(list != NULL && len > 0 && idElement != -1 && neighborhood != NULL){

		for(int i = 0; i < len; i++){
			if(list[i].idElement == idElement){
				strncpy(list[i].neighborhood, neighborhood, sizeof(list[i].neighborhood));
				retorno = 0;//TRUE
			}
		}
	}
	return retorno;
}
