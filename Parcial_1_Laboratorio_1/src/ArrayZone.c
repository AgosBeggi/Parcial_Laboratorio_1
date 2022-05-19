/*
 * ArrayZone.c
 *
 *  Created on: 14 may. 2022
 *      Author: A. Beggi
 */

#include "ArrayZone.h"

//INICIALIZACIÓN
int idZone(){

	static int id = 3000;
	id++;
	return  id;
}

int initZone(Zone* list, int len){

	int retorno = -1;//FALSE
	Zone aux;

	if(list !=NULL && len > 0){
		aux.isEmpty = EMPTY;
		aux.idCensista = EMPTY;
		aux.location = EMPTY;
		aux.virtualForm = EMPTY;
		aux.paperForm = EMPTY;
		aux.absent = EMPTY;
		aux.totalAdd = EMPTY;
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
int addZone(Zone* list, int len, int id, int location){

	int retorno = -1;//FALSE
		int index;
		Zone aux;

		if(list != NULL && len > 0 && id != -1 && location != -1){

			index = findZoneEmpty(list, len);
			aux.id = id;
			aux.location = location;
			aux.state = PENDIENTE;
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

//ASIGNAR
int assignCensistaToZone(Zone* list, int len, int id_Censista, int id_Location, int index){

	int retorno = -1;//FALSE

	if(list != NULL && len > 0 && id_Censista != -1 && id_Location != -1){
		for(int i = 0; i < len; i++){
			if(i == index){
				list[i].idCensista = id_Censista;
				list[i].location = id_Location;
				retorno = 0;//TRUE
			}
		}
	}
	return retorno;
}

int addDataZone(Zone* list, int len, int id, int virtualForm, int paperForm, int absent, int totalAdd){

	int retorno = -1;//FALSE
	int index;

	if(list != NULL && len > 0 && id != -1){

		index = findZoneById(list, len, id);

		for(int i = 0; i < len; i++){
			if(list[i].idCensista != EMPTY && i == index){
				list[i].virtualForm = virtualForm;
				list[i].paperForm = paperForm;
				list[i].absent = absent;
				list[i].totalAdd = totalAdd;
				list[i].state = FINALIZADO;
				retorno = 0;//TRUE
			}
		}
	}
	return retorno;
}

//BUSQUEDA
int findZoneById(Zone* list, int len, int id){

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

int findZoneIndexById(Zone* list, int len, int id, int* index){

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

int findZoneEmpty(Zone* list, int len){

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

int findZoneByLocation(Zone* list, int len, int location){

	int index = -1;//RETURNS AN ILLOGICAL VALUE

	if(list !=NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].location == location){
				index = i;//RETURN POSITION	OF THE LOCATION FOUND
				break;
			}
		}
	}
	return index;
}

int findZoneByState(Zone* list, int len,int state){

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

int findZoneByCensista(Zone* list, int len,int idCensista){

	int index = -1;//RETURNS AN ILLOGICAL VALUE

	if(list !=NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].idCensista == idCensista){
				index = i;//RETURN POSITION	OF CENSUS ID FOUND
				break;
			}
		}
	}
	return index;
}

int findIdZoneByLocation(Zone* list, int len, int location){

	int index = -1;//RETURNS AN ILLOGICAL VALUE

	if(list !=NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].location == location){
				index = list[i].id;//RETURN POSITION	OF THE LOCATION FOUND
				break;
			}
		}
	}
	return index;
}

//SUPRIMIR
int removeZone(Zone* list, int len, int id){

	int retorno = -1;//FALSE
	int index;

	if(list !=NULL && len > 0 && id != -1){
		index = findZoneById(list, len, id);
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
int sortZone(Zone* list, int len, int order){

	int retorno = -1;
	int i;
	int isOrdered;
	Zone aux;

	if (list != NULL && len > 0 && order != -1){
		switch(order){
			case 1:
				do {
					isOrdered = 1;
					len--;
					for (i = 0; i < len; i++) {
						if (list[i].state > list[i + 1].state &&
							list[i].location > list[i + 1].location){
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
								list[i].location < list[i + 1].location){
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
int modifyZoneCensista(Zone* list, int len, int id, int idCensista){

	int retorno = -1;//FALSE
	int index;

	if(list !=NULL && len > 0 && id != -1 && idCensista != -1){
		index = findZoneById(list, len, id);
		for(int i = 0; i < len; i++){
			if(i == index){
				list[i].idCensista = idCensista;
				retorno = 0;//TRUE
				break;
			}
		}
	}
	return retorno;
}

int modifyZoneLocation(Zone* list, int len, int id, int location){

	int retorno = -1;//FALSE
	int index;

	if(list !=NULL && len > 0 && id != -1 && location != -1){
		index = findZoneById(list, len, id);
		for(int i = 0; i < len; i++){
			if(i == index){
				list[i].location = location;
				retorno = 0;//TRUE
				break;
			}
		}
	}
	return retorno;
}

int modifyZoneState(Zone* list, int len, int id, int state){

	int retorno = -1;//FALSE
	int index;

	if(list !=NULL && len > 0 && id != -1 && state != -1){
		index = findZoneById(list, len, id);
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

int modifyZoneVirtualForm(Zone* list, int len, int id, int virtualForm){

	int retorno = -1;//FALSE
	int index;

	if(list !=NULL && len > 0 && id != -1 && virtualForm != -1){
		index = findZoneById(list, len, id);
		for(int i = 0; i < len; i++){
			if(i == index){
				list[i].virtualForm = virtualForm;
				retorno = 0;//TRUE
				break;
			}
		}
	}
	return retorno;
}

int modifyZonePaperForm(Zone* list, int len, int id, int paperForm){

	int retorno = -1;//FALSE
	int index;

	if(list !=NULL && len > 0 && id != -1 && paperForm != -1){
		index = findZoneById(list, len, id);
		for(int i = 0; i < len; i++){
			if(i == index){
				list[i].paperForm = paperForm;
				retorno = 0;//TRUE
				break;
			}
		}
	}
	return retorno;
}

int modifyZoneAbsent(Zone* list, int len, int id, int absent){

	int retorno = -1;//FALSE
	int index;

	if(list !=NULL && len > 0 && id != -1 && absent != -1){
		index = findZoneById(list, len, id);
		for(int i = 0; i < len; i++){
			if(i == index){
				list[i].absent = absent;
				retorno = 0;//TRUE
				break;
			}
		}
	}
	return retorno;
}

//CALCULAR
int totalZone(Zone* list, int len){

	int auxPaper = 0;
	int auxVirtual = 0;
	int auxAbsent = 0;
	int total = 0;

	if(list !=NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].paperForm > 0){
				auxPaper = auxPaper + list[i].paperForm;
			}
			if(list[i].virtualForm > 0){
				auxVirtual = auxVirtual + list[i].virtualForm;
			}
			if(list[i].absent > 0){
				auxAbsent = auxAbsent + list[i].absent;
			}
		}
		total = auxPaper + auxVirtual + auxAbsent;
	}
	return total;
}

int totalZoneUnfinished(Zone* list, int len){

	int aux = 0;

	if(list !=NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].state == PENDIENTE){
				aux ++;
			}
		}
	}
	return aux;
}

int totalZoneFinished(Zone* list, int len){

	int aux = 0;

	if(list !=NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].state == FINALIZADO){
				aux ++;
			}
		}
	}
	return aux;
}

int totalAssignZone(Zone* list, int len){

	int assign = 0;

	if(list !=NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].idCensista != EMPTY){
				assign ++;
			}
		}
	}
	return assign;
}

