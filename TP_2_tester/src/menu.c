/*
 * menu.c
 *
 *  Created on: 7 oct 2022
 *      Author: juanm
 */

#include "menu.h"

// static functions

static int errorCount(void);

static void errorMessage(int errors);

// static developing

static int errorCount(void)
{
	static int cont=1;
	return cont++;
}

static void errorMessage(int errors)
{
	if(errors%2==0)
	{
		printf("\nPor favor intente ingresando un numero (1 - 4)\n\n");
	}
	else
	{
		if(errors%5==0)
		{
			printf("\nSabemos que puede ser engorroso, por favor, tenga en cuenta las opciones (1 - 4)\n\n");
		}
		else
		{
			if(errors%7==0)
			{
				printf("\nSi desea puede precionar 5 para salir del programa...\n\n");
			}
			else
			{
				if(errors%3==0)
				{
					printf("\nVamos, animo...Intente con dar de alta un jugador! (opcion 1)\n\n");
				}
			}
		}
	}
}

// end of static functions

int menu_show(int*  response)
{
	int ret=-1;
	int auxResponse;
	int errors;

	if(utn_getInt(&auxResponse,"1- ALTA DE JUGADOR\n\n"
														"2- BAJA DE JUGADOR\n\n"
														"3- MODIFICACION DE JUGADOR\n\n"
														"4- INFORMES\n\n"
														"5- SALIR\n\n -> ", "Error al ingresar opcion!\n\n",1,5, 2)==0)
	{
		if(auxResponse>0 && auxResponse<5)
		{
			ret=0;
			*response=auxResponse;
		}
		else
		{
			if(auxResponse==5)
			{
				if(utn_getInt(&auxResponse,"Salir del programa\n\n"
																	"1- SI\n"
																	"2- NO\n\n ->", "Error al ingresar opcion!\n\n",1,2, 2)==0)
				{
					if(auxResponse==1)
					{
						printf("\nAdios!\n\n");
						*response=5;
					}
					else
					{
						printf("\nRegresando al menu\n\n");
					}
				}
			} // termina el if de respuesta ==5
		}
	}
	else
		{
			if(!(auxResponse>0 && auxResponse<5))
			{
				errors = errorCount();
				//printf("\nErrores: %d\n\n",errors);
				errorMessage(errors);
			}
		}

	return ret;
}

int menu_responseOptionCaller(int response, sPlayer arrayPlayers[], int lenPlayers, sConfederation arrayConfederations[], int lenConfederations)
{
	int ret=-1;
	if(arrayPlayers!=NULL && lenPlayers>0 && arrayConfederations!=NULL && lenConfederations>0)
	{
		if(response>0 && response<5)
			{
				switch(response)
					{
						case 1:
							if(sConfederation_isConfederationAdded(arrayConfederations, lenConfederations)==0)
							{
								// hay confederaciones agregadas
								if(sPlayer_findEmptyArrayPosition(arrayPlayers, lenPlayers)>-1)
								{
									printf("\n\t\tAlta de jugador\n");
									printf("----------------------------------------------\n");
									// hay lugar en el array todavia
									if(menu_playerLoad(arrayPlayers, lenPlayers,arrayConfederations, lenConfederations)==0)
									{
										printf("\nAlta terminada!\n\n");
									}
									else
									{
										printf("\nEl alta no sera posible!\n\n");
									}
								}
								else
								{
									printf("\nNo se pueden ingresar mas jugadores!\n\n");
								}
							}
							else
							{
								printf("\nNo existen confederaciones ingresadas, no se puede dar de alta!\n\n");
							}
						break;
						case 2:
							if(sConfederation_isConfederationAdded(arrayConfederations, lenConfederations)==0)
							{
								if(sPlayer_isPlayerAdded(arrayPlayers, lenPlayers)==0)
								{
									printf("\n\t\tDar de baja un jugador\n");
									printf("----------------------------------------------\n");
									if(menu_playerRemove(arrayPlayers, lenPlayers,arrayConfederations, lenConfederations)==0)
									{
										printf("\nBaja terminada!\n\n");
									}
									else
									{
										printf("\nLa baja no sera posible!\n\n");
									}
								}
								else
								{
									printf("\nNo existen jugadores ingresados, no se puede realizar la baja!\n\n");
								}
							}
							else
							{
								printf("\nNo existen confederaciones ingresadas, no se puede dar de baja!\n\n");
							}
						break;
						case 3:
							if(sConfederation_isConfederationAdded(arrayConfederations, lenConfederations)==0)
							{
								if(sPlayer_isPlayerAdded(arrayPlayers, lenPlayers)==0)
								{
									printf("\n\t\tModificar Jugador\n");
									printf("----------------------------------------------\n");
									if(menu_playerModify(arrayPlayers, lenPlayers, arrayConfederations, lenConfederations)==0)
									{
										printf("\nModificacion terminada!\n\n");
									}
									else
									{
										printf("\nLa modificacion no sera posible!\n\n");
									}
								}
								else
								{
									printf("\nNo existen jugadores ingresados, no se puede modificar!\n\n");
								}
							}
							else
							{
								printf("\nNo existen confederaciones ingresadas, no se puede modificar!\n\n");
							}
						break;
						case 4:
							if(sConfederation_isConfederationAdded(arrayConfederations, lenConfederations)==0)
							{
								if(sPlayer_isPlayerAdded(arrayPlayers, lenPlayers)==0)
								{
									printf("\n\t\tInformes\n");
									printf("----------------------------------------------\n");
									// aca llama al menu de informes
									if(menu_reportShow(arrayPlayers, lenPlayers, arrayConfederations, lenConfederations)==0)
									{
										// si el retorno es 0 se vuelve de reportes, al menu principal, satisfactoriamente
										printf("\nProceso terminado, volviendo al menu principal!\n\n");
									}
									else
									{
										printf("\nNo fue posible realizar el informe(s)!\n\n");
									}
								}
								else
								{
									printf("\nNo existen jugadores ingresados, no se pueden realizar informes!\n\n");
								}
							}
							else
							{
								printf("\nNo existen confederaciones ingresadas, no se pueden realizar informes!\n\n");
							}
						break;
					}
			}
	}
	return ret;
}

