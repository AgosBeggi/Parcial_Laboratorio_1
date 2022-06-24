#include "Controller.h"

//LEER
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger){//OK

	int retorno = -1;
	FILE* pFile;

	if(path != NULL && pArrayListPassenger != NULL){
		pFile = fopen(path, "r");
		if(pFile != NULL && parser_PassengerFromText(pFile, pArrayListPassenger) == 0){
			fclose(pFile);
			retorno = 0;
		}
	}
	return retorno;
	}

int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger){//OK

	int retorno = -1;
	FILE* pFile;

	if(path != NULL && pArrayListPassenger != NULL){
		pFile = fopen(path, "rb");
		if(pFile != NULL){
			if(parser_PassengerFromBinary(pFile, pArrayListPassenger) == 0){
				fclose(pFile);
				retorno = 0;
			}
		}
	}
	return retorno;
}

//AGREGAR
int controller_addPassenger(LinkedList* pArrayListPassenger){//OK

	int retorno;
	Passenger* auxPassenger;

	char last_Id[50];
	char aux_Nombre[128];
	char aux_Apellido[50];
	char aux_Precio[50];
	float precio;
	char auxTipoPasajero[50];
	int tipoPasajero;
	char aux_Codigo[50];
	int estadoPasajero;
	char aux_Estado[50];

	if(pArrayListPassenger != NULL){
		parser_getLastId("Id.csv", last_Id);
		if(parser_setLastId("Id.csv") == 0){
			//INGRESO NOMBRE
			getString("NOMBRE: ", aux_Nombre);
			//INGRESO APELLIDO
			getString("APELLIDO: ", aux_Apellido);
			//INGRESO PRECIO
			getFloat("PRECIO: ", &precio);
			//LO PASO A CADENA DE CARACTERES
			sprintf(aux_Precio,"%f",precio);
			do{
				//INGRESO TIPO DE PASAJERO
				printf("\nTIPO DE PASAJERO:\n 1. FirstClass\n 2. ExecutiveClass\n 3. EconomyClass\n");
				getInt("", &tipoPasajero);
				if(tipoPasajero < 1 || tipoPasajero > 3){
					printf("Error, intene nuevamente\n");
				}
			}while(tipoPasajero != 1 && tipoPasajero != 2 && tipoPasajero != 3);
			//PARSEO EL TIPO DE PASAJERO
			Passenger_translateTypeIntToStr(tipoPasajero, auxTipoPasajero);
			do{
				//INGRESO ESTADO
				printf("\nESTADO DE VUELO:\n\n 1. En Horario\n 2. En Vuelo\n 3. Demorado\n 4. Aterrizado\n");
				getInt("", &estadoPasajero);
				if(estadoPasajero < 1 || estadoPasajero > 4){
					printf("Error, intene nuevamente\n");
				}
			}while(estadoPasajero != 1 && estadoPasajero != 2 && estadoPasajero != 3 && estadoPasajero != 4);
			//PARSEO EL ESTADO DE PASAJERO
			Passenger_translateStateIntToStr(estadoPasajero, aux_Estado);
			//GENERO UN CODIGO DE VUELO
			controller_generateCode(aux_Codigo);

			auxPassenger = Passenger_newParametros(last_Id, aux_Nombre, aux_Apellido, aux_Precio, auxTipoPasajero, aux_Codigo, aux_Estado);
			retorno = ll_add(pArrayListPassenger, auxPassenger);

			Passenger_getEstado(auxPassenger, &estadoPasajero);
			Passenger_getEstado(auxPassenger, &estadoPasajero);
		}
	}
    return retorno;
}

//MODIFICAR
int controller_editPassenger(LinkedList* pArrayListPassenger){//OK

	int retorno;
	Passenger* auxPassenger;
	int id;
	int index;

	if(pArrayListPassenger != NULL){
		//IMPRIME LA LISTA
		controller_ListPassenger(pArrayListPassenger);
		//GUARDA EL ID A MODIFICAR
		getInt("Ingrese el id del pasajero que desea modificar\n", &id);
		//OBTIENE EL INDEX DEL PASAJERO
		index = controller_findIndexById(pArrayListPassenger, id);
		if(index != -1){
			//OBTIENE LA DIR DE MEMORIA DEL PASAJERO
			auxPassenger = (Passenger*) ll_get(pArrayListPassenger, index);
			//IMPRIME EL PASAJERO
			printf("ID \tNOMBRE \t\tAPELLIDO  \tPRECIO \t\tCODIGO \t\tTIPO  \t\tESTADO\n");
			Passenger_print(auxPassenger);
			puts("-----------------------------------------------------------------------------------------------------");
			if(Passenger_edit(auxPassenger) == 0){
				retorno = 0;
			}
		}
	}
	return retorno;
}

