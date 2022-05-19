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
/// @fn int startMenu(Censista*, int, Zone*, int)
/// @brief calls the init fn from the the parameter lists to initialize.
/// @param listCensista
/// @param lenCensista
/// @param listZone
/// @param lenZone
/// @return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
int startMenu(Censista* listCensista, int lenCensista, Zone* listZone, int lenZone);

/// @fn int hardcodeAddDataMenu(Censista*, int, Date*, int, Address*, int, Zone*, int, Location*, int)
/// @brief automatically fills 10 positions of the parameter lists.
/// @param listCensista
/// @param lenCensista
/// @param listDate
/// @param lenDate
/// @param listAddress
/// @param lenAddress
/// @param listZone
/// @param lenZone
/// @param listLocation
/// @param lenLocation
/// @return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int hardcodeAddDataMenu(Censista* listCensista, int lenCensista, Date* listDate, int lenDate, Address* listAddress, int lenAddress,
		Zone* listZone, int lenZone, Location* listLocation, int lenLocation);

//AGREGAR
/// @fn int singUpCensistaMenu(Censista*, int, char[], char[], int, int, int, int, char[], int, char[], Date*, int, Address*, int)
/// @brief calls the add fn from the the parameter lists to add.
/// @param listCensista
/// @param lenCensista
/// @param name
/// @param lastName
/// @param age
/// @param day
/// @param month
/// @param year
/// @param street
/// @param streetNumber
/// @param neighborhood
/// @param listDate
/// @param lenDate
/// @param listAddress
/// @param lenAddress
/// @return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int singUpCensistaMenu(Censista* listCensista, int lenCensista,	char name[], char lastName[], int age, int day, int month, int year,
		char street[], int streetNumber, char neighborhood[], Date* listDate, int lenDate, Address* listAddress, int lenAddress);

/// @fn int singUpZoneMenu(Zone*, int, char[], char[], char[], char[], char[], Location*, int)
/// @brief calls the add fn from the the parameter lists to add.
/// @param listZone
/// @param lenZone
/// @param nameLocation
/// @param street_1
/// @param street_2
/// @param street_3
/// @param street_4
/// @param listLocation
/// @param lenLocation
/// @return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int singUpZoneMenu(Zone* listZone, int lenZone,	char nameLocation[], char street_1[], char street_2[],
		char street_3[], char street_4[], Location* listLocation, int lenLocation);

/// @fn int assignZoneMenu(Zone*, int, Censista*, int, int, Location*, int, int)
/// @brief calls the assign fn from the the parameter lists to assign.
/// @param listZone
/// @param lenZone
/// @param listCensista
/// @param lenCensista
/// @param id_Censista
/// @param listLocation
/// @param lenLocation
/// @param id_Location
/// @return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int assignZoneMenu(Zone* listZone, int lenZone, Censista* listCensista, int lenCensista, int id_Censista, Location* listLocation, int lenLocation, int id_Location);

/// @fn int addDataMenu(Zone*, int, int, int, int, int, int)
/// @brief calls the add fn from the the parameter lists to add.
/// @param listZone
/// @param lenZone
/// @param id_Zone
/// @param paperForm
/// @param intvirtualForm
/// @param absent
/// @param totalAdd
/// @return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int addDataMenu(Zone* listZone, int lenZone, int id_Zone, int paperForm, int intvirtualForm, int absent, int totalAdd);

//MODIFICACIONES
/// @fn int modificationsCensistaMenu(Censista*, int, char[], char[], int, int, int)
/// @brief calls the mofify fn from the the parameter lists to mofify.
/// @param listCensista
/// @param lenCensista
/// @param name
/// @param lastName
/// @param age
/// @param id
/// @param option
/// @return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int modificationsCensistaMenu(Censista* listCensista, int lenCensista,	char name[], char lastName[], int age, int id, int option);

/// @fn int modificationsDateMenu(Censista*, int, int, int, int, int, int, Date*, int)
/// @brief calls the mofify fn from the the parameter lists to mofify.
/// @param listCensista
/// @param lenCensista
/// @param day
/// @param month
/// @param year
/// @param id
/// @param option
/// @param listDate
/// @param lenDate
/// @return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int modificationsDateMenu(Censista* listCensista, int lenCensista,	int day, int month,
		int year, int id, int option, Date* listDate, int lenDate);

/// @fn int modificationsAddressMenu(Censista*, int, char[], int, char[], int, int, Address*, int)
/// @brief calls the mofify fn from the the parameter lists to mofify.
/// @param listCensista
/// @param lenCensista
/// @param street
/// @param streetNumber
/// @param neighborhood
/// @param id
/// @param option
/// @param listAddress
/// @param lenAddress
/// @return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int modificationsAddressMenu(Censista* listCensista, int lenCensista,	char street[], int streetNumber,
		char neighborhood[], int id, int option, Address* listAddress, int lenAddress);

