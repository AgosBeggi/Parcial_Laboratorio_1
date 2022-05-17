/*
 * ArrayCensista.c
 *
 *  Created on: 14 may. 2022
 *      Author: A. Beggi
 */

#include "ArrayCensista.h"

//INICIALIZACIÓN
int idCensista(){

	static int id = 0;
	id++;
	return  id;
}

int initCensista(Censista* list, int len){

	int retorno = -1;//FALSE
	Censista aux;

	if(list !=NULL && len > 0){
		aux.isEmpty = EMPTY;
		aux.state = INACTIVO;
		aux.zone = EMPTY;
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
int addCensista(Censista* list, int len, int id, char name[],
		char lastName[], Date dateBirth, int age, Address adress){

	int retorno = -1;//FALSE
	int index;
	Censista aux;

	if(list != NULL && len > 0 && id != -1 && name != NULL && lastName != NULL
			/*&& dateBirth != NULL*/ && age != -1 /*&& adress != NULL*/){

		index = findCensistaEmpty(list, len);
		aux.id = id;
		strncpy(aux.name, name, sizeof(aux.name));
		strncpy(aux.lastName, lastName, sizeof(aux.lastName));
		aux.state = LIBERADO;
		aux.dateBirth = dateBirth;
		aux.age = age;
		aux.adress = adress;
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

int assignZoneToCensista(Censista* list, int len, int id_Censista, int zone){

	int retorno = -1;//FALSE
	int index;

	if(list != NULL && len > 0 && id_Censista != -1 && id_Censista != EMPTY){
		index = findCensistaById(list, len, id_Censista);
		for(int i = 0; i < len; i++){
			if(i == index){
				list[i].zone = zone;
				retorno = 0;//TRUE
			}
		}

		retorno = 0;//TRUE
	}
	return retorno;
}

//BUSQUEDA
int findCensistaById(Censista* list, int len, int id){

	int index = -1;//RETURNS AN ILLOGICAL VALUE

	if(list !=NULL && len > 0 && id != -1){
		for(int i = 0; i < len; i++){
			if(list[i].id == id){
				index = i;//RETURNS POSITION OF ID FOUND
				break;
			}
		}
	}
	return index;
}

int findCensistaEmpty(Censista* list, int len){

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

int findCensistaByState(Censista* list, int len, int state){

	int index = -1;//RETURNS AN ILLOGICAL VALUE

	if(list !=NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].state == state){
				index = i;//RETURNS POSITION OF THE FOUND STATE
				break;
			}
		}
	}
	return index;
}

int findCensistaByZone(Censista* list, int len, int zone){
	int index = -1;//RETURNS AN ILLOGICAL VALUE

	if(list !=NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].zone == zone){
				index = i;//RETURN POSITION OF THE ZONE FOUND
				break;
			}
		}
	}
	return index;
}

int findIdCensistaByZone(Censista* list, int len, int zone){
	int index = -1;//RETURNS AN ILLOGICAL VALUE

	if(list !=NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].zone == zone){
				index = list[i].id;//RETURN POSITION OF THE ZONE FOUND
				break;
			}
		}
	}
	return index;
}

