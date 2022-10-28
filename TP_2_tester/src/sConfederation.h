/*
 * sConfederation.h
 *
 *  Created on: 20 oct 2022
 *      Author: juanm
 */

#ifndef SCONFEDERATION_H_
#define SCONFEDERATION_H_

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "utn_input.h"

// la confederacion mas antigual es la FA de Londres, 1863
typedef struct
{
	int id;
	char name[50];
	char region[50];
	int yearOfCreation;
	short int isEmpty;
}sConfederation;

/**
* \brief inicializa un array asignando valor 0 a "campo" isEmpty de la estructura
* \param pArray array de estructuras
* \param len longitud del array
* \return ret = [0] - error = [-1]
*/
int sConfederation_initArray(sConfederation pArray[],int len);

/**
* \brief carga forzada de valores
* \param pArray array de estructuras
* \param len longitud del array
* \param name nombre forzado
* \param region region forzada
* \param yearOfCreation anio forzado
*/
void sConfederation_forceLoad(sConfederation pArray[],int len, char name[], char region[], int yearOfCreation);

/**
* \brief busca la primer posicion libre en un array
* \param pArray array de estructuras
* \param len longitud del array
* \return el indice de la posicion libre
*/
int sConfederation_findEmptyArrayPosition(sConfederation pArray[],int len);

/**
* \brief busca confederacion por id
* \param pArray array de estructuras
* \param len longitud del array
* \param id para obtener posicicion
* \return el indice de la posicion
*/
int sConfederation_findConfederationById(sConfederation pArray[],int len, int id);

/**
* \brief busca id por posicion
* \param pArray array de estructuras
* \param len longitud del array
* \param auxPos posicion para saber el id
* \return el id encontrado
*/
int sConfederation_findIdByPos(sConfederation pArray[],int len, int auxPos);

/**
* \brief carga forzada de valores
* \param pArray array de estructuras
* \param len longitud del array
* \return ret = [0] - error = [-1]
*/
int sConfederation_isConfederationAdded(sConfederation pArray[],int len);

/**
* \brief toma los datos para llamar a la funcion que los agrega al array
* \param pArray array de estructuras
* \param len longitud del array
* \return ret = [0] - error = [-1]
*/
int sConfederation_load(sConfederation pArray[],int len);

/**
* \brief recibe los datos tomados por la funcion load (validados)
* \param pArray array de estructuras
* \param len longitud del array
* \param name nombre validado
* \param region region validada
* \param yearOfCreation anio validado
* \return ret = [0] - error = [-1]
*/
int sConfederation_add(sConfederation pArray[],int len, char name[], char region[], int yearOfCreation);

/**
* \brief se encarga de realizar una baja logica cambiando el valor de isEmpty a 0
* \param pArray array de estructuras
* \param len longitud del array
* \param id selecionado a validar
* \return ret = [0] - error = [-1]
*/
int sConfederation_removeConfederation(sConfederation pArray[],int len, int id);

/**
* \brief se encarga de modificar algun campo de la region (elegido por el usuario)
* \param pArray array de estructuras
* \param len longitud del array
* \param pos selecionada a validar
* \return ret = [0] - error = [-1]
*/
int sConfederation_modifyConfederation(sConfederation pArray[],int len, int pos, int option);

/**
* \brief imprime una posicion del array
* \param confederation una estructura sola
*/
void sConfederation_printConfederation(sConfederation confederation);

/**
* \brief realiza un loop en el array, llamando por cada vuelta, a la funcion que imprime una posicion
* \param pArray array de estructuras
* \param len longitud del array
*/
void sConfederation_printConfederations(sConfederation pArray[],int len);

#endif /* SCONFEDERATION_H_ */
