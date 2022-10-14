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
#include "sResource.h"
#include "sType.h"
#include "sEvent.h"
#include "report.h"

/**
* \brief muestra el menu principal de opciones, y pide al usuario que elija que quiere hacer
* \param response respuesta ingresada por el usuario
* \return ret = [0] - error = [-1]
*/
int menu_show(int*  response);

/**
* \brief recibe la respuesta del usuario en menu_show e ingresa mediante un switch a la opcion correspondiente
* \param arrayResources array de estructura recurso
* \param lenResource longitud de estructura recurso
* \param arrayTypes array de estructura tipo
* \param lenType longitud de estructura tipo
* \param arrayEvents array de estructura evento
* \param lenEvents longitud de estructura evento
* \return ret = [0] - error = [-1]
*/
int menu_resolve(int response, Resource arrayResources[], int lenResource, Type arrayTypes[], int lenType, Event arrayEvents[], int lenEvents);



#endif /* MENU_H_ */
