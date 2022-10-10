/*
 * report.c
 *
 *  Created on: 10 oct 2022
 *      Author: juanm
 */

#include "report.h"

#define EMPTY 1
#define OCCUPIED 0


void report_printResourcesByType(Resource arrayResources[], int lenResource, int TypeId)
{
	if(arrayResources!=NULL && lenResource>0)
	{
		for(int i=0;i<lenResource;i++)
		{
			if(arrayResources[i].typeId==TypeId)
			{
				report_printResourceByType(&arrayResources[i]);
			}
		}
	}
}

void report_printResourceByType(Resource arrayResources[])
{
	if(arrayResources!=NULL)
	{
		printf("\nid: %d\n-------\n"
					"Descripcion:%s\n"
					"Precio por hora: $%.2f\n\n", arrayResources->idResource,arrayResources->description,arrayResources->pricePerHour);
	}
}

void report_printEventsByDate(Event arrayEvents[], int lenEvents, int day, int month, int year)
{
	if(arrayEvents!=NULL && lenEvents>0)
		{
			for(int i=0;i<lenEvents;i++)
			{
				if(arrayEvents[i].eventDate.day==day && arrayEvents[i].eventDate.month==month && arrayEvents[i].eventDate.year)
				{
					report_printEventByDate(&arrayEvents[i]);
				}
			}
		}
}

void report_printEventByDate(Event arrayEvents[])
{
	if(arrayEvents!=NULL)
		{
			printf("\nid: %d\n-------\n"
						"Cantidad: %d\n"
						"Localidad: %s\n\n", arrayEvents->idEvent,arrayEvents->amount,arrayEvents->location);
		}
}

void report_totalAmountEventByResource(Event arrayEvents[], int lenEvents, int ResourceId)
{
	if(arrayEvents!=NULL && lenEvents>0 && ResourceId>0)
	{

	}
}
