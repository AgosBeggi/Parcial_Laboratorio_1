/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#include <stdio.h>
#include <stdlib.h>
#include "Input.h"

#define LEN_STRING 50

typedef struct
{
	int id;
	char nombre[LEN_STRING];
	char apellido[LEN_STRING];
	float precio;
	char codigoVuelo[LEN_STRING];
	int tipoPasajero;
	int estado;
}Passenger;

//CONSTRUIR
Passenger* Passenger_new();

//AGREGAR
Passenger* Passenger_newParametros(char* idStr, char* nombreStr, char* apellidoStr, char* precioStr, char* tipoPasajeroStr, char* codigoVueloStr, char* estadoStr);

//SUPRIMIR
void Passenger_delete(Passenger* this);

//BUSCAR
int Passenger_getId(Passenger* this, int* id);
int Passenger_getNombre(Passenger* this, char* nombre);
int Passenger_getApellido(Passenger* this, char* apellido);
int Passenger_getCodigoVuelo(Passenger* this, char* codigoVuelo);
int Passenger_getTipoPasajero(Passenger* this, int* tipoPasajero);
int Passenger_getPrecio(Passenger* this, float* precio);
int Passenger_getEstado(Passenger* this, int* estado);

//GUARDAR
int Passenger_setId(Passenger* this, int id);
int Passenger_setNombre(Passenger* this, char* nombre);
int Passenger_setApellido(Passenger* this, char* apellido);
int Passenger_setCodigoVuelo(Passenger* this, char* codigoVuelo);
int Passenger_setTipoPasajero(Passenger* this, int tipoPasajero);
int Passenger_setPrecio(Passenger* this, float precio);
int Passenger_setEstado(Passenger* this, int estado);

int isNombre(char* cadena, int len);

//TRADUCIR
int Passenger_translateTypeStrToInt(char* tipoPasajeroStr);
int Passenger_translateStateStrToInt(char* estadoStr);
int Passenger_translateTypeIntToStr(int tipoPasajeroInt, char* auxTipoPasajero);
int Passenger_translateStateIntToStr(int estadoInt, char* estadoStr);

//LISTAR
int Passenger_print(Passenger* this);

//MODIFICAR
int Passenger_edit(Passenger* this);

//COMPARAR
int Passenger_compareById(void* this, void* this2);

int Passenger_compareByNombre(void* this, void* this2);

int Passenger_compareByApellido(void* this, void* this2);

int Passenger_compareByPrecio(void* this, void* this2);

int Passenger_compareByTipo(void* this, void* this2);

int Passenger_compareByEstado(void* this, void* this2);

int Passenger_TotalPassengerType(void* element);

int Passenger_tipo(int* tipo);

int Passenger_PassengerType(void* element);

int Passenger_tipoMenu();

//Passenger* Passenger_copy(Passenger* this);

#endif /* PASSENGER_H_ */























