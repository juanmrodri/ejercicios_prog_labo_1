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

/**
* \brief imprime una posicion del array
* \param pArray array de estructuras
*/
void report_printResourceByType(Resource resource);

/**
* \brief realiza un loop en el array, llamando por cada vuelta, a la funcion que imprime una posicion, teniendo en cuenta el typeId
* \param arrayResources array de estructuras
* \param lenResource longitud del array
* \param typeId id del tipo seleccionado
*/
void report_printResourcesByType(Resource arrayResources[], int lenResource, int typeId);

/**
* \brief imprime una posicion del array
* \param event una estructura sola
*/
void report_printEventByDate(Event event);

/**
* \brief realiza un loop en el array, llamando por cada vuelta, a la funcion que imprime una posicion
* \param arrayEvents array de estructuras
* \param lenEvents longitud del array
* \param day para validar
* \param month para validar
* \param year para validar
*/
void report_printEventsByDate(Event arrayEvents[], int lenEvents, int day, int month, int year);

/**
* \brief cuenta la cantidad de veces que se repite un recurso, estando repetida la cantidad, o formando parte de otro evento
* \param arrayEvents array de estructuras
* \param lenEvents longitud del array
* \param resourceId id del recurso a tener en cuenta
* \return ret = [0] - error = [-1]
*/
int report_totalAmountEventByResourceCount(Event arrayEvents[], int lenEvents, int resourceId);

/**
* \brief calcula el total del precio por recurso, recibiendo la cantidad de veces que se repite un recurso en report_totalAmountEventByResourceCount y el precio por hora tomado por resource_findPriceById
* \param resourceCount array de estructuras
* \param pricePerHour precio por hora obtenido
* \return auxTotalPrice importe total calculado
*/
float report_totalAmountEventByResourcePrice(int resourceCount, float pricePerHour);

/**
* \brief imprime el precio total por recurso
* \param totalPrice precio total obtenido en report_totalAmountEventByResourcePrice
*/
void report_totalAmountEventByResourcePrint(float totalPrice);

/**
* \brief calcula el importe total por tipo, en una fecha determinada, tiendo en cuenta, si se repite la cantidad, de todos los tipos cuyo importe no es 0
* \param arrayEvents array de estructuras
* \param lenEvents longitud del array
* \param day para validadr
* \param month para validar
* \param year para validar
* \param arrayResources
* \param lenResource
* \return auxTotalPrice importe total calculado
*/
void report_findResourceTypeByIdResource(Event arrayEvents[], int lenEvents, int day, int month, int year, Resource arrayResources[], int lenResource);

/**
* \brief imprime los resultados distintos a 0
* \param auxTotalTypeOne valor recibido del tipo animacion
* \param auxTotalTypeTwo valor recibido del tipo dj
* \param auxTotalTypeThree valor recibido del tipo iluminacion
* \param auxTotalTypeFour valor recibido del tipo locucion
*/
void report_findResourceTypeByIdResourceResultPrints(float auxTotalTypeOne, float auxTotalTypeTwo, float auxTotalTypeThree, float auxTotalTypeFour);

#endif /* REPORT_H_ */
