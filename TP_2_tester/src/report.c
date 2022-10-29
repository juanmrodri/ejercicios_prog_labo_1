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
					if(report_countPlayerConfederationAmount(arrayPlayers, lenPlayers, arrayConfederations, lenConfederations, auxConfederationId, &auxConfederationAmount)==0)
					{
						if(auxConfederationAmount>0)
							{
								printf("=======================================\n");
								printf("|  CONFEDERACION        |  %-10s |\n",arrayConfederations[i].name);
								printf("---------------------------------------\n");
								report_printPlayersFilteredByIdConfederation(arrayPlayers, lenPlayers, arrayConfederations, lenConfederations,auxConfederationId);
							}
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

int report_countPlayerConfederationAmount(sPlayer arrayPlayers[], int lenPlayers, sConfederation arrayConfederations[], int lenConfederations, int idConfederation, int* confederationAmount)
{
	int ret=-1;
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
			ret=0;
			*confederationAmount=auxConfederationAmount;
		}
	}
	return ret;
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
			if(arrayPlayers[i].salary>averageSalary && arrayPlayers[i].isEmpty==OCCUPIED)
			{
				playersCount++;
			}
		}
	}

	return playersCount;
}

void report_printPlayersAverageSalaryCalculation(float totalSalary, float averageSalary, int playersOverAverageCount)
{
		printf("\n============================================================================\n");
		printf("|  TOTAL DE SUELDOS   			          |  %20.2f  |\n",totalSalary);
		printf("|  SUELDO PROMEDIO   			          |  %20.2f  |\n",averageSalary);
		if(playersOverAverageCount>0)
		{
			printf("|  CANTIDAD DE JUGADORES QUE SUPERAN EL PROMEDIO  |%22i  |\n",playersOverAverageCount);
		}
		printf("----------------------------------------------------------------------------\n");
}

// informe 4

int report_confederationMostYears(sPlayer arrayPlayers[], int lenPlayers, sConfederation arrayConfederations[], int lenConfederations)
{
	int ret=-1;
	int auxConfederationId;
	int auxAmountYears=0;
	int auxAmountYearsActualRound=0;
	int flagFirstAmount=0;
	int minAmountYears=0;
	int maxAmountYears=0;
	char auxMostYearsContractConfederationName[50];
	int arrayAuxAmountYearsActualRound[lenConfederations];
	int auxEqualMaxAmount=0;

	if(arrayPlayers!=NULL && lenPlayers>0 && arrayConfederations!=NULL && lenConfederations>0)
	{
		for(int i=0;i<lenConfederations;i++)
		{
			//printf("\n%s\n",arrayConfederations[i].name);
			for(int j=0;j<lenPlayers;j++)
			{
				auxConfederationId = arrayConfederations[i].id;
					if(arrayPlayers[j].confederationId==arrayConfederations[i].id && arrayPlayers[j].isEmpty==OCCUPIED && (report_confederationHasYears(arrayPlayers, lenPlayers, auxConfederationId)==0))
						{
							auxAmountYears=auxAmountYears+arrayPlayers[j].contractYears;
							//printf("\n%hd - anios sumados %d\n",arrayPlayers[j].contractYears, auxAmountYears);
							auxAmountYearsActualRound=auxAmountYears;
						}
			}
			//printf("\nanios sumados una vez terminada la vuelta %d\n",auxAmountYearsActualRound);
			arrayAuxAmountYearsActualRound[i]=auxAmountYearsActualRound;

			if(flagFirstAmount==0)
			{
				flagFirstAmount=1;
				minAmountYears=auxAmountYearsActualRound;
				maxAmountYears=auxAmountYearsActualRound;
				//printf("\nminimo %d\nmaximo %d\n",minAmountYears,maxAmountYears);
			}
			else
			{
				if(auxAmountYearsActualRound<minAmountYears)
				{
					minAmountYears=auxAmountYearsActualRound;
				}
				else
				{
					if(auxAmountYearsActualRound>maxAmountYears)
					{
						maxAmountYears=auxAmountYearsActualRound;
						strncpy(auxMostYearsContractConfederationName,arrayConfederations[i].name,sizeof(auxMostYearsContractConfederationName));
						//printf("\nLa confederacion con mas anios de contratacion es: %s\n",auxMostYearsContractConfederationName);

					}
				}
			}
			auxAmountYears=0;
		}
		//printf("\nLa confederacion con mas anios de contratacion es: %s: %d\n",auxMostYearsContractConfederationName, maxAmountYears);

		for(int i=0;i<lenConfederations;i++)
		{
			if(arrayAuxAmountYearsActualRound[i]==maxAmountYears)
			{
				auxEqualMaxAmount++;
			}
			//printf("\nEqual amount %d\n", auxEqualMaxAmount);
			//printf("\nPos %d = %d\n", i, arrayAuxAmountYearsActualRound[i]);

		}

		if(auxEqualMaxAmount==1)
		{
			ret=0;
			printf("\n==========================================================================================\n");
			printf("|  CONFEDERACION CON MAYOR CANTIDAD DE ANIOS DE CONTRATOS TOTAL |  %6s    |  %6d   |\n",auxMostYearsContractConfederationName,maxAmountYears);
			printf("------------------------------------------------------------------------------------------\n");
		}
		else
		{
			ret=0;
			printf("\nPor el momento no existe una unica confederacion con mas anios de contrataciones\n");
		}

	}

	return ret;
}

int report_confederationHasYears(sPlayer arrayPlayers[], int lenPlayers, int confederationId)
{
	int ret=-1;
	if(arrayPlayers!=NULL && lenPlayers>0)
	{
		for(int i=0;i<lenPlayers;i++)
		{
			if(arrayPlayers[i].confederationId==confederationId)
			{
				// el id coincide, fue seleccionado, y por ende, tiene anios
				ret=0;
				break;
			}
		}
	}

	return ret;

}

