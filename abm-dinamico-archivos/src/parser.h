/*
 * parser.h
 *
 *  Created on: 27 oct 2022
 *      Author: juanm
 */

#ifndef PARSER_H_
#define PARSER_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "empleado.h"

int parseEmpleadoDesderTexto(FILE* pArchivo, eEmpleado** empleados);

int parserEmpleadoDesdeBinario(FILE* pArchivo, eEmpleado** empleados);

#endif /* PARSER_H_ */
