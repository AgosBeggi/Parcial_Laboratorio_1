/*
 * ArrayDate.h
 *
 *  Created on: 14 may. 2022
 *      Author: A. Beggi
 */

#ifndef ARRAYDATE_H_
#define ARRAYDATE_H_

#include <stdio.h>

#define EMPTY 0
#define FULL 1

typedef struct{
	int idElement;
	int day;
	int month;
	int year;
	int isEmpty;
}Date;

//INICIALIZACIÓN
/// @fn int initDate(Date*, int)
/// @brief To indicate that all position in the array are empty,
/// this function put the flag (isEmpty) in TRUE in all
/// position of the array.
/// @param list
/// @param len
/// @return Returns 0 for true and -1 for false.
int initDate(Date* list, int len);

//AGREGAR
/// @fn int addDate(Date*, int, int, int, int, int, int)
/// @brief add in a existing list the values received as parameters
/// in the first empty position.
/// @param list
/// @param len
/// @param id
/// @param day
/// @param month
/// @param year
/// @param index
/// @return Returns 0 for true and -1 for false.
int addDate(Date* list, int len, int id, int day, int month, int year, int index);

//BUSQUEDA
/// @fn int findDateEmpty(Date*, int)
/// @brief find the first position empty, returns the index position in array.
/// @param list
/// @param len
/// @return index position or (-1) if [Invalid length or
/// NULL pointer received or element not found].
int findDateEmpty(Date* list, int len);

/// @fn int findDateByIdElement(Date*, int, int)
/// @brief find a element by Id of another list and returns
/// the index position in array.
/// @param list
/// @param len
/// @param idElement
/// @return index position or (-1) if [Invalid length or
/// NULL pointer received or element not found].
int findDateByIdElement(Date* list, int len, int idElement);

//SUPRIMIR
/// @fn int removeDate(Date*, int, int)
/// @brief Remove a element by Id (put isEmpty Flag in 1)
/// @param list
/// @param len
/// @param id
/// @return Return (-1) if Error [Invalid length or NULL pointer or if can't
/// find a element] - (0) if Ok
int removeDate(Date* list, int len, int id);

//MODIFICACIONES
/// @fn int modifyDateDay(Date*, int, int, int)
/// @brief modifies the day number of the element from the id
/// matching the id of the parameter.
/// @param list
/// @param len
/// @param idElement
/// @param day
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
int modifyDateDay(Date* list, int len, int idElement, int day);

/// @fn int modifyDateMonth(Date*, int, int, int)
/// @brief modifies the month number of the element from the id
/// matching the id of the parameter.
/// @param list
/// @param len
/// @param idElement
/// @param month
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
int modifyDateMonth(Date* list, int len, int idElement, int month);

/// @fn int modifyDateYear(Date*, int, int, int)
/// @brief modifies the year number of the element from the id
/// matching the id of the parameter.
/// @param list
/// @param len
/// @param idElement
/// @param year
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
int modifyDateYear(Date* list, int len, int idElement, int year);

#endif /* ARRAYDATE_H_ */
