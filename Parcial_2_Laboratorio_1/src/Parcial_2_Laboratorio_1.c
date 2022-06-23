/*
 ============================================================================
 Name        : Parcial_2_Laboratorio_1.c
 Author      : A. Beggi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "Controller.h"
#include "Passenger.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main(){
	setbuf(stdout, NULL);

    int option = 0;
   	int flag_Text = 0;
   	int flag_Bin = 0;
   	int flag_Add = 0;
   	int flag_Save = 0;

    char messageOk[250];
	strcpy(messageOk, "Operación exitosa");
	char messageError[250];
	strcpy(messageError, "Error, intene nuevamente\n");

    LinkedList* listaPasajeros = ll_newLinkedList();

    puts("-----------------------------------------------------------------------------------------------------");
  	puts("\t\t\t\t\t\tBIENVENIDO");
  	puts("-----------------------------------------------------------------------------------------------------");

    do{
    	puts("INGRESE UNA OPCIÓN\n");

		puts("1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)");
		puts("2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario)");
		puts("3. Alta de pasajero");
		puts("4. Modificar datos de pasajero");
		puts("5. Baja de pasajero");
		puts("6. Listar pasajeros");
		puts("7. Ordenar pasajeros");
		puts("8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).");
		puts("9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).");
		if(flag_Save == 1){
			puts("10. Salir");
		}
		puts("-----------------------------------------------------------------------------------------------------");
		getInt("", &option);

        switch(option)
        {
            case 1:
            	//CARGA DE DATOS - MODO TEXTO
            	if(flag_Text == 0){
            		//if(controller_loadFromText("data.csv", listaPasajeros) == 0){
            		if(controller_loadFromText("prueba.csv", listaPasajeros) == 0){
            			puts("-----------------------------------------------------------------------------------------------------");
            			printf("%s\n", messageOk);
            			puts("-----------------------------------------------------------------------------------------------------");
            		}
            		flag_Text = 1;
            	}else{
					printf("%s", messageError);
					puts("-----------------------------------------------------------------------------------------------------");
				}
            	break;
            case 2:
            	//CARGA DE DATOS - MODO BINARIO
            	if(flag_Bin == 0){
            		//if(controller_loadFromBinary("data.bin", listaPasajeros) == 0){
            		if(controller_loadFromBinary("prueba.bin", listaPasajeros) == 0){
						puts("-----------------------------------------------------------------------------------------------------");
						printf("%s\n", messageOk);
						puts("-----------------------------------------------------------------------------------------------------");
            		}
            		flag_Bin = 1;
            	}else{
					printf("%s", messageError);
					puts("-----------------------------------------------------------------------------------------------------");
				}
            	break;
            case 3:
            	//ALTA
            	if(flag_Add == 0 || flag_Add == 1){
            		if(controller_addPassenger(listaPasajeros) == 0){
						puts("-----------------------------------------------------------------------------------------------------");
						printf("%s\n", messageOk);
						puts("-----------------------------------------------------------------------------------------------------");
            		}
            		flag_Add = 1;
            	}else{
					printf("%s", messageError);
					puts("-----------------------------------------------------------------------------------------------------");
				}
            	break;
            case 4:
			   //MODIFICAR
            	if(flag_Add == 1 || flag_Text == 1 || flag_Bin == 1){
            		if(controller_editPassenger(listaPasajeros) == 0){
						puts("-----------------------------------------------------------------------------------------------------");
						printf("%s\n", messageOk);
						puts("-----------------------------------------------------------------------------------------------------");
            		}
            	}else{
					printf("%s", messageError);
					puts("-----------------------------------------------------------------------------------------------------");
				}
            	break;
            case 5:
            	//BAJA
            	if(flag_Add == 1 || flag_Text == 1 || flag_Bin == 1){
					if(controller_removePassenger(listaPasajeros) == 0){
						puts("-----------------------------------------------------------------------------------------------------");
						printf("%s\n", messageOk);
						puts("-----------------------------------------------------------------------------------------------------");
					}
            	}else{
					printf("%s", messageError);
					puts("-----------------------------------------------------------------------------------------------------");
				}
            	break;
            case 6:
            	//LISTAR
            	if(flag_Add == 1 || flag_Text == 1 || flag_Bin == 1){
            		controller_ListPassenger(listaPasajeros);
            	}else{
            		printf("%s", messageError);
            		puts("-----------------------------------------------------------------------------------------------------");
				}
            	break;
            case 7:
            	//ORDENAR
            	if(flag_Add == 1 || flag_Text == 1 || flag_Bin == 1){
					if(controller_sortPassenger(listaPasajeros) == 0){
						puts("-----------------------------------------------------------------------------------------------------");
						printf("%s\n", messageOk);
						puts("-----------------------------------------------------------------------------------------------------");
					}
            	}else{
					printf("%s", messageError);
					puts("-----------------------------------------------------------------------------------------------------");
				}
            	break;
            case 8:
            	//GUARDAR DATOS - MODO TEXTO
            	if(flag_Add == 1 || flag_Text == 1 || flag_Bin == 1){
            		//if(controller_saveAsText("data.csv",listaPasajeros) == 0){
					if(controller_saveAsText("prueba.csv",listaPasajeros) == 0){
						puts("-----------------------------------------------------------------------------------------------------");
						printf("%s\n", messageOk);
						puts("-----------------------------------------------------------------------------------------------------");
					}
					flag_Save = 1;
            	}else{
					printf("%s", messageError);
					puts("-----------------------------------------------------------------------------------------------------");
				}
            	break;
            case 9:
            	//GUARDAR DATOS - MODO BINARIO
            	if(flag_Add == 1 || flag_Text == 1 || flag_Bin == 1){
            		//if(controller_saveAsBinary("data.bin",listaPasajeros) == 0){
					if(controller_saveAsBinary("prueba.bin",listaPasajeros) == 0){
						puts("-----------------------------------------------------------------------------------------------------");
						printf("%s\n", messageOk);
						puts("-----------------------------------------------------------------------------------------------------");
					}
					flag_Save = 1;
            	}else{
					printf("%s", messageError);
					puts("-----------------------------------------------------------------------------------------------------");
				}
				break;
            case 10:
			   //SALIR
            	puts("Gracias.\n");
			   break;
            default:
            	printf("%s", messageError);
            	puts("-----------------------------------------------------------------------------------------------------");
            	break;
        }
    }while(option != 10);

    return 0;
}
