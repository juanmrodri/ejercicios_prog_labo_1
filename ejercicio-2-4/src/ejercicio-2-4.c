/*
 ============================================================================
 Name        : ejercicio-2-4.c
 Author      : Rodriguez Juan Manuel
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int cantidadLetras;
	int i;
	char caracterIngresado;
	int cantidadLetrasP;

	cantidadLetras=5;
	cantidadLetrasP=0;

	for(i=0;i<cantidadLetras;i++)
	{
		// pedido de caracter
		printf("Ingrese un caracter por favor:");
		fflush(stdin);
		scanf("%c", &caracterIngresado);

		if(caracterIngresado=='p')
		{
			cantidadLetrasP++;
		}

		printf("i: %d\n", i);
	}

	printf("La cantidad de letras p que se ingresaron es: %d\n", cantidadLetrasP);

	return EXIT_SUCCESS;
}
