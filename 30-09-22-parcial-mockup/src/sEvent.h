/*
 * sEvent.h
 *
 *  Created on: 9 oct 2022
 *      Author: juanm
 */

#ifndef SEVENT_H_
#define SEVENT_H_

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "strings.h"
#include "utn_input.h"

typedef struct
{

	int day;
	int month;
	int year;

} Date;

typedef struct
{
	int idEvent;
	int amount;
	char location[31];
	Date eventDate;
	int resourceId; // la foreing
	int isEmpty;

} Event;


#endif /* SEVENT_H_ */
