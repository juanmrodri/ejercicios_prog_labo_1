/*
 ============================================================================
 Name        : clase-funciones-31-08-22.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int sumarNumeros(int numeroUno, int numeroDos);

int restarNumeros(int numeroUno, int numeroDos);

int main(void) {
		setbuf(stdout, NULL);

		int numeroUno;
		int numeroDos;
		char operacionElegida;
		int resultado;

		printf("ingresar el primer numero: ");
		fflush(stdin);
		scanf("%d", &numeroUno);

		printf("ingresar segundo numero: ");
		fflush(stdin);
		scanf("%d", &numeroDos);

		printf("ingresar operacion a realizar: ");
		fflush(stdin);
		scanf("%c", &operacionElegida);

		switch(operacionElegida)
		{
		case'+':
			resultado = sumarNumeros(numeroUno, numeroDos);
		break;
		case'-':
			resultado = restarNumeros(numeroUno, numeroDos);
		break;
		}

		printf("Resultado: %d", resultado);


	return EXIT_SUCCESS;
}

int sumarNumeros(int numeroUno, int numeroDos)
	{
		int resultado;

		resultado = numeroUno + numeroDos;

		return resultado;
	}

int restarNumeros(int numeroUno, int numeroDos)
{
	int resultado;

	resultado = numeroUno - numeroDos;

	return resultado;
}
