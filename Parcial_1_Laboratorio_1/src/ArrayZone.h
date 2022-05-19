/*
 * ArrayZone.h
 *
 *  Created on: 14 may. 2022
 *      Author: A. Beggi
 */

#ifndef ARRAYZONE_H_
#define ARRAYZONE_H_

#include <stdio.h>
#include <string.h>

#include "ArrayLocation.h"
#include "ArrayCensista.h"

#define EMPTY 0
#define FULL 1

#define PENDIENTE 1
#define FINALIZADO 2

typedef struct{
	int id;
	int location;
	int idCensista;
	int state;
	int virtualForm;
	int paperForm;
	int absent;
	int totalAdd;
	int isEmpty;
}Zone;

//INICIALIZACIÓN
/// @fn int idZone()
/// @brief using static int generate an autoincrementing id.
/// @return int id.
int idZone();

/// @fn int initZone(Zone*, int)
/// @brief To indicate that all position in the array are empty,
/// this function put the flag (isEmpty) in TRUE in all
/// position of the array.
/// @param list
/// @param len
/// @return Returns 0 for true and -1 for false.
int initZone(Zone* list, int len);

//AGREGAR
/// @fn int addZone(Zone*, int, int, int)
/// @brief add in a existing list the values received as parameters
/// in the first empty position.
/// @param list
/// @param len
/// @param id
/// @param location
/// @return int 0 for true and -1 for false.
int addZone(Zone* list, int len, int id, int location);

//ASIGNAR
/// @fn int assignCensistaToZone(Zone*, int, int, int, int)
/// @brief loads the id value of an element from another list,
/// to its own element with the same name
/// @param list
/// @param len
/// @param id_Censista
/// @param id_Location
/// @param index
/// @return int 0 for true and -1 for false.
int assignCensistaToZone(Zone* list, int len,	int id_Censista, int id_Location, int index);

/// @fn int addDataZone(Zone*, int, int, int, int, int, int)
/// @brief add in a existing list the values received as parameters
/// in the first empty position, and calculate the total.
/// @param list
/// @param len
/// @param id
/// @param virtualForm
/// @param paperForm
/// @param absent
/// @param totalAdd
/// @return int 0 for true and -1 for false.
int addDataZone(Zone* list, int len, int id, int virtualForm, int paperForm, int absent, int totalAdd);

//BUSQUEDA
/// @fn int findZoneById(Zone*, int, int)
/// @brief find by Id and returns the index position in array.
/// @param list
/// @param len
/// @param id
/// @return index position or (-1) if [Invalid length or
/// NULL pointer received or element not found]
int findZoneById(Zone* list, int len,int id);

/// @fn int findZoneIndexById(Zone*, int, int, int*)
/// @brief find by Id and returns the index position in array,
/// and passes the value to the memory address of the pointer.
/// @param list
/// @param len
/// @param id
/// @param index
/// @return Returns 0 for true and -1 for false.
int findZoneIndexById(Zone* list, int len, int id, int* index);

/// @fn int findZoneEmpty(Zone*, int)
/// @brief find the first position empty, and returns the index position in array.
/// @param list
/// @param len
/// @return index position or (-1) if [Invalid length or
/// NULL pointer received or element not found].
int findZoneEmpty(Zone* list, int len);

/// @fn int findZoneByLocation(Zone*, int, int)
/// @brief find position by Id to another list and returns the index position in array.
/// @param list
/// @param list
/// @param len
/// @param location
/// @return index position or (-1) if [Invalid length or
/// NULL pointer received or element not found].
int findZoneByLocation(Zone* list, int len, int location);

/// @fn int findZoneByState(Zone*, int, int)
/// @brief find position by int state.
/// @param list
/// @param len
/// @param state
/// @return int 0 for true and -1 for false.
int findZoneByState(Zone* list, int len,int state);

/// @fn int findZoneByCensista(Zone*, int, int)
/// @brief find position by Id of another list, returns the index position in array
/// @param list
/// @param len
/// @param idCensista
/// @return index position or (-1) if [Invalid length or
/// NULL pointer received or element not found].
int findZoneByCensista(Zone* list, int len,int idCensista);

/// @fn int findZoneIdByCensista(Zone*, int, int)
/// @brief find id by Id of another list.
/// @param list
/// @param len
/// @param idCensista
/// @return int (-1) if Error [Invalid length or NULL pointer or if can't
/// find a element] - returns the id of the position in array if Ok
int findZoneIdByCensista(Zone* list, int len,int idCensista);

/// @fn int findIdZoneByLocation(Zone*, int, int)
/// @brief find id by Id of another list.
/// @param list
/// @param len
/// @param location
/// @return int (-1) if Error [Invalid length or NULL pointer or if can't
/// find a element] - returns the id of the position in array if Ok
int findIdZoneByLocation(Zone* list, int len, int location);

//SUPRIMIR
/// @fn int removeZone(Zone*, int, int)
/// @brief Remove a element by Id (put isEmpty Flag in 1
/// @param list
/// @param len
/// @param id
/// @return int (-1) if Error [Invalid length or NULL pointer or if can't
/// find a element] - (0) if Ok
int removeZone(Zone* list, int len, int id);

