/*
 ============================================================================
 Name        : ejercicio-3-5.c
 Author      : Rodriguez Juan Manuel
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int sumar1(int numeroUno, int numeroDos);

int sumar2(void);

void sumar3(int numUno,int numDos);

void sumar4(void);

int main(void) {
	setbuf(stdout, NULL);

	int numeroUno;
	int numeroDos;
	int resultadoDeSumar1;
	int resultadoDeSumar2;

	printf("Ingrese el primer numero: ");
	scanf("%d",&numeroUno);

	printf("Ingrese el segundo numero: ");
	scanf("%d",&numeroDos);

	resultadoDeSumar1=sumar1(numeroUno, numeroDos);

	resultadoDeSumar2=sumar2();



	printf("Ingrese el primer numero para suma3: ");
	scanf("%d",&numeroUno);

	printf("Ingrese el segundo numero para suma3: ");
	scanf("%d",&numeroDos);

	printf("sumar1: %d\n"
				"sumar2: %d\n",resultadoDeSumar1,resultadoDeSumar2 );
	sumar3(numeroUno, numeroDos);

	sumar4();

	return EXIT_SUCCESS;
}

int sumar1(int numeroUno, int numeroDos)
{
	int suma;

	suma = numeroUno + numeroDos;

	return suma;
}

int sumar2(void)
{
	int numUno;
	int numDos;
	int suma;

	printf("Ingrese el primer numero para suma: ");
	setbuf(stdout, NULL);
	scanf("%d", &numUno);

	printf("Ingrese el segundo numero para suma:");
	setbuf(stdout, NULL);
	scanf("%d", &numDos);

	suma = numUno + numDos;

	return suma;
}

void sumar3(int numUno,int numDos)
{
	int sumar;

	sumar = numUno + numDos;

	printf("sumar3: %d\n",sumar);
}

void sumar4(void)
{

	int suma;

	suma = sumar2();

	printf("sumar4: %d\n", suma);

}

