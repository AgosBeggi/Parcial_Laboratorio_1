/*
 * ArrayLocation.c
 *
 *  Created on: 15 may. 2022
 *      Author: A. Beggi
 */

#include "ArrayLocation.h"

//INICIALIZACIÓN
int idLocation(){

	static int id = 0;
	id++;
	return  id;
}

int initLocation(Location* listLocation, int lenLocation){

	int retorno = -1;//FALSE
	Location aux;

	if(listLocation !=NULL && lenLocation > 0){
		aux.isEmpty = EMPTY;
		for(int i = 0; i < lenLocation; i++){
			listLocation[i] = aux;
			if(listLocation[i].isEmpty == EMPTY){
				retorno = 0;//TRUE
			}
		}
	}
	return retorno;
}

//AGREGAR
int addLocation(Location* listLocation, int lenLocation, char name[], char street_1[],
				char street_2[], char street_3[], char street_4[], int id){

	int retorno = -1;//FALSE
	int index;
	Location aux;

	if(listLocation != NULL && lenLocation > 0){

		index = findLocationEmpty(listLocation, lenLocation);
		aux.id = id;
		strncpy(aux.name, name, sizeof(aux.name));
		strncpy(aux.street_1, street_1, sizeof(aux.street_1));
		strncpy(aux.street_2, street_2, sizeof(aux.street_2));
		strncpy(aux.street_3, street_3, sizeof(aux.street_3));
		strncpy(aux.street_4, street_4, sizeof(aux.street_4));
		aux.state = SIN_ASIGNAR;
		aux.isEmpty = FULL;

		for(int i = 0; i < lenLocation; i++){
			if(i == index){
				listLocation[i] = aux;
				retorno = 0;//TRUE
			}
		}
	}
	return retorno;
}

int addLocationZone(Location* listLocation, int lenLocation, int id_Location, int id_Zone){

	int retorno = -1;//FALSE
	int index;

	if(listLocation != NULL && lenLocation > 0 && id_Location > 0 && id_Zone > 0){
		if(findLocationById(listLocation, lenLocation, id_Location, &index) == 0){
			for(int i = 0; i < lenLocation; i++){
				if(i == index){
					listLocation[i].id_Zone = id_Zone;
					listLocation[i].state = ASIGNADO;
					retorno = 0;//TRUE
				}
			}
		}
	}
	return retorno;
}

//BUSQUEDA
int findLocationEmpty(Location* listLocation, int lenLocation){

	int index = -1;//RETURNS AN ILLOGICAL VALUE

	if(listLocation !=NULL && lenLocation > 0){
		for(int i = 0; i < lenLocation; i++){
			if(listLocation[i].isEmpty == EMPTY){
				index = i;//RETURNS FIRST POSITION EMPTY
				break;
			}
		}
	}
	return index;
}

int findLocationById(Location* list, int len, int id, int* index){

	int retorno = -1;//RETURNS AN ILLOGICAL VALUE

	if(list !=NULL && len > 0 && id != -1){
		for(int i = 0; i < len; i++){
			if(list[i].id == id){
				*index = i;//RETURNS POSITION OF ID FOUND
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int findLocationIndexByIdZone(Location* list, int len, int id_zone, int* index){

	int retorno = -1;//RETURNS AN ILLOGICAL VALUE

	if(list !=NULL && len > 0 && id_zone != -1){
		for(int i = 0; i < len; i++){
			if(list[i].id_Zone == id_zone){
				*index = i;//RETURNS POSITION OF ID FOUND
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int findLocationByZone(Location* list, int len, int id_Zone){

	int index = -1;//RETURNS AN ILLOGICAL VALUE

	if(list !=NULL && len > 0 && id_Zone != -1){
		for(int i = 0; i < len; i++){
			if(list[i].id_Zone == id_Zone){
				index = i;//RETURNS POSITION OF ID FOUND
				break;
			}
		}
	}
	return index;
}

//MOSTRAR
int printLocationList(Location* listLocation, int lenLocation){
	int retorno = -1;//FALSE


		if(listLocation !=NULL && lenLocation){
			for(int i = 0; i < lenLocation; i++){
				if(listLocation[i].isEmpty == FULL){
					printLocation(listLocation[i]);
					retorno = 0;//TRUE
				}
			}
		}
		return retorno;
}

int printLocation(Location location){
	int retorno = -1;//FALSE

		if(location.isEmpty == FULL){
			switch(location.state){
			case SIN_ASIGNAR:
				printf("%d \t|%-15s \t|%-15s  \t|%-15s \t|%-15s \t|%-15s	|SIN ASIGNAR\n",
				location.id, location.name, location.street_1, location.street_2, location.street_3, location.street_4);
				break;
			case ASIGNADO:
				printf("%d \t|%-15s \t|%-15s  \t|%-15s \t|%-15s \t|%-15s	|ASIGNADO\n",
				location.id, location.name, location.street_1, location.street_2, location.street_3, location.street_4);
				break;
			case TERMINADO:
				break;
			}
		retorno = 0;//TRUE
		}
	return retorno;
}