int totalUnallocatedZone(Zone* list, int len){

	int unallocated = 0;

	if(list !=NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].idCensista == EMPTY){
				unallocated ++;
			}
		}
	}
	return unallocated;
}

//PROMEDIOS
float percentageVirtualZone(Zone* list, int len){

	int total = 0;
	int aux = 0;
	float percentage;

	if(list !=NULL && len > 0){
		total = totalZone(list, len);
		for(int i = 0; i < len; i++){
			if(list[i].paperForm > 0){
				aux = aux + list[i].virtualForm;
			}
		}
		percentage = total / (float)aux;
	}
	return percentage;
}

float percentagePaperZone(Zone* list, int len){

	int aux = 0;
	int total = 0;
	float percentage;

	if(list !=NULL && len > 0){
		total = totalZone(list, len);
		for(int i = 0; i < len; i++){
			if(list[i].paperForm > 0 ){
				aux = aux + list[i].paperForm;
			}
		}
		percentage = total / (float)aux;
	}
	return percentage;
}

float percentageAbsentZone(Zone* list, int len){

	int aux = 0;
	int total = 0;
	float percentage;

	if(list !=NULL && len > 0){
		for(int i = 0; i < len; i++){
			total = totalZone(list, len);
			if(list[i].absent > 0 ){
				aux = aux + list[i].absent;
			}
		}
		percentage = total / (float)aux;
	}
	return percentage;
}

//MOSTRAR
//int printZoneList(Zone* list, int len){
//
//	int retorno = -1;//FALSE
//
//	if(list !=NULL && len > 0){
//		for(int i = 0; i < len; i++){
//			if(list[i].isEmpty == FULL){
//				printZone(list[i]);
//				retorno = 0;//TRUE
//			}
//		}
//	}
//	return retorno;
//}
//
//int printZone(Zone zone){
//
//	int retorno = -1;//FALSE
//
//	if(zone.isEmpty == FULL){
//
//		if(zone.location == EMPTY){//no puede existir
//			printf("%d \t%-7s \t%-7s  \t%-7s \t%-7s \t%-7s \t%-7s %s \t%-7d  \t%-7d   \t%-7d  \tPENDIENTE\n",
//			zone.id, zone.location, zone.idCensista, zone.paperForm, zone.virtualForm, zone.absent, zone.totalAdd);
//		}
//		if(zone.idCensista == EMPTY){
//					printf("%d \t%-7s \t%-7s  \t%-7s \t%-7s \t%-7s \t%-7s %s \t%-7d  \t%-7d   \t%-7d  \tPENDIENTE\n",
//					zone.id, zone.location, zone.idCensista, zone.paperForm, zone.virtualForm, zone.absent, zone.totalAdd);
//				}
//		switch(zone.state){
//		case PENDIENTE:
//			printf("%d \t%-7s \t%-7s  \t%-7s \t%-7s \t%-7s \t%-7s %s \t%-7d  \t%-7d   \t%-7d  \tPENDIENTE\n",
//			zone.id, zone.location, zone.idCensista, zone.paperForm, zone.virtualForm, zone.absent, zone.totalAdd);
//			break;
//		case FINALIZADO:
//			printf("%d \t%-7s \t%-7s  \t%-7s \t%-7s \t%-7s \t%-7s %s \t%d  \t%-7d   \t%-7d  \tPENDIENTE\n",
//					zone.id, zone.location, zone.idCensista, zone.paperForm, zone.virtualForm, zone.absent, zone.totalAdd);
//			break;
//		}
//
//		retorno = 0;//TRUE
//	}
//	return retorno;
//}

//INFORMES
