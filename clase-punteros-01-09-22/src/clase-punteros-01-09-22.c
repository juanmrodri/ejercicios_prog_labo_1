/*
 ============================================================================
 Name        : clase-punteros-01-09-22.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int numero = 4;
	int *pNumero = &numero;
	int otroNumero = 1000;

	printf("Contenido de numero\n");
	printf("Valor de numero: %d\n", numero);

	printf("Contenido de pNumero\n");
	printf("Valor de pNumero: %d\n\n", *pNumero); //accedo al valor que guarda la direccion de memoria a la que apunta pNumero

	numero = 8; //cambio el valor de numero

	printf("El valor de pNumero cambia! por que apunta a numero\n");
	printf("Valor de pNumero: %d\n\n", *pNumero);

	printf("Dir de de numero: %p\n", &numero);
	printf("Valor que guarda pNumero: %p\n", pNumero); //pNumero en si almacena una direccion de memoria
	printf("Muestran el mismo valor por que en la variable puntero a entero (pNumero) guarde la direccion de memoria de numero\n\n\n");

	printf("Dir de de pNumero: %p\n", &pNumero);
	printf("Por que esta direccion es distinta? por que es de la variable pNumero no de la cual apunta\n\n\n");

	*pNumero = 8; //le cambio el CONTENIDO a la variable a la que apunta
	printf("Contenido de pNumero\n");
	printf("Valor de pNumero: %d\n\n", *pNumero); //accedo al valor que guarda la direccion de ememoria a la que apunta pNumero

	pNumero = &otroNumero; //le da dir de memoria a la que apunta
	printf("Contenido de pNumero\n");
	printf("Valor de pNumero: %d\n\n", *pNumero); //accedo al valor que guarda la direccion de ememoria a la que apunta pNumero

	printf("Valor que guarda pNumero: %p\n", pNumero); //pNumero en si almacena una direccion de memoria
	printf("Volvio a cambiar de valor! ahora por la linea 43 guarda la dir de memoria de otroNumero\n\n\n");

	return EXIT_SUCCESS;
}