//SUPRIMIR
int controller_removePassenger(LinkedList* pArrayListPassenger){//OK

	int retorno = -1;
	Passenger* auxPassenger;
	int id;
	int index;
	int ok;

	if(pArrayListPassenger != NULL){
		if(pArrayListPassenger != NULL){
			//IMPRIME LA LISTA
			controller_ListPassenger(pArrayListPassenger);
			//GUARDA EL ID A MODIFICAR
			getInt("Ingrese el id del pasajero que desea eliminar\n", &id);
			//OBTIENE EL INDEX DEL PASAJERO
			index = controller_findIndexById(pArrayListPassenger, id);
			if(index != -1){
				//OBTIENE LA DIR DE MEMORIA DEL PASAJERO
				auxPassenger = (Passenger*) ll_get(pArrayListPassenger, index);
				//IMPRIME EL PASAJERO
				printf("ID \tNOMBRE \t\tAPELLIDO  \tPRECIO \t\tCODIGO \t\tTIPO  \t\tESTADO\n");
				Passenger_print(auxPassenger);
				puts("-----------------------------------------------------------------------------------------------------");
				printf("\n¿Confirma la operación?\n1. Si\n2. No\n");
				getInt("", &ok);
				if(ok == 1){
					ll_remove(pArrayListPassenger, index);
					Passenger_delete(auxPassenger);
					retorno = 0;
				}else{
					puts("-----------------------------------------------------------------------------------------------------");
				}
			}
		}
	}
	return retorno;
}

//LISTAR
int controller_ListPassenger(LinkedList* pArrayListPassenger){//OK

	int retorno = -1;
	Passenger* auxPassenger;
	int len;

	if(pArrayListPassenger != NULL){
		len = ll_len(pArrayListPassenger);
		 if(len > 0){
			printf("ID \tNOMBRE \t\tAPELLIDO  \tPRECIO \t\tCODIGO \t\tTIPO  \t\tESTADO\n");
			for(int i = 0; i < len; i++){
				auxPassenger = (Passenger*) ll_get(pArrayListPassenger, i);
				Passenger_print(auxPassenger);
			}
			puts("-----------------------------------------------------------------------------------------------------");
			retorno = 0;
		 }
	}
	return retorno;
}

//ORDENAR
int controller_sortPassenger(LinkedList* pArrayListPassenger){

	int retorno = -1;
	int orden;
	int criterio;

	if(pArrayListPassenger != NULL){
		puts("¿Cómo desea ordenar la lista?\n");
		puts("1. DESCENDENTE");
		puts("2. ASCENDENTE");
		puts("-----------------------------------------------------------------------------------------------------");
		getInt("", &orden);
		while(orden < 1 || orden > 2){
			printf("Opción incorrecta, vuelva a intentarlo.\n");
		}
		switch(orden){
			case 1:
				orden = 0;
				break;
			case 2:
				orden = 1;
				break;
		}
		puts("¿Cómo desea ordenar la lista?\n");
		puts("1. POR ID");
		puts("2. POR NOMBRE");
		puts("3. POR APELLIDO");
		puts("4. POR PRECIO");
		puts("5. POR TIPO");
		puts("6. POR ESTADO");
		puts("-----------------------------------------------------------------------------------------------------");
		getInt("", &criterio);
		while(criterio < 1 || criterio > 6){
			printf("Opción incorrecta, vuelva a intentarlo.\n");
		}
		switch(criterio){
			case 1:
				if(ll_sort(pArrayListPassenger, Passenger_compareById, orden) == 0){
					retorno = 0;
				}
				break;
			case 2:
				if(ll_sort(pArrayListPassenger, Passenger_compareByNombre, orden) == 0){
					retorno = 0;
				}
				break;
			case 3:
				if(ll_sort(pArrayListPassenger, Passenger_compareByApellido, orden) == 0){
					retorno = 0;
				}
				break;
			case 4:
				if(ll_sort(pArrayListPassenger, Passenger_compareByPrecio, orden) == 0){
					retorno = 0;
				}
				break;
			case 5:
				if(ll_sort(pArrayListPassenger, Passenger_compareByTipo, orden) == 0){
					retorno = 0;
				}
				break;
			case 6:
				if(ll_sort(pArrayListPassenger, Passenger_compareByEstado, orden) == 0){
					retorno = 0;
				}
				break;
		}
	}
	return retorno;
}