int menu_playerLoad(sPlayer arrayPlayers[], int lenPlayers, sConfederation arrayConfederations[], int lenConfederations)
{
	int ret=-1;
	int auxConfederationId;

	if(arrayPlayers!=NULL && lenPlayers>0)
	{
			sConfederation_printConfederations(arrayConfederations, lenConfederations);
			if(utn_getInt(&auxConfederationId, "Por favor ingrese el id de la confederacion a la que pertenece el jugador: ", "Error al ingresar la confederacion\n", 10000, 10009, 2)==0) // solo hay 6 hardcodeadas pero hay espacio para agregar 4 mas si se quiere
			{

				if(sConfederation_findConfederationById(arrayConfederations, lenConfederations, auxConfederationId)>-1)
				{

					if(sPlayer_load(arrayPlayers, lenPlayers, auxConfederationId)==0)
					{
						// todo validadisimo
						ret=0;
					}
				}
				else
				{
					printf("\nError en el id de la confederacion!\n\n");
				}

			}
			else
			{
				printf("\nError en la confederacion!\n\n");
			}
	}
	return ret;
}

int menu_playerRemove(sPlayer arrayPlayers[], int lenPlayers, sConfederation arrayConfederations[], int lenConfederations)
{
	int ret=-1;
	int auxIdPlayer;
	int auxIdConfederation;
	char auxConfederationName[50];

	if(arrayPlayers!=NULL && lenPlayers>0 && arrayConfederations!=NULL && lenConfederations>0)
	{
			// aca mostramos los jugadores para que se elija el id (ordenados por id)
			prints_printPlayersWithConfederations(arrayPlayers, lenPlayers, arrayConfederations, lenConfederations);
			if(utn_getInt(&auxIdPlayer, "\nPor favor ingrese el id del jugador que quiere dar de baja: ", "Error al ingresar el id\n", 1, lenPlayers, 2)==0)
			{
				if(sPlayer_findPlayerById(arrayPlayers, lenPlayers, auxIdPlayer)>-1)
				{
					// con esto conseguimos el id de la confederacion, para luego conseguir el nombre
					auxIdConfederation = sPlayer_findPlayerConfederationId(arrayPlayers, lenPlayers, auxIdPlayer);

					// esto nos consigue el nombre de la confederacion
					prints_findConfederationNameById(arrayConfederations, lenConfederations, auxIdConfederation, auxConfederationName);

					// el id existe y no fue dado de baja previamente
					if(sPlayer_removePlayer(arrayPlayers, lenPlayers, auxIdPlayer, auxConfederationName)==0)
					{
						// todo validadisimo
						ret=0;
					}
				}
				else
				{
					printf("\nError en el id!\n\n");
				}
			}
			else
			{
				printf("\nError en el id!\n\n");
			}
	}

	return ret;
}

