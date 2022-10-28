/*
 * report.c
 *
 *  Created on: 25 oct 2022
 *      Author: juanm
 */

#include "report.h"

#define EMPTY 1
#define OCCUPIED 0

// informe 1

int report_byConfederationNameAndPlayerName(sPlayer arrayPlayers[], int lenPlayers, sConfederation arrayConfederations[], int lenConfederations)
{
	int ret=-1;
	int auxIdConfederation;
	int auxIdConfederationNextPos;
	char auxConfederationName[50];
	char auxConfederationNameNextPos[50];
	int flagSwap;
	sPlayer bufferPos;
	int newLen;

	newLen=lenPlayers-1;

	if(arrayPlayers!=NULL && lenPlayers>0 && arrayConfederations!=NULL && lenConfederations>0)
	{
		do{
				flagSwap = 0;
				for(int i= 0; i < newLen; i++)
				{
					auxIdConfederation=arrayPlayers[i].confederationId;

					auxIdConfederationNextPos=arrayPlayers[i+1].confederationId;

					prints_findConfederationNameById(arrayConfederations, lenConfederations, auxIdConfederation, auxConfederationName); // obtenemos el nombre de la pos actual

					prints_findConfederationNameById(arrayConfederations, lenConfederations, auxIdConfederationNextPos, auxConfederationNameNextPos); // obtenemos el nombre de la pos contigua

					// ahora podemos comparar esas 2 cadenas y determinar si hacer o no el swapeo

					if(strcmp(auxConfederationName,auxConfederationNameNextPos)>0)
						{
							ret=0;
							flagSwap = 1;
							bufferPos =arrayPlayers[i];
							arrayPlayers[i] =arrayPlayers[i+1];
							arrayPlayers[i+1] = bufferPos;
						}
					else
					{
						if(strcmp(auxConfederationName,auxConfederationNameNextPos)==0) // si son iguales
						{
							for(int j=0;j<lenConfederations;j++) // iteramos pero por confedereacion
							{
								if(strcmp(arrayPlayers[i].name,arrayPlayers[i+1].name)>0) // y el critero es el nombre
								{
									ret=0;
									flagSwap = 1;
									bufferPos =arrayPlayers[i];
									arrayPlayers[i] =arrayPlayers[i+1];
									arrayPlayers[i+1] = bufferPos;
								}
							}
						}
					}
				}
				newLen--;
			}while(flagSwap);
	}

	return ret;
}

// informe 2

int report_byConfederation(sPlayer arrayPlayers[], int lenPlayers, sConfederation arrayConfederations[], int lenConfederations)
{
	int ret=-1;
	if(arrayPlayers!=NULL && lenPlayers>0 && arrayConfederations!=NULL && lenConfederations>0)
	{
		ret=0;
		report_playersPerConfederation(arrayConfederations, lenConfederations, arrayPlayers, lenPlayers);
	}

	return ret;
}

void report_playersPerConfederation(sConfederation arrayConfederations[], int lenConfederations,sPlayer arrayPlayers[], int lenPlayers)
{
	int auxConfederationId;
	int auxConfederationAmount;
	if(arrayConfederations!=NULL && lenConfederations>0)
		{
			// printeando asi, queda a la misma altura
			for(int i=0;i<lenConfederations;i++)
			{
				if(arrayConfederations[i].isEmpty==OCCUPIED)
				{
					auxConfederationId = arrayConfederations[i].id;
					report_countPlayerConfederationAmount(arrayPlayers, lenPlayers, arrayConfederations, lenConfederations, auxConfederationId, &auxConfederationAmount);
					if(auxConfederationAmount>0)
					{
						printf("=======================================\n");
						printf("|  CONFEDERACION        |  %-10s |\n",arrayConfederations[i].name);
						printf("---------------------------------------\n");
						report_printPlayersFilteredByIdConfederation(arrayPlayers, lenPlayers, arrayConfederations, lenConfederations,auxConfederationId);
					}
				}
			}
			printf("\n\n");
		}
}

void report_printPlayersFilteredByIdConfederation(sPlayer arrayPlayers[], int lenPlayers, sConfederation arrayConfederations[], int lenConfederations, int idConfederation)
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
			if(arrayPlayers[i].isEmpty==OCCUPIED && arrayPlayers[i].confederationId==idConfederation)
			{
				auxIdConfederation=arrayPlayers[i].confederationId;
				prints_findConfederationNameById(arrayConfederations, lenConfederations, auxIdConfederation, auxConfederationName);
				printf("|   %-8d|    %-20s |   %-17s |          %-13hd |  %-13.2f |      %-12s |          %-12hd |\n", arrayPlayers[i].id,arrayPlayers[i].name,arrayPlayers[i].position,arrayPlayers[i].shirtNumber,arrayPlayers[i].salary,auxConfederationName,arrayPlayers[i].contractYears);

			}

		}
		printf("===================================================================================================================================================\n");
		printf("\n\n");
	}
}