//GUARDAR
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger){

	int retorno = -1;
	FILE* pFile;
	Passenger* auxPassenger;
	int len;
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[50];
	int tipoPasajero;
	char aux_tipoPasajero[50];
	int estado;
	char aux_estado[50];

	if(path != NULL && pArrayListPassenger != NULL){
		pFile = fopen(path, "w");
		if(pFile != NULL){
			len = ll_len(pArrayListPassenger);
			//TITULO ASÍ NO HAGO UNA FALSA LECTURA Y PIERDO UN PASAJERO
			fprintf(pFile, "ID \tNOMBRE \t\tAPELLIDO  \tPRECIO \t\tCODIGO \t\tTIPO  \tESTADO\n");
			for(int i = 0; i < len; i++){
				auxPassenger = (Passenger*) ll_get(pArrayListPassenger, i);

				Passenger_getId(auxPassenger, &id);
				Passenger_getNombre(auxPassenger, nombre);
				Passenger_getApellido(auxPassenger, apellido);
				Passenger_getPrecio(auxPassenger, &precio);
				Passenger_getCodigoVuelo(auxPassenger, codigoVuelo);

				Passenger_getTipoPasajero(auxPassenger, &tipoPasajero);
				Passenger_translateTypeIntToStr(tipoPasajero, aux_tipoPasajero);

				Passenger_getEstado(auxPassenger, &estado);
				Passenger_translateStateIntToStr(estado, aux_estado);

				fprintf(pFile,"%d, %s, %s, %f, %s, %s, %s\n", id, nombre, apellido, precio, codigoVuelo,
						aux_tipoPasajero, aux_estado);
			}
			retorno = 0;
			fclose(pFile);
		}
	}
	return retorno;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger){

	int retorno = -1;
	FILE* pFile;
	Passenger* auxPassenger;
	int len;

	if(path != NULL && pArrayListPassenger != NULL){
		pFile = fopen(path, "wb");
		if(pFile != NULL){
			len = ll_len(pArrayListPassenger);
			for(int i = 0; i < len; i++){
				auxPassenger = (Passenger*) ll_get(pArrayListPassenger, i);
				fwrite(auxPassenger, sizeof(Passenger), 1, pFile);
			}
			retorno = 0;
			fclose(pFile);
		}
	}
	return retorno;
}

//BUSCAR
int controller_findFreePassenger(LinkedList* pArrayListPassenger){

    int retorno = -1;
    Passenger* auxPassenger;

    if(pArrayListPassenger != NULL){
    	for(int i = 0; i < ll_len(pArrayListPassenger); i ++){
    		auxPassenger = (Passenger*) ll_get(pArrayListPassenger, i);
    		if(auxPassenger == NULL){
    			retorno = i;
    			break;
    		}
    	}
    }
    return retorno;
}

int controller_findIndexById(LinkedList* pArrayListPassenger, int id){

	int retorno = -1;
	int auxId;
	int len;

	Passenger* auxPassenger;
	len = ll_len(pArrayListPassenger);

	for(int i = 0; i < len; i++){
		auxPassenger = (Passenger*) ll_get(pArrayListPassenger, i);
		if(!Passenger_getId(auxPassenger, &auxId) && auxId == id){
			retorno = i;
			break;
		}
	}
	return retorno;
}

//OTROS
void controller_generateCode(char flycode[]){

	char auxCharCode[10];

	auxCharCode[0] = 'A' + (rand() % 26);
	auxCharCode[1] = 'A' + (rand() % 26);
	auxCharCode[2] = '1' + (rand() % 9);
	auxCharCode[3] = '1' + (rand() % 9);
	auxCharCode[4] = '1' + (rand() % 9);
	auxCharCode[5] = '1' + (rand() % 9);
	auxCharCode[6] = 'A' + (rand() % 26);

	printf("CODIGO DE VUELO: %s\n", auxCharCode);

	strncpy(flycode, auxCharCode, 10);
}

int controller_Menu(LinkedList* pArrayListPassenger){

	int cantidad = -1;
	int criterio;
	int tipo;

	char aux_TipoPasajero[50];

	LinkedList* pArrayListPassenger2;

	puts("INFORMES\n");
	puts("1. Pasajeros por clase.");
	puts("2. Generar archivo de vuelos");
	puts("3. Calcular millas acumuladas");
	puts("-----------------------------------------------------------------------------------------------------");
	getInt("", &criterio);
	while(criterio < 1 || criterio > 3){
		printf("Opción incorrecta, vuelva a intentarlo.\n");
	}
	switch(criterio){
		case 1:
			tipo = Passenger_tipoMenu();
			cantidad = ll_count(pArrayListPassenger, Passenger_TotalPassengerType);
			if(cantidad > 0){
				Passenger_translateTypeIntToStr(tipo, aux_TipoPasajero);
				printf("La cantidad de pasajeros del tipo %s es: %d", aux_TipoPasajero, cantidad);
			}
			break;
		case 2:
			//LinkedList*
			pArrayListPassenger2 = ll_filter(pArrayListPassenger, Passenger_PassengerType);
			if(pArrayListPassenger2 != NULL){
				controller_saveAsText("prueba2.csv" , pArrayListPassenger2);
			}
			cantidad = 0;
			break;
		case 3:
			//LinkedList* ll_map(LinkedList* this, void (*fn)(void* element))
			cantidad = 0;
			break;
	}


	return cantidad;
}
