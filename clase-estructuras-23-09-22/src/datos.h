/*
 * datos.h
 *
 *  Created on: 28 sept 2022
 *      Author: juanm
 */

#ifndef DATOS_H_
#define DATOS_H_

typedef struct {
	char calle[20];
	int altura;
}domicilio;

typedef struct {
	char nombre[20];
	char apellido[20];
	int legajo;
	domicilio direccion;
} datosPersonales;


#endif /* DATOS_H_ */
