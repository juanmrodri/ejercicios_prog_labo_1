/*
 ============================================================================
 Name        : ejercicio-18-0.c
 Author      : Rodriguez Juan Manuel
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "strings.h"
#include "utn_input.h"

int main(void) {
	setbuf(stdout, NULL);
	char nombreYapellito[] = "sarlanga";
	int cantidadAescribir;
	int longitud;
	FILE *pArch;


	if((pArch=fopen("nombreYapellido.txt","w"))==NULL)
	{
		printf("No se puede abrir el archivo\n\n");
	}

		longitud=strlen(nombreYapellito);
		cantidadAescribir = fwrite(nombreYapellito,sizeof(char),longitud,pArch);
		if(cantidadAescribir<longitud)
		{
			printf("Error al escribir el archivo!\n\n");
		}
		else
		{
			printf("Se escribieron %d caractere(s)\n\n",longitud);
		}
		fclose(pArch);

	return EXIT_SUCCESS;
}
