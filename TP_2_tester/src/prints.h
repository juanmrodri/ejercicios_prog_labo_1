/*
 * prints.h
 *
 *  Created on: 23 oct 2022
 *      Author: juanm
 */

#ifndef PRINTS_H_
#define PRINTS_H_


#include <stdio.h>
#include <stdlib.h>
#include "sPlayer.h"
#include "sConfederation.h"
#include "utn_input.h"

/**
* \brief busca el nombre de la confederacion por id
* \param arrayConfederation array de estructuras
* \param len longitud del array
* \param auxId id de la confederacion a buscar
* \param auxName array de char por el que se pasara por referencia el nombre
*/
void prints_findConfederationNameById(sConfederation arrayConfederations[], int lenConfederations, int auxId, char auxName[]);

/**
* \brief imprime una posicion del array
* \param player una estructura sola
* \param auxConfederationName nombre de la confederederacion a imprimir
*/
void prints_printPlayerWithConfederation(sPlayer player, char auxConfederationName[]);

/**
* \brief realiza un loop en el array, llamando por cada vuelta, a la funcion que imprime una posicion
* \param arrayPlayer array de estructuras
* \param lenPlayers longitud del array
* \param arrayConfederation array de estructuras
* \param lenConfederations longitud del array
*/
void prints_printPlayersWithConfederations(sPlayer arrayPlayers[], int lenPlayers, sConfederation arrayConfederations[], int lenConfederations);

/**
* \brief realiza un loop en el array, llamando por cada vuelta, a la funcion que imprime una posicion
* \param arrayPlayer array de estructuras
* \param lenPlayers longitud del array
* \param arrayConfederation array de estructuras
* \param lenConfederations longitud del array
*/
void prints_printPlayersWithConfederationsOrderedById(sPlayer arrayPlayers[], int lenPlayers, sConfederation arrayConfederations[], int lenConfederations);

/**
* \brief se encarga de ordenar por id el array de jugadores
* \param arrayPlayer array de estructuras
* \param lenPlayers longitud del array
*/
void prints_orderArrayById(sPlayer arrayPlayers[], int lenPlayers);


#endif /* PRINTS_H_ */
