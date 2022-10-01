/*
 ============================================================================
 Name        : clase-estructuras-23-09-22.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "datos.h"

int main(void) {
	setbuf(stdout, NULL);

	int i, j;

		datosPersonales datosProfesores[20];
		//datosPersonales datosEstudiantes[20];
		datosPersonales aux;

		for (i = 0; i < 20; i++) {
			printf("\nIngrese nombre ");
			gets(datosProfesores[i].nombre);
			printf("\nIngrese apellido ");
			gets(datosProfesores[i].apellido);
			printf("\nIngrese calle ");
			gets(datosProfesores[i].direccion.calle);
			printf("\nIngrese numero ");
			scanf("%d", &datosProfesores[i].legajo);
			fflush(stdin);
		}

		for (i = 0; i < 20 - 1; i++) {
			for (j = i + 1; j < 20; j++) {
				if (datosProfesores[i].direccion.altura > datosProfesores[j].direccion.altura) {
					aux = datosProfesores[i];
					datosProfesores[i] = datosProfesores[j];
					datosProfesores[j] = aux;
				}
			}

		}

	return EXIT_SUCCESS;
}