int menu_playerModify(sPlayer arrayPlayers[], int lenPlayers, sConfederation arrayConfederations[], int lenConfederations)
{

	int ret=-1;
	int auxIdPlayer;
	int auxIdConfederation;
	int auxIdConfederationSelectedToModify;
	char auxConfederationName[50];
	int auxResponse;


	if(arrayPlayers!=NULL && lenPlayers>0 && arrayConfederations!=NULL && lenConfederations>0)
	{
		// aca mostramos los jugadores para que se elija el id (ordenados por id)
		prints_printPlayersWithConfederationsOrderedById(arrayPlayers, lenPlayers, arrayConfederations, lenConfederations);
		if(utn_getInt(&auxIdPlayer, "\nPor favor ingrese el id del jugador que quiere modificar: ", "Error al ingresar el id\n", 1, 9999, 2)==0) // ponemos 9999 suponiendo que dan de baja muchas veces y cargan nuevos jugadores
		{
			if(sPlayer_findPlayerById(arrayPlayers, lenPlayers, auxIdPlayer)>-1)
			{

				// con esto conseguimos el id de la confederacion, para luego conseguir el nombre
				auxIdConfederation = sPlayer_findPlayerConfederationId(arrayPlayers, lenPlayers, auxIdPlayer);

				// esto nos consigue el nombre de la confederacion
				prints_findConfederationNameById(arrayConfederations, lenConfederations, auxIdConfederation, auxConfederationName);

				// el id no fue dado de baja entonces, mostramos
				printf("\nSe eligio: \n\n");
				auxIdPlayer = sPlayer_findPlayerById(arrayPlayers, lenPlayers, auxIdPlayer); // buscamos la posicion del id seleccionado para poder imprimirlo en pantalla, y luego llevarlo a la funcion de mod
				sPlayer_printPlayer(arrayPlayers[auxIdPlayer],auxConfederationName);
				if(utn_getInt(&auxResponse, "\nQue desea modificar\n"
																	"1- Nombre\n"
																	"2- Posicion\n"
																	"3- Numero de camiseta\n"
																	"4- Confederacion\n"
																	"5- Sueldo\n"
																	"6- Anios de contrato\n -> ", "\nPor favor elija una opcion correcta", 1, 6, 2)==0)
				{
					 if(auxResponse==4)
					{
						// modifica la confederacion
						sConfederation_printConfederations(arrayConfederations, lenConfederations);
						if(utn_getInt(&auxIdConfederationSelectedToModify, "Por favor ingrese la nueva confederacion (1-AFC 2-CAF 3-CONCACAF 4-CONMEBOL 5-OFC 6-UEFA): ", "Error al ingresar la confederacion\n", 1, 6, 2)==0)
						{
							// conseguimos el nuevo id de la confederacion seleccionada
							auxIdConfederationSelectedToModify=sConfederation_findIdByPos(arrayConfederations, lenConfederations, auxIdConfederationSelectedToModify);

							// le pasamos el auxIdPlayer, porque antes lo "convertimos" a una posicion, y nos sirve para esta funcion
							if(sPlayer_ModifyPlayerConfederation(arrayPlayers, lenPlayers, auxIdPlayer, auxConfederationName, auxIdConfederationSelectedToModify)==0)
							{
								// todo validadisimo
								ret=0;
							}
						}
					}
					else
					{  // modifica cualquier campo
						if(sPlayer_ModifyPlayer(arrayPlayers, lenPlayers, auxIdPlayer, auxConfederationName,auxResponse)==0)
						{
							// todo validadisimo
							ret=0;
						}
					}
				}
				else
				{
					printf("\nError en opcion, no se modificara!\n\n");
				}
			}
			else
			{
				printf("\nError en el id, no existe o se dio de baja!\n\n");
			}
		}
		else
		{
			printf("\nError en el id!\n\n");
		}
	}

	return ret;
}

int menu_reportShow(sPlayer arrayPlayers[], int lenPlayers, sConfederation arrayConfederations[], int lenConfederations)
{
	int ret=-1;
	int auxResponse;

	if(arrayPlayers!=NULL && lenPlayers>0 && arrayConfederations!=NULL && lenConfederations>0)
	{
		if(utn_getInt(&auxResponse,"1- Listado de los jugadores ordenados alfabeticamente por nombre de confederacion y nombre de jugador\n\n"
															"2- Listado de confederaciones con sus jugadores\n\n"
															"3- Total y promedio de todos los salarios y cuantos jugadores cobraen mas del salario promedio\n\n"
															"4- Informar la confederacion con mayor cantidad de anios de contratos total\n\n"
															"5- Informar el porcentaje de jugadores por cada confederacion\n\n"
															"6- Informar cual es la region con mas jugadores y el listado de los mismos\n\n -> ", "Error al ingresar opcion!\n\n",1,6, 2)==0)
		{
			if(auxResponse>0 && auxResponse<7)
			{
				switch(auxResponse)
				{
				case 1:
					printf("\n Jugadores ordenados por confederacion y nombre\n");
					printf("------------------------------------------------\n");
					if(report_byConfederationNameAndPlayerName(arrayPlayers, lenPlayers, arrayConfederations, lenConfederations)==0)
					{
						// si el ordenamiento se dio correctamente, printeamos la lista ya ordenada, esta funcion simplemente printea la lista
						ret=0;
						prints_printPlayersWithConfederations(arrayPlayers, lenPlayers, arrayConfederations, lenConfederations);
					}
					else
					{
						printf("\nNo fue posible ordenar el listado!\n\n");
					}
					break;
				case 2:
					if(report_byConfederation(arrayPlayers, lenPlayers, arrayConfederations, lenConfederations)==0)
					{
						ret=0;
					}
					break;
				case 3:
					//report_playersCount(arrayPlayers, lenPlayers);
					if(report_playersAverageSalaryCalculation(arrayPlayers, lenPlayers)==0)
					{
						ret=0;
					}
					break;
				case 4:
					if(report_confederationMostYears(arrayPlayers, lenPlayers, arrayConfederations, lenConfederations)==0)
					{
						ret=0;
					}
					break;
				}
			}
		}
	}

	return ret;
}
