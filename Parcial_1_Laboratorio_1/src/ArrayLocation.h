/*
 * ArrayLocation.h
 *
 *  Created on: 15 may. 2022
 *      Author: A. Beggi
 */

#ifndef ARRAYLOCATION_H_
#define ARRAYLOCATION_H_

#include <stdio.h>
#include <string.h>

#define EMPTY 0
#define FULL 1

typedef struct{
	int id;
	int id_Zone;
	char name[150];
	char street_1[150];
	char street_2[150];
	char street_3[150];
	char street_4[150];
	int isEmpty;
}Location;

//INICIALIZACIÓN
int idLocation();

int initLocation(Location* listLocation, int lenLocation);

//AGREGAR
int addLocation(Location* listLocation, int lenLocation, char name[], char street_1[], char street_2[], char street_3[], char street_4[], int id);

int addLocationZone(Location* listLocation, int lenLocation, int id_Location, int id_Zone);

//BUSQUEDA
int findLocationEmpty(Location* listLocation, int lenLocation);

int findLocationById(Location* list, int len, int id);

int findLocationByZone(Location* list, int len, int id_Zone);

//MOSTRAR
int printLocationList(Location* listLocation, int lenLocation);

int printLocation(Location location);

#endif /* ARRAYLOCATION_H_ */
