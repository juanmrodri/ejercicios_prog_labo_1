/*
 * prints.c
 *
 *  Created on: 23 oct 2022
 *      Author: juanm
 */

#include "prints.h"

#define EMPTY 1
#define OCCUPIED 0



void prints_findConfederationNameById(sConfederation arrayConfederations[], int lenConfederations, int auxId, char auxName[])
{
	char auxConfederationName[50];
	if(arrayConfederations!=NULL && lenConfederations>0 && auxId>99)
	{
		for(int i=0;i<lenConfederations;i++)
		{
			if(arrayConfederations[i].id==auxId && arrayConfederations[i].isEmpty==OCCUPIED)
			{
				strncpy(auxName,arrayConfederations[i].name,sizeof(auxConfederationName));
			}
		}
	}
}

void prints_printPlayerWithConfederation(sPlayer player, char auxConfederationName[])
{
	printf("|   %-8d|    %-20s |   %-17s |          %-13hd |  %-13.2f |      %-12s |          %-12hd |\n", player.id,player.name,player.position,player.shirtNumber,player.salary,auxConfederationName,player.contractYears);
}

void prints_printPlayersWithConfederations(sPlayer arrayPlayers[], int lenPlayers, sConfederation arrayConfederations[], int lenConfederations)
{
	int auxIdConfederation;
	char auxConfederationName[50];
	if(arrayPlayers!=NULL && lenPlayers>0)
	{
		printf("===================================================================================================================================================\n");
		printf("|   ID      |    NOMBRE               |     POSICION        |      N DE CAMISETA     |   SUELDO       |   CONFEDERACION   |   ANIOS DE CONTRATO   |\n");
		printf("---------------------------------------------------------------------------------------------------------------------------------------------------\n");
		for(int i=0;i<lenPlayers;i++)
		{
			if(arrayPlayers[i].isEmpty==OCCUPIED)
			{
				auxIdConfederation=arrayPlayers[i].confederationId;

				prints_findConfederationNameById(arrayConfederations, lenConfederations, auxIdConfederation, auxConfederationName);

				prints_printPlayerWithConfederation(arrayPlayers[i],auxConfederationName);
			}
		}
		printf("===================================================================================================================================================\n");
		printf("\n\n");
	}
}

void prints_printPlayersWithConfederationsOrderedById(sPlayer arrayPlayers[], int lenPlayers, sConfederation arrayConfederations[], int lenConfederations)
{
	int auxIdConfederation;
	char auxConfederationName[50];
	if(arrayPlayers!=NULL && lenPlayers>0)
	{
		printf("===================================================================================================================================================\n");
		printf("|   ID      |    NOMBRE               |     POSICION        |      N DE CAMISETA     |   SUELDO       |   CONFEDERACION   |   ANIOS DE CONTRATO   |\n");
		printf("---------------------------------------------------------------------------------------------------------------------------------------------------\n");
		for(int i=0;i<lenPlayers;i++)
		{
			if(arrayPlayers[i].isEmpty==OCCUPIED)
			{
				auxIdConfederation=arrayPlayers[i].confederationId;

				prints_findConfederationNameById(arrayConfederations, lenConfederations, auxIdConfederation, auxConfederationName);

				prints_orderArrayById(arrayPlayers, lenPlayers);

				prints_printPlayerWithConfederation(arrayPlayers[i],auxConfederationName);
			}
		}
		printf("===================================================================================================================================================\n");
		printf("\n\n");
	}
}

void prints_orderArrayById(sPlayer arrayPlayers[], int lenPlayers)
{
	int flagSwap;
	int i;
	sPlayer bufferPos;
	int newLen;
	newLen=lenPlayers-1;
	do{
		flagSwap = 0;
		for(i = 0; i < newLen; i++)
		{
			if(arrayPlayers[i].id>arrayPlayers[i+1].id)
			{
				flagSwap = 1;
				bufferPos =arrayPlayers[i];
				arrayPlayers[i] =arrayPlayers[i+1];
				arrayPlayers[i+1] = bufferPos;
			}
		}
		newLen--;

	}while(flagSwap);
}
