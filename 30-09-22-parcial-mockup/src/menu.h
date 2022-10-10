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

int menu_show(int*  response);

int menu_resolve(int response, Resource arrayResources[], int lenResource, Type arrayTypes[], int lenType, Event arrayEvents[], int lenEvents);



#endif /* MENU_H_ */
