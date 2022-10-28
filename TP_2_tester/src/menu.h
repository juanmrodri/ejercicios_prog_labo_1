/*
 * menu.h
 *
 *  Created on: 7 oct 2022
 *      Author: juanm
 */

#ifndef MENU_H_
#define MENU_H_

#include <stdio.h>
#include <stdlib.h>
#include "utn_input.h"
#include "sPlayer.h"
#include "sConfederation.h"
#include "prints.h"
#include "report.h"

/**
* \brief muestra el menu principal de opciones, y pide al usuario que elija que quiere hacer
* \param response respuesta ingresada por el usuario
* \return ret = [0] - error = [-1]
*/
int menu_show(int*  response);

/**
* \brief recibe la respuesta y llama a la funcion correspondiente para realizar la accion
* \param response respuesta ingresada por el usuario
* \return ret = [0] - error = [-1]
*/
int menu_responseOptionCaller(int  response, sPlayer arrayPlayers[], int lenPlayers, sConfederation arrayConfederations[], int lenConfederations);

/**
* \brief se encarga de llamar a la funcion que da de alta a los jugadores
* \param arrayPlayers array de estructura jugador
* \param lenPlayers longitud de estructura jugador
* \param arrayConfederations array de estructura confederacion
* \param lenConfederations longitud de estructura confederacion
* \return ret = [0] - error = [-1]
*/
int menu_playerLoad(sPlayer arrayPlayers[], int lenPlayers, sConfederation arrayConfederations[], int lenConfederations);

/**
* \brief se encarga de llamar a la funcion que da de baja (logica) a los jugadores
* \param arrayPlayers array de estructura jugador
* \param lenPlayers longitud de estructura jugador
* \param arrayConfederations array de estructura confederacion
* \param lenConfederations longitud de estructura confederacion
* \return ret = [0] - error = [-1]
*/
int menu_playerRemove(sPlayer arrayPlayers[], int lenPlayers, sConfederation arrayConfederations[], int lenConfederations);

/**
* \brief se encarga de llamar a la funcion que permite modificar los datos de los jugadores ingresados
* \param arrayPlayers array de estructura jugador
* \param lenPlayers longitud de estructura jugador
* \param arrayConfederations array de estructura confederacion
* \param lenConfederations longitud de estructura confederacion
* \return ret = [0] - error = [-1]
*/
int menu_playerModify(sPlayer arrayPlayers[], int lenPlayers, sConfederation arrayConfederations[], int lenConfederations);

/**
* \brief se encarga de llamar a la funcion que permite mostrar el menu de informes
* \param arrayPlayers array de estructura jugador
* \param lenPlayers longitud de estructura jugador
* \param arrayConfederations array de estructura confederacion
* \param lenConfederations longitud de estructura confederacion
* \return ret = [0] - error = [-1]
*/
int menu_reportShow(sPlayer arrayPlayers[], int lenPlayers, sConfederation arrayConfederations[], int lenConfederations);

#endif /* MENU_H_ */
