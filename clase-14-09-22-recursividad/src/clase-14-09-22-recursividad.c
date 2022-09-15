/*
 ============================================================================
 Name        : clase-14-09-22-recursividad.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int factorial(int numero)
{
	if(numero == 1)
	{
		return 1;
	}
	return numero * factorial(numero - 1);
}


int main(void) {
	setbuf(stdout, NULL);

	int numero=3;
	int resultado = factorial(numero);
	printf("El factorial de %d, es %d", numero, resultado);


	return EXIT_SUCCESS;
}
