/*
 ============================================================================
 Name        : ejercicio-16-1.c
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


	return EXIT_SUCCESS;
}

int recibirPunteroAcHar(char *pAchar, char primerCaracter, char segundoCaracter)
{
	int ret=-1;
	int cantidadReemplazos;

	if(pAchar!=NULL && (primerCaracter>'a' && primerCaracter<'z') && (segundoCaracter>'a' && segundoCaracter<'z'))
	{
		primerCaracter = segundoCaracter;
		cantidadReemplazos++;
	}

	return ret;
}
