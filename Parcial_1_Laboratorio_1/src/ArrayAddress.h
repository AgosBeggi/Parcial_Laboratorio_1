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
int initAddress(Address* list, int len);

//AGREGAR
int addAddress(Address* list, int len, int id, char street[], int streetNumber, char neighborhood[], int index);

//BUSQUEDA
int findAddressEmpty(Address* list, int len);

int findAddressByIdElement(Address* list, int len, int idElement);

//SUPRIMIR
int removeAddress(Address* list, int len, int id);

//MODIFICACIONES
int modifyAddressStreet(Address* list, int len, int idElement, char street[]);

int modifyAddressStreetNumber(Address* list, int len, int idElement, int streetNumber);

int modifyAddressNeighborhood(Address* list, int len, int idElement, char neighborhood[]);

#endif /* ARRAYADDRESS_H_ */