//ORDENAR
/// @fn int sortZone(Zone*, int, int)
/// @brief Sort the elements in the array , the argument order
/// indicate UP or DOWN order
/// @param list
/// @param len
/// @param order
/// @return int (-1) if Error [Invalid length or NULL pointer or if can't
/// find a element] - (0) if Ok
int sortZone(Zone* list, int len, int order);

//MODIFICACIONES
/// @fn int modifyZoneCensista(Zone*, int, int, int)
/// @brief modifies the censista of the element from the id matching the id of the parameter.
/// @param list
/// @param len
/// @param id
/// @param censista
/// @return int 0 for true and -1 for false.
int modifyZoneCensista(Zone* list, int len, int id, int censista);

/// @fn int modifyZoneLocation(Zone*, int, int, int)
/// @brief modifies the location of the element from the id
/// matching the id of the parameter.
/// @param list
/// @param len
/// @param id
/// @param location
/// @return int 0 for true and -1 for false.
int modifyZoneLocation(Zone* list, int len, int id, int location);

/// @fn int modifyZoneState(Zone*, int, int, int)
/// @brief modifies the state of the element from the id
/// matching the id of the parameter.
/// @param list
/// @param len
/// @param id
/// @param state
/// @return int 0 for true and -1 for false.
int modifyZoneState(Zone* list, int len, int id, int state);

/// @fn int modifyZoneVirtualForm(Zone*, int, int, int)
/// @brief modifies the virtualForm of the element from the id
/// matching the id of the parameter.
/// @param list
/// @param len
/// @param id
/// @param virtualForm
/// @return int 0 for true and -1 for false.
int modifyZoneVirtualForm(Zone* list, int len, int id, int virtualForm);

/// @fn int modifyZonePaperForm(Zone*, int, int, int)
/// @brief modifies the paperForm of the element from the id
/// matching the id of the parameter.
/// @param list
/// @param len
/// @param id
/// @param paperForm
/// @return int 0 for true and -1 for false.
int modifyZonePaperForm(Zone* list, int len, int id, int paperForm);

/// @fn int modifyZoneAbsent(Zone*, int, int, int)
/// @brief modifies the absent of the element from the id
/// matching the id of the parameter.
/// @param list
/// @param len
/// @param id
/// @param absent
/// @return int 0 for true and -1 for false.
int modifyZoneAbsent(Zone* list, int len, int id, int absent);

//CALCULAR
/// @fn int totalZone(Zone*, int)
/// @brief calculates the total of all totals in the list
/// @param list
/// @param len
/// @return int (-1) if Error [Invalid length or NULL pointer or if can't
/// find a element] - total if Ok
int totalZone(Zone* list, int len);

/// @fn int totalAssignZone(Zone*, int)
/// @brief calculate how many zones were assigned
/// @param list
/// @param len
/// @return int (-1) if Error [Invalid length or NULL pointer or if can't
/// find a element] - total if Ok
int totalAssignZone(Zone* list, int len);

/// @fn int totalUnassignedZone(Zone*, int)
/// @brief calculate how many zones were unassigned
/// @param list
/// @param len
/// @return int (-1) if Error [Invalid length or NULL pointer or if can't
/// find a element] - total if Ok
int totalUnassignedZone(Zone* list, int len);

/// @fn int totalZoneFinished(Zone*, int)
/// @brief calculates the total of finished zones
/// @param list
/// @param len
/// @return int (-1) if Error [Invalid length or NULL pointer or if can't
/// find a element] - total if Ok
int totalZoneFinished(Zone* list, int len);

/// @fn int totalZoneUnfinished(Zone*, int)
/// @brief calculates the total of unfinished zones
/// @param list
/// @param len
/// @return int (-1) if Error [Invalid length or NULL pointer or if can't
/// find a element] - total if Ok
int totalZoneUnfinished(Zone* list, int len);

//PROMEDIOS
/// @fn float percentageVirtualZone(Zone*, int)
/// @brief calculates the average of virtualForm.
/// @param list
/// @param len
/// @return float (-1) if Error [Invalid length or NULL pointer or if can't
/// find a element] - average if Ok
float percentageVirtualZone(Zone* list, int len);

/// @fn float percentagePaperZone(Zone*, int)
/// @brief calculates the average of paperForm.
/// @param list
/// @param len
/// @return float (-1) if Error [Invalid length or NULL pointer or if can't
/// find a element] - average if Ok
float percentagePaperZone(Zone* list, int len);

/// @fn float percentageAbsentZone(Zone*, int)
/// @brief calculates the average of absent.
/// @param list
/// @param len
/// @return float (-1) if Error [Invalid length or NULL pointer or if can't
/// find a element] - average if Ok
float percentageAbsentZone(Zone* list, int len);

//INFORMES
int totalZoneAbsent(Zone* list, int len);

int totalZonePeperVirtual(Zone* list, int len);

#endif /* ARRAYZONE_H_ */