// informe 5

int report_playersPercentagePerConfederationCalculations(sPlayer arrayPlayers[], int lenPlayers, sConfederation arrayConfederations[], int lenConfederations)
{
	int ret=-1;
	int auxIdConfederation;
	int auxConfederationAmount;
	float auxPercentage;
	char auxConfederationName[50];

	if(arrayPlayers!=NULL && lenPlayers>0 && arrayConfederations!=NULL && lenConfederations>0)
	{
		for(int i=0;i<lenConfederations;i++)
		{
			if(arrayConfederations[i].isEmpty==OCCUPIED)
			{
				auxIdConfederation=arrayConfederations[i].id;
				if(report_countPlayerConfederationAmount(arrayPlayers, lenPlayers, arrayConfederations, lenConfederations, auxIdConfederation, &auxConfederationAmount)==0)
				{
					ret=0;

					auxPercentage = report_playersPercentagePerConfederation(arrayPlayers, lenPlayers, auxConfederationAmount);

					prints_findConfederationNameById(arrayConfederations, lenConfederations, auxIdConfederation, auxConfederationName);

					report_printPlayersPercentagePerConfederationCalculations(auxConfederationName, auxPercentage);
				}
			}
		}

	}

	return ret;
}

float report_playersPercentagePerConfederation(sPlayer arrayPlayers[], int lenPlayers, int auxConfederationAmount)
{
	int auxPlayersTotalAmount=0;
	float auxPercentage=0;

	if(arrayPlayers!=NULL && lenPlayers>0 && auxConfederationAmount>0)
	{
		auxPlayersTotalAmount = report_playersCount(arrayPlayers, lenPlayers);
		auxPercentage =(float)auxPlayersTotalAmount* auxConfederationAmount/100;
	}
	return auxPercentage;
}

void report_printPlayersPercentagePerConfederationCalculations(char auxConfederationName[], float auxPercentage)
{
		if(auxPercentage>0)
			{
				printf("\n================================\n");

				printf("|  %-8s   |  %-10.2f    |\n",auxConfederationName, auxPercentage);

				printf("--------------------------------\n");
			}
}

// informe 6

int report_RegionMostYears(sPlayer arrayPlayers[], int lenPlayers, sConfederation arrayConfederations[], int lenConfederations)
{
	int ret=-1;
	int auxIdConfederation;
	int auxConfederationAmount;
	char auxConfederationName[50];
	int auxConfederationAmountActualRound=0;
	int flagFirstAmount=0;
	int minAmount=0;
	int maxAmount=0;
	int arrayAuxConfederationAmountActualRound[lenConfederations];
	int auxEqualMaxAmount=0;
	char auxConfederationRegion[50];

	if(arrayPlayers!=NULL && lenPlayers>0 && arrayConfederations!=NULL && lenConfederations>0)
	{
		for(int i=0;i<lenConfederations;i++)
		{
			if(arrayConfederations[i].isEmpty==OCCUPIED)
			{
				auxIdConfederation=arrayConfederations[i].id;
				if(report_countPlayerConfederationAmount(arrayPlayers, lenPlayers, arrayConfederations, lenConfederations, auxIdConfederation, &auxConfederationAmount)==0)
				{

						if(auxConfederationAmount>0)
						{
							prints_findConfederationNameById(arrayConfederations, lenConfederations, auxIdConfederation, auxConfederationName);
						}
						auxConfederationAmountActualRound=auxConfederationAmount;
				}

				arrayAuxConfederationAmountActualRound[i]=auxConfederationAmountActualRound;

				if(flagFirstAmount==0)
				{
					minAmount=auxConfederationAmountActualRound;
					maxAmount=auxConfederationAmountActualRound;
				}
				else
				{
					if(auxConfederationAmountActualRound<minAmount)
					{
						minAmount=auxConfederationAmountActualRound;
					}
					else
					{
						if(auxConfederationAmountActualRound>maxAmount)
						{
							maxAmount=auxConfederationAmountActualRound;
							auxIdConfederation=arrayConfederations[i].id;
						}
					}
				}
			}
		}
		for(int i=0;i<lenConfederations;i++)
		{
			if(arrayAuxConfederationAmountActualRound[i]==maxAmount)
			{
				auxEqualMaxAmount++;
			}
		}

		// buscamos la region por id
		report_findConfederationRegionById(arrayConfederations, lenConfederations, auxIdConfederation, auxConfederationRegion);

		if(auxEqualMaxAmount==1)
		{
			ret=0;
			printf("\n============================================================\n");
			printf("|  LA REGION CON MAS JUGADORES ES  |  %8s    |  %3d   |\n",auxConfederationRegion,maxAmount);
			printf("------------------------------------------------------------\n");
			report_printPlayersFilteredByIdConfederation(arrayPlayers, lenPlayers, arrayConfederations, lenConfederations, auxIdConfederation);
		}
		else
		{
			ret=0;
			printf("\nPor el momento no existe una unica region con mas jugadores\n");
		}
	}

	return ret;
}

void report_findConfederationRegionById(sConfederation arrayConfederations[], int lenConfederations, int auxId, char auxName[])
{
	char auxConfederationRegion[50];
	if(arrayConfederations!=NULL && lenConfederations>0 && auxId>99)
	{
		for(int i=0;i<lenConfederations;i++)
		{
			if(arrayConfederations[i].id==auxId && arrayConfederations[i].isEmpty==OCCUPIED)
			{
				strncpy(auxName,arrayConfederations[i].region,sizeof(auxConfederationRegion));
			}
		}
	}
}

