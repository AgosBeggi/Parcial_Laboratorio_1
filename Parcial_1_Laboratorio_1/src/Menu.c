/*
 * Menu.c
 *
 *  Created on: 16 may. 2022
 *      Author: A. Beggi
 */

#include "Menu.h"

//INICIALIZACIÓN
int startMenu(Censista* listCensista, int lenCensista, Zone* listZone, int lenZone){

	int retorno = -1;//FALSE

	if(listCensista != NULL && lenCensista > 0 && listZone !=NULL && lenZone > 0){
		if(initCensista(listCensista, lenCensista) == 0 && initZone(listZone, lenZone) == 0){
			retorno = 0;//TRUE
		}
	}
	return retorno;
}

int hardcodeAddDataMenu(Censista* listCensista, int lenCensista, Date* listDate, int lenDate, Address* listAddress, int lenAddress,
		Zone* listZone, int lenZone, Location* listLocation, int lenLocation){

	int retorno = -1;//FALSE
	int flag = -1;
	int control = 0;
	int j = 0;
	int index;

	char name[10][150]={"LOURDES IVANA", "HERNAN FACUNDO", "SILVIA ELIZABETH", "BRIAN EMANUEL", "GIULIANA", "IARA ANABELA", "ALOMA MAGALI", "MARIANO JAVIER", "ALEXIS JAVIER", "NICOLAS AGUSTIN"};
	char lastName[10][150]={"CALDERON", "IANELLO", "GONZALEZ", "MONTOYA", "OCAMPO", "PANCERA", "TABORDA", "TORRE", "VANDEVENDES", "ZAMUDIO"};
	int age[10]={25,24,24,23,23,25,24,22,25,25};

	int day[10]={10,2,2,26,23,30,29,7,17,25};
	int month[10]={10,9,2,4,6,10,7,5,12,2};
	int year[10]={1997,1998,1998,1999,1999,1997,1998,2000,1997,1997};

	char street[10][150]={"CORRIENTES", "NECOCHEA", "MORENO", "CASEROS", "ALVEAR", "MAIPU", "3 DE FEBRERO", "9 DE JULIO", "SAENZ PEÑA", "CORDOBA"};
	int streetNumber[10]={4624,387,15,7772,5004,337,459,27,536,789};
	char neighborhood[10][150]={"LINIERS","CABALLITO", "VILLA DEVOTO", "SAN NICOLAS", "RETIRO", "CONSTITUCION", "FLORESTA", "CHACARITA", "BARRACAS", "BOEDO"};



	char nameLocation[10][150]={"MERCEDES", "CHASCOMUS", "LOBOS", "SAAVEDRA", "ESCOBAR", "LA PLATA", "LUJAN", "QUILMES", "RAMALLO", "PILAR"};
	char street_1[10][150]={"C. 104", "LIBRES DEL SUR", "AJO", "AV. GARCIA DEL RIO", "CORDOBA", "C. 45", "GRAL. PAZ", "ALEM", "OBLIGADO", "CATAMARCA"};
	char street_2[10][150]={"C. 106", "CASEROS", "CHACABUCO", "AV. MELIAN", "FELIPE BOERO", "C. 14", "GRAL. LAS HERAS", "MORENO", "LAGRAVE", "ALSINA"};
	char street_3[10][150]={"C. 13", "ALVEAR", "BARRACAS", "MANZANERAS", "BOLIVIA", "C. 46", "RAWSON", "GARIBALDI", "COLON", "HIPOLITO YRIGOYEN"};
	char street_4[10][150]={"C. 15", "MAIPU", "LUIS LACOSTE", "WASHINGTON", "PATRICIAS MENDOCINAS", "C. 15", "ITUZAINGO", "LAVALLE", "TUCUMAN", "AMILCAR LUBO"};

	if(listCensista != NULL && lenCensista > 0 && listDate !=NULL && lenDate > 0 && listAddress !=NULL && lenAddress > 0
			&& listZone !=NULL && lenZone > 0 && listLocation !=NULL && lenLocation > 0){
		for(; control < 10; control++){
			if(singUpCensistaMenu(listCensista, lenCensista, name[j], lastName[j], age[j],
					day[j], month[j], year[j], street[j], streetNumber[j], neighborhood[j],
					listDate, lenDate, listAddress, lenAddress) &&
			singUpZoneMenu(listZone, lenZone, nameLocation[j], street_1[j], street_2[j],
					street_3[j], street_4[j], listLocation, lenLocation)){

				flag = 0;//TRUE
			}
			j++;
		}
		if(flag == 0){
			index = findLocationEmpty(listLocation, lenLocation);
			index = index-1;
			if(hardcodeAssignDataMenu(listCensista, lenCensista, lenAddress,
			listZone, lenZone, listLocation, lenLocation, index)){
				retorno = 0;
			}
		}

	}
	return retorno;
}

