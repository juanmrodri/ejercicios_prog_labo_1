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
#include "utn_input.h"
#include "sResource.h"
#include "sType.h"
#include "sEvent.h"
#include "menu.h"

#define RES_LEN 10
#define TYPE_LEN 4

int main(void) {
	setbuf(stdout, NULL);

	int response;

	Resource arrayResources[RES_LEN]; // por ahora 10

	Type arrayTypes[TYPE_LEN];

	resource_initArray(arrayResources, RES_LEN);

	type_initArray(arrayTypes, TYPE_LEN);

	type_forceLoad(arrayTypes, TYPE_LEN, "ANIMACION");
	type_forceLoad(arrayTypes, TYPE_LEN, "DJ");
	type_forceLoad(arrayTypes, TYPE_LEN, "ILUMINACION");
	type_forceLoad(arrayTypes, TYPE_LEN, "LOCUCION");

	// los type id = 1000 - LOCUCION; 1001 - ANIMACION; 1002 - ILUMINACION; 1003 - DJ
	resource_forceLoad(arrayResources, RES_LEN, "Actor, mago", 12500, 1003);
	resource_forceLoad(arrayResources, RES_LEN, "Luces, leds,camaras", 1200, 1002);
	resource_forceLoad(arrayResources, RES_LEN, "Leds", 20000, 1002);
	resource_forceLoad(arrayResources, RES_LEN, "Hernan Cattaneo", 350000, 1000);
	resource_forceLoad(arrayResources, RES_LEN, "Principi", 20000, 1000);
	resource_forceLoad(arrayResources, RES_LEN, "Pablo y Pachu", 350000, 1002);
	resource_forceLoad(arrayResources, RES_LEN, "Pichu", 200000, 1002);
	resource_forceLoad(arrayResources, RES_LEN, "Brzp", 350000, 1003);
	resource_forceLoad(arrayResources, RES_LEN, "Jamie Hewlett", 350000, 1001);
	resource_forceLoad(arrayResources, RES_LEN, "Daft Punk", 350000, 1000);
	//menu

	do
	{

		if(menu_show(&response)==0) // aca llamamos a todo el menu
		{
			menu_resolve(response, arrayResources, RES_LEN, arrayTypes, TYPE_LEN);
		}
		else
		{
			printf("\nIntente de nuevo por favor!\n\n");
		}

	}while(response!=9);


	return EXIT_SUCCESS;
}
