/*
 ============================================================================
 Name        : ejercicio-4-1.c
 Author      : Rodriguez Juan Manuel
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "pedirNumero.h"
#include "calculo.h"

int main(void) {
	setbuf(stdout, NULL);

	int numeroIngresado;
	int factorial;

	if(pedirEntero(&numeroIngresado)==1)
	{
		factorial = calcularFactorial(numeroIngresado);

		imprimirFactorial(numeroIngresado, factorial);
	}


	return EXIT_SUCCESS;
}


