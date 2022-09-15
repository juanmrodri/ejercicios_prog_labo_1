/*
 * checkers.c
 *
 *  Created on: 12 sept 2022
 *      Author: juanm
 */

#include "checkers.h"

int checkPositiveNumber(int number)
{
	int ret=1;

	if(number>0)
	{
		ret=0;
	}

	return ret;
}

int checkNegativeNumber(int number)
{
	int ret=1;

	if(number<0)
	{
		ret=0;
	}

	return ret;
}

int checkEvenNumber(int number)
{
	int ret=1;

	if(number%2==0)
	{
		ret=0;
	}

	return ret;
}

int checkOddNumber(int number)
{
	int ret=1;

	if(number%2!=0)
	{
		ret=0;
	}

	return ret;
}

void checkMaxOddNumber(int* flag, int* min, int* max, int number)
{
	int bufferFlag;
	int bufferMin;
	int bufferMax;

	bufferFlag=*flag;
	bufferMin=*min;
	bufferMax=*max;

	if(flag!=NULL && min!=NULL && max!=NULL)
	{
		if(bufferFlag==1)
				{
					*flag=0;
					*min=number;
					*max=number;
				}
				else
				{
					if(number<bufferMin)
					{
						*min=number;
					}
					else
					{
						if(number>bufferMax)
						{
							*max=number;
						}
					}
				}
	}
}
