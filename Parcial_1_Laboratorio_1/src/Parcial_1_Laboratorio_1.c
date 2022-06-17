/*
 ============================================================================
 Name        : Parcial_1_Laboratorio_1.c
 Author      : A. Beggi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "Input.h"
#include "Menu.h"

#define ELEMENTS 1000

int main(void) {
	setbuf(stdout, NULL);

	Censista listCensista[ELEMENTS];
	char name[150];
	char lastName[150];
	int age;
	int indexCensista;
	int optionCensista;

	Address listAddress[ELEMENTS];
	char street[150];
	int streetNumber;
	char neighborhood[150];
	int optionAddress;

	Date listDate[ELEMENTS];
	int day;
	int month;
	int year;
	int optionDate;

	Zone listZone[ELEMENTS];
	int id_Zone;
	int totalAdd;
	int optionZone;
	int virtualForm;
	int paperForm;
	int absent;
	int indexZone;

	Location listLocation[ELEMENTS];
	int id_Location;
	char nameLocation[150];
	char street_1[150];
	char street_2[150];
	char street_3[150];
	char street_4[150];
	int indexLocation;
	int optionLocation;

	int option;
	int idNumber;
	int option_aux;
	int desactivate;

	int cantidadPActivos;

	char titleListArrayCensista[250];
	strcpy(titleListArrayCensista, "ID \t|NOMBRE \t\t|APELLIDO  \t\t|FECHA NAC. \t|EDAD \t|DIRECCION  \t\t|BARRIO  \t\t|ZONA  \t\t|ESTADO\n");

	char printPromedioDeCensosPorCensista[250];
	strcpy(printPromedioDeCensosPorCensista, "ID \t|NOMBRE \t\t|APELLIDO  \t\t|FECHA NAC. \t|EDAD \t|DIRECCION  \t\t|BARRIO  \t\t|ZONA  \t\t|PROM  \t\t|ESTADO\n");

	char titleListCensista[250];
	strcpy(titleListCensista, "ID \t|NOMBRE \t\t|APELLIDO  \t\t|FECHA NAC. \t|EDAD \t|DIRECCION  \t\t|BARRIO  \t\t|ZONA  \t\t|ESTADO\n");

	char messageOk[250];
	strcpy(messageOk, "Operación exitosa");

	char messageError[250];
	strcpy(messageError, "Ingreso incorrecto, vuelva a intentarlo.\n");

	char optiondModifyCensista[250];
	strcpy(optiondModifyCensista, "¿Qué desea modificar?\n1. NOMBRE\n2. APELLIDO\n3. EDAD\n4. FECHA DE NACIMIENTO\n5. DIRECCION\n6. DESACTIVAR\n");

	char titleLocation[250];
	strcpy(titleLocation, "ID \t|LOCALIDAD \t\t|CALLE 1  \t\t|CALLE 2  \t\t|CALLE 3  \t\t|CALLE 4  \t\t|ESTADO\n");

	char titleZoneLocation[250];
	strcpy(titleZoneLocation, "ID \t|LOCALIDAD \t\t|CALLE 1  \t\t|CALLE 2  \t\t|CALLE 3  \t\t|CALLE 4  \t\t|CENSISTA  \t\t\t|ESTADO\n");

	char titleZoneFinished[250];
	strcpy(titleZoneFinished, "ID \t|LOCALIDAD  \t\t|CENSISTA  \t\t\t|PAPEL  |VIRTUAL |AUSENTE |TOTAL |ESTADO\n");

	char titleAllZoneFinished[250];
	strcpy(titleAllZoneFinished, "ID \t|LOCALIDAD  \t\t|CENSISTA  \t\t\t|PAPEL  |VIRTUAL |AUSENTE |TOTAL |ESTADO\n");

	if(startMenu(listCensista, ELEMENTS, listZone, ELEMENTS) == 0){
		puts("------------------------------------------------------------------------------------------------------------------------------------------");
		puts("\t\t\t\t\t\tBIENVENIDO");
		puts("------------------------------------------------------------------------------------------------------------------------------------------");
		puts("(Presiona 0 para carga automática)");
		puts("------------------------------------------------------------------------------------------------------------------------------------------");

		do{

			puts("INGRESE UNA OPCIÓN\n");

			puts("1. CARGA DE CENSISTA");
			puts("2. MODIFICAR CENSISTA");
			puts("3. BAJA DE CENSISTA");
			puts("4. CARGA DE ZONA");
			puts("5. ASIGNAR ZONA");
			puts("6. CARGA DE DATOS");
			puts("7. MOSTRAR CENSISTAS");
			puts("8. MOSTRAR ZONAS");
			puts("9. INFORMES");
			puts("10. SALIR");
			puts("------------------------------------------------------------------------------------------------------------------------------------------");
			if(getInt("", &option) == 0){
				puts("------------------------------------------------------------------------------------------------------------------------------------------");

				switch(option){
					case 0:
						if(hardcodeAddDataMenu(listCensista, ELEMENTS, listDate, ELEMENTS, listAddress, ELEMENTS, listZone, ELEMENTS, listLocation, ELEMENTS) == 0){
							printf("%s\n", messageOk);
						}
						puts("------------------------------------------------------------------------------------------------------------------------------------------");
					break;
					case 1:
						//CARGA DE CENSISTA

						while(getStrings("1. NOMBRE: ", name) != 0){
							printf("%s\n", messageError);
						}
						while(getStrings("2. APELLIDO: ", lastName) != 0){
							printf("%s\n", messageError);
						}
						while(getIntMinMax("3. EDAD: ", 18, 60, &age) != 0){
							printf("%s\n", messageError);
						}
						puts("4. FECHA DE NACIMIENTO: ");
						while(getIntMinMax("DIA: ", 1, 31, &day) != 0){
							printf("%s\n", messageError);
						}
						while(getIntMinMax("MES: ", 1, 12, &month) != 0){
							printf("%s\n", messageError);
						}
						while(getIntMinMax("ANIO: ", 1962, 2004,  &year) != 0){
							printf("%s\n", messageError);
						}
						puts("5. DIRECCION");
						while(getStrings("CALLE: ", street) != 0){
							printf("%s\n", messageError);
						}
						while(getInt("ALTURA: ", &streetNumber) != 0){
							printf("%s\n", messageError);
						}
						while(getStrings("BARRIO: ", neighborhood) != 0){
							printf("%s\n", messageError);
						}
						if(singUpCensistaMenu(listCensista, ELEMENTS, name, lastName, age, day, month, year, street, streetNumber, neighborhood, listDate, ELEMENTS, listAddress, ELEMENTS) == 0){
							puts("------------------------------------------------------------------------------------------------------------------------------------------");
							printf("%s\n", messageOk);//OK
						}
						puts("------------------------------------------------------------------------------------------------------------------------------------------");
						break;
					case 2:
						//MODIFICAR CENSISTA
						printf("\n%s", titleListArrayCensista);
						puts("------------------------------------------------------------------------------------------------------------------------------------------");
						printCensistaListMenu(listZone, ELEMENTS, listCensista, ELEMENTS, listLocation, ELEMENTS);
						puts("------------------------------------------------------------------------------------------------------------------------------------------");
						getInt("Ingrese el id del censista que desea modificar\n", &idNumber);

						findCensistaIndexById(listCensista, ELEMENTS, idNumber, &indexCensista);
						if(indexCensista != -1){
							id_Zone =  findZoneIdByCensista(listZone, ELEMENTS, idNumber);
							findZoneIndexById(listZone, ELEMENTS, id_Zone, &indexZone);
							if(findLocationIndexByIdZone(listLocation, ELEMENTS, id_Zone, &indexLocation) != 0){
								printf("%s\n", messageError);
								puts("------------------------------------------------------------------------------------------------------------------------------------------");
								break;
							}
							puts("Usted eligio: \n\n");
							printf("\n%s", titleListArrayCensista);
							puts("------------------------------------------------------------------------------------------------------------------------------------------");
							printCensistaMenu(listCensista[indexCensista], listZone[indexZone], listLocation[indexLocation]);
							puts("------------------------------------------------------------------------------------------------------------------------------------------");

							puts("\n¿Desea continuar?\n");
							puts("1. SI");
							puts("2. NO");
							getInt("", &option_aux);
							if(option_aux == 1){
								do{
									printf("%s\n", optiondModifyCensista);
									getInt("", &option);
									}while(option != 1 && option != 2 && option != 3 && option != 4 && option != 5 && option != 6);
								switch(option){
									case 1:
										while(getStrings("1. NOMBRE: ", name) != 0){
											printf("%s\n", messageError);
										}
										if(modificationsCensistaMenu(listCensista, ELEMENTS,	name, name, age, idNumber, option) == 0){
											printf("%s\n", messageOk);//OK
										}
									break;
									case 2:
										while(getStrings("2. APELLIDO: ", lastName) != 0){
											printf("%s\n", messageError);
										}
										if(modificationsCensistaMenu(listCensista, ELEMENTS,	name, lastName, age, idNumber, option) == 0){
											printf("%s\n", messageOk);//OK
										}
									break;
									case 3:
										while(getInt("3. EDAD: ", &age) != 0){
											printf("%s\n", messageError);
										}
										if(modificationsCensistaMenu(listCensista, ELEMENTS,	name, lastName, age, idNumber, option) == 0){
											printf("%s\n", messageOk);//OK
										}
									break;
									case 4:
										do{
											puts("¿Qué desea modificar?\n1. DIA\n2. MES\n3. ANIO\n");
											getInt("", &optionDate);
										}while(optionDate != 1 && optionDate != 2 && optionDate != 3);
										switch(optionDate){
											case 1:
												while(getInt("DIA: ", &day) != 0){
													printf("%s\n", messageError);//OK
												}
												break;
											case 2:
												while(getInt("MES: ", &month) != 0){
													printf("%s\n", messageError);//OK
												}
												break;
											case 3:
												while(getInt("ANIO: ", &year) != 0){
													printf("%s\n", messageError);//OK
												}
												break;
										}
										if(modificationsDateMenu(listCensista, ELEMENTS, day, month, year, idNumber, optionDate, listDate, ELEMENTS) == 0){
											printf("%s\n", messageOk);
										}
									break;
									case 5:
										do{
											puts("¿Qué desea modificar?\n1. CALLE\n2. ALTURA\n3. BARRIO\n");
											getInt("", &optionAddress);
										}while(optionAddress != 1 && optionAddress != 2 && optionAddress != 3);
										switch(optionAddress){
											case 1:
												while(getStrings("CALLE: ", street) != 0){
													printf("%s\n", messageError);
												}
												printf("%s\n", street);
												break;
											case 2:
												while(getInt("ALTURA: ", &streetNumber) != 0){
													printf("%s\n", messageError);
												}
												break;
											case 3:
												while(getStrings("BARRIO: ", neighborhood) != 0){
													printf("%s\n", messageError);
												}
												break;
										}
										if(modificationsAddressMenu(listCensista, ELEMENTS, street, streetNumber, neighborhood, idNumber, optionAddress, listAddress, ELEMENTS) == 0){
											printf("%s\n", messageOk);
										}
									break;
									case 6://DESACTIVAR
										puts("Está a punto de desactivar al censista");
										puts("¿Desea continuar?\n");
										puts("1. SI");
										puts("2. NO");
										if(getInt("", &desactivate) == 0){
											if(modifyCensistaState(listCensista, ELEMENTS, idNumber, 3)){
												printf("%s\n", messageOk);
											}
										}
									break;
								}
							}
						}else{
							printf("\n%s\n", messageError);
						}
						puts("------------------------------------------------------------------------------------------------------------------------------------------");
						break;
					case 3:
						printf("\n%s", titleListArrayCensista);
						puts("------------------------------------------------------------------------------------------------------------------------------------------");
						printCensistaList(listCensista, ELEMENTS);
						puts("------------------------------------------------------------------------------------------------------------------------------------------");
						getInt("Ingrese el id del censista que desea eliminar\n", &idNumber);

						if(findCensistaIndexById(listCensista, ELEMENTS, idNumber, &indexCensista) == 0){
							puts("Usted eligio: \n\n");
							printf("%s", titleListCensista);
							puts("------------------------------------------------------------------------------------------------------------------------------------------");
							printCensista(listCensista[indexCensista]);
							puts("------------------------------------------------------------------------------------------------------------------------------------------");

							puts("\n¿Desea continuar?\n");
							puts("1. SI");
							puts("2. NO");
							getInt("", &option_aux);
							if(option_aux == 1){
								if(removeCensistaMenu(listCensista, ELEMENTS, idNumber, listDate, ELEMENTS, listAddress, ELEMENTS) == 0){
								printf("%s\n", messageOk);//OK
								}
							}
						}else{
							printf("%s\n", messageError);
						}
						puts("------------------------------------------------------------------------------------------------------------------------------------------");
						break;
					case 4:
						//CARGA DE ZONA
						while(getStrings("1. LOCALIDAD: ", nameLocation) != 0){
							printf("%s\n", messageError);
						}
						while(getStrings("CALLE 1: ", street_1) != 0){
							printf("%s\n", messageError);
						}
						while(getStrings("CALLE 2: ", street_2) != 0){
							printf("%s\n", messageError);
						}
						while(getStrings("CALLE 3: ", street_3) != 0){
							printf("%s\n", messageError);
						}
						while(getStrings("CALLE 4: ", street_4) != 0){
							printf("%s\n", messageError);
						}

						if(singUpZoneMenu(listZone, ELEMENTS,	nameLocation, street_1, street_2, street_3, street_4, listLocation, ELEMENTS) == 0){
							printf("%s\n", messageOk);//OK
						}
						puts("------------------------------------------------------------------------------------------------------------------------------------------");
						break;
					case 5:
						//ASIGNAR ZONA
						printf("\n%s", titleLocation);
						puts("------------------------------------------------------------------------------------------------------------------------------------------");
						printLocationList(listLocation, ELEMENTS);//OK
						puts("------------------------------------------------------------------------------------------------------------------------------------------");
						getInt("Ingrese el id de la localidad\n", &id_Location);

						if(checkStateAssignLocationList(listLocation, ELEMENTS, id_Location) == 1){
							puts("------------------------------------------------------------------------------------------------------------------------------------------");
							puts("La zona ya esta asignada. Intente nuevamente");
							puts("------------------------------------------------------------------------------------------------------------------------------------------");
							break;
						}
						if(checkStateAssignLocationList(listLocation, ELEMENTS, id_Location) == 2){
							puts("------------------------------------------------------------------------------------------------------------------------------------------");
							puts("Zona finalizada. Intente nuevamente");
							puts("------------------------------------------------------------------------------------------------------------------------------------------");
							break;
						}

						 if(findLocationById(listLocation, ELEMENTS, id_Location, &indexLocation) == 0){
							puts("Usted eligio: \n\n");
							printf("%s", titleLocation);//OK
							puts("------------------------------------------------------------------------------------------------------------------------------------------");
							printLocation(listLocation[indexLocation]);
							puts("------------------------------------------------------------------------------------------------------------------------------------------");

							puts("\n¿Desea continuar?\n");
							puts("1. SI");
							puts("2. NO");
							getInt("", &optionLocation);

							if(optionLocation == 1){
								optionLocation = -1;
								do{
									printf("\n%s", titleListCensista);
									puts("------------------------------------------------------------------------------------------------------------------------------------------");
									printCensistaList(listCensista, ELEMENTS);
									puts("------------------------------------------------------------------------------------------------------------------------------------------");
									getInt("Ingrese el id del censista que desea asignar\n", &idNumber);

									indexCensista = findCensistaById(listCensista, ELEMENTS, idNumber);

									puts("Usted eligio: \n\n");
									printf("%s", titleListCensista);
									puts("------------------------------------------------------------------------------------------------------------------------------------------");
									printCensista(listCensista[indexCensista]);
									puts("------------------------------------------------------------------------------------------------------------------------------------------");

									puts("\n¿Desea continuar?\n");
									puts("1. SI");
									puts("2. NO");
									getInt("", &optionCensista);
									if(optionCensista == 1){
										optionCensista = -1;
										if(assignZoneMenu(listZone, ELEMENTS, listCensista, ELEMENTS, idNumber, listLocation, ELEMENTS, id_Location) == 0){
										printf("%s\n", messageOk);
										}
									}
								}while(optionCensista != -1);
							}
						 }else{
							 printf("%s\n", messageError);
						 }
						puts("------------------------------------------------------------------------------------------------------------------------------------------");
						break;
					case 6:
						//CARGA DE DATOS
						printf("\n%s", titleZoneLocation);
						puts("------------------------------------------------------------------------------------------------------------------------------------------");
						printZoneDataList(listZone, ELEMENTS, listCensista, ELEMENTS, listLocation, ELEMENTS);//OK
						puts("------------------------------------------------------------------------------------------------------------------------------------------");
						getInt("Ingrese el id de la zona\n", &id_Zone);

						if(checkStateFinishZoneList(listZone, ELEMENTS, id_Zone) == 0){
							puts("Esa zona ya esta finalizada. Intente nuevamente");
							puts("------------------------------------------------------------------------------------------------------------------------------------------");
							break;
						}

						if(findZoneIndexById(listZone, ELEMENTS, id_Zone, &indexZone) != 0){
							printf("%s\n", messageError);
							puts("------------------------------------------------------------------------------------------------------------------------------------------");
							break;
						}
						if(findCensistaIndexByIdZone(listCensista, ELEMENTS, id_Zone, &indexCensista) != 0){
							printf("%s\n", messageError);
							puts("------------------------------------------------------------------------------------------------------------------------------------------");
							break;
						}
						if(findLocationIndexByIdZone(listLocation, ELEMENTS, id_Zone, &indexLocation) != 0){
							printf("%s\n", messageError);
							puts("------------------------------------------------------------------------------------------------------------------------------------------");
							break;
						}

						puts("Usted eligio: \n\n");
						printf("%s", titleZoneLocation);
						puts("------------------------------------------------------------------------------------------------------------------------------------------");
						printZoneData(listZone[indexZone], listCensista[indexCensista], listLocation[indexLocation]);//NO OK
						puts("------------------------------------------------------------------------------------------------------------------------------------------");

						puts("\n¿Desea continuar?\n");
						puts("1. SI");
						puts("2. NO");
						getInt("", &optionZone);

						if(optionZone == 1){
							while(getInt("1. CENSOS PRECENCIALES: ", &paperForm) != 0){
								printf("%s\n", messageError);
							}
							while(getInt("2. CENSOS VIRTUALES: ", &virtualForm) != 0){
								printf("%s\n", messageError);
							}
							while(getInt("3. AUSENTES: ", &absent) != 0){
								printf("%s\n", messageError);
							}
							totalAdd = paperForm + virtualForm + absent;

							if(addDataMenu(listZone, ELEMENTS, id_Zone, paperForm, virtualForm, absent, totalAdd)){
								printf("%s\n", messageOk);//NO IMPRIME
							}
						}
						puts("------------------------------------------------------------------------------------------------------------------------------------------");
						break;
					case 7:
						//MOSTRAR CENSISTAS
						printf("\n%s", titleListCensista);//OK
						puts("------------------------------------------------------------------------------------------------------------------------------------------");
						printCensistaListMenu(listZone, ELEMENTS, listCensista, ELEMENTS, listLocation, ELEMENTS);
						puts("------------------------------------------------------------------------------------------------------------------------------------------");
						break;
					case 8:
						//MOSTRAR ZONAS
						printf("\n%s", titleZoneFinished);//OK
						puts("------------------------------------------------------------------------------------------------------------------------------------------");
						printAllZoneDataList(listZone, ELEMENTS, listCensista, ELEMENTS, listLocation, ELEMENTS);
						puts("------------------------------------------------------------------------------------------------------------------------------------------");
						break;
					case 9:
						//INFORMES//
						cantidadPActivos = cantidadCensistasEstadoActivoZonaPendiente(listZone, ELEMENTS, listCensista, ELEMENTS, listLocation, ELEMENTS);
						printf("a. Informar cantidad de censistas en estado Activo con zona Pendiente: %d\n", cantidadPActivos);
						puts("------------------------------------------------------------------------------------------------------------------------------------------");
						printf("b. Mostrar el listado de censistas de Avellaneda, Lanús, Lomas de Zamora o Banfield	ordenados alfabéticamente por apellido y nombre.\n");
						puts("------------------------------------------------------------------------------------------------------------------------------------------");
						printf("\n%s", titleListCensista);//OK
						puts("------------------------------------------------------------------------------------------------------------------------------------------");
						printCensistaEspecificosListMenu(listZone, ELEMENTS, listCensista, ELEMENTS, listLocation, ELEMENTS);
						puts("------------------------------------------------------------------------------------------------------------------------------------------");
						id_Location = totalZoneAbsent(listZone, ELEMENTS);
						findLocationById(listLocation, ELEMENTS, id_Location, &indexLocation);
						printf("c. Localidad con más casas ausentes: %s\n", listLocation[indexLocation].name);
						puts("------------------------------------------------------------------------------------------------------------------------------------------");
						printf("d. Censista cuya zona fue la más censada (total censados presencial y virtual): \n");
						puts("------------------------------------------------------------------------------------------------------------------------------------------");
						idNumber = totalZonePeperVirtual(listZone, ELEMENTS);
						findCensistaIndexById(listCensista, ELEMENTS, idNumber, &indexCensista);
						printf("%s, %s\n", listCensista[indexCensista].name, listCensista[indexCensista].lastName);
						puts("------------------------------------------------------------------------------------------------------------------------------------------");
						printf("e. Informar el promedio de censos por censista/zona.\n");
						puts("------------------------------------------------------------------------------------------------------------------------------------------");
						printf("\n%s", printPromedioDeCensosPorCensista);//OK
						puts("------------------------------------------------------------------------------------------------------------------------------------------");
						promedioDeCensosPorCensista(listZone, ELEMENTS, listCensista, ELEMENTS, listLocation, ELEMENTS);
						puts("------------------------------------------------------------------------------------------------------------------------------------------");
						break;
					case 10:
						puts("\t\t\t\t\t\tGRACIAS");
						puts("------------------------------------------------------------------------------------------------------------------------------------------");
						break;
				}
			}
		}while(option != 10);
	}
	puts("\nPARCIAL_1\nBeggi A.");
	return EXIT_SUCCESS;
}

/******************************************************************************

PUNTEROS

1-Realizar una función que reciba un puntero a char y dos char.
La función deberá reemplazar en la cadena cada ocurrencia del primer carácter recibido,
por el segundo. Retornando la cantidad de reemplazos o -1 en caso de error.
Utilizar aritmetica de punteros

2-Realizar una función que reciba como parámetros un array de enteros y un entero por referencia.
La función calculará el valor máximo de ese array y utilizará el valor por referencia para retornar ese valor.
Utilizar aritmetica de punteros

3-Dada la siguiente estructura: int legajo; char nombre[20]; int edad;
Realizar una función que cargue un array de 3 estudiantes.
Recibe un entero.
Retorna el estudiante dado de alta y por parámetro 0 si funcionó correctamente -1 mal.
Una vez devuelto el estudiante cargarlo en una posición del array.
Al final mostrar el array cargado
Utilizar aritmetica de punteros

 4-Dada la siguiente estructura: int legajo; char nombre[20]; int edad;
Realizar una función que cargue un array de 3 estudiantes.
Recibe un puntero al array de estudiantes, lo carga y retorna 0 si funcionó correctamente -1 mal.
Una vez cargados los estudiantes mostrar el array cargado
Utilizar aritmetica de punteros

******************************************************************************
#include <stdio.h>
#include <string.h>

typedef struct{
    int legajo;
    char nombre[20];
    int edad;
}Alumno;

int funcionUno(char* pChar, char a, char b);
int funcionDos(int* arrayInt, int* pInt, int len);
Alumno funcionTres(int* retorno);
int funcionCuatro(Alumno* arrayAlumno, int len);

int main()
{
    char cadena[10] = {'h', 'o', 'l', 'a', '\0'};
    char a = 'o';
    char b = 'x';

    int array[10] = {2,5,9,7,9};
    int mayor;

    int retorno;
	Alumno estudiantes[3];

    printf("Cadena: %s\n", cadena);
    printf("Cantidad de cambios: %d\n", funcionUno(cadena, a, b));
    printf("Cadena: %s\n", cadena);

    if(funcionDos(array, &mayor, 10)){
        printf("El mayor numero es: %d\n", mayor);
    }

    for(int i=0;i<3;i++)
	{
		estudiantes[i]=funcionTres(&retorno);
		if(!retorno)
		{
			printf("Todo ok\n");
		}
	}

	for(int i=0;i<3;i++)
	{
		printf("nombre: %s\n",estudiantes[i].nombre);
	}

    return 0;
}

int funcionUno(char* pChar, char a, char b){

    int retorno = -1;

    if(pChar != NULL){
        retorno = 0;
        for(int i = 0; i < strlen(pChar); i++){
            if(*(pChar+i) == a){//es lo mismo que poner pChar[i] == a
               *(pChar+i) = b;//es lo mismo que poner pChar[i] = b;
               retorno ++;
            }
        }
    }

    return retorno;
}

int funcionDos(int* arrayInt, int* pInt, int len){

    int retorno = -1;
    int flag = 0;
    int mayor;


    if(pInt != NULL){
        for(int i = 0; i < len; i++){
            if(flag == 0 || mayor < *(arrayInt+i)){
               mayor = *(arrayInt+i);
               flag = 1;
            }
        }
    }

    *pInt = mayor;

    return retorno;
}

Alumno funcionTres(int* retorno){

    Alumno aux;
    int auxRetorno;

    if(retorno != NULL){

        auxRetorno = -1;
        puts("Ingrese el legajo");
        scanf("%d", &aux.legajo);
        puts("Ingrese el nombre");
    	fflush(stdin);
		scanf("%s", aux.nombre);
        puts("Ingrese la edad");
        scanf("%d", &aux.edad);
    }

    if(aux.legajo > 0){
        auxRetorno = 0;
        *retorno = auxRetorno;
    }

    return aux;
}

int funcionCuatro(Alumno* arrayAlumno, int len){

    int retorno = -1;

    if(arrayAlumno != NULL && len > 0){

        for(int i = 0; i < len; i++){
            puts("Ingrese el legajo");
            scanf("%d", *(arrayAlumno+i)->legajo);
            puts("Ingrese el nombre");
        	fflush(stdin);
    		scanf("%s", &(*(arrayAlumno+i)).nombre);
            puts("Ingrese la edad");
            scanf("%d", &(*arrayAlumno+i).edad);
        }
        retorno = 0;
    }
    return retorno;
}
 */
