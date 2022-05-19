/*
 * ArrayAddress.h
 *
 *  Created on: 14 may. 2022
 *      Author: A. Beggi
 */

#ifndef ARRAYADDRESS_H_
#define ARRAYADDRESS_H_

#include <stdio.h>
#include <string.h>

#define EMPTY 0
#define FULL 1

typedef struct{
	int idElement;
	char street[250];
	int streetNumber;
	char neighborhood[250];
	int isEmpty;
}Address;

//INICIALIZACIÓN
/// @fn int initAddress(Address*, int)
/// @brief To indicate that all position in the array are empty,
/// this function put the flag (isEmpty) in TRUE in all
/// position of the array.
/// @param list
/// @param len
/// @return Returns 0 for true and -1 for false.
int initAddress(Address* list, int len);

//AGREGAR
/// @fn int addAddress(Address*, int, int, char[], int, char[], int)
/// @brief add in a existing list the values received as parameters
/// in the first empty position.
/// @param list
/// @param len
/// @param id
/// @param street
/// @param streetNumber
/// @param neighborhood
/// @param index
/// @return Returns 0 for true and -1 for false.
int addAddress(Address* list, int len, int id, char street[], int streetNumber, char neighborhood[], int index);

//BUSQUEDA
/// @fn int findAddressEmpty(Address*, int)
/// @brief find the first position empty, returns the index position in array.
/// @param list
/// @param len
/// @return index position or (-1) if [Invalid length or
/// NULL pointer received or element not found].
int findAddressEmpty(Address* list, int len);

/// @fn int findAddressByIdElement(Address*, int, int)
/// @brief find a element by Id of another list and returns
/// the index position in array.
/// @param list
/// @param len
/// @param idElement
/// @return index position or (-1) if [Invalid length or
/// NULL pointer received or element not found].
int findAddressByIdElement(Address* list, int len, int idElement);

//SUPRIMIR
/// @fn int removeAddress(Address*, int, int)
/// @brief Remove a element by Id (put isEmpty Flag in 1)
/// @param list
/// @param len
/// @param id
/// @return Return (-1) if Error [Invalid length or NULL pointer or if can't
/// find a element] - (0) if Ok
int removeAddress(Address* list, int len, int id);

//MODIFICACIONES
/// @fn int modifyAddressStreet(Address*, int, int, char[])
/// @brief modifies the street of the element from the id
/// matching the id of the parameter.
/// @param list
/// @param len
/// @param idElement
/// @param street
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
int modifyAddressStreet(Address* list, int len, int idElement, char street[]);

/// @fn int modifyAddressStreetNumber(Address*, int, int, int)
/// @brief modifies the street number of the element from the id
/// matching the id of the parameter.
/// @param list
/// @param len
/// @param idElement
/// @param streetNumber
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
int modifyAddressStreetNumber(Address* list, int len, int idElement, int streetNumber);

/// @fn int modifyAddressNeighborhood(Address*, int, int, char[])
/// @brief modifies the neighborhood of the element from the id
/// matching the id of the parameter.
/// @param list
/// @param len
/// @param idElement
/// @param neighborhood
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
int modifyAddressNeighborhood(Address* list, int len, int idElement, char neighborhood[]);

#endif /* ARRAYADDRESS_H_ */
