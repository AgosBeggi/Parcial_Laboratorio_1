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
int initDate(Date* list, int len);

//AGREGAR
int addDate(Date* list, int len, int id, int day, int month, int year, int index);

//BUSQUEDA
int findDateEmpty(Date* list, int len);

int findDateByIdElement(Date* list, int len, int idElement);

//SUPRIMIR
int removeDate(Date* list, int len, int id);

//MODIFICACIONES
int modifyDateDay(Date* list, int len, int idElement, int day);

int modifyDateMonth(Date* list, int len, int idElement, int month);

int modifyDateYear(Date* list, int len, int idElement, int year);

#endif /* ARRAYDATE_H_ */
