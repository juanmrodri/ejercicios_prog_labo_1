/*
 ============================================================================
 Name        : ejercicio-2-2.c
 Author      : Rodriguez Juan Manuel
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 	 Ingresar 10 números enteros, distintos de cero. Mostrar:
		Cantidad de pares e impares.
		El menor número ingresado.
		De los pares el mayor número ingresado.
		Suma de los positivos.
		Producto de los negativos.

 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int cantidadNumeros;
	int numeroIngresado;
	int cantidadNumerosPar;
	int cantidadNumerosImpar;
	int mayorNum;
	int menorNum;
	int banderaPrimerNum;
	int mayorNumPar;
	int sumaPositivos;
	int productoNegativos;
	int banderaPrimerNegativo;

	cantidadNumeros=10;
	cantidadNumerosPar=0;
	cantidadNumerosImpar=0;
	mayorNum=0;
	menorNum=0;
	banderaPrimerNum=1;
	mayorNumPar=0;
	sumaPositivos=0;
	productoNegativos=0;
	banderaPrimerNegativo=1;

	while(cantidadNumeros>0)
	{
		printf("Por favor ingrese un numero entero distinto a cero: ");
		fflush(stdin);
		scanf("%d", &numeroIngresado);

		// no puede ser cero
		while(numeroIngresado==0)
		{
			printf("Por favor el numero tiene que ser distinto de cero: ");
			fflush(stdin);
			scanf("%d", &numeroIngresado);
		}
		printf("--------------------------------------------------\n");

		//hacemos el primer negativo que sea 1, sino, se muestra 0 al no haber ninguno, ese 1 se multiplica la primera vez, con el numero ingresado mas abajo
		if(banderaPrimerNegativo==1)
		{
			if(numeroIngresado<0)
				{
					banderaPrimerNegativo=0;
					productoNegativos=1;
				}
		}

		// menor numero ingresado

		if(banderaPrimerNum==1)
		{
			banderaPrimerNum=0;
			mayorNum=numeroIngresado;
			menorNum=numeroIngresado;
		}
		else
		{
			if(numeroIngresado<menorNum)
			{
				menorNum=numeroIngresado;
			}
			else
			{
				if(numeroIngresado>mayorNum)
				{
					mayorNum=numeroIngresado;
					if(mayorNum%2==0)
					{
						mayorNumPar=mayorNum;
					}
				}
			}
		}
		// cantidad de pares e impares
		if(numeroIngresado%2==0)
		{
			cantidadNumerosPar++;
		}
		else
		{
			if(numeroIngresado%2!=0)
			{
				cantidadNumerosImpar++;
			}
		}

		// suma positivos

		if(numeroIngresado>0)
		{
			sumaPositivos=sumaPositivos+numeroIngresado;
		}

		// producto negativos

		if(numeroIngresado<0)
		{
			productoNegativos=productoNegativos*numeroIngresado;
		}

		// disminuimos la cantidad
		cantidadNumeros--;
	}



	printf("Pares: %d\n"
		   "Impares: %d\n"
		   "Menor numero ingresado: %d\n"
		   "Mayor numero par ingresado: %d\n"
		   "Suma de los positivos: %d\n"
		   "Producto de los negativos: %d\n",cantidadNumerosPar, cantidadNumerosImpar, menorNum, mayorNumPar, sumaPositivos, productoNegativos);


	return EXIT_SUCCESS;
}
