/*
 ============================================================================
 Name        : ejercicio-3-3.c
 Author      : Rodriguez Juan Manuel
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int pedirEntero(void);

int main(void) {
	setbuf(stdout, NULL);

	int numeroPedido;

	numeroPedido=pedirEntero();

	printf("El numero ingresado por funcion es: %d", numeroPedido);

	return EXIT_SUCCESS;
}

int pedirEntero(void)
{
	int numeroIngresado;

	printf("Por favor ingrese un numero entero: ");
	scanf("%d", &numeroIngresado);

	return numeroIngresado;
}
