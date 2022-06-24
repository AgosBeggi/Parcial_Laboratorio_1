#include "parser.h"

//PARSEAR
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger){

	int retorno = -1;
	int items;

	char aux_id[50];
	char nombre[50];
	char apellido[50];
	char aux_precio[50];
	char codigoVuelo[50];
	char aux_tipoPasajero[50];
	char aux_estado[50];

	Passenger* pPassenger;

	if(pFile != NULL && pArrayListPassenger != NULL){
		items = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
				aux_id, nombre, apellido, aux_precio, aux_tipoPasajero, codigoVuelo, aux_estado);
		do{
			if(items == 7){
				fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
						aux_id, nombre, apellido, aux_precio, aux_tipoPasajero, codigoVuelo, aux_estado);

				parser_getLastId("Id.csv", aux_id);
				parser_setLastId("Id.csv");

				pPassenger = Passenger_newParametros(aux_id, nombre, apellido, aux_precio, codigoVuelo,	aux_tipoPasajero, aux_estado);

				if(ll_add(pArrayListPassenger, (Passenger*) pPassenger) == 0){
					retorno = 0;
				}
			}
		}while(feof(pFile) == 0);
		fclose(pFile);
	}
	return retorno;
}

int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger){

	int retorno = -1;
	int items = 0;

	Passenger* pPassenger;

	if(pFile != NULL && pArrayListPassenger != NULL){
		while(feof(pFile) == 0){
			pPassenger = Passenger_new();
			items = fread(pPassenger, sizeof(Passenger), 1, pFile);
			if(items == 1){
				if(ll_add(pArrayListPassenger, (Passenger*) pPassenger) == 0){
					retorno = 0;
				}
			}
		}
		fclose(pFile);
	}
	return retorno;
}

//BUSCAR
int parser_getLastId(char* path, char* lastId){

	int retorno = -1;
	FILE* pFile;

	if(path != NULL){
		pFile = fopen(path, "r");
		if(pFile != NULL){
			fscanf(pFile, "%[^\n]\n", lastId);
			retorno = 0;
			fclose(pFile);
		}
	}
	return retorno;
}

//GUARDAR
int parser_setLastId(char* path){

	int retorno = -1;
	FILE* pFile;
	char lastId[50];
	int idPlus;

	if(path != NULL){
		if(parser_getLastId(path, lastId) == 0){
			idPlus = atoi(lastId);
			idPlus++;
			itoa(idPlus, lastId, 10);
			pFile = fopen(path, "w");
			fprintf(pFile, "%s\n", lastId);
			retorno = 0;
		}
		fclose(pFile);
	}
	return retorno;
}
