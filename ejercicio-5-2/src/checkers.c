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

void initArray(int pArray[], int len, int number)
{

	int i;

	if(pArray!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			pArray[i]=number;
		}
	}
}

int findEmptyPosArray(int pArray[], int len, int* ind)
{
	int ret=1;
	int i;

	if(pArray!=NULL && len >0 && ind!=NULL)
	{
		for(i=0;i<len;i++)
		{
			if(pArray[i]==0 || pArray[i]==-1001)
			{
				*ind=i;
				ret=0;
				break;
			}
		}
	}

	return ret;
}

int findRepeatNumbers(int pArray[], int len, int pArrayRep[], int lenRep)
{
	int ret=1;
	int i;
	int j;
	int auxBuffer;
	int auxIndex;

	if(pArray!=NULL && len >0)
	{
		for(i=0;i<len-1;i++)
		{
			auxBuffer=pArray[i];
			//printf("Estoy en el primer for: %d\n", pArray[i]);
			for(j=i+1;j<len;j++)
			{
				//printf("\tEstoy en el segundo for: %d\n", pArray[j]);
				if(auxBuffer==pArray[j])
				{
					//printf("\tAca hay un numero igual: %d == %d\n", auxBuffer, pArray[j]);
					findEmptyPosArray(pArrayRep, lenRep, &auxIndex);
					//auxNumber=pArray[j];
					pArrayRep[auxIndex]=auxBuffer;
					ret=0;
				}
			}
		}
	}

	return ret;
}

int orderAsc(int pArray[], int len)
{
	int ret=1;
	int i;
	int flagSwap;
	int buffer;

	if(pArray!=NULL && len >0)
	{
		do{
		            flagSwap = 0;
		            for(i = 0; i < len - 1; i++){
		                if(pArray[i] > pArray[i+1]){
		                    flagSwap = 1;
		                    buffer = pArray[i];
		                    pArray[i] = pArray[i+1];
		                    pArray[i+1] = buffer;
		                }
		            }
		        }while(flagSwap);
		ret=0;
	}
	return ret;
}

int orderDes(int pArray[], int len)
{
	int ret=1;
	int i;
	int flagSwap;
	int buffer;

	if(pArray!=NULL && len >0)
	{
		do{
		            flagSwap = 0;
		            for(i = 0; i < len - 1; i++){
		                if(pArray[i] < pArray[i+1]){
		                    flagSwap = 1;
		                    buffer = pArray[i];
		                    pArray[i] = pArray[i+1];
		                    pArray[i+1] = buffer;
		                }
		            }
		        }while(flagSwap);
		ret=0;
	}
	return ret;
}
