/*
 ============================================================================
 Name        : ejercicio-5-1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "output.h"
#include "operacion.h"
#define LEN 5

int main(void) {
	setbuf(stdout, NULL);

	int numeroIngresado;
	int i;
	int numeros[5];
	int resultadoSuma;

	for(i=0;i<5;i++)
	{
		if(utn_getNumber(&numeroIngresado, "Por favor ingrese un numero entero: ",  "Error al ingresar el numero\n", -1200000, 1200000, 2)==0)
			{
				numeros[i]=numeroIngresado;
			}
	}

	mostrarArrayNumeros(numeros, LEN);

	resultadoSuma = sumarNumerosArray(numeros, LEN);

	mostrarSumaArray(resultadoSuma);

	return EXIT_SUCCESS;
}


