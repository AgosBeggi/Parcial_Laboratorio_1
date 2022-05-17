/*
 * Menu.h
 *
 *  Created on: 16 may. 2022
 *      Author: A. Beggi
 */

#ifndef MENU_H_
#define MENU_H_

#include "ArrayCensista.h"
#include "ArrayDate.h"
#include "ArrayAddress.h"
#include "ArrayZone.h"
#include "ArrayLocation.h"

//INICIALIZACIÓN
int startMenu(Censista* listCensista, int lenCensista, Zone* listZone, int lenZone);

int hardcodeAddDataMenu(Censista* listCensista, int lenCensista, Date* listDate, int lenDate, Address* listAddress, int lenAddress,
		Zone* listZone, int lenZone, Location* listLocation, int lenLocation);

int hardcodeAssignDataMenu(Censista* listCensista, int lenCensista, int lenAddress,
		Zone* listZone, int lenZone, Location* listLocation, int lenLocation, int index);

//AGREGAR
int singUpCensistaMenu(Censista* listCensista, int lenCensista,	char name[], char lastName[], int age, int day, int month, int year,
		char street[], int streetNumber, char neighborhood[], Date* listDate, int lenDate, Address* listAddress, int lenAddress);

int singUpZoneMenu(Zone* listZone, int lenZone,	char nameLocation[], char street_1[], char street_2[],
		char street_3[], char street_4[], Location* listLocation, int lenLocation);

int assignZoneMenu(Zone* listZone, int lenZone, Censista* listCensista, int lenCensista, int id_Censista, Location* listLocation, int lenLocation, int id_Location);

int addDataMenu(Zone* listZone, int lenZone, int id_Zone, int paperForm, int intvirtualForm, int absent, int totalAdd);

//MODIFICACIONES
int modificationsCensistaMenu(Censista* listCensista, int lenCensista,	char name[], char lastName[], int age, int id, int option);

int modificationsDateMenu(Censista* listCensista, int lenCensista,	int day, int month,
		int year, int id, int option, Date* listDate, int lenDate);

int modificationsAddressMenu(Censista* listCensista, int lenCensista,	char street[], int streetNumber,
		char neighborhood[], int id, int option, Address* listAddress, int lenAddress);

//SUPRIMIR
int removeCensistaMenu(Censista* listCensista, int lenCensista,	int id, Date* listDate, int lenDate, Address* listAddress, int lenAddress);

//MOSTRAR
int printListZoneCensistaList(Zone* listZone, int lenZone, Censista* listCensista, int lenCensista, Location* listLocation, int lenLocation);

int printZoneCensistaList(Zone zone, Censista censista, Location location);

#endif /* MENU_H_ */
