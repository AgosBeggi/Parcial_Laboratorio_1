/*
 * ArrayDate.c
 *
 *  Created on: 14 may. 2022
 *      Author: A. Beggi
 */

#include "ArrayDate.h"

//INICIALIZACIÓN
int initDate(Date* list, int len){

	int retorno = -1;//FALSE
	Date aux;

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
int addDate(Date* list, int len, int idElement, int day, int month, int year, int index){

	int retorno = -1;//FALSE
	Date aux;

	if(list != NULL && len > 0 && idElement != -1 && day != -1 && month != -1 && year != -1){

		aux.idElement = idElement;
		aux.day = day;
		aux.month = month;
		aux.year = year;
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
int findDateEmpty(Date* list, int len){

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

int findDateByIdElement(Date* list, int len, int idElement){

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

//SUPRIMIR
int removeDate(Date* list, int len, int id){

	int retorno = -1;//FALSE
	int index;

	if(list !=NULL && len > 0 && id != -1){
		index = findDateByIdElement(list, len, id);
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

//MODIFICACIONES
int modifyDateDay(Date* list, int len, int idElement, int day){

	int retorno = -1;//FALSE

	if(list != NULL && len > 0 && idElement != -1 && day != -1){

		for(int i = 0; i < len; i++){
			if(list[i].idElement == idElement){
				list[i].day = day;
				retorno = 0;//TRUE
			}
		}
	}
	return retorno;
}

int modifyDateMonth(Date* list, int len, int idElement, int month){

	int retorno = -1;//FALSE

	if(list != NULL && len > 0 && idElement != -1 && month != -1){

		for(int i = 0; i < len; i++){
			if(list[i].idElement == idElement){
				list[i].month = month;
				retorno = 0;//TRUE
			}
		}
	}
	return retorno;
}

int modifyDateYear(Date* list, int len, int idElement, int year){

	int retorno = -1;//FALSE

	if(list != NULL && len > 0 && idElement != -1 && year != -1){

		for(int i = 0; i < len; i++){
			if(list[i].idElement == idElement){
				list[i].year = year;
				retorno = 0;//TRUE
			}
		}
	}
	return retorno;
}
