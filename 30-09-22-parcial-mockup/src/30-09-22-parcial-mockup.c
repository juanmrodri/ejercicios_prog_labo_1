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

#define RES_LEN 1
#define TYPE_LEN 4

int main(void) {
	setbuf(stdout, NULL);

	Resource arrayResources[RES_LEN]; // por ahora 10

	Type arrayTypes[TYPE_LEN];

	resource_initArray(arrayResources, RES_LEN);

	type_initArray(arrayTypes, TYPE_LEN);

	type_forceLoad(arrayTypes, TYPE_LEN, "LOCUCION");
	type_forceLoad(arrayTypes, TYPE_LEN, "ANIMACION");
	type_forceLoad(arrayTypes, TYPE_LEN, "ILUMINACION");
	type_forceLoad(arrayTypes, TYPE_LEN, "DJ");

	int response;

	//menu

	do
	{

		if(utn_getInt(&response, "1- ALTA DE RECURSO\n"
													 "2- MODIFICAR RECURSO\n"
													 "3- BAJA RECURSO\n"
													 "4- LISTAR RECURSOS\n -> ", "Error al ingresar opcion!\n\n",1,5, 2)==0)
		{
			switch(response)
			{
			case 1:
				if(resource_findEmptyArrayPosition(arrayResources, RES_LEN)>-1)
				{
					printf("\nAlta de recurso\n");
					// significa que hay posiciones libres
					resource_load(arrayResources, RES_LEN, arrayTypes, TYPE_LEN);
				}
				else
				{
					printf("Por el momento, no se pueden cargar mas recursos\n");
				}
				break;
			case 2:
				printf("Modificar recurso\n");
				break;
			case 3:
				printf("Baja de recurso\n");
				break;
			case 4:
				resource_printResources(arrayResources, RES_LEN);
				break;
			case 5:
				// para probar los tipos
				type_printTypes(arrayTypes, TYPE_LEN);
				break;
			}
		}
		else
		{
			// error al ingresar opcion
			// mesaje para avivar del error, igualmente vuelve a pedir el dato
			printf("Por favor seleccione una opcion valida!\n\n");
		}

	}while(response!=9);


	return EXIT_SUCCESS;
}
