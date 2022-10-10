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

int event_initArray(Event pArray[], int len); // ok

int event_findEmptyArrayPosition(Event pArray[], int len); // ok

int event_isEventAdded(Event pArray[], int len); // ok;

int event_load(Event pArray[], int len, int ResourceId); // ok

int event_add(Event pArray[], int len, int amount, char location[], int day, int month, int year ,int ResourceId); // ok

int event_printEvent(Event pArray[]); // ok

int event_printEvents(Event pArray[], int len); // ok


#endif /* SEVENT_H_ */
