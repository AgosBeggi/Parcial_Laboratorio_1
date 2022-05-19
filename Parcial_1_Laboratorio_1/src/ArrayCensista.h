/*
 * ArrayCensista.h
 *
 *  Created on: 14 may. 2022
 *      Author: A. Beggi
 */

#ifndef ARRAYCENSISTA_H_
#define ARRAYCENSISTA_H_

#include <stdio.h>
#include <string.h>

#include "ArrayDate.h"
#include "ArrayAddress.h"
#include "ArrayZone.h"

#define EMPTY 0
#define FULL 1

#define ACTIVO 1
#define LIBERADO 2
#define INACTIVO 3

typedef struct{
	int id;
	int zone;
	char name[51];
	char lastName[51];
	int state;
	Date dateBirth;
	int age;
	Address adress;
	int isEmpty;
}Censista;

//INICIALIZACIÓN
/// @fn int idCensista()
/// @brief using static int generate an autoincrementing id.
/// @return int id.
int idCensista();

/// @fn int initCensista(Censista*, int)
/// @brief To indicate that all position in the array are empty,
/// this function put the flag (isEmpty) in TRUE in all
/// position of the array.
/// @param list
/// @param len
/// @return Returns 0 for true and -1 for false.
int initCensista(Censista* list, int len);

//AGREGAR
/// @fn int addCensista(Censista*, int, int, char[], char[], Date, int, Address)
/// @brief add in a existing list the values received as parameters
/// in the first empty position.
/// @param list
/// @param len
/// @param id
/// @param name
/// @param lastName
/// @param dateBirth
/// @param age
/// @param adress
/// @return Returns int 0 for true and -1 for false.
int addCensista(Censista* list, int len, int id, char name[], char lastName[], Date dateBirth, int age, Address adress);

/// @fn int assignZoneToCensista(Censista*, int, int, int)
/// @brief loads the id value of an element from another list,
/// to its own element with the same name
/// @param list
/// @param len
/// @param id_Censista
/// @param zone
/// @return Returns 0 for true and -1 for false.
int assignZoneToCensista(Censista* list, int len, int id_Censista, int zone);

//BUSQUEDA
/// @fn int findCensistaById(Censista*, int, int)
/// @brief find by Id and returns the index position in array.
/// @param list
/// @param len
/// @param id
/// @return index position or (-1) if [Invalid length or
/// NULL pointer received or element not found]
int findCensistaById(Censista* list, int len, int id);

/// @fn int findCensistaIndexById(Censista*, int, int, int*)
/// @brief find by Id and returns the index position in array,
/// and passes the value to the memory address of the pointer.
/// @param list
/// @param len
/// @param id
/// @param index
/// @return Returns 0 for true and -1 for false.
int findCensistaIndexById(Censista* list, int len, int id, int* index);

/// @fn int findCensistaIndexByIdZone(Censista*, int, int, int*)
/// @brief find by Id to another list and returns the index position in array,
/// and passes the value to the memory address of the pointer.
/// @param list
/// @param len
/// @param id_zone
/// @param index
/// @return Returns 0 for true and -1 for false.
int findCensistaIndexByIdZone(Censista* list, int len, int id_zone, int* index);

/// @fn int findCensistaEmpty(Censista*, int)
/// @brief find the first position empty, and returns the id number in
/// array to the memory address of the pointer.
/// @param list
/// @param len
/// @return index position or (-1) if [Invalid length or
/// NULL pointer received or element not found].
int findCensistaEmpty(Censista* list, int len);

/// @fn int findCensistaByState(Censista*, int, int)
/// @brief find position by int state.
/// @param list
/// @param len
/// @param state
/// @return int 0 for true and -1 for false.
int findCensistaByState(Censista* list, int len, int state);

/// @fn int findCensistaByZone(Censista*, int, int)
/// @brief find position by Id of another list, returns the index position in array
/// @param list
/// @param len
/// @param zone
/// @return index position or (-1) if [Invalid length or
/// NULL pointer received or element not found].
int findCensistaByZone(Censista* list, int len, int zone);

