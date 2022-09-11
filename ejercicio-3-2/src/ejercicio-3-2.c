/*
 ============================================================================
 Name        : ejercicio-3-2.c
 Author      : Rodriguez Juan Manuel
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int esPar(int numero);

int main(void) {
	setbuf(stdout, NULL);

	int numeroIngresado;

	printf("Por favor ingrese un numero entero: ");
	fflush(stdin);
	scanf("%d", &numeroIngresado);

	if(esPar(numeroIngresado)==1)
	{
		printf("El numero %d es par ", numeroIngresado);
	}
	else
	{
		printf("El numero %d no es par ", numeroIngresado);
	}

	return EXIT_SUCCESS;
}

int esPar(int numero)
	{
		int ret=0;

		if(numero%2==0)
		{
			ret=1;
		}

		return ret;
	}