void report_countPlayerConfederationAmount(sPlayer arrayPlayers[], int lenPlayers, sConfederation arrayConfederations[], int lenConfederations, int idConfederation, int* confederationAmount)
{
	int auxConfederationAmount=0;
	if(arrayPlayers!=NULL && lenPlayers>0)
	{
		if(sConfederation_findConfederationById(arrayConfederations, lenConfederations, idConfederation)>-1) // esto significa que el id existe
		{
			for(int i=0;i<lenPlayers;i++)
			{
				if(arrayPlayers[i].confederationId==idConfederation)
				{
					auxConfederationAmount++;
				}
			}
			*confederationAmount=auxConfederationAmount;
		}
	}
}

// informe 3

int report_playersAverageSalaryCalculation(sPlayer arrayPlayers[], int lenPlayers)
{
	int ret=-1;
	int auxPlayersCount;
	float auxSalaryAmount;
	float auxAverageSalary;
	int auxPlayersOverAverageCount;

	if(arrayPlayers!=NULL && lenPlayers>0)
	{

		auxPlayersCount = report_playersCount(arrayPlayers, lenPlayers); // conseguimos la cantidad de jugadores ingresados

		auxSalaryAmount = report_playersTotalSalaryCount(arrayPlayers, lenPlayers); // suma total de los sueldos

		// calculamos el salario promedio

		auxAverageSalary = report_AverageSalary(auxPlayersCount, auxSalaryAmount);

		// contamos cuantos jugadores superan el sueldo promedio

		auxPlayersOverAverageCount = report_amountPlayersSalaryMoreThanAverage(arrayPlayers, lenPlayers, auxAverageSalary);

		// llamamos al printeo
		ret=0;
		report_printPlayersAverageSalaryCalculation(auxSalaryAmount, auxAverageSalary, auxPlayersOverAverageCount);
	}

	return ret;
}

int report_playersCount(sPlayer arrayPlayers[], int lenPlayers)
{
	int auxPlayersCount=0;

	if(arrayPlayers!=NULL && lenPlayers>0)
	{
		for(int i=0;i<lenPlayers;i++)
		{
			if(arrayPlayers[i].isEmpty==OCCUPIED)
			{
				auxPlayersCount++;
			}
		}
	}

	return auxPlayersCount;
}

float report_playersTotalSalaryCount(sPlayer arrayPlayers[], int lenPlayers)
{
	float auxSalaryAmount=0;

	if(arrayPlayers!=NULL && lenPlayers>0)
	{
		for(int i=0;i<lenPlayers;i++)
		{
			if(arrayPlayers[i].isEmpty==OCCUPIED)
			{
				auxSalaryAmount=auxSalaryAmount+arrayPlayers[i].salary;
			}
		}
	}

	return auxSalaryAmount;
}

float report_AverageSalary(int totalPlayers, float totalSalary)
{
	float averageSalary;

	if(totalPlayers>0)
	{
		averageSalary = totalSalary / (float)totalPlayers;
	}

	return averageSalary;
}

int report_amountPlayersSalaryMoreThanAverage(sPlayer arrayPlayers[], int lenPlayers, float averageSalary)
{
	int playersCount=0;
	if(arrayPlayers!=NULL && lenPlayers>0)
	{
		for(int i=0;i<lenPlayers;i++)
		{
			if(arrayPlayers[i].salary>averageSalary)
			{
				playersCount++;
			}
		}
	}

	return playersCount;
}

void report_printPlayersAverageSalaryCalculation(float totalSalary, float averageSalary, int playersOverAverageCount)
{
		printf("============================================================================\n");
		printf("|  TOTAL DE SUELDOS   			          |  %20.2f  |\n",totalSalary);
		printf("|  SUELDO PROMEDIO   			          |  %20.2f  |\n",averageSalary);
		printf("|  CANTIDAD DE JUGADORES QUE SUPERAN EL PROMEDIO  |%22i  |\n",playersOverAverageCount);
		printf("----------------------------------------------------------------------------\n");
}

// informe 4

