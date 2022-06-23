/*
 * Validation.c
 *
 *  Created on: 23 jun. 2022
 *      Author: A. Beggi
 */

#include "Validation.h"

int isInt(char number[]){

	int retorno = 0;

	for (int i = 0; i < strlen(number); i++){
		if(!isdigit(number[i])){
			retorno = -1;
			break;
		}
	}
	return retorno;
}

int isIntBetweenMinMax(int number, int min, int max){

	int retorno = 0;

	if(number <= min || number >= max){
		retorno = -1;
	}
	return retorno;
}

int isFloat(char number[]){

	int retorno = 0;

	for (int i = 0; i < strlen(number); i++){
		if(!isdigit(number[i]) && number[i] != '.'){
			retorno = -1;
			break;
		}
	}
	return retorno;
}

int isChar(char character){

	int retorno = 0;

	if (!(isalpha(character))) {
		retorno = -1;
	  }
	return retorno;
}

int isString(char chains[]){

	int retorno = -1;

	for (int i = 0; i < strlen(chains); i++){
		if(isalpha(chains[i]) || chains[i] == 'ñ'){
			if(i == 0){
				chains[i] = toupper(chains[i]);
				retorno = 0;
			}
		}
	}
	return retorno;
}

int areTheyStrings(char chains[]){

	int retorno = -1;

	for (int i = 0; i < strlen(chains); i++){
		if ((chains[i] < 'a' || chains[i] > 'z') && (chains[i] < 'A' || chains[i] > 'Z') && (chains[i] != ' ')){
			chains[i] = toupper(chains[i]);
			retorno = 0;
		}
	}
	return retorno;
}

int isStringAlnum(char chains[]){

	int retorno = 0;

	for (int i = 0; i < strlen(chains); i++){
		if(!isalnum(chains[i]) && chains[i] != 'ñ'){
			retorno = -1;
			break;
		}
	}
	return retorno;
}

int isNumberStrings(char chains[]){

	int retorno = -1;

	for (int i = 0; i < strlen(chains); i++){
		if (chains[i] < '0' || chains[i] > '9'){
			chains[i] = toupper(chains[i]);
			retorno = 0;
		}
	}
	return retorno;
}

