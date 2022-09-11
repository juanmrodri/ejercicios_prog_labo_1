/*
 * output.c
 *
 *  Created on: 11 sept 2022
 *      Author: juanm
 */

#include "output.h"


void mostrarArrayNumeros(int numeros[], int len)
{
	int i;

	for(i=0;i<len;i++)
		{
			printf("El (%d) numero ingresado fue: %d \n",i+1,numeros[i]);
		}
}
