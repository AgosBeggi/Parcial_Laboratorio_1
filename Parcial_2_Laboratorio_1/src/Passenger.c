/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include "Passenger.h"

//CONSTRUIR
Passenger* Passenger_new(){
	Passenger* passenger_aux = NULL;
	passenger_aux = (Passenger*) malloc(sizeof(Passenger));
	return passenger_aux;
}

//AGREGAR
Passenger* Passenger_newParametros(char* idStr, char* nombreStr, char* apellidoStr, char* precioStr, char* tipoPasajeroStr, char* codigoVueloStr, char* estadoStr){

	Passenger* auxPassenger;
	int aux_id;
	int aux_tipoPasajero;
	float aux_precioPasajero;
	int aux_estadoPasajero;

	auxPassenger = Passenger_new();

	if(auxPassenger != NULL && idStr != NULL && nombreStr != NULL && apellidoStr != NULL && precioStr != NULL && tipoPasajeroStr != NULL && codigoVueloStr != NULL && estadoStr != NULL){

		aux_id = atoi(idStr);
		Passenger_setId(auxPassenger, aux_id);

		aux_precioPasajero = atof(precioStr);
		Passenger_setPrecio(auxPassenger, aux_precioPasajero);

		Passenger_setNombre(auxPassenger, nombreStr);
		Passenger_setApellido(auxPassenger, apellidoStr);

		aux_tipoPasajero = Passenger_translateTypeStrToInt(tipoPasajeroStr);
		Passenger_setTipoPasajero(auxPassenger, aux_tipoPasajero);

		aux_estadoPasajero = Passenger_translateStateStrToInt(estadoStr);
		Passenger_setEstado(auxPassenger, aux_estadoPasajero);

		Passenger_getEstado(auxPassenger, &aux_estadoPasajero);
		Passenger_translateStateIntToStr(aux_estadoPasajero, estadoStr);

		Passenger_setCodigoVuelo(auxPassenger, codigoVueloStr);
	}
	return auxPassenger;
}

//SUPRIMIR
void Passenger_delete(Passenger* this){

	if (this != NULL){
		free(this);
	}
}

