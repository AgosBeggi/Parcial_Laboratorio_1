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

#define SIN_ASIGNAR 0
#define ASIGNADO 1
#define TERMINADO 2

typedef struct{
	int id;
	int id_Zone;
	char name[150];
	char street_1[150];
	char street_2[150];
	char street_3[150];
	char street_4[150];
	int state;
	int isEmpty;
}Location;

//INICIALIZACIÓN
/// @fn int idLocation()
/// @brief using static int generate an autoincrementing id.
/// @return int id.
int idLocation();

/// @fn int initLocation(Location*, int)
/// @brief To indicate that all position in the array are empty,
/// this function put the flag (isEmpty) in TRUE in all
/// position of the array.
/// @param listLocation
/// @param lenLocation
/// @return Returns 0 for true and -1 for false.
int initLocation(Location* listLocation, int lenLocation);

//AGREGAR
/// @fn int addLocation(Location*, int, char[], char[], char[], char[], char[], int)
/// @brief add in a existing list the values received as parameters
/// in the first empty position.
/// @param listLocation
/// @param lenLocation
/// @param name
/// @param street_1
/// @param street_2
/// @param street_3
/// @param street_4
/// @param id
/// @return Returns int 0 for true and -1 for false.
int addLocation(Location* listLocation, int lenLocation, char name[], char street_1[], char street_2[], char street_3[], char street_4[], int id);

/// @fn int addLocationZone(Location*, int, int, int)
/// @brief add in a existing list the values received as parameters
/// in the first empty position.
/// @param listLocation
/// @param lenLocation
/// @param id_Location
/// @param id_Zone
/// @return Returns 0 for true and -1 for false.
int addLocationZone(Location* listLocation, int lenLocation, int id_Location, int id_Zone);

//BUSQUEDA
/// @fn int findLocationEmpty(Location*, int)
/// @brief find the first position empty, returns the index position in array.
/// @param listLocation
/// @param lenLocation
/// @return index position or (-1) if [Invalid length or
/// NULL pointer received or element not found].
int findLocationEmpty(Location* listLocation, int lenLocation);

/// @fn int findLocationById(Location*, int, int, int*)
/// @brief find by Id and returns the index position in array.
/// @param list
/// @param len
/// @param id
/// @param index
/// @return index position or (-1) if [Invalid length or
/// NULL pointer received or element not found]
int findLocationById(Location* list, int len, int id, int* index);

/// @fn int findLocationIndexByIdZone(Location*, int, int, int*)
/// @brief find position by Id of another list and returns the index position in
/// array to the memory address of the pointer.
/// @param list
/// @param len
/// @param id_zone
/// @param index
/// @return Returns 0 for true and -1 for false.
int findLocationIndexByIdZone(Location* list, int len, int id_zone, int* index);

/// @fn int findLocationByZone(Location*, int, int)
/// @brief find a element by Id of another list and returns
/// the index position in array.
/// @param list
/// @param len
/// @param id_Zone
/// @return index position or (-1) if [Invalid length or
/// NULL pointer received or element not found].
int findLocationByZone(Location* list, int len, int id_Zone);

int modifyLocationState(Location* list, int len, int id, int state);

//MOSTRAR
/// @fn int printLocationList(Location*, int)
/// @brief print the content of passengers array.
/// @param listLocation
/// @param lenLocation
/// @return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
int printLocationList(Location* listLocation, int lenLocation);

/// @fn int printLocation(Location)
/// @brief print the content of a single element of the array.
/// @param location
/// @return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
int printLocation(Location location);

#endif /* ARRAYLOCATION_H_ */
