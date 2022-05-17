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

	char titleListCensista[250];
	strcpy(titleListCensista, "ID \tNOMBRE \t\t\tAPELLIDO  \tFECHA NAC. \tEDAD \tDIRECCION  \t\tBARRIO  \tESTADO\n");

	char messageOk[250];
	strcpy(messageOk, "Operación exitosa");

	char optiondModifyCensista[250];
	strcpy(optiondModifyCensista, "¿Qué desea modificar?\n1. NOMBRE\n2. APELLIDO\n3. EDAD\n4. FECHA DE NACIMIENTO\n5. DIRECCION\n");

	char titleLocation[250];
	strcpy(titleLocation, "ID \tLOCACION \tCALLE 1  \tCALLE 2  \tCALLE 3  \tCALLE 4\n");

	char titleZone[250];
	strcpy(titleZone, "ID \tLOCACION \t\t\tCENSISTA  \t\t\t\tCALLES  \t\t\t\tESTADO\n");
	char titleZoneFinished[250];
	strcpy(titleZoneFinished, "ID \tLOCALIDAD \t\tCALLE 1  \t\tCALLE 2  \t\tCALLE 3  \t\tCALLE 4  \t\tCENSISTA  \tPRES  \tVIR  \tAUS  \tESTADO\n");

	if(startMenu(listCensista, ELEMENTS, listZone, ELEMENTS) == 0){
		puts("-----------------------------------------------------------------------------------------------------");
		puts("\t\t\t\t\t\tBIENVENIDO");
		puts("-----------------------------------------------------------------------------------------------------");
		puts("(Presiona 0 para carga automática)");
		puts("-----------------------------------------------------------------------------------------------------");

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
			puts("-----------------------------------------------------------------------------------------------------");
			if(getInt("", &option) == 0){
				puts("-----------------------------------------------------------------------------------------------------");

				switch(option){
					case 0:
						if(hardcodeAddDataMenu(listCensista, ELEMENTS, listDate, ELEMENTS, listAddress, ELEMENTS, listZone, ELEMENTS, listLocation, ELEMENTS)){
							printf("%s\n", messageOk);
						}
						puts("-----------------------------------------------------------------------------------------------------");
					break;
					case 1:
						//CARGA DE CENSISTA
						getString("1. NOMBRE: ", name);
						getString("2. APELLIDO: ", lastName);
						getInt("3. EDAD", &age);

						puts("4. FECHA DE NACIMIENTO: ");
						getInt("DIA: ", &day);
						getInt("MES: ", &month);
						getInt("ANIO: ", &year);

						puts("5. DIRECCION");
						getString("CALLE: ", street);
						getInt("ALTURA: ", &streetNumber);
						getString("BARRIO: ", neighborhood);

						if(singUpCensistaMenu(listCensista, ELEMENTS, name, lastName, age, day, month, year, street, streetNumber, neighborhood, listDate, ELEMENTS, listAddress, ELEMENTS) == 0){
							puts("-----------------------------------------------------------------------------------------------------");
							printf("%s\n", messageOk);
						}
						puts("-----------------------------------------------------------------------------------------------------");
						break;
					case 2:
						//MODIFICAR CENSISTA
						printf("%s", titleListCensista);
						printCensistaList(listCensista, ELEMENTS);
						puts("-----------------------------------------------------------------------------------------------------");
						getInt("Ingrese el id del censista que desea modificar\n", &idNumber);

						indexCensista = findCensistaById(listCensista, ELEMENTS, idNumber);

						puts("Usted eligio: \n\n");
						printf("%s", titleListCensista);
						printCensista(listCensista[indexCensista]);
						puts("-----------------------------------------------------------------------------------------------------");

						puts("\n¿Desea continuar?\n");
						puts("1. SI");
						puts("2. NO");
						getInt("", &option_aux);
						if(option_aux == 1){
							do{
								printf("%s\n", optiondModifyCensista);
								getInt("", &option);
								}while(option != 1 && option != 2 && option != 3 && option != 4 && option != 5);
							switch(option){
								case 1:
									getString("1. NOMBRE: ", name);
									if(modificationsCensistaMenu(listCensista, ELEMENTS,	name, lastName, age, idNumber, option) == 0){
										printf("%s\n", messageOk);
									}
								break;
								case 2:
									getString("2. APELLIDO: ", lastName);
									if(modificationsCensistaMenu(listCensista, ELEMENTS,	name, lastName, age, idNumber, option) == 0){
										printf("%s\n", messageOk);
									}
								break;
								case 3:
									getInt("3. EDAD", &age);
									if(modificationsCensistaMenu(listCensista, ELEMENTS,	name, lastName, age, idNumber, option) == 0){
										printf("%s\n", messageOk);
									}
								break;
								case 4:
									do{
										puts("¿Qué desea modificar?\n1. DIA\n2. MES\n3. ANIO\n");
										getInt("", &optionDate);
									}while(optionDate != 1 && optionDate != 2 && optionDate != 3);
									switch(optionDate){
										case 1:
											getInt("DIA: ", &day);
											break;
										case 2:
											getInt("MES: ", &month);
											break;
										case 3:
											getInt("ANIO: ", &year);
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
											getString("CALLE: ", street);
											break;
										case 2:
											getInt("ALTURA: ", &streetNumber);
											break;
										case 3:
											getString("BARRIO: ", neighborhood);
											break;
									}
									if(modificationsAddressMenu(listCensista, ELEMENTS, street, streetNumber, neighborhood, idNumber, optionDate, listAddress, ELEMENTS) == 0){
										printf("%s\n", messageOk);
									}
								break;
							}
						}
						puts("-----------------------------------------------------------------------------------------------------");
						break;
					case 3:
						//BAJA DE CENSISTA
						printf("%s", titleListCensista);
						printCensistaList(listCensista, ELEMENTS);
						puts("-----------------------------------------------------------------------------------------------------");
						getInt("Ingrese el id del censista que desea eliminar\n", &idNumber);

						indexCensista = findCensistaById(listCensista, ELEMENTS, idNumber);

						puts("Usted eligio: \n\n");
						printf("%s", titleListCensista);
						printCensista(listCensista[indexCensista]);
						puts("-----------------------------------------------------------------------------------------------------");

						puts("\n¿Desea continuar?\n");
						puts("1. SI");
						puts("2. NO");
						getInt("", &option_aux);
						if(option_aux == 1){
							if(removeCensistaMenu(listCensista, ELEMENTS, idNumber, listDate, ELEMENTS, listAddress, ELEMENTS) == 0){
							printf("%s\n", messageOk);
							}
						}
						puts("-----------------------------------------------------------------------------------------------------");
						break;
					case 4:
						//CARGA DE ZONA
						getString("1. LOCALIDAD: ", nameLocation);
						getString("CALLE 1: ", street_1);
						getString("CALLE 2: ", street_2);
						getString("CALLE 3: ", street_3);
						getString("CALLE 4: ", street_4);

						if(singUpZoneMenu(listZone, ELEMENTS,	nameLocation, street_1, street_2, street_3, street_4, listLocation, ELEMENTS) == 0){
							printf("%s\n", messageOk);
						}
						puts("-----------------------------------------------------------------------------------------------------");
						break;
					case 5:
						//ASIGNAR ZONA
						do{
							printf("%s", titleLocation);
							printLocationList(listLocation, ELEMENTS);
							puts("-----------------------------------------------------------------------------------------------------");
							getInt("Ingrese el id de la localidad\n", &id_Location);

							indexLocation = findLocationById(listLocation, ELEMENTS, id_Location);

							puts("Usted eligio: \n\n");
							printf("%s", titleLocation);
							printLocation(listLocation[indexLocation]);
							puts("-----------------------------------------------------------------------------------------------------");

							puts("\n¿Desea continuar?\n");
							puts("1. SI");
							puts("2. NO");
							getInt("", &optionLocation);

							if(optionLocation == 1){
								optionLocation = -1;
								do{
									printf("%s", titleListCensista);
									printCensistaList(listCensista, ELEMENTS);
									puts("-----------------------------------------------------------------------------------------------------");
									getInt("Ingrese el id del censista que desea asignar\n", &idNumber);

									indexCensista = findCensistaById(listCensista, ELEMENTS, idNumber);

									puts("Usted eligio: \n\n");
									printf("%s", titleListCensista);
									printCensista(listCensista[indexCensista]);
									puts("-----------------------------------------------------------------------------------------------------");

									puts("\n¿Desea continuar?\n");
									puts("1. SI");
									puts("2. NO");
									getInt("", &optionCensista);
									if(optionCensista == 1){
										optionCensista = -1;
										if(assignZoneMenu(listZone, ELEMENTS, listCensista, ELEMENTS, idNumber, listLocation, ELEMENTS, indexLocation) == 0){
										printf("%s\n", messageOk);
										}
									}
								}while(optionCensista != -1);
							}
						}while(optionLocation != -1);
						puts("-----------------------------------------------------------------------------------------------------");
						break;
					case 6:
						//CARGA DE DATOS
//						Carga de datos: al finalizar una zona se cargará cantidad de censados in situ, cantidad de
//						censados que completaron el formulario virtual y cantidad ausentes. De esta forma se marcará como
//						“FINALIZADO” el censo en esa zona y el censista estará disponible para una nueva asignación
//						(“LIBERADO”).
						//int totalAddCensados; // cantidad de censados in situ
						//int virtualForm; cantidad de censados que completaron el formulario virtual
						//int paperForm; cantidad ausentes


						printf("%s", titleZoneFinished);
						printListZoneCensistaList(listZone, ELEMENTS, listCensista, ELEMENTS, listLocation, ELEMENTS);
						puts("-----------------------------------------------------------------------------------------------------");
						getInt("Ingrese el id de la zona\n", &id_Zone);

						indexZone = findZoneById(listZone, ELEMENTS, id_Zone);
						indexCensista = findCensistaByZone(listCensista, ELEMENTS, id_Zone);
						indexLocation = findLocationByZone(listLocation, ELEMENTS, id_Zone);

						puts("Usted eligio: \n\n");
						printf("%s", titleZoneFinished);
						printZoneCensistaList(listZone[indexZone], listCensista[indexCensista], listLocation[indexLocation]);
						puts("-----------------------------------------------------------------------------------------------------");

						puts("\n¿Desea continuar?\n");
						puts("1. SI");
						puts("2. NO");
						getInt("", &optionZone);

						if(optionZone == 1){
							getInt("1. CENSOS PRECENCIALES: ", &paperForm);
							getInt("2. CENSOS VIRTUALES: ", &virtualForm);
							getInt("3. AUSENTES: ", &absent);
							totalAdd = paperForm + virtualForm + absent;

							if(addDataMenu(listZone, ELEMENTS, id_Zone, paperForm, virtualForm, absent, totalAdd)){
										printf("%s\n", messageOk);
							}
						}
						puts("-----------------------------------------------------------------------------------------------------");
						break;
					case 7:
						//MOSTRAR CENSISTAS
						printf("%s", titleListCensista);
						printCensistaList(listCensista, ELEMENTS);
						puts("-----------------------------------------------------------------------------------------------------");
						break;
					case 8:
						//MOSTRAR ZONAS
						puts("-----------------------------------------------------------------------------------------------------");
						break;
					case 9:
						//INFORMES
						puts("-----------------------------------------------------------------------------------------------------");
						break;
					case 10:
						puts("\t\t\t\t\t\tGRACIAS");
						puts("-----------------------------------------------------------------------------------------------------");
						break;
				}
			}
		}while(option != 10);
	}
	puts("\nPARCIAL_1\nBeggi A.");
	return EXIT_SUCCESS;
}

//switch(option){
//				case 1:
//					break;
//				case 2:
//					break;
//				case 3:
//					break;
//			}
