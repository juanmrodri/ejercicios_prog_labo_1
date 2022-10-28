/*
 * controller.h
 *
 *  Created on: 27 oct 2022
 *      Author: juanm
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "parser.h"

int controlerCargarDesdeTexto(char* path, eEmpleado** empleados);

int controlerCargarDesdeBinario(char* path, eEmpleado** empleados);

#endif /* CONTROLLER_H_ */
