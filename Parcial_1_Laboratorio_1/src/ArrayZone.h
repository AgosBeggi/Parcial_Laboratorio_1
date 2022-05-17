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
int idZone();

int initZone(Zone* list, int len);

//AGREGAR
int addZone(Zone* list, int len, int id, int location);

//ASIGNAR
int assignCensistaToZone(Zone* list, int len,	int id_Censista, int id_Location, int index);

int addDataZone(Zone* list, int len, int id, int virtualForm, int paperForm, int absent, int totalAdd);

//BUSQUEDA
int findZoneById(Zone* list, int len,int id);

int findZoneEmpty(Zone* list, int len);

int findZoneByLocation(Zone* list, int len, int location);

int findZoneByState(Zone* list, int len,int state);

int findZoneByCensista(Zone* list, int len,int idCensista);

int findIdZoneByLocation(Zone* list, int len, int location);

//SUPRIMIR
int removeZone(Zone* list, int len, int id);

//ORDENAR
int sortZone(Zone* list, int len, int order);

//MODIFICACIONES
int modifyZoneCensista(Zone* list, int len, int id, int censista);

int modifyZoneLocation(Zone* list, int len, int id, int location);

int modifyZoneState(Zone* list, int len, int id, int state);

int modifyZoneVirtualForm(Zone* list, int len, int id, int virtualForm);

int modifyZonePaperForm(Zone* list, int len, int id, int paperForm);

int modifyZoneAbsent(Zone* list, int len, int id, int absent);

//CALCULAR
int totalZone(Zone* list, int len);

int totalAssignZone(Zone* list, int len);

int totalUnallocatedZone(Zone* list, int len);

float percentageVirtualZone(Zone* list, int len);

float percentagePaperZone(Zone* list, int len);

float percentageAbsentZone(Zone* list, int len);

int totalZoneUnfinished(Zone* list, int len);

int totalZoneFinished(Zone* list, int len);

//MOSTRAR
//int printZoneList(Zone* list, int len, Censista* listCensista, int lenCensista, Location* listLocation, int lenLocation);
//
//int printZone(Zone zone, Censista censista, Location location);

//INFORMES

#endif /* ARRAYZONE_H_ */

