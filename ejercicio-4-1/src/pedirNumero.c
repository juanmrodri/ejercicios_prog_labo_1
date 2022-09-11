/*
 * pedirNumero.c
 *
 *  Created on: 2 sept 2022
 *      Author: juanm
 */

#include "pedirNumero.h"

int pedirEntero(int *numero)
{
	int ret=0;
	int numeroIngresado;

	printf("Por favor ingrese un numero entero (entre el 5 y el 10) ");
	fflush(stdout);
	scanf("%d", &numeroIngresado);

	if(numeroIngresado>2 && numeroIngresado<6)
		{
			ret=1;
			*numero = numeroIngresado;
		}

	return ret;
}