int hardcodeAssignDataMenu(Censista* listCensista, int lenCensista, int lenAddress,
		Zone* listZone, int lenZone, Location* listLocation, int lenLocation, int index){

	int retorno = -1;//FALSE
	int control = 0;
	int j = 0;

	int id_Censista;
	int id_Zone;

	int virtualForm[10]={2,5,0,9,1,3,7,1,2,6};
	int paperForm[10]={1,0,2,0,3,2,4,0,6,7};
	int absent[10]={0,0,1,0,3,2,0,1,5,2};
	int total[10]={3,5,3,9,7,7,11,6,13,15};

	if(listCensista != NULL && lenCensista > 0 && lenAddress > 0
				&& listZone !=NULL && lenZone > 0 && listLocation !=NULL && lenLocation > 0){

		for(; control < 10; control++){
			id_Zone = findIdZoneByLocation(listZone, lenZone, index);
			id_Censista = findIdCensistaByZone(listCensista, lenCensista, id_Zone);
			for(int i = 0; i < lenLocation; i++){
				if(assignZoneMenu(listZone, lenZone, listCensista, lenCensista, id_Censista, listLocation, lenLocation, index)){
					addDataMenu(listZone, lenZone, id_Zone, virtualForm[j], paperForm[j], absent[j], total[j]);
					retorno = 0;//TRUE
				}
			}
			j++;
			index--;
		}
	}
	return retorno;
}

//AGREGAR
int singUpCensistaMenu(Censista* listCensista, int lenCensista,	char name[], char lastName[], int age, int day, int month, int year,
		char street[], int streetNumber, char neighborhood[], Date* listDate, int lenDate, Address* listAddress, int lenAddress){

	int retorno = -1;//FALSE
	int id;
	int indexAddress;
	int indexDate;

	if(listCensista != NULL && lenCensista > 0 && name != NULL && lastName != NULL && age > 0
			&& day > 0 && month > 0 && year > 0
			&& street != NULL && streetNumber > 0 && neighborhood != NULL
			&& listDate != NULL && lenDate > 0
			&& listAddress != NULL && lenAddress > 0){
		id = idCensista();

		indexAddress = findAddressEmpty(listAddress, lenAddress);
		indexDate = findDateEmpty(listDate, lenDate);

		addDate(listDate, lenDate, id, day, month, year, indexDate);
		addAddress(listAddress, lenAddress, id, street, streetNumber, neighborhood, indexAddress);

		if(addCensista(listCensista, lenCensista, id, name, lastName, listDate[indexDate], age, listAddress[indexAddress])){
			retorno = 0;//TRUE
		}
	}
	return retorno;
}

int singUpZoneMenu(Zone* listZone, int lenZone,	char nameLocation[], char street_1[], char street_2[],
		char street_3[], char street_4[], Location* listLocation, int lenLocation){

	int retorno = -1;//FALSE
	int id;
	int id_Location;

	if(listZone != NULL && lenZone > 0 && nameLocation != NULL && street_1 != NULL
			&& street_2 != NULL && street_3 != NULL  && street_4 != NULL
			&& listLocation != NULL && lenLocation > 0){

		id_Location = idLocation();
		addLocation(listLocation, lenLocation, nameLocation, street_1, street_2, street_3, street_4, id_Location);

		id = idZone();
		if(addZone(listZone, lenZone, id, id_Location)){
			retorno = 0;//TRUE
		}
	}
	return retorno;
}

int assignZoneMenu(Zone* listZone, int lenZone, Censista* listCensista, int lenCensista, int id_Censista, Location* listLocation, int lenLocation, int id_Location){

	int retorno = -1;//FALSE
	int indexZ;
	int id_Zone;

	if(listZone != NULL && lenZone > 0 && listCensista != NULL && lenCensista != -1 && id_Censista != -1 && listLocation != NULL && lenLocation != -1 && id_Location != -1){

		indexZ = findZoneByLocation(listZone, lenZone, id_Location);

		assignCensistaToZone(listZone, lenZone, id_Censista, id_Location, indexZ);
		assignZoneToCensista(listCensista, lenCensista, id_Censista, indexZ);
		id_Zone = findIdZoneByLocation(listZone, lenZone, id_Location);
		addLocationZone(listLocation, lenLocation, id_Location, id_Zone);

		retorno = 0;//TRUE
	}
	return retorno;
}

int addDataMenu(Zone* listZone, int lenZone, int id_Zone, int paperForm, int intvirtualForm, int absent, int totalAdd){

	int retorno = -1;//FALSE

	if(listZone != NULL && lenZone > 0 && id_Zone != -1 && paperForm != -1 && intvirtualForm != -1 && absent != -1 && totalAdd != -1){
		addDataZone(listZone, lenZone, id_Zone, intvirtualForm, paperForm, absent, totalAdd);
		retorno = 0;//TRUE
	}
	return retorno;
}

