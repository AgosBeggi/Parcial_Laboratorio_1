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
int idCensista();

int initCensista(Censista* list, int len);

//AGREGAR
int addCensista(Censista* list, int len, int id, char name[], char lastName[], Date dateBirth, int age, Address adress);

int assignZoneToCensista(Censista* list, int len, int id_Censista, int zone);

//BUSQUEDA
int findCensistaById(Censista* list, int len, int id);

int findCensistaEmpty(Censista* list, int len);

int findCensistaByState(Censista* list, int len, int state);

int findCensistaByZone(Censista* list, int len, int zone);

int findIdCensistaByZone(Censista* list, int len, int zone);

//SUPRIMIR
int removeCensista(Censista* list, int len, int id);

//ORDENAR
int sortCensista(Censista* list, int len, int order);

//MODIFICACIONES
int modifyCensistaZone(Censista* list, int len, int id, int zone);

int modifyCensistaName(Censista* list, int len, int id, char Name[]);

int modifyCensistaLastName(Censista* list, int len, int id, char lastName[]);

int modifyCensistaState(Censista* list, int len, int id, int state);

int modifyCensistaDateBirth(Censista* list, int len, int id, Date dateBirth);

int modifyCensistaAge(Censista* list, int len, int id, int age);

int modifyCensistaAddress(Censista* list, int len, int id, Address adress);

//MOSTRAR
int printCensistaList(Censista* list, int len);

int printCensista(Censista censista);

//INFORMES

#endif /* ARRAYCENSISTA_H_ */