//BUSCAR
int Passenger_getId(Passenger* this, int* id){

	int retorno = -1;

	if(this != NULL && id != NULL){
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int Passenger_getNombre(Passenger* this, char* nombre){

	int retorno = -1;

	if(nombre != NULL && this != NULL){
		strncpy(nombre, this->nombre, LEN_STRING);
		retorno = 0;
	}
	return retorno;
}

int Passenger_getApellido(Passenger* this, char* apellido){

	int retorno = -1;

	if(this != NULL && apellido != NULL){
		strncpy(apellido, this->apellido, LEN_STRING);
		retorno = 0;
	}
	return retorno;
}

int Passenger_getCodigoVuelo(Passenger* this, char* codigoVuelo){

	int retorno = -1;

	if(this != NULL && codigoVuelo != NULL){
		strncpy(codigoVuelo, this->codigoVuelo, LEN_STRING);
		retorno = 0;
	}
	return retorno;
}

int Passenger_getTipoPasajero(Passenger* this, int* tipoPasajero){

	int retorno = -1;

	if(this != NULL && tipoPasajero > 0){
		*tipoPasajero = this->tipoPasajero;
		retorno = 0;
	}
	return retorno;
}

int Passenger_getPrecio(Passenger* this, float* precio){

	int retorno = -1;

	if(this != NULL && precio > 0){
		*precio = this->precio;
		retorno = 0;
	}

	return retorno;
}

int Passenger_getEstado(Passenger* this, int* estado){

	int retorno = -1;

	if(this != NULL && estado != NULL){//>0
		*estado = this->estado;
		retorno = 0;
	}

	return retorno;
}

int Passenger_setId(Passenger* this, int id){

	int retorno = -1;

	if(this != NULL && id > 0){
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

//GUARDAR
int Passenger_setNombre(Passenger* this, char* nombre){

	int retorno = -1;

	if(nombre != NULL && this != NULL){
		strncpy(this->nombre, nombre, LEN_STRING);
		retorno = 0;
	}
	return retorno;
}

int Passenger_setApellido(Passenger* this, char* apellido){

	int retorno = -1;

	if(this != NULL && apellido != NULL){
		strncpy(this->apellido, apellido, LEN_STRING);
		retorno = 0;
	}
	return retorno;
}

int Passenger_setCodigoVuelo(Passenger* this, char* codigoVuelo){

	int retorno = -1;

	if(this != NULL && codigoVuelo != NULL){
		strncpy(this->codigoVuelo, codigoVuelo, LEN_STRING);
		retorno = 0;
	}
	return retorno;
}

int Passenger_setTipoPasajero(Passenger* this, int tipoPasajero){

	int retorno = -1;

	if(this != NULL && tipoPasajero > 0){
		this->tipoPasajero = tipoPasajero;
		retorno = 0;
	}
	return retorno;
}

int Passenger_setPrecio(Passenger* this, float precio){

	int retorno = -1;

	if(this != NULL && precio > 0){
		this->precio = precio;
		retorno = 0;
	}
	return retorno;
}

int Passenger_setEstado(Passenger* this, int estado){
	int retorno = -1;

	if(this != NULL && estado > 0){
		this->estado = estado;
		retorno = 0;
	}
	return retorno;
}

//TRADUCIR
int Passenger_translateTypeStrToInt(char* tipoPasajeroStr){

	int tipoPasajeroInt = 0;

	if(tipoPasajeroStr != NULL){
		if(strcmp(tipoPasajeroStr, "FirstClass") == 0){
			tipoPasajeroInt = 1;
		}
		if(strcmp(tipoPasajeroStr, "ExecutiveClass") == 0){
			tipoPasajeroInt = 2;
		}
		if(strcmp(tipoPasajeroStr, "EconomyClass") == 0){
			tipoPasajeroInt = 3;
		}
	}
	return tipoPasajeroInt;
}

int Passenger_translateStateStrToInt(char* estadoStr){

	int estadoInt = 0;

	if(estadoStr != NULL){
		if(strcmp(estadoStr, "En Horario") == 0){
			estadoInt = 1;
		}
		if(strcmp(estadoStr, "En Vuelo") == 0){
			estadoInt = 2;
		}
		if(strcmp(estadoStr, "Demorado") == 0){
			estadoInt = 3;
		}
		if(strcmp(estadoStr, "Aterrizado") == 0){
			estadoInt = 4;
		}
	}
	return estadoInt;
}

int Passenger_translateTypeIntToStr(int tipoPasajeroInt, char* auxTipoPasajero){

	if(tipoPasajeroInt > 0 && auxTipoPasajero != NULL){
		switch(tipoPasajeroInt){
		case 1:
			strncpy(auxTipoPasajero, "FirstClass", LEN_STRING);
			tipoPasajeroInt = 0;
			break;
		case 2:
			strncpy(auxTipoPasajero, "ExecutiveClass", LEN_STRING);
			tipoPasajeroInt = 0;
			break;
		case 3:
			strncpy(auxTipoPasajero, "EconomyClass", LEN_STRING);
			tipoPasajeroInt = 0;
			break;
		}
	}
	return tipoPasajeroInt;
}

int Passenger_translateStateIntToStr(int estadoInt, char* estadoStr){

	if(estadoInt > 0 && estadoStr != NULL){
		switch(estadoInt){
			case 1:
				strncpy(estadoStr, "En Horario", LEN_STRING);
				estadoInt = 0;

				break;
			case 2:
				strncpy(estadoStr, "En Vuelo", LEN_STRING);
				estadoInt = 0;
				break;
			case 3:
				strncpy(estadoStr, "Demorado", LEN_STRING);
				estadoInt = 0;
				break;
			case 4:
				strncpy(estadoStr, "Aterrizado", LEN_STRING);
				estadoInt = 0;
				break;
		}
	}
	return estadoInt;
}

//LISTAR
int Passenger_print(Passenger* this){

	int retorno = -1;
	int id;
	int estadoPasajero;
	char aux_EstadoPasajero[50];
	int tipoPasajero;
	char aux_TipoPasajero[50];
	char nombre[50];
	char apellido[50];
	char codigoVuelo[50];
	float precio;

	if(this != NULL){
		Passenger_getId(this, &id);
		Passenger_getNombre(this, nombre);
		Passenger_getApellido(this, apellido);
		Passenger_getPrecio(this, &precio);
		Passenger_getCodigoVuelo(this, codigoVuelo);
		Passenger_getTipoPasajero(this, &tipoPasajero);
		Passenger_getEstado(this, &estadoPasajero);

		Passenger_translateTypeIntToStr(tipoPasajero, aux_TipoPasajero);
		Passenger_translateStateIntToStr(estadoPasajero, aux_EstadoPasajero);

		printf("%d \t%-7s \t%-7s \t%0.2f \t%-7s \t%-7s \t%-7s\n",
				id, nombre, apellido, precio, codigoVuelo, aux_TipoPasajero, aux_EstadoPasajero);
		retorno = 0;
	}
	return retorno;
}

//MODIFICAR
int Passenger_edit(Passenger* this){

	int retorno = -1;
	int opcion;

	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	int estado;

	char messageOk[250];
	strcpy(messageOk, "Operación exitosa");

	if(this != NULL){
		do{
			puts("¿Qué desea modificar?\n");
			puts("1. NOMBRE");
			puts("2. APELLIDO");
			puts("3. PRECIO");
			puts("4. TIPO DE PASAJERO");
			puts("5. ESTADO DE VUELO");
			getInt("", &opcion);
			if(opcion < 1 || opcion > 5){
				puts("Error, intene nuevamente\n");
				puts("-----------------------------------------------------------------------------------------------------");
			}
		}while(opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 && opcion != 5);
			switch(opcion){
				case 1:
					getString("NOMBRE: ", nombre);
					printf("lo que escribi: %s\n", nombre);
					if(Passenger_setNombre(this, nombre) == 0){
						retorno = 0;
					}
					break;
				case 2:
					getString("APELLIDO: ", apellido);
					if(Passenger_setApellido(this, apellido) == 0){
						retorno = 0;
					}
					break;
				case 3:
					getFloat("PRECIO: ", &precio);
					if(Passenger_setPrecio(this, precio) == 0){
						retorno = 0;
					}
					break;
				case 4:
					getInt("\nTIPO DE PASAJERO:\n 1. FirstClass\n 2. ExecutiveClass\n 3. EconomyClass\n", &tipoPasajero);
					if(Passenger_setTipoPasajero(this, tipoPasajero) == 0){
						retorno = 0;
					}
					break;
				case 5:
					getInt("\nESTADO DE VUELO:\n\n1. En Horario\n2. En Vuelo\n3. Demorado\n4. Aterrizado\n", &estado);
					if(Passenger_setEstado(this, estado) == 0){
						retorno = 0;
					}
					break;
			}
		}
	return retorno;
}

//COMPARAR
int Passenger_compareById(void* this, void* this2){

	int retorno = 0;
	int aux_id;
	int aux_id2;

	if(this != NULL && this2 != NULL){
		Passenger_getId((Passenger*) this, &aux_id);
		Passenger_getId((Passenger*) this2, &aux_id2);
		if(aux_id > aux_id2){
			retorno = 1;
		}else if(aux_id < aux_id2){
			retorno = -1;
		}
	}
	return retorno;
}

int Passenger_compareByNombre(void* this, void* this2){

	int retorno;//no hace falta inicializar en 0 porque ya tomo lo que devuelve strcmp
	char nombre[128];
	char nombre2[128];

	if(this != NULL && this2 != NULL){
		Passenger_getNombre((Passenger*) this, nombre);
		Passenger_getNombre((Passenger*) this2, nombre2);
		retorno = strcmp(nombre, nombre2);
	}
	return retorno;
}

int Passenger_compareByApellido(void* this, void* this2){

	int retorno;
	char apellido[128];
	char apellido2[128];

	if(this != NULL && this2 != NULL){
		Passenger_getApellido((Passenger*) this, apellido);
		Passenger_getApellido((Passenger*) this2, apellido2);
		retorno = strcmp(apellido, apellido2);
	}
	return retorno;
}

int Passenger_compareByPrecio(void* this, void* this2){

	int retorno;
	float precio;
	float precio2;

	if(this != NULL && this2 != NULL){
		Passenger_getPrecio((Passenger*) this, &precio);
		Passenger_getPrecio((Passenger*) this2, &precio2);
		if(precio > precio2){
			retorno = 1;
		}else if(precio < precio2){
			retorno = -1;
		}
	}
	return retorno;
}

int Passenger_compareByTipo(void* this, void* this2){

	int retorno = 0;
	int tipo;
	int tipo2;

	if(this != NULL && this2 != NULL){
		Passenger_getTipoPasajero((Passenger*) this, &tipo);
		Passenger_getTipoPasajero((Passenger*) this2, &tipo2);
		if(tipo > tipo2){
			retorno = 1;
		}else if(tipo < tipo2){
			retorno = -1;
		}
	}
	return retorno;
}

int Passenger_compareByEstado(void* this, void* this2){

	int retorno = 0;
	int estado;
	int estado2;

	if(this != NULL && this2 != NULL){
		Passenger_getEstado((Passenger*) this, &estado);
		Passenger_getEstado((Passenger*) this2, &estado2);
		if(estado > estado2) {
			retorno = 1;
		}else if(estado < estado2){
			retorno = -1;
		}
	}
	return retorno;
}

int Passenger_tipoMenu(){

	int tipoPasajero = 0;

	do{
		printf("Indique el sipo de pasajero");
		getInt("\nTIPO DE PASAJERO:\n 1. FirstClass\n 2. ExecutiveClass\n 3. EconomyClass\n", &tipoPasajero);
		if(tipoPasajero < 1 || tipoPasajero > 3){
			printf("Error, intene nuevamente\n");
		}
	}while(tipoPasajero != 1 && tipoPasajero != 2 && tipoPasajero != 3);

	return tipoPasajero;
}


int Passenger_TotalPassengerType(void* element){

	int tipoPasajero = 0;

	if(element != NULL){
		tipoPasajero = Passenger_tipoMenu();
		Passenger_getTipoPasajero((Passenger*) element, &tipoPasajero);
	}
	return tipoPasajero;
}

