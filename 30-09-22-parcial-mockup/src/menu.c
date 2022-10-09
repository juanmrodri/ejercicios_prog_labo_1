/*
 * menu.c
 *
 *  Created on: 7 oct 2022
 *      Author: juanm
 */

#include "menu.h"

#define RES_LEN 10
#define TYPE_LEN 4

// static functions

static int errorCount(void);

// static developing

static int errorCount(void)
{
	static int cont=1;
	return cont++;
}

int menu_show(int*  response)
{
	int ret=-1;
	int bufferResponse;
	int errors;

	if(utn_getInt(&bufferResponse, "1- ALTA DE RECURSO\n"
															"2- MODIFICAR RECURSO\n"
															"3- BAJA RECURSO\n"
															"4- LISTAR RECURSOS\n"
															"5- LISTAR TIPOS\n"
															"6- ALTA EVENTO\n"
															"7- LISTAR EVENTOS\n"
															"8- INFORMES\n -> ", "Error al ingresar opcion!\n\n",1,8, 2)==0)
	{
		if(bufferResponse>0 && bufferResponse<9)
		{
			*response=bufferResponse;
			ret=0;
		}
		else
		{
			printf("\nError al seleccionar\n\n");
		}
	}
	else
	{
		if(!(bufferResponse>0 && bufferResponse<9))
		{
			errors = errorCount();
			//printf("\nError(es): %d\n\n",errors);
			if(errors==2)
			{
				printf("\nPor favor intente ingresando un numero (1 - 8)\n\n");
			}
		}

	}

	return ret;
}

int menu_resolve(int response, Resource arrayResources[], int lenResource, Type arrayTypes[], int lenType)
{
	int ret=-1;
	int auxTypeId;
	int auxId;
	int auxPos;

	if(response>0 && response <9 && arrayResources!=NULL && arrayTypes!=NULL)
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
							if(utn_getInt(&auxTypeId, "Por favor ingrese el tipo de recurso (1- Animacion 2- Dj 3- Iluminacion 4- Locucion): ", "Error al ingresar el tipo\n", 1, 4, 2)==0)
							{
									// con esto obtenemos el id y lo mandamos al add como llave foranea de Resource
									auxTypeId = type_findIdByPos(arrayTypes, TYPE_LEN, auxTypeId);

									// aca llamamos a la carga de recurso y le mandamos el idType
									resource_load(arrayResources, RES_LEN, auxTypeId);
							}

						}
						else
						{
							printf("\nPor el momento no se pueden cargar mas recursos\n");
						}
						break;
					case 2:
						// modificacion
						if(resource_isResourceAdded(arrayResources, RES_LEN)==0)
						{
							printf("\n\tModificar recurso\n");
							printf("\n----------------------------------------------\n");
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
							printf("\n----------------------------------------------\n\n");
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
							printf("\n\tBaja recurso\n");
							printf("\n----------------------------------------------\n");
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
							printf("\n----------------------------------------------\n\n");
						}
						else
						{
							printf("\nNo existen recursos ingresados!\n\n");
						}
						break;
					case 4:
						if(resource_isResourceAdded(arrayResources, RES_LEN)==0)
						{
							printf("\n\tLista de recursos\n");
							printf("\n----------------------------------------------\n");
							// primero ordenamos el tipo, y adentro de esa funcion, llamamos a la que ordena la descripcion
							resource_arrayAscendingOrderById(arrayResources, RES_LEN);
							resource_printResources(arrayResources, RES_LEN);
							printf("\n----------------------------------------------\n\n");
						}
						else
						{
							printf("\nNo existen recursos ingresados para listar!\n\n");
						}
						break;
					case 5:
						printf("\n\tLista de tipos\n");
						printf("\n----------------------------------------------\n");
						// para probar los tipos
						type_printTypes(arrayTypes, TYPE_LEN);
						printf("\n----------------------------------------------\n\n");
						break;
					default:
						printf("\nLa opcion no existe!\n\n");
						break;
					}
	}
	return ret;
}
