/*
 ============================================================================
 Name        : TP_2_tester.c
 Author      : Rodriguez Juan Manuel
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "utn_input.h"
#include "sPlayer.h"
#include "sConfederation.h"
#include "prints.h"

#define PLAYERS_LEN 3000
#define CONFEDERATIONS_LEN 6

int main(void) {
	setbuf(stdout, NULL);

	int response;

	sPlayer arrayPlayers[PLAYERS_LEN];

	sConfederation arrayConfederations[CONFEDERATIONS_LEN];

	sPlayer_initArray(arrayPlayers, PLAYERS_LEN);

	sConfederation_initArray(arrayConfederations, CONFEDERATIONS_LEN);

	// alta forzada de confederaciones
	sConfederation_forceLoad(arrayConfederations, CONFEDERATIONS_LEN, "AFC", "ASIA", 1954);
	sConfederation_forceLoad(arrayConfederations, CONFEDERATIONS_LEN, "CAF", "AFRICA", 1957);
	sConfederation_forceLoad(arrayConfederations, CONFEDERATIONS_LEN, "CONCACAF", "NORTE Y CENTRO AMERICA", 1961);
	sConfederation_forceLoad(arrayConfederations, CONFEDERATIONS_LEN, "CONMEBOL", "SUDAMERICA", 1916);
	sConfederation_forceLoad(arrayConfederations, CONFEDERATIONS_LEN, "OFC", "OCEANIA", 1966);
	sConfederation_forceLoad(arrayConfederations, CONFEDERATIONS_LEN, "UEFA", "EUROPA", 1954);

	// alta forzada de jugadores (BORRAR!)
	sPlayer_forceLoad(arrayPlayers, PLAYERS_LEN, "Benzema", "Delantero", 9,350000000, 2, 105);
	sPlayer_forceLoad(arrayPlayers, PLAYERS_LEN, "Messi", "Delantero", 10, 2700000, 2, 105);
	sPlayer_forceLoad(arrayPlayers, PLAYERS_LEN, "Lewandowski", "Delantero", 9, 4500000, 4, 105);
	sPlayer_forceLoad(arrayPlayers, PLAYERS_LEN, "Bukayo Saka", "Mediocampista", 7, 35000000, 1, 105);
	sPlayer_forceLoad(arrayPlayers, PLAYERS_LEN, "Valverde", "Mediocampista",7, 25000000, 4, 105);
	sPlayer_forceLoad(arrayPlayers, PLAYERS_LEN, "Cavani", "Delantero", 7, 45000000, 3, 103);
	sPlayer_forceLoad(arrayPlayers, PLAYERS_LEN, "Bellingham", "Mediocampista", 22, 35000000, 3, 105);
	sPlayer_forceLoad(arrayPlayers, PLAYERS_LEN, "Brahim", "Mediocampista", 10, 350000000, 4, 105);
	sPlayer_forceLoad(arrayPlayers, PLAYERS_LEN, "Haaland", "Delantero", 9, 35000000, 3, 105);
	sPlayer_forceLoad(arrayPlayers, PLAYERS_LEN, "Casemiro", "Mediocampista",18, 35000000, 5, 105);
	sPlayer_forceLoad(arrayPlayers, PLAYERS_LEN, "Carlos Sanchez", "Defensor", 31, 35000000, 1, 102);
	sPlayer_forceLoad(arrayPlayers, PLAYERS_LEN, "Pedro Baez", "Delantero", 17, 2700000, 2, 102);
	sPlayer_forceLoad(arrayPlayers, PLAYERS_LEN, "Teanonui tehau", "Delantero", 10, 4500000, 2, 104);
	sPlayer_forceLoad(arrayPlayers, PLAYERS_LEN, "Clemente Rodriguez", "Defensor", 14, 3500000, 4, 104);
	sPlayer_forceLoad(arrayPlayers, PLAYERS_LEN, "Gonzalo Morales", "Delantero",28, 35000000, 3, 104);
	sPlayer_forceLoad(arrayPlayers, PLAYERS_LEN, "Famara Diedhieou", "Delantero", 14, 2700000, 2, 101);
	sPlayer_forceLoad(arrayPlayers, PLAYERS_LEN, "Sadio Mane", "Delantero", 17, 4500000, 4, 101);
	sPlayer_forceLoad(arrayPlayers, PLAYERS_LEN, "Mohanad Lasheen", "Mediocampista", 14, 3500000, 3, 101);
	sPlayer_forceLoad(arrayPlayers, PLAYERS_LEN, "Zizo", "Delantero",25, 3500000, 4, 101);
	sPlayer_forceLoad(arrayPlayers, PLAYERS_LEN, "Mohamed Abougabal", "Arquero",1, 3500000, 5, 101);
	//menu

		do
		{

			if(menu_show(&response)==0) // aca llamamos a todo el menu
			{
				menu_responseOptionCaller(response, arrayPlayers,PLAYERS_LEN,arrayConfederations,CONFEDERATIONS_LEN);
			}
			else
			{
				if(response!=5)
				{
					printf("\nIntente de nuevo por favor!\n\n");
				}
			}

		}while(response!=5);

	return EXIT_SUCCESS;
}
