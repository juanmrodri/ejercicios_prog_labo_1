/*
 * report.c
 *
 *  Created on: 10 oct 2022
 *      Author: juanm
 */

#include "report.h"

#define EMPTY 1
#define OCCUPIED 0


void report_printResourcesByType(Resource arrayResources[], int lenResource, int typeId)
{
	if(arrayResources!=NULL && lenResource>0)
	{
		for(int i=0;i<lenResource;i++)
		{
			if(arrayResources[i].typeId==typeId)
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

int report_totalAmountEventByResourceCount(Event arrayEvents[], int lenEvents, int resourceId)
{
	int auxResourceCount=0;
	if(arrayEvents!=NULL && lenEvents>0 && resourceId>0)
	{
		for(int i=0;i<lenEvents;i++)
		{
			if(arrayEvents[i].resourceId == resourceId)
			{
				auxResourceCount++;
			}
		}
	}
	return auxResourceCount;
}

float report_totalAmountEventByResourcePrice(Event arrayEvents[], int lenEvents, int resourceCount, float pricePerHour)
{
	float auxTotalPrice;

	if(arrayEvents!=NULL && lenEvents>0 && resourceCount>0 && pricePerHour>100)
		{
		auxTotalPrice = pricePerHour*resourceCount;
		}
	return auxTotalPrice;
}
