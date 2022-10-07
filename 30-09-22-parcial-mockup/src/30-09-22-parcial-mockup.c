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
#include "utn_input.h"
#include "sResource.h"
#include "sType.h"

#define RES_LEN 4
#define TYPE_LEN 4

int main(void) {
	setbuf(stdout, NULL);

	int response;
	int auxTypeId;
	int auxId;
	int auxPos;

	Resource arrayResources[RES_LEN]; // por ahora 10

	Type arrayTypes[TYPE_LEN];

	resource_initArray(arrayResources, RES_LEN);

	type_initArray(arrayTypes, TYPE_LEN);

	type_forceLoad(arrayTypes, TYPE_LEN, "LOCUCION");
	type_forceLoad(arrayTypes, TYPE_LEN, "ANIMACION");
	type_forceLoad(arrayTypes, TYPE_LEN, "ILUMINACION");
	type_forceLoad(arrayTypes, TYPE_LEN, "DJ");



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
				// alta
				if(resource_findEmptyArrayPosition(arrayResources, RES_LEN)>-1)
				{
					printf("\n\tAlta de recurso\n");
					printf("\n----------------------------------------------\n");
					// significa que hay posiciones libres

					// primero preguntamos que tipo queremos cargar, para separar la estructuras, antes llamaba la estructura type y su len en resource_load, asi queda mas prolijo

					// mostramos los tipos disponibles para poder elegir
					type_printTypes(arrayTypes, TYPE_LEN);
					if(utn_getInt(&auxTypeId, "Por favor ingrese el tipo de recurso (1- Locucion 2- Animacion 3- Iluminacion 4- Dj): ", "Error al ingresar el tipo\n", 1, 4, 2)==0)
					{
							// con esto obtenemos el id y lo mandamos al add como llave foranea de Resource
							auxTypeId = type_findIdByPos(arrayTypes, TYPE_LEN, auxTypeId);

							// aca llamamos a la carga de recurso y le mandamos el idType
							resource_load(arrayResources, RES_LEN, auxTypeId);
					}

				}
				else
				{
					printf("\nPor el momento, no se pueden cargar mas recursos\n");
				}
				break;
			case 2:
				// modificacion
				printf("\n\tModificar recurso\n");
				printf("\n----------------------------------------------\n");
				if(resource_isResourceAdded(arrayResources, RES_LEN)==0)
				{
					resource_printResources(arrayResources, RES_LEN);
					if(utn_getInt(&auxId, "Ingrese el Id del recurso que quiere modificar: ",  "\nError al ingresar opcion!\n\n", 1, RES_LEN, 2)==0)
					{
						auxPos = resource_findById(arrayResources, RES_LEN,auxId);
						if(auxPos>-1)
						{
							printf("\nSe eligio: \n\n");
							resource_printResource(&arrayResources[auxPos]);
							if(utn_getInt(&response, "Que desea modificar\n"
																		"1- Precio por hora\n"
																		"2- Descripcion\n -> ", "\nError al ingresar opcion!\n\n", 1, 2, 2)==0)
							{
								// aca ya estamos en condiciones de ingresar a la modificacion
								if(resource_modify(arrayResources, RES_LEN, auxPos, response)==0)
								{
									printf("\nModificacion realizada con exito\n\n");
								}
							}
							else
							{
								printf("\nError al seleccionar que quiere modificar\n\n");
							}
						}
						else
						{
							printf("\n\tEse posible que el id ingresado no exista, vuelva a intentar\n\n");
						}
					}
					else
					{
						printf("\nError al ingresar el id!\n\n");
					}
				}
				else
				{
					printf("\nNo existen recursos ingresados, no se puede realizar la modificacion!\n\n");
				}
				break;
			case 3:
				// baja
				if(resource_isResourceAdded(arrayResources, RES_LEN)==0)
				{
					resource_printResources(arrayResources, RES_LEN);
					if(utn_getInt(&auxId, "Ingrese el Id del recurso que quiere dar de baja: ",  "\nError al ingresar opcion!\n\n", 1, RES_LEN, 2)==0)
					{
						if(resource_findById(arrayResources, RES_LEN, auxId)>-1)
						{
							// el id existe
							if(resource_remove(arrayResources, RES_LEN, auxId)==0)
							{
								printf("\nEl recurso fue dado de baja de manera correcta\n\n");
							}
						}
						else
						{
							printf("\nNo existe el id seleccionado\n\n");
						}
					}
				}
				else
				{
					printf("\nNo existen recursos ingresados!\n\n");
				}
				break;
			case 4:
				if(resource_isResourceAdded(arrayResources, RES_LEN)==0)
				{
					resource_printResources(arrayResources, RES_LEN);
				}
				else
				{
					printf("\nNo existen recursos ingresados para listar!\n\n");
				}
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
