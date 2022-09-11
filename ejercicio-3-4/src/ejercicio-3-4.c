/*
 ============================================================================
 Name        : ejercicio-3-4.c
 Author      : Rodriguez Juan Manuel
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int pedirEntero(int *numero);

int main(void) {
	setbuf(stdout, NULL);

	int numeroPedido;

	if(pedirEntero(&numeroPedido)==1)
	{
		printf("El numero ingresado por funcion es: %d", numeroPedido);
	}
	else
	{
		printf("El numero ingresado no estaba dentro del rango solicitado");
	}

	return EXIT_SUCCESS;
}

int pedirEntero(int *numero)
{
	int ret=0;
	int numeroIngresado;

	printf("Por favor ingrese un numero entero (entre el 5 y el 10) ");
	fflush(stdout);
	scanf("%d", &numeroIngresado);

	if(numeroIngresado>4 && numeroIngresado<11)
		{
			ret=1;
			*numero = numeroIngresado;
		}

	return ret;
}
