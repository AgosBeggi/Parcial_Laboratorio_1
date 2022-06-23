/*
 * Input.c
 *
 *  Created on: 23 jun. 2022
 *      Author: A. Beggi
 */

#include "Input.h"

int getInt(char message[], int* number){

	int retorno = -1;
	char aux[SIZE];
	int num;

	printf("%s", message);
	fflush(stdin);
	scanf("%s", aux);

	if(isInt(aux) == 0){
		num = atoi(aux);
		*number = num;
		retorno = 0;
	}
	return retorno;
}

int getIntMinMax(char message[], int min, int max, int* number){

	int retorno = -1;
	char aux[SIZE];
	int num;

	printf("%s", message);
	fflush(stdin);
	scanf("%s", aux);

	if(isInt(aux) == 0){
		num = atoi(aux);
		if(isIntBetweenMinMax(num, min, max) == 0){
			*number = num;
			retorno = 0;
		}
	}
	return retorno;
}

int getFloat(char message[], float* number){

	int retorno = -1;
	char aux[SIZE];
	float num;

	printf("%s", message);
	fflush(stdin);
	scanf("%s", aux);

	if(isFloat(aux) == 0){
		num = atof(aux);
		*number = num;
		retorno = 0;
	}
	return retorno;
}

int getChar(char message[], char* character){

	char aux;
	int retorno = -1;

	printf("%s", message);
	fflush(stdin);
	scanf("%c", &aux);

	if(isChar(aux) == 0){
		*character = aux;
		retorno = 0;
	}
	return retorno;
}

int getString(char message[], char string[]){

	char aux[SIZE];
	int retorno = -1;

	printf("%s", message);
	fflush(stdin);
	scanf("%s", aux);

	if(isString(aux) == 0){
		strcpy(string, aux);
		retorno = 0;
	}
	return retorno;
}

int getStrings(char message[], char string[]){

	char aux[SIZE];
	int retorno = -1;

	printf("%s", message);
	fflush(stdin);
	scanf("%[^\n]", aux);

	if(areTheyStrings(aux) == 0){
		strcpy(string, aux);
		retorno = 0;
	}
	return retorno;
}

int getStringAlnum(char message[], char string[]){

	char aux[SIZE];
	int retorno = -1;

	printf("%s", message);

	fflush(stdin);
	scanf("%s", aux);

	if(isStringAlnum(aux) == 0){
		strcpy(string, aux);
		retorno = 0;
	}
	return retorno;
}

int getNumberStrings(char message[], char string[]){

	char aux[SIZE];
	int retorno = -1;

	printf("%s", message);
	fflush(stdin);
	gets(aux);

	if(isNumberStrings(aux) == 0){
		strcpy(string, aux);
		retorno = 0;
	}
	return retorno;
}

