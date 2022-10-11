/*
 * report.h
 *
 *  Created on: 10 oct 2022
 *      Author: juanm
 */

#ifndef REPORT_H_
#define REPORT_H_

#include "sResource.h"
#include "sEvent.h"

void report_printResourceByType(Resource arrayResources[]);

void report_printResourcesByType(Resource arrayResources[], int lenResource, int typeId);

void report_printEventByDate(Event arrayEvents[]);

void report_printEventsByDate(Event arrayEvents[], int lenEvents, int day, int month, int year);

int report_totalAmountEventByResourceCount(Event arrayEvents[], int lenEvents, int resourceId);

float report_totalAmountEventByResourcePrice(int resourceCount, float pricePerHour);

void report_totalAmountEventByResourcePrint(float totalPrice);

#endif /* REPORT_H_ */
