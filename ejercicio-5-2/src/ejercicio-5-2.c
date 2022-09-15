/*
 ============================================================================
 Name        : ejercicio-5-2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

    Pedir el ingreso de 10 números enteros entre -1000 y 1000. Determinar:

	Cantidad de positivos y negativos. ok
	Sumatoria de los pares. ok
	El mayor de los impares.
	Listado de los números ingresados.
	Listado de los números pares.
	Listado de los números de las posiciones impares.

	Anexo 5-2
	Los números que se repiten
	Los positivos creciente y los negativos de manera decreciente
	Se deberán utilizar funciones y vectores.


 */

#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "checkers.h"

int main(void) {
	setbuf(stdout, NULL);

	int numeroIngresado;
	int i;
	int cantidadPositivos;
	int cantidadNegativos;
	int sumaPares;
	int minImpar;
	int maxImpar;
	int imparFlag;
	int listaNumeros[10];
	//int listaPares[10];
	//int listaPosImpares[10];

	cantidadPositivos=0;
	cantidadNegativos=0;
	sumaPares=0;
	imparFlag=1;


	for(i=0;i<10;i++)
	{
		utn_getNumber(&numeroIngresado, "Por favor ingrese un entero entre -1000 y 1000: ", "Error al ingresar el numero\n", -1000, 1000, 2);
		printf("\n%d)---> %d\n\n",i+1,numeroIngresado);

		// checkeo de positivos y negativos
		if(checkPositiveNumber(numeroIngresado)==0)
		{
			cantidadPositivos++;
		}
		else
		{
			if(checkNegativeNumber(numeroIngresado)==0)
			{
				cantidadNegativos++;
			}
		}

		// checkeo de numeros pares e impares
		if(checkEvenNumber(numeroIngresado)==0)
		{
			// el numero es par
			sumaPares=sumaPares+numeroIngresado;
		}
		else
		{
			if(checkOddNumber(numeroIngresado)==0)
			{
				checkMaxOddNumber(&imparFlag, &minImpar, &maxImpar, numeroIngresado);
			}
		}
		// listados

		// se carga el numero ingresado en el array de numeros
		listaNumeros[i]=numeroIngresado;

	}


	printf("positivos: %d\n"
			   "negativos: %d\n"
			   "Suma de los pares: %d\n"
			   "Mayor de los impares: %d\n", cantidadPositivos, cantidadNegativos,sumaPares,maxImpar);

	for(i=0;i<10;i++)
	{
		printf("Pos.%d) contiene el numero: %d\n",i,listaNumeros[i]);
	}


	return EXIT_SUCCESS;
}
