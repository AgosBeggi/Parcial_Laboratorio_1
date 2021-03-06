#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "Passenger.h"

//PARSEAR
/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger);

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger);

//BUSCAR
int parser_getLastId(char* path, char* lastId);

//GUARDAR
int parser_setLastId(char* path);
