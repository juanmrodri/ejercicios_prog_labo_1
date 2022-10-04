/*
 * sType.h
 *
 *  Created on: 1 oct 2022
 *      Author: juanm
 */

#ifndef STYPE_H_
#define STYPE_H_

#include <stdio.h>
#include <stdlib.h>
#include "strings.h"
#include "utn_input.h"

// 1- Locucion 2- Animacion 3- Iluminacion 4- Dj
typedef struct
{
	int idType;
	char description[31];
	int isEmpty;
} Type;


int type_initArray(Type pArray[], int len); //

int type_findEmptyArrayPosition(Type pArray[], int len);

int type_findIdByPos(Type pArray[], int len, int pos);

void type_forceLoad(Type pArray[], int len, char description[]);

// para probar como se ven

int type_printType(Type pArray[]);

int type_printTypes(Type pArray[], int len);


#endif /* STYPE_H_ */
