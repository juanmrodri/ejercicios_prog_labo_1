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
	int auxAmountCount=0;
	if(arrayEvents!=NULL && lenEvents>0 && resourceId>0)
	{
		for(int i=0;i<lenEvents;i++)
		{
			if(arrayEvents[i].resourceId == resourceId)
			{
				auxResourceCount++;
				auxAmountCount = arrayEvents[i].amount;
			}
		}
	}
	auxResourceCount=auxResourceCount*auxAmountCount;
	return auxResourceCount;
}

float report_totalAmountEventByResourcePrice(int resourceCount, float pricePerHour)
{
	float auxTotalPrice;

	if(resourceCount>0 && pricePerHour>100)
		{
		auxTotalPrice = pricePerHour*resourceCount;
		}
	return auxTotalPrice;
}

void report_totalAmountEventByResourcePrint(float totalPrice)
{
	if( totalPrice >0)
	{
		printf("\nImporte total: $%.2f\n\n" ,totalPrice);
	}
}


int report_findResourceTypeByIdResource(Event arrayEvents[], int lenEvents, int day, int month, int year, Resource arrayResources[], int lenResource)
{
	int ret=-1;
	int auxAmount;
	float auxPricePerHour;
	float auxTotalType;
	float auxTotalTypeOne=0;
	float auxTotalTypeTwo=0;
	float auxTotalTypeThree=0;
	float auxTotalTypeFour=0;

	if(arrayEvents!=NULL && lenEvents>0)
	{
		for(int i=0;i<lenEvents;i++)
		{
			if(arrayEvents[i].eventDate.day==day && arrayEvents[i].eventDate.month==month && arrayEvents[i].eventDate.year)
			{
				for(int j=0;j<lenResource;j++)
				{
						if(arrayResources[j].idResource == arrayEvents[i].resourceId)
						{
							/*
							printf("\ntipo disponible: %d\n\n", arrayResources[j].typeId);

							printf("\nEl evento con este tipo:\n"
										"(evento)cantidad: %d\n"
										"(recurso)precio por hora: %.2f\n\n", arrayEvents[i].amount,arrayResources[j].pricePerHour);
							*/
							auxAmount = arrayEvents[i].amount;
							auxPricePerHour = arrayResources[j].pricePerHour;
							auxTotalType = auxPricePerHour*auxAmount;

							//printf("\nTotal por tipo%d: %.2f\n\n", arrayResources[j].typeId,auxTotalType);
							if(arrayResources[j].typeId==1000)
							{
								auxTotalTypeOne = auxTotalTypeOne + auxTotalType;
							}
							else
									{
										if(arrayResources[j].typeId==1001)
											{
											auxTotalTypeTwo = auxTotalTypeTwo + auxTotalType;
											}
										else
												{
													if(arrayResources[j].typeId==1002)
													{
														auxTotalTypeThree = auxTotalTypeThree + auxTotalType;
													}
													else
															{
																if(arrayResources[j].typeId==1003)
																{
																	auxTotalTypeFour = auxTotalTypeFour + auxTotalType;
																}
															}
												}
									}
						}
				}
			}
		}
		if(auxTotalTypeOne>0)
		{
			printf("\nTotal Animacion: $%.2f\n\n", auxTotalTypeOne);
		}
		if(auxTotalTypeTwo>0)
		{
			printf("\nTotal Dj: $%.2f\n\n", auxTotalTypeTwo);

		}
		if(auxTotalTypeThree>0)
		{
			printf("\nTotal Iluminacion: $%.2f\n\n", auxTotalTypeThree);

		}
		if(auxTotalTypeFour>0)
		{
			printf("\nTotal Locucion: $%.2f\n\n", auxTotalTypeFour);
		}
	}

	return ret;

}




