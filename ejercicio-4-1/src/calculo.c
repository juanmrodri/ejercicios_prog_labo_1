/*
 * calculo.c
 *
 *  Created on: 2 sept 2022
 *      Author: juanm
 */

#include "calculo.h"

int calcularFactorial(int numero)
{
	int i;
	int factorial;
	int numeroPrevio=1;

	for(i=numero;i>1;i--)
	{
		factorial=i*numeroPrevio;
		//printf("El factorial de %d\n", factorial);
		numeroPrevio=factorial;
	}

	return factorial;
}

void imprimirFactorial(int numero, int factorial)
{
	printf("El factorial de %d es: %d\n", numero, factorial);
}



