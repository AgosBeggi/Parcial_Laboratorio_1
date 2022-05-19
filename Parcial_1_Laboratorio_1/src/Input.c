/*
 * Input.c
 *
 *  Created on: 14 may. 2022
 *      Author: A. Beggi
 */

#include "Input.h"

int getInt(char message[], int* number){

	int retorno = -1;//FALSE
	char aux[SIZE];
	int num;

	printf("%s", message);
	fflush(stdin);
	scanf("%s", aux);

	if(isInt(aux) == 0){
		num = atoi(aux);
		*number = num;
		retorno = 0;//TRUE
	}
	return retorno;
}

int getIntMinMax(char message[], int min, int max, int* number){

	int retorno = -1;//FALSE
	char aux[SIZE];
	int num;

	printf("%s", message);
	fflush(stdin);
	scanf("%s", aux);

	if(isInt(aux) == 0){
		num = atoi(aux);
		if(isIntBetweenMinMax(num, min, max) == 0){
			*number = num;
			retorno = 0;//TRUE
		}
	}
	return retorno;
}

int getFloat(char message[], float* number){

	int retorno = -1;//FALSE
	char aux[SIZE];
	float num;

	printf("%s", message);
	fflush(stdin);
	scanf("%s", aux);

	if(isFloat(aux) == 0){
		num = atof(aux);
		*number = num;
		retorno = 0;//TRUE
	}
	return retorno;
}

int getChar(char message[], char* character){

	char aux;
	int retorno = -1;//FALSE

	printf("%s", message);
	fflush(stdin);
	scanf("%c", &aux);

	if(isChar(aux) == 0){
		*character = aux;
		retorno = 0;//TRUE
	}
	return retorno;
}

int getString(char message[], char string[]){

	char aux[SIZE];
	int retorno = -1;//FALSE

	printf("%s", message);
	fflush(stdin);
	scanf("%s", aux);

	if(isString(aux) == 0){
		strcpy(string, aux);
		retorno = 0;//TRUE
	}
	return retorno;
}

int getStrings(char message[], char string[]){

	char aux[SIZE];
	int retorno = -1;//FALSE

	printf("%s", message);
	fflush(stdin);
	scanf("%[^\n]", aux);

	if(areTheyStrings(aux) == 0){
		strcpy(string, aux);
		retorno = 0;//TRUE
	}
	return retorno;
}

int getStringAlnum(char message[], char string[]){//OK

	char aux[SIZE];
	int retorno = -1;//FALSE

	printf("%s", message);
	fflush(stdin);
	scanf("%s", aux);

	if(isStringAlnum(aux) == 0){
		strcpy(string, aux);
		retorno = 0;//TRUE
	}
	return retorno;
}

