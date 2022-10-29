/*
 * report.h
 *
 *  Created on: 25 oct 2022
 *      Author: juanm
 */

#ifndef REPORT_H_
#define REPORT_H_

#include "sPlayer.h"
#include "sConfederation.h"
#include "utn_input.h"
#include "prints.h"

// informe 1
int report_byConfederationNameAndPlayerName(sPlayer arrayPlayers[], int lenPlayers, sConfederation arrayConfederations[], int lenConfederations);

// informe 2
int report_byConfederation(sPlayer arrayPlayers[], int lenPlayers, sConfederation arrayConfederations[], int lenConfederations);

void report_playersPerConfederation(sConfederation arrayConfederations[], int lenConfederations,sPlayer arrayPlayers[], int lenPlayers);

void report_printPlayersFilteredByIdConfederation(sPlayer arrayPlayers[], int lenPlayers, sConfederation arrayConfederations[], int lenConfederations, int idConfederation);

int report_countPlayerConfederationAmount(sPlayer arrayPlayers[], int lenPlayers, sConfederation arrayConfederations[], int lenConfederations, int idConfederation, int* confederationAmount);

// informe 3
int report_playersAverageSalaryCalculation(sPlayer arrayPlayers[], int lenPlayers);

int report_playersCount(sPlayer arrayPlayers[], int lenPlayers);

float report_playersTotalSalaryCount(sPlayer arrayPlayers[], int lenPlayers);

float report_AverageSalary(int totalPlayers, float totalSalary);

int report_amountPlayersSalaryMoreThanAverage(sPlayer arrayPlayers[], int lenPlayers, float averageSalary);

void report_printPlayersAverageSalaryCalculation(float totalSalary, float averageSalary, int playersOverAverageCount);


// informe 4

int report_confederationMostYears(sPlayer arrayPlayers[], int lenPlayers, sConfederation arrayConfederations[], int lenConfederations);

int report_confederationHasYears(sPlayer arrayPlayers[], int lenPlayers, int confederationId);

// informe 5

int report_playersPercentagePerConfederationCalculations(sPlayer arrayPlayers[], int lenPlayers, sConfederation arrayConfederations[], int lenConfederations);

float report_playersPercentagePerConfederation(sPlayer arrayPlayers[], int lenPlayers, int auxConfederationAmount);

void report_printPlayersPercentagePerConfederationCalculations(char auxConfederationName[], float auxPercentage);

// informe 6

int report_RegionMostYears(sPlayer arrayPlayers[], int lenPlayers, sConfederation arrayConfederations[], int lenConfederations);

void report_findConfederationRegionById(sConfederation arrayConfederations[], int lenConfederations, int auxId, char auxName[]);

#endif /* REPORT_H_ */