//MODIFICACIONES
int modificationsCensistaMenu(Censista* listCensista, int lenCensista,	char name[], char lastName[], int age, int id, int option){

	int retorno = -1;//FALSE

	if(listCensista != NULL && lenCensista > 0 && name != NULL && lastName != NULL && age > 0 && option > 0){
		switch(option){
			case 1:
				if(modifyCensistaName(listCensista, lenCensista, id, name) == 0){
					retorno = 0;//TRUE
				}
				break;
			case 2:
				if(modifyCensistaLastName(listCensista, lenCensista, id, lastName) == 0){
					retorno = 0;//TRUE
				}
				break;
			case 3:
				if(modifyCensistaAge(listCensista, lenCensista, id, age) == 0){
					retorno = 0;//TRUE
				}
				break;
		}
	}
	return retorno;
}

int modificationsDateMenu(Censista* listCensista, int lenCensista,	int day, int month,
		int year, int id, int option, Date* listDate, int lenDate){

	int retorno = -1;//FALSE
	int indexDate;

	if(listCensista != NULL && lenCensista > 0 && day > 0 && month > 0 && year > 0 && option > 0 && listDate != NULL && lenDate > 0){
		switch(option){
			case 1:
				modifyDateDay(listDate, lenDate, id, day);
				break;
			case 2:
				modifyDateMonth(listDate, lenDate, id, month);
				break;
			case 3:
				modifyDateYear(listDate, lenDate, id, year);
				break;
		}
		indexDate = findDateByIdElement(listDate, lenDate, id);
		if(modifyCensistaDateBirth(listCensista, lenCensista, id, listDate[indexDate]) == 0){
			retorno = 0;//TRUE
		}
	}
	return retorno;
}

int modificationsAddressMenu(Censista* listCensista, int lenCensista,	char street[], int streetNumber,
		char neighborhood[], int id, int option, Address* listAddress, int lenAddress){

	int retorno = -1;//FALSE
	int indexAddress;

	if(listCensista != NULL && lenCensista > 0 && street != NULL && streetNumber > 0 && neighborhood != NULL && option > 0 && listAddress != NULL && lenAddress > 0){
		switch(option){
			case 1:
				modifyAddressStreet(listAddress, lenAddress, id, street);
				break;
			case 2:
				modifyAddressStreetNumber(listAddress, lenAddress, id, streetNumber);
				break;
			case 3:
				modifyAddressNeighborhood(listAddress, lenAddress, id, neighborhood);
				break;
		}
	}
	indexAddress = findAddressByIdElement(listAddress, lenAddress, id);
	if(modifyCensistaAddress(listCensista, lenCensista, id, listAddress[indexAddress]) == 0){
		retorno = 0;//TRUE
	}

	return retorno;
}

//SUPRIMIR
int removeCensistaMenu(Censista* listCensista, int lenCensista,	int id, Date* listDate, int lenDate, Address* listAddress, int lenAddress){

	int retorno = -1;//FALSE

		if(listCensista != NULL && lenCensista > 0 && id > 0 && listDate != NULL && lenDate > 0 && listAddress != NULL && lenAddress > 0){
			if(removeCensista(listCensista, lenCensista, id) && removeAddress(listAddress, lenAddress, id) && removeDate(listDate, lenDate, id)){
				retorno = 0;//TRUE
			}
		}
		return retorno;
}

//MOSTRAR
int printListZoneCensistaList(Zone* listZone, int lenZone, Censista* listCensista, int lenCensista, Location* listLocation, int lenLocation){

	int retorno = -1;//FALSE

	if(listZone !=NULL && lenZone > 0 && listCensista !=NULL && lenCensista > 0 && listLocation !=NULL && lenLocation > 0){
		for(int i = 0; i < lenZone; i++){
			if(listZone[i].isEmpty == FULL && listZone[i].location == listLocation[i].id){
				printZoneCensistaList(listZone[i], listCensista[i], listLocation[i]);
				retorno = 0;//TRUE
			}
		}
	}
	return retorno;
}

int printZoneCensistaList(Zone zone, Censista censista, Location location){

	int retorno = -1;//FALSE

	if(zone.isEmpty == FULL){
		if(censista.zone == EMPTY){
			printf("%d \t%-15s \t%-15s  \t%-15s \t%-15s \t%-15s \tSIN ASIGNAR \t%d  \t%d   \t%d  \tPENDIENTE\n",
			zone.id, location.name, location.street_1, location.street_2, location.street_3, location.street_4,
			zone.paperForm, zone.virtualForm, zone.absent);
		}else{
			switch(zone.state){
			case PENDIENTE:
				printf("%d \t%-15s \t%-15s  \t%-15s \t%-15s \t%-15s \t%-15s %s \t%d  \t%d   \t%d  \tPENDIENTE\n",
				zone.id, location.name, location.street_1, location.street_2, location.street_3, location.street_4,
				censista.name, censista.lastName, zone.paperForm, zone.virtualForm, zone.absent);
				break;
			case FINALIZADO:
				printf("%d \t%-15s \t%-15s  \t%-15s \t%-15s \t%-15s \t%-15s %s \t%d  \t%d   \t%d  \tFINALIZADO\n",
				zone.id, location.name, location.street_1, location.street_2, location.street_3, location.street_4,
				  censista.name, censista.lastName, zone.paperForm, zone.virtualForm, zone.absent);
				break;
			}
		}
		retorno = 0;//TRUE
	}
	return retorno;
}