//SUPRIMIR
int removeCensista(Censista* list, int len, int id){

	int retorno = -1;//FALSE
	int index;

	if(list !=NULL && len > 0 && id != -1){
		index = findCensistaById(list, len, id);
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

//ORDENAR
int sortCensista(Censista* list, int len, int order){

	int retorno = -1;
	int i;
	int isOrdered;
	Censista aux;

	if (list != NULL && len > 0 && order != -1){
		switch(order){
			case 1:
				do {
					isOrdered = 1;
					len--;
					for (i = 0; i < len; i++) {
						if (list[i].state > list[i + 1].state &&
							strcmp(list[i].lastName, list[i].lastName) < 0){
							aux = list[i];
							list[i] = list[i + 1];
							list[i + 1] = aux;
							isOrdered = 0;
						}
					}
				} while (isOrdered == 0);
				retorno = 0;
				break;
			case 2:
				do {
					isOrdered = 1;
					len--;
					for (i = 0; i < len; i++) {
						if (list[i].state < list[i + 1].state &&
							strcmp(list[i].lastName, list[i].lastName) < 0){
							aux = list[i];
							list[i] = list[i + 1];
							list[i + 1] = aux;
							isOrdered = 0;
						}
					}
				} while (isOrdered == 0);
				retorno = 0;
				break;
		}
	}
	return retorno;
}

//MODIFICACIONES
int modifyCensistaZone(Censista* list, int len, int id, int zone){

	int retorno = -1;//FALSE
	int index;

	if(list !=NULL && len > 0 && id != -1 && zone != -1){
		index = findCensistaById(list, len, id);
		for(int i = 0; i < len; i++){
			if(i == index){
				list[i].zone = zone;
				retorno = 0;//TRUE
				break;
			}
		}
	}
	return retorno;
}

int modifyCensistaName(Censista* list, int len, int id, char Name[]){

	int retorno = -1;//FALSE
	int index;

	if(list !=NULL && len > 0 && id != -1 && Name != NULL){
		index = findCensistaById(list, len, id);
		for(int i = 0; i < len; i++){
			if(i == index){
				strncpy(list[i].lastName, Name, sizeof(list[i].lastName));
				retorno = 0;//TRUE
				break;
			}
		}
	}
	return retorno;
}

int modifyCensistaLastName(Censista* list, int len, int id, char lastName[]){

	int retorno = -1;//FALSE
	int index;

	if(list !=NULL && len > 0 && id != -1 && lastName != NULL){
		index = findCensistaById(list, len, id);
		for(int i = 0; i < len; i++){
			if(i == index){
				strncpy(list[i].lastName, lastName, sizeof(list[i].lastName));
				retorno = 0;//TRUE
				break;
			}
		}
	}
	return retorno;
}

int modifyCensistaState(Censista* list, int len, int id, int state){

	int retorno = -1;//FALSE
	int index;

	if(list !=NULL && len > 0 && id != -1 && state != -1){
		index = findCensistaById(list, len, id);
		for(int i = 0; i < len; i++){
			if(i == index){
				list[i].state = state;
				retorno = 0;//TRUE
				break;
			}
		}
	}
	return retorno;
}

int modifyCensistaAge(Censista* list, int len, int id, int age){

	int retorno = -1;//FALSE
	int index;

	if(list !=NULL && len > 0 && id != -1 && age != -1){
		index = findCensistaById(list, len, id);
		for(int i = 0; i < len; i++){
			if(i == index){
				list[i].age = age;
				retorno = 0;//TRUE
				break;
			}
		}
	}
	return retorno;
}

int modifyCensistaDateBirth(Censista* list, int len, int id, Date dateBirth){

	int retorno = -1;//FALSE
	int index;

	if(list !=NULL && len > 0 && id != -1){
		index = findCensistaById(list, len, id);
		for(int i = 0; i < len; i++){
			if(i == index){
				if(list[i].dateBirth.day != dateBirth.day){
					list[i].dateBirth.day = dateBirth.day;
				}
				if(list[i].dateBirth.month != dateBirth.month){
					list[i].dateBirth.month = dateBirth.month;
				}
				if(list[i].dateBirth.year != dateBirth.year){
					list[i].dateBirth.year = dateBirth.year;
				}
				retorno = 0;//TRUE
				break;
			}
		}
	}
	return retorno;
}

int modifyCensistaAddress(Censista* list, int len, int id, Address adress){

	int retorno = -1;//FALSE
	int index;

	if(list !=NULL && len > 0 && id != -1){
		index = findCensistaById(list, len, id);
		for(int i = 0; i < len; i++){
			if(i == index){
				if(strcmp(list[i].adress.street, adress.street) != 0){
					strncpy(list[i].adress.street, adress.street, sizeof(list[i].adress.street));
				}
				if(list[i].adress.streetNumber != adress.streetNumber){
					list[i].adress.streetNumber = adress.streetNumber;
				}
				if(strcmp(list[i].adress.neighborhood, adress.neighborhood) != 0){
					strncpy(list[i].adress.neighborhood, adress.neighborhood, sizeof(list[i].adress.neighborhood));
				}
				retorno = 0;//TRUE
				break;
			}
		}
	}
	return retorno;
}

//MOSTRAR
int printCensistaList(Censista* list, int len){

	int retorno = -1;//FALSE

	if(list !=NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == FULL && printCensista(list[i]) == 0){
				retorno = 0;//TRUE
			}
		}
	}
	return retorno;
}

int printCensista(Censista censista){

	int retorno = -1;//FALSE

	if(censista.isEmpty == FULL){
		switch(censista.state){
			case ACTIVO:
				printf("%d \t%-7s   \t%-5s \t%d/%d/%d  \t%d \t%-5s %d \t%-5s  \tACTIVO\n",
				censista.id, censista.name, censista.lastName,
				censista.dateBirth.day, censista.dateBirth.month, censista.dateBirth.year,
				censista.age, censista.adress.street, censista.adress.streetNumber, censista.adress.neighborhood);
				break;
			case LIBERADO:
				printf("%d \t%-7s   \t%-5s \t%d/%d/%d  \t%d \t%-5s %d \t%-5s  \tLIBERADO\n",
				censista.id, censista.name, censista.lastName,
				censista.dateBirth.day, censista.dateBirth.month, censista.dateBirth.year,
				censista.age, censista.adress.street, censista.adress.streetNumber, censista.adress.neighborhood);
				break;
			case INACTIVO:
				printf("%d \t%-7s   \t%-5s \t%d/%d/%d  \t%d \t%-5s %d \t%-5s  \tINACTIVO\n",
				censista.id, censista.name, censista.lastName,
				censista.dateBirth.day, censista.dateBirth.month, censista.dateBirth.year,
				censista.age, censista.adress.street, censista.adress.streetNumber, censista.adress.neighborhood);
				break;
		}
		retorno = 0;//TRUE
	}
	return retorno;
}

//INFORMES