//SUPRIMIR
/// @fn int removeCensistaMenu(Censista*, int, int, Date*, int, Address*, int)
/// @brief Remove a element by Id calling remove fn from the parameter lists.
/// @param listCensista
/// @param lenCensista
/// @param id
/// @param listDate
/// @param lenDate
/// @param listAddress
/// @param lenAddress
/// @return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
int removeCensistaMenu(Censista* listCensista, int lenCensista,	int id, Date* listDate, int lenDate, Address* listAddress, int lenAddress);

/// @fn int checkStateAssignLocationList(Location*, int, int)
/// @brief check the state of the parameter list.
/// @param listLocation
/// @param lenLocation
/// @param index
/// @return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
int checkStateAssignLocationList(Location* listLocation, int lenLocation, int index);

/// @fn int checkStateFinishZoneList(Zone*, int, int)
/// @brief check the state of the parameter list.
/// @param listZone
/// @param lenZone
/// @param id_Zone
/// @return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
int checkStateFinishZoneList(Zone* listZone, int lenZone, int id_Zone);

//MOSTRAR
/// @fn int printZoneDataList(Zone*, int, Censista*, int, Location*, int)
/// @brief print items from related parameter lists
/// @param listZone
/// @param lenZone
/// @param listCensista
/// @param lenCensista
/// @param listLocation
/// @param lenLocation
/// @return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
int printZoneDataList(Zone* listZone, int lenZone, Censista* listCensista, int lenCensista, Location* listLocation, int lenLocation);

/// @fn int printAllZoneDataList(Zone*, int, Censista*, int, Location*, int)
/// @brief print items from related parameter lists
/// @param listZone
/// @param lenZone
/// @param listCensista
/// @param lenCensista
/// @param listLocation
/// @param lenLocation
/// @return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
int printAllZoneDataList(Zone* listZone, int lenZone, Censista* listCensista, int lenCensista, Location* listLocation, int lenLocation);

/// @fn int printCensistaListMenu(Zone*, int, Censista*, int, Location*, int)
/// @brief print items from related parameter lists
/// @param listZone
/// @param lenZone
/// @param listCensista
/// @param lenCensista
/// @param listLocation
/// @param lenLocation
/// @return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
int printCensistaListMenu(Zone* listZone, int lenZone, Censista* listCensista, int lenCensista, Location* listLocation, int lenLocation);

/// @fn int printZoneData(Zone, Censista, Location)
/// @brief prin a single item from related parameter lists
/// @param zone
/// @param censista
/// @param location
/// @return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
int printZoneData(Zone zone,  Censista censista, Location location);

/// @fn int printAllZoneData(Zone, Censista, Location)
/// @brief prin a single item from related parameter lists
/// @param zone
/// @param censista
/// @param location
/// @return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
int printAllZoneData(Zone zone, Censista censista, Location location);

/// @fn int printCensistaMenu(Censista, Zone, Location)
/// @brief prin a single item from related parameter lists
/// @param censista
/// @param zone
/// @param location
/// @return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
int printCensistaMenu(Censista censista, Zone zone, Location location);

int printCensistaMinTotalZoneListMenu(Censista censista, Zone zone, Location location);

int censistaMaxTotalZoneListMenu(Zone* listZone, int lenZone, Censista* listCensista, int lenCensista, Location* listLocation, int lenLocation);

int censistaMinTotalZoneListMenu(Zone* listZone, int lenZone, Censista* listCensista, int lenCensista, Location* listLocation, int lenLocation);

int percentajeVirtualZoneListMenu(Zone* listZone, int lenZone, Censista* listCensista, int lenCensista, Location* listLocation, int lenLocation);

int percentajePaperlZoneListMenu(Zone* listZone, int lenZone, Censista* listCensista, int lenCensista, Location* listLocation, int lenLocation);

int percentajeAbsentlZoneListMenu(Zone* listZone, int lenZone, Censista* listCensista, int lenCensista, Location* listLocation, int lenLocation);

int cantidadCensistasEstadoActivoZonaPendiente(Zone* listZone, int lenZone, Censista* listCensista, int lenCensista, Location* listLocation, int lenLocation);

//INFORMES
int printCensistaEspecificosMenu(Censista censista, Zone zone, Location location);

int printCensistaEspecificosListMenu(Zone* listZone, int lenZone, Censista* listCensista, int lenCensista, Location* listLocation, int lenLocation);

int promedioDeCensosPorCensista(Zone* listZone, int lenZone, Censista* listCensista, int lenCensista, Location* listLocation, int lenLocation);

int printPromedioDeCensosPorCensista(Censista censista, Zone zone, Location location, float promedio);

#endif /* MENU_H_ */









