/*
 ============================================================================
 Name        : 30-09-22-parcial-mockup.c
 Author      : Rodriguez Juan Manuel
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

		 ENTIDADES:
			Fecha:
				 dia
				 mes
				 año

			Tipo:
				 idTipo (comienza en 1000)
				 descripción (máx 30 caracteres)

			Recurso:
				 idRecurso
				 descripción (máx 20 caracteres)
				 precioPorHora
				 tipoId

			Evento:
				 idEvento (comienza en 20000)
				 recursoId (debe existir) Validar
				 cantidad
				 localidad (máx 30 caracteres)
				 fecha (Validar día, mes y año)

			DATOS PREVIOS:
			Los tipos deberán ser hardcodeados.
			Tipo: (1-LOCUCION, 2-ANIMACION, 3-ILUMINACION, 4-DJ)

			MENU DE OPCIONES:

			A. ALTA RECURSO

			B. MODIFICAR RECURSO: Se ingresará el idRecurso, permitiendo en un submenú modificar:
				 precioPorHora
				 descripción

			C. BAJA RECURSO: Se ingresará el id del recurso y se realizará una baja lógica.

 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
