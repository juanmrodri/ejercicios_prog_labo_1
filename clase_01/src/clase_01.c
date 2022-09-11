/*
 ============================================================================
 Name        : clase_01.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int numUno;
	int numDos;
	int result;

	printf("Por favor ingrese el primer numero: ");
	scanf("%d",&numUno);

	printf("Por favor ingrese el segundo numero: ");
	scanf("%d",&numDos);

	result = numUno + numDos;

	printf("\nLa suma de %d + %d es = %d",numUno, numDos, result);

	return EXIT_SUCCESS;
}
