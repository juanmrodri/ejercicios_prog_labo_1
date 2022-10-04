/*
 * sResource.h
 *
 *  Created on: 1 oct 2022
 *      Author: juanm
 */

#ifndef SRESOURCE_H_
#define SRESOURCE_H_

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "strings.h"
#include "utn_input.h"
#include "sType.h"

typedef struct
{
	int idResource;
	char description[21];
	float pricePerHour;
	int typeId; // la foreing
	int isEmpty;

} Resource;

int resource_initArray(Resource pArray[], int len); // ok

int resource_findEmptyArrayPosition(Resource pArray[], int len); // ok

int resource_load(Resource pArrayRes[], int lenRes, Type pArrayType[], int lenType);

int resource_add(Resource pArray[], int len, char description[], float price, int idType);

int resource_findById(Resource pArray[], int len, int id); // esto me va a dar la posicion en el array del elemento a modificar

int resource_modify(Resource pArray[], int len, int index, int option); // el option es lo que se quiere modificar

int resource_printResource(Resource pArray[]); // ok

int resource_printResources(Resource pArray[], int len); // ok


#endif /* SRESOURCE_H_ */
