/*
 * operacion.c
 *
 *  Created on: 11 sept 2022
 *      Author: juanm
 */

#include "operacion.h"

int sumarNumerosArray(int array[], int len)
{
	int sumaNumeros;
	int i;

	sumaNumeros=0;

	if(array!=NULL && len>0)
	{
		for(i=0;i<len;i++)
			{
				sumaNumeros=sumaNumeros+array[i];
			}
	}

	return sumaNumeros;
}

void mostrarSumaArray(int resultado)
{
	int result;

	result=resultado;

	printf("La suma del array de numeros es: %d",result);
}
