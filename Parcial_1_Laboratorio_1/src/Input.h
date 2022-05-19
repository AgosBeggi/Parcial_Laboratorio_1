/*
 * Input.h
 *
 *  Created on: 14 may. 2022
 *      Author: A. Beggi
 */

#ifndef INPUT_H_
#define INPUT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Validation.h"

#define SIZE 51

/// @fn int getInt(char[], int*)
/// @brief Prints a message, saves a string data type,
/// if the integer validation is ok, converts to int
/// and passes the value of the number to the memory
/// address of the pointer.
/// @param message
/// @param number
/// @return Returns 0 for true and -1 for false.
int getInt(char message[], int* number);

int getIntMinMax(char message[], int min, int max, int* number);

/// @fn int getFloat(char[], float*)
/// @brief Prints a message, saves a string data type,
/// if the float validation is ok, converts to float
/// and passes the value of the number to the memory
/// address of the pointer.
/// @param message
/// @param number
/// @return Returns 0 for true and -1 for false.
int getFloat(char message[], float* number);

/// @fn int getChar(char[], char*)
/// @brief Print a message, save a char data type,
/// if character validation is ok, copy the value to
/// the pointer's memory address.
/// @param message
/// @param character
/// @return Returns 0 for true and -1 for false.
int getChar(char message[], char* character);

/// @fn int getString(char[], char[])
/// @brief Print a message, save a string data type,
/// if string validation is ok, copy the value to
/// the pointer's memory address.
/// @param message
/// @param string
/// @return Returns 0 for true and -1 for false.
int getString(char message[], char string[]);

int getStrings(char message[], char string[]);

/// \fn int getStringAlnum(char[], char[])
/// \brief Print a message, save an alphanumeric string data type,
/// if the string validation is ok, copy the value to
/// the memory address of the pointer.
/// \param message
/// \param string
/// \return Returns 0 for true and -1 for false.
int getStringAlnum(char message[], char string[]);

#endif /* INPUT_H_ */
