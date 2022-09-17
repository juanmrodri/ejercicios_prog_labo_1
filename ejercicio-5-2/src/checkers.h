/*
 * checkers.h
 *
 *  Created on: 12 sept 2022
 *      Author: juanm
 */

#ifndef CHECKERS_H_
#define CHECKERS_H_

#include <stdio.h>
#include <stdlib.h>

int checkPositiveNumber(int number);

int checkNegativeNumber(int number);

int checkEvenNumber(int number);

int checkOddNumber(int number);

void checkMaxOddNumber(int* flag, int* min, int* max, int number);

void initArray(int pArray[], int len, int number);

int findEmptyPosArray(int pArray[], int len, int* ind);

#endif /* CHECKERS_H_ */
