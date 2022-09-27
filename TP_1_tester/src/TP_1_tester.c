/*
 ============================================================================
 Name        : TP_1_tester.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn_input.h"
#include "calculations.h"

int main(void) {
	setbuf(stdout, NULL);
	// declaracion variables
	int response;
	char auxPosition[4];
	float accommodationCost;
	float auxAccommodationCost;
	float foodCost;
	float auxFoodCost;
	float transportationCost;
	float auxTransportationCost;
	int cantidadArqueros;
	int cantidadDefensores;
	int cantidadMediocampistas;
	int cantidadDelanteros;
	char auxConfederation[12];
	int cantidadAfc;
	int cantidadCaf;
	int cantidadConcacaf;
	int cantidadConmebol;
	int cantidadUefa;
	int cantidadOfc;
	int totalJugadores;
	float porcentajeUefa;
	float porcentajeConmebol;
	float porcentajeConcacaf;
	float porcentajeAfc;
	float porcentajeOfc;
	float porcentajeCaf;
	float mainTenanceCost;
	float increase;
	float mainTenanceCostIncrease;

	// inicializacion de variables
	accommodationCost=0;
	foodCost=0;
	transportationCost=0;
	cantidadArqueros=0;
	cantidadDefensores=0;
	cantidadMediocampistas=0;
	cantidadDelanteros=0;
	cantidadAfc=0;
	cantidadCaf=0;
	cantidadConcacaf=0;
	cantidadConmebol=0;
	cantidadUefa=0;
	cantidadOfc=0;
	totalJugadores=0;
	increase=0;
	mainTenanceCostIncrease=0;

	do
	{
			printf("\t\tMenu Principal\n\n");
			printf("\t\tcantidad AFC: %d\n"
						"\t\tcantidad CAF: %d\n"
						"\t\tcantidad CONCACAF: %d\n"
						"\t\tcantidad CONMEBOL: %d\n"
						"\t\tcantidad UEFA: %d\n"
						"\t\tcantidad OFC: %d\n", cantidadAfc,cantidadCaf,cantidadConcacaf,cantidadConmebol,cantidadUefa,cantidadOfc);
			printf("1.Ingreso de los costos de Mantenimiento\n"
						" Costo de Hospedaje -> $%.2f\n"
						" Costo de Comida -> $%.2f\n"
						" Costo de Transporte -> $%.2f\n"
						"2.Carga de jugadores\n"
						" Arqueros -> %d\n"
						" Defensores -> %d\n"
						" Mediocampistas -> %d\n"
						" Delanteros -> %d\n"
						"3.Realizar todos los calculos\n"
						"4.Informar todos los resultados\n"
						"5.Salir\n ",accommodationCost,foodCost,transportationCost,cantidadArqueros,cantidadDefensores,cantidadMediocampistas,cantidadDelanteros);
		if(utn_getInt(&response, "-> ", "Error al ingresar opcion\n", 1, 5, 2)==0)
			{
				// respuesta ingresada
					switch(response)
						{
						case 1:
							if(utn_getInt(&response, "Que costo desea ingresar?\n"
																		"1.Costo de Hospedaje \n"
																		"2.Costo de Comida \n"
																		"3.Costo de Transporte\n", "Error al ingresar opcion\n", 1, 3, 2)==0)
							{
								switch(response)
								{
								case 1:
									utn_getFloat(&auxAccommodationCost, "Por favor ingrese el costo de hospedaje: $ ", "Error al ingresar el costo de hospedaje\n", 50, 2000000000, 2);
									accommodationCost=accommodationCost+auxAccommodationCost;
									printf("Costo de hospedaje cargado correctamente\n");
									break;
								case 2:
									utn_getFloat(&auxFoodCost, "Por favor ingrese el costo de la comida: $ ", "Error al ingresar el costo de la comida\n", 50, 2000000000, 2);
									foodCost=foodCost+auxFoodCost;
									printf("Costo de comida cargado correctamente\n");
									break;
								case 3:
									utn_getFloat(&auxTransportationCost, "Por favor ingrese el costo de transporte: $ ", "Error al ingresar el costo de transporte\n", 50, 2000000000, 2);
									transportationCost=transportationCost+auxTransportationCost;
									printf("Costo de transporte cargado correctamente\n");
									break;
								}
							}
							break;
						case 2:
							if(utn_getPosition(auxPosition,4,"Que posicion desea ingresar?\n"
																						"Arquero - (arq)\n"
																						"Defensores - (def)\n"
																						"Mediocampistas - (med)\n"
																						"Delanteros - (del) \n->", "Error al ingresar opcion\n", 2)==0)
							{
								if(strncmp(auxPosition,"DEL",4)==0)
								{
									if(cantidadDelanteros==4)
									{
										printf("Disculpe, no pueden ingresarse mas delanteros!\n");
										break;
									}
									else
									{
										cantidadDelanteros++;
									}
								}
								else
								{
									if(strncmp(auxPosition,"MED",4)==0)
									{
										if(cantidadMediocampistas==8)
										{
											printf("Disculpe, no pueden ingresarse mas mediocampistas!\n");
											break;
										}
										else
										{
											cantidadMediocampistas++;
										}
									}
									else
									{
										if(strncmp(auxPosition,"DEF",4)==0)
										{
											if(cantidadDefensores==8)
											{
												printf("Disculpe, no pueden ingresarse mas defensores!\n");
												break;
											}
											else
											{
												cantidadDefensores++;
											}
										}
										else
										{
											if(strncmp(auxPosition,"ARQ",4)==0)
											{
												if(cantidadArqueros==2)
												{
													printf("Disculpe, no pueden ingresarse mas arqueros!\n");
													break;
												}
												else
												{
													cantidadArqueros++;
												}
											}
										}
									}
								}
								if(utn_getInt(&response, "Ingrese el numero de camiseta del jugador: ","Error al ingresar el numero de camiseta\n", 1, 99, 2)==0)
								{
									if(utn_getConfederation(auxConfederation, 12, "Ingrese la confederacion en la que juega (AFC - CAF - CONCACAF - CONMEBOL - UEFA - OFC): ", "Error al ingresar la confederacion\n", 2)==0)
									{
										if(strncmp(auxConfederation,"AFC",12)==0)
										{
											cantidadAfc++;
										}
										else
										{
											if(strncmp(auxConfederation,"CAF",12)==0)
												{
													cantidadCaf++;
												}
											else
											{
												if(strncmp(auxConfederation,"CONCACAF",12)==0)
												{
													cantidadConcacaf++;
												}
												else
												{
													if(strncmp(auxConfederation,"CONMEBOL",12)==0)
													{
														cantidadConmebol++;
													}
													else
													{
														if(strncmp(auxConfederation,"UEFA",12)==0)
														{
															cantidadUefa++;
														}
														else
														{
															if(strncmp(auxConfederation,"OFC",12)==0)
															{
																cantidadOfc++;
															}
														}
													}
												}
											}
										}
										printf("Jugador cargado correctamente\n");
									}
									if(response==5)
									{
										// si pasa esto, nos atajamos de que no se cierre el programa
										response=0;
									}
								}
							}
							break;
						case 3:
							if((accommodationCost==0 || foodCost==0 || transportationCost==0) || (cantidadArqueros==0 && cantidadDefensores==0 && cantidadMediocampistas==0 && cantidadDelanteros==0))
							{
								printf("Por favor, debe cargar los gastos de mantenimiento y jugadores para realizar los calculos\n");
							}
							else
							{
								// los datos estaban cargados correctamente

								//a. promedio de jugadores de cada mercado
								totalJugadores = calculations_totalPlayers(cantidadAfc, cantidadCaf, cantidadConcacaf, cantidadConmebol,cantidadUefa, cantidadOfc);
								porcentajeUefa = calculations_averagePlayer(cantidadUefa, totalJugadores);
								porcentajeConmebol = calculations_averagePlayer(cantidadConmebol, totalJugadores);
								porcentajeConcacaf = calculations_averagePlayer(cantidadConcacaf, totalJugadores);
								porcentajeAfc = calculations_averagePlayer(cantidadAfc, totalJugadores);
								porcentajeOfc = calculations_averagePlayer(cantidadOfc, totalJugadores);
								porcentajeCaf = calculations_averagePlayer(cantidadCaf, totalJugadores);

								//b. costo de mantenimiento
								mainTenanceCost = calculations_maintenanceCost(accommodationCost, foodCost, transportationCost);

								//c.si la mayoria es de la uefa, mantenimiento +35%
								if(calculations_mostUefa(cantidadAfc, cantidadCaf, cantidadConcacaf, cantidadConmebol, cantidadUefa, cantidadOfc)==0)
								{
								mainTenanceCostIncrease	= calculations_mainTenanceCostIncrease(mainTenanceCost, &increase);
								}
								printf("Calculos realizados correctamente!\n");
							}
							break;
						case 4:
							if((accommodationCost==0 || foodCost==0 || transportationCost==0) || (cantidadArqueros==0 && cantidadDefensores==0 && cantidadMediocampistas==0 && cantidadDelanteros==0))
							{
								printf("Por favor, debe cargar los gastos de mantenimiento y jugadores para realizar los calculos, y luego poder imprimirlos\n");
							}
							else
							{
								// si no ingreso el 3, es decir, no realizo los calculos, tampoco va a entrar
								if(totalJugadores==0)
								{
									printf("Por favor, debe realizar los calculos para poder imprimirlos\n");
								}
								else
								{
									printf("jugadores total: %d\n"
												"porcentaje Uefa %.2f\n"
												"porcentaje Conmebol %.2f\n"
												"porcentaje Concacaf %.2f\n"
												"porcentaje Afc %.2f\n"
												"porcentaje Ofc %.2f\n"
												"porcentaje Caf %.2f\n"
												"el costo de mantenimiento era de $%.0f y recibio un aumento de $%.0f, su nuevo valor es de: $%.0f\n",totalJugadores, porcentajeUefa,porcentajeConmebol,porcentajeConcacaf,porcentajeAfc,porcentajeOfc,porcentajeCaf,mainTenanceCost, increase, mainTenanceCostIncrease);
								}
							}

							break;
						}
			}
	}while(response!=5);

	printf("\t\tAdios\n\n");

	return EXIT_SUCCESS;
}


