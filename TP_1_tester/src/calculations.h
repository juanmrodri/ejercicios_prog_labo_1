/*
 * calculations.h
 *
 *  Created on: 23 sept 2022
 *      Author: juanm
 */

#ifndef CALCULATIONS_H_
#define CALCULATIONS_H_

#include <stdio.h>
#include <stdlib.h>

int calculations_totalPlayers (int afc, int caf, int concacaf, int conmebol, int uefa, int ofc);

float calculations_averagePlayer(int playerPerMarket, int totalPlayers);

float calculations_maintenanceCost(float costOne, float costTwo, float costThree);

int calculations_mostUefa(int afc, int caf, int concacaf, int conmebol, int uefa, int ofc);

float calculations_mainTenanceCostIncrease(float mainTenanceCost, float* increase);

#endif /* CALCULATIONS_H_ */
