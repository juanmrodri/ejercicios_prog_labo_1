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

/**
* \brief inicializa un array asignando valor 0 a "campo" isEmpty de la estructura
* \param pArray array de estructuras
* \param len longitud del array
* \return ret = [0] - error = [1]
*/
int event_initArray(Event pArray[], int len); // ok

/**
* \brief busca la primer posicion libre en un array
* \param pArray array de estructuras
* \param len longitud del array
* \return el indice de la posicion libre
*/
int event_findEmptyArrayPosition(Event pArray[], int len); // ok

/**
* \brief busca la si existe algun evento dado de alta
* \param pArray array de estructuras
* \param len longitud del array
* \return ret = [0] - error = [-1]
*/
int event_isEventAdded(Event pArray[], int len); // ok;

/**
* \brief busca la si existe un recurso especifico en los eventos, por id
* \param pArray array de estructuras
* \param len longitud del array
* \param ResourceId id del recurso a buscar
* \return ret = [0] - error =[-1]
*/
int event_findIsResourceAdded(Event pArray[], int len, int ResourceId);

/**
* \brief busca la si existe un evento en una fecha especifica
* \param pArray array de estructuras
* \param len longitud del array
* \param day dia ingresado
* \param month mes ingresado
* \param year anio ingresado
* \param ResourceId id del recurso a buscar
* \return ret = [0] - error = [-1]
*/
int event_findEventAddedByDate(Event pArray[], int len, int day, int month, int year); // ok

/**
* \brief toma los datos para llamar a la funcion que los agrega al array
* \param pArray array de estructuras
* \param len longitud del array
* \param ResourceId id del recurso, solicitado previamente
* \return ret = [0] - error = [-1]
*/
int event_load(Event pArray[], int len, int ResourceId); // ok

/**
* \brief recibe los datos tomados por la funcion load (validados)
* \param pArray array de estructuras
* \param len longitud del array
* \param amount la descripcion validada
* \param location el precio validado
* \param day dia ingresado
* \param month mes ingresado
* \param year anio ingresado
* \param ResourceId id del recurso, solicitado previamente
* \return ret = [0] - error = [-1]
*/
int event_add(Event pArray[], int len, int amount, char location[], int day, int month, int year ,int ResourceId); // ok

/**
* \brief imprime una posicion del array
* \param event una estructura sola
*/
void event_printEvent(Event event); // ok

/**
* \brief realiza un loop en el array, llamando por cada vuelta, a la funcion que imprime una posicion
* \param pArray array de estructuras
* \param len longitud del array
*/
void event_printEvents(Event pArray[], int len); // ok


#endif /* SEVENT_H_ */