/// @fn int findIdCensistaByZone(Censista*, int, int)
/// @brief find position by Id of another list and returns the index position in array.
/// @param list
/// @param len
/// @param zone
/// @return index position or (-1) if [Invalid length or
/// NULL pointer received or element not found].
int findIdCensistaByZone(Censista* list, int len, int zone);

//SUPRIMIR
/// @fn int removeCensista(Censista*, int, int)
/// @brief Remove a element by Id (put isEmpty Flag in 1
/// @param list
/// @param len
/// @param id
/// @return int (-1) if Error [Invalid length or NULL pointer or if can't
/// find a element] - (0) if Ok
int removeCensista(Censista* list, int len, int id);

//ORDENAR
/// @fn int sortCensista(Censista*, int, int)
/// @brief Sort the elements in the array , the argument order
/// indicate UP or DOWN order
/// @param list
/// @param len
/// @param order
/// @return int (-1) if Error [Invalid length or NULL pointer or if can't
/// find a passenger] - (0) if Ok
int sortCensista(Censista* list, int len, int order);

//MODIFICACIONES
/// @fn int modifyCensistaZone(Censista*, int, int, int)
/// @brief modifies the zone of the element from the id matching the id of the parameter.
/// @param list
/// @param len
/// @param id
/// @param zone
/// @return int 0 for true and -1 for false.
int modifyCensistaZone(Censista* list, int len, int id, int zone);

/// @fn int modifyCensistaName(Censista*, int, int, char[])
/// @brief modifies the name of the element from the id matching the id of the parameter.
/// @param list
/// @param len
/// @param id
/// @param Name
/// @return int 0 for true and -1 for false.
int modifyCensistaName(Censista* list, int len, int id, char Name[]);

/// @fn int modifyCensistaLastName(Censista*, int, int, char[])
/// @brief modifies the last name of the element from the id matching the id of the parameter.
/// @param list
/// @param len
/// @param id
/// @param lastName
/// @return int 0 for true and -1 for false.
int modifyCensistaLastName(Censista* list, int len, int id, char lastName[]);

/// @fn int modifyCensistaState(Censista*, int, int, int)
/// @brief modifies the state of the element from the
/// id matching the id of the parameter.
/// @param list
/// @param len
/// @param id
/// @param state
/// @return int 0 for true and -1 for false.
int modifyCensistaState(Censista* list, int len, int id, int state);

/// @fn int modifyCensistaDateBirth(Censista*, int, int, Date)
/// @brief modifies the date of the element from the
/// id matching the id of the parameter.
/// @param list
/// @param len
/// @param id
/// @param dateBirth
/// @return int 0 for true and -1 for false.
int modifyCensistaDateBirth(Censista* list, int len, int id, Date dateBirth);

/// @fn int modifyCensistaAge(Censista*, int, int, int)
/// @brief modifies the age of the element from the
/// id matching the id of the parameter.
/// @param list
/// @param len
/// @param id
/// @param age
/// @return int 0 for true and -1 for false.
int modifyCensistaAge(Censista* list, int len, int id, int age);

/// @fn int modifyCensistaAddress(Censista*, int, int, Address)
/// @brief modifies the adress of the element from the
/// id matching the id of the parameter.
/// @param list
/// @param len
/// @param id
/// @param adress
/// @return int 0 for true and -1 for false.
int modifyCensistaAddress(Censista* list, int len, int id, Address adress);

//MOSTRAR
/// @fn int printCensistaList(Censista*, int)
/// @brief print the content of passengers array.
/// @param list
/// @param len
/// @return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
int printCensistaList(Censista* list, int len);

/// @fn int printCensista(Censista)
/// @brief print the content of a single element of the array.
/// @param censista
/// @return int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
int printCensista(Censista censista);

//INFORMES

#endif /* ARRAYCENSISTA_H_ */

