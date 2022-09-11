/*
 ============================================================================
 Name        : ejercicio-3-1.c
 Author      : Rodriguez Juan Manuel
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int mostrarNumero(float numeroMostrar);

int main(void) {
	setbuf(stdout, NULL);

	float numeroEnviadoPorParametro;

	numeroEnviadoPorParametro= 2.4;

	mostrarNumero(numeroEnviadoPorParametro);


	return EXIT_SUCCESS;
}

int mostrarNumero(float numeroMostrar)
{
	printf("El numero es: %.2f\n",numeroMostrar);

	return 0;
}
