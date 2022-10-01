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
				 a�o

			Tipo:
				 idTipo (comienza en 1000)
				 descripci�n (m�x 30 caracteres)

			Recurso:
				 idRecurso
				 descripci�n (m�x 20 caracteres)
				 precioPorHora
				 tipoId

			Evento:
				 idEvento (comienza en 20000)
				 recursoId (debe existir) Validar
				 cantidad
				 localidad (m�x 30 caracteres)
				 fecha (Validar d�a, mes y a�o)

			DATOS PREVIOS:
			Los tipos deber�n ser hardcodeados.
			Tipo: (1-LOCUCION, 2-ANIMACION, 3-ILUMINACION, 4-DJ)

			MENU DE OPCIONES:

			A. ALTA RECURSO

			B. MODIFICAR RECURSO: Se ingresar� el idRecurso, permitiendo en un submen� modificar:
				 precioPorHora
				 descripci�n

			C. BAJA RECURSO: Se ingresar� el id del recurso y se realizar� una baja l�gica.

 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
