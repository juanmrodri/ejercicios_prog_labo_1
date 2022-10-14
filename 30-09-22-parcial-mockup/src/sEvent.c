/*
 * sEvent.c
 *
 *  Created on: 9 oct 2022
 *      Author: juanm
 */

#include "sEvent.h"

#define EMPTY 1
#define OCCUPIED 0

// static functions

static int newIdGenerator(void);

// static developing

static int newIdGenerator(void)
{
	static int cont=20000;
	return cont++;
}

int event_initArray(Event pArray[], int len)
{
	int ret=-1;

	if(pArray!=NULL && len>0)
	{
		for(int i=0;i<len;i++)
		{
			pArray[i].isEmpty = EMPTY;
		}
		ret=0;
	}

	return ret;
}

int event_findEmptyArrayPosition(Event pArray[], int len)
{
	int index=-1;
	if(pArray!=NULL && len>0)
	{
		for(int i=0;i<len;i++)
		{
			if(pArray[i].isEmpty==EMPTY)
			{
				index = i;
				break;
			}
		}
	}
	return index;
}

int event_isEventAdded(Event pArray[], int len)
{
	int ret=-1;
	if(pArray!=NULL && len>0)
	{
		for(int i=0;i<len;i++)
		{
			if(pArray[i].isEmpty==OCCUPIED)
			{
				ret=0;
				break;
			}
		}
	}

	return ret;
}

int event_findIsResourceAdded(Event pArray[], int len, int ResourceId)
{
	int ret=-1;
	if(pArray!=NULL && len>0)
	{
		for(int i=0;i<len;i++)
		{
			if(pArray[i].resourceId == ResourceId && pArray[i].isEmpty==OCCUPIED)
			{
				ret=0;
				break;
			}
		}
	}

	return ret;
}

int event_findEventAddedByDate(Event pArray[], int len, int day, int month, int year)
{
	int ret=-1;
	if(pArray!=NULL && len>0 && day>0 && month>0 && year>0)
	{
		for(int i=0;i<len;i++)
		{
			if(pArray[i].eventDate.day == day && pArray[i].eventDate.month == month && pArray[i].eventDate.year == year)
			{
				// la fecha existe
				ret=0;
				break;
			}
		}
	}
	return ret;
}

int event_load(Event pArray[], int len, int ResourceId)
{
	int ret=-1;
	int auxAmount;
	char auxLocation[31];
	int auxDay;
	int auxMonth;
	int auxYear;
	if(pArray!=NULL && len>0)
	{
		if(event_findEmptyArrayPosition(pArray, len)>-1)
		{
			if(utn_getInt(&auxAmount,"\nPor favor ingrese la cantidad (hora(s) - maximo 4 horas): ", "Error al ingresar la cantidad\n", 1,4, 2)==0) // maximo 4 horas, porque el mismo evento de mas horas es innecesario
			{
				if(utn_getText(auxLocation, 31, "\nPor favor ingrese la localidad del evento: ", "Error al ingresar la localidad\n", 2)==0)
				{
					if(utn_getInt(&auxYear,"\nPor favor ingrese la fecha del evento(anio) - hasta 2024: ", "Error al ingresar el anio\n", 2022,2024, 2)==0)
					{
						if(utn_getInt(&auxMonth,"\nPor favor ingrese la fecha del evento(mes): ", "Error al ingresar el mes\n", 1,12, 2)==0)
						{
							while(auxYear==2022 && auxMonth<10)
							{
								if(utn_getInt(&auxMonth,"\nPor favor ingrese un mes valido: ", "Error al ingresar el mes\n", 1,12, 2)==0)
								{
									if(auxMonth<10)
									{
										printf("\nIntente nuevamente!\n");
									}
									else
									{
										printf("\nPerfecto!\n");
									}
								}
							}
							if(utn_getInt(&auxDay,"\nPor favor ingrese la fecha del evento(dia): ", "Error al ingresar el dia\n", 1,31, 2)==0)
							{
								while(auxYear==2022 && auxMonth==10 && auxDay<13)
								{
									if(utn_getInt(&auxDay,"\nPor favor ingrese un dia valido: ", "Error al ingresar el dia\n", 13,31, 2)==0)
									{
										if(auxDay<13)
										{
											printf("\nIntente nuevamente!\n");
										}
										else
										{
											printf("\nPerfecto!\n");
										}
									}
								}
								ret=0;
								printf("\nEvento cargado correctamente!\n\n");
								event_add(pArray, len, auxAmount, auxLocation, auxDay, auxMonth, auxYear, ResourceId);
							}
							else
							{
								ret=-1;
								printf("Se produjo un error al ingresar la fecha(anio)!\n");
							}
						}
						else
						{
							ret=-1;
							printf("Se produjo un error al ingresar la fecha(mes)!\n");
						}
					}
					else
					{
						ret=-1;
						printf("Se produjo un error al ingresar la fecha(dia)!\n");
					}
				}
				else
				{
					ret=-1;
					printf("Se produjo un error al ingresar la localidad!\n");
				}
			}
			else
			{
				ret=-1;
				printf("Se produjo un error al ingresar la cantidad!\n");
			}
		}

	}

	return ret;
}

int event_add(Event pArray[], int len, int amount, char location[], int day, int month, int year ,int ResourceId)
{
	int ret=-1;
	int indexFree;
	if(pArray!=NULL && len>0 &&  amount>0 && location!=NULL && day>0 && month>0 && year>0 )
	{
		indexFree = event_findEmptyArrayPosition(pArray, len);
		pArray[indexFree].idEvent = newIdGenerator();
		pArray[indexFree].amount = amount;
		strncpy(pArray[indexFree].location,location,sizeof(pArray[indexFree].location));
		pArray[indexFree].eventDate.day = day;
		pArray[indexFree].eventDate.month = month;
		pArray[indexFree].eventDate.year = year;
		pArray[indexFree].resourceId = ResourceId;
		pArray[indexFree].isEmpty=OCCUPIED;
	}

	return ret;
}

void event_printEvent(Event event)
{

		printf("\nid: %d\n-------\n"
					"Cantidad(horas):%d\n"
					"Localidad: %s\n"
					"fecha: %d/%d/%d\n"
					"Recurso(id): %d\n\n", event.idEvent,event.amount,event.location, event.eventDate.day,event.eventDate.month,event.eventDate.year,event.resourceId);

}

void event_printEvents(Event pArray[], int len)
{
	if(pArray!=NULL && len>0)
		{
			for(int i=0;i<len;i++)
			{
				if(pArray[i].isEmpty==OCCUPIED)
				{
					event_printEvent(pArray[i]);
				}
			}
		}
}
