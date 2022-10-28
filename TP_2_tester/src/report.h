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

void report_countPlayerConfederationAmount(sPlayer arrayPlayers[], int lenPlayers, sConfederation arrayConfederations[], int lenConfederations, int idConfederation, int* confederationAmount);

// informe 3
int report_playersAverageSalaryCalculation(sPlayer arrayPlayers[], int lenPlayers);

int report_playersCount(sPlayer arrayPlayers[], int lenPlayers);

float report_playersTotalSalaryCount(sPlayer arrayPlayers[], int lenPlayers);

float report_AverageSalary(int totalPlayers, float totalSalary);

int report_amountPlayersSalaryMoreThanAverage(sPlayer arrayPlayers[], int lenPlayers, float averageSalary);

void report_printPlayersAverageSalaryCalculation(float totalSalary, float averageSalary, int playersOverAverageCount);


// informe 4

#endif /* REPORT_H_ */
