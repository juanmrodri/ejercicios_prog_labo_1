/*
 * sPlayer.h
 *
 *  Created on: 18 oct 2022
 *      Author: juanm
 */

#ifndef SPLAYER_H_
#define SPLAYER_H_

#include <stdio.h>
#include <stdlib.h>
#include "utn_input.h"

typedef struct
{
	int id;
	char name[50];
	char position[50]; // DELANTERO - MEDIOCAMPISTA - DEFENSOR - ARQUERO (VALIDAR)
	short shirtNumber;
	int confederationId;
	float salary;
	short contractYears;
	short isEmpty;
}sPlayer;

/**
* \brief inicializa un array asignando valor 0 a "campo" isEmpty de la estructura
* \param pArray array de estructuras
* \param len longitud del array
* \return ret = [0] - error = [-1]
*/
int sPlayer_initArray(sPlayer pArray[],int len);

/**
* \brief realiza la carga de un array de manera forzada, con valores hardcodeados
* \param pArray array de estructuras
* \param len longitud del array
* \param name nombre hardcodeada
* \param position posicion hardcodeada
* \param shirtNumber numero de camiseta hardcodeada
* \param salary sueldo hardcodeado
* \param contractYears anios de contrato hardcodeado
* \param confederationId id confederacion hardcodeado
*/
void sPlayer_forceLoad(sPlayer pArray[], int len, char name[], char position[], short  shirtNumber, float salary, short contractYears, int confederationId);

/**
* \brief busca la primer posicion libre en un array
* \param pArray array de estructuras
* \param len longitud del array
* \return el indice de la posicion libre
*/
int sPlayer_findEmptyArrayPosition(sPlayer pArray[],int len);


/**
* \brief busca la posicion de un jugador por su id
* \param pArray array de estructuras
* \param len longitud del array
* \param id selecionado a validar
* \return el indice del id
*/
int sPlayer_findPlayerById(sPlayer pArray[],int len, int id);


/**
* \brief busca el id de confederacion por id jugador
* \param pArray array de estructuras
* \param len longitud del array
* \param id selecionado a validar
* \return el id jugador
*/
int sPlayer_findPlayerConfederationId(sPlayer pArray[],int len, int id);

/**
* \brief busca la si existe alguna posicion del array con el "campo" isEmpty en 1
* \param pArray array de estructuras
* \param len longitud del array
* \return ret = [0] - error = [-1]
*/
int sPlayer_isPlayerAdded(sPlayer pArray[],int len);

/**
* \brief toma los datos para llamar a la funcion que los agrega al array
* \param pArray array de estructuras
* \param len longitud del array
* \param confederationId id de la confederacion, solicitado previamente
* \return ret = [0] - error = [-1]
*/
int sPlayer_load(sPlayer pArray[], int len, int confederationId);

/**
* \brief recibe los datos tomados por la funcion load (validados)
* \param pArray array de estructuras
* \param len longitud del array
* \param name nombre validado
* \param position posicion validada
* \param shirtNumber numero de camiseta validado
* \param salary salario validado
* \param contractYears anios de contratacion validados
* \param confederationId id recibido por parametro en load, llega aca y se carga
* \return ret = [0] - error = [-1]
*/
int sPlayer_add(sPlayer pArray[], int len, char name[], char position[], short  shirtNumber, float salary, short contractYears, int confederationId);

/**
* \brief se encarga de realizar una baja logica cambiando el valor de isEmpty a 0
* \param pArray array de estructuras
* \param len longitud del array
* \param id selecionado a validar
* \return ret = [0] - error = [-1]
*/
int sPlayer_removePlayer(sPlayer pArray[],int len, int id, char auxConfederationName[]);

/**
* \brief se encarga de modificar algun campo del jugador (elegido por el usuario)
* \param pArray array de estructuras
* \param len longitud del array
* \param pos selecionada a validar
* \return ret = [0] - error = [-1]
*/
int sPlayer_ModifyPlayer(sPlayer pArray[],int len, int pos, char auxConfederationName[], int option);

/**
* \brief se encarga de modificar la confederacion
* \param pArray array de estructuras
* \param len longitud del array
* \param id selecionado a validar
* \return ret = [0] - error = [-1]
*/
int sPlayer_ModifyPlayerConfederation(sPlayer pArray[],int len, int id, char auxConfederationName[], int auxIdConfederationSelectedToModify);

/**
* \brief imprime una posicion del array
* \param player una estructura sola
* \param auxConfederationName descripcion recibida para poder imprimir
*/
void sPlayer_printPlayer(sPlayer player, char auxConfederationName[]);


#endif /* SPLAYER_H_ */
