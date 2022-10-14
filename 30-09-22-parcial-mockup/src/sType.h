/*
 * sType.h
 *
 *  Created on: 1 oct 2022
 *      Author: juanm
 */

#ifndef STYPE_H_
#define STYPE_H_

#include <stdio.h>
#include <stdlib.h>
#include "strings.h"
#include "utn_input.h"

// 1- Locucion 2- Animacion 3- Iluminacion 4- Dj
typedef struct
{
	int idType;
	char description[31];
	int isEmpty;
} Type;

/**
* \brief inicializa un array asignando valor 0 a "campo" isEmpty de la estructura
* \param pArray array de estructuras
* \param len longitud del array
* \return ret = [0] - error = [-1]
*/
int type_initArray(Type pArray[], int len); // ok

/**
* \brief busca la primer posicion libre en un array
* \param pArray array de estructuras
* \param len longitud del array
* \return el indice de la posicion libre
*/
int type_findEmptyArrayPosition(Type pArray[], int len); // ok

/**
* \brief encuentra el id del tipo, usando la posicion, teniendo en cuenta que esta hardcodeado
* \param pArray array de estructuras
* \param len longitud del array
* \param pos es la posicion en array, teniendo en cuenta la eleccion del usuario -1
* \return el id
*/
int type_findIdByPos(Type pArray[], int len, int pos); // ok

/**
* \brief busca posicion por id
* \param pArray array de estructuras
* \param len longitud del array
* \param id seleccionado
* \return el indice
*/
int type_findPosById(Type pArray[], int len, int id); // ok

/**
* \brief carga forzada de valores
* \param pArray array de estructuras
* \param len longitud del array
* \param description forzada
*/
void type_forceLoad(Type pArray[], int len, char description[]); // ok

//void type_getDescriptionById(Type pArray[], int len, int id, char description[]); // ok

/**
* \brief imprime una posicion del array
* \param type una estructura sola
*/
void type_printType(Type type); // ok

/**
* \brief realiza un loop en el array, llamando por cada vuelta, a la funcion que imprime una posicion
* \param pArray array de estructuras
* \param len longitud del array
*/
void type_printTypes(Type pArray[], int len); // ok


#endif /* STYPE_H_ */
