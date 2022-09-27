/*
 * calculations.c
 *
 *  Created on: 23 sept 2022
 *      Author: juanm
 */

#include "calculations.h"

int calculations_totalPlayers (int afc, int caf, int concacaf, int conmebol, int uefa, int ofc)
{
	int totalPlayers;

	totalPlayers=afc+caf+concacaf+conmebol+uefa+ofc;

	return totalPlayers;
}

float calculations_averagePlayer(int playerPerMarket, int totalPlayers)
{
	float auxAverage;

	auxAverage = ((float)playerPerMarket*100)/totalPlayers;

	return auxAverage;
}

float calculations_maintenanceCost(float costOne, float costTwo, float costThree)
{
	float maintenance;

	maintenance = costOne + costTwo + costThree;

	return maintenance;
}

int calculations_mostUefa(int afc, int caf, int concacaf, int conmebol, int uefa, int ofc)
{
	int ret=1;

	if(afc > caf && afc > concacaf && afc > conmebol && afc > ofc)
	{
		//afc mayor
		if(uefa > afc)
		{
			ret=0;
		}
	}
	else
	{
		if(caf > concacaf && caf > conmebol && caf > ofc && caf > afc)
		{
			//caf mayor
			if(uefa > caf)
			{
				ret=0;
			}
		}
		else
		{
			if(concacaf > conmebol && concacaf > ofc && concacaf > afc && concacaf > caf)
			{
				//concacaf mayor
				if(uefa > concacaf)
				{
					ret=0;
				}
			}
			else
			{
				if( conmebol > ofc && conmebol > afc && conmebol > caf && conmebol > concacaf)
				{
					//conmebol mayor
					if(uefa > conmebol)
					{
						ret=0;
					}
				}
				else
				{
					if(ofc > afc && ofc > caf && ofc > concacaf && ofc > conmebol)
					{
						//ofc mayor
						if(uefa > ofc)
						{
							ret=0;
						}
					}
				}
			}
		}
	}

	return ret;
}

float calculations_mainTenanceCostIncrease(float mainTenanceCost, float* increase)
{
	float result;

	result = (35*mainTenanceCost)/100;

	*increase = result;

	result = result+mainTenanceCost;

	return result;

}
