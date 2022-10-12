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

typedef struct
{
	int idResource;
	char description[21];
	float pricePerHour;
	int typeId; // la foreing
	int isEmpty;

} Resource;

/**
* \brief inicializa un array asignando valor 0 a "campo" isEmpty de la estructura
* \param pArray array de estructuras
* \param len longitud del array
* \return ret = [0] - error = [1]
*/
int resource_initArray(Resource pArray[], int len); // ok

/**
* \brief realiza la carga de un array de manera forzada, con valores hardcodeados
* \param pArray array de estructuras
* \param len longitud del array
* \param description descripcion hardcodeada
* \param pricePerHour precio hardcodeado
* \param typeId tipo hardcodeado
*/
void resource_forceLoad(Resource pArray[], int len, char description[], float pricePerHour, int typeId); // ok

/**
* \brief busca la primer posicion libre en un array
* \param pArray array de estructuras
* \param len longitud del array
* \return el indice de la posicion libre
*/
int resource_findEmptyArrayPosition(Resource pArray[], int len); // ok

/**
* \brief busca la posicion del id en parametro
* \param pArray array de estructuras
* \param len longitud del array
* \param id por valor
* \return el indice de la posicion libre
*/
int resource_findById(Resource pArray[], int len, int id); // ok

/**
* \brief busca el id del tipo, por el id en parametro
* \param pArray array de estructuras
* \param len longitud del array
* \param id por valor
* \return el id tipo
*/
int resource_findIdTypeById(Resource pArray[], int len, int id); // ok

/**
* \brief busca si existe el recurso, por el id tipo
* \param pArray array de estructuras
* \param len longitud del array
* \param typeId por valor
* \return ret = [0] - error = [1]
*/
int resource_findResourcetAddedByType(Resource pArray[], int len, int typeId); // ok

/**
* \brief busc el precio por hora, por el id en parametro
* \param pArray array de estructuras
* \param len longitud del array
* \param id por valor
* \return ret el precio por hora
*/
float resource_findPriceById(Resource pArray[], int len, int id);

/**
* \brief busca la si existe algun recurso dado de alta
* \param pArray array de estructuras
* \param len longitud del array
* \return ret = [0] - error = [1]
*/
int resource_isResourceAdded(Resource pArray[], int len); // ok

/**
* \brief toma los datos para llamar a la funcion que los agrega al array
* \param pArray array de estructuras
* \param len longitud del array
* \param typeId id del tipo, solicitado previamente
* \return ret = [0] - error = [1]
*/
int resource_load(Resource pArray[], int len, int typeId); // ok

/**
* \brief recibe los datos tomados por la funcion load (validados)
* \param pArray array de estructuras
* \param len longitud del array
* \param description la descripcion validada
* \param price el precio validado
* \param typeId id recibido por parametro en load, llega aca y se carga
* \return ret = [0] - error = [1]
*/
int resource_add(Resource pArray[], int len, char description[], float price, int typeId); // ok

/**
* \brief modifica descripcion o precio, recibe opcion que indica que se modificara
* \param pArray array de estructuras
* \param len longitud del array
* \param pos posicion del array a modificar
* \param option opcion que indica el campo a modificar
* \return ret = [0] - error = [1]
*/
int resource_modify(Resource pArray[], int len, int pos, int option); // ok

/**
* \brief baja logica de la posicion
* \param pArray array de estructuras
* \param len longitud del array
* \param id a dar de baja
* \return ret = [0] - error = [1]
*/
int resource_remove(Resource pArray[], int len, int id); // ok

/**
* \brief imprime una posicion del array
* \param pArray array de estructuras
* \return ret = [0] - error = [1]
*/
int resource_printResource(Resource pArray[]); // ok

/**
* \brief realiza un loop en el array, llamando por cada vuelta, a la funcion que imprime una posicion
* \param pArray array de estructuras
* \param len longitud del array
* \return ret = [0] - error = [1]
*/
int resource_printResources(Resource pArray[], int len); // ok

/**
* \brief ordena el array de forma ascendente, teniendo en cuenta el tipo, luego llama a la funcion ue ordena por descripcion
* \param pArray array de estructuras
* \param len longitud del array
*/
void resource_arrayAscendingOrderById(Resource pArray[], int len); // ok

/**
* \brief ordena el array de forma ascendente, teniendo en cuenta la descripcion
* \param pArray array de estructuras
* \param len longitud del array
*/
void resource_arrayAscendingOrderByDescription(Resource pArray[], int len); //ok


#endif /* SRESOURCE_H_ */
